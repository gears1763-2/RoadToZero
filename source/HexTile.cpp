/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the HexTile class.
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
/// \file HexTile.cpp
///
/// \brief Implementation file for the HexTile class.
///
/// A class which defines a tile of a hex map.
///


#include "../header/HexTile.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpNodeSprite(void)
///
/// \brief Helper method to set up node sprite.
///

void HexTile :: __setUpNodeSprite(void)
{
    this->node_sprite.setRadius(4);
    
    this->node_sprite.setOrigin(
        this->node_sprite.getLocalBounds().width / 2,
        this->node_sprite.getLocalBounds().height / 2
    );
    
    this->node_sprite.setPosition(this->position_x, this->position_y);
    
    this->node_sprite.setFillColor(sf::Color(255, 0, 0, 255));
    
    return;
}   /* __setUpNodeSprite() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpTileSprite(void)
///
/// \brief Helper method to set up tile sprite.
///

void HexTile :: __setUpTileSprite(void)
{
    int n_points = 6;
    
    this->tile_sprite.setPointCount(n_points);
    
    for (int i = 0; i < n_points; i++) {
        this->tile_sprite.setPoint(
            i,
            sf::Vector2f(
                this->position_x + this->major_radius * cos((30 + 60 * i) * (M_PI / 180)),
                this->position_y + this->major_radius * sin((30 + 60 * i) * (M_PI / 180))
            )
        );
    }
    
    this->tile_sprite.setOutlineThickness(1);
    this->tile_sprite.setOutlineColor(sf::Color(175, 175, 175, 255));
    
    return;
}   /* __setUpTileSprite() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpSelectOutlineSprite(void)
///
/// \brief Helper method to set up select outline sprite.
///

void HexTile :: __setUpSelectOutlineSprite(void)
{
    int n_points = 6;
    
    this->select_outline_sprite.setPointCount(n_points);
    
    for (int i = 0; i < n_points; i++) {
        this->select_outline_sprite.setPoint(
            i,
            sf::Vector2f(
                this->position_x + this->major_radius * cos((30 + 60 * i) * (M_PI / 180)),
                this->position_y + this->major_radius * sin((30 + 60 * i) * (M_PI / 180))
            )
        );
    }
    
    this->select_outline_sprite.setOutlineThickness(4);
    this->select_outline_sprite.setOutlineColor(MONOCHROME_TEXT_RED);
    
    this->select_outline_sprite.setFillColor(sf::Color(0, 0, 0, 0));
    
    return;
}   /* __setUpSelectOutline() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpResourceChipSprite(void)
///
/// \brief Helper method to set up resource chip sprite.
///

void HexTile :: __setUpResourceChipSprite(void)
{
    this->resource_chip_sprite.setRadius(2 * this->minor_radius / 3);
    
    this->resource_chip_sprite.setOrigin(
        this->resource_chip_sprite.getLocalBounds().width / 2,
        this->resource_chip_sprite.getLocalBounds().height / 2
    );
    
    this->resource_chip_sprite.setPosition(this->position_x, this->position_y);
    
    this->resource_chip_sprite.setFillColor(RESOURCE_CHIP_GREY);
    
    return;
}   /* __setUpResourceChip() */

// ---------------------------------------------------------------------------------- //


// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setResourceText(void)
///
/// \brief Helper method to set up resource text.
///

