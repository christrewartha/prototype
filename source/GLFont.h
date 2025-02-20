#ifndef GLFONT_H
#define GLFONT_H

#include <nds.h>
#include <gl2d.h>

class GLFont {
public:
    GLFont();
    int Load(glImage* _font_sprite,
             const unsigned int numframes,
             const unsigned int* texcoords,
             GL_TEXTURE_TYPE_ENUM type,
             int sizeX,
             int sizeY,
             int param,
             int pallette_width,
             const u16* palette,
             const u8* texture);
    void Print(int x, int y, const char* text);
    void Print(int x, int y, int value);
    void PrintCentered(int x, int y, const char* text);
    void PrintCentered(int x, int y, int value);

private:
    glImage* font_sprite;
    char str[256];
    char str2[256];
};

#endif // GLFONT_H 