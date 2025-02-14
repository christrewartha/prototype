#ifndef CHARACTER_H
#define CHARACTER_H

#include <nds.h>
#include <gl2d.h>
#include "Player.h"
#include "AudioManager.h"

// Define character types as an enum for clarity
enum class CharacterType {
    ROBBER,
    CLIENT,
    HAT_GUY
};

// Base Character class
class Character {
public:
    CharacterType type;
    int door_index;
    int xPos, yPos;
    bool isAggressive;
    bool done;
    bool is_alive;
    bool make_switch_to_robber;
    int time_to_leave;
    static const int MAX_TIME_TO_LEAVE = 300;
    static const int MIN_TIME_TO_LEAVE = 100;
    static const int TIME_TO_LEAVE_DECREASE = 10;
    glImage* sprite;  // Pointer to the glImage for this character
    int character_x_margin;
    int character_y_margin;
    int character_width;
    int character_height;


    Character(CharacterType t, int index, int x, int y, bool aggressive, glImage* spr) 
      : type(t), door_index(index), xPos(x), yPos(y), isAggressive(aggressive), sprite(spr) 
      {
        done = false;
        is_alive = true;
        time_to_leave = MAX_TIME_TO_LEAVE - (TIME_TO_LEAVE_DECREASE * Player::getInstance().getRound()); // GAMEDIFFICULTY
        time_to_leave = time_to_leave < MIN_TIME_TO_LEAVE ? MIN_TIME_TO_LEAVE : time_to_leave;
        character_x_margin = 5;
        character_y_margin = 15;
        character_width = 50;
        character_height = 95;
        make_switch_to_robber = false;
      } 

    virtual ~Character() {}

    virtual void display() 
    {
        // Basic sprite drawing (you'll likely want to customize this)
        //glSprite(xPos, yPos, GL_FLIP_NONE, sprite); 
    }

    virtual void update() {
        // Handle character-specific actions in derived classes
        time_to_leave--;
        if(time_to_leave <= 0) {
            depositMoney();
            done = true;
        }
    }

    virtual void get_shot() {
        // Default behavior for getting shot
        // This can be overridden in derived classes
    }

    virtual void depositMoney() {
        // Default behavior for depositing money
        // This can be overridden in derived classes
    }

    virtual bool is_done() {
        return done;
    }

    virtual bool should_switch_to_robber() {
        return make_switch_to_robber;
    }

    // Declare the handleShot function
    void handleShot(int x, int y)
    {
        if(is_alive) {
            if(x >= xPos + character_x_margin &&
                x <= (xPos + character_x_margin + character_width) && 
                y >= yPos + character_y_margin && 
                y <= (yPos + character_y_margin + character_height)) {
                get_shot();
            }
        }
    }
};

// Robber class (inherits from Character)
class Robber: public Character {
public:
    static const int MAX_TIME_TO_SHOOT = 100;
    static const int MIN_TIME_TO_SHOOT = 30; // GAMEDIFFICULTY
    static const int TIME_TO_SHOOT_DECREASE = 5;
    int time_to_shoot;
    bool has_shot;
    Robber(int index, int x, int y, glImage* spr): Character(CharacterType::ROBBER, index, x, y, true, spr) 
    {
        character_x_margin = 5;
        character_y_margin = 15;
        character_width = 50;
        character_height = 95;

        is_alive = true;
        time_to_shoot = MAX_TIME_TO_SHOOT - (TIME_TO_SHOOT_DECREASE * Player::getInstance().getRound());
        time_to_shoot = time_to_shoot < MIN_TIME_TO_SHOOT ? MIN_TIME_TO_SHOOT : time_to_shoot;
        has_shot = false;
    }

    void shoot() {
        // Play shooting animation/sound
        // Check for collision with player (and decrease player health if hit)
        if(!has_shot && is_alive) {
            has_shot = true;    
            Player::getInstance().decreasePlayerLives();
            AudioManager::getInstance().playGunshot();
        }
    }

    void update() override {
        // Robber AI (e.g., move towards player, decide when to shoot)
        Character::update();
        time_to_shoot--;
        if(time_to_shoot <= 0) {
            shoot();
        }
    }

    void get_shot() override {
        // increase player score - if the robber hasn't shot yet
        if(!has_shot) {
            //player_score += 100;
        }

        // kill the robber
        is_alive = false;
    }

