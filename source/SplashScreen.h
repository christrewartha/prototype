#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <nds.h>
#include <stdio.h>
#include "GLFontManager.h"
#include "SpriteManager.h"

class SplashScreen {
public:
    SplashScreen() : displayTime(120), elapsedTime(0) {} // Display for 120 frames

    void init() {
        displayTime = 120;
        elapsedTime = 0;
    }

    void update() {
        if (elapsedTime < displayTime) {
            elapsedTime++;
        } else {
            // Transition to the next state (e.g., MAIN_MENU)
            // You can set a flag or call a function to notify the App
        }
    }

    void render() {
        //GLFontManager::getInstance().renderTextCentered(0, 96, "SPLASH SCREEN");
        SpriteManager::getInstance().drawSprite(Sprites::WESTBANK_LOGO, 0, 0);
    }

    bool isFinished() const {
        return elapsedTime >= displayTime;
    }

private:
    int displayTime; // Time to display the splash screen
    int elapsedTime; // Time elapsed since display started
};

#endif // SPLASHSCREEN_H 