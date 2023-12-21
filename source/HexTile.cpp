/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the HexTile class.
 *
 */


///
/// \file HexTile.cpp
///
/// \brief Implementation file for the HexTile class.
///
/// A class which defines a tile of a hex map.
///


#include "../header/HexTile.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpNodeSprite(void)
///
/// \brief Helper method to set up node sprite.
///

void HexTile :: __setUpNodeSprite(void)
{
    this->node_sprite.setRadius(4);
    
    this->node_sprite.setOrigin(
        this->node_sprite.getLocalBounds().width / 2,
        this->node_sprite.getLocalBounds().height / 2
    );
    
    this->node_sprite.setPosition(this->position_x, this->position_y);
    
    this->node_sprite.setFillColor(sf::Color(255, 0, 0, 255));
    
    return;
}   /* __setUpNodeSprite() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpTileSprite(void)
///
/// \brief Helper method to set up tile sprite.
///

void HexTile :: __setUpTileSprite(void)
{
    int n_points = 6;
    
    this->tile_sprite.setPointCount(n_points);
    
    for (int i = 0; i < n_points; i++) {
        this->tile_sprite.setPoint(
            i,
            sf::Vector2f(
                this->position_x + this->major_radius * cos((30 + 60 * i) * (M_PI / 180)),
                this->position_y + this->major_radius * sin((30 + 60 * i) * (M_PI / 180))
            )
        );
    }
    
    this->tile_sprite.setOutlineThickness(1);
    this->tile_sprite.setOutlineColor(sf::Color(175, 175, 175, 255));
    
    return;
}   /* __setUpTileSprite() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpSelectOutlineSprite(void)
///
/// \brief Helper method to set up select outline sprite.
///

void HexTile :: __setUpSelectOutlineSprite(void)
{
    int n_points = 6;
    
    this->select_outline_sprite.setPointCount(n_points);
    
    for (int i = 0; i < n_points; i++) {
        this->select_outline_sprite.setPoint(
            i,
            sf::Vector2f(
                this->position_x + this->major_radius * cos((30 + 60 * i) * (M_PI / 180)),
                this->position_y + this->major_radius * sin((30 + 60 * i) * (M_PI / 180))
            )
        );
    }
    
    this->select_outline_sprite.setOutlineThickness(4);
    this->select_outline_sprite.setOutlineColor(MONOCHROME_TEXT_RED);
    
    this->select_outline_sprite.setFillColor(sf::Color(0, 0, 0, 0));
    
    return;
}   /* __setUpSelectOutline() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpResourceChipSprite(void)
///
/// \brief Helper method to set up resource chip sprite.
///

void HexTile :: __setUpResourceChipSprite(void)
{
    this->resource_chip_sprite.setRadius(2 * this->minor_radius / 3);
    
    this->resource_chip_sprite.setOrigin(
        this->resource_chip_sprite.getLocalBounds().width / 2,
        this->resource_chip_sprite.getLocalBounds().height / 2
    );
    
    this->resource_chip_sprite.setPosition(this->position_x, this->position_y);
    
    this->resource_chip_sprite.setFillColor(RESOURCE_CHIP_GREY);
    
    return;
}   /* __setUpResourceChip() */

// ---------------------------------------------------------------------------------- //


// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setResourceText(void)
///
/// \brief Helper method to set up resource text.
///

