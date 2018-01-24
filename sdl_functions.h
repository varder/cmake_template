//
// Created by v.chubar on 24.01.2018.
//

#ifndef JEOMETRY_TEST_STD_FUNCTIONS_H
#define JEOMETRY_TEST_STD_FUNCTIONS_H

void updateSize(SDL_Surface* surface, int w, int h){
    SDL_Rect stretchRect;
    stretchRect.x=0;
    stretchRect.y=0;
    stretchRect.w=w;
    stretchRect.h=h;
    SDL_BlitScaled(surface, NULL, surface, &stretchRect);
}

SDL_Surface* loadSurface( std::string path, SDL_PixelFormat *format)
{
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, format, NULL );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}

#endif //JEOMETRY_TEST_STD_FUNCTIONS_H
