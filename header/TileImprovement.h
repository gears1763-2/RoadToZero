/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Header file for the TileImprovement class.
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
/// \file TileImprovement.h
///
/// \brief Header file for the TileImprovement class.
///


#ifndef TILEIMPROVEMENT_H
#define TILEIMPROVEMENT_H


#include "ESC_core/constants.h"
#include "ESC_core/includes.h"
#include "ESC_core/AssetsManager.h"
#include "ESC_core/MessageHub.h"


///
/// \enum TileImprovementType
///
/// \brief An enumeration of the different tile improvement types
///

enum TileImprovementType {
    SETTLEMENT, ///< A settlement.
    DIESEL_GENERATOR, ///< A diesel generator.
    SOLAR_PV, ///< A solar PV array.
    WIND_TURBINE, ///< A wind turbine.
    TIDAL_TURBINE, ///< A tidal turbine.
    WAVE_ENERGY_CONVERTER, ///< A wave energy converter.
    ENERGY_STORAGE_SYSTEM, ///< An energy storage system.
    N_TILE_IMPROVEMENT_TYPES ///< A simple hack to get the number of elements in TileImprovementType.
};  /* TileImprovementType */


///
/// \class TileImprovement
///
/// \brief A base class for the tile improvement hierarchy.
///

class TileImprovement {
    protected:
        //  1. attributes
        sf::Event* event_ptr; ///< A pointer to the event class.
        sf::RenderWindow* render_window_ptr; ///< A pointer to the render window.
        
        AssetsManager* assets_manager_ptr; ///< A pointer to the assets manager.
        MessageHub* message_hub_ptr; ///< A pointer to the message hub.
        
        
        //  2. methods
        void __setUpProductionMenu(void);
        void __setUpUpgradeMenu(void);
        
        void __upgradeStorageCapacity(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
        
        void __openProductionMenu(void);
        void __closeProductionMenu(void);
        
        void __breakdown(void);
        
        void __openUpgradeMenu(void);
        void __closeUpgradeMenu(void);
        
        void __sendTileStateRequest(void);
        void __sendGameStateRequest(void);
        
        void __sendCreditsSpentMessage(int);
        void __sendInsufficientCreditsMessage(void);
    
    
    public:
        //  1. attributes
        TileImprovementType tile_improvement_type; ///< The type of the tile improvement.
        
        bool is_running; ///< A boolean which indicates whether or not the improvement is running.
        bool is_selected; ///< A boolean which indicates whether or not the tile is selected.
        bool just_built; ///< A boolean which indicates that the improvement was just built.
        bool just_upgraded; ///< A boolean which indicates that the improvement was just upgraded.
        bool production_menu_open; ///< A boolean which indicates whether or not the production menu is open.
        bool upgrade_menu_open; ///< A boolean which indicates whether or not the build menu is open.
        bool is_broken; ///< A boolean which indicated whether or not improvement is broken.
        
        unsigned long long int frame; ///< The current frame of this object.
        int credits; ///< The current balance of credits.
        int month; ///< The current month of play
        int demand_MWh; ///< The current demand [MWh].
        int health; ///< The health of the improvement.
        int upgrade_level; ///< The upgrade level of the improvement.
        int upgrade_frame; ///< The frame of the upgrade animation.
        
        int storage_kWh; ///< The rated energy capacity [kWh] of the storage.
        int storage_level; ///< The level of storage installed alongside the tile improvement.
        
        int operation_maintenance_cost; ///< The operation and maintenance costs for this turn.
        
        int tile_resource; ///< The renewable resource quality of the tile.
        double tile_resource_scalar; ///< A scalar associated with the renewable resource quality.
        
        double position_x; ///< The x position of the tile improvement.
        double position_y; ///< The y position of the tile improvement.
        
        std::vector<double> demand_vec_MWh; ///< A vector of daily demands [MWh] for the current month.
        
        std::string game_phase; ///< The current phase of the game.
        std::string tile_improvement_string; ///< A string representation of the tile improvement type.
        
        sf::Sprite tile_improvement_sprite_static; ///< A static sprite, for decorating the tile.
        std::vector<sf::Sprite> tile_improvement_sprite_animated; ///< An animated sprite, for the ContextMenu visual screen.
        
        sf::RectangleShape production_menu_backing; ///< A backing for the production menu.
        sf::Text production_menu_backing_text; ///< Text for the production menu backing.
        
        sf::RectangleShape upgrade_menu_backing; ///< A backing for the upgrade menu.
        sf::Text upgrade_menu_backing_text; ///< Text for the upgrade menu backing.
        
        sf::Sprite storage_upgrade_sprite; ///< A sprite for illustrating storage (in upgrade menu).
        std::vector<sf::Sprite> storage_upgrade_sprite_vec; ///< A vector of sprites for illustrating the storage upgrade level (on tile).
        
        sf::Sprite upgrade_arrow_sprite; ///< An upgrade arrow sprite.
        sf::Sprite upgrade_plus_sprite; ///< An upgrade plus sprite.
        
        //  2. methods
        TileImprovement(
            double,
            double,
            int,
            sf::Event*,
            sf::RenderWindow*,
            AssetsManager*,
            MessageHub*
        );
        
        virtual void setIsSelected(bool);
        
        virtual void advanceTurn(void) {return;}
        
        virtual void update(void) {return;}
        
        virtual std::string getTileOptionsSubstring(void) {return "";}
        
        virtual void processEvent(void);
        virtual void processMessage(void);
        
        virtual void draw(void);
        
        virtual ~TileImprovement(void);
        
};  /* TileImprovement */


#endif  /* TILEIMPROVEMENT_H */
