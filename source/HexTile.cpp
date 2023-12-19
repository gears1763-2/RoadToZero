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
    
    this->resource_chip_sprite.setFillColor(sf::Color(175, 175, 175, 175));
    
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
    
    switch (this->tile_resource) {
        case (TileResource :: POOR): {
            this->resource_text.setString("-2");
            
            break;
        }
        
        case (TileResource :: BELOW_AVERAGE): {
            this->resource_text.setString("-1");
            
            break;
        }
        
        case (TileResource :: AVERAGE): {
            this->resource_text.setString("0");
            
            break;
        }
        
        case (TileResource :: ABOVE_AVERAGE): {
            this->resource_text.setString("+1");
            
            break;
        }
        
        case (TileResource :: GOOD): {
            this->resource_text.setString("+2");
            
            break;
        }
        
        default: {
            this->resource_text.setString("?");
            
            break;
        }
    }
    
    if (not this->resource_assessed) {
        this->resource_text.setString("?");
    }
    
    this->resource_text.setCharacterSize(16);
    
    this->resource_text.setOrigin(
        this->resource_text.getLocalBounds().width / 2,
        this->resource_text.getLocalBounds().height / 2
    );
    
    this->resource_text.setFillColor(sf::Color(0, 0, 0, 255));
    
    this->resource_text.setPosition(
        this->position_x,
        this->position_y - 4
    );
    
    return;
}   /* __setResourceText() */

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
    switch (this->event_ptr->key.code) {
        case (sf::Keyboard::Escape): {
            this->is_selected = false;
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
                
                this->is_selected = true;
                
                this->__sendTileSelectedMessage();
                this->__sendTileStateMessage();
            }
            
            else {
                this->is_selected = false;
            }
            
            break;
        }
        
        
        case (sf::Mouse::Right): {
            this->is_selected = false;
            
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
            //...
            
            
            default: {
                resource_substring += "???\n";
                
                break;
            }
        }
    }
    
    else {
        resource_substring += "[A]: ASSESS\n";
    }
    
    return resource_substring;
}   /* __getTileResourceSubstring() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn

std::string HexTile :: __getTileImprovementSubstring(void)
{
    std::string improvement_substring = "TILE IMPROVEMENT:  ";
    
    if (this->has_improvement) {
        //...
    }
    
    else {
        improvement_substring += "NONE\n";
    }
    
    return improvement_substring;
}   /* __getTileImprovementSubstring() */

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
    std::string string_payload                   = "  **** TILE INFO/OPTIONS ****   \n";
    string_payload                              += "                                \n";
    
    string_payload                              += this->__getTileCoordsSubstring();
    string_payload                              += "                                \n";
    
    string_payload                              += this->__getTileTypeSubstring();
    string_payload                              += this->__getTileResourceSubstring();
    string_payload                              += this->__getTileImprovementSubstring();
    
    string_payload                              += "                                \n";
    string_payload                              += "                                \n";
    string_payload                              += "                                \n";
    string_payload                              += "                                \n";
    string_payload                              += "                                \n";
    string_payload                              += "                                \n";
    string_payload                              += "                                \n";
    string_payload                              += "                                \n";
    string_payload                              += "                                \n";
    string_payload                              += "                                ";
    
    
    tile_state_message.string_payload = string_payload;
    
    this->message_hub_ptr->sendMessage(tile_state_message);
    
    return;
}   /* __sendTileStateMessage() */

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
    this->is_selected = false;
    
    this->has_improvement = false;
    this->tile_improvement_ptr = NULL;
    
    this->frame = 0;
    
    this->position_x = position_x;
    this->position_y = position_y;
    
    this->major_radius = 32;
    this->minor_radius = (sqrt(3) / 2) * this->major_radius;
    
    //  2. set up and position drawable attributes
    this->__setUpNodeSprite();
    this->__setUpTileSprite();
    this->__setUpSelectOutlineSprite();
    this->__setUpResourceChipSprite();
    this->__setResourceText();
    
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
            //...
            
            break;
        }
        
        case (TileType :: MOUNTAINS): {
            this->tile_decoration_sprite.setTexture(
                *(this->assets_manager_ptr->getTexture("mountain_64x64_1"))
            );
            
            break;
        }
        
        case (TileType :: OCEAN): {
            //...
            
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
    this->__setResourceText();
    
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
    //...
    
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
    this->render_window_ptr->draw(this->tile_decoration_sprite);
    
    //  4. draw resource
    if (this->show_resource) {
        this->render_window_ptr->draw(this->resource_chip_sprite);
        this->render_window_ptr->draw(this->resource_text);
    }
    
    //  5. draw selection outline
    if (this->is_selected) {
        sf::Color outline_colour = this->select_outline_sprite.getOutlineColor();
        
        outline_colour.a =
            255 * pow(cos((M_PI * this->frame) / (1.5 * FRAMES_PER_SECOND)), 2);
        
        this->select_outline_sprite.setOutlineColor(outline_colour);
        
        this->render_window_ptr->draw(this->select_outline_sprite);
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
