/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the ContextMenu class.
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
/// \file ContextMenu.h
///
/// \brief Header file for the ContextMenu class.
///


#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H


#include "ESC_core/constants.h"
#include "ESC_core/includes.h"
#include "ESC_core/AssetsManager.h"
#include "ESC_core/MessageHub.h"


///
/// \enum ConsoleState
///
/// \brief An enumeration of the different console screen states
///

enum ConsoleState {
    NONE_STATE, ///< None state (for initialization)
    READY, ///< Ready (default) state.
    MENU, ///< Game menu state.
    TILE, ///< Tile context state.
    N_CONSOLE_STATES ///< A simple hack to get the number of console screen states.
};


///
/// \class ContextMenu
///
/// \brief A class which defines a context menu for the game.
///

class ContextMenu {
    private:
        //  1. attributes
        sf::Event* event_ptr; ///< A pointer to the event class.
        sf::RenderWindow* render_window_ptr; ///< A pointer to the render window.
        
        AssetsManager* assets_manager_ptr; ///< A pointer to the assets manager.
        MessageHub* message_hub_ptr; ///< A pointer to the message hub.
        
        
        //  2. methods
        void __setUpMenuFrame(void);
        
        void __setUpVisualScreen(void);
        void __setUpVisualScreenFrame(void);
        void __drawVisualScreenFrame(void);
        
        void __setUpConsoleScreen(void);
        void __setUpConsoleScreenFrame(void);
        void __drawConsoleScreenFrame(void);
        
        void __setConsoleState(ConsoleState);
        void __setConsoleString(void);
        
        void __drawConsoleText(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
        
        void __sendQuitGameMessage(void);
        void __sendRestartGameMessage(void);
    
    
    public:
        //  1. attributes
        ConsoleState console_state; ///< The current state of the console screen.
        
        bool console_string_changed; ///< Boolean which indicates if console string just changed.
        bool game_menu_up; ///< Indicates whether or not the game menu is up.
        
        size_t console_substring_idx; ///< The current final index of the console string draw.
        
        unsigned long long int frame; ///< The current frame of this object.
        
        double position_x; ///< The position of the object.
        double position_y; ///< The position of the object.
        
        std::string console_string; ///< The string to be printed to the console screen.
        
        sf::RectangleShape menu_frame; ///< The frame of the context menu.
        
        sf::RectangleShape visual_screen; ///< The context menu screen for visuals.
        sf::ConvexShape visual_screen_frame_top; ///< The top framing of the visual screen.
        sf::ConvexShape visual_screen_frame_left; ///< The left framing of the visual screen.
        sf::ConvexShape visual_screen_frame_bottom; ///< The bottom framing of the visual screen.
        sf::ConvexShape visual_screen_frame_right; ///< The right framing of the visual screen.
        
        sf::RectangleShape console_screen; ///< The context menu console screen (for animated text output).
        sf::ConvexShape console_screen_frame_top; ///< The top framing of the console screen.
        sf::ConvexShape console_screen_frame_left; ///< The left framing of the console screen.
        sf::ConvexShape console_screen_frame_bottom; ///< The bottom framing of the console screen.
        sf::ConvexShape console_screen_frame_right; ///< The right framing of the console screen.
        
        
        //  2. methods
        ContextMenu(
            sf::Event*,
            sf::RenderWindow*,
            AssetsManager*,
            MessageHub*
        );
        
        void processEvent(void);
        void processMessage(void);
        
        void draw(void);
        
        ~ContextMenu(void);
};


#endif  /* CONTEXTMENU_H */
