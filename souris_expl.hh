
#include "souris.hh"

class Souris_expl : public Souris{
private:
    sf::Texture * image_expl2 ;

public :
    Souris_expl(sf::Vector2u windowSize,int vitesse_souris,bool haut);
    ~Souris_expl();
    // void explosion(sf::RenderWindow * main_window);

};