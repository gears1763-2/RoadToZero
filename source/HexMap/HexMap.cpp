/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the HexMap class.
 *
 */


///
/// \file HexMap.cpp
///
/// \brief Implementation file for the HexMap class.
///
/// A class which defines a hex map of hex tiles.
///


#include "../../header/HexMap/HexMap.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void HexMap :: __assembleHexMap(void)
///
/// \brief Helper method to assemble the hex map.
///

void HexMap :: __assembleHexMap(void)
{
    //  1. add origin tile
    HexTile* hex_ptr = new HexTile(
        this->position_x,
        this->position_y,
        this->assets_manager_ptr,
        this->inputs_handler_ptr,
        this->messages_handler_ptr
    );
    
    this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
    
    
    //  2. fill out first row (reflect across origin tile)
    for (int i = 0; i < this->n_layers; i++) {
        hex_ptr = new HexTile(
            this->position_x + 2 * (i + 1) * hex_ptr->minor_radius,
            this->position_y,
            this->assets_manager_ptr,
            this->inputs_handler_ptr,
            this->messages_handler_ptr
        );
        
        this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
        
        hex_ptr = new HexTile(
            this->position_x - 2 * (i + 1) * hex_ptr->minor_radius,
            this->position_y,
            this->assets_manager_ptr,
            this->inputs_handler_ptr,
            this->messages_handler_ptr
        );
        
        this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
    }
    
    
    //  3. fill out subsequent rows (reflect across first row)
    HexTile* first_row_left_tile = hex_ptr;
    
    int offset_count = 1;
    
    double x_offset = 0;
    double y_offset = 0;
    
    for (
        int row_width = 2 * this->n_layers;
        row_width > this->n_layers;
        row_width--
    ) {
        //  3.1. upper row
        x_offset = first_row_left_tile->position_x +
            2 * offset_count * first_row_left_tile->minor_radius *
            cos(60 * (M_PI / 180));
        
        y_offset = first_row_left_tile->position_y -
            2 * offset_count * first_row_left_tile->minor_radius *
            sin(60 * (M_PI / 180));
        
        hex_ptr = new HexTile(
            x_offset,
            y_offset,
            this->assets_manager_ptr,
            this->inputs_handler_ptr,
            this->messages_handler_ptr
        );
        
        this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
        
        for (int i = 1; i < row_width; i++) {
            x_offset += 2 * first_row_left_tile->minor_radius;
            
            hex_ptr = new HexTile(
                x_offset,
                y_offset,
                this->assets_manager_ptr,
                this->inputs_handler_ptr,
                this->messages_handler_ptr
            );
        
            this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
        }
        
        //  3.2. lower row
        x_offset = first_row_left_tile->position_x +
            2 * offset_count * first_row_left_tile->minor_radius *
            cos(60 * (M_PI / 180));
        
        y_offset = first_row_left_tile->position_y +
            2 * offset_count * first_row_left_tile->minor_radius *
            sin(60 * (M_PI / 180));
        
        hex_ptr = new HexTile(
            x_offset,
            y_offset,
            this->assets_manager_ptr,
            this->inputs_handler_ptr,
            this->messages_handler_ptr
        );
        
        this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
        
        for (int i = 1; i < row_width; i++) {
            x_offset += 2 * first_row_left_tile->minor_radius;
            
            hex_ptr = new HexTile(
                x_offset,
                y_offset,
                this->assets_manager_ptr,
                this->inputs_handler_ptr,
                this->messages_handler_ptr
            );
        
            this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
        }
        
        offset_count++;
    }
    
    return;
}   /* __assembleHexMap() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn HexMap :: HexMap(
///         int n_layers,
///         AssetsManager* assets_manager_ptr,
///         InputsHandler* inputs_handler_ptr,
///         MessagesHandler* messages_handler_ptr
///     )
///
/// \brief Constructor for the HexMap class.
///
/// \param n_layers The number of layers in the HexMap.
///
/// \param assets_manager_ptr Pointer to the assets manager.
///
/// \param inputs_handler_ptr Pointer to the inputs handler.
///
/// \param messages_handler_ptr Pointer to the messages handler.
///

HexMap :: HexMap(
    int n_layers,
    AssetsManager* assets_manager_ptr,
    InputsHandler* inputs_handler_ptr,
    MessagesHandler* messages_handler_ptr
)
{
    //  1. set attributes
    this->assets_manager_ptr = assets_manager_ptr;
    this->inputs_handler_ptr = inputs_handler_ptr;
    this->messages_handler_ptr = messages_handler_ptr;
    
    this->frame = 0;
    
    this->n_layers = n_layers;
    if (this->n_layers < 0) {
        this->n_layers = 0;
    }
    
    this->position_x = 400;
    this->position_y = 400;
    
    //  2. assemble n layer hex map
    this->__assembleHexMap();
    
    std::cout << "HexMap constructed at " << this << std::endl;
    
    return;
}   /* HexMap() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexMap :: draw(sf::RenderWindow* window_ptr)
///
/// \brief Method to draw the hex map to the render window. To be called only once per
///     frame!
///
/// \param window_ptr A pointer to the render window.
///

void HexMap :: draw(sf::RenderWindow* window_ptr)
{
    std::map<double, std::map<double, HexTile*>>::iterator hex_map_iter_x;
    std::map<double, HexTile*>::iterator hex_map_iter_y;
    for (
        hex_map_iter_x = this->hex_map.begin();
        hex_map_iter_x != this->hex_map.end();
        hex_map_iter_x++
    ) {
        for (
            hex_map_iter_y = hex_map_iter_x->second.begin();
            hex_map_iter_y != hex_map_iter_x->second.end();
            hex_map_iter_y++
        ) {
            hex_map_iter_y->second->draw(window_ptr);
        }
    }
    
    this->frame++;
    return;
}   /* draw() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexMap :: clear(void)
///
/// \brief Method to clear the hex map.
///

void HexMap :: clear(void)
{
    std::map<double, std::map<double, HexTile*>>::iterator hex_map_iter_x;
    std::map<double, HexTile*>::iterator hex_map_iter_y;
    for (
        hex_map_iter_x = this->hex_map.begin();
        hex_map_iter_x != this->hex_map.end();
        hex_map_iter_x++
    ) {
        for (
            hex_map_iter_y = hex_map_iter_x->second.begin();
            hex_map_iter_y != hex_map_iter_x->second.end();
            hex_map_iter_y++
        ) {
            delete hex_map_iter_y->second;
        }
    }
    this->hex_map.clear();
    
    return;
}   /* clear() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn HexMap :: ~HexMap(void)
///
/// \brief Destructor for the HexMap class.
///

HexMap :: ~HexMap(void)
{
    this->clear();
    
    std::cout << "HexMap at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~HexMap() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
