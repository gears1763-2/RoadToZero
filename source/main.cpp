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
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/diesel_generator_64x64_2.png",
        "diesel generator"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/solar_PV_64x64_1.png",
        "solar PV array"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/wind_turbine_64x64_2.png",
        "wind turbine"
    );
    
     assets_manager_ptr->loadTexture(
        "assets/tile_sheets/energy_storage_system_64x64_1.png",
        "energy storage system"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/tidal_turbine_64x64_2.png",
        "tidal turbine"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/wave_energy_converter_64x64_2.png",
        "wave energy converter"
    );
    
    
    //  3. load sounds
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-magical-coin-win-1936.ogg",
        "coin ring"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-positive-notification-951.ogg",
        "positive notification"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-sci-fi-click-900.ogg",
        "sci-fi click"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-apartment-buzzer-bell-press-932.ogg",
        "insufficient credits"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-data-scanner-2487.ogg",
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
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-electronic-retro-block-hit-2185.ogg",
        "place improvement"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-video-game-lock-2851_REVERSED.ogg",
        "build menu open"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-video-game-lock-2851.ogg",
        "build menu close"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-jump-into-the-water-1180.ogg",
        "splash"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/505316__nuncaconoci__diesel.ogg",
        "diesel running"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/33460__pempi__320d_2.ogg",
        "diesel start"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/132724__andy_gardner__wind-turbine-blades.ogg",
        "wind turbine running"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/58416__darren1979__oceanwaves.ogg",
        "ocean waves"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/369927__mephisto_egmont__water-flowing-in-tubes.ogg",
        "water flow"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/647663__jotraing__electric-train-motor-idle-loop-new-generation-rollingstock.ogg",
        "energy storage system idle"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-epic-futuristic-movie-accent-2913.ogg",
        "game title screen"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-calm-park-with-people-and-children.ogg",
        "people and children"
    );
    
    
    //  4. load tracks
    assets_manager_ptr->loadTrack(
        "assets/audio/tracks/TreeStarMoon_Dobranoc.ogg",
        "Tree Star Moon - Dobranoc"
    );
    
    assets_manager_ptr->loadTrack(
        "assets/audio/tracks/TreeStarMoon_Lighthouse.ogg",
        "Tree Star Moon - Lighthouse"
    );
    
    assets_manager_ptr->loadTrack(
        "assets/audio/tracks/TreeStarMoon_SkyFarm.ogg",
        "Tree Star Moon - Sky Farm"
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
    assets_manager.playTrack();
    
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
