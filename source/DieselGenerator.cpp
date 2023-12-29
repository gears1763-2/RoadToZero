/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the DieselGenerator class.
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
/// \file DieselGenerator.cpp
///
/// \brief Implementation file for the DieselGenerator class.
///
/// A base class for the tile improvement hierarchy.
///


#include "../header/DieselGenerator.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void DieselGenerator :: __setUpTileImprovementSpriteAnimated(void)
///
/// \brief Helper method to set up tile improvement sprite (static).
///

void DieselGenerator :: __setUpTileImprovementSpriteAnimated(void)
{
    sf::Sprite diesel_generator_sheet(
        *(this->assets_manager_ptr->getTexture("diesel generator"))
    );
    
    int n_elements = diesel_generator_sheet.getLocalBounds().height / 64;
    
    for (int i = 0; i < n_elements; i++) {
        this->tile_improvement_sprite_animated.push_back(
            sf::Sprite(
                *(this->assets_manager_ptr->getTexture("diesel generator")),
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
/// \fn void DieselGenerator :: __drawProductionMenu(void)
///
/// \brief Helper method to draw production menu assets.
///

void DieselGenerator :: __drawProductionMenu(void)
{
    //  1. draw animated sprite (in off state)
    for (size_t i = 0; i < this->tile_improvement_sprite_animated.size(); i++) {
        sf::Vector2f initial_position = this->tile_improvement_sprite_animated[i].getPosition();
        this->tile_improvement_sprite_animated[i].setPosition(400 - 138, 400 + 16);
        
        sf::Color initial_colour = this->tile_improvement_sprite_animated[i].getColor();
        this->tile_improvement_sprite_animated[i].setColor(sf::Color(255, 255, 255, 255));
        
        sf::Vector2f initial_scale = this->tile_improvement_sprite_animated[i].getScale();
        this->tile_improvement_sprite_animated[i].setScale(sf::Vector2f(1, 1));
        
        this->render_window_ptr->draw(this->tile_improvement_sprite_animated[i]);
        
        this->tile_improvement_sprite_animated[i].setPosition(initial_position);
        this->tile_improvement_sprite_animated[i].setColor(initial_colour);
        this->tile_improvement_sprite_animated[i].setScale(initial_scale);
    }
    
    //  2. draw production text
    std::string production_string = "[W]:  INCREASE PRODUCTION\n";
    production_string            += "[S]:  DECREASE PRODUCTION\n";
    production_string            += "                         \n";
    
    production_string            += "PRODUCTION:  ";
    production_string            += std::to_string(this->production_MWh);
    production_string            += " MWh (MAX ";
    production_string            += std::to_string(this->max_production_MWh);
    production_string            += ")\n";
    
    production_string            += "FUEL COST:   ";
    production_string            += std::to_string(this->fuel_cost);
    production_string            += " K\n";
    
    production_string            += "O&M COST:    ";
    production_string            += std::to_string(this->operation_maintenance_cost);
    production_string            += " K\n";
    
    production_string            += "EMISSIONS:   ";
    production_string            += std::to_string(this->emissions_tonnes_CO2e);
    production_string            += " tonnes (CO2e)\n";
    
    sf::Text production_text(
        production_string,
        *(this->assets_manager_ptr->getFont("Glass_TTY_VT220")),
        16
    );
    
    production_text.setOrigin(production_text.getLocalBounds().width / 2,0);
    production_text.setFillColor(MONOCHROME_TEXT_GREEN);
    
    production_text.setPosition(400 + 30, 400 - 55);
    
    this->render_window_ptr->draw(production_text);
    
    return;
}   /* __drawProductionMenu() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void DieselGenerator :: __upgrade(void)
///
/// \brief Helper method to upgrade the diesel generator.
///

void DieselGenerator :: __upgrade(void)
{
    if (this->credits < DIESEL_GENERATOR_BUILD_COST) {
        std::cout << "Cannot upgrade diesel generator: insufficient credits (need "
            << DIESEL_GENERATOR_BUILD_COST << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
    
    if (this->upgrade_level >= MAX_UPGRADE_LEVELS) {
        return;
    }
    
    this->is_running = false;
    
    this->__repair();
    
    this->capacity_kW += 100;
    this->upgrade_level++;
    
    this->production_MWh = 0;
    this->max_production_MWh += 72;
    
    this->just_upgraded = true;
    
    this->assets_manager_ptr->getSound("upgrade")->play();
    
    this->__sendCreditsSpentMessage(DIESEL_GENERATOR_BUILD_COST);
    this->__sendTileStateRequest();
    this->__sendGameStateRequest();
    
    return;
}   /* __upgrade() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void DieselGenerator :: __computeProductionCosts(void)
///
/// \brief Helper method to compute production costs (fuel, O&M, emissions) based on 
///     current production level.
///

void DieselGenerator :: __computeProductionCosts(void)
{
    double litres_diesel = this->production_MWh * LITRES_DIESEL_PER_MWH_PRODUCTION;
    
    double fuel_cost = (litres_diesel * COST_PER_LITRE_DIESEL) / 1000;
    this->fuel_cost = round(fuel_cost);
    
    double emissions_tonnes_CO2e = (litres_diesel * KG_CO2E_PER_LITRE_DIESEL) / 1000;
    this->emissions_tonnes_CO2e = round(emissions_tonnes_CO2e);
    
    double operation_maintenance_cost =
        (this->production_MWh * DIESEL_OP_MAINT_COST_PER_MWH_PRODUCTION) / 1000;
    this->operation_maintenance_cost = round(operation_maintenance_cost);
    
    this->__sendTileStateRequest();
    
    return;
}   /* __computeProductionCosts() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void DieselGenerator :: __breakdown(void)
///
/// \brief Helper method to trigger an equipment breakdown.
///

void DieselGenerator :: __breakdown(void)
{
    TileImprovement :: __breakdown();
    
    this->production_MWh = 0;
    this->fuel_cost = 0;
    this->operation_maintenance_cost = 0;
    this->emissions_tonnes_CO2e = 0;
    
    return;
}   /* __breakdown() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void DieselGenerator :: __handleKeyPressEvents(void)
///
/// \brief Helper method to handle key press events.
///

void DieselGenerator :: __handleKeyPressEvents(void)
{
    if (this->just_built) {
        return;
    }
    
    
    switch (this->event_ptr->key.code) {
        case (sf::Keyboard::U): {
            this->__upgrade();
            
            break;
        }
        
        
        case (sf::Keyboard::W): {
            if (this->production_menu_open) {
                this->production_MWh++;
                
                if (this->production_MWh > this->max_production_MWh) {
                    this->production_MWh = 0;
                }
                
                this->__computeProductionCosts();
                this->assets_manager_ptr->getSound("interface click")->play();
            }
            
            break;
        }
        
        
        case (sf::Keyboard::S): {
            if (this->production_menu_open) {
                this->production_MWh--;
                
                if (this->production_MWh < 0) {
                    this->production_MWh = this->max_production_MWh;
                }
                
                this->__computeProductionCosts();
                this->assets_manager_ptr->getSound("interface click")->play();
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
/// \fn DieselGenerator :: __handleMouseButtonEvents(void)
///
/// \brief Helper method to handle mouse button events.
///

void DieselGenerator :: __handleMouseButtonEvents(void)
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
/// \fn void DieselGenerator :: __sendImprovementStateMessage(void)
///
/// \brief Helper method to format and sent improvement state message.
///

void DieselGenerator :: __sendImprovementStateMessage(void)
{
    Message improvement_state_message;
    
    improvement_state_message.channel = GAME_CHANNEL;
    improvement_state_message.subject = "improvement state";
    
    improvement_state_message.int_payload["dispatch_MWh"] = this->production_MWh;
    improvement_state_message.int_payload["fuel_cost"] = this->fuel_cost;
    improvement_state_message.int_payload["operation_maintenance_cost"] =
        this->operation_maintenance_cost;
    improvement_state_message.int_payload["emissions_tonnes_CO2e"] =
        this->emissions_tonnes_CO2e;
    
    this->message_hub_ptr->sendMessage(improvement_state_message);
    
    std::cout << "Improvement state message sent by " << this << std::endl;
    
    return;
}   /* __sendImprovementStateMessage() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn DieselGenerator :: DieselGenerator(
///         double position_x,
///         double position_y,
///         int tile_resource,
///         sf::Event* event_ptr,
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr,
///         MessageHub* message_hub_ptr
///     )
///
/// \brief Constructor for the DieselGenerator class.
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

DieselGenerator :: DieselGenerator(
    double position_x,
    double position_y,
    int tile_resource,
    sf::Event* event_ptr,
    sf::RenderWindow* render_window_ptr,
    AssetsManager* assets_manager_ptr,
    MessageHub* message_hub_ptr
) :
TileImprovement(
    position_x,
    position_y,
    tile_resource,
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
    this->tile_improvement_type = TileImprovementType :: DIESEL_GENERATOR;
    
    this->is_running = false;
    
    this->health = 100;
    
    this->capacity_kW = 100;
    this->upgrade_level = 1;
    
    this->production_MWh = 0;
    this->max_production_MWh = 72;
    
    this->smoke_da = 1e-8 * SECONDS_PER_FRAME;
    this->smoke_dx = 5 * SECONDS_PER_FRAME;
    this->smoke_dy = -10 * SECONDS_PER_FRAME;
    this->smoke_prob = 16 * SECONDS_PER_FRAME;
    
    this->smoke_sprite_list = {};
    
    this->fuel_cost = 0;
    this->emissions_tonnes_CO2e = 0;
    
    this->tile_improvement_string = "DIESEL GEN";
    
    this->__setUpTileImprovementSpriteAnimated();
    
    std::cout << "DieselGenerator constructed at " << this << std::endl;
    
    return;
}   /* DieselGenerator() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void DieselGenerator :: getTileOptionsSubstring(void)
///
/// \brief Helper method to assemble and return tile options substring.
///
/// \return Tile options substring.
///

std::string DieselGenerator :: getTileOptionsSubstring(void)
{
    int upgrade_cost = DIESEL_GENERATOR_BUILD_COST;
    
    //                   32 char x 17 line console "--------------------------------\n";
    std::string options_substring                = "CAPACITY:    ";
    options_substring                           += std::to_string(this->capacity_kW);
    options_substring                           += " kW (level ";
    options_substring                           += std::to_string(this->upgrade_level);
    options_substring                           += ")\n";
    
    options_substring                           += "PRODUCTION:  ";
    options_substring                           += std::to_string(this->production_MWh);
    options_substring                           += " MWh (MAX ";
    options_substring                           += std::to_string(this->max_production_MWh);
    options_substring                           += ")\n";
    
    options_substring                           += "HEALTH:      ";
    options_substring                           += std::to_string(this->health);
    options_substring                           += "/100";
    
    if (this->health <= 0) {
        options_substring                       += " ** BROKEN! **\n";
    }
    
    else {
        options_substring                       += "\n";
    }
    
    options_substring                           += "                                \n";
    options_substring                           += "  **** DIESEL GEN OPTIONS ****  \n";
    options_substring                           += "                                \n";
    
    options_substring                           += "     [E]:  ";
    
    if (this->is_broken) {
        options_substring                       += "*** BROKEN! ***\n";
    }
    
    else {
        options_substring                       += "OPEN PRODUCTION MENU\n";
    }
    
    if (this->upgrade_level < MAX_UPGRADE_LEVELS) {
        options_substring                           += "     [U]:  + 100 kW (";
        options_substring                           += std::to_string(upgrade_cost);
        options_substring                           +=" K)\n";
    }
    
    options_substring                           += "HOLD [P]:  SCRAP (";
    options_substring                           += std::to_string(SCRAP_COST);
    options_substring                           += " K)";
    
    return options_substring;
}   /* getTileOptionsSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void DieselGenerator :: setIsSelected(bool is_selected)
///
/// \brief Method to set the is selected attribute.
///
/// \param is_selected The value to set the is selected attribute to.
///

void DieselGenerator :: setIsSelected(bool is_selected)
{
    TileImprovement :: setIsSelected(is_selected);
    
    if (this->is_running and this->is_selected) {
        this->assets_manager_ptr->getSound("diesel running")->play();
    }
    
    return;
}   /* setIsSelected() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void DieselGenerator :: advanceTurn(void)
///
/// \brief Method to handle turn advance.
///

void DieselGenerator :: advanceTurn(void)
{
    //  1. send improvement state message
    this->__sendImprovementStateMessage();
    
    //  2. handle start/stop
    if ((not this->is_running) and (this->production_MWh > 0)) {
        this->is_running = true;
        this->assets_manager_ptr->getSound("diesel start")->play();
    }
    
    else if (this->is_running and (this->production_MWh <= 0)) {
        this->is_running = false;
        this->tile_improvement_sprite_animated[1].setScale(sf::Vector2f(1, 1));
    }
    
    //  3. handle equipment health
    if (this->is_running) {
        this->health--;
        
        if (this->health <= 0) {
            this->__breakdown();
        }
    }
    
    //  4. close menus
    if (this->production_menu_open) {
        this->__closeProductionMenu();
    }
    
    if (this->upgrade_menu_open) {
        this->__closeUpgradeMenu();
    }
    
    //  5. send tile state request (if selected)
    if (this->is_selected) {
        this->__sendTileStateRequest();
    }
    
    return;
}   /* advanceTurn() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void DieselGenerator :: processEvent(void)
///
/// \brief Method to process DieselGenerator. To be called once per event.
///

void DieselGenerator :: processEvent(void)
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
/// \fn void DieselGenerator :: processMessage(void)
///
/// \brief Method to process DieselGenerator. To be called once per message.
///

void DieselGenerator :: processMessage(void)
{
    TileImprovement :: processMessage();
    
    //...
    
    return;
}   /* processMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void DieselGenerator :: draw(void)
///
/// \brief Method to draw the hex tile to the render window. To be called once per
///     frame.
///

void DieselGenerator :: draw(void)
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
    double move_x = 0;
    double move_y = 0;
    
    if (this->is_running) {
        this->tile_improvement_sprite_animated[1].setScale(
            sf::Vector2f(
                1 + 0.05 * pow(cos((6 * M_PI * this->frame) / FRAMES_PER_SECOND), 2),
                1 + 0.05 * pow(cos((6 * M_PI * this->frame) / FRAMES_PER_SECOND), 2)
            )
        );
        
        move_x = 1 * ((double)rand() / RAND_MAX) - 0.5;
        move_y = 1 * ((double)rand() / RAND_MAX) - 0.5;
        
        this->tile_improvement_sprite_animated[1].move(move_x, move_y);
    }
    
    this->render_window_ptr->draw(this->tile_improvement_sprite_animated[1]);
    
    if (this->is_running) {
        this->tile_improvement_sprite_animated[1].move(-1 * move_x, -1 * move_y);
    }
    
    
    //  5. draw smoke effects
    if (this->is_running) {
        if ((double)rand() / RAND_MAX < smoke_prob) {
            this->smoke_sprite_list.push_back(
                sf::Sprite(*(this->assets_manager_ptr->getTexture("emissions")))
            );
            
            this->smoke_sprite_list.back().setOrigin(
                this->smoke_sprite_list.back().getLocalBounds().width / 2,
                this->smoke_sprite_list.back().getLocalBounds().height / 2
            );
            
            this->smoke_sprite_list.back().setPosition(
                this->position_x + 9 + 4 * ((double)rand() / RAND_MAX) - 2,
                this->position_y - 33
            );
        }
    }
    
    std::list<sf::Sprite>::iterator iter = this->smoke_sprite_list.begin();

    double alpha = 255;
    
    while (iter != this->smoke_sprite_list.end()) {
        this->render_window_ptr->draw(*iter);
        
        alpha = (*iter).getColor().a;
    
        alpha -= this->smoke_da;
        
        if (alpha <= 0) {
            iter = this->smoke_sprite_list.erase(iter);
            continue;
        }
        
        (*iter).setColor(sf::Color(255, 255, 255, alpha));
        
        (*iter).move(
            this->smoke_dx + 2 * (((double)rand() / RAND_MAX) - 1) / FRAMES_PER_SECOND,
            this->smoke_dy
        );
        
        (*iter).rotate(((double)rand() / RAND_MAX));
        
        iter++;
    }
    
    
    //  6. handle dispatch illustration
    if (this->production_MWh > 0) {
        this->dispatch_text.setString(std::to_string(this->production_MWh));
        this->__drawDispatch();
    }
    
    
    //  7. draw production menu
    if (this->production_menu_open) {
        this->render_window_ptr->draw(this->production_menu_backing);
        this->render_window_ptr->draw(this->production_menu_backing_text);
        
        this->__drawProductionMenu();
    }
    
    
    //  8. handle broken effects
    if (this->is_broken) {
        for (size_t i = 0; i < this->tile_improvement_sprite_animated.size(); i++) {
            this->tile_improvement_sprite_animated[i].setColor(
                sf::Color(
                    255,
                    255 * pow(cos((M_PI * this->frame) / FRAMES_PER_SECOND), 2),
                    255 * pow(cos((M_PI * this->frame) / FRAMES_PER_SECOND), 2),
                    255
                )
            );
        }
    }
    
    this->frame++;
    return;
}   /* draw() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn DieselGenerator :: ~DieselGenerator(void)
///
/// \brief Destructor for the DieselGenerator class.
///

DieselGenerator :: ~DieselGenerator(void)
{
    std::cout << "DieselGenerator at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~DieselGenerator() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
