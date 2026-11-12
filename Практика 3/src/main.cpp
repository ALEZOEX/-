#include <SFML/Graphics.hpp>
#include <string>


int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), L"Приложение для вывода массивов");

    sf::CircleShape mouseCursor(4);
    mouseCursor.setFillColor(sf::Color::White);
    mouseCursor.setOutlineColor(sf::Color::Black);
    mouseCursor.setOutlineThickness(1);

    // Загрузка шрифта
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }


    const int cellSize = 50;
    const int gridSize = 10;

    // Массив для хранения ячеек
    sf::RectangleShape cells[gridSize][gridSize];

    // Инициализируем ячейки вложенными циклами
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            cells[i][j].setSize(sf::Vector2f(cellSize - 2, cellSize - 2)); // размер ячейки
            cells[i][j].setPosition(i * cellSize, j * cellSize);           // позиция из индексов
            //cells[i][j].setFillColor(sf::Color::Black);                    // цвет заливки
            cells[i][j].setOutlineColor(sf::Color::Black);                 // цвет границы
            cells[i][j].setOutlineThickness(1);

            if (i % 2 != 0 and j % 2 == 0) {
                cells[i][j].setFillColor(sf::Color::Green);
            } else {
                cells[i][j].setFillColor(sf::Color::White);
            }
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        for (int i = 0; i < gridSize; ++i)
        {
            for (int j = 0; j < gridSize; ++j)
            {
                window.draw(cells[i][j]);
            }
        }
        window.display();
    }



    return 0;
}