void HexTile :: __setResourceText(void)
{
    this->resource_text.setFont(*(assets_manager_ptr->getFont("DroidSansMono")));
    
    this->resource_text.setFillColor(sf::Color(0, 0, 0, 255));
    
    if (this->resource_assessed) {
        switch (this->tile_resource) {
            case (TileResource :: POOR): {
                this->resource_text.setString("-2");
                this->resource_text.setFillColor(MONOCHROME_TEXT_RED);
                
                break;
            }
            
            case (TileResource :: BELOW_AVERAGE): {
                this->resource_text.setString("-1");
                this->resource_text.setFillColor(MONOCHROME_TEXT_RED);
                
                break;
            }
            
            case (TileResource :: AVERAGE): {
                this->resource_text.setString("+0");
                
                break;
            }
            
            case (TileResource :: ABOVE_AVERAGE): {
                this->resource_text.setString("+1");
                this->resource_text.setFillColor(MONOCHROME_TEXT_GREEN);
                
                break;
            }
            
            case (TileResource :: GOOD): {
                this->resource_text.setString("+2");
                this->resource_text.setFillColor(MONOCHROME_TEXT_GREEN);
                
                break;
            }
            
            default: {
                this->resource_text.setString("");
                
                break;
            }
        }
    }
    
    else {
        this->resource_text.setString("");
    }
    
    this->resource_text.setCharacterSize(20);
    
    this->resource_text.setOrigin(
        this->resource_text.getLocalBounds().width / 2,
        this->resource_text.getLocalBounds().height / 2
    );
    
    this->resource_text.setPosition(
        this->position_x,
        this->position_y - 4
    );
    
    this->resource_text.setOutlineThickness(1);
    this->resource_text.setOutlineColor(sf::Color(0, 0, 0, 255));
    
    return;
}   /* __setResourceText() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpMagnifyingGlassSprite(void)
///
/// \brief Helper method to set up and position magnifying glass sprite.
///

void HexTile :: __setUpMagnifyingGlassSprite(void)
{
    this->magnifying_glass_sprite.setTexture(
        *(this->assets_manager_ptr->getTexture("magnifying_glass_64x64_1"))
    );
    
    this->magnifying_glass_sprite.setOrigin(
        this->magnifying_glass_sprite.getLocalBounds().width / 2,
        this->magnifying_glass_sprite.getLocalBounds().height / 2
    );
    
    this->magnifying_glass_sprite.setPosition(
        this->position_x,
        this->position_y
    );
    
    return;
}   /* __setUpMagnifyingGlassSprite() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setUpTileExplosionReel(void)
///
/// \brief Helper method to set up tile explosion sprite reel.
///

void HexTile :: __setUpTileExplosionReel(void)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->explosion_sprite_reel.push_back(
                sf::Sprite(
                    *(this->assets_manager_ptr->getTexture("tile clear explosion")),
                    sf::IntRect(j * 64, i * 64, 64, 64)
                )
            );
            
            this->explosion_sprite_reel.back().setOrigin(
                this->explosion_sprite_reel.back().getLocalBounds().width / 2,
                this->explosion_sprite_reel.back().getLocalBounds().height / 2
            );
            
            this->explosion_sprite_reel.back().setPosition(
                this->position_x,
                this->position_y
            );
        }
    }
    
    return;
}   /* __setUpTileExplosionReel() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __setIsSelected(bool is_selected)
///
/// \brief Helper method to set the is selected attribute (of tile and improvement).
///
/// \param is_selected The value to set the is selected attribute to.
///

void HexTile :: __setIsSelected(bool is_selected)
{
    this->is_selected = is_selected;
    
    if (this->tile_improvement_ptr != NULL) {
        this->tile_improvement_ptr->is_selected = is_selected;
    }
    
    return;
}   /* __toggleIsSelected() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __clearDecoration(void)
///
/// \brief Helper method to clear tile decoration.
///

void HexTile :: __clearDecoration(void)
{
    this->decoration_cleared = true;
    this->draw_explosion = true;
    
    switch (this->tile_type) {
        case (TileType :: FOREST): {
            this->assets_manager_ptr->getSound("clear non-mountains tile")->play();
            
            break;
        }
        
        
        case (TileType :: MOUNTAINS): {
            this->assets_manager_ptr->getSound("clear mountains tile")->play();
            
            break;
        }
        
        
        case (TileType :: PLAINS): {
            this->assets_manager_ptr->getSound("clear non-mountains tile")->play();
            
            break;
        }
        
        
        default: {
            // do nothing!
            
            break;
        }
    }
    
    return;
}   /* __clearDecoration() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn bool HexTile :: __isClicked(void)
///
/// \brief Helper method to determine if tile was clicked on.
///
/// \return Boolean indicating whether or not tile was clicked on.
///

bool HexTile :: __isClicked(void)
{
    sf::Vector2i mouse_position = sf::Mouse::getPosition(*render_window_ptr);
        
    double mouse_x = mouse_position.x;
    double mouse_y = mouse_position.y;
    
    double distance = sqrt(
        pow(this->position_x - mouse_x, 2) +
        pow(this->position_y - mouse_y, 2)
    );
    
    if (distance < this->minor_radius) {
        return true;
    }
    else {
        return false;
    }
}   /* __isClicked() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __handleKeyPressEvents(void)
///
/// \brief Helper method to handle key press events.
///

void HexTile :: __handleKeyPressEvents(void)
{
    if (this->event_ptr->key.code == sf::Keyboard::Escape) {
        this->__setIsSelected(false);
    }
    
    if (not this->is_selected) {
        return;
    }
    
    
    if (this->game_phase == "build settlement") {
        if (
            (this->tile_type != TileType :: OCEAN) and
            (this->tile_type != TileType :: LAKE)
        ) {
            if (this->event_ptr->key.code == sf::Keyboard::B) {
                this->__clearDecoration();
                
                this->tile_improvement_ptr = new Settlement(
                    this->position_x,
                    this->position_y,
                    this->event_ptr,
                    this->render_window_ptr,
                    this->assets_manager_ptr,
                    this->message_hub_ptr
                );
                
                this->has_improvement = true;
                
                this->assess();
                this->__sendAssessNeighboursMessage();
                
                this->__sendUpdateGamePhaseMessage("system management");
                this->__sendCreditsSpentMessage(BUILD_SETTLEMENT_COST);
                this->__sendTileStateMessage();
                this->__sendGameStateRequest();
            }
        }
    }
    
    
    else if (this->game_phase == "system management") {
        if (this->has_improvement) {
            //...
        }
        
        
        else if (not this->resource_assessed) {
            if (this->event_ptr->key.code == sf::Keyboard::A) {
                if (this->credits < RESOURCE_ASSESSMENT_COST) {
                    std::cout << "Cannot assess resource: insufficient credits (need "
                        << RESOURCE_ASSESSMENT_COST << " K)" << std::endl;
                        
                    this->__sendInsufficientCreditsMessage();
                }
                
                else {
                    this->assess();
                    this->__sendCreditsSpentMessage(RESOURCE_ASSESSMENT_COST);
                    this->__sendTileStateMessage();
                    this->__sendGameStateRequest();
                }
            }
        }
        
        
        else if (not this->decoration_cleared) {
            if (this->event_ptr->key.code == sf::Keyboard::C) {
                int clear_cost = 0;
                
                switch (this->tile_type) {
                    case (TileType :: FOREST): {
                        clear_cost = CLEAR_FOREST_COST;
                        
                        break;
                    }
                    
                    
                    case (TileType :: MOUNTAINS): {
                        clear_cost = CLEAR_MOUNTAINS_COST;
                        
                        break;
                    }
                    
                    
                    case (TileType :: PLAINS): {
                        clear_cost = CLEAR_PLAINS_COST;
                        
                        break;
                    }
                    
                    
                    default: {
                        // do nothing!
                        
                        break;
                    }
                }
                
                if (this->credits < clear_cost) {
                    std::cout << "Cannot clear tile: insufficient credits (need "
                        << clear_cost << " K)" << std::endl;
                        
                    this->__sendInsufficientCreditsMessage();
                }
                
                else {
                    this->__clearDecoration();
                    this->__sendCreditsSpentMessage(clear_cost);
                    this->__sendTileStateMessage();
                    this->__sendGameStateRequest();
                }
            }
        }
        
        
        else {
            //...
        }
    }

    return;
}   /* __handleKeyPressEvents() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn HexTile :: __handleMouseButtonEvents(void)
///
/// \brief Helper method to handle mouse button events.
///

void HexTile :: __handleMouseButtonEvents(void)
{
    switch (this->event_ptr->mouseButton.button) {
        case (sf::Mouse::Left): {
            if (this->__isClicked()) {
                std::cout << "Tile (" << this->position_x << ", " <<
                    this->position_y << ") was selected" << std::endl;
                
                this->__setIsSelected(true);
                
                this->__sendTileSelectedMessage();
                this->__sendTileStateMessage();
                this->__sendGameStateRequest();
            }
            
            else {
                this->__setIsSelected(false);
            }
            
            break;
        }
        
        
        case (sf::Mouse::Right): {
            this->__setIsSelected(false);
            
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
/// \fn void HexTile :: __sendTileSelectedMessage(void)
///
/// \brief Helper method to format and send message on tile selection.
///

void HexTile :: __sendTileSelectedMessage(void)
{
    Message tile_selected_message;
    
    tile_selected_message.channel = TILE_SELECTED_CHANNEL;
    tile_selected_message.subject = "tile selected";
    
    this->message_hub_ptr->sendMessage(tile_selected_message);
    
    return;
}   /* __sendTileSelectedMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string HexTile :: __getTileCoordsSubstring(void)
///
/// \brief Helper method to assemble and return tile coordinates substring.
///
/// \return Tile coordinates substring.
///

std::string HexTile :: __getTileCoordsSubstring(void)
{
    std::string coords_substring = "TILE COORDS:  (";
    coords_substring += std::to_string(int(this->position_x - 400));
    coords_substring += ", ";
    coords_substring += std::to_string(int(this->position_y - 400));
    coords_substring += ")\n";
    
    return coords_substring;
}   /* __getTileCoordsSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string HexTile :: __getTileTypeSubstring(void)
///
/// \brief Helper method to assemble and return tile type substring.
///
/// \return Tile type substring.
///

std::string HexTile :: __getTileTypeSubstring(void)
{
    std::string type_substring = "TILE TYPE:         ";
    
    switch (this->tile_type) {
        case (TileType :: FOREST): {
            type_substring += "FOREST\n";
            
            break;
        }
        
        
        case (TileType :: LAKE): {
            type_substring += "LAKE\n";
            
            break;
        }
        
        
        case (TileType :: MOUNTAINS): {
            type_substring += "MOUNTAINS\n";
            
            break;
        }
        
        
        case (TileType :: OCEAN): {
            type_substring += "OCEAN\n";
            
            break;
        }
        
        
        case (TileType :: PLAINS): {
            type_substring += "PLAINS\n";
            
            break;
        }
        
        
        default: {
            type_substring += "???\n";
            
            break;
        }
    }
    
    return type_substring;
}   /* __getTileTypeSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string HexTile :: __getTileResourceSubstring(void)
///
/// \brief Helper method to assemble and return tile resource substring.
///
/// \return Tile resource substring.
///

std::string HexTile :: __getTileResourceSubstring(void)
{
    std::string resource_substring = "TILE RESOURCE:     ";
    
    if (this->resource_assessed) {
        switch (this->tile_resource) {
            case (TileResource :: POOR): {
                resource_substring += "POOR\n";
                
                break;
            }
            
            
            case (TileResource ::BELOW_AVERAGE): {
                resource_substring += "BELOW AVERAGE\n";
                
                break;
            }
            
            
            case (TileResource :: AVERAGE): {
                resource_substring += "AVERAGE\n";
                
                break;
            }
            
            
            case (TileResource :: ABOVE_AVERAGE): {
                resource_substring += "ABOVE AVERAGE\n";
                
                break;
            }
            
            
            case (TileResource :: GOOD): {
                resource_substring += "GOOD\n";
                
                break;
            }
            
            
            default: {
                resource_substring += "???\n";
                
                break;
            }
        }
    }
    
    else {
        resource_substring += "???\n";
    }
    
    return resource_substring;
}   /* __getTileResourceSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string HexTile :: __getTileImprovementSubstring(void)
///
/// \brief Helper method to assemble and return the tile improvement substring.
///
/// \return Tile improvement substring.
///

std::string HexTile :: __getTileImprovementSubstring(void)
{
    std::string improvement_substring = "TILE IMPROVEMENT:  ";
    
    if (this->has_improvement) {
        switch(this->tile_improvement_ptr->tile_improvement_type) {
            case (TileImprovementType :: SETTLEMENT): {
                improvement_substring += "SETTLEMENT\n";
                
                break;
            }
            
            
            default: {
                improvement_substring += "???\n";
                
                break;
            }
        }
    }
    
    else {
        improvement_substring += "NONE\n";
    }
    
    return improvement_substring;
}   /* __getTileImprovementSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string HexTile :: __getTileOptionsSubstring(void)
///
/// \brief Helper method to assemble and return tile options substring.
///
/// \return Tile options substring.
///

std::string HexTile :: __getTileOptionsSubstring(void)
{
    //                   32 char x 17 line console "--------------------------------\n";
    std::string options_substring                = "     **** TILE OPTIONS ****     \n";
    options_substring                           += "                                \n";
    
    if (this->game_phase == "build settlement") {
        if (
            (this->tile_type != TileType :: OCEAN) and
            (this->tile_type != TileType :: LAKE)
        ) {
            options_substring += "[B]:  BUILD SETTLEMENT (";
            options_substring += std::to_string(BUILD_SETTLEMENT_COST);
            options_substring += " K)";
        }
    }
    
    
    else if (this->game_phase == "system management") {
        if (this->has_improvement) {
            //...
        }
        
        
        else if (not this->resource_assessed) {
            options_substring += "[A]:  ASSESS RESOURCE (";
            options_substring += std::to_string(RESOURCE_ASSESSMENT_COST);
            options_substring += " K)\n";
        }
        
        
        else if (not this->decoration_cleared) {
            if (
                (this->tile_type != TileType :: OCEAN) and
                (this->tile_type != TileType :: LAKE)
            ) {
                options_substring += "[C]:  CLEAR TILE (";
                
                switch (this->tile_type) {
                    case (TileType :: FOREST): {
                        options_substring += std::to_string(CLEAR_FOREST_COST);
                        
                        break;
                    }
                    
                    
                    case (TileType :: MOUNTAINS): {
                        options_substring += std::to_string(CLEAR_MOUNTAINS_COST);
                        
                        break;
                    }
                    
                    
                    case (TileType :: PLAINS): {
                        options_substring += std::to_string(CLEAR_PLAINS_COST);
                        
                        break;
                    }
                    
                    
                    default: {
                        //do nothing!
                        
                        break;
                    }
                }
                
                options_substring += " K)\n";
            }
        }
        
        
        else {
            //...
        }
    }
    
    
    else if (this->game_phase == "victory") {
        options_substring                       += "       **** VICTORY ****        \n";
    }
    
    
    else {
        options_substring                       += "        **** LOSS ****          \n";
    }
    
    return options_substring;
}   /* __getTileOptionsString() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __sendTileStateMessage(void)
///
/// \brief Helper method to format and send tile state message.
///

void HexTile :: __sendTileStateMessage(void)
{
    Message tile_state_message;
    
    tile_state_message.channel = TILE_STATE_CHANNEL;
    tile_state_message.subject = "tile state";
    
    
    //                   32 char x 17 line console "--------------------------------\n";
    std::string console_string                   = "      **** TILE INFO ****       \n";
    console_string                              += "                                \n";
    
    console_string                              += this->__getTileCoordsSubstring();
    console_string                              += "                                \n";
    
    console_string                              += this->__getTileTypeSubstring();
    console_string                              += this->__getTileResourceSubstring();
    console_string                              += this->__getTileImprovementSubstring();
    console_string                              += "                                \n";

    console_string                              += this->__getTileOptionsSubstring();
    
    
    tile_state_message.string_payload["console string"] = console_string;
    
    this->message_hub_ptr->sendMessage(tile_state_message);
    
    std::cout << "Tile state message sent by " << this << std::endl;
    return;
}   /* __sendTileStateMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __sendAssessNeighboursMessage(void)
///
/// \brief Helper method to format and send assess neighbours message.
///

void HexTile :: __sendAssessNeighboursMessage(void)
{
    Message assess_neighbours_message;
    
    assess_neighbours_message.channel = HEX_MAP_CHANNEL;
    assess_neighbours_message.subject = "assess neighbours";
    
    this->message_hub_ptr->sendMessage(assess_neighbours_message);
    
    std::cout << "Assess neighbours message sent by " << this << std::endl;
    
    return;
}   /* __sendAssessNeighboursMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __sendGameStateRequest(void)
///
/// \brief Helper method to format and send a game state request (message).
///

void HexTile :: __sendGameStateRequest(void)
{
    Message game_state_request;
    
    game_state_request.channel = GAME_CHANNEL;
    game_state_request.subject = "state request";
    
    this->message_hub_ptr->sendMessage(game_state_request);
    
    std::cout << "Game state request message sent by " << this << std::endl;
    return;
}   /* __sendGameStateRequest() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __sendUpdateGamePhaseMessage(void)
///
/// \brief Helper method to format and send update game phase message.
///
/// \param game_phase The updated game phase.
///

void HexTile :: __sendUpdateGamePhaseMessage(std::string game_phase)
{
    Message update_game_phase_message;
    
    update_game_phase_message.channel = GAME_CHANNEL;
    update_game_phase_message.subject = "update game phase";
    
    update_game_phase_message.string_payload["game phase"] = game_phase;
    
    this->message_hub_ptr->sendMessage(update_game_phase_message);
    
    std::cout << "Update game phase message sent by " << this << std::endl;
    
    return;
}   /* __sendUpdateGamePhaseMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __sendCreditsSpentMessage(int credits_spent)
///
/// \brief Helper method to format and send a credits spent message.
///
/// \param credits_spent The number of credits that were spent.
///

void HexTile :: __sendCreditsSpentMessage(int credits_spent)
{
    Message credits_spent_message;
    
    credits_spent_message.channel = GAME_CHANNEL;
    credits_spent_message.subject = "credits spent";
    
    credits_spent_message.int_payload["credits spent"] = credits_spent;
    
    this->message_hub_ptr->sendMessage(credits_spent_message);
    
    std::cout << "Credits spent (" << credits_spent << ") message sent by " << this
        << std::endl;
    return;
}   /* __sendCreditsSpentMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: __sendInsufficientCreditsMessage(void)
///
/// \brief Helper method to format and send an insufficient credits message.
///

void HexTile :: __sendInsufficientCreditsMessage(void)
{
    Message insufficient_credits_message;
    
    insufficient_credits_message.channel = GAME_CHANNEL;
    insufficient_credits_message.subject = "insufficient credits";
    
    this->message_hub_ptr->sendMessage(insufficient_credits_message);
    
    std::cout << "Insufficient credits message sent by " << this << std::endl;
    
    return;
}   /* __sendInsufficientCreditsMessage() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn HexTile :: HexTile(
///         double position_x,
///         double position_y,
///         sf::Event* event_ptr,
///         sf::RenderWindow* render_window_ptr,
///         AssetsManager* assets_manager_ptr,
///         MessageHub* message_hub_ptr
///     )
///
/// \brief Constructor for the HexTile class.
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

HexTile :: HexTile(
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
    this->show_node = false;
    this->show_resource = false;
    this->resource_assessed = false;
    this->resource_assessment = false;
    this->is_selected = false;
    this->draw_explosion = false;
    
    this->decoration_cleared = false;
    this->has_improvement = false;
    this->tile_improvement_ptr = NULL;
    
    this->explosion_frame = 0;
    
    this->frame = 0;
    this->credits = 0;
    
    this->position_x = position_x;
    this->position_y = position_y;
    
    this->major_radius = 32;
    this->minor_radius = (sqrt(3) / 2) * this->major_radius;
    
    this->game_phase = "build settlement";
    
    //  2. set up and position drawable attributes
    this->__setUpNodeSprite();
    this->__setUpTileSprite();
    this->__setUpSelectOutlineSprite();
    this->__setUpResourceChipSprite();
    this->__setResourceText();
    this->__setUpMagnifyingGlassSprite();
    this->__setUpTileExplosionReel();
    
    //  3. set tile type and resource (default to none type and average)
    this->setTileType(TileType :: NONE_TYPE);
    this->setTileResource(TileResource :: AVERAGE);
    
    std::cout << "HexTile constructed at " << this << std::endl;
    
    return;
}   /* HexTile() */

