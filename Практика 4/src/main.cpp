#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(512, 396), "Variant 23");
    window.setFramerateLimit(60);

    const Color background(200, 200, 220);

    CircleShape face(150);
    face.setScale(1.3,1);
    face.setPosition(60, 80);
    face.setFillColor(Color(50, 160, 60));

    CircleShape eyeWhite(40);
    eyeWhite.setFillColor(Color::White);

    CircleShape eyeBlack(20);
    eyeBlack.setFillColor(Color::Black);

    RectangleShape brovi(Vector2f(80, 20));
    brovi.setFillColor(Color(40, 130, 50));

    const float eyeX[] = {112, 260};

    RectangleShape mouthBorder(Vector2f(130, 12));
    mouthBorder.setPosition(190, 250);
    mouthBorder.setFillColor(Color::Black);

    RectangleShape mouth(Vector2f(120, 6));
    mouth.setPosition(195, 253);
    mouth.setFillColor(Color::Red);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (!window.isOpen()) {
            break;
        }

        window.clear(background);
        window.draw(face);

        for (float x : eyeX) {
            eyeWhite.setPosition(x, 80);
            eyeBlack.setPosition(x + 20, 100);
            brovi.setPosition(x, 90);

            window.draw(eyeWhite);
            window.draw(eyeBlack);
            window.draw(brovi);
        }

        window.draw(mouthBorder);
        window.draw(mouth);
        window.display();
    }
}
