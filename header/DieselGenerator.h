/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the DieselGenerator class.
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
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
    
    
    public:
        //  1. attributes
        bool skip_smoke_processing; ///< A boolean which indicates whether or not to skip smoke processing.
        
        double smoke_da; ///< The per frame delta in smoke particle alpha value.
        double smoke_dx; ///< The per frame delta in smoke particle x position.
        double smoke_dy; ///< The per frame delta in smoke particle y position.
        double smoke_prob; ///< The probability of spawning a new smoke prob in any given frame.
        
        std::list<sf::Sprite> smoke_sprite_list; ///< A list of smoke sprite (for chimney animation).
        
        //  2. methods
        DieselGenerator(
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
        
        virtual ~DieselGenerator(void);
        
};  /* DieselGenerator */


#endif  /* DIESELGENERATOR_H */