// ---------------------------------------------------------------------------------- //


// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: setTileType(TileType tile_type)
///
/// \brief Method to set the tile type (by enum value).
///
/// \param tile_type The type (TileType) to set the tile to.

void HexTile :: setTileType(TileType tile_type)
{
    this->tile_type = tile_type;
    
    switch (this->tile_type) {
        case (TileType :: FOREST): {
            this->tile_sprite.setFillColor(FOREST_GREEN);

            break;
        }
        
        case (TileType :: LAKE): {
            this->tile_sprite.setFillColor(LAKE_BLUE);
            
            break;
        }
        
        case (TileType :: MOUNTAINS): {
            this->tile_sprite.setFillColor(MOUNTAINS_GREY);
            
            break;
        }
        
        case (TileType :: OCEAN): {
            this->tile_sprite.setFillColor(OCEAN_BLUE);
            
            break;
        }
        
        case (TileType :: PLAINS): {
            this->tile_sprite.setFillColor(PLAINS_YELLOW);
            
            break;
        }
        
        default: {
            // do nothing!
            
            break;
        }
    }
    
    return;
}   /* setTileType(TileType) */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: setTileType(double input_value)
///
/// \brief Method to set the tile type (by numeric input).
///
/// \param input_value A numerical input in the closed interval [0, 1].
///

