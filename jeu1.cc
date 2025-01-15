#include "jeu1.hh"
#include "chat1.hh"
#include <random>
#include <chrono>

Jeu1::Jeu1(sf::RenderWindow * main_window,int* gameState):gameState(gameState),main_window(main_window) {
  main_window->setKeyRepeatEnabled(false);
  font = new sf::Font();
  image = new sf::Texture();
  bg = new sf::Sprite();

  set_values();
}



void Jeu1::set_values(){
  // window->create(sf::VideoMode(1280,720), "Menu SFML", sf::Style::Default);
  main_window->setPosition(sf::Vector2i(0,0));

//   pos = 0;
//   pressed = theselect = false;
//   font->loadFromFile("./assets/LVDCGO__.TTF");
  image->loadFromFile("./assets/game1-floor.png");
  sf::Vector2u windowSize = main_window->getSize();
  sf::Vector2u textureSize = image->getSize();
  bg->setScale(
    float(windowSize.x) / textureSize.x,
    float(windowSize.y) / textureSize.y
  );
  bg->setTexture(*image);

  // pos_mouse = {0,0};
//   mouse_coord = {0, 0};

//   options = {"JEU 1", "JEU 2", "JEU 3"};
//   texts.resize(3);
//   coords = {{410,225},{410,365},{410,510}};
//   sizes = {30,30,30};

//   for (std::size_t i{}; i < texts.size(); ++i){
//    texts[i].setFont(*font); 
//    texts[i].setString(options[i]); 
//    texts[i].setCharacterSize(sizes[i]);
//    texts[i].setOutlineColor(sf::Color::Black);
//    texts[i].setPosition(coords[i]);
//   }
//   texts[0].setOutlineThickness(4);
//   pos = 0;

}

void Jeu1::loop_events(Chat1 *chat,std::vector<Souris *> souris_liste) {
  sf::Event event;
  while(main_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        main_window->close();
      }

      // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
        main_window->clear();
        main_window->draw(*bg);
        chat->jouer(main_window,souris_liste,&nb_souris_attrape);
      }
        
  }
}


// void Jeu1::draw_all() {
//   main_window->clear();
//   main_window->draw(*bg);
//   main_window->display();
// }

void Jeu1::print_score(int nb_souris_attrape,float nb_souris_attrape_max){
  options={"Bonjour"};
  // texts.setFont(*font);
  texts.resize(1);
  texts[0].setString(options[0]); 
  texts[0].setCharacterSize(30);
  texts[0].setOutlineColor(sf::Color::Black);
  // texts[0].setPosition(main_window->getSize().x/1.1,main_window->getSize().y/10);
  texts[0].setPosition(main_window->getSize().x/2,main_window->getSize().y/2);
  texts[0].setOutlineThickness(4);
  main_window->draw(texts[0]);

}


void Jeu1::run_jeu1() {

  Chat1 * chat = new Chat1(main_window);

  std::vector<Souris *> souris_liste;
  float inc_vitesse=1;
  // for (int i = 0; i < nb_souris; i++) {
  //   souris_liste.push_back(new Souris(main_window));
  //   souris_liste[i]->seDeplacer(150*i);
  // }
  unsigned int seed = static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count());
  std::default_random_engine generator(seed);
  // std::uniform_int_distribution<int> distribution(5000, 8000); // intervalle de temps aléatoire entre 0.5 et 3 secondes
  std::uniform_int_distribution<int> distribution(200, 3000); 

  auto last_spawn_time = std::chrono::steady_clock::now();
  int spawn_interval = distribution(generator);

  int vitesse_souris=10;
  sf::Texture *image2 = new sf::Texture();
  image2->loadFromFile("./assets/pointeur.png");
  sf::Sprite * pointeur=new sf::Sprite();
  pointeur->setTexture(*image2);
  pointeur->setPosition(main_window->getSize().x/2.45,main_window->getSize().y/1.85);
  pointeur->setScale(sf::Vector2f(0.5f,0.5f));




  while(main_window->isOpen() && *gameState == 1) {
    // draw_all();
    main_window->clear();
    main_window->draw(*bg);
    main_window->draw(*pointeur);
    auto current_time = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_spawn_time).count();

    if (elapsed_time > spawn_interval) {
    souris_liste.push_back(new Souris(main_window));
    last_spawn_time = current_time;
    spawn_interval = distribution(generator);
  }

    for (auto it = souris_liste.begin(); it != souris_liste.end();) {
      (*it)->seDeplacer(vitesse_souris);
      main_window->draw(*(*it)->sprite);

    if ((*it)->position.x > main_window->getSize().x) {
      it = souris_liste.erase(it);
    } else {
      ++it;
    }
  }
  
    // for (int i = 0; i < nb_souris; i++) {
    //   souris_liste[i]->seDeplacer(10);
    //   main_window->draw(*souris_liste[i]->sprite);


    //   if (souris_liste[i]->position.x > main_window->getSize().x) {
    //     souris_liste[i]->position.x = -130;
    //   }
    // }
    main_window->draw(*chat->sprite);
    print_score(nb_souris_attrape,nb_souris_attrape_max);
    main_window->display();

    // for (int i = 0; i < 100; i++) {
    //   souris->seDeplacer(2);
    //   main_window->clear();
    //   main_window->draw(*bg);
    //   main_window->draw(*souris->sprite);
    //   main_window->display();
    // }

    loop_events(chat,souris_liste);
    if ((nb_souris_attrape/nb_souris_attrape_max)>inc_vitesse/6){
      vitesse_souris+=8;
      inc_vitesse++;
      std::cout<<"vitesse_souris"<<vitesse_souris<<std::endl;
      std::cout<<"inc_vitesse"<<inc_vitesse<<std::endl;
    }
    if (nb_souris_attrape>nb_souris_attrape_max){
      *gameState=4;



    }
  
  }

}





