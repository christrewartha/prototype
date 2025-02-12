#ifndef DOOR_H
#define DOOR_H

#include "Character.h" // Include the Character class

class Door {
public:
    static const int X_MARGIN = 5;  
    static const int Y_MARGIN = 5;
    static const int DOOR_WIDTH = 60;
    static const int DOOR_HEIGHT = 120;
    
    Door();
    void init(int index, int x, int y);
    void open();
    void close();
    void update();
    bool isOpen() const;
    bool isUnopened() const;
    bool isDone() const;
    int getIndex() const;   
    Character* getCharacter();
    void display();
    void handleShot(int x, int y);


private:
    int index;
    int xPos;
    int yPos;   
    bool openState; // true if the door is open, false if closed
    bool unopenedState; // true if the door is unopened, false if it has been opened
    bool done;
    Character* character; // Pointer to the character revealed when the door opens
};

#endif // DOOR_H 