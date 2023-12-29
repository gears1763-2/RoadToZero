/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Header file for the DieselGenerator class.
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
/// \file DieselGenerator.h
///
/// \brief Header file for the DieselGenerator class.
///


#ifndef DIESELGENERATOR_H
#define DIESELGENERATOR_H


#include "ESC_core/constants.h"
#include "ESC_core/includes.h"
#include "ESC_core/AssetsManager.h"
#include "ESC_core/MessageHub.h"

#include "TileImprovement.h"


///
/// \class DieselGenerator
///
/// \brief A settlement class (child class of TileImprovement).
///

class DieselGenerator: public TileImprovement {
    private:
        //  1. attributes
        //...
        
        
        //  2. methods
        void __setUpTileImprovementSpriteAnimated(void);
        
        void __drawProductionMenu(void);
        
        void __upgrade(void);
        
        void __computeProductionCosts(void);
        
        void __breakdown(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
        
        void __sendImprovementStateMessage(void);
    
    
    public:
        //  1. attributes
        int capacity_kW; ///< The rated production capacity [kW] of the diesel generator.
        
        int production_MWh; ///< The current production [MWh] of the diesel generator.
        int max_production_MWh; ///< The maximum production [MWh] for this turn.
        
        double smoke_da; ///< The per frame delta in smoke particle alpha value.
        double smoke_dx; ///< The per frame delta in smoke particle x position.
        double smoke_dy; ///< The per frame delta in smoke particle y position.
        double smoke_prob; ///< The probability of spawning a new smoke prob in any given frame.
        
        std::list<sf::Sprite> smoke_sprite_list; ///< A list of smoke sprite (for exhaust animation).
        
        int fuel_cost; ///< The fuel costs for this turn.
        int emissions_tonnes_CO2e; ///< The emissions for this turn.
        
        //  2. methods
        DieselGenerator(
            double,
            double,
            int,
            sf::Event*,
            sf::RenderWindow*,
            AssetsManager*,
            MessageHub*
        );
        
        std::string getTileOptionsSubstring(void);
        
        void setIsSelected(bool);
        
        void advanceTurn(void);
        
        void processEvent(void);
        void processMessage(void);
        
        void draw(void);
        
        virtual ~DieselGenerator(void);
        
};  /* DieselGenerator */


#endif  /* DIESELGENERATOR_H */
