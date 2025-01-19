#include "settings.hh"

Settings::Settings(sf::RenderWindow * main_window, int* gameState, int* level): Instance(main_window, gameState), level(level){
    set_values();
}

Settings::~Settings(){
    delete font;
    delete image;
}


void Settings::set_values() {
    pos = 0;
    level_pos = 0;
    theselect = false;

    image->loadFromFile("./assets/settings.png");
    //bg->setTexture(*image);
    map_sprites["bg"]->setTexture(*image);
    font->loadFromFile("./assets/LVDCGO__.TTF");

    options_settings = { {"SETTINGS", "CHANGE LEVEL", "BACK TO MENU"},
                            {"EASY", "MEDIUM", "HARD"},
                        };
    text_coords_settings = { {{470, 200}, {410, 310}, {410, 500}},
                            {{320, 400}, {550, 400}, {800, 400}},
                        };
    text_size_settings = {{30,30,30, 30}, {20, 20, 20}};

    for (std::size_t i{}; i < options_settings.size(); ++i) {
        texts_settings.resize(options_settings.size());
        for (std::size_t j{}; j < options_settings[i].size(); ++j) {
            texts_settings[i].push_back(sf::Text());
            texts_settings[i][j].setFont(*font); 
            texts_settings[i][j].setString(options_settings[i][j]); 
            texts_settings[i][j].setCharacterSize(text_size_settings[i][j]);
            texts_settings[i][j].setOutlineColor(sf::Color::Black);
            texts_settings[i][j].setPosition(text_coords_settings[i][j]);
        }
    }
    texts_settings[0][0].setOutlineThickness(4);  
}



void Settings::loop_events() {
    sf::Event event;
    while (main_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            main_window->close();
        }

        if (event.type == sf::Event::Resized) {
            windowSize = main_window->getSize();
        }

        if (!theselect) {  // Navigation principale avec flèches haut/bas
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
                if (pos < 2) {
                    ++pos;
                    pressed = true;
                    texts_settings[0][pos].setOutlineThickness(4);
                    texts_settings[0][pos - 1].setOutlineThickness(0);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
                if (pos > 0) {
                    --pos;
                    pressed = true;
                    texts_settings[0][pos].setOutlineThickness(4);
                    texts_settings[0][pos + 1].setOutlineThickness(0);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !pressed) {
                pressed = true;

                if (pos == 2) {  
                    *gameState = 0;
                }
                else if (pos == 1) {  // Entrer dans le sous-menu "Change Level"
                    theselect = true;  
                    level_pos = 0;  
                    texts_settings[1][0].setOutlineThickness(4);  
                    texts_settings[0][1].setOutlineThickness(0);  
                }
            }
        } 

        if (theselect && pos == 1) {  // Sous-menu "Change Level"
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !pressed) {
                if (level_pos < 2) {
                    ++level_pos;
                    pressed = true;
                    texts_settings[1][level_pos].setOutlineThickness(4);
                    texts_settings[1][level_pos - 1].setOutlineThickness(0);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !pressed) {
                if (level_pos > 0) {
                    --level_pos;
                    pressed = true;
                    texts_settings[1][level_pos].setOutlineThickness(4);
                    texts_settings[1][level_pos + 1].setOutlineThickness(0);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !pressed) {
                pressed = true;
                theselect = false; 
                texts_settings[1][level_pos].setOutlineThickness(0);

                // Appliquer le niveau sélectionné
                changeLevel(level_pos, level);

                
                texts_settings[0][1].setOutlineThickness(4); 
            }
        }

        if (event.type == sf::Event::KeyReleased) {
            pressed = false;
        }
    }
}



void Settings::draw_all(){
    main_window->clear();
    main_window->draw(*map_sprites["bg"]);
    for (std::size_t i{}; i < texts_settings.size(); ++i) {
        for (std::size_t j{}; j < texts_settings[i].size(); ++j) {
            main_window->draw(texts_settings[i][j]);
        }
    }
    main_window->display();
}

void Settings::changeLevel(int level_pos, int* level) {
    *level = level_pos + 1;
}


void Settings::run(){
    theselect = false;
    while(main_window->isOpen() && *gameState == 2){
        loop_events();
        draw_all();
    }
}