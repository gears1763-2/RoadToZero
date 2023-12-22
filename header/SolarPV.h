/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the SolarPV class.
 *
 */


///
/// \file SolarPV.h
///
/// \brief Header file for the SolarPV class.
///


#ifndef SOLARPV_H
#define SOLARPV_H


#include "ESC_core/constants.h"
#include "ESC_core/includes.h"
#include "ESC_core/AssetsManager.h"
#include "ESC_core/MessageHub.h"

#include "TileImprovement.h"


///
/// \class SolarPV
///
/// \brief A settlement class (child class of TileImprovement).
///

class SolarPV: public TileImprovement {
    private:
        //  1. attributes
        //...
        
        
        //  2. methods
        void __setUpTileImprovementSpriteStatic(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
    
    
    public:
        //  1. attributes
        //...
        
        //  2. methods
        SolarPV(
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
        
        virtual ~SolarPV(void);
        
};  /* SolarPV */


#endif  /* SOLARPV_H */
