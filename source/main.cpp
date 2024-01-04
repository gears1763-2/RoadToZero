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
    
    assets_manager_ptr->loadTexture(
        "assets/tile_sheets/coin_16x16_1_CC-BY.png",
        "coin"
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
        "solar hum"
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
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-cool-interface-click-tone-2568_MixkitFree.ogg",
        "interface click"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-factory-metal-hard-hit-2980_MixkitFree.ogg",
        "breakdown"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-fantasy-game-success-notification-270_MixkitFree.ogg",
        "victory"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-player-losing-or-failing-2042_MixkitFree.ogg",
        "loss"
    );
    
    assets_manager_ptr->loadSound(
        "assets/audio/samples/mixkit-poker-card-flick-2002_MixkitFree.ogg",
        "card flick"
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
///

sf::RenderWindow* constructRenderWindow(void)
{
    //  1. get desktop resolution
    sf::VideoMode video_mode = sf::VideoMode::getDesktopMode();
    int desktop_width = video_mode.width;
    int desktop_height = video_mode.height;
    
    //  2. adjust render window dimensions as necessary (maintain 3:2 aspect ratio)
    int window_width = GAME_WIDTH;
    int window_height = GAME_HEIGHT;
    
    if (
        (window_width > desktop_width) or
        (window_height > desktop_height)
    ) {
        int width_diff = window_width - desktop_width;
        int height_diff = window_height - desktop_height;
        
        if (width_diff > height_diff) {
            window_width = desktop_width;
            window_height = (2.0 / 3.0) * desktop_width;
        }
        
        else {
            window_height = desktop_height;
            window_width = (3.0 / 2.0) * desktop_height;
        }
    }
    
    //  3. construct render window
    sf::RenderWindow* render_window_ptr = new sf::RenderWindow(
        sf::VideoMode(window_width, window_height),
        "Road To Zero"
    );
    
    //  4. reset render window view as necessary
    if (
        (window_width != GAME_WIDTH) or
        (window_height != GAME_HEIGHT)
    ) {
        sf::View view;
        view.reset(sf::FloatRect(0, 0, GAME_WIDTH, GAME_HEIGHT));
        render_window_ptr->setView(view);
    }
    
    //  5. change render window icon
    sf::Image icon;
    icon.loadFromFile("assets/images/RoadToZero_favicon_CC-BY.png");
    
    render_window_ptr->setIcon(
        icon.getSize().x,
        icon.getSize().y,
        icon.getPixelsPtr()
    );
    
    return render_window_ptr;
}   /* constructRenderWindow() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void playBrandAnimation(void)
///
/// \brief Helper function to play brand animation. This should really be implemented
///     in an [ESC] core class.
///
/// \param render_window_ptr Pointer to the render window.
///

void playBrandAnimation(sf::RenderWindow* render_window_ptr)
{
    //  1. load assets
    AssetsManager brand_assets_manager;
    
    brand_assets_manager.loadFont(
        "assets/ESC_brand/OpenSans-Bold.ttf",
        "OpenSansBold"
    );
    
    brand_assets_manager.loadTexture(
        "assets/ESC_brand/ESC_key_109x90.png",
        "[ESC] large"
    );
    
    brand_assets_manager.loadTexture(
        "assets/ESC_brand/ESC_key_98x81.png",
        "[ESC] small"
    );
    
    brand_assets_manager.loadTexture(
        "assets/ESC_brand/SFML_256x128.png",
        "SFML"
    );
    
    brand_assets_manager.loadSound(
        "assets/ESC_brand/mixkit-single-key-type-2533_MixkitFree.ogg",
        "key press"
    );
    
    
    //  2. set up and position assets
    std::string brand_string = "INTERACTIVE";
    
    sf::Text brand_text(
        brand_string,
        *(brand_assets_manager.getFont("OpenSansBold")),
        64
    );
    
    brand_text.setOrigin(
        brand_text.getLocalBounds().width / 2,
        brand_text.getLocalBounds().height / 2
    );
    
    brand_text.setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2);
    
    double key_position_x =
        (GAME_WIDTH / 2) - (brand_text.getLocalBounds().width / 2) - 64;
        
    double key_position_y =
        (GAME_HEIGHT / 2) - (brand_text.getLocalBounds().height / 2) - 32;
    
    sf::Sprite ESC_large(
        *(brand_assets_manager.getTexture("[ESC] large"))
    );
    
    ESC_large.setOrigin(
        ESC_large.getLocalBounds().width / 2,
        ESC_large.getLocalBounds().height / 2
    );
    
    ESC_large.setPosition(key_position_x, key_position_y);
    
    ESC_large.setColor(sf::Color(255, 255, 255, 0));
    
    sf::Sprite ESC_small(
        *(brand_assets_manager.getTexture("[ESC] small"))
    );
    
    ESC_small.setOrigin(
        ESC_small.getLocalBounds().width / 2,
        ESC_small.getLocalBounds().height / 2
    );
    
    ESC_small.setPosition(key_position_x, key_position_y);
    
    ESC_small.setColor(sf::Color(255, 255, 255, 255));
    
    sf::Sprite SFML(
        *(brand_assets_manager.getTexture("SFML"))
    );
    
    SFML.setOrigin(
        SFML.getLocalBounds().width / 2,
        SFML.getLocalBounds().height / 2
    );
    
    SFML.setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2);
    
    SFML.setColor(sf::Color(255, 255, 255, 0));
    
    
    //  3. draw loop
    bool sound_played = false;
    
    int brand_frame = 0;
    int click_frame = 0;
    int brand_state = 0;
    
    size_t substring_idx = 0;
    
    double alpha = 0;
    double dalpha = FRAMES_PER_SECOND / 18;
    double time_since_start_s = 0;
    
    sf::Clock brand_clock;
    sf::Event brand_event;
    
    while (brand_state < 6) {
        time_since_start_s = brand_clock.getElapsedTime().asSeconds();
        
        if (time_since_start_s >= (brand_frame + 1) * SECONDS_PER_FRAME) {
            render_window_ptr->clear();
            
            while (render_window_ptr->pollEvent(brand_event)) {
                if (brand_event.type == sf::Event::Closed) {
                    render_window_ptr->close();
                    return;
                }
            }
            
            //  3.1. brand state switch
            switch (brand_state) {
                case (0): {
                    // fade in key
                    render_window_ptr->draw(ESC_large);
                    
                    if (alpha < 255) {
                        
                        alpha += dalpha;
                        
                        if (alpha > 255) {
                            alpha = 255;
                        }
                        
                        ESC_large.setColor(sf::Color(255, 255, 255, alpha));
                    }
                    
                    else {
                        brand_state++;
                    }
                    
                    break;
                }
                
                
                case (1): {
                    // key press
                    render_window_ptr->draw(ESC_small);
                    
                    if (click_frame < FRAMES_PER_SECOND / 8) {
                        if (not sound_played) {
                            brand_assets_manager.getSound("key press")->play();
                            sound_played = true;
                        }
                        
                        click_frame++;
                    }
                    
                    else {
                        brand_state++;
                    }
                    
                    break;
                }
                
                
                case (2): {
                    // text wave
                    brand_text.setString(brand_string.substr(0, substring_idx));
                    
                    render_window_ptr->draw(brand_text);
                    render_window_ptr->draw(ESC_large);
                    
                    if (substring_idx <= brand_string.size()) {
                        if (brand_frame % (FRAMES_PER_SECOND / 20) == 0) {
                            substring_idx++;
                        }
                    }
                    
                    else {
                        brand_state++;
                    }
                    
                    break;
                }
                
                
                case (3): {
                    // fade out brand
                    render_window_ptr->draw(brand_text);
                    render_window_ptr->draw(ESC_large);
                        
                    if (alpha > 0) {
                        alpha -= dalpha;
                        
                        if (alpha < 0) {
                            alpha = 0;
                        }
                        
                        brand_text.setFillColor(sf::Color(255, 255, 255, alpha));
                        ESC_large.setColor(sf::Color(255, 255, 255, alpha));
                    }
                    
                    else {
                        brand_state++;
                    }
                    
                    break;
                }
                
                
                case (4): {
                    // fade in SFML
                    render_window_ptr->draw(SFML);
                    
                    if (alpha < 255) {
                        alpha += dalpha;
                        
                        if (alpha > 255) {
                            alpha = 255;
                        }
                        
                        SFML.setColor(sf::Color(255, 255, 255, alpha));
                    }
                    
                    else {
                        brand_state++;
                    }
                    
                    break;
                }
                
                
                case (5): {
                    // fade out SFML
                    render_window_ptr->draw(SFML);
                    
                    if (alpha > 0) {
                        alpha -= dalpha;
                        
                        if (alpha < 0) {
                            alpha = 0;
                        }
                        
                        SFML.setColor(sf::Color(255, 255, 255, alpha));
                    }
                    
                    else {
                        brand_state++;
                    }
                    
                    break;
                }
                
                
                default: {
                    // do nothing!
                    
                    break;
                }
            }
            
            render_window_ptr->display();
            brand_frame++;
        }
    }
    
    return;
}   /* playBrandAnimation() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void showTitleScreen(
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr
///     )
///
/// \brief Helper function 
///
/// \param render_window_ptr A pointer to the render window.
///
/// \param assets_manager_ptr A pointer to the assets manager.
///

void showTitleScreen(
    sf::RenderWindow* render_window_ptr,
    AssetsManager* assets_manager_ptr
)
{
    //  1. set up and position title assets
    int outline_thickness = 32;
    
    sf::RectangleShape title_console(
        sf::Vector2f(
            GAME_WIDTH - 2 * outline_thickness,
            GAME_HEIGHT - 2 * outline_thickness
        )
    );
    
    title_console.setPosition(outline_thickness, outline_thickness);
    
    sf::Color title_fill_colour = MONOCHROME_SCREEN_BACKGROUND;
    title_fill_colour.a = 0;
    
    sf::Color title_outline_colour = MENU_FRAME_GREY;
    title_outline_colour.a = 0;
    
    title_console.setFillColor(title_fill_colour);
    title_console.setOutlineColor(title_outline_colour);
    title_console.setOutlineThickness(outline_thickness);
    
    std::string title_string_upper = "ROAD TO ZERO";
    sf::Text title_text_upper(
        title_string_upper,
        *(assets_manager_ptr->getFont("Glass_TTY_VT220")),
        128
    );
    
    title_text_upper.setOrigin(
        title_text_upper.getLocalBounds().width / 2,
        title_text_upper.getLocalBounds().height / 2
    );
    
    title_text_upper.setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2 - 128);
    title_text_upper.setFillColor(MONOCHROME_TEXT_GREEN);
    
    std::string title_string_lower = "THE MICROGRID MANAGEMENT GAME";
    sf::Text title_text_lower(
        title_string_lower,
        *(assets_manager_ptr->getFont("Glass_TTY_VT220")),
        64
    );
    
    title_text_lower.setOrigin(
        title_text_lower.getLocalBounds().width / 2,
        title_text_lower.getLocalBounds().height / 2
    );
    
    title_text_lower.setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2);
    title_text_lower.setFillColor(MONOCHROME_TEXT_GREEN);
    
    std::string title_string_bottom = "ROAD TO ZERO V";
    title_string_bottom += GAME_VERSION;
    title_string_bottom += "    COPYRIGHT 2023 - [ESC] INTERACTIVE";
    sf::Text title_text_bottom(
        title_string_bottom,
        *(assets_manager_ptr->getFont("Glass_TTY_VT220")),
        16
    );
    
    title_text_bottom.setOrigin(
        title_text_bottom.getLocalBounds().width / 2,
        title_text_bottom.getLocalBounds().height / 2
    );
    
    title_text_bottom.setPosition(GAME_WIDTH / 2, GAME_HEIGHT - 64);
    title_text_bottom.setFillColor(MONOCHROME_TEXT_GREEN);
    
    sf::Text prompt_text(
        "PRESS ANY KEY TO CONTINUE",
        *(assets_manager_ptr->getFont("Glass_TTY_VT220")),
        24
    );
    
    prompt_text.setOrigin(
        prompt_text.getLocalBounds().width / 2,
        prompt_text.getLocalBounds().height / 2
    );
    
    prompt_text.setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2 + 175);
    prompt_text.setFillColor(MONOCHROME_TEXT_GREEN);
    
    sf::RectangleShape fade_rectangle(sf::Vector2f(GAME_WIDTH, GAME_HEIGHT));
    sf::Color fade_rectangle_colour(0, 0, 0, 0);
    fade_rectangle.setFillColor(fade_rectangle_colour);
    
    
    //  2. draw loop
    bool draw_title = true;
    bool sound_played = false;
    
    int title_frame = 0;
    int title_state = 0;
    
    size_t upper_substring_idx = 0;
    size_t lower_substring_idx = 0;
    size_t bottom_substring_idx = 0;
    
    double alpha = 0;
    double dalpha = FRAMES_PER_SECOND / 18;
    double time_since_start_s = 0;
    
    sf::Clock title_clock;
    sf::Event title_event;
    
    while (draw_title) {
        time_since_start_s = title_clock.getElapsedTime().asSeconds();
        
        if (time_since_start_s >= (title_frame + 1) * SECONDS_PER_FRAME) {
            render_window_ptr->clear();
            
            //  2.1. title state switch
            switch (title_state) {
                case (0): {
                    while (render_window_ptr->pollEvent(title_event)) {
                        if (title_event.type == sf::Event::Closed) {
                            render_window_ptr->close();
                            return;
                        }
                    }
                    
                    // fade in title console
                    render_window_ptr->draw(title_console);
                    
                    if (alpha < 255) {
                        alpha += dalpha;
                        
                        if (alpha > 255) {
                            alpha = 255;
                        }
                        
                        title_fill_colour.a = alpha;
                        title_outline_colour.a = alpha;
                        
                        title_console.setFillColor(title_fill_colour);
                        title_console.setOutlineColor(title_outline_colour);
                    }
                    
                    else {
                        title_state++;
                        alpha = 0;
                    }
                    
                    break;
                }
                
                
                case (1): {
                    while (render_window_ptr->pollEvent(title_event)) {
                        if (title_event.type == sf::Event::Closed) {
                            render_window_ptr->close();
                            return;
                        }
                    }
                    
                    // fade in title text
                    if (not sound_played) {
                        assets_manager_ptr->getSound("game title screen")->play();
                        sound_played = true;
                    }
                    
                    if (title_string_bottom.substr(0, bottom_substring_idx) != title_string_bottom) {
                        title_text_upper.setString(title_string_upper.substr(0, upper_substring_idx));
                        title_text_lower.setString(title_string_lower.substr(0, lower_substring_idx));
                        title_text_bottom.setString(title_string_bottom.substr(0, bottom_substring_idx));
                        
                        assets_manager_ptr->getSound("console string print")->play();
                        
                        upper_substring_idx++;
                        lower_substring_idx++;
                        bottom_substring_idx++;
                        
                        if (upper_substring_idx > title_string_upper.size()) {
                            upper_substring_idx = title_string_upper.size();
                        }
                        
                        if (lower_substring_idx > title_string_lower.size()) {
                            lower_substring_idx = title_string_lower.size();
                        }
                    }
                    
                    else {
                        title_text_upper.setString(title_string_upper.substr(0, upper_substring_idx));
                        title_text_lower.setString(title_string_lower.substr(0, lower_substring_idx));
                        title_text_bottom.setString(title_string_bottom.substr(0, bottom_substring_idx));
                        title_state++;
                    }
                    
                    render_window_ptr->draw(title_console);
                    render_window_ptr->draw(title_text_upper);
                    render_window_ptr->draw(title_text_lower);
                    render_window_ptr->draw(title_text_bottom);
                    
                    break;
                }
                
                
                case (2): {
                    while (render_window_ptr->pollEvent(title_event)) {
                        if (title_event.type == sf::Event::KeyPressed) {
                            title_state++;
                        }
                        
                        if (title_event.type == sf::Event::Closed) {
                            render_window_ptr->close();
                            return;
                        }
                    }
                    
                    // flashing prompt
                    render_window_ptr->draw(title_console);
                    render_window_ptr->draw(title_text_upper);
                    render_window_ptr->draw(title_text_lower);
                    render_window_ptr->draw(title_text_bottom);
                    
                    if (
                        (title_frame > 3.5 * FRAMES_PER_SECOND) and
                        ((title_frame % FRAMES_PER_SECOND) > FRAMES_PER_SECOND / 2)
                    ) {
                        render_window_ptr->draw(prompt_text);
                    }
                    
                    break;
                }
                
                
                case (3): {
                    while (render_window_ptr->pollEvent(title_event)) {
                        if (title_event.type == sf::Event::Closed) {
                            render_window_ptr->close();
                            return;
                        }
                    }
                    
                    // fade out
                    render_window_ptr->draw(title_console);
                    render_window_ptr->draw(title_text_upper);
                    render_window_ptr->draw(title_text_lower);
                    render_window_ptr->draw(title_text_bottom);
                    
                    if ((title_frame % FRAMES_PER_SECOND) > FRAMES_PER_SECOND / 2) {
                        render_window_ptr->draw(prompt_text);
                    }
                    
                    render_window_ptr->draw(fade_rectangle);
                    
                    if (alpha < 255) {
                        alpha += dalpha;
                        
                        if (alpha > 255) {
                            alpha = 255;
                        }
                        
                        fade_rectangle_colour.a = alpha;
                        
                        fade_rectangle.setFillColor(fade_rectangle_colour);
                    }
                    
                    else {
                        draw_title = false;
                    }
                    
                    break;
                }
                
                
                default: {
                    // do nothing!
                    
                    break;
                }
            }
            
            render_window_ptr->display();
            title_frame++;
        }
    }
    
    return;
}   /* showTitleScreen() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

int main(int argc, char** argv)
{
    //  1. load assets
    AssetsManager assets_manager;
    loadAssets(&assets_manager);
    
    //  2. construct render window
    sf::RenderWindow* render_window_ptr = constructRenderWindow();
    
    //  3. show brand animation and splash screen
    playBrandAnimation(render_window_ptr);
    
    //  4. show title screen
    if (render_window_ptr->isOpen()) {
        showTitleScreen(render_window_ptr, &assets_manager);
    }
    
    //  5. start game loop
    bool quit_game = false;
    bool transition_from_title = true;
    
    if (render_window_ptr->isOpen()) {
        assets_manager.playTrack();
    }
    
    else {
        quit_game = true;
    }
    
    while (not quit_game) {
        Game game(render_window_ptr, &assets_manager, transition_from_title);
        quit_game = game.run();
        
        if (transition_from_title and (not quit_game)) {
            transition_from_title = false;
        }
    }
    
    //  4. clean up
    render_window_ptr->close();
    delete render_window_ptr;
    
    return 0;
}   /* main() */

// ---------------------------------------------------------------------------------- //
