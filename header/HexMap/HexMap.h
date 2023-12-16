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


#include "HexTile.h"


const double AMPLITUDE_BASE = 1; ///< A base amplitude value to use in procedural generation (based on random cosine series).
const double WAVE_NUMBER_BASE = (2.0 * M_PI) / 64; ///< A base wave number to use in procedural generation(based on random cosine series).


///
/// \class HexMap
///
/// \brief A class which defines a hex map of hex tiles.
///

class HexMap {
    private:
        //  1. attributes
        AssetsManager* assets_manager_ptr; ///< A pointer to the assets manager.
        InputsHandler* inputs_handler_ptr; ///< A pointer to the inputs handler.
        MessagesHandler* messages_handler_ptr; ///< A pointer to the messages handler.
        sf::RenderWindow* render_window_ptr; ///< A pointer to the render window.
        
        
        //  2. methods
        void __layTiles(void);
        
        std::vector<double> __getNoise(int, int=64);
        
        void __procedurallyGenerateTileTypes(void);
        std::vector<double> __getValidMapIndexPositions(double, double);
        bool __isLakeTouchingOcean(HexTile*);
        void __enforceOceanContinuity(void);
        
        void __procedurallyGenerateTileResources(void);
        
        void __assembleHexMap(void);
    
    
    public:
        //  1. attributes
        int n_layers; ///< The number of layers in the hex map.
        int n_tiles; ///< The number of tiles in the hex map.
        int frame; ///< The current frame of this object.
        
        double position_x; ///< The x position of the hex map's origin (i.e. central) tile.
        double position_y; ///< The y position of the hex map's origin (i.e. central) tile.
        
        std::vector<double> tile_position_x_vec; ///< A vector of tile x positions.
        std::vector<double> tile_position_y_vec; ///< A vector of tile y position.
        std::vector<HexTile*> border_tiles_vec; ///< A vector of pointers to the border tiles.
        
        std::map<double, std::map<double, HexTile*>>  hex_map; ///< A position-indexed, nested map of hex tiles.
        
        
        //  2. methods
        HexMap(
            int,
            AssetsManager*,
            InputsHandler*,
            MessagesHandler*,
            sf::RenderWindow*
        );
        
        void process(void);
        void reroll(void);
        void toggleResourceOverlay(void);
        
        void draw(void);
        void clear(void);
        
        ~HexMap(void);
};


#endif  /* HEXMAP_H */
