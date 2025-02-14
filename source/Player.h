#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    // Singleton access method
    static Player& getInstance() {
        static Player instance; // Guaranteed to be destroyed
        return instance; // Return reference to the instance
    }

    static const int NUM_DOORS = 12;

    // Player state
    int playerLives; // Player lives
    int playerScore; // Player score
    int round;                       // Current round number
    bool doorsCollected[NUM_DOORS];  // Track which doors have been collected from

    // Methods to get and update player score and lives
    int getPlayerScore() const { return playerScore; }
    void increasePlayerScore(int amount) { playerScore += amount; }
    int getPlayerLives() const { return playerLives; }
    void setPlayerLives(int lives) { playerLives = lives; }
    void decreasePlayerLives() { playerLives--; }
    int getRound() const { return round; }
    void increaseRound() { round++; }
    void decreaseRound() { round--; round = round < 0 ? 0 : round;}

    bool hasDoorBeenCollected(int doorIndex) const { return doorsCollected[doorIndex]; }
    void setDoorCollected(int doorIndex, bool collected) { doorsCollected[doorIndex] = collected; }

    void resetDoorsCollected() {
        for(int i = 0; i < NUM_DOORS; i++) {
            doorsCollected[i] = false;
        }
    }

    void resetPlayer() {
        playerLives = 3;
        playerScore = 0;
        round = 0;
        resetDoorsCollected();
    }   
private:
    Player() : playerLives(3), playerScore(0), round(0) {} // Private constructor
    Player(const Player&) = delete; // Prevent copying
    Player& operator=(const Player&) = delete; // Prevent assignment
};

#endif // PLAYER_H 