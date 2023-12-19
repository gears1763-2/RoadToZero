/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for main() for Road To Zero.
 *
 */


///
/// \file main.cpp
///
/// \brief Implementation file for main() for Road To Zero.
///


#include "../header/Game.h"


// ---------------------------------------------------------------------------------- //

///
/// \fn void loadAssets(AssetsManager* assets_manager_ptr)
///
/// \brief Helper function to load game assets
///
/// \param assets_manager_ptr Pointer to the assets manager.
///

void loadAssets(AssetsManager* assets_manager_ptr)
{
    //  1. load font assets
    assets_manager_ptr->loadFont("assets/fonts/DroidSansMono.ttf", "DroidSansMono");
    assets_manager_ptr->loadFont("assets/fonts/Glass_TTY_VT220.ttf", "Glass_TTY_VT220");
    
    return;
}   /* loadAssets() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn sf::RenderWindow* constructRenderWindow(void)
///
/// \brief Helper function to construct render window.
///
/// \return Pointer to the render window.

sf::RenderWindow* constructRenderWindow(void)
{
    sf::RenderWindow* render_window_ptr = new sf::RenderWindow(
        sf::VideoMode(GAME_WIDTH, GAME_HEIGHT),
        "Road To Zero"
    );
    
    return render_window_ptr;
}   /* constructRenderWindow() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

int main(int argc, char** argv)
{
    //  1. load assets
    AssetsManager assets_manager;
    loadAssets(&assets_manager);
    
    //  2. construct render window
    sf::RenderWindow* render_window_ptr = constructRenderWindow();
    
    //  3. start game loop
    bool quit_game = false;
    
    while (not quit_game) {
        Game game(render_window_ptr, &assets_manager);
        quit_game = game.run();
    }
    
    //  4. clean up
    render_window_ptr->close();
    delete render_window_ptr;
    
    return 0;
}   /* main() */

// ---------------------------------------------------------------------------------- //
