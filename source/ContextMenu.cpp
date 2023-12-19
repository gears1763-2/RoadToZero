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


#include "../header/ContextMenu.h"


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
/// \fn void ContextMenu :: __setConsoleState(ConsoleState console_state)
///
/// \brief Helper method to set state of console screen and update string if necessary.
///
/// \param console_state The state (ConsoleState) to set the console to.
///

void ContextMenu :: __setConsoleState(ConsoleState console_state)
{
    //  1. if no change, do nothing
    if (this->console_state == console_state) {
        return;
    }
    
    //  2. update console state, set console string accordingly
    this->console_state = console_state;
    this->__setConsoleString();
    
    return;
}   /* __setConsoleState() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string ContextMenu :: __setConsoleString(void)
///
/// \brief Helper method to set console string depending on console state.
///

void ContextMenu :: __setConsoleString(void)
{
    this->console_string.clear();
    
    switch (this->console_state) {
        case (ConsoleState :: MENU): {
            //           32 char x 17 line console "--------------------------------\n";
            this->console_string                 = "         **** MENU ****         \n";
            this->console_string                += "                                \n";
            this->console_string                += "[R]:  RESTART                   \n";
            this->console_string                += "                                \n";
            this->console_string                += "[TAB]:  TOGGLE RESOURCE OVERLAY \n";
            this->console_string                += "[T]:  TUTORIAL                  \n";
            this->console_string                += "                                \n";
            this->console_string                += "                                \n";
            this->console_string                += "                                \n";
            this->console_string                += "                                \n";
            this->console_string                += "                                \n";
            this->console_string                += "                                \n";
            this->console_string                += "                                \n";
            this->console_string                += "[Q]:    QUIT                    \n";
            this->console_string                += "[ESC]:  CLOSE MENU              \n";
            this->console_string                += "                                \n";
            
            break;
        }
        
        
        case (ConsoleState :: TILE): {
            // take console string from tile state message
            
            break;
        }
        
        
        default: {
            //           32 char x 17 line console "--------------------------------\n";
            this->console_string                 = "  **** RTZ 64 CONTEXT V12 ****  \n";
            this->console_string                += "                                \n";
            this->console_string                += "64K RAM SYSTEM  38911 BYTES FREE\n";
            this->console_string                += "                                \n";
            this->console_string                += "[TAB]:  TOGGLE RESOURCE OVERLAY \n";
            this->console_string                += "                                \n";
            this->console_string                += "[ESC]:        MENU              \n";
            this->console_string                += "[LEFT CLICK]: TILE INFO/OPTIONS \n";
            this->console_string                += "                                \n";
            this->console_string                += "READY.                          ";
            
            break;
        }
    }
    
    return;
}   /* __setConsoleString() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __drawConsoleText(void)
///
/// \brief Helper method to draw animated text to context menu console screen.
///

void ContextMenu :: __drawConsoleText(void)
{
    //  1. set up console text (drawable)
    sf::Text console_text(
        this->console_string,
        *(this->assets_manager_ptr->getFont("Glass_TTY_VT220")),
        16
    );
    
    console_text.setFillColor(MONOCHROME_TEXT_GREEN);
        
    console_text.setPosition(
        this->position_x - 50 - 300 + 16,
        this->position_y + GAME_HEIGHT - 50 - 340 + 16
    );
    
    
    //  2. draw console text
    this->render_window_ptr->draw(console_text);
    
    
    //  3. assemble and draw blinking console cursor
    if ((this->frame % FRAMES_PER_SECOND) > FRAMES_PER_SECOND / 2) {
        sf::RectangleShape console_cursor(sf::Vector2f(10, 16));
    
        console_cursor.setFillColor(MONOCHROME_TEXT_GREEN);
        
        console_cursor.setPosition(
            console_text.getPosition().x,
            console_text.getPosition().y + console_text.getLocalBounds().height + 10
        );
        
        this->render_window_ptr->draw(console_cursor);
    }
    
    //  4. updating frame count if console is in menu state
    if (this->console_state == ConsoleState :: MENU) {
        std::string frame_count_string = "FRAME: ";
        frame_count_string += std::to_string(this->frame);
        
        sf::Text frame_count_text(
            frame_count_string,
            *(this->assets_manager_ptr->getFont("Glass_TTY_VT220")),
            16
        );
        
        frame_count_text.setFillColor(MONOCHROME_TEXT_GREEN);
        
        frame_count_text.setPosition(
            console_text.getPosition().x,
            console_text.getPosition().y + console_text.getLocalBounds().height - 10
        );
        
        this->render_window_ptr->draw(frame_count_text);
    }
    
    return;
}   /* __drawConsoleText() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __handleKeyPressEvents(void)
///
/// \brief Helper method to handle key press events.
///

void ContextMenu :: __handleKeyPressEvents(void)
{
    switch (this->event_ptr->key.code) {
        case (sf::Keyboard::Escape): {
            if (this->console_state == ConsoleState :: MENU) {
                this->__setConsoleState(ConsoleState :: READY);
            }
            
            else {
                this->__setConsoleState(ConsoleState :: MENU);
            }
            
            break;
        }
        
        
        case (sf::Keyboard::Q): {
            if (this->console_state == ConsoleState :: MENU) {
                this->__sendQuitGameMessage();
            }
        }
        
        
        case (sf::Keyboard::R): {
            if (this->console_state == ConsoleState :: MENU) {
                this->__sendRestartGameMessage();
            }
        }
        
        
        default: {
            // do nothing!
            
            break;
        }
    }

    return;
}   /* __handleKeyPressEvents() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn ContextMenu :: __handleMouseButtonEvents(void)
///
/// \brief Helper method to handle mouse button events.
///

void ContextMenu :: __handleMouseButtonEvents(void)
{
    switch (this->event_ptr->mouseButton.button) {
        case (sf::Mouse::Left): {
            //...
            
            break;
        }
        
        
        case (sf::Mouse::Right): {
            //...
            
            break;
        }
        
        
        default: {
            // do nothing!
            
            break;
        }
    }
    
    return;
}   /* __handleMouseButtonEvents() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __sendQuitGameMessage(void)
///
/// \brief Helper method to format and send a quit game message.
///

void ContextMenu :: __sendQuitGameMessage(void)
{
    Message quit_game_message;
    
    quit_game_message.channel = GAME_CHANNEL;
    quit_game_message.subject = "quit game";
    
    this->message_hub_ptr->sendMessage(quit_game_message);
    
    return;
}   /* __sendQuitGameMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: __sendRestartGameMessage(void)
///
/// \brief Helper method to format and send a restart game message.
///

void ContextMenu :: __sendRestartGameMessage(void)
{
    Message restart_game_message;
    
    restart_game_message.channel = GAME_CHANNEL;
    restart_game_message.subject = "restart game";
    
    this->message_hub_ptr->sendMessage(restart_game_message);
    
    return;
}   /* __sendRestartGameMessage() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn ContextMenu :: ContextMenu(
///         sf::Event* event_ptr,
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr,
///         MessageHub* message_hub_ptr
///     )
///
/// \brief Constructor for the ContextMenu class.
///
/// \param event_ptr Pointer to the event class.
///
/// \param render_window_ptr Pointer to the render window.
///
/// \param assets_manager_ptr Pointer to the assets manager.
///
/// \param message_hub_ptr Pointer to the message hub.
///

ContextMenu :: ContextMenu(
    sf::Event* event_ptr,
    sf::RenderWindow* render_window_ptr,
    AssetsManager* assets_manager_ptr,
    MessageHub* message_hub_ptr
)
{
    //  1. set attributes
    
    //  1.1. private
    this->event_ptr = event_ptr;
    this->render_window_ptr = render_window_ptr;
    
    this->assets_manager_ptr = assets_manager_ptr;
    this->message_hub_ptr = message_hub_ptr;
    
    //  1.2. public
    this->console_state = ConsoleState :: NONE_STATE;
    this->__setConsoleState(ConsoleState :: READY);
    
    this->game_menu_up = false;
    
    this->frame = 0;
    
    this->position_x = GAME_WIDTH;
    this->position_y = 0;
    
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

///
/// \fn void ContextMenu :: processEvent(void)
///
/// \brief Method to processEvent ContextMenu. To be called once per event.
///

void ContextMenu :: processEvent(void)
{
    if (this->event_ptr->type == sf::Event::KeyPressed) {
        this->__handleKeyPressEvents();
    }
    
    if (this->event_ptr->type == sf::Event::MouseButtonPressed) {
        this->__handleMouseButtonEvents();
    }
    
    return;
}   /* processEvent() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void ContextMenu :: processMessage(void)
///
/// \brief Method to processMessage ContextMenu. To be called once per message.
///

void ContextMenu :: processMessage(void)
{
    switch (this->console_state) {
        case (ConsoleState :: TILE): {
            //  process no tile selected
            if (not this->message_hub_ptr->isEmpty(NO_TILE_SELECTED_CHANNEL)) {
                Message no_tile_selected_message = this->message_hub_ptr->receiveMessage(
                    NO_TILE_SELECTED_CHANNEL
                );
                
                if (no_tile_selected_message.subject == "no tile selected") {
                    this->__setConsoleState(ConsoleState :: READY);
                    this->message_hub_ptr->popMessage(NO_TILE_SELECTED_CHANNEL);
                }
            }
            
            //  process tile state
            if (not this->message_hub_ptr->isEmpty(TILE_STATE_CHANNEL)) {
                Message tile_state_message = this->message_hub_ptr->receiveMessage(
                    TILE_STATE_CHANNEL
                );
                
                if (tile_state_message.subject == "tile state") {
                    this->console_string = tile_state_message.string_payload;
                    this->message_hub_ptr->popMessage(TILE_STATE_CHANNEL);
                }
            }
            
            //  process tile selected (subsequent left clicks causing program to hang)
            if (not this->message_hub_ptr->isEmpty(TILE_SELECTED_CHANNEL)) {
                this->message_hub_ptr->popMessage(TILE_SELECTED_CHANNEL);
            }
            
            break;
        }
        
        default: {
            //  process tile selected
            if (not this->message_hub_ptr->isEmpty(TILE_SELECTED_CHANNEL)) {
                Message tile_selected_message = this->message_hub_ptr->receiveMessage(
                    TILE_SELECTED_CHANNEL
                );
                
                if (tile_selected_message.subject == "tile selected") {
                    this->__setConsoleState(ConsoleState :: TILE);
                    this->message_hub_ptr->popMessage(TILE_SELECTED_CHANNEL);
                }
            }
            
            break;
        }
    }
    
    return;
}   /* processMessage() */

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
