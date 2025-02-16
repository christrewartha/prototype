#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <nds.h>
#include <nds/arm9/input.h>
#include <stdio.h>
#include "GLFontManager.h"
#include "AudioManager.h"

class PauseMenu {
public:
    PauseMenu() : selectedOption(0) {
        // Initialize menu options
        menuOptions[0] = "RESUME GAME";
        menuOptions[1] = "MAIN MENU";
        menuOptions[2] = "DISABLE MUSIC";
        menuOptions[3] = "EXIT";
    }

    void init() {
        selectedOption = 0;
        resumeGame = false;
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
                resumeGame = true;
            } else if (selectedOption == 1) {
                // View High Scores
                mainMenu = true;
            } else if (selectedOption == 2) {
                // Toggle Music
                AudioManager::getInstance().toggleMusic();
                if(AudioManager::getInstance().isMusicEnabled()) {
                    AudioManager::getInstance().startMenuMusic();
                    menuOptions[2] = "DISABLE MUSIC";
                } else {
                    AudioManager::getInstance().stopMusic();
                    menuOptions[2] = "ENABLE MUSIC";
                }
            } else if (selectedOption == 3) {
                // Exit
                exit = true;
            }
        }
    }

    void render() {
        glColor(RGB15(31, 31, 31));
        GLFontManager::getInstance().renderTextCentered(0, 25, "PAUSE MENU", true);
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
        if(selectedOption == 3) 
            glColor(RGB15(31, 31, 31));
        else
            glColor(RGB15(15, 15, 15));
        GLFontManager::getInstance().renderTextCentered(0, 150, menuOptions[3]);
    }

    bool isResumeGame() {
        return resumeGame;
    }

    bool isMainMenu() {
        return mainMenu;
    }   

    bool isExit() {
        return exit;
    }

private:
    static const int NUM_OPTIONS = 4; // Number of menu options
    const char* menuOptions[NUM_OPTIONS]; // Menu options
    int selectedOption; // Currently selected option
    bool resumeGame = false;
    bool mainMenu = false;
    bool exit = false;
};

#endif // PAUSEMENU_H 