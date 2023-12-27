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
/// \fn void WaveEnergyConverter :: __upgradePowerCapacity(void)
///
/// \brief Helper method to upgrade power capacity.
///

void WaveEnergyConverter :: __upgradePowerCapacity(void)
{
    if (this->credits < WAVE_ENERGY_CONVERTER_BUILD_COST) {
        std::cout << "Cannot upgrade wave energy converter: insufficient credits (need "
            << WAVE_ENERGY_CONVERTER_BUILD_COST << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
    
    if (this->upgrade_level >= MAX_UPGRADE_LEVELS) {
        return;
    }
    
    this->health = 100;
    
    this->capacity_kW += 100;
    this->upgrade_level++;
    
    this->just_upgraded = true;
    
    this->assets_manager_ptr->getSound("upgrade")->play();
    
    this->__sendCreditsSpentMessage(WAVE_ENERGY_CONVERTER_BUILD_COST);
    this->__sendTileStateRequest();
    this->__sendGameStateRequest();
    
    return;
}   /* __upgradePowerCapacity() */

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
            this->__openUpgradeMenu();
            
            break;
        }
        
        
        case (sf::Keyboard::W): {
            if (this->production_menu_open) {
                //...
            }
            
            else if (this->upgrade_menu_open) {
                this->__upgradePowerCapacity();
            }
            
            break;
        }
        
        
        case (sf::Keyboard::S): {
            //...
            
            break;
        }
        
        
        case (sf::Keyboard::D): {
            if (this->upgrade_menu_open) {
                this->__upgradeStorageCapacity();
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



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: __drawUpgradeOptions(void)
///
/// \brief Helper method to set up and draw upgrade options.
///

void WaveEnergyConverter :: __drawUpgradeOptions(void)
{
    //  1. draw power capacity upgrade sprite
    for (size_t i = 0; i < this->tile_improvement_sprite_animated.size(); i++) {
        sf::Vector2f initial_position = this->tile_improvement_sprite_animated[i].getPosition();
        this->tile_improvement_sprite_animated[i].setPosition(400 - 100, 400 - 32 - 20);
        
        sf::Color initial_colour = this->tile_improvement_sprite_animated[i].getColor();
        this->tile_improvement_sprite_animated[i].setColor(sf::Color(255, 255, 255, 255));
        
        sf::Vector2f initial_scale = this->tile_improvement_sprite_animated[i].getScale();
        this->tile_improvement_sprite_animated[i].setScale(sf::Vector2f(1, 1));
        
        this->render_window_ptr->draw(this->tile_improvement_sprite_animated[i]);
        
        this->tile_improvement_sprite_animated[i].setPosition(initial_position);
        this->tile_improvement_sprite_animated[i].setColor(initial_colour);
        this->tile_improvement_sprite_animated[i].setScale(initial_scale);
    }
    
    this->render_window_ptr->draw(this->upgrade_arrow_sprite);
    
    
    //  2. draw power capacity upgrade text
    //                  16 char line = "                \n"
    std::string power_upgrade_string = "POWER CAPACITY  \n";
    power_upgrade_string            += "                \n";
    
    power_upgrade_string            += "CAPACITY:  ";
    power_upgrade_string            += std::to_string(this->capacity_kW);
    power_upgrade_string            += " kW\n";
    
    power_upgrade_string            += "LEVEL:     ";
    power_upgrade_string            += std::to_string(this->upgrade_level);
    power_upgrade_string            += "\n\n";
    
    if (this->upgrade_level < MAX_UPGRADE_LEVELS) {
        power_upgrade_string        += "[W]: + 100 kW (";
        power_upgrade_string        +=  std::to_string(WAVE_ENERGY_CONVERTER_BUILD_COST);
        power_upgrade_string        += " K)\n";
    }
    
    else {
        power_upgrade_string        += " * MAX LEVEL *  \n";
    }
    
    sf::Text power_upgrade_text = sf::Text(
        power_upgrade_string,
        *(this->assets_manager_ptr->getFont("Glass_TTY_VT220")),
        16
    );
    
    power_upgrade_text.setOrigin(power_upgrade_text.getLocalBounds().width / 2, 0);
    power_upgrade_text.setPosition(400 - 100, 400 - 32 + 16);
    power_upgrade_text.setFillColor(MONOCHROME_TEXT_GREEN);
    
    this->render_window_ptr->draw(power_upgrade_text);
    
    
    //  3. draw energy capacity (storage) upgrade sprite
    this->render_window_ptr->draw(this->storage_upgrade_sprite);
    this->render_window_ptr->draw(this->upgrade_plus_sprite);
    
    
    //  4. draw energy capacity (storage) upgrade text
    //                   16 char line = "                \n"
    std::string energy_upgrade_string = "ENERGY CAPACITY \n";
    energy_upgrade_string            += "                \n";
    
    energy_upgrade_string            += "CAPACITY:  ";
    energy_upgrade_string            += std::to_string(this->storage_level * 200);
    energy_upgrade_string            += " kWh\n";
    
    energy_upgrade_string            += "LEVEL:     ";
    energy_upgrade_string            += std::to_string(this->storage_level);
    energy_upgrade_string            += "\n\n";
    
    if (this->storage_level < MAX_STORAGE_LEVELS) {
        energy_upgrade_string        += "[D]: + 200 kWh (";
        energy_upgrade_string        +=  std::to_string(ENERGY_STORAGE_SYSTEM_BUILD_COST);
        energy_upgrade_string        += " K)\n";
    }
    
    else {
        energy_upgrade_string += " * MAX LEVEL *  \n";
    }
    
    sf::Text energy_upgrade_text = sf::Text(
        energy_upgrade_string,
        *(this->assets_manager_ptr->getFont("Glass_TTY_VT220")),
        16
    );
    
    energy_upgrade_text.setOrigin(energy_upgrade_text.getLocalBounds().width / 2, 0);
    energy_upgrade_text.setPosition(400 + 100, 400 - 32 + 16);
    energy_upgrade_text.setFillColor(MONOCHROME_TEXT_GREEN);
    
    this->render_window_ptr->draw(energy_upgrade_text);
    
    return;
}   /* __drawUpgradeOptions() */

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
    this->storage_level = 0;
    
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
    
    
    //  2. handle upgrade effects
    if (this->just_upgraded) {
        for (size_t i = 0; i < this->tile_improvement_sprite_animated.size(); i++) {
            this->tile_improvement_sprite_animated[i].setColor(
                sf::Color(
                    255 * pow(cos((M_PI * this->upgrade_frame) / FRAMES_PER_SECOND), 2),
                    255,
                    255 * pow(cos((M_PI * this->upgrade_frame) / FRAMES_PER_SECOND), 2),
                    255
                )
            );
            
            this->tile_improvement_sprite_animated[i].setScale(
                sf::Vector2f(
                    1 + 0.2 * pow(cos((M_PI * this->upgrade_frame) / FRAMES_PER_SECOND), 2),
                    1 + 0.2 * pow(cos((M_PI * this->upgrade_frame) / FRAMES_PER_SECOND), 2)
                )
            );
        }
        
        this->upgrade_frame++;
    }
    
    if (this->upgrade_frame >= 2 * FRAMES_PER_SECOND) {
        for (size_t i = 0; i < this->tile_improvement_sprite_animated.size(); i++) {
            this->tile_improvement_sprite_animated[i].setColor(
                sf::Color(255,255,255,255)
            );
            
            this->tile_improvement_sprite_animated[i].setScale(sf::Vector2f(1,1));
        }
        
        this->just_upgraded = false;
        this->upgrade_frame = 0;
    }
    
    
    //  3. draw first element of animated sprite
    this->render_window_ptr->draw(this->tile_improvement_sprite_animated[0]);
    
    
    //  4. draw second element of animated sprite
    if (this->is_running) {
        //...
    }
    
    else {
        //...
    }
    
    this->render_window_ptr->draw(this->tile_improvement_sprite_animated[1]);
    
    //  5. draw production menu
    if (this->production_menu_open) {
        this->render_window_ptr->draw(this->production_menu_backing);
        this->render_window_ptr->draw(this->production_menu_backing_text);
        
        //...
    }
    
    //  6. draw upgrade menu
    if (this->upgrade_menu_open) {
        this->render_window_ptr->draw(this->upgrade_menu_backing);
        this->render_window_ptr->draw(this->upgrade_menu_backing_text);
        
        this->__drawUpgradeOptions();
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
