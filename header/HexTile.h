/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Header file for the HexTile class.
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
/// \file HexTile.h
///
/// \brief Header file for the HexTile class.
///


#ifndef HEXTILE_H
#define HEXTILE_H


#include "DieselGenerator.h"
//#include "EnergyStorageSystem.h"
#include "Settlement.h"
#include "SolarPV.h"
#include "TidalTurbine.h"
#include "WaveEnergyConverter.h"
#include "WindTurbine.h"


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
        void __setUpMagnifyingGlassSprite(void);
        void __setUpTileExplosionReel(void);
        
        void __setUpBuildOption(std::string, std::string);
        void __setUpDieselGeneratorBuildOption(void);
        void __setUpWindTurbineBuildOption(bool=false, bool=false);
        void __setUpSolarPVBuildOption(bool=false);
        void __setUpTidalTurbineBuildOption(void);
        void __setUpWaveEnergyConverterBuildOption(void);
        void __setUpEnergyStorageSystemBuildOption(void);
        void __setUpBuildMenu(void);
        
        void __setIsSelected(bool);
        
        void __clearDecoration(void);
        
        bool __isClicked(void);
        
        void __handleKeyPressEvents(void);
        void __handleKeyReleaseEvents(void);
        void __handleMouseButtonEvents(void);
        
        void __openBuildMenu(void);
        void __closeBuildMenu(void);
        
        void __buildSettlement(void);
        void __buildDieselGenerator(void);
        void __buildSolarPV(void);
        void __buildWindTurbine(void);
        void __buildTidalTurbine(void);
        void __buildWaveEnergyConverter(void);
        void __buildEnergyStorage(void);
        
        void __scrapImprovement(void);
        
        void __sendTileSelectedMessage(void);
        
        std::string __getTileCoordsSubstring(void);
        std::string __getTileTypeSubstring(void);
        std::string __getTileResourceSubstring(void);
        std::string __getTileImprovementSubstring(void);
        std::string __getTileOptionsSubstring(void);
        void __sendTileStateMessage(void);
        void __sendAssessNeighboursMessage(void);
        
        void __sendGameStateRequest(void);
        void __sendUpdateGamePhaseMessage(std::string);
        
        void __sendCreditsSpentMessage(int);
        void __sendInsufficientCreditsMessage(void);
    
    
    public:
        //  1. attributes
        TileType tile_type; ///< The terrain type of the tile.
        TileResource tile_resource; ///< The renewable resource quality of the tile.
        
        bool show_node; ///< A boolean which indicates whether or not to show the tile node.
        bool show_resource; ///< A boolean which indicates whether or not to show resource value.
        bool resource_assessed; ///< A boolean which indicates whether or not the resource has been assessed.
        bool resource_assessment; ///< A boolean which triggers a resource assessment notification.
        bool is_selected; ///< A boolean which indicates whether or not the tile is selected.
        bool draw_explosion; ///< A boolean which indicates whether or not to draw a tile explosion.
        
        bool decoration_cleared; ///< A boolean which indicates if the tile decoration has been cleared.
        bool has_improvement; ///< A boolean which indicates if tile has improvement or not.
        TileImprovement* tile_improvement_ptr; ///< A pointer to the improvement for this tile.
        
        bool build_menu_open; ///< A boolean which indicates if the tile build menu is open.
        
        size_t explosion_frame; ///< The current frame of the explosion animation.
        
        unsigned long long int frame; ///< The current frame of this object.
        int credits; ///< The current balance of credits.
        int scrap_improvement_frame; ///< A frame for key-hold to confirm scrapping.
        
        double position_x; ///< The x position of the tile.
        double position_y; ///< The y position of the tile.
        
        double major_radius; ///< The radius of the smallest bounding circle.
        double minor_radius; ///< The radius of the largest inscribed circle.
        
        std::string game_phase; ///< The current phase of the game.
        
        sf::CircleShape node_sprite; ///< A circle shape to mark the tile node.
        sf::ConvexShape tile_sprite; ///< A convex shape which represents the tile.
        sf::ConvexShape select_outline_sprite; ///< A convex shape which outlines the tile when selected.
        sf::CircleShape resource_chip_sprite; ///< A circle shape which represents a resource chip.
        
        sf::Text resource_text; ///< A text representation of the resource.
        sf::Sprite tile_decoration_sprite; ///< A tile decoration sprite.
        sf::Sprite magnifying_glass_sprite; ///< A magnifying glass sprite.
        
        std::vector<sf::Sprite> explosion_sprite_reel; ///< A reel of sprites for a tile explosion animation.
        
        sf::RectangleShape build_menu_backing; ///< A backing for the tile build menu.
        sf::Text build_menu_backing_text; ///< A text label for the build menu.
        std::vector<std::vector<sf::Sprite>> build_menu_options_vec; ///< A vector of sprites for illustrating the tile build options.
        std::vector<sf::Text> build_menu_options_text_vec; ///< A vector of text for the tile build options.
        
        
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
