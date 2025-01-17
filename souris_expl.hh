
#include "souris.hh"

class Souris_expl : public Souris{

public :
    Souris_expl(sf::Vector2u windowSize,int vitesse_souris,bool haut);
    ~Souris_expl();
    void explosion(sf::RenderWindow * main_window);

};