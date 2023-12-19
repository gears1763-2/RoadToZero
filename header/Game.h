/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the Game class.
 *
 */


///
/// \file HexTile.h
///
/// \brief Header file for the Game class.
///


#ifndef GAME_H
#define GAME_H


#include "HexMap.h"
#include "ContextMenu.h"


///
/// \class Game
///
/// \brief A class which acts as the central class for the game, by containing all other
///     classes and implementing the game loop.
///

class Game {
    private:
        //  1. attributes
        sf::RenderWindow* render_window_ptr; ///< A pointer to the render window.
        
        AssetsManager* assets_manager_ptr; ///< A pointer to the assets manager.
        
        
        //  2. methods
        void __toggleFrameClockOverlay(void);
        void __drawFrameClockOverlay(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
        
        void __processEvent(void);
        void __processMessage(void);
        
        void __draw(void);
    
    
    public:
        //  1. attributes
        bool quit_game; ///< Boolean indicating whether to quit (true) or create a new Game instance (false).
        bool game_loop_broken; ///< Boolean indicating whether or not the game loop is broken.
        bool show_frame_clock_overlay; ///< Boolean indicating whether or not to show frame and clock overlay.
        
        unsigned long long int frame; ///< The current frame of the game.
        double time_since_start_s; ///< The time elapsed [s] since the start of the game.
        
        sf::Clock clock; ///< The game clock.
        sf::Event event; ///< The game events class.
        
        MessageHub message_hub; ///< The message hub (for inter-object message traffic).
        
        HexMap* hex_map_ptr; ///< Pointer to the hex map (defines game world).
        ContextMenu* context_menu_ptr; ///< Pointer to the context menu.
        
        
        //  2. methods
        Game(sf::RenderWindow*, AssetsManager*);
        
        bool run(void);
        
        ~Game(void);
        
}; /* Game */


#endif  /* GAME_H */
