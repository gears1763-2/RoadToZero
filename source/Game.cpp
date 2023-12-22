/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the Game class.
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
/// \fn void Game :: __sendGameStateMessage(void)
///
/// \brief Helper method to format and send a game state message.
///

void Game :: __sendGameStateMessage(void)
{
    Message game_state_message;
    
    game_state_message.channel = GAME_STATE_CHANNEL;
    game_state_message.subject = "game state";
    
    game_state_message.int_payload["year"] = this->year;
    game_state_message.int_payload["month"] = this->month;
    game_state_message.int_payload["population"] = this->population;
    game_state_message.int_payload["credits"] = this->credits;
    game_state_message.int_payload["demand_MWh"] = this->demand_MWh;
    game_state_message.int_payload["cumulative_emissions_tonnes"] =
        this->cumulative_emissions_tonnes;
    
    switch (this->game_phase) {
        case (GamePhase :: BUILD_SETTLEMENT): {
            game_state_message.string_payload["game phase"] = "build settlement";
            
            break;
        }
        
        
        case (GamePhase :: SYSTEM_MANAGEMENT): {
            game_state_message.string_payload["game phase"] = "system management";
            
            break;
        }
        
        
        case (GamePhase :: LOSS_EMISSIONS): {
            game_state_message.string_payload["game phase"] = "loss emissions";
            
            break;
        }
        
        
        case (GamePhase :: LOSS_DEMAND): {
            game_state_message.string_payload["game phase"] = "loss demand";
            
            break;
        }
        
        
        case (GamePhase :: LOSS_CREDITS): {
            game_state_message.string_payload["game phase"] = "loss credits";
            
            break;
        }
        
        
        case (GamePhase :: VICTORY): {
            game_state_message.string_payload["game phase"] = "victory";
            
            break;
        }
        
        
        default: {
            // do nothing!
            
            break;
        }
    }
    
    this->message_hub.sendMessage(game_state_message);
    
    std::cout << "Game state message sent by " << this << std::endl;
    return;
}   /* __sendGameStateMessage() */

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
            
            std::cout << "Quit game message received by " << this << std::endl;
            this->message_hub.popMessage(GAME_CHANNEL);
        }
        
        if (game_channel_message.subject == "restart game") {
            this->game_loop_broken = true;
            
            std::cout << "Restart game message received by " << this << std::endl;
            this->message_hub.popMessage(GAME_CHANNEL);
        }
        
        if (game_channel_message.subject == "state request") {
            std::cout << "Game state request message received by " << this << std::endl;
            
            this->__sendGameStateMessage();
            this->message_hub.popMessage(GAME_CHANNEL);
        }
        
        if (game_channel_message.subject == "credits spent") {
            this->credits -= game_channel_message.int_payload["credits spent"];
            
            std::cout << "Credits spent message (" << 
                game_channel_message.int_payload["credits spent"] << ") received by "
                << this << std::endl;
                
            std::cout << "Current credits (Game): " << this->credits << " K" <<
                std::endl;
                
            this->message_hub.popMessage(GAME_CHANNEL);
        }
        
        if (game_channel_message.subject == "insufficient credits") {
            std::cout << "Insufficient credits message received by " << this <<
                std::endl;
            
            this->__insufficientCreditsAlarm();
                
            this->message_hub.popMessage(GAME_CHANNEL);
        }
        
        if (game_channel_message.subject == "update game phase") {
            std::cout << "Update game phase message received by " << this << std::endl;
            
            if (
                game_channel_message.string_payload["game phase"] == "system management"
            ) {
                this->game_phase = GamePhase :: SYSTEM_MANAGEMENT;
                this->population = STARTING_POPULATION;
                this->turn++;
            }
            
            else if (
                game_channel_message.string_payload["game phase"] == "loss emissions"
            ) {
                this->game_phase = GamePhase :: LOSS_EMISSIONS;
            }
            
            else if (
                game_channel_message.string_payload["game phase"] == "loss demand"
            ) {
                this->game_phase = GamePhase :: LOSS_DEMAND;
            }
            
            else if (
                game_channel_message.string_payload["game phase"] == "loss credits"
            ) {
                this->game_phase = GamePhase :: LOSS_CREDITS;
            }
            
            else if (
                game_channel_message.string_payload["game phase"] == "victory"
            ) {
                this->game_phase = GamePhase :: VICTORY;
            }
            
            this->message_hub.popMessage(GAME_CHANNEL);
        }
    }
    
    return;
}   /* __processMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __insufficientCreditsAlarm(void)
///
/// \brief Helper method to sound and display and insufficient credits alarm.
///

void Game :: __insufficientCreditsAlarm(void)
{
    //  1. sound buzzer
    this->assets_manager_ptr->getSound("insufficient credits")->play();
    
    //  2. construct alarm text and backing rectangle
    sf::Text insufficient_credits_text(
        "INSUFFICIENT CREDITS",
        (*(this->assets_manager_ptr->getFont("DroidSansMono"))),
        32
    );
    
    insufficient_credits_text.setOrigin(
        insufficient_credits_text.getLocalBounds().width / 2,
        insufficient_credits_text.getLocalBounds().height / 2
    );
    
    insufficient_credits_text.setPosition(400, GAME_HEIGHT / 2);
    
    sf::RectangleShape backing_rectangle(
        sf::Vector2f(
            1.1 * insufficient_credits_text.getLocalBounds().width,
            1.5 * insufficient_credits_text.getLocalBounds().height
        )
    );
    
    backing_rectangle.setFillColor(RESOURCE_CHIP_GREY);
    
    backing_rectangle.setOrigin(
        backing_rectangle.getLocalBounds().width / 2,
        backing_rectangle.getLocalBounds().height / 2
    );
    
    backing_rectangle.setPosition(400, (GAME_HEIGHT / 2) + 8);
    
    //  3. display loop (blocking ~3 seconds)
    bool red_flag = true;
    int alarm_frame = 0;
    double time_since_alarm_s = 0;
    
    sf::Clock alarm_clock;
    
    while (alarm_frame < 2.5 * FRAMES_PER_SECOND) {
        
        
        time_since_alarm_s = alarm_clock.getElapsedTime().asSeconds();

        if (time_since_alarm_s >= (alarm_frame + 1) * SECONDS_PER_FRAME) {
            while (this->render_window_ptr->pollEvent(this->event)) {
                // do nothing!
            }
            
            this->render_window_ptr->clear();
            
            this->hex_map_ptr->draw();
            this->context_menu_ptr->draw();
            this->__draw();
            
            if (alarm_frame % (FRAMES_PER_SECOND / 3) == 0) {
                if (red_flag) {
                    red_flag = false;
                }
                
                else {
                    red_flag = true;
                }
            }
            
            if (red_flag) {
                insufficient_credits_text.setFillColor(MONOCHROME_TEXT_RED);
            }
            
            else {
                insufficient_credits_text.setFillColor(sf::Color(255, 255, 255));
            }
            
            this->render_window_ptr->draw(backing_rectangle);
            this->render_window_ptr->draw(insufficient_credits_text);
            
            this->render_window_ptr->display();
            
            alarm_frame++;
            this->frame++;
        }
        
        // check track status, move to next if stopped
        if (this->assets_manager_ptr->getTrackStatus() == sf::SoundSource::Stopped) {
            this->assets_manager_ptr->nextTrack();
            this->assets_manager_ptr->playTrack();
        }
    }

    return;
}   /* __insufficientCreditsAlarm( */

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
    //  1. first line (top)
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
    
    
    //  2. second line (top)
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
    
    
    //  3. third line (bottom)
    HUD_string = "GAME PHASE: ";
    
    switch (this->game_phase) {
        case (GamePhase :: BUILD_SETTLEMENT): {
            HUD_string += "BUILD SETTLEMENT";
            
            break;
        }
        
        
        case (GamePhase :: SYSTEM_MANAGEMENT): {
            HUD_string += "SYSTEM MANAGEMENT";
            
            break;
        }
        
        
        case (GamePhase :: LOSS_EMISSIONS): {
            HUD_string += "LOSS (EMISSIONS)";
            
            break;
        }
        
        
        case (GamePhase :: LOSS_DEMAND): {
            HUD_string += "LOSS (DEMAND)";
            
            break;
        }
        
        
        case (GamePhase :: LOSS_CREDITS): {
            HUD_string += "LOSS (CREDITS)";
            
            break;
        }
        
        
        case (GamePhase :: VICTORY): {
            HUD_string += "VICTORY";
            
            break;
        }
        
        
        default: {
            HUD_string += "???";
            
            break;
        }
    }
    
    HUD_string += "    TURN: ";
    HUD_string += std::to_string(this->turn);
    
    HUD_text.setString(HUD_string);
    
    HUD_text.setPosition(
        (800 - HUD_text.getLocalBounds().width) / 2,
        GAME_HEIGHT - 35
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
    this->game_phase = GamePhase :: BUILD_SETTLEMENT;
    
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
    this->credits = STARTING_CREDITS;
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
    this->message_hub.addChannel(GAME_STATE_CHANNEL);
    
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
        
        // check track status, move to next if stopped
        if (this->assets_manager_ptr->getTrackStatus() == sf::SoundSource::Stopped) {
            this->assets_manager_ptr->nextTrack();
            this->assets_manager_ptr->playTrack();
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
