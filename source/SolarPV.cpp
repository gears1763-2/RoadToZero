/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the SolarPV class.
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
/// \file SolarPV.cpp
///
/// \brief Implementation file for the SolarPV class.
///
/// A base class for the tile improvement hierarchy.
///


#include "../header/SolarPV.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void SolarPV :: __setUpTileImprovementSpriteStatic(void)
///
/// \brief Helper method to set up tile improvement sprite (static).
///

void SolarPV :: __setUpTileImprovementSpriteStatic(void)
{
    this->tile_improvement_sprite_static.setTexture(
        *(this->assets_manager_ptr->getTexture("solar PV array"))
    );
    
    this->tile_improvement_sprite_static.setOrigin(
        this->tile_improvement_sprite_static.getLocalBounds().width / 2,
        this->tile_improvement_sprite_static.getLocalBounds().height
    );
    
    this->tile_improvement_sprite_static.setPosition(
        this->position_x,
        this->position_y - 32
    );
    
    this->tile_improvement_sprite_static.setColor(
        sf::Color(255, 255, 255, 0)
    );
    
    return;
}   /* __setUpTileImprovementSpriteStatic() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void SolarPV :: __upgrade(void)
///
/// \brief Helper method to upgrade the diesel generator.
///

void SolarPV :: __upgrade(void)
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
/// \fn void SolarPV :: __handleKeyPressEvents(void)
///
/// \brief Helper method to handle key press events.
///

void SolarPV :: __handleKeyPressEvents(void)
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
/// \fn SolarPV :: __handleMouseButtonEvents(void)
///
/// \brief Helper method to handle mouse button events.
///

void SolarPV :: __handleMouseButtonEvents(void)
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
/// \fn SolarPV :: SolarPV(
///         double position_x,
///         double position_y,
///         sf::Event* event_ptr,
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr,
///         MessageHub* message_hub_ptr
///     )
///
/// \brief Constructor for the SolarPV class.
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

SolarPV :: SolarPV(
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
    this->tile_improvement_type = TileImprovementType :: SOLAR_PV;
    
    this->is_running = false;
    
    this->health = 100;
    
    this->capacity_kW = 100;
    this->upgrade_level = 1;
    
    this->production_MWh = 0;
    this->dispatchable_MWh = 0;
    
    this->tile_improvement_string = "SOLAR PV ARRAY";
    
    this->__setUpTileImprovementSpriteStatic();
    
    std::cout << "SolarPV constructed at " << this << std::endl;
    
    return;
}   /* SolarPV() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void SolarPV :: getTileOptionsSubstring(void)
///
/// \brief Helper method to assemble and return tile options substring.
///
/// \return Tile options substring.
///

std::string SolarPV :: getTileOptionsSubstring(void)
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
    options_substring                           += "   **** SOLAR PV OPTIONS ****   \n";
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
/// \fn void SolarPV :: processEvent(void)
///
/// \brief Method to process SolarPV. To be called once per event.
///

void SolarPV :: processEvent(void)
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
/// \fn void SolarPV :: processMessage(void)
///
/// \brief Method to process SolarPV. To be called once per message.
///

void SolarPV :: processMessage(void)
{
    TileImprovement :: processMessage();
    
    //...
    
    return;
}   /* processMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void SolarPV :: draw(void)
///
/// \brief Method to draw the hex tile to the render window. To be called once per
///     frame.
///

void SolarPV :: draw(void)
{
    //  1. if just built, call base method and return
    if (this->just_built) {
        TileImprovement :: draw();
        
        return;
    }
    
    
    //  2. draw static sprite
    this->render_window_ptr->draw(this->tile_improvement_sprite_static);
    
    
    //  3. draw production menu
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
/// \fn SolarPV :: ~SolarPV(void)
///
/// \brief Destructor for the SolarPV class.
///

SolarPV :: ~SolarPV(void)
{
    std::cout << "SolarPV at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~SolarPV() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
