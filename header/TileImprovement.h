/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the TileImprovement class.
 *
 */


///
/// \file TileImprovement.h
///
/// \brief Header file for the TileImprovement class.
///


#ifndef TILEIMPROVEMENT_H
#define TILEIMPROVEMENT_H


#include "ESC_core/constants.h"
#include "ESC_core/includes.h"
#include "ESC_core/AssetsManager.h"
#include "ESC_core/MessageHub.h"


///
/// \enum TileImprovementType
///
/// \brief An enumeration of the different tile improvement types
///

enum TileImprovementType {
    SETTLEMENT, ///< A settlement.
    SOLAR_PV, ///< A solar PV array.
    WIND_TURBINE, ///< A wind turbine.
    TIDAL_TURBINE, ///< A tidal turbine.
    WAVE_ENERGY_CONVERTER, ///< A wave energy converter.
    ENERGY_STORAGE_SYSTEM, ///< An energy storage system.
    N_TILE_IMPROVEMENT_TYPES ///< A simple hack to get the number of elements in TileImprovementType.
};  /* TileImprovementType */


///
/// \class TileImprovement
///
/// \brief A base class for the tile improvement hierarchy.
///

class TileImprovement {
    protected:
        //  1. attributes
        sf::Event* event_ptr; ///< A pointer to the event class.
        sf::RenderWindow* render_window_ptr; ///< A pointer to the render window.
        
        AssetsManager* assets_manager_ptr; ///< A pointer to the assets manager.
        MessageHub* message_hub_ptr; ///< A pointer to the message hub.
        
        
        //  2. methods
        virtual void __handleKeyPressEvents(void);
        virtual void __handleMouseButtonEvents(void);
    
    
    public:
        //  1. attributes
        TileImprovementType tile_improvement_type; ///< The type of the tile improvement.
        
        int frame; ///< The current frame of this object.
        int credits; ///< The current balance of credits.
        
        double position_x; ///< The x position of the tile improvement.
        double position_y; ///< The y position of the tile improvement.
        
        std::string game_phase; ///< The current phase of the game.
        
        sf::Sprite tile_improvement_sprite_static; ///< A static sprite, for decorating the tile.
        std::vector<sf::Sprite> tile_improvement_sprite_animated; ///< An animated sprite, for the ContextMenu visual screen.
        
        //  2. methods
        TileImprovement(
            double,
            double,
            sf::Event*,
            sf::RenderWindow*,
            AssetsManager*,
            MessageHub*
        );
        
        virtual void processEvent(void);
        virtual void processMessage(void);
        
        virtual void draw(void);
        
        virtual ~TileImprovement(void);
        
};  /* TileImprovement */


#endif  /* TILEIMPROVEMENT_H */
