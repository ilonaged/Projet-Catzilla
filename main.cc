#include <iostream>
#include "menu.hh"
#include "jeu1.hh"
#include "finjeu1.hh"
#include "settings.hh"

int main(int argc, char **argv) {
    // std::cerr << "to quit, type C-c in the terminal" << std::endl;
    // srand(time(0));
    // Screen main_window(1280,720);
    sf::RenderWindow main_window(sf::VideoMode(1280, 720), "Catzilla", sf::Style::Default);
    main_window.setFramerateLimit(60); 

    //SI gameState vaut 0 on est sur le menu, gameState vaut 1 on est sur le jeu 1, gameState vaut 2 on est sur jeu 2, gameState vaut 3 on est sur le jeu 3
    int gamestate = 0;

    int nb_souris_attrape_max=50;
    int niveau_jeu=1;
    
    Menu * menu = new Menu(&main_window, &gamestate);
    while (main_window.isOpen()) {
        Jeu1 * jeu1 = new Jeu1(&main_window, &gamestate,nb_souris_attrape_max,niveau_jeu);
        if (gamestate == 0) {
            menu->run();
        }
        std::cout << gamestate << '\n';
        std::cout << "Sortie du menu" << '\n';
        if(gamestate==1){
            jeu1->run();
        }
        if (gamestate==2){
            Settings * settings = new Settings(&main_window, &gamestate, &niveau_jeu);
            settings->run();
        }
        if (gamestate==4){
            FinJeu1 * fin_jeu1 = new FinJeu1(&main_window, &gamestate,jeu1->getScore(),nb_souris_attrape_max,niveau_jeu,false);
            fin_jeu1->run();
        }
        if (gamestate==5){
            FinJeu1 * fin_jeu1 = new FinJeu1(&main_window, &gamestate,jeu1->getScore(),nb_souris_attrape_max,niveau_jeu,true);
            fin_jeu1->run();
        }
        

        // menu = nullptr;

    }
    
}
