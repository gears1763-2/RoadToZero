/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Header file for the HexMap class.
 *
 */


/*
 *   **** 3-Clause BSD License ****
 *   ref: https://opensource.org/license/bsd-3-clause/
 *
 *
 *   Copyright 2023 - [ESC] Interactive (Anthony Truelove MASc, P.Eng.)
 *
 *   Redistribution and use in source and binary forms, with or without modification, are
 *   permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list of
 *   conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this list
 *   of conditions and the following disclaimer in the documentation and/or other materials
 *   provided with the distribution.
 *
 *   3. Neither the name of the copyright holder nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without specific prior
 *   written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY
 *   EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 *   THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 *   OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 *   TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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


///
/// \class HexMap
///
/// \brief A class which defines a hex map of hex tiles.
///

class HexMap {
    private:
        //  1. attributes
        sf::Event* event_ptr; ///< A pointer to the event class.
        sf::RenderWindow* render_window_ptr; ///< A pointer to the render window.
        
        AssetsManager* assets_manager_ptr; ///< A pointer to the assets manager.
        MessageHub* message_hub_ptr; ///< A pointer to the message hub.
        
        
        //  2. methods
        void __setUpGlassScreen(void);
        
        void __layTiles(void);
        void __buildDrawOrderVector(void);
        
        std::vector<double> __getNoise(int, int=128);
        
        void __procedurallyGenerateTileTypes(void);
        std::vector<double> __getValidMapIndexPositions(double, double);
        std::vector<HexTile*> __getNeighboursVector(HexTile*);
        TileType __getMajorityTileType(HexTile*);
        void __smoothTileTypes(void);
        bool __isLakeTouchingOcean(HexTile*);
        void __enforceOceanContinuity(void);
        
        void __procedurallyGenerateTileResources(void);
        
        void __assembleHexMap(void);
        
        HexTile* __getSelectedTile(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
        
        void __sendNoTileSelectedMessage(void);
        
        void __assessNeighbours(HexTile*);
    
    
    public:
        //  1. attributes
        bool show_resource; ///< A boolean which indicates whether or not to show resource value.
        bool tile_selected; ///< A boolean which indicates if a tile is currently selected.
        
        int n_layers; ///< The number of layers in the hex map.
        int n_tiles; ///< The number of tiles in the hex map.
        unsigned long long int frame; ///< The current frame of this object.
        
        double position_x; ///< The x position of the hex map's origin (i.e. central) tile.
        double position_y; ///< The y position of the hex map's origin (i.e. central) tile.
        
        sf::RectangleShape glass_screen; ///< To give the effect of an old glass screen over the hex map.
        
        std::vector<double> tile_position_x_vec; ///< A vector of tile x positions.
        std::vector<double> tile_position_y_vec; ///< A vector of tile y position.
        std::vector<HexTile*> border_tiles_vec; ///< A vector of pointers to the border tiles.
        
        std::map<double, std::map<double, HexTile*>>  hex_map; ///< A position-indexed, nested map of hex tiles.
        std::vector<HexTile*> hex_draw_order_vec; ///< A vector of hex tiles, in drawing order.
        
        
        //  2. methods
        HexMap(
            int,
            sf::Event*,
            sf::RenderWindow*,
            AssetsManager*,
            MessageHub*
        );
        
        void assess(void);
        
        void reroll(void);
        void toggleResourceOverlay(void);
        
        void processEvent(void);
        void processMessage(void);
        
        void draw(void);
        
        void clear(void);
        ~HexMap(void);
};  /* HexMap */


#endif  /* HEXMAP_H */
