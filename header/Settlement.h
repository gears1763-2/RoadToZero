/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Header file for the Settlement class.
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
/// \file Settlement.h
///
/// \brief Header file for the Settlement class.
///


#ifndef SETTLEMENT_H
#define SETTLEMENT_H


#include "ESC_core/constants.h"
#include "ESC_core/includes.h"
#include "ESC_core/AssetsManager.h"
#include "ESC_core/MessageHub.h"

#include "TileImprovement.h"


///
/// \class Settlement
///
/// \brief A settlement class (child class of TileImprovement).
///

class Settlement: public TileImprovement {
    private:
        //  1. attributes
        //...
        
        
        //  2. methods
        void __setUpTileImprovementSpriteStatic(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
    
    
    public:
        //  1. attributes
        double smoke_da; ///< The per frame delta in smoke particle alpha value.
        double smoke_dx; ///< The per frame delta in smoke particle x position.
        double smoke_dy; ///< The per frame delta in smoke particle y position.
        double smoke_prob; ///< The probability of spawning a new smoke prob in any given frame.
        
        std::list<sf::Sprite> smoke_sprite_list; ///< A list of smoke sprite (for chimney animation).
        
        //  2. methods
        Settlement(
            double,
            double,
            sf::Event*,
            sf::RenderWindow*,
            AssetsManager*,
            MessageHub*
        );
        
        std::string getTileOptionsSubstring(void);
        
        void processEvent(void);
        void processMessage(void);
        
        void draw(void);
        
        virtual ~Settlement(void);
        
};  /* Settlement */


#endif  /* SETTLEMENT_H */
