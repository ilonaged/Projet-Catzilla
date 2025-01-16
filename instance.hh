#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Instance {
    protected:
        int* gameState;
        sf::RenderWindow * main_window;
        sf::Vector2u windowSize;

        sf::Font * font;
        sf::Texture * image;
        sf::Sprite * bg;

        bool pressed;

        std::vector<sf::Text> texts;
        std::vector<sf::Vector2f> text_coords;
        std::vector<std::size_t> text_size;
        std::vector<const char *> options;

        void set_values_instance();
        virtual void loop_events();
        // void draw_all(){};

    public:
        Instance(sf::RenderWindow * main_window, int* gameState);
        ~Instance();
        void run();
};