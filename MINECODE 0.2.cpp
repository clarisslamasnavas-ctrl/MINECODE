#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 300), "MINECODE");

    // Botón A
    sf::RectangleShape buttonA(sf::Vector2f(200, 60));
    buttonA.setFillColor(sf::Color::Green);
    buttonA.setPosition(150, 120);

    // Fuente (NECESARIA)
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "ERROR: No se encontro la fuente arial.ttf\n";
        return 1;
    }

    // Texto del botón
    sf::Text textA;
    textA.setFont(font);
    textA.setString("EJECUTAR A");
    textA.setCharacterSize(24);
    textA.setFillColor(sf::Color::Black);
    textA.setPosition(185, 135);

    // Texto de estado
    sf::Text status;
    status.setFont(font);
    status.setCharacterSize(18);
    status.setFillColor(sf::Color::White);
    status.setPosition(20, 20);
    status.setString("Esperando accion...");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Detectar clic del mouse
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) {

                sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

                if (buttonA.getGlobalBounds().contains(mousePos)) {
                    status.setString("Actualizacion A ejecutada!");
                    std::cout << "MINECODE: Ejecutando A...\n";
                }
            }
        }

        window.clear(sf::Color(30, 30, 30));
        window.draw(buttonA);
        window.draw(textA);
        window.draw(status);
        window.display();
    }

    return 0;
}

