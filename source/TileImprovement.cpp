/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the TileImprovement class.
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
/// \file TileImprovement.cpp
///
/// \brief Implementation file for the TileImprovement class.
///
/// A base class for the tile improvement hierarchy.
///


#include "../header/TileImprovement.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __setUpProductionMenu(void)
///
/// \brief Helper method to set up and position production menu assets (drawable).
///

void TileImprovement :: __setUpProductionMenu(void)
{
    //  1. set up and place production menu backing and text
    this->production_menu_backing.setSize(sf::Vector2f(400, 256));
    this->production_menu_backing.setOrigin(200, 128);
    this->production_menu_backing.setPosition(400, 400);
    this->production_menu_backing.setFillColor(MONOCHROME_SCREEN_BACKGROUND);
    this->production_menu_backing.setOutlineColor(MENU_FRAME_GREY);
    this->production_menu_backing.setOutlineThickness(4);
    
    this->production_menu_backing_text.setString("**** PRODUCTION MENU ****");
    this->production_menu_backing_text.setFont(
        *(this->assets_manager_ptr->getFont("Glass_TTY_VT220"))
    );
    this->production_menu_backing_text.setCharacterSize(16);
    this->production_menu_backing_text.setFillColor(MONOCHROME_TEXT_GREEN);
    this->production_menu_backing_text.setOrigin(
        this->production_menu_backing_text.getLocalBounds().width / 2, 0
    );
    this->production_menu_backing_text.setPosition(400, 400 - 128 + 4);
    
    return;
}   /* __setUpProductionMenu() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __setUpUpgradeMenu(void)
///
/// \brief Helper method to set up and position upgrade menu assets (drawable).
///

void TileImprovement :: __setUpUpgradeMenu(void)
{
    //  1. set up and place upgrade menu backing and text
    this->upgrade_menu_backing.setSize(sf::Vector2f(400, 256));
    this->upgrade_menu_backing.setOrigin(200, 128);
    this->upgrade_menu_backing.setPosition(400, 400);
    this->upgrade_menu_backing.setFillColor(MONOCHROME_SCREEN_BACKGROUND);
    this->upgrade_menu_backing.setOutlineColor(MENU_FRAME_GREY);
    this->upgrade_menu_backing.setOutlineThickness(4);
    
    this->upgrade_menu_backing_text.setString("**** UPGRADE MENU ****");
    this->upgrade_menu_backing_text.setFont(
        *(this->assets_manager_ptr->getFont("Glass_TTY_VT220"))
    );
    this->upgrade_menu_backing_text.setCharacterSize(16);
    this->upgrade_menu_backing_text.setFillColor(MONOCHROME_TEXT_GREEN);
    this->upgrade_menu_backing_text.setOrigin(
        this->upgrade_menu_backing_text.getLocalBounds().width / 2, 0
    );
    this->upgrade_menu_backing_text.setPosition(400, 400 - 128 + 4);
    
    
    //  2. set up and place storage upgrade sprite (with upgrade plus)
    this->storage_upgrade_sprite = sf::Sprite(
        *(this->assets_manager_ptr->getTexture("energy storage system"))
    );
    
    this->storage_upgrade_sprite.setOrigin(
        this->storage_upgrade_sprite.getLocalBounds().width / 2,
        this->storage_upgrade_sprite.getLocalBounds().height
    );
    
    this->storage_upgrade_sprite.setPosition(400 + 100, 400 - 32);
    
    this->upgrade_plus_sprite = sf::Sprite(
        *(this->assets_manager_ptr->getTexture("upgrade plus"))
    );
    
    this->upgrade_plus_sprite.setOrigin(
        this->upgrade_plus_sprite.getLocalBounds().width / 2,
        this->upgrade_plus_sprite.getLocalBounds().height / 2
    );
    
    this->upgrade_plus_sprite.setPosition(400 + 130, 400 - 64);
    
    
    //  3. set up and place upgrade arrow sprite
    this->upgrade_arrow_sprite = sf::Sprite(
        *(this->assets_manager_ptr->getTexture("upgrade arrow"))
    );
    
    this->upgrade_arrow_sprite.setOrigin(
        this->upgrade_arrow_sprite.getLocalBounds().width / 2,
        this->upgrade_arrow_sprite.getLocalBounds().height / 2
    );
    
    this->upgrade_arrow_sprite.setPosition(400 - 64, 400 - 64);
    
    
    return;
}   /* __setUpUpgradeMenu() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __upgradeStorageCapacity(void)
///
/// \brief Helper method to upgrade storage capacity.
///

void TileImprovement :: __upgradeStorageCapacity(void)
{
    if (this->credits < ENERGY_STORAGE_SYSTEM_BUILD_COST) {
        std::cout << "Cannot add energy storage: insufficient credits (need "
            << ENERGY_STORAGE_SYSTEM_BUILD_COST << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
    
    if (this->storage_level >= MAX_STORAGE_LEVELS) {
        return;
    }
    
    this->health = 100;
    
    this->storage_level++;
    
    this->storage_upgrade_sprite_vec.push_back(
        sf::Sprite(
            *(this->assets_manager_ptr->getTexture("storage level"))
        )
    );
    
    this->storage_upgrade_sprite_vec.back().setOrigin(
        this->storage_upgrade_sprite_vec.back().getLocalBounds().width / 2,
        this->storage_upgrade_sprite_vec.back().getLocalBounds().height
    );
    
    this->storage_upgrade_sprite_vec.back().setPosition(
        this->position_x + 18,
        this->position_y + 25 - 7 * this->storage_upgrade_sprite_vec.size()
    );
    
    this->just_upgraded = true;
    
    this->assets_manager_ptr->getSound("upgrade")->play();
    
    this->__sendCreditsSpentMessage(ENERGY_STORAGE_SYSTEM_BUILD_COST);
    this->__sendTileStateRequest();
    this->__sendGameStateRequest();
    
    return;
}   /* __upgradeStorageCapacity() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __handleKeyPressEvents(void)
///
/// \brief Helper method to handle key press events.
///

void TileImprovement :: __handleKeyPressEvents(void)
{
    if (this->tile_improvement_type == TileImprovementType :: SETTLEMENT) {
        return;
    }
    
    if (this->just_built) {
        return;
    }
    
    switch (this->event_ptr->key.code) {
        case (sf::Keyboard::E): {
            this->__openProductionMenu();
            
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
/// \fn TileImprovement :: __handleMouseButtonEvents(void)
///
/// \brief Helper method to handle mouse button events.
///

void TileImprovement :: __handleMouseButtonEvents(void)
{
    if (this->tile_improvement_type == TileImprovementType :: SETTLEMENT) {
        return;
    }
    
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
/// \fn void TileImprovement :: __openProductionMenu(void)
///
/// \brief Helper method to open the production menu.
///

void TileImprovement :: __openProductionMenu(void)
{
    if (this->production_menu_open) {
        return;
    }
    
    if (this->upgrade_menu_open) {
        this->__closeUpgradeMenu();
    }
    
    this->production_menu_open = true;
    this->assets_manager_ptr->getSound("build menu open")->play();
    
    return;
}   /* __openProductionMenu() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __closeProductionMenu(void)
///
/// \brief Helper method to close the production menu.
///

void TileImprovement :: __closeProductionMenu(void)
{
    if (not this->production_menu_open) {
        return;
    }
    
    this->production_menu_open = false;
    this->assets_manager_ptr->getSound("build menu close")->play();
    
    return;
}   /* __closeProductionMenu() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __openUpgradeMenu(void)
///
/// \brief Helper method to open the upgrade menu.
///

void TileImprovement :: __openUpgradeMenu(void)
{
    if (this->upgrade_menu_open) {
        return;
    }
    
    if (this->production_menu_open) {
        this->__closeProductionMenu();
    }
    
    this->upgrade_menu_open = true;
    this->assets_manager_ptr->getSound("build menu open")->play();
    
    return;
}   /* __openUpgradeMenu() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __closeUpgradeMenu(void)
///
/// \brief Helper method to close the build menu.
///

void TileImprovement :: __closeUpgradeMenu(void)
{
    if (not this->upgrade_menu_open) {
        return;
    }
    
    this->upgrade_menu_open = false;
    this->assets_manager_ptr->getSound("build menu close")->play();
    
    return;
}   /* __closeUpgradeMenu() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __sendTileStateRequest(void)
///
/// \brief Helper method to format and send a request for the parent HexTile to send
///     a tile state message.
///

void TileImprovement :: __sendTileStateRequest(void)
{
    Message tile_state_request;
    
    tile_state_request.channel = TILE_STATE_CHANNEL;
    tile_state_request.subject = "state request";
    
    this->message_hub_ptr->sendMessage(tile_state_request);
    
    std::cout << "Tile state request sent by " << this << std::endl;
    return;
}   /* __sendTileStateRequest() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __sendGameStateRequest(void)
///
/// \brief Helper method to format and send a game state request (message).
///

void TileImprovement :: __sendGameStateRequest(void)
{
    Message game_state_request;
    
    game_state_request.channel = GAME_CHANNEL;
    game_state_request.subject = "state request";
    
    this->message_hub_ptr->sendMessage(game_state_request);
    
    std::cout << "Game state request message sent by " << this << std::endl;
    return;
}   /* __sendGameStateRequest() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __sendCreditsSpentMessage(int credits_spent)
///
/// \brief Helper method to format and send a credits spent message.
///
/// \param credits_spent The number of credits that were spent.
///

void TileImprovement :: __sendCreditsSpentMessage(int credits_spent)
{
    Message credits_spent_message;
    
    credits_spent_message.channel = GAME_CHANNEL;
    credits_spent_message.subject = "credits spent";
    
    credits_spent_message.int_payload["credits spent"] = credits_spent;
    
    this->message_hub_ptr->sendMessage(credits_spent_message);
    
    std::cout << "Credits spent (" << credits_spent << ") message sent by " << this
        << std::endl;
    return;
}   /* __sendCreditsSpentMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __sendInsufficientCreditsMessage(void)
///
/// \brief Helper method to format and send an insufficient credits message.
///

void TileImprovement :: __sendInsufficientCreditsMessage(void)
{
    Message insufficient_credits_message;
    
    insufficient_credits_message.channel = GAME_CHANNEL;
    insufficient_credits_message.subject = "insufficient credits";
    
    this->message_hub_ptr->sendMessage(insufficient_credits_message);
    
    std::cout << "Insufficient credits message sent by " << this << std::endl;
    
    return;
}   /* __sendInsufficientCreditsMessage() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn TileImprovement :: TileImprovement(
///         double position_x,
///         double position_y,
///         int tile_resource,
///         sf::Event* event_ptr,
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr,
///         MessageHub* message_hub_ptr
///     )
///
/// \brief Constructor for the TileImprovement class.
///
/// Ref: \cite hexagon\n
///
/// \param position_x The x position of the tile.
///
/// \param position_y The y position of the tile.
///
/// \param tile_resource The renewable resource quality of the tile.
///
/// \param event_ptr Pointer to the event class.
///
/// \param render_window_ptr Pointer to the render window.
///
/// \param assets_manager_ptr Pointer to the assets manager.
///
/// \param message_hub_ptr Pointer to the message hub.
///

TileImprovement :: TileImprovement(
    double position_x,
    double position_y,
    int tile_resource,
    sf::Event* event_ptr,
    sf::RenderWindow* render_window_ptr,
    AssetsManager* assets_manager_ptr,
    MessageHub* message_hub_ptr
)
{
    //  1. set attributes
    
    //  1.1. protected
    this->event_ptr = event_ptr;
    this->render_window_ptr = render_window_ptr;
    
    this->assets_manager_ptr = assets_manager_ptr;
    this->message_hub_ptr = message_hub_ptr;
    
    //  1.2. public
    this->is_selected = true;
    this->just_built = true;
    this->production_menu_open = false;
    this->upgrade_menu_open = false;
    
    this->just_upgraded = false;
    this->upgrade_frame = 0;
    
    this->frame = 0;
    this->credits = 0;
    this->month = 1;
    this->demand_MWh = 0;
    
    this->tile_resource = tile_resource;
    
    switch (this->tile_resource) {
        case (0): {
            this->tile_resource_scalar = 0.8;
            
            break;
        }
        
        
        case (1): {
            this->tile_resource_scalar = 0.9;
            
            break;
        }
        
        
        case (2): {
            this->tile_resource_scalar = 1;
            
            break;
        }
        
        
        case (3): {
            this->tile_resource_scalar = 1.1;
            
            break;
        }
        
        
        case (4): {
            this->tile_resource_scalar = 1.2;
            
            break;
        }
        
        
        default: {
            this->tile_resource_scalar = 1;
        }
    }
    
    this->position_x = position_x;
    this->position_y = position_y;
    
    this->game_phase = "build settlement";
    
    this->__setUpProductionMenu();
    this->__setUpUpgradeMenu();
    
    std::cout << "TileImprovement constructed at " << this << std::endl;
    
    return;
}   /* TileImprovement() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: setIsSelected(bool is_selected)
///
/// \brief Method to set the is selected attribute.
///
/// \param is_selected The value to set the is selected attribute to.
///

void TileImprovement :: setIsSelected(bool is_selected)
{
    this->is_selected = is_selected;
    
    if ((not is_selected) and this->production_menu_open) {
        this->__closeProductionMenu();
    }
    
    if ((not is_selected) and this->upgrade_menu_open) {
        this->__closeUpgradeMenu();
    }
    
    return;
}   /* setIsSelected() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: processEvent(void)
///
/// \brief Method to process TileImprovement. To be called once per event.
///

void TileImprovement :: processEvent(void)
{
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
/// \fn void TileImprovement :: processMessage(void)
///
/// \brief Method to process TileImprovement. To be called once per message.
///

void TileImprovement :: processMessage(void)
{
    //...
    
    return;
}   /* processMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: draw(void)
///
/// \brief Method to draw the hex tile to the render window. To be called once per
///     frame.
///

void TileImprovement :: draw(void)
{
    if (this->tile_improvement_sprite_static.getTexture() != NULL) {
        int alpha = this->tile_improvement_sprite_static.getColor().a;
    
        alpha += 0.08 * FRAMES_PER_SECOND;
        
        this->tile_improvement_sprite_static.setColor(
            sf::Color(255, 255, 255, alpha)
        );
        
        this->tile_improvement_sprite_static.move(0, 50 * SECONDS_PER_FRAME);
        
        if (
            (alpha >= 255) or
            (this->tile_improvement_sprite_static.getPosition().y >= this->position_y + 12)
        ) {
            this->tile_improvement_sprite_static.setColor(
                sf::Color(255, 255, 255, 255)
            );
            
            this->tile_improvement_sprite_static.setPosition(
                this->position_x,
                this->position_y + 12
            );
            
            this->just_built = false;
            this->assets_manager_ptr->getSound("place improvement")->play();
        }
        
        this->render_window_ptr->draw(this->tile_improvement_sprite_static);
    }
    
    
    else {
        int alpha = 0;
        
        for (size_t i = 0; i < this->tile_improvement_sprite_animated.size(); i++) {
            alpha = this->tile_improvement_sprite_animated[i].getColor().a;
            
            alpha += 0.08 * FRAMES_PER_SECOND;
            
            this->tile_improvement_sprite_animated[i].setColor(
                sf::Color(255, 255, 255, alpha)
            );
            
            this->tile_improvement_sprite_animated[i].move(0, 50 * SECONDS_PER_FRAME);
            
            if (
                (alpha >= 255) or
                (this->tile_improvement_sprite_animated[i].getPosition().y >= this->position_y + 12)
            ) {
                this->tile_improvement_sprite_animated[i].setColor(
                    sf::Color(255, 255, 255, 255)
                );
                
                this->tile_improvement_sprite_animated[i].setPosition(
                    this->position_x,
                    this->position_y + 12
                );
            }
            
            this->render_window_ptr->draw(this->tile_improvement_sprite_animated[i]);
        }
        
        if (
            (alpha >= 255) or
            (this->tile_improvement_sprite_animated[0].getPosition().y >= this->position_y + 12)
        ) {
            this->just_built = false;
            this->assets_manager_ptr->getSound("place improvement")->play();
            
            switch (this->tile_improvement_type) {
                case (TileImprovementType :: WIND_TURBINE): {
                    for (size_t i = 0; i < this->tile_improvement_sprite_animated.size(); i++) {
                        this->tile_improvement_sprite_animated[i].setOrigin(32, 32);
                        this->tile_improvement_sprite_animated[i].move(0, -32);
                    }
                    
                    break;
                }
                
                
                case (TileImprovementType :: TIDAL_TURBINE): {
                    for (size_t i = 0; i < this->tile_improvement_sprite_animated.size(); i++) {
                        this->tile_improvement_sprite_animated[i].setOrigin(32, 45);
                        this->tile_improvement_sprite_animated[i].move(0, -19);
                    }
                    
                    break;
                }
                
                
                case (TileImprovementType :: WAVE_ENERGY_CONVERTER): {
                    for (size_t i = 0; i < this->tile_improvement_sprite_animated.size(); i++) {
                        this->tile_improvement_sprite_animated[i].setOrigin(32, 32);
                        this->tile_improvement_sprite_animated[i].move(0, -32);
                    }
                    
                    break;
                }
                
                
                default: {
                    // do nothing!
                    
                    break;
                }
            }
        }
    }
    
    
    this->frame++;
    return;
}   /* draw() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn TileImprovement :: ~TileImprovement(void)
///
/// \brief Destructor for the TileImprovement class.
///

TileImprovement :: ~TileImprovement(void)
{
    std::cout << "TileImprovement at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~TileImprovement() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
