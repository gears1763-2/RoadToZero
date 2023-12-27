/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Implementation file for main() for Road To Zero.
 *
 */


/*
 *   **** 3-Clause BSD License ****
 *   ref: https://opensource.org/license/bsd-3-clause/
 *
 *
 *   Copyright 2023 - [ESC] Interactive (Anthony Truelove MASc, P.Eng.)
 *
 *   Redistribution and use in source and binary forms, with or without modification, are
 *   permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list of
 *   conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this list
 *   of conditions and the following disclaimer in the documentation and/or other materials
 *   provided with the distribution.
 *
 *   3. Neither the name of the copyright holder nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without specific prior
 *   written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY
 *   EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 *   THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 *   OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 *   TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
        "assets/tile_sheets/pine_tree_64x64_1_CC-BY.png",
        "pine_tree_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/wheat_64x64_1_CC-BY.png",
        "wheat_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/mountain_64x64_1_CC-BY.png",
        "mountain_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/water_waves_64x64_1_CC-BY.png",
        "water_waves_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/water_shimmer_64x64_1_CC-BY.png",
        "water_shimmer_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/brick_house_64x64_1_CC-BY.png",
        "brick_house_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/magnifying_glass_64x64_1_CC-BY.png",
        "magnifying_glass_64x64_1"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/exp2_0_CC0.png",
        "tile clear explosion"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/emissions_8x8_1_CC-BY.png",
        "emissions"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/diesel_generator_64x64_2_CC-BY.png",
        "diesel generator"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/solar_PV_64x64_1_CC-BY.png",
        "solar PV array"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/wind_turbine_64x64_2_CC-BY.png",
        "wind turbine"
    );
    
     assets_manager_ptr->loadTexture(
        "assets/tile_sheets/energy_storage_system_64x64_1_CC-BY.png",
        "energy storage system"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/tidal_turbine_64x64_2_CC-BY.png",
        "tidal turbine"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/wave_energy_converter_64x64_2_CC-BY.png",
        "wave energy converter"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/upgrade_arrow_16x16_1_CC-BY.png",
        "upgrade arrow"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/upgrade_plus_16x16_1_CC-BY.png",
        "upgrade plus"
    );
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/energy_storage_16x16_1_CC-BY.png",
        "storage level"
    );
    
    
    //  3. load sounds
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-magical-coin-win-1936_MixkitFree.ogg",
        "coin ring"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-positive-notification-951_MixkitFree.ogg",
        "positive notification"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-sci-fi-click-900_MixkitFree.ogg",
        "sci-fi click"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-apartment-buzzer-bell-press-932_MixkitFree.ogg",
        "insufficient credits"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-data-scanner-2487_MixkitFree.ogg",
        "resource assessment"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-interface-click-1126_MixkitFree.ogg",
        "console string print"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-video-game-retro-click-237_MixkitFree.ogg",
        "resource overlay toggle on"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-video-game-retro-click-237_REVERSED_MixkitFree.ogg",
        "resource overlay toggle off"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-explosion-with-rocks-debris-1703_MixkitFree.ogg",
        "clear mountains tile"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-arcade-game-explosion-2759_MixkitFree.ogg",
        "clear non-mountains tile"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-electronic-retro-block-hit-2185_MixkitFree.ogg",
        "place improvement"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-video-game-lock-2851_REVERSED_MixkitFree.ogg",
        "build menu open"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-video-game-lock-2851_MixkitFree.ogg",
        "build menu close"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-jump-into-the-water-1180_MixkitFree.ogg",
        "splash"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/505316__nuncaconoci__diesel_CC0.ogg",
        "diesel running"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/33460__pempi__320d_2_CC-BY.ogg",
        "diesel start"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/132724__andy_gardner__wind-turbine-blades_CC-BY.ogg",
        "wind turbine running"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/58416__darren1979__oceanwaves_CC-SAMPLING.ogg",
        "ocean waves"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/369927__mephisto_egmont__water-flowing-in-tubes_CC-BY.ogg",
        "water flow"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/647663__jotraing__electric-train-motor-idle-loop-new-generation-rollingstock_CC0.ogg",
        "energy storage system"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-epic-futuristic-movie-accent-2913_MixkitFree.ogg",
        "game title screen"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-calm-park-with-people-and-children_MixkitFree.ogg",
        "people and children"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-magical-coin-win-1936_MixkitFree.ogg",
        "upgrade"
    );
    
    
    //  4. load tracks
    assets_manager_ptr->loadTrack(
        "assets/audio/tracks/TreeStarMoon_Dobranoc_CC0.ogg",
        "Tree Star Moon - Dobranoc"
    );
    
    assets_manager_ptr->loadTrack(
        "assets/audio/tracks/TreeStarMoon_Lighthouse_CC0.ogg",
        "Tree Star Moon - Lighthouse"
    );
    
    assets_manager_ptr->loadTrack(
        "assets/audio/tracks/TreeStarMoon_SkyFarm_CC0.ogg",
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
