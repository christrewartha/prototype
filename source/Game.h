#ifndef GAME_H
#define GAME_H

#include "Door.h" // Include the Door class
#include "Character.h" // Include the Character class
#include "Player.h" // Include the Player class

class Game {
public:
    // Constants
    static const int NUM_DOORS = 12;
    static const int DOORS_DISPLAYED = 3; 

    static const int MAX_TIME_TO_DOOR_OPEN = 120;
    static const int MIN_TIME_TO_DOOR_OPEN = 20;

    static const int TIME_TO_NEXT_ROUND = 120;

    static const int X_DOOR_POSITION = 23;
    static const int X_DOOR_WIDTH = 70;
    static const int Y_DOOR_POSITION = 20;
    static const int Y_DOOR_HEIGHT = 120;

    // Game state
    int currentDoorIndex;            // Index of the leftmost visible door
    

    int time_to_next_round;
    bool between_rounds;
    // Door and character management
    Door doors[DOORS_DISPLAYED]; 
    int door_timer[DOORS_DISPLAYED];

    Game(): currentDoorIndex(0){
        
    }

    void init() {
        Player::getInstance().resetPlayer();
        InitRound();

    }

    void InitRound() 
    {
        // Initialize doors
        for(int i = 0; i < DOORS_DISPLAYED; i++) {
            doors[i].init( (currentDoorIndex + i) % NUM_DOORS, X_DOOR_POSITION + i * X_DOOR_WIDTH, Y_DOOR_POSITION);
            door_timer[i] = rand() % (MAX_TIME_TO_DOOR_OPEN - MIN_TIME_TO_DOOR_OPEN) + MIN_TIME_TO_DOOR_OPEN;
        }   

        time_to_next_round = TIME_TO_NEXT_ROUND;
        between_rounds = false;
        
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
            between_rounds = true;
        }

        if(between_rounds) {
            time_to_next_round--;
            if(time_to_next_round <= 0) {
                InitRound();
            }
        }
        handleInput();  

        checkGameStatus(); 

    }

    void display();

    void displayDoorStatus(); // New method to display door status indicators

    void displayPlayerLives();

    void handleShot(int x, int y); // Declare the handleShot function

    bool doorIsDisplayed(int index); // Declare the doorIsDisplayed method

private:
    void handleInput() {
        if(between_rounds) {
            if(keysDown() & KEY_LEFT) {
                currentDoorIndex--;
                if(currentDoorIndex < 0) {
                    currentDoorIndex = NUM_DOORS - 1;
                }
            }
            if(keysDown() & KEY_RIGHT) {
                currentDoorIndex++;
                if(currentDoorIndex >= NUM_DOORS) {
                    currentDoorIndex = 0;
                }
            }
        }

        if(keysDown() & KEY_UP) {
            Player::getInstance().increaseRound();
        }
        if(keysDown() & KEY_DOWN) {
            Player::getInstance().decreaseRound();
        }
        if(keysDown() & KEY_SELECT) {
            Player::getInstance().setPlayerLives(10);
        }
    }

    void checkGameStatus() {
        bool round_complete = true;
        for(int i = 0; i < NUM_DOORS; i++) 
        {
            if(!Player::getInstance().hasDoorBeenCollected(i)) {
                round_complete = false;
            }
        }

        if(round_complete) {
            Player::getInstance().increaseRound();
            currentDoorIndex = 0;
            InitRound();
            Player::getInstance().resetDoorsCollected();
        }

        // Check if the player has lost all lives
        if(Player::getInstance().getPlayerLives() <= 0) {
            currentDoorIndex = 0;
            InitRound();
            Player::getInstance().resetPlayer();
        }
        // Update round/level if necessary
    }
};

#endif // GAME_H 