    void display() override {

        if(is_alive) {
            glBoxFilled(xPos + character_x_margin, 
                    yPos + character_y_margin, 
                    xPos + character_x_margin + character_width, 
                    yPos + character_y_margin + character_height, 
                    RGB15(0,0,0));

            if(has_shot) {
                glBoxFilled(xPos + 30,yPos + 50,xPos + 50,yPos + 70,RGB15(255,165,0));
            }
        }
        //glSprite(x + x_margin, y + y_margin, GL_FLIP_NONE, sprite);
    }
};

// Client class (inherits from Character)
class Client: public Character {
public:
    bool is_robber_switch;
    int time_to_switch;
    static const int MAX_TIME_TO_SWITCH = 100;
    static const int MIN_TIME_TO_SWITCH = 30; // GAMEDIFFICULTY
    static const int TIME_TO_SWITCH_DECREASE = 5;

    Client(int index, int x, int y, glImage* spr): Character(CharacterType::CLIENT, index, x, y, false, spr) 
    {   
        character_x_margin = 5;
        character_y_margin = 15;
        character_width = 50;
        character_height = 95;

        is_robber_switch = rand() % 2 == 0;
        time_to_switch = MAX_TIME_TO_SWITCH - (TIME_TO_SWITCH_DECREASE * Player::getInstance().getRound());
        time_to_switch = time_to_switch < MIN_TIME_TO_SWITCH ? MIN_TIME_TO_SWITCH : time_to_switch; 

        is_alive = true;
    }

    void depositMoney() {
        // Increase player's score
        // Play sound effect/animation
        if(is_alive) {
            Player::getInstance().increasePlayerScore(100);
            Player::getInstance().setDoorCollected(door_index, true);
        }
    }

    void switch_to_robber() {
        make_switch_to_robber = true;
    }

    void update() override {
        // Client behavior (e.g., deposit money after a delay)
        Character::update();

        // switch to robber after a delay
        if(is_robber_switch) {
            time_to_switch--;
            if(time_to_switch <= 0) {
                switch_to_robber();
            }
        }
    }

    void get_shot() override {
        // Specific behavior for when the client gets shot
        // E.g., decrease player life
        Player::getInstance().decreasePlayerLives();
        is_alive = false;
    }

    void display() override {
        if(is_alive) {
            glBoxFilled(xPos + character_x_margin, 
                    yPos + character_y_margin, 
                    xPos + character_x_margin + character_width, 
                    yPos + character_y_margin + character_height, 
                    RGB15(85,107,47));
        }
    }
};

// HatGuy class (inherits from Character)
class HatGuy: public Character {
public:
    int hats;

    HatGuy(int index, int x, int y, glImage* spr): Character(CharacterType::HAT_GUY, index, x, y, false, spr) 
    {
        character_x_margin = 10;
        character_y_margin = 60;
        character_width = 40;
        character_height = 50;

        is_alive = true;
        // start with 3 to 5 hats
        hats = 3 + rand() % 3;
    } 

    void loseHat() {
        hats--;
        if (hats < 0) {
            is_alive = false;
            Player::getInstance().decreasePlayerLives();
        }
    }

    void update() override {
        // HatGuy animation (e.g., maybe he juggles hats?)
        Character::update();
    }

    void get_shot() override {
        loseHat();
    }

    void depositMoney() {
        if(hats == 0 && is_alive) {
            // Increase player's score
            // Play sound effect/animation
            Player::getInstance().increasePlayerScore(100);
            Player::getInstance().setDoorCollected(door_index, true);
        }
    }

    void display() override {
        // Draw the HatGuy sprite at the specified position
        if(is_alive) {  
            glBoxFilled(xPos + character_x_margin, 
                    yPos + character_y_margin, 
                    xPos + character_x_margin + character_width, 
                    yPos + character_y_margin + character_height, 
                    RGB15(70,130,180));

            // draw the hats    
            int hat_x_margin = 25;
            int hat_y_margin = 60;
            int hat_width = 10;
            int hat_height = 10;
            int hat_spacing = 3;    
            for(int i = 0; i < hats; i++) 
            {
                glBoxFilled(xPos + hat_x_margin, 
                    yPos + hat_y_margin - (hat_height + hat_spacing) * i, 
                    xPos + hat_x_margin + hat_width, 
                    yPos + hat_y_margin - (hat_height + hat_spacing) * i + hat_height, 
                    RGB15(0,0,139));
            }
        }
    }
};

#endif // CHARACTER_H 