void HexTile :: __setResourceText(void)
{
    this->resource_text.setFont(*(assets_manager_ptr->getFont("DroidSansMono")));
    
    this->resource_text.setFillColor(sf::Color(0, 0, 0, 255));
    
    if (this->resource_assessed) {
        switch (this->tile_resource) {
            case (TileResource :: POOR): {
                this->resource_text.setString("-2");
                this->resource_text.setFillColor(MONOCHROME_TEXT_RED);
                
                break;
            }
            
            case (TileResource :: BELOW_AVERAGE): {
                this->resource_text.setString("-1");
                this->resource_text.setFillColor(MONOCHROME_TEXT_RED);
                
                break;
            }
            
            case (TileResource :: AVERAGE): {
                this->resource_text.setString("+0");
                
                break;
            }
            
            case (TileResource :: ABOVE_AVERAGE): {
                this->resource_text.setString("+1");
                this->resource_text.setFillColor(MONOCHROME_TEXT_GREEN);
                
                break;
            }
            
            case (TileResource :: GOOD): {
                this->resource_text.setString("+2");
                this->resource_text.setFillColor(MONOCHROME_TEXT_GREEN);
                
                break;
            }
            
            default: {
                this->resource_text.setString("");
                
                break;
            }
        }
    }
    
    else {
        this->resource_text.setString("");
    }
    
    this->resource_text.setCharacterSize(20);
    
    this->resource_text.setOrigin(
        this->resource_text.getLocalBounds().width / 2,
        this->resource_text.getLocalBounds().height / 2
    );
    
    this->resource_text.setPosition(
        this->position_x,
        this->position_y - 4
    );
    
    this->resource_text.setOutlineThickness(1);
    this->resource_text.setOutlineColor(sf::Color(0, 0, 0, 255));
    
    return;
}   /* __setResourceText() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpMagnifyingGlassSprite(void)
///
/// \brief Helper method to set up and position magnifying glass sprite.
///

void HexTile :: __setUpMagnifyingGlassSprite(void)
{
    this->magnifying_glass_sprite.setTexture(
        *(this->assets_manager_ptr->getTexture("magnifying_glass_64x64_1"))
    );
    
    this->magnifying_glass_sprite.setOrigin(
        this->magnifying_glass_sprite.getLocalBounds().width / 2,
        this->magnifying_glass_sprite.getLocalBounds().height / 2
    );
    
    this->magnifying_glass_sprite.setPosition(
        this->position_x,
        this->position_y
    );
    
    return;
}   /* __setUpMagnifyingGlassSprite() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpTileExplosionReel(void)
///
/// \brief Helper method to set up tile explosion sprite reel.
///

void HexTile :: __setUpTileExplosionReel(void)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->explosion_sprite_reel.push_back(
                sf::Sprite(
                    *(this->assets_manager_ptr->getTexture("tile clear explosion")),
                    sf::IntRect(j * 64, i * 64, 64, 64)
                )
            );
            
            this->explosion_sprite_reel.back().setOrigin(
                this->explosion_sprite_reel.back().getLocalBounds().width / 2,
                this->explosion_sprite_reel.back().getLocalBounds().height / 2
            );
            
            this->explosion_sprite_reel.back().setPosition(
                this->position_x,
                this->position_y
            );
        }
    }
    
    return;
}   /* __setUpTileExplosionReel() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpBuildOption(
///         std::string texture_key,
///         std::string option_string
///     )
///
/// \brief Helper method to set up and postion the sprite and text for a build option.
///
/// \param texture_key The key for the appropriate illustration asset for the build
///     option.
///
/// \param option_string A string for the build option.
///

void HexTile :: __setUpBuildOption(
    std::string texture_key,
    std::string option_string
)
{
    size_t n_options = this->build_menu_options_vec.size();
    
    //  1. set up option sprite(s)
    this->build_menu_options_vec.push_back({});
    
    if (not texture_key.empty()) {
        sf::Sprite texture_sheet(
            *(this->assets_manager_ptr->getTexture(texture_key))
        );
        
        int sheet_height = texture_sheet.getLocalBounds().height;
        int n_subrects = sheet_height / 64;
        
        for (int i = 0; i < n_subrects; i++) {
            this->build_menu_options_vec.back().push_back(
                sf::Sprite(
                    *(this->assets_manager_ptr->getTexture(texture_key)),
                    sf::IntRect(0, i * 64, 64, 64)
                )
            );
            
            this->build_menu_options_vec.back().back().setOrigin(
                this->build_menu_options_vec.back().back().getLocalBounds().width / 2,
                this->build_menu_options_vec.back().back().getLocalBounds().height
            );
            
            this->build_menu_options_vec.back().back().setPosition(
                400 - 300 + 75 + n_options * 150,
                400 - 32
            );
        }
    }
    
    else {
        this->build_menu_options_vec.back().push_back(sf::Sprite());
    }
    
    
    //  2. set up option text
    this->build_menu_options_text_vec.push_back(
        sf::Text(
            option_string,
            *(this->assets_manager_ptr->getFont("Glass_TTY_VT220")),
            16
        )
    );
    
    this->build_menu_options_text_vec.back().setOrigin(
        this->build_menu_options_text_vec.back().getLocalBounds().width / 2,
        0
    );
    
    this->build_menu_options_text_vec.back().setPosition(
        400 - 300 + 75 + n_options * 150,
        400 - 16 - 4
    );
    
    this->build_menu_options_text_vec.back().setFillColor(MONOCHROME_TEXT_GREEN);
    
    return;
}   /* __setUpBuildOption() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpDieselGeneratorBuildOption(void)
///
/// \brief Helper method to set up and position the diesel generator build option.
///

void HexTile :: __setUpDieselGeneratorBuildOption(void)
{
    //  1. set up option sprite(s)
    std::string texture_key = "diesel generator";
    
    //  2. set up option string (up to 16 chars wide)
    //                                    "----------------\n"
    std::string diesel_generator_string = "DIESEL GENERATOR\n";
    diesel_generator_string            += "                \n";
    diesel_generator_string            += "CAPACITY: 200 kW\n";
    diesel_generator_string            += "COST:     ";
    diesel_generator_string            += std::to_string(DIESEL_GENERATOR_BUILD_COST);
    diesel_generator_string            += " K\n\n\n";
    diesel_generator_string            += "BUILD:    [D]   \n";
    
    //  3. call general method
    this->__setUpBuildOption(texture_key, diesel_generator_string);
    
    return;
}   /* __setUpDieselGeneratorBuildOption() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpWindTurbineBuildOption(bool is_lake, bool is_ocean)
///
/// \brief Helper method to set up and position the wind turbine build option.
///
/// \param is_lake If being built on a lake tile.
///
/// \param is_ocean If being built on an ocean tile.
///

void HexTile :: __setUpWindTurbineBuildOption(bool is_lake, bool is_ocean)
{
    //  1. set up option sprite(s)
    std::string texture_key = "wind turbine";
    
    //  2. set up option string (up to 16 chars wide)
    int build_cost = WIND_TURBINE_BUILD_COST;
    if (is_lake or is_ocean) {
        build_cost *= WIND_TURBINE_WATER_BUILD_MULTIPLIER;
    }
    
    //                                    "----------------\n"
    std::string wind_turbine_string     = "  WIND TURBINE  \n";
    wind_turbine_string                += "                \n";
    wind_turbine_string                += "CAPACITY: 100 kW\n";
    wind_turbine_string                += "COST:     ";
    wind_turbine_string                += std::to_string(build_cost);
    wind_turbine_string                += " K";
    
    if (is_lake) {
        wind_turbine_string += "\n** LAKE BUILD **\n\n";
    }
    else if (is_ocean) {
        wind_turbine_string += "\n* OCEAN BUILD * \n\n";
    }
    else {
        wind_turbine_string += "\n\n\n";
    }
    
    wind_turbine_string                += "BUILD:    [W]   \n";
    
    //  3. call general method
    this->__setUpBuildOption(texture_key, wind_turbine_string);
    
    return;
}   /* __setUpWindTurbineBuildOption() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpSolarPVBuildOption(bool is_lake)
///
/// \brief Helper method to set up and position the solar PV array build option.
///
/// \param is_lake If being built on a lake.
///

void HexTile :: __setUpSolarPVBuildOption(bool is_lake)
{
    //  1. set up option sprite(s)
    std::string texture_key = "solar PV array";
    
    //  2. set up option string (up to 16 chars wide)
    int build_cost = SOLAR_PV_BUILD_COST;
    if (is_lake) {
        build_cost *= SOLAR_PV_WATER_BUILD_MULTIPLIER;
    }
    
    //                                    "----------------\n"
    std::string solar_PV_string         = " SOLAR PV ARRAY \n";
    solar_PV_string                    += "                \n";
    solar_PV_string                    += "CAPACITY: 100 kW\n";
    solar_PV_string                    += "COST:     ";
    solar_PV_string                    += std::to_string(build_cost);
    solar_PV_string                    += " K";
    
    if (is_lake) {
        solar_PV_string += "\n** LAKE BUILD **\n\n";
    }
    else {
        solar_PV_string += "\n\n\n";
    }
    
    solar_PV_string                    += "BUILD:    [S]   \n";
    
    //  3. call general method
    this->__setUpBuildOption(texture_key, solar_PV_string);
    
    return;
}   /* __setUpSolarPVBuildOption() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpTidalTurbineBuildOption(void)
///
/// \brief Helper method to set up and position the tidal turbine build option.
///

void HexTile :: __setUpTidalTurbineBuildOption(void)
{
    //  1. set up option sprite(s)
    std::string texture_key = "tidal turbine";
    
    //  2. set up option string (up to 16 chars wide)
    //                                    "----------------\n"
    std::string tidal_turbine_string    = " TIDAL TURBINE  \n";
    tidal_turbine_string               += "                \n";
    tidal_turbine_string               += "CAPACITY: 100 kW\n";
    tidal_turbine_string               += "COST:     ";
    tidal_turbine_string               += std::to_string(TIDAL_TURBINE_BUILD_COST);
    tidal_turbine_string               += " K\n\n\n";
    tidal_turbine_string               += "BUILD:    [T]   \n";
    
    //  3. call general method
    this->__setUpBuildOption(texture_key, tidal_turbine_string);
    
    return;
}   /* __setUpTidalTurbineBuildOption() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpWaveEnergyConverterBuildOption(void)
///
/// \brief Helper method to set up and position the wave energy converter build option.
///

void HexTile :: __setUpWaveEnergyConverterBuildOption(void)
{
    //  1. set up option sprite(s)
    std::string texture_key = "wave energy converter";
    
    //  2. set up option string (up to 16 chars wide)
    //                                            "----------------\n"
    std::string wave_energy_converter_string    = "WAVE ENERGY CVTR\n";
    wave_energy_converter_string               += "                \n";
    wave_energy_converter_string               += "CAPACITY: 100 kW\n";
    wave_energy_converter_string               += "COST:     ";
    wave_energy_converter_string               += std::to_string(WAVE_ENERGY_CONVERTER_BUILD_COST);
    wave_energy_converter_string               += " K\n\n\n";
    wave_energy_converter_string               += "BUILD:    [A]   \n";
    
    //  3. call general method
    this->__setUpBuildOption(texture_key, wave_energy_converter_string);
    
    return;
}   /* __setUpWaveEnergyConverterBuildOption() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpEnergyStorageSystemBuildOption(void)
///
/// \brief Helper method to set up and position the wave energy converter build option.
///

void HexTile :: __setUpEnergyStorageSystemBuildOption(void)
{
    /*
    //  1. set up option sprite(s)
    std::string texture_key = "energy storage system";
    
    //  2. set up option string (up to 16 chars wide)
    //                                            "----------------\n"
    std::string energy_storage_system_string    = " ENERGY STORAGE \n";
    energy_storage_system_string               += "                \n";
    energy_storage_system_string               += "CAPCTY:   1 MWh\n";
    energy_storage_system_string               += "COST:     ";
    energy_storage_system_string               += std::to_string(ENERGY_STORAGE_SYSTEM_BUILD_COST);
    energy_storage_system_string               += " K\n\n\n";
    energy_storage_system_string               += "BUILD:    [E]   \n";
    
    //  3. call general method
    this->__setUpBuildOption(texture_key, energy_storage_system_string);
    */
    return;
}   /* __setUpEnergyStorageSystemBuildOption() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpBuildMenu(void)
///
/// \brief Helper method to set up and place build menu assets (drawable).
///

void HexTile :: __setUpBuildMenu(void)
{
    this->build_menu_options_vec.clear();
    this->build_menu_options_text_vec.clear();
    
    //  1. set up and place build menu backing and text
    this->build_menu_backing.setSize(sf::Vector2f(600, 256));
    this->build_menu_backing.setOrigin(300, 128);
    this->build_menu_backing.setPosition(400, 400);
    this->build_menu_backing.setFillColor(MONOCHROME_SCREEN_BACKGROUND);
    this->build_menu_backing.setOutlineColor(MENU_FRAME_GREY);
    this->build_menu_backing.setOutlineThickness(4);
    
    this->build_menu_backing_text.setString("**** BUILD MENU ****");
    this->build_menu_backing_text.setFont(
        *(this->assets_manager_ptr->getFont("Glass_TTY_VT220"))
    );
    this->build_menu_backing_text.setCharacterSize(16);
    this->build_menu_backing_text.setFillColor(MONOCHROME_TEXT_GREEN);
    this->build_menu_backing_text.setOrigin(
        this->build_menu_backing_text.getLocalBounds().width / 2, 0
    );
    this->build_menu_backing_text.setPosition(400, 400 - 128 + 4);
    
    //  2. set up and place build menu option sprites and text
    switch (this->tile_type) {
        case (TileType :: FOREST): {
            this->__setUpDieselGeneratorBuildOption();
            this->__setUpSolarPVBuildOption();
            this->__setUpWindTurbineBuildOption();
            //this->__setUpEnergyStorageSystemBuildOption();
            
            break;
        }
        
        
        case (TileType :: LAKE): {
            this->__setUpSolarPVBuildOption(true);
            this->__setUpWindTurbineBuildOption(true);
            
            break;
        }
        
        
        case (TileType :: MOUNTAINS): {
            this->__setUpDieselGeneratorBuildOption();
            this->__setUpSolarPVBuildOption();
            this->__setUpWindTurbineBuildOption();
            //this->__setUpEnergyStorageSystemBuildOption();
            
            break;
        }
        
        
        case (TileType :: OCEAN): {
            this->__setUpWindTurbineBuildOption(false, true);
            this->__setUpTidalTurbineBuildOption();
            this->__setUpWaveEnergyConverterBuildOption();
            
            break;
        }
        
        
        case (TileType :: PLAINS): {
            this->__setUpDieselGeneratorBuildOption();
            this->__setUpSolarPVBuildOption();
            this->__setUpWindTurbineBuildOption();
            //this->__setUpEnergyStorageSystemBuildOption();
            
            break;
        }
        
        
        default: {
            // do nothing!
            
            break;
        }
    }
    
    return;
}   /* __setUpBuildMenu() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setIsSelected(bool is_selected)
///
/// \brief Helper method to set the is selected attribute (of tile and improvement).
///
/// \param is_selected The value to set the is selected attribute to.
///

void HexTile :: __setIsSelected(bool is_selected)
{
    this->is_selected = is_selected;
    
    if (this->tile_improvement_ptr != NULL) {
        this->tile_improvement_ptr->setIsSelected(is_selected);
    }
    
    if ((not is_selected) and this->build_menu_open) {
        this->__closeBuildMenu();
    }
    
    return;
}   /* __setIsSelected() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __clearDecoration(void)
///
/// \brief Helper method to clear tile decoration.
///

void HexTile :: __clearDecoration(void)
{
    this->decoration_cleared = true;
    this->draw_explosion = true;
    
    switch (this->tile_type) {
        case (TileType :: FOREST): {
            this->assets_manager_ptr->getSound("clear non-mountains tile")->play();
            
            break;
        }
        
        
        case (TileType :: MOUNTAINS): {
            this->assets_manager_ptr->getSound("clear mountains tile")->play();
            
            break;
        }
        
        
        case (TileType :: PLAINS): {
            this->assets_manager_ptr->getSound("clear non-mountains tile")->play();
            
            break;
        }
        
        
        default: {
            // do nothing!
            
            break;
        }
    }
    
    return;
}   /* __clearDecoration() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn bool HexTile :: __isClicked(void)
///
/// \brief Helper method to determine if tile was clicked on.
///
/// \return Boolean indicating whether or not tile was clicked on.
///

bool HexTile :: __isClicked(void)
{
    sf::Vector2i mouse_position = sf::Mouse::getPosition(*render_window_ptr);
        
    double mouse_x = mouse_position.x;
    double mouse_y = mouse_position.y;
    
    double distance = sqrt(
        pow(this->position_x - mouse_x, 2) +
        pow(this->position_y - mouse_y, 2)
    );
    
    if (distance < this->minor_radius) {
        return true;
    }
    else {
        return false;
    }
}   /* __isClicked() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __handleKeyPressEvents(void)
///
/// \brief Helper method to handle key press events.
///

void HexTile :: __handleKeyPressEvents(void)
{
    if (not this->is_selected) {
        return;
    }
    
    
    if (this->event_ptr->key.code == sf::Keyboard::Escape) {
        this->__setIsSelected(false);
    }
    
    
    if (this->build_menu_open) {
        switch (this->tile_type) {
            case (TileType :: FOREST): {
                switch (this->event_ptr->key.code) {
                    case (sf::Keyboard::D): {
                        this->__buildDieselGenerator();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::S): {
                        this->__buildSolarPV();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::W): {
                        this->__buildWindTurbine();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::E): {
                        this->__buildEnergyStorage();
                        
                        break;
                    }
                    
                    
                    default: {
                        // do nothing!
                        
                        break;
                    }
                }
                
                break;
            }
            
            
            case (TileType :: LAKE): {
                switch (this->event_ptr->key.code) {
                    case (sf::Keyboard::S): {
                        this->__buildSolarPV();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::W): {
                        this->__buildWindTurbine();
                        
                        break;
                    }
                    
                    
                    default: {
                        // do nothing!
                        
                        break;
                    }
                }
                
                break;
            }
            
            
            case (TileType :: MOUNTAINS): {
                switch (this->event_ptr->key.code) {
                    case (sf::Keyboard::D): {
                        this->__buildDieselGenerator();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::S): {
                        this->__buildSolarPV();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::W): {
                        this->__buildWindTurbine();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::E): {
                        this->__buildEnergyStorage();
                        
                        break;
                    }
                    
                    
                    default: {
                        // do nothing!
                        
                        break;
                    }
                }
                
                break;
            }
            
            
            case (TileType :: OCEAN): {
                switch (this->event_ptr->key.code) {
                    case (sf::Keyboard::W): {
                        this->__buildWindTurbine();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::T): {
                        this->__buildTidalTurbine();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::A): {
                        this->__buildWaveEnergyConverter();
                        
                        break;
                    }
                    
                    
                    default: {
                        // do nothing!
                        
                        break;
                    }
                }
                
                break;
            }
            
            
            case (TileType :: PLAINS): {
                switch (this->event_ptr->key.code) {
                    case (sf::Keyboard::D): {
                        this->__buildDieselGenerator();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::S): {
                        this->__buildSolarPV();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::W): {
                        this->__buildWindTurbine();
                        
                        break;
                    }
                    
                    
                    case (sf::Keyboard::E): {
                        this->__buildEnergyStorage();
                        
                        break;
                    }
                    
                    
                    default: {
                        // do nothing!
                        
                        break;
                    }
                }
                
                break;
            }
            
            
            default: {
                //do nothing!
                
                break;
            }
        }
    }
    
    
    if (this->game_phase == "build settlement") {
        if (
            (this->tile_type != TileType :: OCEAN) and
            (this->tile_type != TileType :: LAKE)
        ) {
            if (this->event_ptr->key.code == sf::Keyboard::B) {
                this->__buildSettlement();
            }
        }
    }
    
    
    else if (this->game_phase == "system management") {
        if (this->has_improvement) {
            if (this->tile_improvement_ptr->tile_improvement_type != TileImprovementType :: SETTLEMENT) {
                if (this->event_ptr->key.code == sf::Keyboard::P) {
                    this->__scrapImprovement();
                }
            }
            
            /*
             * All other inputs will be caught and handled by
             *   this->tile_improvement_ptr->processEvent()
             */
        }
        
        
        else if (not this->resource_assessed) {
            if (this->event_ptr->key.code == sf::Keyboard::A) {
                if (this->credits < RESOURCE_ASSESSMENT_COST) {
                    std::cout << "Cannot assess resource: insufficient credits (need "
                        << RESOURCE_ASSESSMENT_COST << " K)" << std::endl;
                        
                    this->__sendInsufficientCreditsMessage();
                }
                
                else {
                    this->assess();
                    this->__sendCreditsSpentMessage(RESOURCE_ASSESSMENT_COST);
                    this->__sendTileStateMessage();
                    this->__sendGameStateRequest();
                }
            }
        }
        
        
        else if (
            (not this->decoration_cleared) and
            (this->tile_type != TileType :: OCEAN) and
            (this->tile_type != TileType :: LAKE)
        ) {
            if (this->event_ptr->key.code == sf::Keyboard::C) {
                int clear_cost = 0;
                
                switch (this->tile_type) {
                    case (TileType :: FOREST): {
                        clear_cost = CLEAR_FOREST_COST;
                        
                        break;
                    }
                    
                    
                    case (TileType :: MOUNTAINS): {
                        clear_cost = CLEAR_MOUNTAINS_COST;
                        
                        break;
                    }
                    
                    
                    case (TileType :: PLAINS): {
                        clear_cost = CLEAR_PLAINS_COST;
                        
                        break;
                    }
                    
                    
                    default: {
                        // do nothing!
                        
                        break;
                    }
                }
                
                if (this->credits < clear_cost) {
                    std::cout << "Cannot clear tile: insufficient credits (need "
                        << clear_cost << " K)" << std::endl;
                        
                    this->__sendInsufficientCreditsMessage();
                }
                
                else {
                    this->__clearDecoration();
                    this->__sendCreditsSpentMessage(clear_cost);
                    this->__sendTileStateMessage();
                    this->__sendGameStateRequest();
                }
            }
        }
        
        
        else if (
            (this->decoration_cleared) or
            (this->tile_type == TileType :: OCEAN) or
            (this->tile_type == TileType :: LAKE)
        ) {
            if (this->event_ptr->key.code == sf::Keyboard::B) {
                this->__openBuildMenu();
            }
        }
    }

    return;
}   /* __handleKeyPressEvents() */

