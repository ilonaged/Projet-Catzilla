
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "chat1.hh"

class Jeu1{
    private :
        int* gameState;
        sf::RenderWindow * main_window;
        sf::Font * font;
        sf::Texture * image;
        sf::Sprite * bg;

    protected:
        void set_values();
        void loop_events(Chat1 *chat);
        void draw_all();

    public:
        Jeu1(sf::RenderWindow * main_window, int* gameState);
        ~Jeu1();
        void run_jeu1();


};