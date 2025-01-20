#pragma once

#include "instance.hh"

// Classe Credits: permet d'afficher les crédits du jeu
class Credits : public Instance {
    private:
        //méthodes de la classe
        void draw_all();
        void set_values();
        void loop_events();

    public:
        Credits(sf::RenderWindow * main_window, int* gameState);
        ~Credits();
        void run();
};