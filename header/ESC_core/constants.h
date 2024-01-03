/*
 *  [ESC] Interactive
 *
 *  Header file for various constants.
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
/// \file constants.h
///
/// \brief Header file for various constants.
///


#ifndef CONSTANTS_H
#define CONSTANTS_H


#include "includes.h"


// ======== TESTING CONSTANTS ======================================================= //

const double FLOAT_TOLERANCE = 1e-6; ///< Tolerance for floating point equality tests.

// ======== END TESTING CONSTANTS =================================================== //



// ======== GENERAL GAME CONSTANTS ================================================== //

const unsigned long long int SECONDS_PER_YEAR = 31537970;
const unsigned long long int SECONDS_PER_MONTH = 2628164;

const int FRAMES_PER_SECOND = 60; ///< Target frames per second.
const double SECONDS_PER_FRAME = 1.0 / 60; ///< Target seconds per frame (just reciprocal of target frames per second).

const int GAME_WIDTH = 1200; ///< Width of the game space.
const int GAME_HEIGHT = 800; ///< Height of the game space.

// ======== END GENERAL GAME CONSTANTS ============================================== //



// ======== HEXTILE AND HEXMAP CONSTANTS ============================================ //

const sf::Color FOREST_GREEN(34, 139, 34); ///< The base colour of a forest tile.
const sf::Color LAKE_BLUE(0, 102, 204); ///< The base colour of a lake (water) tile.
const sf::Color MOUNTAINS_GREY(97, 110, 113); ///< The base colour of a mountains tile.
const sf::Color OCEAN_BLUE(0, 51, 102); ///< The base colour of an ocean (water) tile.
const sf::Color PLAINS_YELLOW(245, 222, 133); ///< The base colour of a plains tile.

const sf::Color RESOURCE_CHIP_GREY(175, 175, 175, 250); ///< The base colour of the resource chip (backing).

const std::vector<double> TILE_TYPE_CUMULATIVE_PROBABILITIES = {
    0.25,  // LAKE
    0.50,  // PLAINS
    0.75,  // FOREST
    1.00   // MOUNTAINS
}; ///< Cumulative probabilities for each tile type (to support procedural generation).

const std::vector<double> TILE_RESOURCE_CUMULATIVE_PROBABILITIES = {
    0.10,  // POOR
    0.30,  // BELOW_AVERAGE
    0.70,  // AVERAGE
    0.90,  // ABOVE_AVERAGE
    1.00   // GOOD
}; ///< Cumulative probabilities for each tile resource (to support procedural generation).

const std::string TILE_SELECTED_CHANNEL = "TILE SELECTED CHANNEL"; ///< A message channel for tile selection messages.
const std::string NO_TILE_SELECTED_CHANNEL = "NO TILE SELECTED CHANNEL"; ///< A message channel for no tile selected messages.
const std::string TILE_STATE_CHANNEL = "TILE STATE CHANNEL"; ///< A message channel for tile state messages.

const std::string HEX_MAP_CHANNEL = "HEX MAP CHANNEL"; ///< A message channel for hex map messages.

const std::string SETTLEMENT_CHANNEL = "SETTLEMENT CHANNEL"; ///< A message channel for the settlement.

const int CLEAR_FOREST_COST = 160; ///< The cost of clearing a forest tile.
const int CLEAR_MOUNTAINS_COST = 500; ///< The cost of clearing a mountains tile.
const int CLEAR_PLAINS_COST = 80; ///< The cost of clearing a plains tile.

const int DIESEL_GENERATOR_BUILD_COST = 200; ///< The cost of building (or ugrading) a diesel generator in 200 kW increments.
const int WIND_TURBINE_BUILD_COST = 450; ///< The cost of building (or upgrading) a wind turbine in 100 kW increments.
const double WIND_TURBINE_WATER_BUILD_MULTIPLIER = 1.222222; ///< The additional cost of building on water.
const int SOLAR_PV_BUILD_COST = 350; ///< The cost of building (or upgrading) a solar PV array in 100 kW increments.
const double SOLAR_PV_WATER_BUILD_MULTIPLIER = 1.285714; ///< The additional cost of building on water.
const int TIDAL_TURBINE_BUILD_COST = 550; ///< The cost of building (or upgrading) a tidal turbine in 100 kW increments.
const int WAVE_ENERGY_CONVERTER_BUILD_COST = 850; ///< The cost of building (or upgrading) a wave energy converter in 100 kW increments.

const int ENERGY_STORAGE_SYSTEM_BUILD_COST = 160; ///< The cost of adding energy storage in 200 kWh increments

const double BREAKDOWN_PROBABILITY_INCREMENT = 0.01; ///< The amount by which equipment breakdown probability is incremented for each point of health below 50.

const int SCRAP_COST = 50; ///< The cost of scrapping a tile improvement (other than settlement).

const int MAX_UPGRADE_LEVELS = 5; ///< The maximum upgrade level of any tile improvement.
const int MAX_STORAGE_LEVELS = 5; ///< The maximum storage level of any tile improvement.

// ======== END HEXTILE AND HEXMAP CONSTANTS ======================================== //



// ======== CONTEXTMENU CONSTANTS =================================================== //

const sf::Color MENU_FRAME_GREY(185, 187, 182); ///< The base colour of the context menu frame.
const sf::Color MONOCHROME_SCREEN_BACKGROUND(40, 40, 40); ///< The base colour of old monochrome screens.
const sf::Color VISUAL_SCREEN_FRAME_GREY(151, 151, 143); ///< The base colour of the framing of the visual screen.
const sf::Color MONOCHROME_TEXT_GREEN(0, 255, 102); ///< The base colour of old monochrome text (green).
const sf::Color MONOCHROME_TEXT_AMBER(255, 176, 0); ///< The base colour of old monochrome text (amber).
const sf::Color MONOCHROME_TEXT_RED(255, 44, 0); ///< The base colour of old monochrome text (red).

// ======== END CONTEXTMENU CONSTANTS =============================================== //



// ======== GAME CONSTANTS ========================================================== //

const int STARTING_CREDITS = 800; ///< The starting balance of credits.
const double CREDITS_PER_MWH_SERVED = 1.125; ///< The number of credits (x1000) earned

const int EMISSIONS_LIFETIME_LIMIT_TONNES = 2000; ///< The lifetime limit on CO2-equivalent emissions (1 tonne CO2e ~= 667 L diesel).

const int RESOURCE_ASSESSMENT_COST = 20; ///< The cost of doing a resource assessment.

const int BUILD_SETTLEMENT_COST = 250; ///< The cost of building a settlement.

const int STARTING_POPULATION = 100; ///< The starting population of a settlement.

const double MEAN_POPULATION_GROWTH_RATE = 0.020; ///< The mean monthly population growth rate.
const double STDEV_POPULATION_GROWTH_RATE = 0.005; ///< The standard deviation in monthly population growth rate.

const double LITRES_DIESEL_PER_MWH_PRODUCTION = 375; ///< The litres of diesel consumed in producing 1 MWh (assumes higher heating value and constant thermal efficiency of ~0.25).
const double COST_PER_LITRE_DIESEL = 1.75; ///< The cost of a litre of diesel.
const double KG_CO2E_PER_LITRE_DIESEL = 3.16; ///< The CO2-equivalent mass of emissions that result from burning one litre of diesel fuel.
const double DIESEL_OP_MAINT_COST_PER_MWH_PRODUCTION = 50; ///< The operation and maintenace cost of running a diesel generator (assumed 0.05 credits per kWh produced).

const double SOLAR_OP_MAINT_COST_PER_MWH_PRODUCTION = 10; ///< The operation and maintenance cost of running a solar PV array (assumed 0.01 credits per kWh produced).
const double TIDAL_OP_MAINT_COST_PER_MWH_PRODUCTION = 50; ///< The operation and maintenance cost of running a tidal turbine (assumed 0.05 credits per kWh produced).
const double WAVE_OP_MAINT_COST_PER_MWH_PRODUCTION = 50; ///< The operation and maintenance cost of running a wave energy converter (assumed 0.05 credits per kWh produced).
const double WIND_OP_MAINT_COST_PER_MWH_PRODUCTION = 50; ///< The operation and maintenance cost of running a wind turbine (assumed 0.05 credits per kWh produced).

const std::vector<double> MEAN_DAILY_DEMAND_RATIOS = {
    0.702, 0.704, 0.652,
    0.546, 0.445, 0.362,
    0.261, 0.261, 0.379,
    0.518, 0.622, 0.716
}; ///< The mean daily demand ratio for each month, where demand ratio is demand [MWh] divided by maximum daily demand [MWh]. Maximum daily demand is simply (24)(max load [kW]) / 1000.

const std::vector<double> STDEV_DAILY_DEMAND_RATIOS = {
    0.069, 0.074, 0.072,
    0.072, 0.063, 0.060,
    0.012, 0.031, 0.040,
    0.049, 0.063, 0.053
}; ///< The standard deviation in daily demand ratio for each month, where demand ratio is demand [MWh] divided by maximum daily demand [MWh]. Maximum daily demand is simply (24)(max load [kW]) / 1000.

const double MAXIMUM_DAILY_DEMAND_PER_CAPITA = 0.05; ///< The maximum daily demand [MWh] (at any point in the year) per capita.

const std::vector<double> MEAN_DAILY_SOLAR_CAPACITY_FACTORS = {
    0.029, 0.061, 0.117,
    0.183, 0.228, 0.233,
    0.219, 0.185, 0.139,
    0.081, 0.040, 0.021
}; ///< The mean daily solar capacity factors for each month, where capacity factor is daily production [MWh] divided by maximum daily production [MWh]. Maximum daily production is simply (24)(power capacity [kW]) / 1000.

const std::vector<double> STDEV_DAILY_SOLAR_CAPACITY_FACTORS = {
    0.013, 0.024, 0.043,
    0.049, 0.072, 0.072,
    0.076, 0.065, 0.048,
    0.026, 0.018, 0.009
}; ///< The standard deviation in daily solar capacity factors for each month, where capacity factor is daily production [MWh] divided by maximum daily production [MWh]. Maximum daily production is simply (24)(power capacity [kW]) / 1000.

const double DAILY_TIDAL_CAPACITY_FACTOR = 0.225; ///< The daily tidal capacity factor, where capacity factor is daily production [MWh] divided by maximum daily production [MWh]. Maximum daily production is simply (24)(power capacity [kW]) / 1000. The tides are not a random process (usually semi-diurnal, mostly driven by orbits of moon and sun).

const std::vector<double> MEAN_DAILY_WAVE_CAPACITY_FACTORS = {
    0.742, 0.694, 0.618,
    0.467, 0.366, 0.292,
    0.280, 0.293, 0.374,
    0.424, 0.662, 0.600
}; ///< The mean daily wave capacity factors for each month, where capacity factor is daily production [MWh] divided by maximum daily production [MWh]. Maximum daily production is simply (24)(power capacity [kW]) / 1000.

const std::vector<double> STDEV_DAILY_WAVE_CAPACITY_FACTORS = {
    0.146, 0.135, 0.163,
    0.145, 0.158, 0.106,
    0.086, 0.058, 0.145,
    0.171, 0.184, 0.309
}; ///< The standard deviation in daily wave capacity factors for each month, where capacity factor is daily production [MWh] divided by maximum daily production [MWh]. Maximum daily production is simply (24)(power capacity [kW]) / 1000.

const std::vector<double> MEAN_DAILY_WIND_CAPACITY_FACTORS = {
    0.591, 0.594, 0.627,
    0.629, 0.579, 0.537,
    0.442, 0.507, 0.587,
    0.618, 0.611, 0.580
}; ///< The mean daily wind capacity factors for each month, where capacity factor is daily production [MWh] divided by maximum daily production [MWh]. Maximum daily production is simply (24)(power capacity [kW]) / 1000.

const std::vector<double> STDEV_DAILY_WIND_CAPACITY_FACTORS = {
    0.147, 0.142, 0.198,
    0.154, 0.162, 0.202,
    0.180, 0.217, 0.198,
    0.168, 0.141, 0.168
}; ///< The standard deviation in daily wind capacity factors for each month, where capacity factor is daily production [MWh] divided by maximum daily production [MWh]. Maximum daily production is simply (24)(power capacity [kW]) / 1000.

const std::string GAME_CHANNEL = "GAME CHANNEL"; ///< A message channel for game messages.
const std::string GAME_STATE_CHANNEL = "GAME STATE CHANNEL"; ///< A message channel for game state messages.

// ======== END GAME CONSTANTS ====================================================== //



// ======== TUTORIAL STRINGS ======================================================== //

const std::vector<std::string> TUTORIAL_PAGES = {
    //          32 char x 16 line console 
    //          "                                \n"

    std::string("   **** TUTORIAL (1/10) ****    \n") +
    std::string("                                \n") +
    std::string("         ROAD TO ZERO           \n") +
    std::string(" THE MICROGRID MANAGEMENT GAME  \n") +
    std::string("                                \n") +
    std::string("TO WIN, GROW YOUR SETTLEMENT    \n") +
    std::string("TO A POPULATION OF AT LEAST     \n") +
    std::string("1,000 AND ACHIEVE AT LEAST     \n") +
    std::string("12 CONSECUTIVE MONTHS OF ZERO   \n") +
    std::string("EMISSIONS ENERGY DISPATCH.      \n") +
    std::string("                                \n") +
    std::string("FAIL TO MEET DEMAND, RUN OUT    \n") +
    std::string("OF CREDITS, OR EMIT TOO MUCH,   \n") +
    std::string("AND YOU LOSE!                   \n") +
    std::string("                                \n") +
    std::string("[<-]       [T]: CLOSE       [->]\n"),


    std::string("   **** TUTORIAL (2/10) ****    \n") +
    std::string("                                \n") +
    std::string("BEGIN BY BUILDING A SETTLEMENT. \n") +
    std::string("                                \n") +
    std::string("LEFT CLICK SELECT A LAND TILE,  \n") +
    std::string("AND THEN PRESS [B] TO BUILD A   \n") +
    std::string("SETTLEMENT THERE.               \n") +
    std::string("                                \n") +
    std::string("NOTE THAT PLACING A SETTLEMENT  \n") +
    std::string("AUTOMATICALLY ASSESSES THE      \n") +
    std::string("RENEWABLE RESOURCE QUALITIES    \n") +
    std::string("OF EVERY NEIGHBOURING TILE.     \n") +
    std::string("PRESS [TAB] TO TOGGLE THE       \n") +
    std::string("RENEWABLE RESOURCE OVERLAY.     \n") +
    std::string("                                \n") +
    std::string("[<-]       [T]: CLOSE       [->]\n"),


    std::string("   **** TUTORIAL (3/10) ****    \n") +
    std::string("                                \n") +
    std::string("YOUR SETTLEMENT BEGINS IN MONTH \n") +
    std::string("1 (JANUARY) OF THE GAME YEAR,   \n") +
    std::string("AND WITH AN INITIAL POPULATION  \n") +
    std::string("OF 100.                         \n") +
    std::string("                                \n") +
    std::string("THE POPULATION, CREDITS BALANCE,\n") +
    std::string("AND CURRENT ENERGY DEMAND OF THE\n") +
    std::string("SETTLEMENT ARE DISPLAYED IN THE \n") +
    std::string("TOP LINE OF THE GAME HUD.       \n") +
    std::string("                                \n") +
    std::string("REMEMBER, YOU MUST ALWAYS MEET  \n") +
    std::string("THE DEMAND FOR EVERY TURN!      \n") +
    std::string("                                \n") +
    std::string("[<-]       [T]: CLOSE       [->]\n"),


    std::string("   **** TUTORIAL (4/10) ****    \n") +
    std::string("                                \n") +
    std::string("IT IS IMPORTANT TO GET RELIABLE \n") +
    std::string("BASELINE PRODUCTION SET UP      \n") +
    std::string("IMMEDIATELY.                    \n") +
    std::string("                                \n") +
    std::string("LEFT CLICK SELECT AN ASSESSED   \n") +
    std::string("TILE, AND THEN PRESS [C] TO     \n") +
    std::string("CLEAR THE TILE FOR BUILDING.    \n") +
    std::string("                                \n") +
    std::string("THE COST OF CLEARING A TILE     \n") +
    std::string("VARIES BY TILE TYPE. THE COST   \n") +
    std::string("IS DISPLAYED IN THE TILE INFO   \n") +
    std::string("SCREEN, IN THE LOWER CONSOLE.   \n") +
    std::string("                                \n") +
    std::string("[<-]       [T]: CLOSE       [->]\n"),


    std::string("   **** TUTORIAL (5/10) ****    \n") +
    std::string("                                \n") +
    std::string("ONCE A TILE HAS BEEN CLEARED, IT\n") +
    std::string("CAN BE BUILT UPON. LEFT CLICK   \n") +
    std::string("SELECT THE TILE THAT WAS CLEARED\n") +
    std::string("AND THEN PRESS [B] TO OPEN THE  \n") +
    std::string("BUILD MENU.                     \n") +
    std::string("                                \n") +
    std::string("START BY BUILDING A 200 kW      \n") +
    std::string("DIESEL GENERATOR. THIS WILL     \n") +
    std::string("PROVIDE A RELIABLE BASELINE     \n") +
    std::string("PRODUCTION TO EXPAND UPON.      \n") +
    std::string("NOTE THAT RENEWABLE RESOURCE    \n") +
    std::string("QUALITY HAS NO IMPACT ON DIESEL.\n") +
    std::string("                                \n") +
    std::string("[<-]       [T]: CLOSE       [->]\n"),


    std::string("   **** TUTORIAL (6/10) ****    \n") +
    std::string("                                \n") +
    std::string("ONCE A TILE HAS BEEN CLEARED    \n") +
    std::string("AND BUILT, THE PRODUCTION       \n") +
    std::string("ASSET CAN BE INTERACTED WITH    \n") +
    std::string("BY WAY OF [E] FOR THE PRODUCTION\n") +
    std::string("MENU, OR [U] FOR THE UPGRADE    \n") +
    std::string("MENU / ACTION. THE TILE INFO    \n") +
    std::string("SCREEN ALWAYS DETAILS WHAT      \n") +
    std::string("ACTIONS CAN BE TAKEN.           \n") +
    std::string("                                \n") +
    std::string("LEFT CLICK SELECT THE DIESEL,   \n") +
    std::string("OPEN THE PRODUCTION MENU, AND   \n") +
    std::string("EXPERIMENT WITH THE PRODUCTION. \n") +
    std::string("                                \n") +
    std::string("[<-]       [T]: CLOSE       [->]\n"),


    std::string("   **** TUTORIAL (7/10) ****    \n") +
    std::string("                                \n") +
    std::string("NOTE THAT AS PRODUCTION /       \n") +
    std::string("DISPATCH IS ADJUSTED, A POP-UP  \n") +
    std::string("APPEARS NEXT TO THE CURRENT     \n") +
    std::string("DEMAND (TOP LINE OF HUD). THIS  \n") +
    std::string("POP-UP DISPLAYS THE SUM TOTAL   \n") +
    std::string("OF PRODUCTION / DISPATCH        \n") +
    std::string("CURRENTLY MUSTERED.             \n") +
    std::string("                                \n") +
    std::string("NOTE THAT RED INDICATES UNDER-  \n") +
    std::string("PRODUCTION, GREEN INDICATES     \n") +
    std::string("BALANCED PRODUCTION, AND AMBER  \n") +
    std::string("INDICATES OVER-PRODUCTION.      \n") +
    std::string("                                \n") +
    std::string("[<-]       [T]: CLOSE       [->]\n"),


    std::string("   **** TUTORIAL (8/10) ****    \n") +
    std::string("                                \n") +
    std::string("ONCE YOU HAVE BALANCED DIESEL   \n") +
    std::string("PRODUCTION WITH DEMAND, PRESS   \n") +
    std::string("[ENTER] TO END THE CURRENT      \n") +
    std::string("TURN / MONTH AND MOVE TO THE    \n") +
    std::string("NEXT.                           \n") +
    std::string("                                \n") +
    std::string("NOTE THAT YOU EARN CREDITS BY   \n") +
    std::string("SATISFYING DEMAND, BUT MUST ALSO\n") +
    std::string("PAY CREDITS FOR FUEL CONSUMED,  \n") +
    std::string("AS WELL AS FOR OPERATION AND    \n") +
    std::string("MAINTENANCE COSTS. FINALLY, ANY \n") +
    std::string("OVER-PRODUCTION IS PENALIZED.   \n") +
    std::string("                                \n") +
    std::string("[<-]       [T]: CLOSE       [->]\n"),


    std::string("   **** TUTORIAL (9/10) ****    \n") +
    std::string("                                \n") +
    std::string("NOTE THAT, WHENEVER YOU END A   \n") +
    std::string("TURN, A TURN SUMMARY SCREEN IS  \n") +
    std::string("DISPLAYED IN THE UPPER CONSOLE. \n") +
    std::string("THIS IS CONCEALED WHENEVER THIS \n") +
    std::string("TUTORIAL IS OPEN, HOWEVER.      \n") +
    std::string("                                \n") +
    std::string("TO CLOSE THIS TUTORIAL, PRESS   \n") +
    std::string("[T]. YOU CAN ALWAYS OPEN IT     \n") +
    std::string("AGAIN BY PRESSING [T].          \n") +
    std::string("                                \n") +
    std::string("FOR ADDITIONAL OPTIONS, SUCH AS \n") +
    std::string("RESETTING THE GAME, PRESS [ESC].\n") +
    std::string("                                \n") +
    std::string("[<-]       [T]: CLOSE       [->]\n"),


    std::string("   **** TUTORIAL (10/10) ****   \n") +
    std::string("                                \n") +
    std::string("THAT'S IT!                      \n") +
    std::string("                                \n") +
    std::string("REMEMBER TO STAY AHEAD OF THE   \n") +
    std::string("DEMAND CURVE, KEEP AN EYE ON    \n") +
    std::string("YOUR CREDITS, EMISSIONS, AND    \n") +
    std::string("EQUIPMENT HEALTH, AND DON'T     \n") +
    std::string("FORGET TO EXPLORE, EXPAND, AND  \n") +
    std::string("EXPLOIT GOOD RENEWABLE RESOURCES;\n") +
    std::string("YOU WILL NEED TO TO WIN.        \n") +
    std::string("                                \n") +
    std::string("GOOD LUCK, HAVE FUN. =)         \n") +
    std::string("                                \n") +
    std::string("                                \n") +
    std::string("[<-]       [T]: CLOSE       [->]\n")
};

// ======== END TUTORIAL STRINGS ==================================================== //


#endif  /* CONSTANTS_H */
