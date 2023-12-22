/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the TidalTurbine class.
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
/// \file TidalTurbine.cpp
///
/// \brief Implementation file for the TidalTurbine class.
///
/// A base class for the tile improvement hierarchy.
///


#include "../header/TidalTurbine.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void TidalTurbine :: __setUpTileImprovementSpriteAnimated(void)
///
/// \brief Helper method to set up tile improvement sprite (static).
///

void TidalTurbine :: __setUpTileImprovementSpriteAnimated(void)
{
    sf::Sprite diesel_generator_sheet(
        *(this->assets_manager_ptr->getTexture("tidal turbine"))
    );
    
    int n_elements = diesel_generator_sheet.getLocalBounds().height / 64;
    
    for (int i = 0; i < n_elements; i++) {
        this->tile_improvement_sprite_animated.push_back(
            sf::Sprite(
                *(this->assets_manager_ptr->getTexture("tidal turbine")),
                sf::IntRect(0, i * 64, 64, 64)
            )
        );
        
        this->tile_improvement_sprite_animated.back().setOrigin(
            this->tile_improvement_sprite_animated.back().getLocalBounds().width / 2,
            this->tile_improvement_sprite_animated.back().getLocalBounds().height
        );
        
        this->tile_improvement_sprite_animated.back().setPosition(
            this->position_x,
            this->position_y - 32
        );
        
        this->tile_improvement_sprite_animated.back().setColor(
            sf::Color(255, 255, 255, 0)
        );
    }
    
    return;
}   /* __setUpTileImprovementSpriteAnimated() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TidalTurbine :: __handleKeyPressEvents(void)
///
/// \brief Helper method to handle key press events.
///

void TidalTurbine :: __handleKeyPressEvents(void)
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
/// \fn TidalTurbine :: __handleMouseButtonEvents(void)
///
/// \brief Helper method to handle mouse button events.
///

void TidalTurbine :: __handleMouseButtonEvents(void)
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
/// \fn TidalTurbine :: TidalTurbine(
///         double position_x,
///         double position_y,
///         sf::Event* event_ptr,
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr,
///         MessageHub* message_hub_ptr
///     )
///
/// \brief Constructor for the TidalTurbine class.
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

TidalTurbine :: TidalTurbine(
    double position_x,
    double position_y,
    sf::Event* event_ptr,
    sf::RenderWindow* render_window_ptr,
    AssetsManager* assets_manager_ptr,
    MessageHub* message_hub_ptr
) :
TileImprovement(
    position_x,
    position_y,
    event_ptr,
    render_window_ptr,
    assets_manager_ptr,
    message_hub_ptr
)
{
    //  1. set attributes
    
    //  1.1. private
    //...
    
    //  1.2. public
    this->tile_improvement_type = TileImprovementType :: TIDAL_TURBINE;
    
    this->is_running = false;
    
    this->tile_improvement_string = "TIDAL TURBINE";
    
    this->__setUpTileImprovementSpriteAnimated();
    
    std::cout << "TidalTurbine constructed at " << this << std::endl;
    
    return;
}   /* TidalTurbine() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TidalTurbine :: processEvent(void)
///
/// \brief Method to process TidalTurbine. To be called once per event.
///

void TidalTurbine :: processEvent(void)
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
/// \fn void TidalTurbine :: processMessage(void)
///
/// \brief Method to process TidalTurbine. To be called once per message.
///

void TidalTurbine :: processMessage(void)
{
    //...
    
    return;
}   /* processMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void TidalTurbine :: draw(void)
///
/// \brief Method to draw the hex tile to the render window. To be called once per
///     frame.
///

void TidalTurbine :: draw(void)
{
    //  1. if just built, call base method and return
    if (this->just_built) {
        TileImprovement :: draw();
        
        return;
    }
    
    
    //  1. draw first element of animated sprite
    this->render_window_ptr->draw(this->tile_improvement_sprite_animated[0]);
    
    
    //  2. draw second element of animated sprite
    if (this->is_running) {
        //...
    }
    
    else {
        //...
    }
    
    this->render_window_ptr->draw(this->tile_improvement_sprite_animated[1]);
    
    this->frame++;
    return;
}   /* draw() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn TidalTurbine :: ~TidalTurbine(void)
///
/// \brief Destructor for the TidalTurbine class.
///

TidalTurbine :: ~TidalTurbine(void)
{
    std::cout << "TidalTurbine at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~TidalTurbine() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
