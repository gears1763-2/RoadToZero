/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the TidalTurbine class.
 *
 */


///
/// \file TidalTurbine.h
///
/// \brief Header file for the TidalTurbine class.
///


#ifndef TIDALTURBINE_H
#define TIDALTURBINE_H


#include "ESC_core/constants.h"
#include "ESC_core/includes.h"
#include "ESC_core/AssetsManager.h"
#include "ESC_core/MessageHub.h"

#include "TileImprovement.h"


///
/// \class TidalTurbine
///
/// \brief A settlement class (child class of TileImprovement).
///

class TidalTurbine: public TileImprovement {
    private:
        //  1. attributes
        //...
        
        
        //  2. methods
        void __setUpTileImprovementSpriteAnimated(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
    
    
    public:
        //  1. attributes
        //...
        
        //  2. methods
        TidalTurbine(
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
        
        virtual ~TidalTurbine(void);
        
};  /* TidalTurbine */


#endif  /* TIDALTURBINE_H */
