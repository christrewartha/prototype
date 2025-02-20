#ifndef MAINMENU_H
#define MAINMENU_H

#include <nds.h>
#include <nds/arm9/input.h>
#include <stdio.h>
#include "GLFontManager.h"
#include "AudioManager.h"
#include "SpriteManager.h"

class MainMenu {
public:
    MainMenu() : selectedOption(0) {
        // Initialize menu options
        menuOptions[0] = "START GAME";
        menuOptions[1] = "HIGH SCORES";
        menuOptions[2] = "DISABLE MUSIC";
        menuOptions[3] = "EXIT";
    }

    void init() {
        selectedOption = 0;
        startGame = false;
        highScores = false;
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
                startGame = true;
            } else if (selectedOption == 1) {
                // View High Scores
                highScores = true;
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
        glBoxFilled(0, 0, 256, 192, RGB15(31, 31, 31));
        SpriteManager::getInstance().drawSprite(Sprites::WESTBANK_LOGO, 
                148, 
                110,
                RGB15(31, 31, 31),
                true,
                1 << 11,
                1 << 11,
                0);
        glColor(RGB15(31, 31, 31));
        GLFontManager::getInstance().renderTextCentered(0, 50, "MAIN MENU", true);
        if(selectedOption == 0) 
            glColor(RGB15(31, 31, 31));
        else
            glColor(RGB15(15, 15, 15));
        GLFontManager::getInstance().renderText(25, 100, menuOptions[0]);
        if(selectedOption == 1) 
            glColor(RGB15(31, 31, 31));
        else
            glColor(RGB15(15, 15, 15));
        GLFontManager::getInstance().renderText(25, 120, menuOptions[1]);
        if(selectedOption == 2) 
            glColor(RGB15(31, 31, 31));
        else
            glColor(RGB15(15, 15, 15));
        GLFontManager::getInstance().renderText(25, 140, menuOptions[2]);
        if(selectedOption == 3) 
            glColor(RGB15(31, 31, 31));
        else
            glColor(RGB15(15, 15, 15));
        GLFontManager::getInstance().renderText(25, 160, menuOptions[3]);
    
        SpriteManager::getInstance().draw();
    }

    bool isStartGame() {
        return startGame;
    }

    bool isHighScores() {
        return highScores;
    }   

    bool isExit() {
        return exit;
    }

private:
    static const int NUM_OPTIONS = 4; // Number of menu options
    const char* menuOptions[NUM_OPTIONS]; // Menu options
    int selectedOption; // Currently selected option
    bool startGame = false;
    bool highScores = false;
    bool exit = false;
};

#endif // MAINMENU_H 