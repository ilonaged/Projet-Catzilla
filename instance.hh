#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <map>

class Instance {
    protected:
        int* gameState;
        sf::RenderWindow * main_window;
        sf::Vector2u windowSize;
        

        sf::Font * font;
        sf::Texture * image;
        std::map<std::string,sf::Sprite *> map_sprites;

        bool pressed;

        sf::Music music;

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