#pragma once

#include "instance.hh"

class Settings : public Instance {
    private:
        int pos;
        int * level;
        int level_pos;
        bool theselect;

        //vecteur d'options
        std::vector<std::vector<sf::Text> > texts_settings;
        std::vector<std::vector<sf::Vector2f>> text_coords_settings;
        std::vector<std::vector<std::size_t>> text_size_settings;
        std::vector<std::vector<const char *> > options_settings;

        void draw_all();
        void set_values();
        void loop_events();
        void changeLevel(int level_pos, int* level);

    public:
        Settings(sf::RenderWindow * main_window, int* gameState, int* level);
        ~Settings();
        void run();
};