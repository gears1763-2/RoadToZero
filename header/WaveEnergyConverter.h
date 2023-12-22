/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the WaveEnergyConverter class.
 *
 */


///
/// \file WaveEnergyConverter.h
///
/// \brief Header file for the WaveEnergyConverter class.
///


#ifndef WAVEENERGYCONVERTER_H
#define WAVEENERGYCONVERTER_H


#include "ESC_core/constants.h"
#include "ESC_core/includes.h"
#include "ESC_core/AssetsManager.h"
#include "ESC_core/MessageHub.h"

#include "TileImprovement.h"


///
/// \class WaveEnergyConverter
///
/// \brief A settlement class (child class of TileImprovement).
///

class WaveEnergyConverter: public TileImprovement {
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
        WaveEnergyConverter(
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
        
        virtual ~WaveEnergyConverter(void);
        
};  /* WaveEnergyConverter */


#endif  /* WAVEENERGYCONVERTER_H */
