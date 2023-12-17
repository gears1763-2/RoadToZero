/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the ContextMenu class.
 *
 */


///
/// \file ContextMenu.h
///
/// \brief Header file for the ContextMenu class.
///


#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H


#include "../ESC_core/constants.h"
#include "../ESC_core/includes.h"
#include "../ESC_core/AssetsManager.h"
#include "../ESC_core/InputsHandler.h"
#include "../ESC_core/MessagesHandler.h"


///
/// \class ContextMenu
///
/// \brief A class which defines a context menu for the game.
///

class ContextMenu {
    private:
        //  1. attributes
        AssetsManager* assets_manager_ptr; ///< A pointer to the assets manager.
        InputsHandler* inputs_handler_ptr; ///< A pointer to the inputs handler.
        MessagesHandler* messages_handler_ptr; ///< A pointer to the messages handler.
        sf::RenderWindow* render_window_ptr; ///< A pointer to the render window.
        
        
        //  2. methods
        void __setUpMenuFrame(void);
        
        void __setUpVisualScreen(void);
        void __setUpVisualScreenFrame(void);
        void __drawVisualScreenFrame(void);
        
        void __setUpConsoleScreen(void);
        void __setUpConsoleScreenFrame(void);
        void __drawConsoleScreenFrame(void);
        void __drawConsoleText(void);
    
    
    public:
        //  1. attributes
        bool game_menu_up; ///< Indicates whether or not the game menu is up.
        
        int frame; ///< The current frame of this object.
        
        double position_x; ///< The position of the object.
        double position_y; ///< The position of the object.
        
        std::string console_message; ///< The message to be printed to the console screen.
        
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
            AssetsManager*,
            InputsHandler*,
            MessagesHandler*,
            sf::RenderWindow*
        );
        
        void process(void);
        void draw(void);
        
        ~ContextMenu(void);
};


#endif  /* CONTEXTMENU_H */
