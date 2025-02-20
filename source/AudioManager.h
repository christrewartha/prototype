#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <nds.h>
#include <stdio.h> 
#include <maxmod9.h>


#include "soundbank.h"
#include "soundbank_bin.h"

class AudioManager {
public:
    // Get the singleton instance
    static AudioManager& getInstance() {
        static AudioManager instance; // Guaranteed to be destroyed
        return instance;               // Instantiated on first use
    }

    // Delete copy constructor and assignment operator
    AudioManager(AudioManager const&) = delete;
    void operator=(AudioManager const&) = delete;

    // Initialize audio system
    void init() {
        mmInitDefaultMem((mm_addr)soundbank_bin);
	
        // load the module
    	mmLoad( MOD_COWBOYS_HELL );
        mmLoad( MOD_ANTICIPATION );
        // load sound effects
        mmLoadEffect( SFX_BOOM );

        boom = {
            { SFX_BOOM } ,			// id
            (int)(1.0f * (1<<10)),	// rate
            0,		// handle
            255,	// volume
            255,	// panning
        };
    }

    void loadMenuMusic(const char* filename) {
        mmLoad(MOD_ANTICIPATION);
    }

    void UnloadMenuMusic() {
        mmUnload(MOD_ANTICIPATION);
    }

    void loadGameMusic(const char* filename) {
        mmLoad(MOD_COWBOYS_HELL);
    }

    void UnloadGameMusic() {
        mmUnload(MOD_COWBOYS_HELL);
    }

    void startMenuMusic() {
        if(musicEnabled) {
            mmStart( MOD_ANTICIPATION, MM_PLAY_LOOP );
        }
    }

    void startGameMusic() {
        if(musicEnabled) {
            mmStart( MOD_COWBOYS_HELL, MM_PLAY_LOOP );
        }
    }

    void pauseMusic() {
        mmPause();
    }

    void resumeMusic() {
        mmResume();
    }

    void stopMusic() {
        mmStop();
    }

    // Load audio file
    void loadAudio(const char* filename) {
        // Load audio file logic here
        printf("Loading audio file: %s\n", filename);
        // Example: soundLoad(filename);
    }

    // Play audio
    void playAudio(const char* filename) {
        // Play audio logic here
        printf("Playing audio file: %s\n", filename);
        // Example: soundPlay(filename);
    }

    // Stop audio
    void stopAudio() {
        // Stop currently playing audio
        printf("Stopping audio.\n");
        // Example: soundStop();
    }

    void playGunshot() {
        mmEffectEx(&boom);
    }

    void toggleMusic() {
        musicEnabled = !musicEnabled;
    }

    bool isMusicEnabled() {
        return musicEnabled;
    }
private:

    bool musicEnabled = true;
    mm_sound_effect boom;

    // Private constructor to prevent instantiation
    AudioManager() {
        // Constructor logic here
    }

    // Destructor
    ~AudioManager() {
        // Cleanup audio resources here
        printf("AudioManager destroyed.\n");
    }
};

#endif // AUDIOMANAGER_H 