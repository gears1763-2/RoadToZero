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
/// \fn void WaveEnergyConverter :: __drawProductionMenu(void)
///
/// \brief Helper method to draw production menu assets.
///

void WaveEnergyConverter :: __drawProductionMenu(void)
{
    //  1. draw static sprite
    for (size_t i = 0; i < this->tile_improvement_sprite_animated.size(); i++) {
        sf::Vector2f initial_position = this->tile_improvement_sprite_animated[i].getPosition();
        this->tile_improvement_sprite_animated[i].setPosition(400 - 138, 400 + 16);
        
        sf::Color initial_colour = this->tile_improvement_sprite_animated[i].getColor();
        this->tile_improvement_sprite_animated[i].setColor(sf::Color(255, 255, 255, 255));
        
        sf::Vector2f initial_scale = this->tile_improvement_sprite_animated[i].getScale();
        this->tile_improvement_sprite_animated[i].setScale(sf::Vector2f(1, 1));
        
        double initial_rotation = this->tile_improvement_sprite_animated[i].getRotation();
        this->tile_improvement_sprite_animated[i].setRotation(0);
        
        this->render_window_ptr->draw(this->tile_improvement_sprite_animated[i]);
        
        this->tile_improvement_sprite_animated[i].setPosition(initial_position);
        this->tile_improvement_sprite_animated[i].setColor(initial_colour);
        this->tile_improvement_sprite_animated[i].setScale(initial_scale);
        this->tile_improvement_sprite_animated[i].setRotation(initial_rotation);
    }
    
    //  2. draw production text
    std::string production_string = "[W]:  INCREASE DISPATCH\n";
    production_string            += "[S]:  DECREASE DISPATCH\n";
    production_string            += "                         \n";
    
    production_string            += "DISPATCH:  ";
    production_string            += std::to_string(this->dispatch_MWh);
    production_string            += " MWh (MAX ";
    production_string            += std::to_string(this->dispatchable_MWh);
    production_string            += ")\n";
    
    production_string            += "O&M COST:  ";
    production_string            += std::to_string(this->operation_maintenance_cost);
    production_string            += " K\n";
    
    sf::Text production_text(
        production_string,
        *(this->assets_manager_ptr->getFont("Glass_TTY_VT220")),
        16
    );
    
    production_text.setOrigin(production_text.getLocalBounds().width / 2,0);
    production_text.setFillColor(MONOCHROME_TEXT_GREEN);
    
    production_text.setPosition(400 + 30, 400 - 45);
    
    this->render_window_ptr->draw(production_text);
    
    return;
}   /* __drawProductionMenu() */

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
    
    TileImprovement :: __repair();
    
    this->capacity_kW += 100;
    this->upgrade_level++;
    
    this->max_daily_production_MWh = (double)(24 * this->capacity_kW) / 1000;
    
    this->__computeProduction();
    this->__computeDispatch();
    
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
/// \fn void WaveEnergyConverter :: __computeProductionCosts(void)
///
/// \brief Helper method to compute production costs (O&M) based on current production
///     level.
///

