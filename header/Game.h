/*
 *  Road To Zero - The Microgrid Management Game
 *
 *  [ESC] Interactive
 *
 *  Header file for the Game class.
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
/// \file HexTile.h
///
/// \brief Header file for the Game class.
///


#ifndef GAME_H
#define GAME_H


#include "HexMap.h"
#include "ContextMenu.h"


///
/// \enum GamePhase
///
/// \brief An enumeration of the various game phases.
///

enum GamePhase {
    BUILD_SETTLEMENT, ///< The settlement building phase.
    SYSTEM_MANAGEMENT, ///< The system management phase (main phase of play).
    LOSS_EMISSIONS, ///< A loss due to excessive emissions.
    LOSS_DEMAND, ///< A loss due to failing to meet the demand.
    LOSS_CREDITS, ///< A loss due to running out of credits.
    VICTORY, ///< A victory (12 consecutive months of zero emissions).
    N_GAME_PHASES ///< A simple hack to get the number of elements in GamePhase.
};  /* GamePhase */


///
/// \class Game
///
/// \brief A class which acts as the central class for the game, by containing all other
///     classes and implementing the game loop.
///

class Game {
    private:
        //  1. attributes
        sf::RenderWindow* render_window_ptr; ///< A pointer to the render window.
        
        AssetsManager* assets_manager_ptr; ///< A pointer to the assets manager.
        
        
        //  2. methods
        void __toggleFrameClockOverlay(void);
        
        void __checkTerminatingConditions(void);
        void __updatePopulation(void);
        void __advanceTurn(void);
        
        void __computeCurrentDemand(void);
        
        void __toggleTutorial(void);
        void __incrementTutorial(void);
        void __decrementTutorial(void);
        
        void __handleKeyPressEvents(void);
        void __handleMouseButtonEvents(void);
        
        void __handleImprovementStateMessage(Message);
        
        void __processEvent(void);
        void __processMessage(void);
        
        void __sendGameStateMessage(void);
        void __sendTurnAdvanceMessage(void);
        void __sendCreditsEarnedMessage(void);
        
        void __insufficientCreditsAlarm(void);
        
        void __summarizeTurn(void);
        
        void __drawLossDemand(void);
        void __drawLossCredits(void);
        void __drawLossEmissions(void);
        void __drawVictory(void);
        
        void __drawTurnAdvanceBanner(void);
        void __drawTutorial(void);
        void __drawTurnSummary(void);
        void __drawFrameClockOverlay(void);
        void __drawHUD(void);
        void __draw(void);
    
    
    public:
        //  1. attributes
        GamePhase game_phase; ///< The current phase of the game.
        
        bool quit_game; ///< Boolean indicating whether to quit (true) or create a new Game instance (false).
        bool game_loop_broken; ///< Boolean indicating whether or not the game loop is broken.
        bool show_frame_clock_overlay; ///< Boolean indicating whether or not to show frame and clock overlay.
        bool check_terminating_conditions; ///< Boolean indicating whether or not to check terminating conditions.
        bool message_deadlock; ///< A boolean indicating whether a message deadlock has been detected.
        bool show_tutorial; ///< A boolean indicating whether or not to show the tutorial.
        bool turn_end; ///< A boolean indicating a turn end.
        bool draw_turn_advance_banner; ///< A boolean indicating whether or not to draw the turn advance banner.
        bool increase_turn_advance_alpha; ///< A boolean which indicates whether the turn advance alpha is increasing or decreasing.
        bool transition_from_title; ///< A boolean which indicates if construction follows a title transition.
        
        size_t tutorial_page; ///< Index for which page of the tutorial to show.
        std::string tutorial_string; ///< A string representation of the current tutorial page.
        sf::Text tutorial_text; ///< A text representation (drawable) of the tutorial page.
        
        unsigned long long int frame; ///< The current frame of the game.
        double time_since_start_s; ///< The time elapsed [s] since the start of the game.
        
        int year; ///< Current game year.
        int month; ///< Current game month.
        int population; ///< Current population.
        int credits; ///< Current balance of credits.
        int demand_MWh; ///< Current energy demand [MWh].
        int cumulative_emissions_tonnes; ///< Cumulative emissions [tonnes] (1 tonne = 1000 kg).
        
        int past_demand_MWh; ///< The demand in the previous turn.
        double turn_advance_alpha; ///< The alpha value for the turn advance banner.
        
        int demand_served_MWh; ///< The demand served at the end of a turn.
        int demand_remaining_MWh; ///< The demand remaining at the end of a turn.
        int overproduction_MWh; ///< The amount of overproduction at the end of a turn.
        int turn_fuel_cost; ///< The cost of fuel at the end of a turn.
        int turn_operation_maintenance_cost; ///< The cost of operation and maintenance at the end of a turn.
        int turn_emissions_tonnes; ///< The amount of emissions at the end of a turn.
        
        int dispatch_income; ///< The amount earned from dispatch at the end of a turn.
        int overproduction_penalty; ///< The penalty for overproduction.
        int net_credit_flow; ///< The net credit flow at the end of a turn.
        
        int consecutive_zero_emissions_months; ///< The number of recent, consecutive zero emission months.
        
        size_t substring_idx; ///< The index of the turn summary or tutorial substring 
        std::string turn_summary_string; ///< A string representation of the end of turn summary.
        sf::Text turn_summary_text; ///< A text representation (drawable) of the end of turn summary.
        
        int message_deadlock_frame; ///< A frame counter for detecting message deadlock.
        
        int turn = 0; ///< The current game turn.
        
        std::vector<double> demand_vec_MWh; ///< A vector of daily demands [MWh] for the current month.
        
        sf::Clock clock; ///< The game clock.
        sf::Event event; ///< The game events class.
        
        sf::RectangleShape fade_rectangle; ///< A fading rectangle (for smooth transition from title to game).
        
        MessageHub message_hub; ///< The message hub (for inter-object message traffic).
        
        HexMap* hex_map_ptr; ///< Pointer to the hex map (defines game world).
        ContextMenu* context_menu_ptr; ///< Pointer to the context menu.
        
        
        //  2. methods
        Game(sf::RenderWindow*, AssetsManager*, bool);
        
        bool run(void);
        
        ~Game(void);
        
}; /* Game */


#endif  /* GAME_H */
