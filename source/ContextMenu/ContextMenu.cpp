/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the ContextMenu class.
 *
 */


///
/// \file ContextMenu.cpp
///
/// \brief Implementation file for the ContextMenu class.
///
/// A class which defines a context menu for the game.
///


#include "../../header/ContextMenu/ContextMenu.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __setUpMenuFrame(void)
///
/// \brief Helper method to set up context menu frame (drawable).
///

void ContextMenu :: __setUpMenuFrame(void)
{
    this->menu_frame.setSize(sf::Vector2f(400, GAME_HEIGHT));
    this->menu_frame.setOrigin(400, 0);
    this->menu_frame.setPosition(this->position_x, this->position_y);
    this->menu_frame.setFillColor(MENU_FRAME_GREY);
    
    return;
}   /* __setUpMenuFrame() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __setUpVisualScreen(void)
///
/// \brief Helper method to set up context menu visual screen (drawable).
///

void ContextMenu :: __setUpVisualScreen(void)
{
    this->visual_screen.setSize(sf::Vector2f(300, 300));
    this->visual_screen.setOrigin(300, 0);
    this->visual_screen.setPosition(this->position_x - 50, this->position_y + 50);
    this->visual_screen.setFillColor(MONOCHROME_SCREEN_BACKGROUND);
    
    return;
}   /* __setUpVisualScreen() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __setUpVisualScreenFrame(void)
///
/// \brief Helper method to set up framing for context menu visual screen (drawable).
///

void ContextMenu :: __setUpVisualScreenFrame(void)
{
    int n_points = 4;
    
    //  1. top framing
    this->visual_screen_frame_top.setPointCount(n_points);
    
    this->visual_screen_frame_top.setPoint(
        0,
        sf::Vector2f(this->position_x - 50, this->position_y + 50)
    );
    this->visual_screen_frame_top.setPoint(
        1,
        sf::Vector2f(this->position_x - 50 + 16, this->position_y + 50 - 16)
    );
    this->visual_screen_frame_top.setPoint(
        2,
        sf::Vector2f(this->position_x - 350 - 16, this->position_y + 50 - 16)
    );
    this->visual_screen_frame_top.setPoint(
        3,
        sf::Vector2f(this->position_x - 350, this->position_y + 50)
    );
    
    this->visual_screen_frame_top.setFillColor(VISUAL_SCREEN_FRAME_GREY);
    
    this->visual_screen_frame_top.setOutlineThickness(2);
    this->visual_screen_frame_top.setOutlineColor(sf::Color(0, 0, 0, 255));
    
    this->visual_screen_frame_top.move(0, -2);
    
    
    //  2. left framing
    this->visual_screen_frame_left.setPointCount(n_points);
    
    this->visual_screen_frame_left.setPoint(
        0,
        sf::Vector2f(this->position_x - 350, this->position_y + 50)
    );
    this->visual_screen_frame_left.setPoint(
        1,
        sf::Vector2f(this->position_x - 350 - 16, this->position_y + 50 - 16)
    );
    this->visual_screen_frame_left.setPoint(
        2,
        sf::Vector2f(this->position_x - 350 - 16, this->position_y + 350 + 16)
    );
    this->visual_screen_frame_left.setPoint(
        3,
        sf::Vector2f(this->position_x - 350, this->position_y + 350)
    );
    
    this->visual_screen_frame_left.setFillColor(VISUAL_SCREEN_FRAME_GREY);
    
    this->visual_screen_frame_left.setOutlineThickness(2);
    this->visual_screen_frame_left.setOutlineColor(sf::Color(0, 0, 0, 255));
    
    this->visual_screen_frame_left.move(-2, 0);
    
    
    //  3. bottom framing
    this->visual_screen_frame_bottom.setPointCount(n_points);
    
    this->visual_screen_frame_bottom.setPoint(
        0,
        sf::Vector2f(this->position_x - 350, this->position_y + 350)
    );
    this->visual_screen_frame_bottom.setPoint(
        1,
        sf::Vector2f(this->position_x - 350 - 16, this->position_y + 350 + 16)
    );
    this->visual_screen_frame_bottom.setPoint(
        2,
        sf::Vector2f(this->position_x - 50 + 16, this->position_y + 350 + 16)
    );
    this->visual_screen_frame_bottom.setPoint(
        3,
        sf::Vector2f(this->position_x - 50, this->position_y + 350)
    );
    
    this->visual_screen_frame_bottom.setFillColor(VISUAL_SCREEN_FRAME_GREY);
    
    this->visual_screen_frame_bottom.setOutlineThickness(2);
    this->visual_screen_frame_bottom.setOutlineColor(sf::Color(0, 0, 0, 255));
    
    this->visual_screen_frame_bottom.move(0, 2);
    
    
    //  4. right framing
    this->visual_screen_frame_right.setPointCount(n_points);
    
    this->visual_screen_frame_right.setPoint(
        0,
        sf::Vector2f(this->position_x - 50, this->position_y + 350)
    );
    this->visual_screen_frame_right.setPoint(
        1,
        sf::Vector2f(this->position_x - 50 + 16, this->position_y + 350 + 16)
    );
    this->visual_screen_frame_right.setPoint(
        2,
        sf::Vector2f(this->position_x - 50 + 16, this->position_y + 50 - 16)
    );
    this->visual_screen_frame_right.setPoint(
        3,
        sf::Vector2f(this->position_x - 50, this->position_y + 50)
    );
    
    this->visual_screen_frame_right.setFillColor(VISUAL_SCREEN_FRAME_GREY);
    
    this->visual_screen_frame_right.setOutlineThickness(2);
    this->visual_screen_frame_right.setOutlineColor(sf::Color(0, 0, 0, 255));
    
    this->visual_screen_frame_right.move(2, 0);
    
    return;
}   /* __setUpVisualScreenFrame() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __drawVisualScreenFrame(void)
///
/// \brief Helper method to draw visual screen frame.
///

void ContextMenu :: __drawVisualScreenFrame(void)
{
    this->render_window_ptr->draw(this->visual_screen_frame_top);
    this->render_window_ptr->draw(this->visual_screen_frame_left);
    this->render_window_ptr->draw(this->visual_screen_frame_bottom);
    this->render_window_ptr->draw(this->visual_screen_frame_right);
    
    return;
}   /* __drawVisualScreenFrame() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __setUpConsoleScreen(void)
///
/// \brief Helper method to set up context menu console screen (drawable).
///

void ContextMenu :: __setUpConsoleScreen(void)
{
    this->console_screen.setSize(sf::Vector2f(300, 340));
    this->console_screen.setOrigin(300, 340);
    this->console_screen.setPosition(
        this->position_x - 50,
        this->position_y + GAME_HEIGHT - 50
    );
    this->console_screen.setFillColor(MONOCHROME_SCREEN_BACKGROUND);
    
    return;
}   /* __setUpConsoleScreen() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __setUpConsoleScreenFrame(void)
///
/// \brief Helper method to set up framing for context menu console screen (drawable).
///

void ContextMenu :: __setUpConsoleScreenFrame(void)
{
    int n_points = 4;
    
    //  1. top framing
    this->console_screen_frame_top.setPointCount(n_points);
    
    this->console_screen_frame_top.setPoint(
        0,
        sf::Vector2f(
            this->position_x - 50,
            this->position_y + GAME_HEIGHT - 50 - 340
        )
    );
    this->console_screen_frame_top.setPoint(
        1,
        sf::Vector2f(
            this->position_x - 50 + 16,
            this->position_y + GAME_HEIGHT - 50 - 340 - 16
        )
    );
    this->console_screen_frame_top.setPoint(
        2,
        sf::Vector2f(
            this->position_x - 350 - 16,
            this->position_y + GAME_HEIGHT - 50 - 340 - 16
        )
    );
    this->console_screen_frame_top.setPoint(
        3,
        sf::Vector2f(
            this->position_x - 350,
            this->position_y + GAME_HEIGHT - 50 - 340
        )
    );
    
    this->console_screen_frame_top.setFillColor(VISUAL_SCREEN_FRAME_GREY);
    
    this->console_screen_frame_top.setOutlineThickness(2);
    this->console_screen_frame_top.setOutlineColor(sf::Color(0, 0, 0, 255));
    
    this->console_screen_frame_top.move(0, -2);
    
    
    //  2. left framing
    this->console_screen_frame_left.setPointCount(n_points);
    
    this->console_screen_frame_left.setPoint(
        0,
        sf::Vector2f(
            this->position_x - 350,
            this->position_y + GAME_HEIGHT - 50 - 340
        )
    );
    this->console_screen_frame_left.setPoint(
        1,
        sf::Vector2f(
            this->position_x - 350 - 16,
            this->position_y + GAME_HEIGHT - 50 - 340 - 16
        )
    );
    this->console_screen_frame_left.setPoint(
        2,
        sf::Vector2f(
            this->position_x - 350 - 16,
            this->position_y + GAME_HEIGHT - 50 + 16
        )
    );
    this->console_screen_frame_left.setPoint(
        3,
        sf::Vector2f(
            this->position_x - 350,
            this->position_y + GAME_HEIGHT - 50
        )
    );
    
    this->console_screen_frame_left.setFillColor(VISUAL_SCREEN_FRAME_GREY);
    
    this->console_screen_frame_left.setOutlineThickness(2);
    this->console_screen_frame_left.setOutlineColor(sf::Color(0, 0, 0, 255));
    
    this->console_screen_frame_left.move(-2, 0);
    
    
    //  3. bottom framing
    this->console_screen_frame_bottom.setPointCount(n_points);
    
    this->console_screen_frame_bottom.setPoint(
        0,
        sf::Vector2f(
            this->position_x - 350,
            this->position_y + GAME_HEIGHT - 50
        )
    );
    this->console_screen_frame_bottom.setPoint(
        1,
        sf::Vector2f(
            this->position_x - 350 - 16,
            this->position_y + GAME_HEIGHT - 50 + 16
        )
    );
    this->console_screen_frame_bottom.setPoint(
        2,
        sf::Vector2f(
            this->position_x - 50 + 16,
            this->position_y + GAME_HEIGHT - 50 + 16
        )
    );
    this->console_screen_frame_bottom.setPoint(
        3,
        sf::Vector2f(
            this->position_x - 50,
            this->position_y + GAME_HEIGHT - 50
        )
    );
    
    this->console_screen_frame_bottom.setFillColor(VISUAL_SCREEN_FRAME_GREY);
    
    this->console_screen_frame_bottom.setOutlineThickness(2);
    this->console_screen_frame_bottom.setOutlineColor(sf::Color(0, 0, 0, 255));
    
    this->console_screen_frame_bottom.move(0, 2);
    
    
    //  4. right framing
    this->console_screen_frame_right.setPointCount(n_points);
    
    this->console_screen_frame_right.setPoint(
        0,
        sf::Vector2f(
            this->position_x - 50,
            this->position_y + GAME_HEIGHT - 50
        )
    );
    this->console_screen_frame_right.setPoint(
        1,
        sf::Vector2f(
            this->position_x - 50 + 16,
            this->position_y + GAME_HEIGHT - 50 + 16
        )
    );
    this->console_screen_frame_right.setPoint(
        2,
        sf::Vector2f(
            this->position_x - 50 + 16,
            this->position_y + GAME_HEIGHT - 50 - 340 - 16
        )
    );
    this->console_screen_frame_right.setPoint(
        3,
        sf::Vector2f(
            this->position_x - 50,
            this->position_y + GAME_HEIGHT - 50 - 340
        )
    );
    
    this->console_screen_frame_right.setFillColor(VISUAL_SCREEN_FRAME_GREY);
    
    this->console_screen_frame_right.setOutlineThickness(2);
    this->console_screen_frame_right.setOutlineColor(sf::Color(0, 0, 0, 255));
    
    this->console_screen_frame_right.move(2, 0);
    
    return;
}   /* __setUpConsoleScreenFrame() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __drawConsoleScreenFrame(void)
///
/// \brief Helper method to draw console screen frame.
///

void ContextMenu :: __drawConsoleScreenFrame(void)
{
    this->render_window_ptr->draw(this->console_screen_frame_top);
    this->render_window_ptr->draw(this->console_screen_frame_left);
    this->render_window_ptr->draw(this->console_screen_frame_bottom);
    this->render_window_ptr->draw(this->console_screen_frame_right);
    
    return;
}   /* __drawContextScreenFrame() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __drawConsoleText(void)
///
/// \brief Helper method to draw animated text to context menu console screen.
///

void ContextMenu :: __drawConsoleText(void)
{
    //  1. init console text
    sf::Text console_text;
    
    if (this->console_message.empty()) {
        
        //              32 char x 16 line console "--------------------------------\n";
        std::string console_string              = "  **** RTZ 64 CONTEXT V12 ****  \n";
        console_string                         += "                                \n";
        console_string                         += "64K RAM SYSTEM  38911 BYTES FREE\n";
        console_string                         += "                                \n";
        console_string                         += "[ESC]:             MENU         \n";
        console_string                         += "[LEFT CLICK TILE]: TILE OPTIONS \n";
        console_string                         += "                                \n";
        console_string                         += "READY                           ";
        
        console_text.setString(console_string);
    }
    
    else {
        
        //              32 char x 16 line console "--------------------------------\n";
        std::string console_string = this->console_message;
        console_string                         += "\nFRAME: ";
        console_string                         += std::to_string(this->frame);
        
        console_text.setString(console_string);
    }
    
    
    //  2. set console text font, size, colour, and position
    console_text.setFont(*(assets_manager_ptr->getFont("Glass_TTY_VT220")));
    console_text.setCharacterSize(16);
        
    console_text.setFillColor(MONOCHROME_TEXT_GREEN);
        
    console_text.setPosition(
        this->position_x - 50 - 300 + 16,
        this->position_y + GAME_HEIGHT - 50 - 340 + 16
    );
    
    
    //  3. draw console text
    this->render_window_ptr->draw(console_text);
    
    
    //  4. assemble and draw blinking console cursor
    if ((this->frame % FRAMES_PER_SECOND) > FRAMES_PER_SECOND / 2) {
        sf::RectangleShape console_cursor(sf::Vector2f(10, 16));
    
        console_cursor.setFillColor(MONOCHROME_TEXT_GREEN);
        
        console_cursor.setPosition(
            console_text.getPosition().x,
            console_text.getPosition().y + console_text.getLocalBounds().height + 10
        );
        
        this->render_window_ptr->draw(console_cursor);
    }
    
    return;
}   /* __drawConsoleText() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn ContextMenu :: ContextMenu(
///         AssetsManager* assets_manager_ptr,
///         InputsHandler* inputs_handler_ptr,
///         MessagesHandler* messages_handler_ptr,
///         sf::RenderWindow* render_window_ptr
///     )
///
/// \brief Constructor for the ContextMenu class.
///
/// \param assets_manager_ptr Pointer to the assets manager.
///
/// \param inputs_handler_ptr Pointer to the inputs handler.
///
/// \param messages_handler_ptr Pointer to the messages handler.
///
/// \param render_window_ptr Pointer to the render window.
///

ContextMenu :: ContextMenu(
    AssetsManager* assets_manager_ptr,
    InputsHandler* inputs_handler_ptr,
    MessagesHandler* messages_handler_ptr,
    sf::RenderWindow* render_window_ptr
)
{
    //  1. set attributes
    this->assets_manager_ptr = assets_manager_ptr;
    this->inputs_handler_ptr = inputs_handler_ptr;
    this->messages_handler_ptr = messages_handler_ptr;
    this->render_window_ptr = render_window_ptr;
    
    this->game_menu_up = false;
    
    this->frame = 0;
    
    this->position_x = GAME_WIDTH;
    this->position_y = 0;
    
    this->console_message = "";
    
    //  2. set up and position drawable attributes
    this->__setUpMenuFrame();
    this->__setUpVisualScreen();
    this->__setUpVisualScreenFrame();
    this->__setUpConsoleScreen();
    this->__setUpConsoleScreenFrame();
    
    std::cout << "ContextMenu constructed at " << this << std::endl;
    
    return;
}   /* ContextMenu() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

//...

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: process(void)
///
/// \brief Method to process ContextMenu. To be called once per frame.
///

void ContextMenu :: process(void)
{
    //  1. handle inputs
    if (this->inputs_handler_ptr->key_pressed_once_vec[sf::Keyboard::Escape]) {
        if (not this->game_menu_up) {
            this->game_menu_up = true;
        
            //              32 char x 16 line console "--------------------------------\n";
            std::string game_menu_string            = "         **** MENU ****         \n";
            game_menu_string                       += "                                \n";
            game_menu_string                       += "[T]:  TUTORIAL                  \n";
            game_menu_string                       += "                                \n";
            game_menu_string                       += "[R]:  RESTART                   \n";
            game_menu_string                       += "                                \n";
            game_menu_string                       += "                                \n";
            game_menu_string                       += "                                \n";
            game_menu_string                       += "                                \n";
            game_menu_string                       += "                                \n";
            game_menu_string                       += "                                \n";
            game_menu_string                       += "                                \n";
            game_menu_string                       += "[Q]:    QUIT                    \n";
            game_menu_string                       += "                                \n";
            game_menu_string                       += "[ESC]:  CLOSE MENU              \n";
            
            this->console_message = game_menu_string;
        }
        
        else {
            this->game_menu_up = false;
            this->console_message.clear();
        }
    }
    
    if (this->inputs_handler_ptr->key_pressed_once_vec[sf::Keyboard::Q]) {
        if (this->game_menu_up) {
            this->render_window_ptr->close();
        }
    }
    
    if (this->inputs_handler_ptr->mouse_right_click) {
        this->game_menu_up = false;
        this->console_message.clear();
    }
    
    return;
}   /* process() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: draw(void)
///
/// \brief Method to draw the hex tile to the render window. To be called once per 
///     frame.
///

void ContextMenu :: draw(void)
{
    //  1. menu frame
    this->render_window_ptr->draw(this->menu_frame);
    
    //  2. visual screen
    this->render_window_ptr->draw(this->visual_screen);
    this->__drawVisualScreenFrame();
    
    //  3. console screen
    this->render_window_ptr->draw(this->console_screen);
    this->__drawConsoleScreenFrame();
    this->__drawConsoleText();
    
    this->frame++;
    return;
}   /* draw() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn ContextMenu :: ~ContextMenu(void)
///
/// \brief Destructor for the ContextMenu class.
///

ContextMenu :: ~ContextMenu(void)
{
    std::cout << "ContextMenu at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~ContextMenu() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
