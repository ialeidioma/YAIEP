#include <SFML/Graphics.hpp>
#include "MainMenu.h"
using namespace sf;

int main()
{
    RenderWindow MENU(VideoMode(960, 720), "Main Menu", Style::Default);
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
    
    //set background ***UNCOMMENT WHEN BG IS AROUND***
/*  
    RectangleShape menuBG
    menuBG.setSize(Vector2f(960, 720));
    Texture menutexture;
    menutexture.loadFromFile("Texture/MenuBackground.jpeg");
    menuBG.setTexture(&menutexture);
*/

//repeat these lines for different backgrounds

    RectangleShape aboutBG;
    aboutBG.setSize(Vector2f(960, 720));
    Texture abouttexture;
    abouttexture.loadFromFile("Textures/Scripted.png");
    aboutBG.setTexture(&abouttexture);


//Testing Mouse Functionalities
    Mouse::setPosition(Vector2i(400, 200),MENU);

    while (MENU.isOpen())
    {

        Event event;
        
        while (MENU.pollEvent(event))
        {
            if (event.type == Event::Closed)
                MENU.close();
            
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up) {
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == Keyboard::Down) {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == Keyboard::Return) {
                    RenderWindow Play(VideoMode(960, 720), "YAIEP");
                    RenderWindow OPTIONS(VideoMode(960, 720), "Options");
                    RenderWindow ABOUT(VideoMode(960, 720), "About");
                    
                    int x = mainMenu.MainMenuPressed();
                    if (x == 0) {
                        while (Play.isOpen())
                        {
                            Event aevent;
                            while (Play.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed) {
                                    Play.close();
                                }
                                

                                if (aevent.type == Event::KeyReleased) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        Play.close();
                                    }
                                }
                            }
                            OPTIONS.close();
                            ABOUT.close();
                            Play.clear();
                            Play.display();
                        }
                    }
                    if (x == 1)
                    {
                        while (OPTIONS.isOpen())
                        {
                            Event aevent;
                            while (OPTIONS.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                    OPTIONS.close();

                                if (aevent.type == Event::KeyReleased) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        OPTIONS.close();
                                    }
                                }
                            }
                            Play.close();
                            ABOUT.close();
                            OPTIONS.clear();
                            OPTIONS.display();

                        }
                    }
                    if (x == 2)
                    {
                        while (ABOUT.isOpen())
                        {
                            Event aevent;
                            while (ABOUT.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                    ABOUT.close();

                                if (aevent.type == Event::KeyReleased) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        ABOUT.close();
                                    }
                                }
                            }
                            Play.close();
                            OPTIONS.close();
                            ABOUT.clear();
                            ABOUT.draw(aboutBG);
                            ABOUT.display();

                        }
                    }
                    if (x == 3)
                        MENU.close();
                    break;
                }
            }

            int Mx = Mouse::getPosition(MENU).x;
            int My = Mouse::getPosition(MENU).y;

            if (Mx > 350 && Mx < 600 && My > 200 && My < 270) {
                mainMenu.MainMenuSelected = 0;
                mainMenu.Selected();
            }
            else if(Mx > 350 && Mx < 800 && My > 300 && My < 370) {
                mainMenu.MainMenuSelected = 1;
                mainMenu.Selected();
            }
            else if(Mx > 350 && Mx < 700 && My > 400 && My < 470) {
                mainMenu.MainMenuSelected = 2;
                mainMenu.Selected();
            }
            else if(Mx > 350 && Mx < 700 && My > 500 && My < 570) {
                mainMenu.MainMenuSelected = 3;
                mainMenu.Selected();
            }
            else {
                mainMenu.Unselected();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    RenderWindow Play(VideoMode(960, 720), "YAIEP");
                    RenderWindow OPTIONS(VideoMode(960, 720), "Options");
                    RenderWindow ABOUT(VideoMode(960, 720), "About");
                    
                    if (Mx > 350 && Mx < 600 && My > 200 && My < 270) {
                        while (Play.isOpen())
                        {
                            Event aevent;
                            while (Play.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                    Play.close();

                                if (aevent.type == Event::KeyReleased) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        Play.close();
                                    }
                                }
                            }
                            OPTIONS.close();
                            ABOUT.close();
                            Play.clear();
                            Play.display();

                        }
                    }
                    if (Mx > 350 && Mx < 800 && My > 300 && My < 370)
                    {
                        while (OPTIONS.isOpen())
                        {
                            Event aevent;
                            while (OPTIONS.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                    OPTIONS.close();

                                if (aevent.type == Event::KeyReleased) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        OPTIONS.close();
                                    }
                                }
                            }
                            Play.close();
                            ABOUT.close();
                            OPTIONS.clear();
                            OPTIONS.display();

                        }
                    }
                    if (Mx > 350 && Mx < 700 && My > 400 && My < 470)
                    {
                        while (ABOUT.isOpen())
                        {
                            Event aevent;
                            while (ABOUT.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                    ABOUT.close();

                                if (aevent.type == Event::KeyReleased) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        ABOUT.close();
                                    }
                                }
                            }
                            Play.close();
                            OPTIONS.close();
                            ABOUT.clear();
                            ABOUT.draw(aboutBG);
                            ABOUT.display();

                        }
                    }
                    if (Mx > 350 && Mx < 700 && My > 500 && My < 570)
                        MENU.close();
                    break;
                }
            }
        }

        MENU.clear();
//        MENU.draw(menuBG);
        mainMenu.draw(MENU);
        MENU.display();
    }

}