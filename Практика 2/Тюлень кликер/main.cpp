#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), L"Тюлень кликер");

    sf::Texture cookieTexture;                       // текстура печеньки
    if (!cookieTexture.loadFromFile("images.jpg")) {
        return -1;
    }
    sf::Sprite cookieSprite;                         // спрайт печеньки
    cookieSprite.setTexture(cookieTexture);
    cookieSprite.setPosition(300, 200);

    sf::Font font;                                   // шрифт для счёта
    if (!font.loadFromFile("arial.ttf")) {
        return -1;
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    int score = 0;
    scoreText.setString("Score: " + std::to_string(score));

    while (window.isOpen()) {                        // основной цикл игры
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (cookieSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        score += 1;
                        scoreText.setString("Score: " + std::to_string(score));
                    }
                }
            }
        }

        window.clear();
        window.draw(cookieSprite);
        window.draw(scoreText);
        window.display();
    }

    return 0;
}
