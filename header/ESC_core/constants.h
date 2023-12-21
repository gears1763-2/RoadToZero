/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for various constants.
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

const int CLEAR_FOREST_COST = 40; ///< The cost of clearing a forest tile.
const int CLEAR_MOUNTAINS_COST = 100; ///< The cost of clearing a mountains tile.
const int CLEAR_PLAINS_COST = 20; ///< The cost of clearing a plains tile.

// ======== END HEXTILE AND HEXMAP CONSTANTS ======================================== //



// ======== CONTEXTMENU CONSTANTS =================================================== //

const sf::Color MENU_FRAME_GREY(185, 187, 182); ///< The base colour of the context menu frame.
const sf::Color MONOCHROME_SCREEN_BACKGROUND(40, 40, 40); ///< The base colour of old monochrome screens.
const sf::Color VISUAL_SCREEN_FRAME_GREY(151, 151, 143); ///< The base colour of the framing of the visual screen.
const sf::Color MONOCHROME_TEXT_GREEN(0, 255, 102); ///< The base colour of old monochrome text (green).
const sf::Color MONOCHROME_TEXT_AMBER(255, 176, 0); ///< The base colour of old monochrome text (amber).
const sf::Color MONOCHROME_TEXT_RED(255, 44, 0); ///< The base colour of old monochrome text (red).

// ======== END CONTEXTMENU CONSTANTS =============================================== //



// ======== GAME CONSTANTS =================================================== //

const int EMISSIONS_LIFETIME_LIMIT_TONNES = 1500; ///< The CO2-equivalent mass of emissions that would result from burning 1,000,000 L of diesel fuel.

const int RESOURCE_ASSESSMENT_COST = 20; ///< The cost of doing a resource assessment.

const int BUILD_SETTLEMENT_COST = 250; ///< The cost of building a settlement.
const int STARTING_POPULATION = 100; ///< The starting population of a settlement.

const double CO2E_KG_PER_LITRE_DIESEL = 3.1596; ///< The CO2-equivalent mass of emissions that result from burning one litre of diesel fuel.

const std::string GAME_CHANNEL = "GAME CHANNEL"; ///< A message channel for game messages.
const std::string GAME_STATE_CHANNEL = "GAME STATE CHANNEL"; ///< A message channel for game state messages.

// ======== END GAME CONSTANTS =================================================== //


#endif  /* CONSTANTS_H */