// ---------------------------------------------------------------------------------- //


void HexTile :: __handleKeyReleaseEvents(void)
{
    if (not this->is_selected) {
        return;
    }
    
    
    switch (this->event_ptr->key.code) {
        case (sf::Keyboard::P): {
            if (this->has_improvement) {
                this->scrap_improvement_frame = 0;

                if (
                    this->tile_improvement_ptr->tile_improvement_sprite_static.getTexture() != NULL
                ) {
                    this->tile_improvement_ptr->tile_improvement_sprite_static.setColor(
                        sf::Color(255, 255, 255, 255)
                    );
                }

                else {
                    for (
                        size_t i = 0;
                        i < this->tile_improvement_ptr->tile_improvement_sprite_animated.size();
                        i++
                    ) {
                        this->tile_improvement_ptr->tile_improvement_sprite_animated[i].setColor(
                            sf::Color(255, 255, 255, 255)
                        );
                    }
                }
            }
            
            
            break;
        }
        
        
        default: {
            // do nothing!
            
            break;
        }
    }
    
    /*
    if (this->event_ptr->key.code == sf::Keyboard::P) {
        
    }
    */
    
    return;
}   /* __handleKeyReleaseEvents() */



// ---------------------------------------------------------------------------------- //

///
/// \fn HexTile :: __handleMouseButtonEvents(void)
///
/// \brief Helper method to handle mouse button events.
///

