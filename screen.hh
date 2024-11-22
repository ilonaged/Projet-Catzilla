#pragma once

#include <SFML/Graphics.hpp>

class Screen {
private:
    sf::RenderWindow window;

public:
    Screen(int width, int height)
        : window(sf::VideoMode(width, height), "Balls") {
        window.setFramerateLimit(60); 
    }

    void draw(const sf::Drawable &drawable) {
        window.draw(drawable);
    }

    void render() {
        window.display();
        window.clear();
    }

    sf::Vector2u getSize() const {
        return window.getSize();
    }

    bool isOpen() const {
        return window.isOpen();
    }

    void pollEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
};