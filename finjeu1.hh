// #pragma once 

// #include <SFML/Graphics.hpp>
// #include <iostream>

// class FinJeu1 {
//     private:
//         int* gameState;
//         sf::RenderWindow * main_window;
//         sf::Font * font;
//         sf::Texture * image;
//         sf::Sprite * bg;

//         int nb_souris_attrape;
//         int nb_souris_passe;
//         float nb_souris_attrape_max;
//         int niveau_jeu;

//         std::string score;

//         std::vector<sf::Text> texts;
//         std::vector<sf::Vector2f> text_coords;
//         std::vector<std::size_t> text_size;
//         std::vector<const char *> options;

//     protected:
//         void set_values();
//         void loop_events();
//         void draw_all();

//     public:
//         FinJeu1(sf::RenderWindow * main_window, int* gameState, std::string score);
// };