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


#include "TileImprovement.h"


///
/// \enum TileType
///
/// \brief An enumeration of the different tile types.
///

enum TileType {
    NONE_TYPE, ///< A dummy tile (for initialization).
    FOREST, ///< A forest tile.
    LAKE, ///< A lake tile.
    MOUNTAINS, ///< A mountains tile.
    OCEAN, ///< An ocean tile.
    PLAINS, ///< A plains tile.
    N_TILE_TYPES ///< A simple hack to get the number of elements in TileType.
}; /* TileType */


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
};  /* TileResource */


///
/// \class HexTile
///
/// \brief A class which defines a hex tile of the hex map.
///

class HexTile {
    private:
        //  1. attributes
        sf::Event* event_ptr; ///< A pointer to the event class.
        sf::RenderWindow* render_window_ptr; ///< A pointer to the render window.
        
        AssetsManager* assets_manager_ptr; ///< A pointer to the assets manager.
        MessageHub* message_hub_ptr; ///< A pointer to the message hub.
        
        
        //  2. methods
        void __setUpNodeSprite(void);
        void __setUpTileSprite(void);
        void __setUpSelectOutlineSprite(void);
        void __setUpResourceChipSprite(void);
        void __setResourceText(void);
        
        bool __isClicked(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
        
        void __sendTileSelectedMessage(void);
        
        std::string __getTileCoordsSubstring(void);
        std::string __getTileTypeSubstring(void);
        std::string __getTileResourceSubstring(void);
        std::string __getTileImprovementSubstring(void);
        std::string __getTileOptionsSubstring(void);
        void __sendTileStateMessage(void);
        
        void __sendGameStateRequest(void);
        
        void __sendCreditsSpentMessage(int);
        void __sendInsufficientCreditsMessage(void);
    
    
    public:
        //  1. attributes
        TileType tile_type;
        TileResource tile_resource;
        
        bool show_node; ///< A boolean which indicates whether or not to show the tile node.
        bool show_resource; ///< A boolean which indicates whether or not to show resource value.
        bool resource_assessed; ///< A boolean which indicates whether or not the resource has been assessed.
        bool is_selected; ///< A boolean which indicates whether or not the tile is selected.
        
        bool settlement_built; ///< A boolean which indicates if a settlement has been built yet or not.
        bool has_improvement; ///< A boolean which indicates if tile has improvement or not.
        TileImprovement* tile_improvement_ptr; ///< A pointer to the improvement for this tile.
        
        int frame; ///< The current frame of this object.
        int credits; ///< The current balance of credits.
        
        double position_x; ///< The x position of the tile.
        double position_y; ///< The y position of the tile.
        
        double major_radius; ///< The radius of the smallest bounding circle.
        double minor_radius; ///< The radius of the largest inscribed circle.
        
        sf::CircleShape node_sprite; ///< A circle shape to mark the tile node.
        sf::ConvexShape tile_sprite; ///< A convex shape which represents the tile.
        sf::ConvexShape select_outline_sprite; ///< A convex shape which outlines the tile when selected.
        sf::CircleShape resource_chip_sprite; ///< A circle shape which represents a resource chip.
        sf::Text resource_text; ///< A text representation of the resource.
        sf::Sprite tile_decoration_sprite; ///< A tile decoration sprite.
        
        
        //  2. methods
        HexTile(
            double,
            double,
            sf::Event*,
            sf::RenderWindow*,
            AssetsManager*,
            MessageHub*
        );
        
        void setTileType(TileType);
        void setTileType(double);
        
        void setTileResource(TileResource);
        void setTileResource(double);
        
        void decorateTile(void);
        
        void toggleResourceOverlay(void);
        void assess(void);
        
        void processEvent(void);
        void processMessage(void);
        
        void draw(void);
        
        ~HexTile(void);
};  /* HexTile */


#endif  /* HEXTILE_H */