void HexTile :: __handleMouseButtonEvents(void)
{
    switch (this->event_ptr->mouseButton.button) {
        case (sf::Mouse::Left): {
            if (this->__isClicked()) {
                std::cout << "Tile (" << this->position_x << ", " <<
                    this->position_y << ") was selected" << std::endl;
                
                this->__setIsSelected(true);
                
                this->__sendTileSelectedMessage();
                this->__sendTileStateMessage();
            }
            
            else {
                this->__setIsSelected(false);
            }
            
            break;
        }
        
        
        case (sf::Mouse::Right): {
            this->__setIsSelected(false);
            
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
/// \fn void HexTile :: __openBuildMenu(void)
///
/// \brief Helper method to open the tile improvement build menu.
///

void HexTile :: __openBuildMenu(void)
{
    if (this->build_menu_open) {
        return;
    }
    
    this->build_menu_open = true;
    this->assets_manager_ptr->getSound("build menu open")->play();
    
    return;
}   /* __openBuildMenu() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __closeBuildMenu(void)
///
/// \brief Helper method to close the tile improvement build menu.
///

void HexTile :: __closeBuildMenu(void)
{
    if (not this->build_menu_open) {
        return;
    }
    
    this->build_menu_open = false;
    this->assets_manager_ptr->getSound("build menu close")->play();
    
    return;
}   /* __closeBuildMenu() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
///
/// \fn void HexTile :: __buildSettlement(void)
///
/// \brief Helper method to build a settlement on this tile.
///

void HexTile :: __buildSettlement(void)
{
    if (this->credits < BUILD_SETTLEMENT_COST) {
        std::cout << "Cannot build settlement: insufficient credits (need "
            << BUILD_SETTLEMENT_COST << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
                
    this->__clearDecoration();
                
    this->tile_improvement_ptr = new Settlement(
        this->position_x,
        this->position_y,
        this->tile_resource,
        this->event_ptr,
        this->render_window_ptr,
        this->assets_manager_ptr,
        this->message_hub_ptr
    );
    
    this->has_improvement = true;
    
    this->assess();
    this->__sendAssessNeighboursMessage();
    
    this->__sendUpdateGamePhaseMessage("system management");
    this->__sendCreditsSpentMessage(BUILD_SETTLEMENT_COST);
    this->__sendTileStateMessage();
    this->__sendGameStateRequest();
    
    return;
}   /* __buildSettlement() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __buildDieselGenerator(void)
///
/// \brief Helper method to build a diesel generator on this tile.
///

void HexTile :: __buildDieselGenerator(void)
{
    int build_cost = DIESEL_GENERATOR_BUILD_COST;
    
    if (this->credits < build_cost) {
        std::cout << "Cannot build diesel generator: insufficient credits (need "
            << build_cost << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
    
    this->tile_improvement_ptr = new DieselGenerator(
        this->position_x,
        this->position_y,
        this->tile_resource,
        this->event_ptr,
        this->render_window_ptr,
        this->assets_manager_ptr,
        this->message_hub_ptr
    );
    
    this->has_improvement = true;
    this->__closeBuildMenu();
    
    if (not this->resource_assessed) {
        this->assess();
    }
    
    this->__sendCreditsSpentMessage(build_cost);
    this->__sendTileStateMessage();
    this->__sendGameStateRequest();
    
    return;
}   /* __buildDieselGenerator() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __buildSolarPV(void)
///
/// \brief Helper method to build a solar PV array on this tile.
///

void HexTile :: __buildSolarPV(void)
{
    int build_cost = SOLAR_PV_BUILD_COST;
    
    if (this->tile_type == TileType :: LAKE) {
        build_cost *= SOLAR_PV_WATER_BUILD_MULTIPLIER;
    }
    
    if (this->credits < build_cost) {
        std::cout << "Cannot build solar PV array: insufficient credits (need "
            << build_cost << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
    
    this->tile_improvement_ptr = new SolarPV(
        this->position_x,
        this->position_y,
        this->tile_resource,
        this->event_ptr,
        this->render_window_ptr,
        this->assets_manager_ptr,
        this->message_hub_ptr
    );
    
    this->has_improvement = true;
    this->__closeBuildMenu();
    
    if (not this->resource_assessed) {
        this->assess();
    }
    
    if (this->tile_type == TileType :: LAKE) {
        this->decoration_cleared = true;
        this->assets_manager_ptr->getSound("splash")->play();
    }
    
    this->__sendCreditsSpentMessage(build_cost);
    this->__sendTileStateMessage();
    this->__sendGameStateRequest();
    
    return;
}   /* __buildSolarPV() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __buildWindTurbine(void)
///
/// \brief Helper method to build a wind turbine on this tile.
///

void HexTile :: __buildWindTurbine(void)
{
    int build_cost = WIND_TURBINE_BUILD_COST;
    
    if (
        (this->tile_type == TileType :: LAKE) or
        (this->tile_type == TileType :: OCEAN)
    ) {
        build_cost *= WIND_TURBINE_WATER_BUILD_MULTIPLIER;
    }
    
    if (this->credits < build_cost) {
        std::cout << "Cannot build wind turbine: insufficient credits (need "
            << build_cost << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
    
    this->tile_improvement_ptr = new WindTurbine(
        this->position_x,
        this->position_y,
        this->tile_resource,
        this->event_ptr,
        this->render_window_ptr,
        this->assets_manager_ptr,
        this->message_hub_ptr
    );
    
    this->has_improvement = true;
    this->__closeBuildMenu();
    
    if (not this->resource_assessed) {
        this->assess();
    }
    
    if (
        (this->tile_type == TileType :: LAKE) or
        (this->tile_type == TileType :: OCEAN)
    ) {
        this->decoration_cleared = true;
        this->assets_manager_ptr->getSound("splash")->play();
    }
    
    this->__sendCreditsSpentMessage(build_cost);
    this->__sendTileStateMessage();
    this->__sendGameStateRequest();
    
    return;
}   /* __buildWindTurbine() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __buildTidalTurbine(void)
///
/// \brief Helper method to build a tidal turbine on this tile.
///

void HexTile :: __buildTidalTurbine(void)
{
    int build_cost = TIDAL_TURBINE_BUILD_COST;
    
    if (this->credits < build_cost) {
        std::cout << "Cannot build tidal turbine: insufficient credits (need "
            << build_cost << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
    
    this->tile_improvement_ptr = new TidalTurbine(
        this->position_x,
        this->position_y,
        this->tile_resource,
        this->event_ptr,
        this->render_window_ptr,
        this->assets_manager_ptr,
        this->message_hub_ptr
    );
    
    this->has_improvement = true;
    this->decoration_cleared = true;
    this->assets_manager_ptr->getSound("splash")->play();
    this->__closeBuildMenu();
    
    if (not this->resource_assessed) {
        this->assess();
    }
    
    this->__sendCreditsSpentMessage(build_cost);
    this->__sendTileStateMessage();
    this->__sendGameStateRequest();
    
    return;
}   /* __buildTidalTurbine() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __buildWaveEnergyConverter(void)
///
/// \brief Helper method to build a wave energy converter on this tile.
///

void HexTile :: __buildWaveEnergyConverter(void)
{
    int build_cost = WAVE_ENERGY_CONVERTER_BUILD_COST;
    
    if (this->credits < build_cost) {
        std::cout << "Cannot build wave energy converter: insufficient credits (need "
            << build_cost << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
    
    this->tile_improvement_ptr = new WaveEnergyConverter(
        this->position_x,
        this->position_y,
        this->tile_resource,
        this->event_ptr,
        this->render_window_ptr,
        this->assets_manager_ptr,
        this->message_hub_ptr
    );
    
    this->has_improvement = true;
    this->decoration_cleared = true;
    this->assets_manager_ptr->getSound("splash")->play();
    this->__closeBuildMenu();
    
    if (not this->resource_assessed) {
        this->assess();
    }
    
    this->__sendCreditsSpentMessage(build_cost);
    this->__sendTileStateMessage();
    this->__sendGameStateRequest();
    
    return;
}   /* __buildWaveEnergyConverter() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __buildEnergyStorage(void)
///
/// \brief Helper method to build an energy storage system on this tile. DEPRECATED.
///

void HexTile :: __buildEnergyStorage(void)
{
    /*
    int build_cost = ENERGY_STORAGE_SYSTEM_BUILD_COST;
    
    if (this->credits < build_cost) {
        std::cout << "Cannot build energy storage system: insufficient credits (need "
            << build_cost << " K)" << std::endl;
            
        this->__sendInsufficientCreditsMessage();
        return;
    }
    
    this->tile_improvement_ptr = new EnergyStorageSystem(
        this->position_x,
        this->position_y,
        this->event_ptr,
        this->render_window_ptr,
        this->assets_manager_ptr,
        this->message_hub_ptr
    );
    
    this->has_improvement = true;
    this->__closeBuildMenu();

    if (not this->resource_assessed) {
        this->assess();
    }
    
    this->__sendCreditsSpentMessage(build_cost);
    this->__sendTileStateMessage();
    this->__sendGameStateRequest();
    */
    return;
}   /* __buildEnergyStorage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __scrapImprovement(void)
///
/// \brief Helper method to scrap the tile improvement (Settlement cannot be scrapped).
///     Requires the mapped key to be held continuously to confirm.
///

void HexTile :: __scrapImprovement(void)
{
    //  1. implement key hold confirmation
    if (this->scrap_improvement_frame <= FRAMES_PER_SECOND) {
        double colour_scalar =
            1 - ((double)(this->scrap_improvement_frame) / (FRAMES_PER_SECOND));
        
        if (
            this->tile_improvement_ptr->tile_improvement_sprite_static.getTexture() != NULL
        ) {
            this->tile_improvement_ptr->tile_improvement_sprite_static.setColor(
                sf::Color(255, 255 * colour_scalar, 255 * colour_scalar, 255)
            );
        }
        
        else {
            for (
                size_t i = 0;
                i < this->tile_improvement_ptr->tile_improvement_sprite_animated.size();
                i++
            ) {
                this->tile_improvement_ptr->tile_improvement_sprite_animated[i].setColor(
                    sf::Color(255, 255 * colour_scalar, 255 * colour_scalar, 255)
                );
            }
        }
        
        this->scrap_improvement_frame += 4;
    }
    
    
    //  2. carry out scrapping
    else {
        this->draw_explosion = true;
        this->assets_manager_ptr->getSound("clear non-mountains tile")->play();
        
        if (this->tile_improvement_ptr->production_menu_open) {
            this->tile_improvement_ptr->production_menu_open = false;
            this->assets_manager_ptr->getSound("build menu close")->play();
        }
        
        delete this->tile_improvement_ptr;
        this->tile_improvement_ptr = NULL;
        
        this->has_improvement = false;
        
        this->scrap_improvement_frame = 0;
        
        if (
            (this->tile_type == TileType :: LAKE) or
            (this->tile_type == TileType :: OCEAN)
        ) {
            this->decoration_cleared = false;
        }
        
        this->__sendCreditsSpentMessage(SCRAP_COST);
        this->__sendTileStateMessage();
        this->__sendGameStateRequest();
    }
    
    return;
}   /* __scrapImprovement() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __sendTileSelectedMessage(void)
///
/// \brief Helper method to format and send message on tile selection.
///

void HexTile :: __sendTileSelectedMessage(void)
{
    Message tile_selected_message;
    
    tile_selected_message.channel = TILE_SELECTED_CHANNEL;
    tile_selected_message.subject = "tile selected";
    
    this->message_hub_ptr->sendMessage(tile_selected_message);
    
    return;
}   /* __sendTileSelectedMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string HexTile :: __getTileCoordsSubstring(void)
///
/// \brief Helper method to assemble and return tile coordinates substring.
///
/// \return Tile coordinates substring.
///

std::string HexTile :: __getTileCoordsSubstring(void)
{
    std::string coords_substring = "TILE COORDS:  (";
    coords_substring += std::to_string(int(this->position_x - 400));
    coords_substring += ", ";
    coords_substring += std::to_string(int(this->position_y - 400));
    coords_substring += ")\n";
    
    return coords_substring;
}   /* __getTileCoordsSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string HexTile :: __getTileTypeSubstring(void)
///
/// \brief Helper method to assemble and return tile type substring.
///
/// \return Tile type substring.
///

std::string HexTile :: __getTileTypeSubstring(void)
{
    std::string type_substring = "TILE TYPE:         ";
    
    switch (this->tile_type) {
        case (TileType :: FOREST): {
            type_substring += "FOREST\n";
            
            break;
        }
        
        
        case (TileType :: LAKE): {
            type_substring += "LAKE\n";
            
            break;
        }
        
        
        case (TileType :: MOUNTAINS): {
            type_substring += "MOUNTAINS\n";
            
            break;
        }
        
        
        case (TileType :: OCEAN): {
            type_substring += "OCEAN\n";
            
            break;
        }
        
        
        case (TileType :: PLAINS): {
            type_substring += "PLAINS\n";
            
            break;
        }
        
        
        default: {
            type_substring += "???\n";
            
            break;
        }
    }
    
    return type_substring;
}   /* __getTileTypeSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string HexTile :: __getTileResourceSubstring(void)
///
/// \brief Helper method to assemble and return tile resource substring.
///
/// \return Tile resource substring.
///

std::string HexTile :: __getTileResourceSubstring(void)
{
    std::string resource_substring = "TILE RESOURCE:     ";
    
    if (this->resource_assessed) {
        switch (this->tile_resource) {
            case (TileResource :: POOR): {
                resource_substring += "POOR\n";
                
                break;
            }
            
            
            case (TileResource ::BELOW_AVERAGE): {
                resource_substring += "BELOW AVERAGE\n";
                
                break;
            }
            
            
            case (TileResource :: AVERAGE): {
                resource_substring += "AVERAGE\n";
                
                break;
            }
            
            
            case (TileResource :: ABOVE_AVERAGE): {
                resource_substring += "ABOVE AVERAGE\n";
                
                break;
            }
            
            
            case (TileResource :: GOOD): {
                resource_substring += "GOOD\n";
                
                break;
            }
            
            
            default: {
                resource_substring += "???\n";
                
                break;
            }
        }
    }
    
    else {
        resource_substring += "???\n";
    }
    
    return resource_substring;
}   /* __getTileResourceSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string HexTile :: __getTileImprovementSubstring(void)
///
/// \brief Helper method to assemble and return the tile improvement substring.
///
/// \return Tile improvement substring.
///

std::string HexTile :: __getTileImprovementSubstring(void)
{
    std::string improvement_substring = "TILE IMPROVEMENT:  ";
    
    if (this->has_improvement) {
        improvement_substring += this->tile_improvement_ptr->tile_improvement_string;
        improvement_substring += "\n";
    }
    
    else {
        improvement_substring += "NONE\n";
    }
    
    return improvement_substring;
}   /* __getTileImprovementSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string HexTile :: __getTileOptionsSubstring(void)
///
/// \brief Helper method to assemble and return tile options substring.
///
/// \return Tile options substring.
///

std::string HexTile :: __getTileOptionsSubstring(void)
{
    //                   32 char x 17 line console "--------------------------------\n";
    std::string options_substring                = "     **** TILE OPTIONS ****     \n";
    options_substring                           += "                                \n";
    
    if (this->game_phase == "build settlement") {
        if (
            (this->tile_type != TileType :: OCEAN) and
            (this->tile_type != TileType :: LAKE)
        ) {
            options_substring += "[B]:  BUILD SETTLEMENT (";
            options_substring += std::to_string(BUILD_SETTLEMENT_COST);
            options_substring += " K)\n";
        }
    }
    
    
    else if (this->game_phase == "system management") {
        if (this->has_improvement) {
            options_substring.clear();
            options_substring = this->tile_improvement_ptr->getTileOptionsSubstring();
        }
        
        
        else if (not this->resource_assessed) {
            options_substring += "[A]:  ASSESS RESOURCE (";
            options_substring += std::to_string(RESOURCE_ASSESSMENT_COST);
            options_substring += " K)\n";
        }
        
        
        else if (
            (not this->decoration_cleared) and
            (this->tile_type != TileType :: OCEAN) and
            (this->tile_type != TileType :: LAKE)
        ) {
            options_substring += "[C]:  CLEAR TILE (";
            
            switch (this->tile_type) {
                case (TileType :: FOREST): {
                    options_substring += std::to_string(CLEAR_FOREST_COST);
                    
                    break;
                }
                
                
                case (TileType :: MOUNTAINS): {
                    options_substring += std::to_string(CLEAR_MOUNTAINS_COST);
                    
                    break;
                }
                
                
                case (TileType :: PLAINS): {
                    options_substring += std::to_string(CLEAR_PLAINS_COST);
                    
                    break;
                }
                
                
                default: {
                    //do nothing!
                    
                    break;
                }
            }
            
            options_substring += " K)\n";
        }
        
        
        else if (
            (this->decoration_cleared) or
            (this->tile_type == TileType :: OCEAN) or
            (this->tile_type == TileType :: LAKE)
        ) {
            options_substring += "[B]: OPEN BUILD MENU\n";
        }
    }
    
    
    else if (this->game_phase == "victory") {
        options_substring                       += "       **** VICTORY ****        \n";
    }
    
    
    else {
        options_substring                       += "        **** LOSS ****          \n";
    }
    
    return options_substring;
}   /* __getTileOptionsString() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __sendTileStateMessage(void)
///
/// \brief Helper method to format and send tile state message.
///

void HexTile :: __sendTileStateMessage(void)
{
    Message tile_state_message;
    
    tile_state_message.channel = TILE_STATE_CHANNEL;
    tile_state_message.subject = "tile state";
    
    
    //                   32 char x 17 line console "--------------------------------\n";
    std::string console_string                   = "      **** TILE INFO ****       \n";
    
    console_string                              += this->__getTileCoordsSubstring();
    console_string                              += "                                \n";
    
    console_string                              += this->__getTileTypeSubstring();
    console_string                              += this->__getTileResourceSubstring();
    console_string                              += this->__getTileImprovementSubstring();
    console_string                              += "                                \n";

    console_string                              += this->__getTileOptionsSubstring();
    
    tile_state_message.string_payload["console string"] = console_string;
    
    this->message_hub_ptr->sendMessage(tile_state_message);
    
    std::cout << "Tile state message sent by " << this << std::endl;
    return;
}   /* __sendTileStateMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __sendAssessNeighboursMessage(void)
///
/// \brief Helper method to format and send assess neighbours message.
///

void HexTile :: __sendAssessNeighboursMessage(void)
{
    Message assess_neighbours_message;
    
    assess_neighbours_message.channel = HEX_MAP_CHANNEL;
    assess_neighbours_message.subject = "assess neighbours";
    
    this->message_hub_ptr->sendMessage(assess_neighbours_message);
    
    std::cout << "Assess neighbours message sent by " << this << std::endl;
    
    return;
}   /* __sendAssessNeighboursMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __sendGameStateRequest(void)
///
/// \brief Helper method to format and send a game state request (message).
///

void HexTile :: __sendGameStateRequest(void)
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
/// \fn void HexTile :: __sendUpdateGamePhaseMessage(void)
///
/// \brief Helper method to format and send update game phase message.
///
/// \param game_phase The updated game phase.
///

void HexTile :: __sendUpdateGamePhaseMessage(std::string game_phase)
{
    Message update_game_phase_message;
    
    update_game_phase_message.channel = GAME_CHANNEL;
    update_game_phase_message.subject = "update game phase";
    
    update_game_phase_message.string_payload["game phase"] = game_phase;
    
    this->message_hub_ptr->sendMessage(update_game_phase_message);
    
    std::cout << "Update game phase message sent by " << this << std::endl;
    
    return;
}   /* __sendUpdateGamePhaseMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __sendCreditsSpentMessage(int credits_spent)
///
/// \brief Helper method to format and send a credits spent message.
///
/// \param credits_spent The number of credits that were spent.
///

void HexTile :: __sendCreditsSpentMessage(int credits_spent)
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
/// \fn void HexTile :: __sendInsufficientCreditsMessage(void)
///
/// \brief Helper method to format and send an insufficient credits message.
///

void HexTile :: __sendInsufficientCreditsMessage(void)
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
/// \fn HexTile :: HexTile(
///         double position_x,
///         double position_y,
///         sf::Event* event_ptr,
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr,
///         MessageHub* message_hub_ptr
///     )
///
/// \brief Constructor for the HexTile class.
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

HexTile :: HexTile(
    double position_x,
    double position_y,
    sf::Event* event_ptr,
    sf::RenderWindow* render_window_ptr,
    AssetsManager* assets_manager_ptr,
    MessageHub* message_hub_ptr
)
{
    //  1. set attributes
    
    //  1.1. private
    this->event_ptr = event_ptr;
    this->render_window_ptr = render_window_ptr;
    
    this->assets_manager_ptr = assets_manager_ptr;
    this->message_hub_ptr = message_hub_ptr;
    
    //  1.2. public
    this->show_node = false;
    this->show_resource = false;
    this->resource_assessed = false;
    this->resource_assessment = false;
    this->is_selected = false;
    this->draw_explosion = false;
    
    this->decoration_cleared = false;
    this->has_improvement = false;
    this->tile_improvement_ptr = NULL;
    
    this->build_menu_open = false;
    
    this->explosion_frame = 0;
    
    this->frame = 0;
    this->credits = 0;
    
    this->scrap_improvement_frame = 0;
    
    this->position_x = position_x;
    this->position_y = position_y;
    
    this->major_radius = 32;
    this->minor_radius = (sqrt(3) / 2) * this->major_radius;
    
    this->game_phase = "build settlement";
    
    //  2. set up and position drawable attributes
    this->__setUpNodeSprite();
    this->__setUpTileSprite();
    this->__setUpSelectOutlineSprite();
    this->__setUpResourceChipSprite();
    this->__setResourceText();
    this->__setUpMagnifyingGlassSprite();
    this->__setUpTileExplosionReel();
    
    //  3. set tile type and resource (default to none type and average)
    this->setTileType(TileType :: NONE_TYPE);
    this->setTileResource(TileResource :: AVERAGE);
    
    std::cout << "HexTile constructed at " << this << std::endl;
    
    return;
}   /* HexTile() */

// ---------------------------------------------------------------------------------- //


// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: setTileType(TileType tile_type)
///
/// \brief Method to set the tile type (by enum value).
///
/// \param tile_type The type (TileType) to set the tile to.

void HexTile :: setTileType(TileType tile_type)
{
    this->tile_type = tile_type;
    
    switch (this->tile_type) {
        case (TileType :: FOREST): {
            this->tile_sprite.setFillColor(FOREST_GREEN);

            break;
        }
        
        case (TileType :: LAKE): {
            this->tile_sprite.setFillColor(LAKE_BLUE);
            
            break;
        }
        
        case (TileType :: MOUNTAINS): {
            this->tile_sprite.setFillColor(MOUNTAINS_GREY);
            
            break;
        }
        
        case (TileType :: OCEAN): {
            this->tile_sprite.setFillColor(OCEAN_BLUE);
            
            break;
        }
        
        case (TileType :: PLAINS): {
            this->tile_sprite.setFillColor(PLAINS_YELLOW);
            
            break;
        }
        
        default: {
            // do nothing!
            
            break;
        }
    }
    
    this->__setUpBuildMenu();
    
    return;
}   /* setTileType(TileType) */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: setTileType(double input_value)
///
/// \brief Method to set the tile type (by numeric input).
///
/// \param input_value A numerical input in the closed interval [0, 1].
///

void HexTile :: setTileType(double input_value)
{
    //  1. check input
    if (input_value < 0 or input_value > 1) {
        std::string error_str = "ERROR  HexTile::setTileType()  given input value is ";
        error_str += "not in the closed interval [0, 1]";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. convert input value to tile type
    TileType tile_type;
    
    if (input_value <= TILE_TYPE_CUMULATIVE_PROBABILITIES[0]) {
        tile_type = TileType :: LAKE;
    }
    else if (input_value <= TILE_TYPE_CUMULATIVE_PROBABILITIES[1]) {
        tile_type = TileType :: PLAINS;
    }
    else if (input_value <= TILE_TYPE_CUMULATIVE_PROBABILITIES[2]) {
        tile_type = TileType :: FOREST;
    }
    else {
        tile_type = TileType :: MOUNTAINS;
    }
    
    //  3. call alternate method
    this->setTileType(tile_type);
    
    return;
}   /* setTileType(double) */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: setTileResource(TileResource tile_resource)
///
/// \brief Method to set the tile resource (by enum value).
///
/// \param tile_resource The resource (TileResource) value to attribute to the tile.
///

void HexTile :: setTileResource(TileResource tile_resource)
{
    this->tile_resource = tile_resource;
    this->__setResourceText();
    
    return;
}   /* setTileResource(TileResource) */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: setTileResource(double input_value)
///
/// \brief Method to set the tile resource (by numeric input).
///
/// \param input_value A numerical input in the closed interval [0, 1].
///

void HexTile :: setTileResource(double input_value)
{
    //  1. check input
    if (input_value < 0 or input_value > 1) {
        std::string error_str = "ERROR  HexTile::setTileResource()  given input value is ";
        error_str += "not in the closed interval [0, 1]";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. convert input value to tile resource
    TileResource tile_resource;
    
    if (input_value <= TILE_RESOURCE_CUMULATIVE_PROBABILITIES[0]) {
        tile_resource = TileResource :: POOR;
    }
    else if (input_value <= TILE_RESOURCE_CUMULATIVE_PROBABILITIES[1]) {
        tile_resource = TileResource :: BELOW_AVERAGE;
    }
    else if (input_value <= TILE_RESOURCE_CUMULATIVE_PROBABILITIES[2]) {
        tile_resource = TileResource :: AVERAGE;
    }
    else if (input_value <= TILE_RESOURCE_CUMULATIVE_PROBABILITIES[3]) {
        tile_resource = TileResource :: ABOVE_AVERAGE;
    }
    else {
        tile_resource = TileResource :: GOOD;
    }
    
    //  3. call alternate method
    this->setTileResource(tile_resource);
    
    return;
}   /* setTileResource(double) */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: decorateTile(void)
///
/// \brief Method to decorate tile.
///

void HexTile :: decorateTile(void)
{
    switch (this->tile_type) {
        case (TileType :: FOREST): {
            this->tile_decoration_sprite.setTexture(
                *(this->assets_manager_ptr->getTexture("pine_tree_64x64_1"))
            );
            
            break;
        }
        
        case (TileType :: LAKE): {
            this->tile_decoration_sprite.setTexture(
                *(this->assets_manager_ptr->getTexture("water_shimmer_64x64_1"))
            );
            
            break;
        }
        
        case (TileType :: MOUNTAINS): {
            this->tile_decoration_sprite.setTexture(
                *(this->assets_manager_ptr->getTexture("mountain_64x64_1"))
            );
            
            break;
        }
        
        case (TileType :: OCEAN): {
            this->tile_decoration_sprite.setTexture(
                *(this->assets_manager_ptr->getTexture("water_waves_64x64_1"))
            );
            
            break;
        }
        
        case (TileType :: PLAINS): {
            this->tile_decoration_sprite.setTexture(
                *(this->assets_manager_ptr->getTexture("wheat_64x64_1"))
            );
            
            break;
        }
        
        default: {
            // do nothing!
            
            break;
        }
    }
    
    
    if (this->tile_type == TileType :: OCEAN or this->tile_type == TileType :: LAKE) {
        this->tile_decoration_sprite.setOrigin(
            this->tile_decoration_sprite.getLocalBounds().width / 2,
            this->tile_decoration_sprite.getLocalBounds().height / 2
        );
        
        this->tile_decoration_sprite.setPosition(
            this->position_x,
            this->position_y
        );
        
        if ((double)rand() / RAND_MAX > 0.5) {
            this->tile_decoration_sprite.setScale(sf::Vector2f(-1, 1));
        }
    }
    
    else {
        this->tile_decoration_sprite.setOrigin(
            this->tile_decoration_sprite.getLocalBounds().width / 2,
            this->tile_decoration_sprite.getLocalBounds().height
        );
        
        this->tile_decoration_sprite.setPosition(
            this->position_x,
            this->position_y + 12
        );
        
        if ((double)rand() / RAND_MAX > 0.5) {
            this->tile_decoration_sprite.setScale(sf::Vector2f(-1, 1));
        }
    }
    
    return;
}   /* decorateTile(void) */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: toggleResourceOverlay(void)
///
/// \brief Method to toggle the tile resource overlay.
///

void HexTile :: toggleResourceOverlay(void)
{
    if (this->show_resource) {
        this->show_resource = false;
    }
    else {
        this->show_resource = true;
    }
    
    return;
}   /* toggleResourceOverlay() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: assess(void)
///
/// \brief Method to assess the tile's resource.
///

void HexTile :: assess(void)
{
    this->resource_assessed = true;
    this->resource_assessment = true;
    
    this->assets_manager_ptr->getSound("resource assessment")->play();
    
    this->__setResourceText();
    this->__sendTileStateMessage();
    
    return;
}   /* assess() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: processEvent(void)
///
/// \brief Method to process HexTile. To be called once per event.
///

void HexTile :: processEvent(void)
{
    //  1. process TileImprovement events
    if (
        this->is_selected and
        this->tile_improvement_ptr != NULL
    ) {
        this->tile_improvement_ptr->processEvent();
    }
    
    //  2. process HexTile events
    if (this->event_ptr->type == sf::Event::KeyPressed) {
        this->__handleKeyPressEvents();
    }
    
    if (this->event_ptr->type == sf::Event::KeyReleased) {
        this->__handleKeyReleaseEvents();
    }
    
    if (this->event_ptr->type == sf::Event::MouseButtonPressed) {
        this->__handleMouseButtonEvents();
    }
    
    return;
}   /* processEvent() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: processMessage(void)
///
/// \brief Method to process HexTile. To be called once per message.
///

void HexTile :: processMessage(void)
{
    //  1. process TileImprovement messages
    if (this->tile_improvement_ptr != NULL) {
        this->tile_improvement_ptr->processMessage();
    }
    
    //  2. process HexTile messages
    if (this->is_selected) {
        if (not this->message_hub_ptr->isEmpty(TILE_STATE_CHANNEL)) {
            Message tile_state_message = this->message_hub_ptr->receiveMessage(
                TILE_STATE_CHANNEL
            );
            
            if (tile_state_message.subject == "state request") {
                this->__sendTileStateMessage();
                
                std::cout << "Tile state request received by " << this << std::endl;
                this->message_hub_ptr->popMessage(TILE_STATE_CHANNEL);
            }
        }
        
        std::cout << "Current credits (HexTile): " << this->credits << " K" <<
            std::endl;
    }
    
    if (not this->message_hub_ptr->isEmpty(GAME_STATE_CHANNEL)) {
        Message game_state_message = this->message_hub_ptr->receiveMessage(
            GAME_STATE_CHANNEL
        );
        
        if (game_state_message.subject == "game state") {
            this->credits = game_state_message.int_payload["credits"];
            this->game_phase = game_state_message.string_payload["game phase"];
            
            if (this->tile_improvement_ptr != NULL) {
                this->tile_improvement_ptr->credits = this->credits;
                this->tile_improvement_ptr->game_phase = this->game_phase;
                
                this->tile_improvement_ptr->month =
                    game_state_message.int_payload["month"];
                    
                this->tile_improvement_ptr->demand_MWh =
                    game_state_message.int_payload["demand_MWh"];
                
                this->tile_improvement_ptr->demand_vec_MWh =
                    game_state_message.vector_payload["demand_vec_MWh"];
                
                this->tile_improvement_ptr->update();
            }
            
            this->message_hub_ptr->incrementMessageRead(GAME_STATE_CHANNEL);
            
            std::cout << "Game state message read and passed by " << this <<
                " (credits: " << this->credits << " K)" << std::endl;
            
            if (this->is_selected) {
                this->__sendTileStateMessage();
            }
        }
    }
    
    return;
}   /* processMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: draw(void)
///
/// \brief Method to draw the hex tile to the render window. To be called once per
///     frame.
///

void HexTile :: draw(void)
{
    //  1. draw hex
    this->render_window_ptr->draw(this->tile_sprite);
    
    //  2. draw node
    if (this->show_node) {
        this->render_window_ptr->draw(this->node_sprite);
    }
    
    //  3. draw tile decoration
    if (not this->decoration_cleared) {
        this->render_window_ptr->draw(this->tile_decoration_sprite);
    }
    
    //  4. draw selection outline
    if (this->is_selected) {
        sf::Color outline_colour = this->select_outline_sprite.getOutlineColor();
        
        outline_colour.a =
            255 * pow(cos((M_PI * this->frame) / FRAMES_PER_SECOND), 2);
        
        this->select_outline_sprite.setOutlineColor(outline_colour);
        
        this->render_window_ptr->draw(this->select_outline_sprite);
    }
    
    //  5. draw tile improvement
    if (this->has_improvement) {
        if (not this->tile_improvement_ptr->just_built) {
            this->tile_improvement_ptr->draw();
        }
    }
    
    //  6. draw resource
    if (this->show_resource) {
        this->render_window_ptr->draw(this->resource_chip_sprite);
        this->render_window_ptr->draw(this->resource_text);
    }
    
    //  7. draw resource assessment notification
    if (this->resource_assessment) {
        int alpha = this->magnifying_glass_sprite.getColor().a;
        
        alpha -= 0.05 * FRAMES_PER_SECOND;
        if (alpha < 0) {
            alpha = 0;
            this->resource_assessment = false;
        }
        
        this->magnifying_glass_sprite.setColor(
            sf::Color(255, 255, 255, alpha)
        );
        
        this->render_window_ptr->draw(this->magnifying_glass_sprite);
    }
    
    //  8. draw explosion, then settlement placement
    if (this->draw_explosion) {
        this->render_window_ptr->draw(this->explosion_sprite_reel[this->explosion_frame]);
        
        if (this->frame % (FRAMES_PER_SECOND / 20) == 0) {
            this->explosion_frame++;
        }
        
        if (this->explosion_frame >= this->explosion_sprite_reel.size()) {
            this->draw_explosion = false;
            this->explosion_frame = 0;
        }
    }
    
    else if (this->has_improvement) {
        if (this->tile_improvement_ptr->just_built) {
            this->tile_improvement_ptr->draw();
        }
    }
    
    //  9. build menu
    if (this->build_menu_open) {
        this->render_window_ptr->draw(this->build_menu_backing);
        this->render_window_ptr->draw(this->build_menu_backing_text);
        
        for (size_t i = 0; i < this->build_menu_options_vec.size(); i++) {
            for (size_t j = 0; j < this->build_menu_options_vec[i].size(); j++) {
                this->render_window_ptr->draw(this->build_menu_options_vec[i][j]);
            }
            this->render_window_ptr->draw(this->build_menu_options_text_vec[i]);
        }
    }
    
    this->frame++;
    return;
}   /* draw() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn HexTile :: ~HexTile(void)
///
/// \brief Destructor for the HexTile class.
///

HexTile :: ~HexTile(void)
{
    if (this->tile_improvement_ptr != NULL) {
        delete this->tile_improvement_ptr;
    }
    
    std::cout << "HexTile at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~HexTile() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
