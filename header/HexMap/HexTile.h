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
    FOREST, ///< A forest tile.
    LAKE, ///< A lake tile.
    MOUNTAINS, ///< A mountains tile.
    OCEAN, ///< An ocean tile.
    PLAINS, ///< A plains tile.
    N_TILE_TYPES ///< A simple hack to get the number of elements in TileType.
};

const sf::Color FOREST_GREEN(34, 139, 34); ///< The base colour of a forest tile.
const sf::Color LAKE_BLUE(0, 102, 204); ///< The base colour of a lake (water) tile.
const sf::Color MOUNTAINS_GREY(97, 110, 113); ///< The base colour of a mountains tile.
const sf::Color OCEAN_BLUE(0, 51, 102); ///< The base colour of an ocean (water) tile.
const sf::Color PLAINS_YELLOW(245, 222, 133); ///< The base colour of a plains tile.

const std::vector<double> tile_type_cumulative_probabilities = {
    0.25,  // LAKE
    0.50,  // PLAINS
    0.75,  // FOREST
    1.00   // MOUNTAINS
};


///
/// \enum TileResource
///
/// \brief An enumeration of the different tile resource values.
///

enum TileResource {
    POOR, ///< A poor resource value.
    BELOW_AVERAGE, ///< A below average resource value.
    AVERAGE, ///< An average resource value.
    ABOVE_AVERAGE, ///< An above average resource value.
    GOOD, ///< A good resource value.
    N_TILE_RESOURCES ///< A simple hack to get the number of elements in TileResource.
};

const std::vector<double> tile_resource_cumulative_probabilities = {
    0.10,  // POOR
    0.30,  // BELOW_AVERAGE
    0.70,  // AVERAGE
    0.90,  // ABOVE_AVERAGE
    1.00   // GOOD
};


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
        sf::RenderWindow* render_window_ptr; ///< A pointer to the render window.
        
        
        //  2. methods
        void __setUpNodeSprite(void);
        void __setUpTileSprite(void);
        void __setUpResourceChip(void);
        void __setResourceText(void);
    
    
    public:
        //  1. attributes
        TileType tile_type;
        TileResource tile_resource;
        
        bool show_node; ///< A boolean which indicates whether or not to show the tile node.
        bool show_resource; ///< A boolean which indicates whether or not to show resource value.
        bool resource_assessed; ///< A boolean which indicates whether or not the resource has been assessed.
        
        int frame; ///< The current frame of this object.
        
        double position_x; ///< The x position of the tile.
        double position_y; ///< The y position of the tile.
        
        double major_radius; ///< The radius of the smallest bounding circle.
        double minor_radius; ///< The radius of the largest inscribed circle.
        
        sf::CircleShape node_sprite; ///< A circle shape to mark the tile node.
        sf::ConvexShape tile_sprite; ///< A convex shape which represents the tile.
        sf::CircleShape resource_chip_sprite; ///< A circle shape which represents a resource chip.
        sf::Text resource_text; ///< A text representation of the resource.
        
        
        //  2. methods
        HexTile(
            double,
            double,
            AssetsManager*,
            InputsHandler*,
            MessagesHandler*,
            sf::RenderWindow*
        );
        
        void setTileType(TileType);
        void setTileType(double);
        
        void setTileResource(TileResource);
        void setTileResource(double);
        
        void toggleResourceOverlay(void);
        void assess(void);
        
        void process(void);
        void draw(void);
        
        ~HexTile(void);
};


#endif  /* HEXTILE_H */
