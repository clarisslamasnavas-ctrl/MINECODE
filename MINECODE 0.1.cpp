#include <SFML/Graphics.hpp>
#include <vector>

const int WIDTH = 800;
const int HEIGHT = 600;
const int BLOCK_SIZE = 40;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Mini Minecraft");

    // Crear un mundo simple de bloques
    int rows = HEIGHT / BLOCK_SIZE;
    int cols = WIDTH / BLOCK_SIZE;
    std::vector<sf::RectangleShape> blocks;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sf::RectangleShape block(sf::Vector2f(BLOCK_SIZE - 1, BLOCK_SIZE - 1));
            block.setPosition(j * BLOCK_SIZE, i * BLOCK_SIZE);
            if (i > rows / 2) block.setFillColor(sf::Color::Green); // suelo
            else block.setFillColor(sf::Color::Cyan); // cielo
            blocks.push_back(block);
        }
    }

    // Bloque controlado por el jugador
    sf::RectangleShape player(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    player.setFillColor(sf::Color::Red);
    player.setPosition(WIDTH/2, HEIGHT/2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movimiento simple
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  player.move(-5,0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player.move(5,0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    player.move(0,-5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  player.move(0,5);

        window.clear();
        for (auto &b : blocks) window.draw(b);
        window.draw(player);
        window.display();
    }

    return 0;
}
