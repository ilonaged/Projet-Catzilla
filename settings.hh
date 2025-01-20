#pragma once

#include "instance.hh"

// Classe Settings : permet de gérer les paramètres du jeu
class Settings : public Instance {
    private:
        //variables de position
        int pos;
        int level_pos;
        bool theselect;
        int * level; //niveau de difficulté du jeu

        //vecteurs d'options de texte 
        std::vector<std::vector<sf::Text> > texts_settings;
        std::vector<std::vector<sf::Vector2f>> text_coords_settings;
        std::vector<std::vector<std::size_t>> text_size_settings;
        std::vector<std::vector<const char *> > options_settings;

        //méthodes de la classe
        void draw_all(); 
        void set_values(); 
        void loop_events(); 
        void changeLevel(int level_pos, int* level); //changer le niveau de difficulté du jeu

    public:
        Settings(sf::RenderWindow * main_window, int* gameState, int* level);
        ~Settings();
        void run();
};