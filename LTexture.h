//
// Created by v.chubar on 26.01.2018.
//

#ifndef JEOMETRY_TEST_LTEXTURE_H
#define JEOMETRY_TEST_LTEXTURE_H

#include <SDL.h>
#include <string>
class LTexture
{
public:
    //Initializes variables
    LTexture(){

    }

    //Deallocates memory
    ~LTexture(){
        free();
    }

    //Loads image at specified path
    bool loadFromFile(SDL_Renderer* gRenderer, std::string path );

    void free();

    //Renders texture at given point
    void render(SDL_Renderer *gRenderer, int x, int y );

    int getWidth();

    int getHeight();

private:
    //The actual hardware texture
    SDL_Texture* mTexture = nullptr;

    //Image dimensions
    int mWidth = 0;
    int mHeight = 0;
};

#endif //JEOMETRY_TEST_LTEXTURE_H
