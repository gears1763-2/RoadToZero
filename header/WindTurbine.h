/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Header file for the WindTurbine class.
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
/// \file WindTurbine.h
///
/// \brief Header file for the WindTurbine class.
///


#ifndef WINDTURBINE_H
#define WINDTURBINE_H


#include "ESC_core/constants.h"
#include "ESC_core/includes.h"
#include "ESC_core/AssetsManager.h"
#include "ESC_core/MessageHub.h"

#include "TileImprovement.h"


///
/// \class WindTurbine
///
/// \brief A settlement class (child class of TileImprovement).
///

class WindTurbine: public TileImprovement {
    private:
        //  1. attributes
        //...
        
        
        //  2. methods
        void __setUpTileImprovementSpriteAnimated(void);
        
        void __upgradePowerCapacity(void);
        
        void __computeCapacityFactors(void);
        void __computeProduction(void);
        void __computeDispatch(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
        
        void __drawUpgradeOptions(void);
    
    
    public:
        //  1. attributes
        int capacity_kW; ///< The rated production capacity [kW] of the solar PV array.
        
        int production_MWh; ///< The current production [MWh] of the solar PV array.
        int dispatchable_MWh; ///< The amount of production that is directly dispatchable to the grid (i.e. production correlated with demand).
        
        double max_daily_production_MWh; ///< The maximum daily production [MWh] of the solar PV array.
        
        std::vector<double> capacity_factor_vec; ///< A vector of daily capacity factors for the current month.
        std::vector<double> production_vec_MWh; ///< A vector of daily production [MWh] for the current month.
        std::vector<double> dispatch_vec_MWh; ///< A vector of daily dispatch [MWh] for the current month.
        
        //  2. methods
        WindTurbine(
            double,
            double,
            int,
            sf::Event*,
            sf::RenderWindow*,
            AssetsManager*,
            MessageHub*
        );
        
        std::string getTileOptionsSubstring(void);
        
        void advanceTurn(void);
        
        void update(void);
        
        void processEvent(void);
        void processMessage(void);
        
        void draw(void);
        
        virtual ~WindTurbine(void);
        
};  /* WindTurbine */


#endif  /* WINDTURBINE_H */
