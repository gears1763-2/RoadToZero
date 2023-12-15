/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the HexMap class.
 *
 */


///
/// \file HexMap.h
///
/// \brief Header file for the HexMap class.
///


#ifndef HEXMAP_H
#define HEXMAP_H


#include "../ESC_core/AssetsManager.h"
#include "../ESC_core/InputsHandler.h"
#include "HexTile.h"


///
/// \class HexMap
///
/// \brief A class which defines a hex map of hex tiles.
///

class HexMap {
    private:
        //  1. attributes
        //...
        
        
        //  2. methods
        void __assembleHexMap(void);
    
    
    public:
        //  1. attributes
        int n_layers; ///< The number of layers in the hex map.
        
        double position_x; ///< The x position of the hex map's origin (i.e. central) tile.
        double position_y; ///< The y position of the hex map's origin (i.e. central) tile.
        
        std::vector<HexTile*> hex_vec; ///< A vector of pointers to the tiles in the hex map.
        
        
        //  2. methods
        HexMap(int);
        
        void draw(sf::RenderWindow*);
        void clear(void);
        
        ~HexMap(void);
};


#endif  /* HEXMAP_H */
