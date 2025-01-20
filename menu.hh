#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "instance.hh"

// Classe Menu : permet de gérer le menu du jeu
class Menu: public Instance {
  private:
    //variables de position
    int pos; 
    bool theselect;

    //métodes de la classe
    void draw_all();
    void set_values();
    void loop_events();

  public:
    Menu(sf::RenderWindow * main_window, int* gameState);
    ~Menu();
    void run();
};