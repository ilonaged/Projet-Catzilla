#pragma once

#include <SFML/Graphics.hpp>

class Screen {
private:
    // sf::RenderWindow window;

public:
    sf::RenderWindow window;

    Screen(int width, int height)
        : window(sf::VideoMode(width, height), "Catzilla", sf::Style::Default) {
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

    void close(){
        window.close();
    }

    bool pollEvent(sf::Event& event) {
        // bool eventOccurred = false;
        // while (window.pollEvent(event)) {
        //     eventOccurred = true;
        //     if (event.type == sf::Event::Closed) {
        //         window.close();
        //     }
        // }
        // return eventOccurred;
        // if (window.pollEvent(event)) {
        //     if (event.type == sf::Event::Closed) {
        //         window.close();
        //     }
        //     return true;
        // }
        // return false;
        return(window.pollEvent(event));
    }

    void setPosition(const sf::Vector2i& vector) {
        window.setPosition(vector);
    }


    sf::Vector2f getMousePosition() {
        sf::Vector2i pos_mouse=sf::Mouse::getPosition(window);
        return window.mapPixelToCoords(pos_mouse);
    }

};