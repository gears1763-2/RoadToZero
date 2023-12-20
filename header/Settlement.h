/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the Settlement class.
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
        int population; ///< Current population.
        
        //  2. methods
        Settlement(
            double,
            double,
            sf::Event*,
            sf::RenderWindow*,
            AssetsManager*,
            MessageHub*
        );
        
        void processEvent(void);
        void processMessage(void);
        
        void draw(void);
        
        virtual ~Settlement(void);
        
};  /* Settlement */


#endif  /* SETTLEMENT_H */
