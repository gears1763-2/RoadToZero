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
    
    
    //  2. load tile sheets
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/pine_tree_64x64_1.png",
        "pine_tree_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/wheat_64x64_1.png",
        "wheat_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/mountain_64x64_1.png",
        "mountain_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/water_waves_64x64_1.png",
        "water_waves_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/water_shimmer_64x64_1.png",
        "water_shimmer_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/brick_house_64x64_1.png",
        "brick_house_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/magnifying_glass_64x64_1.png",
        "magnifying_glass_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/exp2_0.png",
        "tile clear explosion"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/emissions_8x8_2.png",
        "steam / smoke"
    );
    
    
    //  3. load sounds
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-apartment-buzzer-bell-press-932.ogg",
        "insufficient credits"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-sci-fi-click-900.ogg",
        "resource assessment"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-interface-click-1126.ogg",
        "console string print"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-video-game-retro-click-237.ogg",
        "resource overlay toggle on"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-video-game-retro-click-237_REVERSED.ogg",
        "resource overlay toggle off"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-explosion-with-rocks-debris-1703.ogg",
        "clear mountains tile"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-arcade-game-explosion-2759.ogg",
        "clear non-mountains tile"
    );
    
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
