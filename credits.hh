#pragma once

#include "instance.hh"

class Credits : public Instance {
    private:
        void draw_all();

    protected:
        void set_values();
        void loop_events();
    public:
        Credits(sf::RenderWindow * main_window, int* gameState);
        ~Credits();
        void run();
};