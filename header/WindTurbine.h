/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the WindTurbine class.
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
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
    
    
    public:
        //  1. attributes
        //...
        
        //  2. methods
        WindTurbine(
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
        
        virtual ~WindTurbine(void);
        
};  /* WindTurbine */


#endif  /* WINDTURBINE_H */
