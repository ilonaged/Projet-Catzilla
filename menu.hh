#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "instance.hh"


class Menu: public Instance {
  private:
    int pos;
    bool theselect;
    void draw_all();

  protected:
    void set_values();
    void loop_events();


  public:
    Menu(sf::RenderWindow * main_window, int* gameState);
    ~Menu();
    void run();
};