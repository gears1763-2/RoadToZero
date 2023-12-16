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


#include "../../header/HexMap/HexTile.h"


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
    
    this->tile_sprite.setOutlineThickness(2);
    this->tile_sprite.setOutlineColor(sf::Color(0, 0, 0, 255));
    
    return;
}   /* __setUpTileSprite() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn HexTile :: HexTile(
///         double position_x,
///         double position_y,
///         AssetsManager* assets_manager_ptr,
///         InputsHandler* inputs_handler_ptr,
///         MessagesHandler* messages_handler_ptr
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
/// \param assets_manager_ptr Pointer to the assets manager.
///
/// \param inputs_handler_ptr Pointer to the inputs handler.
///
/// \param messages_handler_ptr Pointer to the messages handler.
///

HexTile :: HexTile(
    double position_x,
    double position_y,
    AssetsManager* assets_manager_ptr,
    InputsHandler* inputs_handler_ptr,
    MessagesHandler* messages_handler_ptr
)
{
    //  1. set attributes
    this->assets_manager_ptr = assets_manager_ptr;
    this->inputs_handler_ptr = inputs_handler_ptr;
    this->messages_handler_ptr = messages_handler_ptr;
    
    this->show_node = false;
    
    this->frame = 0;
    
    this->position_x = position_x;
    this->position_y = position_y;
    
    this->major_radius = 32;
    this->minor_radius = (sqrt(3) / 2) * this->major_radius;
    
    //  2. set up and position the node sprite
    this->__setUpNodeSprite();
    
    //  3. set up and position the tile sprite
    this->__setUpTileSprite();
    
    //  4. set tile type and resource (default to forest and average)
    this->setTileType(TileType :: FOREST);
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
    
    std::cout << input_value << std::endl;
    if (input_value <= tile_type_cumulative_probabilities[0]) {
        tile_type = TileType :: LAKE;
    }
    else if (input_value <= tile_type_cumulative_probabilities[1]) {
        tile_type = TileType :: PLAINS;
    }
    else if (input_value <= tile_type_cumulative_probabilities[2]) {
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
    
    return;
}   /* setTileType() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: process(void)
///
/// \brief Method to process HexTile. To be called once per frame.
///

void HexTile :: process(void)
{
    //...

    return;
}   /* process() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexTile :: draw(sf::RenderWindow* window_ptr)
///
/// \brief Method to draw the hex tile to the render window. To be called only once per
///     frame!
///
/// \param window_ptr A pointer to the render window.
///

void HexTile :: draw(sf::RenderWindow* window_ptr)
{
    //  1. draw hex
    window_ptr->draw(this->tile_sprite);
    
    //  2. draw node
    if (this->show_node) {
        window_ptr->draw(this->node_sprite);
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
    std::cout << "HexTile at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~HexTile() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
