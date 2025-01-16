
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "chat1.hh"
#include "souris.hh"

class Jeu1{
    private :
        int* gameState;
        sf::RenderWindow * main_window;
        sf::Font * font;
        sf::Texture * image;
        sf::Sprite * bg;
        bool pressed;

        int nb_souris_attrape;
        int nb_souris_passe;
        float nb_souris_attrape_max;
        int niveau_jeu;

        std::string score;

        std::vector<sf::Text> texts;
        std::vector<sf::Vector2f> text_coords;
        std::vector<std::size_t> text_size;
        std::vector<const char *> options;

        void print_text(int nb_souris_attrape,float nb_souris_attrape_max);

    protected:
        void set_values();
        void loop_events(Chat1 *chat,std::vector<Souris *> souris_liste);
        void draw_all();


    public:
        Jeu1(sf::RenderWindow * main_window, int* gameState,int nb_souris_attrape_max,int niveau_jeu);
        ~Jeu1();
        void run_jeu1();


};