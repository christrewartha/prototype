#ifndef GLFONTMANAGER_H
#define GLFONTMANAGER_H

#include <nds.h>
#include <gl2d.h>
#include "GLFont.h"

class GLFontManager {
public:
    // Singleton access method
    static GLFontManager& getInstance() {
        static GLFontManager instance; // Guaranteed to be destroyed
        return instance; // Return reference to the instance
    }

    void init(); // Method to initialize the font manager
    void renderText(int x, int y, const char* text, bool bigFont = false); // Method to render text
    void renderTextCentered(int x, int y, const char* text, bool bigFont = false); // Method to render text centered
private:
    GLFontManager() {} // Private constructor
    GLFontManager(const GLFontManager&) = delete; // Prevent copying
    GLFontManager& operator=(const GLFontManager&) = delete; // Prevent assignment

    GLFont font; // Instance of the Font class
    GLFont fontBig; // Instance of the big Font class
};

#endif // GLFONTMANAGER_H 