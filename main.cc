#include <iostream>
#include "screen.hh"
#include "menu.hh"
#include "jeu1.hh"

int main(int argc, char **argv) {
    // std::cerr << "to quit, type C-c in the terminal" << std::endl;
    // srand(time(0));
    // Screen main_window(1280,720);
    sf::RenderWindow main_window(sf::VideoMode(1280, 720), "Catzilla", sf::Style::Default);
    main_window.setFramerateLimit(60); 

    //SI gameState vaut 0 on est sur le menu, gameState vaut 1 on est sur le jeu 1, gameState vaut 2 on est sur jeu 2, gameState vaut 3 on est sur le jeu 3
    int gamestate = 0;
    
    Menu * menu = new Menu(&main_window, &gamestate);
    while (main_window.isOpen()) {

        
        if (gamestate == 0) {
            menu->run_menu();
        }
        std::cout << gamestate << '\n';
        std::cout << "Sortie du menu" << '\n';
        if(gamestate==1){
            Jeu1 * jeu1 = new Jeu1(&main_window, &gamestate);
            jeu1->run_jeu1();
        }
        

        // menu = nullptr;

    }
    
}
