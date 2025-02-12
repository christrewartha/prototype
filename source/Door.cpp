#include "Door.h"
#include <cstdlib> // For rand()
#include <gl2d.h> // Include for drawing functions

Door::Door() : openState(false), character(nullptr) {}

void Door::init(int index, int x, int y) {
    xPos = x;
    yPos = y;   
    openState = false;
    unopenedState = true;
    done = false;
    character = nullptr;
    this->index = index;    
    // Randomly select a character type to reveal
    int randomType = rand() % 3; // 0, 1, or 2
    switch (randomType) {
        case 0:
            character = new Robber(index, xPos + X_MARGIN, yPos + Y_MARGIN, nullptr); // Replace nullptr with actual sprite
            break;
        case 1:
            character = new Client(index, xPos + X_MARGIN, yPos + Y_MARGIN, nullptr); // Replace nullptr with actual sprite
            break;
        case 2:
            character = new HatGuy(index, xPos + X_MARGIN, yPos + Y_MARGIN, nullptr); // Replace nullptr with actual sprite
            break;
    }
}

int Door::getIndex() const {
    return index;
}

void Door::open() {
    if (!openState) {
        openState = true;
        unopenedState = false;
    }
}

void Door::close() {
    if (openState) {
        openState = false;
        delete character; // Clean up the character if the door is closed
        character = nullptr;
        done = true; 
    }
}

bool Door::isOpen() const {
    return openState;
}

bool Door::isDone() const {
    return done;
}

Character* Door::getCharacter() {
    return character; // Return the character revealed by the door
}

bool Door::isUnopened() const {
    return unopenedState;
}

void Door::update() {
    if(character) {
        character->update();

        if(character->is_done()) {
            close();
        }
    }
}   

void Door::display() {
    
    // Draw the door based on its state
    if (openState) {
        // Draw the open door (you can customize the appearance)
        glBoxFilled(xPos + X_MARGIN, 
                    yPos + Y_MARGIN, 
                    xPos + X_MARGIN + DOOR_WIDTH, 
                    yPos + Y_MARGIN + DOOR_HEIGHT, 
                    RGB15(0, 255, 0)); // Example: green for open

        if(character) {
            character->display();
        }
    } else {
        // Draw the closed door
        glBoxFilled(xPos + X_MARGIN, 
                    yPos + Y_MARGIN, 
                    xPos + X_MARGIN + DOOR_WIDTH, 
                    yPos + Y_MARGIN + DOOR_HEIGHT,
                    RGB15(255, 0, 0)); // Example: red for closed
    }
}

// Implement the handleShot function
void Door::handleShot(int x, int y) {
    if (character) {
        character->handleShot(x, y); // Pass the shot to the character if it exists
    }
} 