void WaveEnergyConverter :: __computeProductionCosts(void)
{
    double operation_maintenance_cost =
        (this->production_MWh * WAVE_OP_MAINT_COST_PER_MWH_PRODUCTION) / 1000;
    this->operation_maintenance_cost = round(operation_maintenance_cost);
    
    return;
}   /* __computeProductionCosts() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: __breakdown(void)
///
/// \brief Helper method to trigger an equipment breakdown.
///

void WaveEnergyConverter :: __breakdown(void)
{
    TileImprovement :: __breakdown();
    
    this->production_MWh = 0;
    this->dispatch_MWh = 0;
    this->dispatchable_MWh = 0;
    this->operation_maintenance_cost = 0;
    
    return;
}   /* __breakdown() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: __repair(void)
///
/// \brief Helper method to repair the wave energy converter.
///

void WaveEnergyConverter :: __repair(void)
{
    if (this->credits < WAVE_ENERGY_CONVERTER_BUILD_COST) {
        std::cout << "Cannot repair wave energy converter: insufficient credits (need "
            << WAVE_ENERGY_CONVERTER_BUILD_COST << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
    
    TileImprovement :: __repair();
    
    this->just_upgraded = true;
    
    this->__sendCreditsSpentMessage(WAVE_ENERGY_CONVERTER_BUILD_COST);
    this->__sendTileStateRequest();
    this->__sendGameStateRequest();
    
    return;
}   /* __repair() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: __computeCapacityFactors(void)
///
/// \brief Helper method to compute capacity factors
///

void WaveEnergyConverter :: __computeCapacityFactors(void)
{
    if (this->is_broken) {
        return;
    }
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    double mean =
        this->tile_resource_scalar * MEAN_DAILY_WAVE_CAPACITY_FACTORS[this->month - 1];
    
    double stdev = STDEV_DAILY_WAVE_CAPACITY_FACTORS[this->month - 1];
    
    if (this->tile_resource_scalar > 1) {
        stdev /= this->tile_resource_scalar;
    }

    std::normal_distribution<double> normal_dist(mean, stdev);
    
    double capacity_factor = 0;
    
    for (int i = 0; i < 30; i++) {
        capacity_factor = normal_dist(generator);
        
        if (capacity_factor < 0) {
            capacity_factor = 0;
        }
        
        this->capacity_factor_vec[i] = capacity_factor;
    }

    return;
}   /* __computeCapacityFactors() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: __computeProduction(void)
///
/// \brief Helper method to compute production values.
///

void WaveEnergyConverter :: __computeProduction(void)
{
    if (this->is_broken) {
        this->production_MWh = 0;
        return;
    }
    
    double production_MWh = 0;
    
    for (int i = 0; i < 30; i++) {
        this->production_vec_MWh[i] =
            this->max_daily_production_MWh * this->capacity_factor_vec[i];
        
        production_MWh += this->production_vec_MWh[i];
    }
    
    this->production_MWh = round(production_MWh);
    
    return;
}   /* __computeProduction() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: __computeDispatch(void)
///
/// \brief Helper method to compute dispatch values.
///

void WaveEnergyConverter :: __computeDispatch(void)
{
    if (this->is_broken) {
        this->dispatchable_MWh = 0;
        return;
    }
    
    double stored_energy_MWh = 0;
    double storage_capacity_MWh = (double)(this->storage_kWh) / 1000;
    
    double demand_MWh = 0;
    double production_MWh = 0;
    double dispatchable_MWh = 0;
    double difference_MWh = 0;
    
    double room_MWh = 0;
    
    for (int i = 0; i < 30; i++) {
        demand_MWh = this->demand_vec_MWh[i];
        production_MWh = this->production_vec_MWh[i];
        
        if (production_MWh <= demand_MWh) {
            this->dispatch_vec_MWh[i] = production_MWh;
            dispatchable_MWh += this->dispatch_vec_MWh[i];
            
            difference_MWh = demand_MWh - production_MWh;
            
            if ((storage_capacity_MWh > 0) and (stored_energy_MWh > 0)) {
                if (difference_MWh > stored_energy_MWh) {
                    this->dispatch_vec_MWh[i] += stored_energy_MWh;
                    dispatchable_MWh += stored_energy_MWh;
                    stored_energy_MWh = 0;
                }
                
                else {
                    this->dispatch_vec_MWh[i] += difference_MWh;
                    dispatchable_MWh += difference_MWh;
                    stored_energy_MWh -= difference_MWh;
                }
            }
        }
        
        else {
            this->dispatch_vec_MWh[i] = demand_MWh;
            dispatchable_MWh += this->dispatch_vec_MWh[i];
            
            difference_MWh = production_MWh - demand_MWh;
            
            if (
                (storage_capacity_MWh > 0) and
                (stored_energy_MWh < storage_capacity_MWh)
            ) {
                room_MWh = storage_capacity_MWh - stored_energy_MWh;
                
                if (difference_MWh > room_MWh) {
                    stored_energy_MWh += room_MWh;
                }
                
                else {
                    stored_energy_MWh += difference_MWh;
                }
            }
        }
    }
    
    this->dispatchable_MWh = round(dispatchable_MWh);
    
    if (this->dispatch_MWh != this->dispatchable_MWh) {
        this->dispatch_MWh = this->dispatchable_MWh;
    }
    
    return;
}   /* __computeDispatch() */

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
                this->dispatch_MWh++;
                
                if (this->dispatch_MWh > this->dispatchable_MWh) {
                    this->dispatch_MWh = 0;
                }
                
                this->__computeProductionCosts();
                this->assets_manager_ptr->getSound("interface click")->play();
            }
            
            else if (this->upgrade_menu_open) {
                this->__upgradePowerCapacity();
            }
            
            break;
        }
        
        
        case (sf::Keyboard::S): {
            if (this->production_menu_open) {
                this->dispatch_MWh--;
                
                if (this->dispatch_MWh < 0) {
                    this->dispatch_MWh = this->dispatchable_MWh;
                }
                
                this->__computeProductionCosts();
                this->assets_manager_ptr->getSound("interface click")->play();
            }
            
            break;
        }
        
        
        case (sf::Keyboard::D): {
            if (this->upgrade_menu_open) {
                this->__upgradeStorageCapacity();
                this->__computeProduction();
                this->__computeDispatch();
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



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: __sendImprovementStateMessage(void)
///
/// \brief Helper method to format and sent improvement state message.
///

void WaveEnergyConverter :: __sendImprovementStateMessage(void)
{
    Message improvement_state_message;
    
    improvement_state_message.channel = GAME_CHANNEL;
    improvement_state_message.subject = "improvement state";
    
    improvement_state_message.int_payload["dispatch_MWh"] = this->dispatch_MWh;
    improvement_state_message.int_payload["operation_maintenance_cost"] =
        this->operation_maintenance_cost;
    
    this->message_hub_ptr->sendMessage(improvement_state_message);
    
    std::cout << "Improvement state message sent by " << this << std::endl;
    
    return;
}   /* __sendImprovementStateMessage() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn WaveEnergyConverter :: WaveEnergyConverter(
///         double position_x,
///         double position_y,
///         int tile_resource,
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

WaveEnergyConverter :: WaveEnergyConverter(
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
    this->tile_improvement_type = TileImprovementType :: WAVE_ENERGY_CONVERTER;
    
    this->is_running = false;

    this->health = 100;
    
    this->capacity_kW = 100;
    this->upgrade_level = 1;
    
    this->storage_kWh = 0;
    this->storage_level = 0;
    
    this->production_MWh = 0;
    this->dispatch_MWh = 0;
    this->dispatchable_MWh = 0;
    
    this->max_daily_production_MWh = (double)(24 * this->capacity_kW) / 1000;
    
    this->bobbing_y = 4;
    
    this->capacity_factor_vec.resize(30, 0);
    this->production_vec_MWh.resize(30, 0);
    this->dispatch_vec_MWh.resize(30, 0);
    
    this->tile_improvement_string = "WAVE ENERGY";
    
    this->__setUpTileImprovementSpriteAnimated();
    this->__computeCapacityFactors();
    this->update();
    
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
    options_substring                           += " **** WAVE ENERGY OPTIONS ****  \n";
    options_substring                           += "                                \n";
    
    if (this->is_broken) {
        options_substring                       += "     [R]:  REPAIR (";
        options_substring                       += std::to_string(WAVE_ENERGY_CONVERTER_BUILD_COST);
        options_substring                       += " K)\n";
    }
    
    else {
        options_substring                       += "     [E]:  OPEN PRODUCTION MENU \n";
    }
    
    options_substring                           += "     [U]:  OPEN UPGRADE MENU    \n";
    options_substring                           += "HOLD [P]:  SCRAP (";
    options_substring                           += std::to_string(SCRAP_COST);
    options_substring                           += " K)";
    
    return options_substring;
}   /* getTileOptionsSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: setIsSelected(bool is_selected)
///
/// \brief Method to set the is selected attribute.
///
/// \param is_selected The value to set the is selected attribute to.
///

void WaveEnergyConverter :: setIsSelected(bool is_selected)
{
    TileImprovement :: setIsSelected(is_selected);
    
    if (this->is_running and this->is_selected) {
        this->assets_manager_ptr->getSound("ocean waves")->play();
    }
    
    return;
}   /* setIsSelected() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void WaveEnergyConverter :: advanceTurn(void)
///
/// \brief Method to handle turn advance.
///

void WaveEnergyConverter :: advanceTurn(void)
{
    //  1. send improvement state message
    this->__sendImprovementStateMessage();
    
    //  2. update
    this->__computeCapacityFactors();
    this->update();
    
    //  3. handle start/stop
    if ((not this->is_running) and (this->dispatch_MWh > 0)) {
        this->is_running = true;
    }
    
    else if (this->is_running and (this->dispatch_MWh <= 0)) {
        this->is_running = false;
    }
    
    //  4. handle equipment health and breakdowns
    if (this->is_running) {
        this->health--;
        
        if (this->health <= 50) {
            double breakdown_prob = (51 - this->health) * BREAKDOWN_PROBABILITY_INCREMENT;
            
            if ((double)rand() / RAND_MAX <= breakdown_prob) {
                this->health = 0;
            }
        }
        
        if (this->health <= 0) {
            this->__breakdown();
        }
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
/// \fn void WaveEnergyConverter :: update(void)
///
/// \brief Method to trigger production and dispatchable updates.
///

void WaveEnergyConverter :: update(void)
{
    this->__computeProduction();
    this->__computeProductionCosts();
    this->__computeDispatch();
    
    if (this->is_selected) {
        this->__sendTileStateRequest();
    }
    
    return;
}   /* update() */

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
        this->tile_improvement_sprite_animated[0].setPosition(
            this->position_x,
            this->position_y + this->bobbing_y * cos(
                (double)(0.4 * M_PI * this->frame) / FRAMES_PER_SECOND
            )
        );
        
        this->tile_improvement_sprite_animated[1].setPosition(
            this->position_x,
            this->position_y + 1.25 * this->bobbing_y * sin(
                (double)(0.4 * M_PI * this->frame) / FRAMES_PER_SECOND
            )
        );
    }
    
    else {
        for (size_t i = 0; i < this->tile_improvement_sprite_animated.size(); i++) {
            this->tile_improvement_sprite_animated[i].setPosition(
                this->position_x,
                this->position_y + this->bobbing_y * cos(
                    (double)(0.4 * M_PI * this->frame) / FRAMES_PER_SECOND
                )
            );
        }
    }
    
    this->render_window_ptr->draw(this->tile_improvement_sprite_animated[1]);
    
    
    //  5. draw storage upgrades
    for (size_t i = 0; i < this->storage_upgrade_sprite_vec.size(); i++) {
        this->render_window_ptr->draw(this->storage_upgrade_sprite_vec[i]);
    }
    
    
    //  6. handle dispatch illustration
    if (this->dispatch_MWh > 0) {
        this->dispatch_text.setString(std::to_string(this->dispatch_MWh));
        this->__drawDispatch();
    }
    
    
    //  7. draw production menu
    if (this->production_menu_open) {
        this->render_window_ptr->draw(this->production_menu_backing);
        this->render_window_ptr->draw(this->production_menu_backing_text);
        
        this->__drawProductionMenu();
    }
    
    
    //  8. draw upgrade menu
    if (this->upgrade_menu_open) {
        this->render_window_ptr->draw(this->upgrade_menu_backing);
        this->render_window_ptr->draw(this->upgrade_menu_backing_text);
        
        this->__drawUpgradeOptions();
    }
    
    
    //  9. handle broken effects
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
