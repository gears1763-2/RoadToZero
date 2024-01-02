/*
 *  Road To Zero - The Microgrid Management Game
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
/// \fn void Game :: __checkTerminatingConditions(void)
///
/// \brief Helper method to check terminating conditions (i.e., loss or victory
///     conditions).
///

void Game :: __checkTerminatingConditions(void)
{
    //  1. loss emissions
    if (this->cumulative_emissions_tonnes >= EMISSIONS_LIFETIME_LIMIT_TONNES) {
        this->assets_manager_ptr->getSound("loss")->play();
        this->game_phase = GamePhase :: LOSS_EMISSIONS;
    }
    
    //  2. loss demand
    else if (this->demand_remaining_MWh > 0) {
        this->assets_manager_ptr->getSound("loss")->play();
        this->game_phase = GamePhase :: LOSS_DEMAND;
    }
    
    //  3. loss credits
    else if (this->credits < 0) {
        this->assets_manager_ptr->getSound("loss")->play();
        this->game_phase = GamePhase :: LOSS_CREDITS;
    }
    
    //  4. victory
    else if (
        (this->population >= 1000) and
        (this->consecutive_zero_emissions_months >= 12)
    ) {
        this->assets_manager_ptr->getSound("victory")->play();
        this->game_phase = GamePhase :: VICTORY;
    }
    
    //  5. send game state message
    //this->__sendGameStateMessage();
    
    return;
}   /* __checkTerminatingConditions() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __updatePopulation(void)
///
/// \brief Helper method to update (i.e. grow) population.
///

void Game :: __updatePopulation(void)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    
    std::normal_distribution<double> normal_dist(
        MEAN_POPULATION_GROWTH_RATE,
        STDEV_POPULATION_GROWTH_RATE
    );
    
    double growth_rate = normal_dist(generator);
    
    this->population = ceil((1 + growth_rate) * this->population);
    
    return;
}   /* __updatePopulation() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __advanceTurn(void)
///
/// \brief Helper method to advance turn.
///

void Game :: __advanceTurn(void)
{
    //  1. advance turn, raise turn end flag
    this->turn++;
    this->turn_end = true;
    
    //  2. reset turn summary attributes
    this->demand_served_MWh = 0;
    this->demand_remaining_MWh = 0;
    this->overproduction_MWh = 0;
    this->turn_fuel_cost = 0;
    this->turn_operation_maintenance_cost = 0;
    this->turn_emissions_tonnes = 0;
    
    this->overproduction_penalty = 0;
    this->dispatch_income = 0;
    this->net_credit_flow = 0;
    
    //  3. advance month/year
    this->month++;
    if (this->month > 12) {
        this->year++;
        this->month = 1;
    }
    
    //  4. update population
    if (this->turn == 1) {
        this->population = STARTING_POPULATION;
    }
    
    else {
        this->__updatePopulation();
    }
    
    //  5. update demand
    this->__computeCurrentDemand();
    
    //  6. send turn advance message
    this->__sendTurnAdvanceMessage();
    this->__sendGameStateMessage();
    
}   /* __advanceTurn() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __computeCurrentDemand(void)
///
/// \brief Helper method to compute current energy demand.
///

void Game :: __computeCurrentDemand(void)
{
    this->past_demand_MWh = this->demand_MWh;
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    std::normal_distribution<double> normal_dist(
        MEAN_DAILY_DEMAND_RATIOS[this->month - 1],
        STDEV_DAILY_DEMAND_RATIOS[this->month - 1]
    );
    
    double demand_MWh = 0;
    
    for (int i = 0; i < 30; i++) {
        this->demand_vec_MWh[i] =
            normal_dist(generator) * MAXIMUM_DAILY_DEMAND_PER_CAPITA * this->population;
        
        demand_MWh += this->demand_vec_MWh[i];
    }
    
    this->demand_MWh = round(demand_MWh);

    return;
}   /* __computeCurrentDemand() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __toggleTutorial(void)
///
/// \brief Helper method to handle toggling the tutorial on and off.
///

void Game :: __toggleTutorial(void)
{
    if (this->show_tutorial) {
        this->show_tutorial = false;
    }
    
    else {
        this->tutorial_page = 0;
        this->tutorial_string = TUTORIAL_PAGES[this->tutorial_page];
    
        this->show_tutorial = true;
    }
    
    this->substring_idx = 0;
    
    this->assets_manager_ptr->getSound("interface click")->play();
    
    return;
}   /* __toggleTutorial() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __incrementTutorial(void)
///
/// \brief Helper method to increment tutorial page (with wrap around).
///

void Game :: __incrementTutorial(void)
{
    if (this->tutorial_page == TUTORIAL_PAGES.size() - 1) {
        this->tutorial_page = 0;
    }
    
    else {
        this->tutorial_page++;
    }
    
    this->tutorial_string = TUTORIAL_PAGES[this->tutorial_page];
    this->substring_idx = 0;
    
    this->assets_manager_ptr->getSound("interface click")->play();
    
    return;
}   /* __incrementTutorial() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __decrementTutorial(void)
///
/// \brief Helper method to decrement tutorial page (with wrap around).
///

void Game :: __decrementTutorial(void)
{
    if (this->tutorial_page == 0) {
        this->tutorial_page = TUTORIAL_PAGES.size() - 1;
    }
    
    else {
        this->tutorial_page--;
    }
    
    this->tutorial_string = TUTORIAL_PAGES[this->tutorial_page];
    this->substring_idx = 0;
    
    this->assets_manager_ptr->getSound("interface click")->play();
    
    return;
}   /* __decrementTutorial() */

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
        case (sf::Keyboard::Enter): {
            if (this->game_phase == GamePhase :: SYSTEM_MANAGEMENT) {
                this->__advanceTurn();
            }
            
            break;
        }
        
        
        case (sf::Keyboard::Tilde): {
            this->__toggleFrameClockOverlay();
            
            break;
        }
        
        
        case (sf::Keyboard::Tab): {
            this->hex_map_ptr->toggleResourceOverlay();
            
            break;
        }
        
        
        case (sf::Keyboard::T): {
            this->__toggleTutorial();
            
            break;
        }
        
        
        case (sf::Keyboard::Left): {
            if (this->show_tutorial) {
                this->__decrementTutorial();
            }
            
            break;
        }
        
        
        case (sf::Keyboard::Right): {
            if (this->show_tutorial) {
                this->__incrementTutorial();
            }
            
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
/// \fn void Game :: __handleImprovementStateMessage(Message improvement_state_message)
///
/// \brief Helper method to handle improvement state messages.
///

void Game :: __handleImprovementStateMessage(Message improvement_state_message)
{
    //  1. dispatch
    if (improvement_state_message.int_payload.count("dispatch_MWh") > 0) {
        this->demand_served_MWh += improvement_state_message.int_payload["dispatch_MWh"];
    }
    
    //  2. fuel costs
    if (improvement_state_message.int_payload.count("fuel_cost") > 0) {
        this->turn_fuel_cost += improvement_state_message.int_payload["fuel_cost"];
    }
    
    //  3. operation and maintenance costs
    if (improvement_state_message.int_payload.count("operation_maintenance_cost") > 0) {
        this->turn_operation_maintenance_cost +=
            improvement_state_message.int_payload["operation_maintenance_cost"];
    }
    
    //  4. emissions
    if (improvement_state_message.int_payload.count("emissions_tonnes_CO2e") > 0) {
        double emissions_tonnes_CO2e =
            improvement_state_message.int_payload["emissions_tonnes_CO2e"];
        
        this->cumulative_emissions_tonnes += emissions_tonnes_CO2e;
        this->turn_emissions_tonnes += emissions_tonnes_CO2e;
    }
    
    return;
}   /* __handleImprovementStateMessage() */

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
    
    game_state_message.int_payload["reads"] = 0;
    
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
    
    game_state_message.vector_payload["demand_vec_MWh"] = this->demand_vec_MWh;
    
    this->message_hub.sendMessage(game_state_message);
    
    std::cout << "Game state message sent by " << this << std::endl;
    return;
}   /* __sendGameStateMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __sendTurnAdvanceMessage(void)
///
/// \brief Helper method to format and send a turn advance message.
///

void Game :: __sendTurnAdvanceMessage(void)
{
    Message turn_advance_message;
    
    turn_advance_message.channel = GAME_STATE_CHANNEL;
    turn_advance_message.subject = "turn advance";
    
    turn_advance_message.int_payload["credits"] = this->credits;
    turn_advance_message.int_payload["month"] = this->month;
    turn_advance_message.int_payload["demand_MWh"] = this->demand_MWh;
    
    this->message_hub.sendMessage(turn_advance_message);
    
    std::cout << "Turn advance message sent by " << this << std::endl;
    return;
}   /* __sendTurnAdvanceMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __sendCreditsEarnedMessage(void)
///
/// \brief Helper method to format and send a credits earned message.
///

void Game :: __sendCreditsEarnedMessage(void)
{
    Message credits_earned_message;
    
    credits_earned_message.channel = SETTLEMENT_CHANNEL;
    credits_earned_message.subject = "credits earned";
    
    this->message_hub.sendMessage(credits_earned_message);
    
    std::cout << "Credits earned message sent by " << this << std::endl;
    return;
}   /* __sendCreditsEarnedMessage() */

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
                this->__advanceTurn();
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
        
        if (game_channel_message.subject == "improvement state") {
            std::cout << "Improvement state message received by " << this << std::endl;
            
            this->__handleImprovementStateMessage(game_channel_message);
                
            this->message_hub.popMessage(GAME_CHANNEL);
        }
    }
    
    if (not this->message_hub.isEmpty(GAME_STATE_CHANNEL)) {
        Message game_state_message =
            this->message_hub.receiveMessage(GAME_STATE_CHANNEL);
        
        if (game_state_message.subject == "turn advance") {
            if (game_state_message.number_of_reads > 0) {
                std::cout << "Turn advance message received by " << this << std::endl;
                this->message_hub.popMessage(GAME_STATE_CHANNEL);
            }
        }
        
        if (game_state_message.subject == "game state") {
            if (game_state_message.number_of_reads > 0) {
                std::cout << "Game state message received by " << this << std::endl;
                this->message_hub.popMessage(GAME_STATE_CHANNEL);
            }
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
/// \fn void Game :: __summarizeTurn(void)
///
/// \brief Helper method to generate end of turn summary.
///

void Game :: __summarizeTurn(void)
{
    if (this->turn - 1 == 0) {
        return;
    }
    
    this->substring_idx = 0;
    
    //  1. handle dispatch and demand
    if (this->demand_served_MWh > this->past_demand_MWh) {
        this->overproduction_MWh = this->demand_served_MWh - this->past_demand_MWh;
        this->demand_served_MWh -= this->overproduction_MWh;
        
        this->overproduction_penalty =
            round(CREDITS_PER_MWH_SERVED * this->overproduction_MWh);
    }
    
    else if (this->demand_served_MWh < this->past_demand_MWh) {
        this->demand_remaining_MWh = this->past_demand_MWh - this->demand_served_MWh;
    }
    
    //  2. compute dispatch income
    this->dispatch_income = round(CREDITS_PER_MWH_SERVED * this->demand_served_MWh);
    
    if (this->dispatch_income > 0) {
        this->__sendCreditsEarnedMessage();
    }
    
    //  3. compute net credit flow
    this->net_credit_flow = this->dispatch_income -
        this->overproduction_penalty -
        this->turn_fuel_cost -
        this->turn_operation_maintenance_cost;
    
    this->credits += this->net_credit_flow;
    
    //  4. assemble turn summary string
    this->turn_summary_string.clear();
    
    //16 line x 32 char console  "                                \n";
    this->turn_summary_string  = "     **** TURN ";
    this->turn_summary_string += std::to_string(this->turn - 1);
    this->turn_summary_string += " SUMMARY ****   \n";
    this->turn_summary_string += "                                \n";
    
    this->turn_summary_string += "DEMAND:            ";
    this->turn_summary_string += std::to_string(this->past_demand_MWh);
    this->turn_summary_string += " MWh\n";
    
    this->turn_summary_string += "DEMAND SERVED:     ";
    this->turn_summary_string += std::to_string(this->demand_served_MWh);
    this->turn_summary_string += " MWh\n";
    
    if (this->overproduction_MWh > 0) {
        this->turn_summary_string += "OVERPRODUCTION:    ";
        this->turn_summary_string += std::to_string(this->overproduction_MWh);
        this->turn_summary_string += " MWh\n";
    }
    
    else if (this->demand_remaining_MWh > 0) {
        this->turn_summary_string += "DEMAND REMAINING:  ";
        this->turn_summary_string += std::to_string(this->demand_remaining_MWh);
        this->turn_summary_string += " MWh\n";
    }
    
    this->turn_summary_string += "                                \n";
    this->turn_summary_string += "                                \n";
    
    this->turn_summary_string += "DISPATCH INCOME:  +";
    this->turn_summary_string += std::to_string(this->dispatch_income);
    this->turn_summary_string += " K\n";
    
    this->turn_summary_string += "FUEL COST:        -";
    this->turn_summary_string += std::to_string(this->turn_fuel_cost);
    this->turn_summary_string += " K\n";
    
    this->turn_summary_string += "OP & MAINT COST:  -";
    this->turn_summary_string += std::to_string(this->turn_operation_maintenance_cost);
    this->turn_summary_string += " K\n";
    
    this->turn_summary_string += "OVERPRODUCTION:   -";
    this->turn_summary_string += std::to_string(this->overproduction_penalty);
    this->turn_summary_string += " K\n";
    
    this->turn_summary_string += "--------------------------------\n";
    
    this->turn_summary_string += "NET:              ";
    
    if (this->net_credit_flow > 0) {
        this->turn_summary_string += "+";
    }
    
    this->turn_summary_string += std::to_string(this->net_credit_flow);
    this->turn_summary_string += " K\n";
    
    this->turn_summary_string += "                                \n";
    
    this->turn_summary_string += "EMISSIONS: ";
    this->turn_summary_string += std::to_string(this->turn_emissions_tonnes);
    this->turn_summary_string += " tonnes CO2e\n";
    
    if (this->turn_emissions_tonnes <= 0) {
        this->consecutive_zero_emissions_months++;
    }
    
    else {
        this->consecutive_zero_emissions_months = 0;
    }
    
    //  5. send game state message
    this->__sendGameStateMessage();
    
    return;
}   /* _summarizeTurn() */

// ---------------------------------------------------------------------------------- //


// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __drawLossDemand(void)
///
/// \brief Helper method to draw loss (demand) pop-up.
///

void Game :: __drawLossDemand(void)
{
    //  1. construct alarm text and backing rectangle
    std::string loss_demand_string  = "   LOSS! - FAILED TO MEET DEMAND   \n";
    loss_demand_string             += "     press any key to restart      ";
    
    sf::Text loss_demand_text(
        loss_demand_string,
        (*(this->assets_manager_ptr->getFont("DroidSansMono"))),
        32
    );
    
    loss_demand_text.setOrigin(
        loss_demand_text.getLocalBounds().width / 2,
        loss_demand_text.getLocalBounds().height / 2
    );
    
    loss_demand_text.setPosition(400, GAME_HEIGHT / 2);
    
    sf::RectangleShape backing_rectangle(
        sf::Vector2f(
            800,
            1.5 * loss_demand_text.getLocalBounds().height
        )
    );
    
    backing_rectangle.setFillColor(RESOURCE_CHIP_GREY);
    
    backing_rectangle.setOrigin(
        backing_rectangle.getLocalBounds().width / 2,
        backing_rectangle.getLocalBounds().height / 2
    );
    
    backing_rectangle.setPosition(400, (GAME_HEIGHT / 2) + 8);
    
    //  3. colour cycle and draw
    if (this->frame % FRAMES_PER_SECOND <= FRAMES_PER_SECOND / 2) {
        loss_demand_text.setFillColor(MONOCHROME_TEXT_RED);
    }
    
    else {
        loss_demand_text.setFillColor(sf::Color(255, 255, 255, 255));
    }
    
    this->render_window_ptr->draw(backing_rectangle);
    this->render_window_ptr->draw(loss_demand_text);
    
    return;
}   /* __drawLossDemand() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __drawLossCredits(void)
///
/// \brief Helper method to draw loss (credits) pop-up.
///

void Game :: __drawLossCredits(void)
{
    //  1. construct loss text and backing rectangle
    std::string loss_credits_string  = "    LOSS! - RAN OUT OF CREDITS     \n";
    loss_credits_string             += "     press any key to restart      ";
    
    sf::Text loss_credits_text(
        loss_credits_string,
        (*(this->assets_manager_ptr->getFont("DroidSansMono"))),
        32
    );
    
    loss_credits_text.setOrigin(
        loss_credits_text.getLocalBounds().width / 2,
        loss_credits_text.getLocalBounds().height / 2
    );
    
    loss_credits_text.setPosition(400, GAME_HEIGHT / 2);
    
    sf::RectangleShape backing_rectangle(
        sf::Vector2f(
            800,
            1.5 * loss_credits_text.getLocalBounds().height
        )
    );
    
    backing_rectangle.setFillColor(RESOURCE_CHIP_GREY);
    
    backing_rectangle.setOrigin(
        backing_rectangle.getLocalBounds().width / 2,
        backing_rectangle.getLocalBounds().height / 2
    );
    
    backing_rectangle.setPosition(400, (GAME_HEIGHT / 2) + 8);
    
    //  3. colour cycle and draw
    if (this->frame % FRAMES_PER_SECOND <= FRAMES_PER_SECOND / 2) {
        loss_credits_text.setFillColor(MONOCHROME_TEXT_RED);
    }
    
    else {
        loss_credits_text.setFillColor(sf::Color(255, 255, 255, 255));
    }
    
    this->render_window_ptr->draw(backing_rectangle);
    this->render_window_ptr->draw(loss_credits_text);
    
    return;
}   /* __drawLossCredits() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __drawLossEmissions(void)
///
/// \brief Helper method to draw loss (emissions) pop-up.
///

void Game :: __drawLossEmissions(void)
{
    //  1. construct loss text and backing rectangle
    std::string loss_emissions_string  = "    LOSS! - EXCESSIVE EMISSIONS    \n";
    loss_emissions_string             += "     press any key to restart      ";
    
    sf::Text loss_emissions_text(
        loss_emissions_string,
        (*(this->assets_manager_ptr->getFont("DroidSansMono"))),
        32
    );
    
    loss_emissions_text.setOrigin(
        loss_emissions_text.getLocalBounds().width / 2,
        loss_emissions_text.getLocalBounds().height / 2
    );
    
    loss_emissions_text.setPosition(400, GAME_HEIGHT / 2);
    
    sf::RectangleShape backing_rectangle(
        sf::Vector2f(
            800,
            1.5 * loss_emissions_text.getLocalBounds().height
        )
    );
    
    backing_rectangle.setFillColor(RESOURCE_CHIP_GREY);
    
    backing_rectangle.setOrigin(
        backing_rectangle.getLocalBounds().width / 2,
        backing_rectangle.getLocalBounds().height / 2
    );
    
    backing_rectangle.setPosition(400, (GAME_HEIGHT / 2) + 8);
    
    //  3. colour cycle and draw
    if (this->frame % FRAMES_PER_SECOND <= FRAMES_PER_SECOND / 2) {
        loss_emissions_text.setFillColor(MONOCHROME_TEXT_RED);
    }
    
    else {
        loss_emissions_text.setFillColor(sf::Color(255, 255, 255, 255));
    }
    
    this->render_window_ptr->draw(backing_rectangle);
    this->render_window_ptr->draw(loss_emissions_text);
    
    return;
}   /* __drawLossEmissions() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __drawVictory(void)
///
/// \brief Helper method to draw victory pop-up.
///

void Game :: __drawVictory(void)
{
    //  1. construct victory text and backing rectangle
    std::string victory_string  = "        **** VICTORY! ****         \n";
    victory_string             += "     press any key to restart      ";
    
    sf::Text victory_text(
        victory_string,
        (*(this->assets_manager_ptr->getFont("DroidSansMono"))),
        32
    );
    
    victory_text.setOrigin(
        victory_text.getLocalBounds().width / 2,
        victory_text.getLocalBounds().height / 2
    );
    
    victory_text.setPosition(400, GAME_HEIGHT / 2);
    
    sf::RectangleShape backing_rectangle(
        sf::Vector2f(
            800,
            1.5 * victory_text.getLocalBounds().height
        )
    );
    
    backing_rectangle.setFillColor(RESOURCE_CHIP_GREY);
    
    backing_rectangle.setOrigin(
        backing_rectangle.getLocalBounds().width / 2,
        backing_rectangle.getLocalBounds().height / 2
    );
    
    backing_rectangle.setPosition(400, (GAME_HEIGHT / 2) + 8);
    
    //  3. colour cycle and draw
    if (this->frame % FRAMES_PER_SECOND <= FRAMES_PER_SECOND / 2) {
        victory_text.setFillColor(MONOCHROME_TEXT_GREEN);
    }
    
    else {
        victory_text.setFillColor(sf::Color(255, 255, 255, 255));
    }
    
    this->render_window_ptr->draw(backing_rectangle);
    this->render_window_ptr->draw(victory_text);
    
    return;
}   /* __drawVictory() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __drawTurnAdvanceBanner(void)
///
/// \brief Helper method to draw turn advance banner.
///

void Game :: __drawTurnAdvanceBanner(void)
{
    //  1. construct advance banner text
    std::string turn_advance_banner_string  = "      Turn: ";
    turn_advance_banner_string             += std::to_string(this->turn);
    turn_advance_banner_string             += "\n";
    turn_advance_banner_string             += "Year: ";
    turn_advance_banner_string             += std::to_string(this->year);
    turn_advance_banner_string             += "    Month: ";
    turn_advance_banner_string             += std::to_string(this->month);
    
    sf::Text turn_advance_banner_text(
        turn_advance_banner_string,
        *(this->assets_manager_ptr->getFont("DroidSansMono")),
        24
    );
    
    turn_advance_banner_text.setOrigin(
        turn_advance_banner_text.getLocalBounds().width / 2,
        turn_advance_banner_text.getLocalBounds().height / 2
    );
    
    turn_advance_banner_text.setPosition(400, GAME_HEIGHT / 2);
    
    turn_advance_banner_text.setFillColor(sf::Color(0, 0, 0, this->turn_advance_alpha));
    
    
    //  2. construct advance banner backing
    sf::RectangleShape backing_rectangle(
        sf::Vector2f(
            800,
            1.5 * turn_advance_banner_text.getLocalBounds().height
        )
    );
    
    sf::Color backing_colour = RESOURCE_CHIP_GREY;
    backing_colour.a = this->turn_advance_alpha;
    
    backing_rectangle.setFillColor(backing_colour);
    
    backing_rectangle.setOrigin(
        backing_rectangle.getLocalBounds().width / 2,
        backing_rectangle.getLocalBounds().height / 2
    );
    
    backing_rectangle.setPosition(400, (GAME_HEIGHT / 2) + 8);
    
    
    //  3. draw
    this->render_window_ptr->draw(backing_rectangle);
    this->render_window_ptr->draw(turn_advance_banner_text);
    
    //  4. adjust alpha, check terminating conditions
    if (this->increase_turn_advance_alpha) {
        this->turn_advance_alpha += 180 * SECONDS_PER_FRAME;
        
        if (this->turn_advance_alpha >= 255) {
            this->turn_advance_alpha = 255;
            this->increase_turn_advance_alpha = false;
        }
    }
    
    else {
        this->turn_advance_alpha -= 180 * SECONDS_PER_FRAME;
        
        if (this->turn_advance_alpha <= 0) {
            this->draw_turn_advance_banner = false;
        }
    }
    
    return;
}   /* __drawTurnAdvanceBanner() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __drawTutorial(void)
///
/// \brief Helper method to draw tutorial text.
///

void Game :: __drawTutorial(void)
{
    if (this->substring_idx < this->tutorial_string.size()) {
        this->assets_manager_ptr->getSound("console string print")->play();
        
        this->tutorial_text.setString(
            this->tutorial_string.substr(0, this->substring_idx)
        );
        
        while (
            (this->tutorial_string.substr(0, this->substring_idx).back() == ' ') or
            (this->tutorial_string.substr(0, this->substring_idx).back() == '\n')
        ) {
            this->substring_idx++;
            
            if (this->substring_idx == this->tutorial_string.size() - 1) {
                this->tutorial_text.setString(
                    this->tutorial_string.substr(0, this->substring_idx)
                );
                
                break;
            }
        }
        
        this->substring_idx++;
    }
    
    this->render_window_ptr->draw(this->tutorial_text);
    
    return;
}   /* __drawTutorial() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void Game :: __drawTurnSummary(void)
///
/// \brief Helper method to draw turn summary.
///

void Game :: __drawTurnSummary(void)
{
    if (this->substring_idx < this->turn_summary_string.size()) {
        this->assets_manager_ptr->getSound("console string print")->play();
        
        this->turn_summary_text.setString(
            this->turn_summary_string.substr(0, this->substring_idx)
        );
        
        while (
            (this->turn_summary_string.substr(0, this->substring_idx).back() == ' ') or
            (this->turn_summary_string.substr(0, this->substring_idx).back() == '\n')
        ) {
            this->substring_idx++;
            
            if (this->substring_idx == this->turn_summary_string.size() - 1) {
                this->turn_summary_text.setString(
                    this->turn_summary_string.substr(0, this->substring_idx)
                );
                
                break;
            }
        }
        
        this->substring_idx++;
    }
    
    this->render_window_ptr->draw(this->turn_summary_text);
    
    return;
}   /* __drawTurnSummary() */

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
    
    HUD_string += "    CONSECUTIVE ZERO EMISSIONS MONTHS: ";
    HUD_string += std::to_string(this->consecutive_zero_emissions_months);
    
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
    //  1. HUD
    this->__drawHUD();
    
    //  2. frame / clock overlay
    if (this->show_frame_clock_overlay) {
        this->__drawFrameClockOverlay();
    }
    
    //  3. tutorial or turn summary
    if (this->show_tutorial) {
        this->__drawTutorial();
    }
    
    else if (not this->turn_summary_string.empty()) {
        this->__drawTurnSummary();
    }
    
    //  4. turn advance banner
    if (this->draw_turn_advance_banner) {
        this->__drawTurnAdvanceBanner();
    }
    
    //  5. terminating conditions
    switch (this->game_phase) {
        case (GamePhase :: LOSS_DEMAND): {
            this->__drawLossDemand();
            
            break;
        }
        
        
        case (GamePhase :: LOSS_CREDITS): {
            this->__drawLossCredits();
            
            break;
        }
        
        
        case (GamePhase :: LOSS_EMISSIONS): {
            this->__drawLossEmissions();
            
            break;
        }
        
        
        case (GamePhase ::VICTORY): {
            this->__drawVictory();
            
            break;
        }
        
        
        default: {
            // do nothing!
            
            break;
        }
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
    this->check_terminating_conditions = false;
    this->show_tutorial = true;
    this->turn_end = false;
    this->draw_turn_advance_banner = false;
    this->increase_turn_advance_alpha = true;
    
    this->tutorial_page = 0;
    this->tutorial_string = TUTORIAL_PAGES[this->tutorial_page];
    
    this->tutorial_text.setFont(
        *(this->assets_manager_ptr->getFont("Glass_TTY_VT220"))
    );
    this->tutorial_text.setCharacterSize(16);
    this->tutorial_text.setFillColor(MONOCHROME_TEXT_GREEN);
    this->tutorial_text.setPosition(GAME_WIDTH - 400 + 64, 64);
    
    this->frame = 0;
    this->time_since_start_s = 0;
    
    this->message_deadlock = false;
    this->message_deadlock_frame = 0;
    
    double seconds_since_epoch = time(NULL);
    double years_since_epoch = seconds_since_epoch / SECONDS_PER_YEAR;
    
    this->year = 1970 + (int)years_since_epoch;
    this->month = (years_since_epoch - (int)years_since_epoch) * 12 + 1;
    while (this->month > 12) {
        this->month -= 12;
    }
    
    this->population = 0;
    this->credits = STARTING_CREDITS;
    this->demand_MWh = 0;
    this->cumulative_emissions_tonnes = 0;
    
    this->past_demand_MWh = 0;
    this->turn_advance_alpha = 0;
    
    this->demand_vec_MWh.resize(30, 0);
    
    this->demand_served_MWh = 0;
    this->demand_remaining_MWh = 0;
    this->overproduction_MWh = 0;
    this->turn_fuel_cost = 0;
    this->turn_operation_maintenance_cost = 0;
    this->turn_emissions_tonnes = 0;
    
    this->overproduction_penalty = 0;
    this->dispatch_income = 0;
    this->net_credit_flow = 0;
    
    this->consecutive_zero_emissions_months = 0;
    
    this->substring_idx = 0;
    this->turn_summary_string = "";
    
    this->turn_summary_text.setFont(
        *(this->assets_manager_ptr->getFont("Glass_TTY_VT220"))
    );
    this->turn_summary_text.setCharacterSize(16);
    this->turn_summary_text.setFillColor(MONOCHROME_TEXT_GREEN);
    this->turn_summary_text.setPosition(GAME_WIDTH - 400 + 64, 64);

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
    
    this->__sendGameStateMessage();
    
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
    // start game loop
    while (not this->game_loop_broken) {
        this->time_since_start_s = this->clock.getElapsedTime().asSeconds();
        
        if (this->time_since_start_s >= (this->frame + 1) * SECONDS_PER_FRAME) {
            //  process events
            while (this->render_window_ptr->pollEvent(this->event)) {
                if (
                    (this->game_phase == GamePhase :: BUILD_SETTLEMENT) or
                    (this->game_phase == GamePhase :: SYSTEM_MANAGEMENT)
                ) {
                    this->hex_map_ptr->processEvent();
                    this->context_menu_ptr->processEvent();
                    this->__processEvent();
                }
                
                else {
                    if (this->event.type == sf::Event::KeyPressed) {
                        this->game_loop_broken = true;
                    }
                }
            }
            
            
            //  process messages
            while (this->message_hub.hasTraffic()) {
                this->hex_map_ptr->processMessage();
                this->context_menu_ptr->processMessage();
                this->__processMessage();
                
                this->check_terminating_conditions = true;
                
                if (not this->message_deadlock) {
                    this->message_deadlock_frame++;
                    
                    if (this->message_deadlock_frame > 5 * FRAMES_PER_SECOND) {
                        this->message_hub.printState();
                        this->message_deadlock = true;
                    }
                }
            }
            this->message_deadlock = false;
            this->message_deadlock_frame = 0;
            
            
            //  handle turn end summary
            if (this->turn_end) {
                std::cout << "**** END OF TURN " << std::to_string(this->turn - 1) <<
                    " ****" << std::endl;
                
                this->__summarizeTurn();
                
                this->turn_end = false;
                
                this->draw_turn_advance_banner = true;
                this->turn_advance_alpha = 0;
                this->increase_turn_advance_alpha = true;
            }
            
            
            //  check terminating conditions
            if (this->check_terminating_conditions) {
                this->__checkTerminatingConditions();
                this->check_terminating_conditions = false;
            }
            
            
            //  draw frame
            this->render_window_ptr->clear();
            
            this->hex_map_ptr->draw();
            this->context_menu_ptr->draw();
            this->__draw();
            
            this->render_window_ptr->display();
            
            
            //  increment frame
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
