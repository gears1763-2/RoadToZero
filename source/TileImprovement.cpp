/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the TileImprovement class.
 *
 */


///
/// \file TileImprovement.cpp
///
/// \brief Implementation file for the TileImprovement class.
///
/// A base class for the tile improvement hierarchy.
///


#include "../header/TileImprovement.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: __handleKeyPressEvents(void)
///
/// \brief Helper method to handle key press events.
///

void TileImprovement :: __handleKeyPressEvents(void)
{
    switch (this->event_ptr->key.code) {
        //...
        
        
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
/// \fn TileImprovement :: __handleMouseButtonEvents(void)
///
/// \brief Helper method to handle mouse button events.
///

void TileImprovement :: __handleMouseButtonEvents(void)
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

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn TileImprovement :: TileImprovement(
///         double position_x,
///         double position_y,
///         sf::Event* event_ptr,
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr,
///         MessageHub* message_hub_ptr
///     )
///
/// \brief Constructor for the TileImprovement class.
///
/// Ref: \cite hexagon\n
///
/// \param position_x The x position of the tile.
///
/// \param position_y The y position of the tile.
///
/// \param event_ptr Pointer to the event class.
///
/// \param render_window_ptr Pointer to the render window.
///
/// \param assets_manager_ptr Pointer to the assets manager.
///
/// \param message_hub_ptr Pointer to the message hub.
///

TileImprovement :: TileImprovement(
    double position_x,
    double position_y,
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
    this->frame = 0;
    
    this->position_x = position_x;
    this->position_y = position_y;
    
    std::cout << "TileImprovement constructed at " << this << std::endl;
    
    return;
}   /* TileImprovement() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: processEvent(void)
///
/// \brief Method to process TileImprovement. To be called once per event.
///

void TileImprovement :: processEvent(void)
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
/// \fn void TileImprovement :: processMessage(void)
///
/// \brief Method to process TileImprovement. To be called once per message.
///

void TileImprovement :: processMessage(void)
{
    //...
    
    return;
}   /* processMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TileImprovement :: draw(void)
///
/// \brief Method to draw the hex tile to the render window. To be called once per
///     frame.
///

void TileImprovement :: draw(void)
{
    //...
    
    this->frame++;
    return;
}   /* draw() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn TileImprovement :: ~TileImprovement(void)
///
/// \brief Destructor for the TileImprovement class.
///

TileImprovement :: ~TileImprovement(void)
{
    std::cout << "TileImprovement at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~TileImprovement() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
