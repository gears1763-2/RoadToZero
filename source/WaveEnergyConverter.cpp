/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the WaveEnergyConverter class.
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
/// \file WaveEnergyConverter.cpp
///
/// \brief Implementation file for the WaveEnergyConverter class.
///
/// A base class for the tile improvement hierarchy.
///


#include "../header/WaveEnergyConverter.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: __setUpTileImprovementSpriteAnimated(void)
///
/// \brief Helper method to set up tile improvement sprite (static).
///

void WaveEnergyConverter :: __setUpTileImprovementSpriteAnimated(void)
{
    sf::Sprite diesel_generator_sheet(
        *(this->assets_manager_ptr->getTexture("wave energy converter"))
    );
    
    int n_elements = diesel_generator_sheet.getLocalBounds().height / 64;
    
    for (int i = 0; i < n_elements; i++) {
        this->tile_improvement_sprite_animated.push_back(
            sf::Sprite(
                *(this->assets_manager_ptr->getTexture("wave energy converter")),
                sf::IntRect(0, i * 64, 64, 64)
            )
        );
        
        this->tile_improvement_sprite_animated.back().setOrigin(
            this->tile_improvement_sprite_animated.back().getLocalBounds().width / 2,
            this->tile_improvement_sprite_animated.back().getLocalBounds().height
        );
        
        this->tile_improvement_sprite_animated.back().setPosition(
            this->position_x,
            this->position_y - 32
        );
        
        this->tile_improvement_sprite_animated.back().setColor(
            sf::Color(255, 255, 255, 0)
        );
    }
    
    return;
}   /* __setUpTileImprovementSpriteAnimated() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: __upgrade(void)
///
/// \brief Helper method to upgrade the diesel generator.
///

void WaveEnergyConverter :: __upgrade(void)
{
    /*
    int upgrade_cost = DIESEL_GENERATOR_BUILD_COST;
    
    if (this->credits < upgrade_cost) {
        std::cout << "Cannot upgrade diesel generator: insufficient credits (need "
            << upgrade_cost << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
    
    this->is_running = false;
    
    this->health = 100;
    
    this->capacity_kW += 100;
    this->upgrade_level++;
    
    this->production_MWh = 0;
    this->max_production_MWh += 72;
    
    this->just_upgraded = true;
    
    this->assets_manager_ptr->getSound("upgrade")->play();
    
    this->__sendCreditsSpentMessage(upgrade_cost);
    this->__sendTileStateRequest();
    this->__sendGameStateRequest();
    */
    
    return;
}   /* __upgrade() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: __handleKeyPressEvents(void)
///
/// \brief Helper method to handle key press events.
///

void WaveEnergyConverter :: __handleKeyPressEvents(void)
{
    if (this->just_built) {
        return;
    }
    
    switch (this->event_ptr->key.code) {
        case (sf::Keyboard::U): {
            if (this->upgrade_level < MAX_UPGRADE_LEVELS) {
                this->__upgrade();
            }
            
            break;
        }
        
        
        default: {
            // do nothing!
            
            break;
        }
    }

    return;
}   /* __handleKeyPressEvents() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn WaveEnergyConverter :: __handleMouseButtonEvents(void)
///
/// \brief Helper method to handle mouse button events.
///

void WaveEnergyConverter :: __handleMouseButtonEvents(void)
{
    if (this->just_built) {
        return;
    }
    switch (this->event_ptr->mouseButton.button) {
        case (sf::Mouse::Left): {
            //...
            
            break;
        }
        
        
        case (sf::Mouse::Right): {
            //...
            
            break;
        }
        
        
        default: {
            // do nothing!
            
            break;
        }
    }
    
    return;
}   /* __handleMouseButtonEvents() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn WaveEnergyConverter :: WaveEnergyConverter(
///         double position_x,
///         double position_y,
///         sf::Event* event_ptr,
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr,
///         MessageHub* message_hub_ptr
///     )
///
/// \brief Constructor for the WaveEnergyConverter class.
///
/// Ref: \cite hexagon\n
///
/// \param position_x The x position of the tile.
///
/// \param position_y The y position of the tile.
///
/// \param event_ptr Pointer to the event class.
///
/// \param render_window_ptr Pointer to the render window.
///
/// \param assets_manager_ptr Pointer to the assets manager.
///
/// \param message_hub_ptr Pointer to the message hub.
///

WaveEnergyConverter :: WaveEnergyConverter(
    double position_x,
    double position_y,
    sf::Event* event_ptr,
    sf::RenderWindow* render_window_ptr,
    AssetsManager* assets_manager_ptr,
    MessageHub* message_hub_ptr
) :
TileImprovement(
    position_x,
    position_y,
    event_ptr,
    render_window_ptr,
    assets_manager_ptr,
    message_hub_ptr
)
{
    //  1. set attributes
    
    //  1.1. private
    //...
    
    //  1.2. public
    this->tile_improvement_type = TileImprovementType :: WAVE_ENERGY_CONVERTER;
    
    this->is_running = false;

    this->health = 100;
    
    this->capacity_kW = 100;
    this->upgrade_level = 1;
    
    this->production_MWh = 0;
    this->dispatchable_MWh = 0;
    
    this->tile_improvement_string = "WAVE ENERGY";
    
    this->__setUpTileImprovementSpriteAnimated();
    
    std::cout << "WaveEnergyConverter constructed at " << this << std::endl;
    
    return;
}   /* WaveEnergyConverter() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: getTileOptionsSubstring(void)
///
/// \brief Helper method to assemble and return tile options substring.
///
/// \return Tile options substring.
///

std::string WaveEnergyConverter :: getTileOptionsSubstring(void)
{
    //                   32 char x 17 line console "--------------------------------\n";
    std::string options_substring                = "CAPACITY:      ";
    options_substring                           += std::to_string(this->capacity_kW);
    options_substring                           += " kW (level ";
    options_substring                           += std::to_string(this->upgrade_level);
    options_substring                           += ")\n";
    
    options_substring                           += "PRODUCTION:    ";
    options_substring                           += std::to_string(this->production_MWh);
    options_substring                           += " MWh\n";
    
    options_substring                           += "DISPATCHABLE:  ";
    options_substring                           += std::to_string(this->dispatchable_MWh);
    options_substring                           += " MWh\n";
    
    options_substring                           += "HEALTH:        ";
    options_substring                           += std::to_string(this->health);
    options_substring                           += "/100\n";
    
    options_substring                           += "                                \n";
    options_substring                           += " **** WAVE ENERGY OPTIONS ****  \n";
    options_substring                           += "                                \n";
    options_substring                           += "     [E]:  OPEN PRODUCTION MENU \n";
    options_substring                           += "     [U]:  OPEN UPGRADE MENU    \n";
    options_substring                           += "HOLD [P]:  SCRAP (";
    options_substring                           += std::to_string(SCRAP_COST);
    options_substring                           += " K)";
    
    return options_substring;
}   /* getTileOptionsSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: processEvent(void)
///
/// \brief Method to process WaveEnergyConverter. To be called once per event.
///

void WaveEnergyConverter :: processEvent(void)
{
    TileImprovement :: processEvent();
    
    if (this->event_ptr->type == sf::Event::KeyPressed) {
        this->__handleKeyPressEvents();
    }
    
    if (this->event_ptr->type == sf::Event::MouseButtonPressed) {
        this->__handleMouseButtonEvents();
    }
    
    return;
}   /* processEvent() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: processMessage(void)
///
/// \brief Method to process WaveEnergyConverter. To be called once per message.
///

void WaveEnergyConverter :: processMessage(void)
{
    TileImprovement :: processMessage();
    
    //...
    
    return;
}   /* processMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: draw(void)
///
/// \brief Method to draw the hex tile to the render window. To be called once per
///     frame.
///

void WaveEnergyConverter :: draw(void)
{
    //  1. if just built, call base method and return
    if (this->just_built) {
        TileImprovement :: draw();
        
        return;
    }
    
    
    //  2. draw first element of animated sprite
    this->render_window_ptr->draw(this->tile_improvement_sprite_animated[0]);
    
    
    //  3. draw second element of animated sprite
    if (this->is_running) {
        //...
    }
    
    else {
        //...
    }
    
    this->render_window_ptr->draw(this->tile_improvement_sprite_animated[1]);
    
    //  4. draw production menu
    if (this->production_menu_open) {
        this->render_window_ptr->draw(this->production_menu_backing);
        this->render_window_ptr->draw(this->production_menu_backing_text);
        
        //...
    }
    
    this->frame++;
    return;
}   /* draw() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn WaveEnergyConverter :: ~WaveEnergyConverter(void)
///
/// \brief Destructor for the WaveEnergyConverter class.
///

WaveEnergyConverter :: ~WaveEnergyConverter(void)
{
    std::cout << "WaveEnergyConverter at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~WaveEnergyConverter() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