void HexTile :: setTileType(double input_value)
{
    //  1. check input
    if (input_value < 0 or input_value > 1) {
        std::string error_str = "ERROR  HexTile::setTileType()  given input value is ";
        error_str += "not in the closed interval [0, 1]";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. convert input value to tile type
    TileType tile_type;
    
    if (input_value <= TILE_TYPE_CUMULATIVE_PROBABILITIES[0]) {
        tile_type = TileType :: LAKE;
    }
    else if (input_value <= TILE_TYPE_CUMULATIVE_PROBABILITIES[1]) {
        tile_type = TileType :: PLAINS;
    }
    else if (input_value <= TILE_TYPE_CUMULATIVE_PROBABILITIES[2]) {
        tile_type = TileType :: FOREST;
    }
    else {
        tile_type = TileType :: MOUNTAINS;
    }
    
    //  3. call alternate method
    this->setTileType(tile_type);
    
    return;
}   /* setTileType(double) */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: setTileResource(TileResource tile_resource)
///
/// \brief Method to set the tile resource (by enum value).
///
/// \param tile_resource The resource (TileResource) value to attribute to the tile.
///

void HexTile :: setTileResource(TileResource tile_resource)
{
    this->tile_resource = tile_resource;
    this->__setResourceText();
    
    return;
}   /* setTileResource(TileResource) */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: setTileResource(double input_value)
///
/// \brief Method to set the tile resource (by numeric input).
///
/// \param input_value A numerical input in the closed interval [0, 1].
///

void HexTile :: setTileResource(double input_value)
{
    //  1. check input
    if (input_value < 0 or input_value > 1) {
        std::string error_str = "ERROR  HexTile::setTileResource()  given input value is ";
        error_str += "not in the closed interval [0, 1]";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. convert input value to tile resource
    TileResource tile_resource;
    
    if (input_value <= TILE_RESOURCE_CUMULATIVE_PROBABILITIES[0]) {
        tile_resource = TileResource :: POOR;
    }
    else if (input_value <= TILE_RESOURCE_CUMULATIVE_PROBABILITIES[1]) {
        tile_resource = TileResource :: BELOW_AVERAGE;
    }
    else if (input_value <= TILE_RESOURCE_CUMULATIVE_PROBABILITIES[2]) {
        tile_resource = TileResource :: AVERAGE;
    }
    else if (input_value <= TILE_RESOURCE_CUMULATIVE_PROBABILITIES[3]) {
        tile_resource = TileResource :: ABOVE_AVERAGE;
    }
    else {
        tile_resource = TileResource :: GOOD;
    }
    
    //  3. call alternate method
    this->setTileResource(tile_resource);
    
    return;
}   /* setTileResource(double) */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: decorateTile(void)
///
/// \brief Method to decorate tile.
///

void HexTile :: decorateTile(void)
{
    switch (this->tile_type) {
        case (TileType :: FOREST): {
            this->tile_decoration_sprite.setTexture(
                *(this->assets_manager_ptr->getTexture("pine_tree_64x64_1"))
            );
            
            break;
        }
        
        case (TileType :: LAKE): {
            this->tile_decoration_sprite.setTexture(
                *(this->assets_manager_ptr->getTexture("water_shimmer_64x64_1"))
            );
            
            break;
        }
        
        case (TileType :: MOUNTAINS): {
            this->tile_decoration_sprite.setTexture(
                *(this->assets_manager_ptr->getTexture("mountain_64x64_1"))
            );
            
            break;
        }
        
        case (TileType :: OCEAN): {
            this->tile_decoration_sprite.setTexture(
                *(this->assets_manager_ptr->getTexture("water_waves_64x64_1"))
            );
            
            break;
        }
        
        case (TileType :: PLAINS): {
            this->tile_decoration_sprite.setTexture(
                *(this->assets_manager_ptr->getTexture("wheat_64x64_1"))
            );
            
            break;
        }
        
        default: {
            // do nothing!
            
            break;
        }
    }
    
    
    if (this->tile_type == TileType :: OCEAN or this->tile_type == TileType :: LAKE) {
        this->tile_decoration_sprite.setOrigin(
            this->tile_decoration_sprite.getLocalBounds().width / 2,
            this->tile_decoration_sprite.getLocalBounds().height / 2
        );
        
        this->tile_decoration_sprite.setPosition(
            this->position_x,
            this->position_y
        );
        
        if ((double)rand() / RAND_MAX > 0.5) {
            this->tile_decoration_sprite.setScale(sf::Vector2f(-1, 1));
        }
    }
    
    else {
        this->tile_decoration_sprite.setOrigin(
            this->tile_decoration_sprite.getLocalBounds().width / 2,
            this->tile_decoration_sprite.getLocalBounds().height
        );
        
        this->tile_decoration_sprite.setPosition(
            this->position_x,
            this->position_y + 12
        );
        
        if ((double)rand() / RAND_MAX > 0.5) {
            this->tile_decoration_sprite.setScale(sf::Vector2f(-1, 1));
        }
    }
    
    return;
}   /* decorateTile(void) */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: toggleResourceOverlay(void)
///
/// \brief Method to toggle the tile resource overlay.
///

void HexTile :: toggleResourceOverlay(void)
{
    if (this->show_resource) {
        this->show_resource = false;
    }
    else {
        this->show_resource = true;
    }
    
    return;
}   /* toggleResourceOverlay() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: assess(void)
///
/// \brief Method to assess the tile's resource.
///

void HexTile :: assess(void)
{
    this->resource_assessed = true;
    this->resource_assessment = true;
    
    this->assets_manager_ptr->getSound("resource assessment")->play();
    
    this->__setResourceText();
    this->__sendTileStateMessage();
    
    return;
}   /* assess() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: processEvent(void)
///
/// \brief Method to process HexTile. To be called once per event.
///

void HexTile :: processEvent(void)
{
    //  1. process TileImprovement events
    if (this->tile_improvement_ptr != NULL) {
        this->tile_improvement_ptr->processEvent();
    }
    
    //  2. process HexTile events
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
/// \fn void HexTile :: processMessage(void)
///
/// \brief Method to process HexTile. To be called once per message.
///

void HexTile :: processMessage(void)
{
    //  1. process TileImprovement messages
    if (this->tile_improvement_ptr != NULL) {
        this->tile_improvement_ptr->processMessage();
    }
    
    //  2. process HexTile messages
    if (this->is_selected) {
        if (not this->message_hub_ptr->isEmpty(GAME_STATE_CHANNEL)) {
            Message game_state_message = this->message_hub_ptr->receiveMessage(
                GAME_STATE_CHANNEL
            );
            
            if (game_state_message.subject == "game state") {
                this->credits = game_state_message.int_payload["credits"];
                this->game_phase = game_state_message.string_payload["game phase"];
                
                if (this->tile_improvement_ptr != NULL) {
                    this->tile_improvement_ptr->credits = this->credits;
                    this->tile_improvement_ptr->game_phase = this->game_phase;
                }
                
                std::cout << "Game state message received by " << this << std::endl;
                this->__sendTileStateMessage();
                this->message_hub_ptr->popMessage(GAME_STATE_CHANNEL);
            }
        }
        
        std::cout << "Current credits (HexTile): " << this->credits << " K" <<
            std::endl;
    }
    
    return;
}   /* processMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: draw(void)
///
/// \brief Method to draw the hex tile to the render window. To be called once per
///     frame.
///

void HexTile :: draw(void)
{
    //  1. draw hex
    this->render_window_ptr->draw(this->tile_sprite);
    
    //  2. draw node
    if (this->show_node) {
        this->render_window_ptr->draw(this->node_sprite);
    }
    
    //  3. draw tile decoration
    if (not this->decoration_cleared) {
        this->render_window_ptr->draw(this->tile_decoration_sprite);
    }
    
    //  4. draw tile improvement
    if (this->has_improvement) {
        this->tile_improvement_ptr->draw();
    }
    
    //  5. draw resource
    if (this->show_resource) {
        this->render_window_ptr->draw(this->resource_chip_sprite);
        this->render_window_ptr->draw(this->resource_text);
    }
    
    //  6. draw selection outline
    if (this->is_selected) {
        sf::Color outline_colour = this->select_outline_sprite.getOutlineColor();
        
        outline_colour.a =
            255 * pow(cos((M_PI * this->frame) / (1.5 * FRAMES_PER_SECOND)), 2);
        
        this->select_outline_sprite.setOutlineColor(outline_colour);
        
        this->render_window_ptr->draw(this->select_outline_sprite);
    }
    
    //  7. draw resource assessment notification
    if (this->resource_assessment) {
        int alpha = this->magnifying_glass_sprite.getColor().a;
        
        alpha -= 0.05 * FRAMES_PER_SECOND;
        if (alpha < 0) {
            alpha = 0;
            this->resource_assessment = false;
        }
        
        this->magnifying_glass_sprite.setColor(
            sf::Color(255, 255, 255, alpha)
        );
        
        this->render_window_ptr->draw(this->magnifying_glass_sprite);
    }
    
    //  8. draw explosion
    if (this->draw_explosion) {
        this->render_window_ptr->draw(this->explosion_sprite_reel[this->explosion_frame]);
        
        if (this->frame % (FRAMES_PER_SECOND / 10) == 0) {
            this->explosion_frame++;
        }
        
        if (this->explosion_frame >= this->explosion_sprite_reel.size()) {
            this->draw_explosion = false;
        }
    }
    
    this->frame++;
    return;
}   /* draw() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn HexTile :: ~HexTile(void)
///
/// \brief Destructor for the HexTile class.
///

HexTile :: ~HexTile(void)
{
    if (this->tile_improvement_ptr != NULL) {
        delete this->tile_improvement_ptr;
    }
    
    std::cout << "HexTile at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~HexTile() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
