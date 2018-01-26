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
SDL_Texture* loadTexture(SDL_Renderer *renderor, std::string path)
{
    //The final optimized image
    SDL_Texture* texture;

    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    else
    {
        //Convert surface to screen format
        texture = SDL_CreateTextureFromSurface(renderor, loadedSurface);
        if( texture== NULL )
        {
            printf( "Unable to optimize texture %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return texture;//optimizedSurface;
}

void renderPrimitives(SDL_Renderer *gRenderer){

    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(gRenderer);
//        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xff);
    SDL_Rect rect = {50, 50, 100, 100};
    SDL_RenderDrawRect(gRenderer, &rect);

    SDL_SetRenderDrawColor(gRenderer, 0x88, 0xaa, 0xaa, 0xff);
    SDL_RenderFillRect(gRenderer, &rect);

    SDL_SetRenderDrawColor(gRenderer, 0xff, 0x00, 0x00, 0xff);
    SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );

    SDL_SetRenderDrawColor( gRenderer, 0xaa, 0x00, 0x00, 0xFF );
    for( int i = 0; i < SCREEN_HEIGHT; i += 4 )
    {
        SDL_RenderDrawPoint( gRenderer, SCREEN_WIDTH / 2, i );
    }
}


void testViewPort(SDL_Renderer *gRenderer, SDL_Texture *texture){
    SDL_Rect topLeftViewport;
    topLeftViewport.x = 0;
    topLeftViewport.y = 0;
    topLeftViewport.w = SCREEN_WIDTH / 2;
    topLeftViewport.h = SCREEN_HEIGHT / 2;
    SDL_RenderSetViewport( gRenderer, &topLeftViewport );

    SDL_RenderCopy( gRenderer, texture, NULL, NULL );

    SDL_Rect bottomViewport;
    bottomViewport.x = 0;
    bottomViewport.y = SCREEN_HEIGHT / 2;
    bottomViewport.w = SCREEN_WIDTH;
    bottomViewport.h = SCREEN_HEIGHT / 2;
    SDL_RenderSetViewport( gRenderer, &bottomViewport );

    //Render texture to screen
    SDL_RenderCopy( gRenderer, texture, NULL, NULL );


    //Top right viewport
    SDL_Rect topRightViewport;
    topRightViewport.x = SCREEN_WIDTH / 2;
    topRightViewport.y = 0;
    topRightViewport.w = SCREEN_WIDTH / 2;
    topRightViewport.h = SCREEN_HEIGHT / 2;
    SDL_RenderSetViewport( gRenderer, &topRightViewport );

    //Render texture to screen
    SDL_RenderCopy( gRenderer, texture, NULL, NULL );
}
#endif //JEOMETRY_TEST_STD_FUNCTIONS_H
