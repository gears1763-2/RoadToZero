/*
 *  RoadToZero
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
        virtual void __handleKeyPressEvents(void);
        virtual void __handleMouseButtonEvents(void);
    
    
    public:
        //  1. attributes
        TileImprovementType tile_improvement_type; ///< The type of the tile improvement.
        
        bool is_running; ///< A boolean which indicates whether or not the improvement is running.
        bool is_selected; ///< A boolean which indicates whether or not the tile is selected.
        bool just_built; ///< A boolean which indicates that the improvement was just built.
        
        unsigned long long int frame; ///< The current frame of this object.
        int credits; ///< The current balance of credits.
        
        double position_x; ///< The x position of the tile improvement.
        double position_y; ///< The y position of the tile improvement.
        
        std::string game_phase; ///< The current phase of the game.
        std::string tile_improvement_string; ///< A string representation of the tile improvement type.
        
        sf::Sprite tile_improvement_sprite_static; ///< A static sprite, for decorating the tile.
        std::vector<sf::Sprite> tile_improvement_sprite_animated; ///< An animated sprite, for the ContextMenu visual screen.
        
        //  2. methods
        TileImprovement(
            double,
            double,
            sf::Event*,
            sf::RenderWindow*,
            AssetsManager*,
            MessageHub*
        );
        
        virtual void processEvent(void);
        virtual void processMessage(void);
        
        virtual void draw(void);
        
        virtual ~TileImprovement(void);
        
};  /* TileImprovement */


#endif  /* TILEIMPROVEMENT_H */
