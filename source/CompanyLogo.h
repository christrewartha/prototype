#ifndef COMPANYLOGO_H
#define COMPANYLOGO_H

#include <nds.h>
#include <stdio.h>
#include "SpriteManager.h"

class CompanyLogo {
public:
    CompanyLogo() : elapsedTime(0), transitionTime(120) {} // Display for 120 frames

    void init() {
        transitionTime = 120;
        elapsedTime = 0;
    }

    void update() {
        if (elapsedTime < transitionTime) {
            elapsedTime++;
        } else {
            // Transition to the next state (e.g., MAIN_MENU)
            // You can set a flag or call a function to notify the App
        }
    }

    void render() {
        glBoxFilled(0, 0, 256, 192, RGB15(0, 0, 0));
        SpriteManager::getInstance().drawSprite(Sprites::WARTHREAT_LOGO, 64, 32);
    
    }

    bool isFinished() const {
        return elapsedTime >= transitionTime;
    }

private:
    int elapsedTime; // Time elapsed since display started
    int transitionTime; // Time to transition to the next state
};

#endif // COMPANYLOGO_H 
