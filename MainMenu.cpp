#include "MainMenu.h"
#include "GameSettings.h"

MainMenu::MainMenu(float width, float height) {
    if(!font.loadFromFile("resources/Roboto-Bold.ttf")) {
        cout << "No Font Found!";
    }

    //Play
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(font_size);
    mainMenu[0].setPosition(video_width/2-50 ,200);

    //Highest Score
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Highest Score");
    mainMenu[1].setCharacterSize(font_size);
    mainMenu[1].setPosition(video_width/2-160,280);

    //About
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("About");
    mainMenu[2].setCharacterSize(font_size);
    mainMenu[2].setPosition(video_width/2-70,360);

    //Exit
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::White);
    mainMenu[3].setString("Exit");
    mainMenu[3].setCharacterSize(font_size);
    mainMenu[3].setPosition(video_width/2-50,440);

    MainMenuSelected = -1;
}

MainMenu::~MainMenu() {

}

void MainMenu::draw(RenderWindow& window)
{
    Text title;
    title.setFont(font);
    title.setFillColor(Color::Red);
    title.setString("Train Game");
    title.setStyle(Text::Bold | Text::Underlined);
    title.setCharacterSize(font_size+30);
    title.setPosition(video_width/2-200,30);

    window.draw(title);

    for(int i=0;i<max_menu_list;i++)
        window.draw(mainMenu[i]);
}

void MainMenu::MoveUp() {
    if(MainMenuSelected >= 0) {
        mainMenu[MainMenuSelected].setFillColor(Color::White);

        MainMenuSelected--;
        if(MainMenuSelected == -1)
            MainMenuSelected = max_menu_list-1;
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}

void MainMenu::MoveDown() {
    if(MainMenuSelected+1 <= max_menu_list) {
        mainMenu[MainMenuSelected].setFillColor(Color::White);

        MainMenuSelected++;
        if(MainMenuSelected == max_menu_list)
            MainMenuSelected = 0;
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}