#include <stdio.h>
#include <gl2d.h>
#include <ctime>
#include <stdlib.h>
#include <nds.h>
#include "GameState.h"
#include "Character.h"
#include "Door.h"
#include "Game.h"
#include "CompanyLogo.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "GameOverScreen.h"
#include "HighScoreTable.h"
#include "PauseMenu.h"
#include "GLFont.h" // Include the new Font class
#include "GLFontManager.h" // Include the GLFontManager class
#include "AudioManager.h"

#include "SpriteManager.h"

// Ensure that all includes are above the class definition
class App {
public:
    App() 
	{}

    void init() {
        // Initialize the DS
        videoSetMode(MODE_5_3D);
        glScreen2D();

        //set up enough texture memory for our textures
        vramSetBankA( VRAM_A_TEXTURE );

        // Very Important!!! Or you get black sprites
        vramSetBankE(VRAM_E_TEX_PALETTE);  // Allocate VRAM bank for all the palettes

        SpriteManager::getInstance().loadSprites();
        // Initialize the font manager
        GLFontManager::getInstance().init();
        AudioManager::getInstance().init();

        currentState = COMPANY_LOGO;
        companyLogo.init();

        //AudioManager::getInstance().startMusic();


    }

    void run() {
        int frame = 0;

        srand(time(NULL));

		bool running = true;  
        while (running) {
            frame++;

            scanKeys();
            glBegin2D();

            // Update and render based on the current game state
            switch (currentState) {
                case COMPANY_LOGO:
                    companyLogo.update();
                    companyLogo.render();
                    if(companyLogo.isFinished()) {
                        currentState = SPLASH_SCREEN;
                        splashScreen.init();
                    }
                    break;
                case SPLASH_SCREEN:
                    splashScreen.update();
                    splashScreen.render();
                    if(splashScreen.isFinished()) {
                        currentState = MAIN_MENU    ;
                        mainMenu.init();
                        AudioManager::getInstance().startMenuMusic();
                    }   
                    break;
                case MAIN_MENU:
                    mainMenu.update();
                    mainMenu.render();
                    if(mainMenu.isStartGame()) {
                        currentState = GAME;
                        game.init();
                        AudioManager::getInstance().stopMusic();
                        AudioManager::getInstance().startGameMusic();
                    }
                    if(mainMenu.isHighScores()){
                        currentState = HIGH_SCORE_TABLE;
                        highScoreTable.init();
                    }
                    break;
                case GAME:
                    game.update();
                    game.display();

                    if(game.isGameOver()) {
                        currentState = GAME_OVER;
                        gameOverScreen.init();
                        AudioManager::getInstance().stopMusic();
                        AudioManager::getInstance().startMenuMusic();
                    }
                    else if(game.shouldPause()) {
                        currentState = PAUSE_MENU;
                        pauseMenu.init();
                        AudioManager::getInstance().pauseMusic();
                    }
                    break;  
                case PAUSE_MENU:
                    pauseMenu.update();
                    pauseMenu.render();
                    if(pauseMenu.isResumeGame()) {
                        currentState = GAME;
                        game.clearPause();
                        AudioManager::getInstance().resumeMusic();
                    }
                    if(pauseMenu.isMainMenu()) {
                        currentState = MAIN_MENU;
                        mainMenu.init();
                        AudioManager::getInstance().startMenuMusic();
                    }
                    break;
                case GAME_OVER:
                    gameOverScreen.update();
                    gameOverScreen.render();
                    if(gameOverScreen.isRestartGame()) {
                        currentState = GAME;
                        game.init();
                        AudioManager::getInstance().stopMusic();
                        AudioManager::getInstance().startGameMusic();
                    }
                    if(gameOverScreen.isMainMenu()) {
                        currentState = MAIN_MENU;
                        mainMenu.init();
                    }
                    break;
                case HIGH_SCORE_TABLE:
                    highScoreTable.update();
                    highScoreTable.render();
                    if(highScoreTable.isDone())
                    {
                        currentState = MAIN_MENU;
                        mainMenu.init();
                    }
                    break;
            }


            glEnd2D();
            glFlush(0);
            swiWaitForVBlank();
        }
    }

    void cleanup() {
    }

private:
    GameState currentState; 
	Game game;
    CompanyLogo companyLogo;
    SplashScreen splashScreen;
    MainMenu mainMenu;
    GameOverScreen gameOverScreen;
    HighScoreTable highScoreTable;
    PauseMenu pauseMenu;
};

int main() {
    App app; // Create an instance of App
    app.init(); // Initialize the app
    app.run(); // Run the main loop
    app.cleanup(); // Clean up resources
    return 0;
}
