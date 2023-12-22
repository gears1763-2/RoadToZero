/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the Settlement class.
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
/// \file Settlement.cpp
///
/// \brief Implementation file for the Settlement class.
///
/// A base class for the tile improvement hierarchy.
///


#include "../header/Settlement.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void Settlement :: __setUpTileImprovementSpriteStatic(void)
///
/// \brief Helper method to set up tile improvement sprite (static).
///

void Settlement :: __setUpTileImprovementSpriteStatic(void)
{
    this->tile_improvement_sprite_static.setTexture(
        *(this->assets_manager_ptr->getTexture("brick_house_64x64_1"))
    );
    
    this->tile_improvement_sprite_static.setOrigin(
        this->tile_improvement_sprite_static.getLocalBounds().width / 2,
        this->tile_improvement_sprite_static.getLocalBounds().height
    );
    
    this->tile_improvement_sprite_static.setPosition(
        this->position_x,
        this->position_y - 32
    );
    
    this->tile_improvement_sprite_static.setColor(
        sf::Color(255, 255, 255, 0)
    );
    
    return;
}   /* __setUpTileImprovementSpriteStatic() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Settlement :: __handleKeyPressEvents(void)
///
/// \brief Helper method to handle key press events.
///

void Settlement :: __handleKeyPressEvents(void)
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
/// \fn Settlement :: __handleMouseButtonEvents(void)
///
/// \brief Helper method to handle mouse button events.
///

void Settlement :: __handleMouseButtonEvents(void)
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
/// \fn Settlement :: Settlement(
///         double position_x,
///         double position_y,
///         sf::Event* event_ptr,
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr,
///         MessageHub* message_hub_ptr
///     )
///
/// \brief Constructor for the Settlement class.
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

Settlement :: Settlement(
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
    this->tile_improvement_type = TileImprovementType :: SETTLEMENT;
    
    this->skip_smoke_processing = true;
    
    this->smoke_da = 1e-8 * SECONDS_PER_FRAME;
    this->smoke_dx = 5 * SECONDS_PER_FRAME;
    this->smoke_dy = -10 * SECONDS_PER_FRAME;
    this->smoke_prob = 2 * SECONDS_PER_FRAME;
    
    this->smoke_sprite_list = {};
    
    this->tile_improvement_string = "SETTLEMENT";
    
    this->__setUpTileImprovementSpriteStatic();
    
    std::cout << "Settlement constructed at " << this << std::endl;
    
    return;
}   /* Settlement() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Settlement :: processEvent(void)
///
/// \brief Method to process Settlement. To be called once per event.
///

void Settlement :: processEvent(void)
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
/// \fn void Settlement :: processMessage(void)
///
/// \brief Method to process Settlement. To be called once per message.
///

void Settlement :: processMessage(void)
{
    //...
    
    return;
}   /* processMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Settlement :: draw(void)
///
/// \brief Method to draw the hex tile to the render window. To be called once per
///     frame.
///

void Settlement :: draw(void)
{
    //  1. if just built, call base method and return
    if (this->just_built) {
        TileImprovement :: draw();
        
        return;
    }
    
    //  2. draw static sprite and chimney smoke effects
    this->render_window_ptr->draw(this->tile_improvement_sprite_static);
    
    std::list<sf::Sprite>::iterator iter = this->smoke_sprite_list.begin();

    double alpha = 255;
    
    while (iter != this->smoke_sprite_list.end()) {
        this->render_window_ptr->draw(*iter);
        
        if (not this->skip_smoke_processing) {
            alpha = (*iter).getColor().a;
        
            alpha -= this->smoke_da;
            
            if (alpha <= 0) {
                iter = this->smoke_sprite_list.erase(iter);
                continue;
            }
            
            (*iter).setColor(sf::Color(255, 255, 255, alpha));
            
            (*iter).move(
                this->smoke_dx + 2 * (((double)rand() / RAND_MAX) - 1) / FRAMES_PER_SECOND,
                this->smoke_dy
            );
            
            (*iter).rotate(((double)rand() / RAND_MAX));
        }
        
        iter++;
    }
    
    
    if (not this->skip_smoke_processing) {
        if ((double)rand() / RAND_MAX < smoke_prob) {
            this->smoke_sprite_list.push_back(
                sf::Sprite(*(this->assets_manager_ptr->getTexture("emissions")))
            );
            
            this->smoke_sprite_list.back().setOrigin(
                this->smoke_sprite_list.back().getLocalBounds().width / 2,
                this->smoke_sprite_list.back().getLocalBounds().height / 2
            );
            
            this->smoke_sprite_list.back().setPosition(
                this->position_x + 9,
                this->position_y - 33
            );
        }
    }
    
    
    if (this->is_selected) {
        if (this->skip_smoke_processing) {
            this->skip_smoke_processing = false;
        }
        
        else {
            this->skip_smoke_processing = true;
        }
    }
    
    else {
        this->skip_smoke_processing = false;
    }
    
    this->frame++;
    return;
}   /* draw() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn Settlement :: ~Settlement(void)
///
/// \brief Destructor for the Settlement class.
///

Settlement :: ~Settlement(void)
{
    std::cout << "Settlement at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~Settlement() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
