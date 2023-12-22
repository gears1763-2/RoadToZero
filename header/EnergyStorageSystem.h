/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the EnergyStorageSystem class.
 *
 */


///
/// \file EnergyStorageSystem.h
///
/// \brief Header file for the EnergyStorageSystem class.
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
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
    
    
    public:
        //  1. attributes
        //...
        
        //  2. methods
        EnergyStorageSystem(
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
        
        virtual ~EnergyStorageSystem(void);
        
};  /* EnergyStorageSystem */


#endif  /* ENERGY_STORAGE_SYSTEM_H */
