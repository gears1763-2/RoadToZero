/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Header file for the EnergyStorageSystem class.
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
/// \file EnergyStorageSystem.h
///
/// \brief Header file for the EnergyStorageSystem class. DEPRECATED / NOT USED.
///


#ifndef ENERGY_STORAGE_SYSTEM_H
#define ENERGY_STORAGE_SYSTEM_H


#include "ESC_core/constants.h"
#include "ESC_core/includes.h"
#include "ESC_core/AssetsManager.h"
#include "ESC_core/MessageHub.h"

#include "TileImprovement.h"


///
/// \class EnergyStorageSystem
///
/// \brief A settlement class (child class of TileImprovement).
///

class EnergyStorageSystem: public TileImprovement {
    private:
        //  1. attributes
        //...
        
        
        //  2. methods
        void __setUpTileImprovementSpriteStatic(void);
        void __setUpProductionMenu(void);
        
        void __upgrade(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
    
    
    public:
        //  1. attributes
        int capacity_MWh; ///< The rated energy capacity [MWh] of the energy storage system.
        int charge_MWh; ///< The charge [MWh] in the energy storage system.
        
        //  2. methods
        EnergyStorageSystem(
            double,
            double,
            sf::Event*,
            sf::RenderWindow*,
            AssetsManager*,
            MessageHub*
        );
        
        void setIsSelected(bool);
        
        std::string getTileOptionsSubstring(void);
        
        void processEvent(void);
        void processMessage(void);
        
        void draw(void);
        
        virtual ~EnergyStorageSystem(void);
        
};  /* EnergyStorageSystem */


#endif  /* ENERGY_STORAGE_SYSTEM_H */
