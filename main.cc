#include <iostream>
#include "screen.hh"

int main(int argc, char **argv) {
    std::cerr << "to quit, type C-c in the terminal" << std::endl;
    srand(time(0));
    Screen screen(500, 500);
    
    while (screen.isOpen()) {
        screen.render();
        screen.pollEvents();
    }

}
