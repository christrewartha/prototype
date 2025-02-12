#ifndef CHARACTER_H
#define CHARACTER_H

#include <nds.h>
#include <gl2d.h>
#include "Player.h"

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
    int time_to_leave;
    static const int TIME_TO_LEAVE = 300;
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
        time_to_leave = TIME_TO_LEAVE;
        character_x_margin = 5;
        character_y_margin = 15;
        character_width = 50;
        character_height = 95;
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
    static const int TIME_TO_SHOOT = 100;
    int time_to_shoot;
    bool has_shot;
    Robber(int index, int x, int y, glImage* spr): Character(CharacterType::ROBBER, index, x, y, true, spr) 
    {
        character_x_margin = 5;
        character_y_margin = 15;
        character_width = 50;
        character_height = 95;

        is_alive = true;
        time_to_shoot = TIME_TO_SHOOT;
        has_shot = false;
    }

    void shoot() {
        // Play shooting animation/sound
        // Check for collision with player (and decrease player health if hit)
        if(!has_shot && is_alive) {
            has_shot = true;    
            Player::getInstance().decreasePlayerLives();
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
                    RGB15(0, 0, 0));

            if(has_shot) {
                glBoxFilled(xPos + 30,yPos + 50,xPos + 50,yPos + 70,RGB15(255,0,0));
            }
        }
        //glSprite(x + x_margin, y + y_margin, GL_FLIP_NONE, sprite);
    }
};

// Client class (inherits from Character)
class Client: public Character {
public:
    Client(int index, int x, int y, glImage* spr): Character(CharacterType::CLIENT, index, x, y, false, spr) 
    {   
        character_x_margin = 5;
        character_y_margin = 15;
        character_width = 50;
        character_height = 95;

        is_alive = true;
    }

    void depositMoney() {
        // Increase player's score
        // Play sound effect/animation
        Player::getInstance().increasePlayerScore(100);
        Player::getInstance().setDoorCollected(door_index, true);
    }

    void switch_to_robber() {
        // Transform into a Robber (change type, sprite, isAggressive)
    }

    void update() override {
        // Client behavior (e.g., deposit money after a delay)
        Character::update();
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
                    RGB15(0, 0, 255));
        }
    }
};

// HatGuy class (inherits from Character)
class HatGuy: public Character {
public:
    int hats;

    HatGuy(int index, int x, int y, glImage* spr): Character(CharacterType::HAT_GUY, index, x, y, false, spr), hats(5) 
    {
        character_x_margin = 10;
        character_y_margin = 60;
        character_width = 40;
        character_height = 50;

        is_alive = true;
    } // Start with 5 hats

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
        if(hats == 0) {
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
                    RGB15(0, 0, 255));

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
                    RGB15(255, 255, 255));
            }
        }
    }
};

#endif // CHARACTER_H 