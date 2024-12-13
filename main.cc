#include <iostream>
#include "screen.hh"
#include "menu.hh"

int main(int argc, char **argv) {
    // std::cerr << "to quit, type C-c in the terminal" << std::endl;
    // srand(time(0));
    Screen main_window(1280,720);

    //SI gameState vaut 0 on est sur le menu, gameState vaut 1 on est sur le jeu 1, gameState vaut 2 on est sur jeu 2, gameState vaut 3 on est sur le jeu 3
    int gameStateVal=0;
    
    Menu * menu = new Menu(&main_window,&gameStateVal);
    while (main_window.isOpen()) {
        while(gameStateVal==0){
            menu->run_menu();

        }
        std::cout <<gameStateVal<<std::endl;
        std::cout << "sortie du menu" << '\n';
        delete menu;

        // menu = nullptr;

    }
    
}
