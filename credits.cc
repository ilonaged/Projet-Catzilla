#include "credits.hh"

Credits::Credits(sf::RenderWindow * main_window, int* gameState):Instance(main_window,gameState){
    set_values();
}

Credits::~Credits(){
    delete font;
    delete image;
    // delete bg;
}


void Credits::set_values() {
    font->loadFromFile("./assets/LVDCGO__.TTF");

    options = {"CREDITS - CATZILLA",
                "Developed by:", "- Paul Poupeau", "- Ilona Gedeon--Amrouche",
                "Music by:", "- Antoine Harmel",
                "Special thanks to:", "- The cat that inspired us ;)",
                "Press Enter to go back to the menu"
            };
    texts.resize(options.size());
    text_coords = { {350, 100},
                    {150, 200}, {410, 250}, {410, 300},
                    {150, 350}, {410, 400},
                    {150, 450}, {410, 500},
                    {200, 650} };
    text_size = {30, 20, 20, 20, 20, 20, 20, 20, 20};

    for (std::size_t i{}; i < texts.size(); ++i){
        texts[i].setFont(*font); 
        texts[i].setString(options[i]); 
        texts[i].setCharacterSize(text_size[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(text_coords[i]);
    }
}


void Credits::loop_events() {
    sf::Event event;
    while (main_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            main_window->close();
        }

        if (event.type == sf::Event::Resized) {
            windowSize = main_window->getSize();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !pressed) {
            pressed = true;
            *gameState = 0;
        }
    }

    if (event.type == sf::Event::KeyReleased) {
        pressed = false;
    }
}

void Credits::draw_all(){
    main_window->clear();
    for (std::size_t i{}; i < texts.size(); ++i) {
        main_window->draw(texts[i]);
    }
    main_window->display();
}

void Credits::run(){
    while(main_window->isOpen() && *gameState == 3){
        loop_events();
        draw_all();
    }
}

