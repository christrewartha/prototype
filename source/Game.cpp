#include "Game.h"

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
            // Call the door's get_shot method to handle the shot
            doors[i].handleShot(x, y);
            break; // Exit the loop after handling the shot
        }
    }
}

void Game::displayDoorStatus() {
    int x_start = 23; // Starting x position for the door status indicators
    int y_start = 170; // Starting y position for the indicators
    int door_width = 13; // Width of each status indicator
    int door_height = 13; // Height of each status indicator
    int spacing = 5; // Spacing between indicators

    for (int i = 0; i < NUM_DOORS; i++) {
        // Determine the color based on whether the door has been collected from
        u16 color = doorsCollected[i] ? RGB15(0, 255, 0) : RGB15(255, 0, 0); // Green if collected, red if not

        // Draw the status indicator
        glBoxFilled(x_start + (door_width + spacing) * i, 
                    y_start, 
                    x_start + (door_width + spacing) * i + door_width, 
                    y_start + door_height, 
                    color);
    }
}

void Game::display() {
    // Draw the bank background
    glBoxFilled(23, 10, 233, 160, RGB15(200, 200, 200));
    
    // Draw the visible doors (using Door::display())
    for(int i = 0; i < DOORS_DISPLAYED; i++) {
        doors[i].display();
    }

    // Display the door status indicators
    displayDoorStatus();

    // Display player score and lives
    // Example positions for score and lives
    glColor(RGB15(0, 0, 0)); // Set color to black for text
    // Display score
//    char scoreText[20];
//    sprintf(scoreText, "Score: %d", playerScore);
//    glPrint(10, 170, scoreText); // Adjust position as needed

    // Display lives
//    char livesText[20];
//    sprintf(livesText, "Lives: %d", playerLives);
//    glPrint(10, 190, livesText); // Adjust position as needed
}

