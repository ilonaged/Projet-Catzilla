#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <map>

// Classe Instance : permet de gérer toutes les instances du jeu (menu, jeu, fin de jeu...)
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

    public:
        Instance(sf::RenderWindow * main_window, int* gameState);
        ~Instance();
        void run();
};