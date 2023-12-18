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
            1.02 * frame_clock_text.getLocalBounds().height
        )
    );
    frame_clock_backing.setFillColor(sf::Color(0, 0, 0, 255));
    
    this->render_window_ptr->draw(frame_clock_backing);
    this->render_window_ptr->draw(frame_clock_text);
    
    return;
}   /* __drawFrameClockOverlay() */

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
    this->show_frame_clock_overlay = false;
    
    this->frame = 0;
    this->time_since_start_s = 0;

    this->hex_map_ptr = new HexMap(
        6,
        &(this->event),
        this->render_window_ptr,
        this->assets_manager_ptr,
        &(this->message_hub)
    );
    
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
    while (this->render_window_ptr->isOpen()) {
        this->time_since_start_s = this->clock.getElapsedTime().asSeconds();
        
        if (this->time_since_start_s >= (this->frame + 1) * SECONDS_PER_FRAME) {
            //  6.1. process events
            while (this->render_window_ptr->pollEvent(this->event)) {
                this->hex_map_ptr->processEvent();
                
                if (this->event.type == sf::Event::KeyPressed) {
                    switch (this->event.key.code) {
                        case (sf::Keyboard::Tilde): {
                            this->__toggleFrameClockOverlay();
                            
                            break;
                        }
                        
                        default: {
                            // do nothing!
                            
                            break;
                        }
                    }
                }
                
                if (this->event.type == sf::Event::Closed) {
                    this->render_window_ptr->close();
                    this->quit_game = true;
                }
            }
            
            //  6.2. process frame
            this->hex_map_ptr->processFrame();
            
            //  6.3. draw frame
            this->render_window_ptr->clear();
            
            this->hex_map_ptr->draw();
            
            if (this->show_frame_clock_overlay) {
                this->__drawFrameClockOverlay();
            }
            
            this->render_window_ptr->display();
            
            this->frame++;
        }
    }
    
    return this->quit_game;
}   /*  */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn Game :: ~Game(void)
///
/// \brief Destructor for the Game class.
///

Game :: ~Game(void)
{
    delete this->hex_map_ptr;
    
    std::cout << "Game at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~Game() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
