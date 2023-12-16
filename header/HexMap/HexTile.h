/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the HexTile class.
 *
 */


///
/// \file HexTile.h
///
/// \brief Header file for the HexTile class.
///


#ifndef HEXTILE_H
#define HEXTILE_H


#include "../ESC_core/includes.h"
#include "../ESC_core/AssetsManager.h"
#include "../ESC_core/InputsHandler.h"
#include "../ESC_core/MessagesHandler.h"


///
/// \enum TileType
///
/// \brief An enumeration of the different tile types.
///

enum TileType {
    FOREST, ///< A forest tile
    LAKE, ///< A lake tile
    MOUNTAINS, ///< A mountains tile
    OCEAN, ///< An ocean tile
    PLAINS, ///< A plains tile
    N_TILE_TYPES ///< A simple hack to get the number of elements in TileType
};

const sf::Color FOREST_GREEN(34, 139, 34); ///< The base colour of a forest tile
const sf::Color LAKE_BLUE(0, 102, 204); ///< The base colour of a lake (water) tile
const sf::Color MOUNTAINS_GREY(97, 110, 113); ///< The base colour of a mountains tile
const sf::Color OCEAN_BLUE(0, 51, 102); ///< The base colour of an ocean (water) tile
const sf::Color PLAINS_YELLOW(245, 222, 133); ///< The base colour of a plains tile


///
/// \class HexTile
///
/// \brief A class which defines a hex tile of the hex map.
///

class HexTile {
    private:
        //  1. attributes
        AssetsManager* assets_manager_ptr; ///< A pointer to the assets manager.
        InputsHandler* inputs_handler_ptr; ///< A pointer to the inputs handler.
        MessagesHandler* messages_handler_ptr; ///< A pointer to the messages handler.
        
        
        //  2. methods
        void __setUpNodeSprite(void);
        void __setUpTileSprite(void);
    
    
    public:
        //  1. attributes
        TileType tile_type;
        
        bool show_node; ///< A boolean which indicates whether or not to show the tile node.
        
        int frame; ///< The current frame of this object.
        
        double position_x; ///< The x position of the tile.
        double position_y; ///< The y position of the tile.
        
        double major_radius; ///< The radius of the smallest bounding circle.
        double minor_radius; ///< The radius of the largest inscribed circle.
        
        sf::CircleShape node_sprite; ///< A circle shape to mark the tile node.
        sf::ConvexShape tile_sprite; ///< A convex shape which represents the tile.
        
        
        //  2. methods
        HexTile(double, double, AssetsManager*, InputsHandler*, MessagesHandler*);
        
        void setTileType(TileType);
        void draw(sf::RenderWindow*);
        
        ~HexTile(void);
};


#endif  /* HEXTILE_H */
