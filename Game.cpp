#include<SFML/Graphics.hpp>
#include "MainMenu.cpp"
#include "MainGame.cpp"
#include "GameSettings.h"

using namespace sf;
Game game;

int main()
{
    int score,highestscore=0;

    RenderWindow MENU(VideoMode(video_width,video_height), "Main Menu", Style::Default);
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

    //set main menu background
    RectangleShape background;
    background.setSize(Vector2f(video_width,video_height));
    Texture MainTexture;
    MainTexture.loadFromFile("resources/sand.jpg");
    background.setTexture(&MainTexture);


    while(MENU.isOpen()) {
        Event event;
        while(MENU.pollEvent(event)) {
            if(event.type == Event::Closed)
                MENU.close();
            if(event.type == Event::KeyReleased) {
                if(event.key.code == Keyboard::Up) {
                    mainMenu.MoveUp();
                    break;
                }
                if(event.key.code == Keyboard::Down) {
                    mainMenu.MoveDown();
                    break;
                }
                if(event.key.code == Keyboard::Return) {
                    int x = mainMenu.MainMenuPressed();
                    
                    if(x==0)
                    {
                        score = game.Run();
                        highestscore = score > highestscore ? score : highestscore;
                    }
                    if(x==1) {
                        RenderWindow HIGHSCORE(VideoMode(video_width,video_height),"Highest Score",Style::Default);
                        while(HIGHSCORE.isOpen()) {
                            Event aevent;
                            while(HIGHSCORE.pollEvent(aevent)) {
                                if(aevent.type == Event::Closed)
                                    HIGHSCORE.close();
                                if(aevent.type == Event::KeyPressed) {
                                    if(aevent.key.code == Keyboard::Escape || aevent.key.code == Keyboard::Return)
                                        HIGHSCORE.close();
                                }
                            }

                            Text highscore_text, display_highest_score;
                            Font highscore_font;
                            highscore_font.loadFromFile("resources/Roboto-Bold.ttf");
                            
                            display_highest_score.setFont(highscore_font);
                            display_highest_score.setString("Highest Score");
                            display_highest_score.setCharacterSize(font_size+10);
                            display_highest_score.setFillColor(Color::Red);
                            display_highest_score.setPosition(video_width/2-180,120);

                            highscore_text.setFont(highscore_font);
                            highscore_text.setString(sf::String(std::to_string(highestscore)));
                            highscore_text.setCharacterSize(font_size);
                            highscore_text.setFillColor(Color::Blue);
                            highscore_text.setPosition(video_width/2-10,250);

                            HIGHSCORE.clear();
                            HIGHSCORE.draw(background);
                            HIGHSCORE.draw(display_highest_score);
                            HIGHSCORE.draw(highscore_text);
                            HIGHSCORE.display();
                        }
                    }
                    if(x==2) {
                        RenderWindow ABOUT(VideoMode(video_width,video_height),"About");
                        while(ABOUT.isOpen()) {
                            Event aevent;
                            while(ABOUT.pollEvent(aevent)) {
                                if(aevent.type == Event::Closed)
                                    ABOUT.close();
                                if(aevent.type == Event::KeyPressed) {
                                    if(aevent.key.code == Keyboard::Escape)
                                        ABOUT.close();
                                }
                            }
                            // PLAY.close();
                            // ABOUT.clear();
                            // ABOUT.display();
                        }
                    }
                    if(x==3)
                        MENU.close();
                    break;
                }
            }
        }
        MENU.clear();
        MENU.draw(background);
        mainMenu.draw(MENU);
        MENU.display();
    }
}
