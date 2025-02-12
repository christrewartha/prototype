#ifndef GAME_H
#define GAME_H

#include "Door.h" // Include the Door class
#include "Character.h" // Include the Character class

class Game {
public:
    // Constants
    static const int NUM_DOORS = 12;
    static const int DOORS_DISPLAYED = 3; 

    static const int MAX_TIME_TO_DOOR_OPEN = 120;
    static const int MIN_TIME_TO_DOOR_OPEN = 20;

    static const int X_DOOR_POSITION = 23;
    static const int X_DOOR_WIDTH = 70;
    static const int Y_DOOR_POSITION = 20;
    static const int Y_DOOR_HEIGHT = 120;

    // Game state
    bool doorsCollected[NUM_DOORS];  // Track which doors have been collected from
    int currentDoorIndex;            // Index of the leftmost visible door
    int playerLives;                 // Player lives
    int playerScore;                 // Player score
    int round;                       // Current round number

    // Door and character management
    Door doors[DOORS_DISPLAYED]; 
    int door_timer[DOORS_DISPLAYED];

    Game(): currentDoorIndex(0), playerLives(3), playerScore(0), round(1) {
        
    }

    void init() {
        // Initialize doorsCollected array to false
        for (int i = 0; i < NUM_DOORS; i++) {
            doorsCollected[i] = false;
        }

        InitRound();

    }

    void InitRound() 
    {
        // Initialize doors
        for(int i = 0; i < DOORS_DISPLAYED; i++) {
            doors[i].init(X_DOOR_POSITION + i * X_DOOR_WIDTH, Y_DOOR_POSITION);
            door_timer[i] = rand() % (MAX_TIME_TO_DOOR_OPEN - MIN_TIME_TO_DOOR_OPEN) + MIN_TIME_TO_DOOR_OPEN;
        }   

    }

    void update() {
        
        bool all_doors_done = true;
        for(int i = 0; i < DOORS_DISPLAYED; i++) 
        {
            if(doors[i].isUnopened()) {
                door_timer[i]--;
                if(door_timer[i] <= 0) {   
                    doors[i].open();
                }
            }  
            if(doors[i].isOpen()) {
                doors[i].update();
            }
            if (!doors[i].isDone()) {
                all_doors_done = false;
            }
            
        }    

        if(all_doors_done) {
            InitRound();
        }


        // 1. Check for player input (shooting, moving between doors)
        handleInput(); 

        // 2. Update doors (open/close, generate characters)
        updateDoors();

        // 3. Update characters in open doors (e.g., robber AI, client actions)
        updateCharacters(); 

        // 4. Check for end of round/level/game
        checkGameStatus(); 
    }

    void display();

    void displayDoorStatus(); // New method to display door status indicators

    void handleShot(int x, int y); // Declare the handleShot function

    // Methods to get and update player score and lives
    int getPlayerScore() const { return playerScore; }
    void increasePlayerScore(int amount) { playerScore += amount; }
    int getPlayerLives() const { return playerLives; }
    void decreasePlayerLives() { playerLives--; }

private:
    void handleInput() {
        // Process player input (shooting, moving between doors)
    }

    void updateDoors() {
        // Logic to open/close doors, move to the next set of doors, etc.
    }

    void updateCharacters() {
        // Update the behavior of characters in the open doors
    }

    void checkGameStatus() {
        // Check if the player has collected from all doors
        // Check if the player has lost all lives
        // Update round/level if necessary
    }
};

#endif // GAME_H 