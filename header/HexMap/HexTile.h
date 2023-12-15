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


///
/// \class HexTile
///
/// \brief A class which defines a hex tile of the hex map.
///

class HexTile {
    private:
        //  1. attributes
        void __setUpNodeSprite(void);
        void __setUpTileSprite(void);
        
        
        //  2. methods
        //...
    
    
    public:
        //  1. attributes
        bool show_node; ///< A boolean which indicates whether or not to show the tile node.
        
        double position_x; ///< The x position of the tile.
        double position_y; ///< The y position of the tile.
        
        double major_radius; ///< The radius of the smallest bounding circle.
        double minor_radius; ///< The radius of the largest inscribed circle.
        
        sf::CircleShape node_sprite; ///< A circle shape to mark the tile node.
        sf::ConvexShape tile_sprite; ///< A convex shape which represents the tile.
        
        
        //  2. methods
        HexTile(double, double);
        
        void draw(sf::RenderWindow*);
        
        ~HexTile(void);
};


#endif  /* HEXTILE_H */
