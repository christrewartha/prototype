#include "Game.h"
#include "GLFontManager.h"
#include <cstdio>
#include "Player.h"
#include "AudioManager.h"
#include "SpriteManager.h"



void Game::handleShot(int x, int y) {
    for (int i = 0; i < DOORS_DISPLAYED; i++) {
        // Calculate the x position of the door using the static constants
        int doorX = X_DOOR_POSITION + i * X_DOOR_WIDTH; // Use the static constant for x position
        int doorY = Y_DOOR_POSITION; // Use the static constant for y position
        int doorWidth = X_DOOR_WIDTH; // Use the static constant for width
        int doorHeight = Y_DOOR_HEIGHT; // Use the static constant for height

        // Check if the shot coordinates are within the bounds of the door
        if (x >= doorX &&
            x <= (doorX + doorWidth) && 
            y >= doorY && 
            y <= (doorY + doorHeight)) 
        {
            // Call the door's handleShot method to handle the shot
            doors[i].handleShot(x, y);

            break; // Exit the loop after handling the shot
        }
    }
    AudioManager::getInstance().playGunshot();
}

bool Game::doorIsDisplayed(int index) {
    // check if the door is displayed in the current round
    for(int i = 0; i < DOORS_DISPLAYED; i++) 
    {
        if((currentDoorIndex + i) % NUM_DOORS == index) {
            return true;
        }
    }
    return false;
}

void Game::displayDoorStatus() {
    int x_start = 23; // Starting x position for the door status indicators
    int y_start = 170; // Starting y position for the indicators
    int door_width = 13; // Width of each status indicator
    int door_height = 13; // Height of each status indicator
    int spacing = 5; // Spacing between indicators

    for (int i = 0; i < NUM_DOORS; i++) {

        if(doorIsDisplayed(i)) {
            // draw a box around the door
            glBoxFilled(x_start + (door_width + spacing) * i - 3, 
                        y_start - 3, 
                        x_start + (door_width + spacing) * i + door_width + 3, 
                        y_start + door_height + 3, 
                        RGB15(150, 150, 150));
        }
            // Determine the color based on whether the door has been collected from
        u16 color = Player::getInstance().hasDoorBeenCollected(i) ? RGB15(0, 255, 0) : RGB15(255, 0, 0); // Green if collected, red if not

        // Draw the status indicator
        glBoxFilled(x_start + (door_width + spacing) * i, 
                    y_start, 
                    x_start + (door_width + spacing) * i + door_width, 
                    y_start + door_height, 
                    color);
    }
}

void Game::displayPlayerLives() {
    // Display player score
    int x_start = 200;
    int y_start = 5;
    int score_width = 5;
    int score_height = 5;
    int spacing = 2;

    for(int i = 0; i < Player::getInstance().getPlayerLives(); i++) 
    {
        glBoxFilled(x_start + i * (score_width + spacing), 
                    y_start, 
                    x_start + i * (score_width + spacing) + score_width, 
                    y_start + score_height, 
                    RGB15(150, 150, 0));   
    }
}

void Game::display() {
    // Draw the bank background
    glBoxFilled(23, 15, 233, 160, RGB15(200, 200, 200));
    
    // Draw the visible doors (using Door::display())
    for(int i = 0; i < DOORS_DISPLAYED; i++) {
        doors[i].display();
    }

    // Display the door status indicators
    displayDoorStatus();

    displayPlayerLives();

    // Display player score and lives
    // Example positions for score and lives
    glColor(RGB15(31, 31, 31)); // Set color to black for text

    // Display round
    char roundText[20];
    sprintf(roundText, "%d", Player::getInstance().getRound() + 1);
    GLFontManager::getInstance().renderText(2, 2, roundText);

    if(paused)
    {
        GLFontManager::getInstance().renderTextCentered(0, 96, "PAUSED");
    }

    SpriteManager::getInstance().draw();


    if(shot_display_timer > 0) {    
        glBoxFilled(touchX - 2, 
                    touchY - 2, 
                    touchX + 2, 
                    touchY + 2, 
                    RGB15(255, 255, 0));
        shot_display_timer--;
    }

                    
    // Display score
//    char scoreText[20];
//    sprintf(scoreText, "Score: %d", playerScore);
//    glPrint(10, 170, scoreText); // Adjust position as needed

    // Display lives
//    char livesText[20];
//    sprintf(livesText, "Lives: %d", playerLives);
//    glPrint(10, 190, livesText); // Adjust position as needed
}

