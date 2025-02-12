#include <stdio.h>
#include <gl2d.h>
#include <ctime>
#include <stdlib.h>
#include <nds.h>
#include "Character.h"
#include "Door.h"
#include "Game.h"


// Ensure that all includes are above the class definition
class App {
public:
    App() 
	{}

    void init() {
        // Initialize the DS
        videoSetMode(MODE_5_3D);
        glScreen2D();

        // Set up enough texture memory for our textures
        // Bank A is just 128kb and we are using 194 kb of
        // sprites
        vramSetBankA( VRAM_A_TEXTURE );
        vramSetBankB( VRAM_B_TEXTURE );

		game.init();

    }

    void run() {
        int frame = 0;

        srand(time(NULL));

		bool running = true;
        while (running) {
            frame++;

            scanKeys();
			ProcessTouchInput();

			if(keysDown() & KEY_TOUCH) {	
				game.handleShot(touchX, touchY);
			}
			game.update();

            glBegin2D();

			game.display();

			glBoxFilled(touchX - 2, 
						touchY - 2, 
						touchX + 2, 
						touchY + 2, 
						RGB15(255, 255, 0));

            glEnd2D();

			
            if(keysDown() & KEY_START)
            {
				running = false;
            }
            glFlush(0);
            swiWaitForVBlank();
        }
    }

    void cleanup() {
    }

private:

	Game game;

	int touchX = 0;
	int touchY = 0;

	void ProcessTouchInput() {

		touchPosition touchXY;

		if( touchRead(&touchXY) ) 
		{
			if(touchXY.px > 0 && touchXY.py > 0) 
			{
				touchX = touchXY.px;
				touchY = touchXY.py;
			}
		}
	}
};

int main() {
    App app; // Create an instance of App
    app.init(); // Initialize the app
    app.run(); // Run the main loop
    app.cleanup(); // Clean up resources
    return 0;
}
