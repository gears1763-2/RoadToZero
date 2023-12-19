/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the Game class.
 *
 */


///
/// \file Game.cpp
///
/// \brief Implementation file for the Game class.
///
/// A class which defines a tile of a hex map.
///


#include "../header/Game.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __toggleFrameClockOverlay(void)
///
/// \brief Helper method to toggle frame clock overlay.
///

void Game :: __toggleFrameClockOverlay(void)
{
    if (this->show_frame_clock_overlay) {
        this->show_frame_clock_overlay = false;
    }
    
    else {
        this->show_frame_clock_overlay = true;
    }
    
    return;
}   /* __toggleFrameClockOverlay() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __handleKeyPressEvents(void)
///
/// \brief Helper method to handle key press events.
///

void Game :: __handleKeyPressEvents(void)
{
    switch (this->event.key.code) {
        case (sf::Keyboard::Tilde): {
            this->__toggleFrameClockOverlay();
            
            break;
        }
        
        
        case (sf::Keyboard::Tab): {
            this->hex_map_ptr->toggleResourceOverlay();
            
            break;
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
/// \fn Game :: __handleMouseButtonEvents(void)
///
/// \brief Helper method to handle mouse button events.
///

void Game :: __handleMouseButtonEvents(void)
{
    switch (this->event.mouseButton.button) {
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
/// \fn void Game :: __processEvent(void)
///
/// \brief Helper method to process Game. To be called once per event.
///

void Game :: __processEvent(void)
{
    if (this->event.type == sf::Event::Closed) {
        this->quit_game = true;
        this->game_loop_broken = true;
    }
    
    if (this->event.type == sf::Event::KeyPressed) {
        this->__handleKeyPressEvents();
    }
    
    if (this->event.type == sf::Event::MouseButtonPressed) {
        this->__handleMouseButtonEvents();
    }
    
    return;
}   /* __processEvent() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __processMessage(void)
///
/// \brief Helper method to process Game. To be called once per message.
///

void Game :: __processMessage(void)
{
    if (not this->message_hub.isEmpty(GAME_CHANNEL)) {
        Message game_channel_message = this->message_hub.receiveMessage(GAME_CHANNEL);
        
        if (game_channel_message.subject == "quit game") {
            this->quit_game = true;
            this->game_loop_broken = true;
            this->message_hub.popMessage(GAME_CHANNEL);
        }
        
        if (game_channel_message.subject == "restart game") {
            this->game_loop_broken = true;
            this->message_hub.popMessage(GAME_CHANNEL);
        }
    }
    
    return;
}   /* __processMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __drawFrameClockOverlay(void)
///
/// \brief Helper method to draw frame clock overlay.
///

void Game :: __drawFrameClockOverlay(void)
{
    std::string frame_clock_string = "FRAME: ";
    frame_clock_string += std::to_string(this->frame);
    frame_clock_string += "\nTIME SINCE START [s]: ";
    frame_clock_string += std::to_string(this->time_since_start_s);
    
    sf::Text frame_clock_text(
        frame_clock_string,
        *(this->assets_manager_ptr->getFont("DroidSansMono")),
        16
    );
    
    sf::RectangleShape frame_clock_backing(
        sf::Vector2f(
            1.02 * frame_clock_text.getLocalBounds().width,
            1.20 * frame_clock_text.getLocalBounds().height
        )
    );
    frame_clock_backing.setFillColor(sf::Color(0, 0, 0, 255));
    
    this->render_window_ptr->draw(frame_clock_backing);
    this->render_window_ptr->draw(frame_clock_text);
    
    return;
}   /* __drawFrameClockOverlay() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __drawHUD(void)
///
/// \brief Helper method to heads-up display (HUD).
///

void Game :: __drawHUD(void)
{
    //  1. first line
    std::string HUD_string = "YEAR: ";
    HUD_string += std::to_string(this->year);
    
    HUD_string += "    MONTH: ";
    HUD_string += std::to_string(this->month);
    
    HUD_string += "    POPULATION: ";
    HUD_string += std::to_string(this->population);
    
    HUD_string += "    CREDITS: ";
    HUD_string += std::to_string(this->credits);
    HUD_string += " K";
    
    HUD_string += "    CURRENT DEMAND: ";
    HUD_string += std::to_string(this->demand_MWh);
    HUD_string += " MWh";
    
    sf::Text HUD_text(
        HUD_string,
        *(this->assets_manager_ptr->getFont("Glass_TTY_VT220")),
        16
    );
    
    HUD_text.setPosition(
        (800 - HUD_text.getLocalBounds().width) / 2,
        8
    );
    
    HUD_text.setFillColor(MONOCHROME_TEXT_GREEN);
    
    this->render_window_ptr->draw(HUD_text);
    
    
    //  2. second line
    HUD_string = "CUMULATIVE EMISSIONS: ";
    HUD_string += std::to_string(this->cumulative_emissions_tonnes);
    HUD_string += " tonnes (CO2e)";
    
    HUD_string += "    LIFETIME LIMIT: ";
    HUD_string += std::to_string(EMISSIONS_LIFETIME_LIMIT_TONNES);
    HUD_string += " tonnes (CO2e)";
    
    HUD_text.setString(HUD_string);
    
    HUD_text.setPosition(
        (800 - HUD_text.getLocalBounds().width) / 2,
        35
    );
    
    this->render_window_ptr->draw(HUD_text);
    
    return;
}   /* __drawHUD() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __draw(void)
///
/// \brief Helper method to draw game to the render window. To be called once per frame.
///

void Game :: __draw(void)
{
    this->__drawHUD();
    
    if (this->show_frame_clock_overlay) {
        this->__drawFrameClockOverlay();
    }
    
    return;
}   /* draw() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn Game :: Game(
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr
///     )
///
/// \brief Constructor for the Game class.
///

Game :: Game(
    sf::RenderWindow* render_window_ptr,
    AssetsManager* assets_manager_ptr
)
{
    //  1. set attributes
    
    //  1.1. private
    this->render_window_ptr = render_window_ptr;
    
    this->assets_manager_ptr = assets_manager_ptr;
    
    //  1.2. public
    this->quit_game = false;
    this->game_loop_broken = false;
    this->show_frame_clock_overlay = false;
    
    this->frame = 0;
    this->time_since_start_s = 0;
    
    double seconds_since_epoch = time(NULL);
    double years_since_epoch = seconds_since_epoch / SECONDS_PER_YEAR;
    
    this->year = 1970 + (int)years_since_epoch;
    this->month = (years_since_epoch - (int)years_since_epoch) * 12 + 1;
    
    this->population = 0;
    this->credits = 0;
    this->demand_MWh = 0;
    this->cumulative_emissions_tonnes = 0;

    this->hex_map_ptr = new HexMap(
        6,
        &(this->event),
        this->render_window_ptr,
        this->assets_manager_ptr,
        &(this->message_hub)
    );
    
    this->context_menu_ptr = new ContextMenu(
        &(this->event),
        this->render_window_ptr,
        this->assets_manager_ptr,
        &(this->message_hub)
    );
    
    //  2. add message channel(s)
    this->message_hub.addChannel(GAME_CHANNEL);
    
    std::cout << "Game constructed at " << this << std::endl;
    
    return;
}   /* Game() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn bool Game :: run(void)
///
/// \brief Method to run game (defines game loop).
///
/// \return Boolean indicating whether to quit (true) or create a new Game instance
///     (false).
///

bool Game :: run(void)
{
    //  1. play brand animation
    //...
    
    //  2. show splash screen
    //...
    
    //  3. start game loop
    while (not this->game_loop_broken) {
        this->time_since_start_s = this->clock.getElapsedTime().asSeconds();
        
        if (this->time_since_start_s >= (this->frame + 1) * SECONDS_PER_FRAME) {
            //  6.1. process events
            while (this->render_window_ptr->pollEvent(this->event)) {
                this->hex_map_ptr->processEvent();
                this->context_menu_ptr->processEvent();
                this->__processEvent();
            }
            
            
            //  6.2. process messages
            while (this->message_hub.hasTraffic()) {
                this->hex_map_ptr->processMessage();
                this->context_menu_ptr->processMessage();
                this->__processMessage();
            }
            
            
            //  6.3. draw frame
            this->render_window_ptr->clear();
            
            this->hex_map_ptr->draw();
            this->context_menu_ptr->draw();
            this->__draw();
            
            this->render_window_ptr->display();
            
            
            //  6.4. increment frame
            this->frame++;
        }
    }
    
    return this->quit_game;
}   /* run() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn Game :: ~Game(void)
///
/// \brief Destructor for the Game class.
///

Game :: ~Game(void)
{
    //  1. clean up attributes
    delete this->hex_map_ptr;
    delete this->context_menu_ptr;
    
    std::cout << "Game at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~Game() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
