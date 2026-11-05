#include <SFML/Graphics.hpp>
#include <functional>
#include <cmath>
#include <string>

// Функция для отрисовки графика
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func,
               float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x);                 // вычисление значения функции

        float screenX = 400 + x * scaleX;  // преобразование координат в экранные
        float screenY = 300 - y * scaleY;

        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), L"Приложение для вывода графиков");

    sf::CircleShape userPoint(5);          // пользовательская точка, радиус 5 пикселей
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false;

    sf::CircleShape mouseCursor(4);
    mouseCursor.setFillColor(sf::Color::White);
    mouseCursor.setOutlineColor(sf::Color::Black);
    mouseCursor.setOutlineThickness(1);

    // 1 _ Загрузка шрифта
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }

    // 2 _ Текст для отображения координат: размер 20, позиция (10,10), цвет белый,
    //     переменная coordinatesText
    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10,10);

    // Оси X и Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300);   xAxis[0].color = sf::Color::White;
    xAxis[1].position = sf::Vector2f(750, 300);  xAxis[1].color = sf::Color::White;
    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50);   yAxis[0].color = sf::Color::White;
    yAxis[1].position = sf::Vector2f(400, 550);  yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Преобразование экранных координат в «математические»
                    float mathX = (mousePos.x - 400) / 30.0f;
                    float mathY = -(mousePos.y - 300) / 2.5f;

                    userPoint.setPosition(mousePos.x - userPoint.getRadius(),
                                          mousePos.y - userPoint.getRadius());
                    userPointExists = true;

                    // 3 _ Допишите логику проверки точки по mathX и mathY!
                    float y1 = mathX * mathX - 8;
                    float y2 = -mathX * mathX + 8;

                    std::wstring zone;

                    if (std::abs(mathY - y1) <= 0.5f or std::abs(mathY - y2) <= 0.5f)
                    {zone = L"Граница";}
                    else if (mathY < y1 and mathY < y2) {zone = L"1";}
                    else if (mathY > y1 and mathY < y2) {zone = L"2";}
                    else if (mathY > y1 and mathY > y2) {zone = L"3";}
                    else if (mathX < 0) {zone = L"4";}
                    else {zone = L"5";}

                    coordinatesText.setString(
                        std::wstring(L"Координаты: (") + std::to_wstring(mathX) +
                        L", " + std::to_wstring(mathY) + L") Зона: " + zone);
                }
            }
        }

        // 4 _ Очистка экрана
        window.clear();

        window.draw(xAxis);
        window.draw(yAxis);

        // 5 _ Замените на графики вашего варианта
        drawGraph(window, [](float x) { return x * x - 8; }, -10, 10, 30, 2.5f, sf::Color::Red);
        drawGraph(window, [](float x) { return -x * x + 8; }, -10, 10, 30, 2.5f, sf::Color::Blue);

        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (mousePos.x >= 0 && mousePos.x < 800 &&
            mousePos.y >= 0 && mousePos.y < 600) {

            mouseCursor.setPosition(mousePos.x - 4, mousePos.y - 4);
            window.draw(mouseCursor);
        }

        window.display();
    }

    return 0;
}
