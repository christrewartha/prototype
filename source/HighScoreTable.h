#ifndef HIGHSCORETABLE_H
#define HIGHSCORETABLE_H

#include <nds.h>
#include <nds/arm9/input.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include "GLFontManager.h"

struct HighScoreEntry {
    std::string name; // Player's name
    int stage;        // Stage number
    int cash;        // Cash amount

    // Comparison operator for sorting
    bool operator<(const HighScoreEntry& other) const {
        if (stage == other.stage) {
            return cash < other.cash; // Higher cash wins as tiebreaker
        }
        return stage < other.stage; // Sort by stage
    }
};

class HighScoreTable {
public:
    HighScoreTable() : selectedOption(0), doneViewing(false) {
        // Initialize some example high scores
        highScores.push_back({"ALICE   ", 5, 1500});
        highScores.push_back({"BOB     ", 6, 2000});
        highScores.push_back({"CHARLIE ", 3, 1200});
        highScores.push_back({"DAVE    ", 1, 500});
        highScores.push_back({"EVE     ", 2, 800});

        // Sort the high scores
        std::sort(highScores.begin(), highScores.end());
        std::reverse(highScores.begin(), highScores.end());
    }

    void init() {
        doneViewing = false;
    }

    void addHighScore(const std::string& name, int stage, int cash) {
        highScores.push_back({name, stage, cash});
        std::sort(highScores.begin(), highScores.end());
    }

    void update() {
        // Read the current keys pressed
        int keys = keysDown();

        // Select option to return to main menu
        if (keys & KEY_A) {
            // Handle selection
            doneViewing = true; // Mark as done viewing high scores
        }
    }

    void render() {
        glBoxFilled(0, 0, 256, 192, RGB15(31, 31, 31));
        SpriteManager::getInstance().drawSprite(Sprites::WESTBANK_LOGO, 
                148, 
                110,
                RGB15(31, 31, 31),
                true,
                1 << 11,
                1 << 11,
                0);
        glColor(RGB15(31, 31, 31));
        GLFontManager::getInstance().renderTextCentered(0, 50, "HIGH SCORES", true);
        for(int i = 0; i < (int)highScores.size(); i++) {
            char buffer[32];
            sprintf(buffer, "%s %d: %d", highScores[i].name.c_str(), highScores[i].stage, highScores[i].cash);
            GLFontManager::getInstance().renderText(15, 90 + (i * 16), buffer);
        }
    }

    bool isDone() const {
        return doneViewing; // Return whether the player is done viewing
    }

private:
    std::vector<HighScoreEntry> highScores; // Vector to hold high score entries
    int selectedOption; // Currently selected option
    bool doneViewing = false; // Flag to indicate if done viewing high scores
};

#endif // HIGHSCORETABLE_H 