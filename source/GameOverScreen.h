#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <nds.h>
#include <stdio.h>
#include "GLFontManager.h"

class GameOverScreen {
public:
    GameOverScreen() : selectedOption(0) {
        // Initialize menu options
        menuOptions[0] = "Restart Game";
        menuOptions[1] = "Main Menu";
        menuOptions[2] = "Exit";
    }

    void init() {
        selectedOption = 0;
        restartGame = false;
        mainMenu = false;
        exit = false;
    }

    void update() {
        // Read the current keys pressed
        int keys = keysDown();

        // Navigate through menu options
        if (keys & KEY_UP) {
            selectedOption = (selectedOption - 1 + NUM_OPTIONS) % NUM_OPTIONS; // Wrap around
        }
        if (keys & KEY_DOWN) {
            selectedOption = (selectedOption + 1) % NUM_OPTIONS; // Wrap around
        }

        // Select option
        if (keys & KEY_A) {
            // Handle selection
            if (selectedOption == 0) {
                // Restart Game
                restartGame = true;
            } else if (selectedOption == 1) {
                // Return to Main Menu
                mainMenu = true;
            } else if (selectedOption == 2) {
                // Exit
                exit = true;
            }
        }
    }

    void render() {
        glColor(RGB15(31, 31, 31));
        GLFontManager::getInstance().renderTextCentered(0, 25, "GAME OVER", true);
        if(selectedOption == 0) 
            glColor(RGB15(31, 31, 31));
        else
            glColor(RGB15(15, 15, 15));
        GLFontManager::getInstance().renderTextCentered(0, 75, menuOptions[0]);
        if(selectedOption == 1) 
            glColor(RGB15(31, 31, 31));
        else
            glColor(RGB15(15, 15, 15));
        GLFontManager::getInstance().renderTextCentered(0, 100, menuOptions[1]);
        if(selectedOption == 2) 
            glColor(RGB15(31, 31, 31));
        else
            glColor(RGB15(15, 15, 15));
        GLFontManager::getInstance().renderTextCentered(0, 125, menuOptions[2]);
        glColor(RGB15(31, 31, 31));
    }

    bool isRestartGame() {
        return restartGame;
    }

    bool isMainMenu() {
        return mainMenu;
    }   
    
    bool isExit() {
        return exit;
    }

private:
    static const int NUM_OPTIONS = 3; // Number of menu options
    const char* menuOptions[NUM_OPTIONS]; // Menu options
    int selectedOption; // Currently selected option
    bool restartGame = false;
    bool mainMenu = false;
    bool exit = false;
};

#endif // GAMEOVERSCREEN_H 