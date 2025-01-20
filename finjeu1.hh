#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>
#include "instance.hh"

// Classe FinJeu1 : permet de gérer la fin du jeu 1 (gameover ou victoire)
class FinJeu1 : public Instance {
    private:
        int nb_souris_attrape;
        int niveau_jeu;
        bool is_game_over;

        std::string score;
        void draw_all();

    protected:
        void set_values();
        void loop_events();

    public:
        FinJeu1(sf::RenderWindow * main_window, int* gameState, int nb_souris_attrape,int niveau_jeu,bool is_game_over);
        ~FinJeu1();
        void run();
};