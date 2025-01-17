#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "instance.hh"
#include "chat1.hh"
#include "objet.hh"
#include "souris_expl.hh"

class Jeu1: public Instance{
    private :
        sf::Texture * image_sang;
        sf::Sprite * sprite_sang;

        int nb_souris_attrape;
        int nb_souris_passe;
        float nb_souris_attrape_max;
        int niveau_jeu;
        unsigned int seed;

        std::string score;

        Chat1 *chat;
        std::vector<Objet *> souris_liste;

        void print_text(int nb_souris_attrape,float nb_souris_attrape_max);
        // int genere_intervalle(int borne_gauche, int borne_droite);
        void gestion_vitesse(int * vitesse_souris,float * inc_vitesse);
        void draw_all();
        void genere_objet(int vitesse_souris);

    protected:
        void set_values();
        void loop_events();

    


    public:
        Jeu1(sf::RenderWindow * main_window, int* gameState,int nb_souris_attrape_max,int niveau_jeu);
        ~Jeu1();
        void run();
        int getScore(){return nb_souris_attrape;};


};