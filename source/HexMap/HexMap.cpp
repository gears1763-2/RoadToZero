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
/// \fn void HexMap :: __layTiles(void)
///
/// \brief Helper method to lay the hex tiles down to generate the game world.
///

void HexMap :: __layTiles(void)
{
    this->n_tiles = 0;
    
    //  1. add origin tile
    HexTile* hex_ptr = new HexTile(
        this->position_x,
        this->position_y,
        this->assets_manager_ptr,
        this->inputs_handler_ptr,
        this->messages_handler_ptr,
        this->render_window_ptr
    );
    
    this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
    this->tile_position_x_vec.push_back(hex_ptr->position_x);
    this->tile_position_y_vec.push_back(hex_ptr->position_y);
    this->n_tiles++;
    
    
    //  2. fill out first row (reflect across origin tile)
    for (int i = 0; i < this->n_layers; i++) {
        hex_ptr = new HexTile(
            this->position_x + 2 * (i + 1) * hex_ptr->minor_radius,
            this->position_y,
            this->assets_manager_ptr,
            this->inputs_handler_ptr,
            this->messages_handler_ptr,
            this->render_window_ptr
        );
        
        this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
        this->tile_position_x_vec.push_back(hex_ptr->position_x);
        this->tile_position_y_vec.push_back(hex_ptr->position_y);
        this->n_tiles++;
        
        if (i == this->n_layers - 1) {
            this->border_tiles_vec.push_back(hex_ptr);
        }
        
        hex_ptr = new HexTile(
            this->position_x - 2 * (i + 1) * hex_ptr->minor_radius,
            this->position_y,
            this->assets_manager_ptr,
            this->inputs_handler_ptr,
            this->messages_handler_ptr,
            this->render_window_ptr
        );
        
        this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
        this->tile_position_x_vec.push_back(hex_ptr->position_x);
        this->tile_position_y_vec.push_back(hex_ptr->position_y);
        this->n_tiles++;
        
        if (i == this->n_layers - 1) {
            this->border_tiles_vec.push_back(hex_ptr);
        }
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
            this->messages_handler_ptr,
            this->render_window_ptr
        );
        
        this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
        this->tile_position_x_vec.push_back(hex_ptr->position_x);
        this->tile_position_y_vec.push_back(hex_ptr->position_y);
        this->n_tiles++;
        
        this->border_tiles_vec.push_back(hex_ptr);
        
        for (int i = 1; i < row_width; i++) {
            x_offset += 2 * first_row_left_tile->minor_radius;
            
            hex_ptr = new HexTile(
                x_offset,
                y_offset,
                this->assets_manager_ptr,
                this->inputs_handler_ptr,
                this->messages_handler_ptr,
                this->render_window_ptr
            );
        
            this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
            this->tile_position_x_vec.push_back(hex_ptr->position_x);
            this->tile_position_y_vec.push_back(hex_ptr->position_y);
            this->n_tiles++;
            
            if (row_width == this->n_layers + 1 or i == row_width - 1) {
                this->border_tiles_vec.push_back(hex_ptr);
            }
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
            this->messages_handler_ptr,
            this->render_window_ptr
        );
        
        this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
        this->tile_position_x_vec.push_back(hex_ptr->position_x);
        this->tile_position_y_vec.push_back(hex_ptr->position_y);
        this->n_tiles++;
        
        this->border_tiles_vec.push_back(hex_ptr);
        
        for (int i = 1; i < row_width; i++) {
            x_offset += 2 * first_row_left_tile->minor_radius;
            
            hex_ptr = new HexTile(
                x_offset,
                y_offset,
                this->assets_manager_ptr,
                this->inputs_handler_ptr,
                this->messages_handler_ptr,
                this->render_window_ptr
            );
        
            this->hex_map[hex_ptr->position_x][hex_ptr->position_y] = hex_ptr;
            this->tile_position_x_vec.push_back(hex_ptr->position_x);
            this->tile_position_y_vec.push_back(hex_ptr->position_y);
            this->n_tiles++;
            
            if (row_width == this->n_layers + 1 or i == row_width - 1) {
                this->border_tiles_vec.push_back(hex_ptr);
            }
        }
        
        offset_count++;
    }
    
    return;
}   /* __layTiles() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::vector<double> HexMap :: __getNoise(int n_elements, int n_components)
///
/// \brief Helper method to generate a vector of noise, with values mapped to the closed
///     interval [0, 1]. Applies a random cosine series approach.
///
/// \param n_elements The number of elements in the generated noise vector.
///
/// \param n_components The number of components to use in the random cosine series.
///     Defaults to 64.
///
/// \return A vector of noise, with values mapped to the closed interval [0, 1].
///

std::vector<double> HexMap :: __getNoise(int n_elements, int n_components)
{
    //  1. generate random amplitude, wave number, direction, and phase vectors
    std::vector<double> random_amplitude_vec(n_components, 0);
    std::vector<double> random_wave_number_vec(n_components, 0);
    std::vector<double> random_frequency_vec(n_components, 0);
    std::vector<double> random_direction_vec(n_components, 0);
    std::vector<double> random_phase_vec(n_components, 0);
    
    for (int i = 0; i < n_components; i++) {
        random_amplitude_vec[i] = 10 * ((double)rand() / RAND_MAX);
        
        random_wave_number_vec[i] = 2 * M_PI * ((double)rand() / RAND_MAX);
        
        random_frequency_vec[i] = ((double)rand() / RAND_MAX);
        
        random_direction_vec[i] = 2 * M_PI * ((double)rand() / RAND_MAX);
        
        random_phase_vec[i] = 2 * M_PI * ((double)rand() / RAND_MAX);
    }
    
    //  2. generate noise vec
    double amp = 0;
    double wave_no = 0;
    double freq = 0;
    double dir = 0;
    double phase = 0;
    
    double x = 0;
    double y = 0;
    double t = time(NULL);
    
    double max_noise = -1 * std::numeric_limits<double>::infinity();
    double min_noise = std::numeric_limits<double>::infinity();
    
    double noise = 0;
    std::vector<double> noise_vec(n_elements, 0);
    
    for (int i = 0; i < n_elements; i++) {
        x = this->tile_position_x_vec[i] - this->position_x;
        y = this->tile_position_y_vec[i] - this->position_y;
        
        for (int j = 0; j < n_components; j++) {
            amp = random_amplitude_vec[j];
            wave_no = random_wave_number_vec[j];
            freq = random_frequency_vec[j];
            dir = random_direction_vec[j];
            phase = random_phase_vec[j];
            
            noise += (amp / (j + 1)) * cos(
                wave_no * (j + 1) * (x * sin(dir) + y * cos(dir)) +
                2 * M_PI * (j + 1) * freq * t +
                phase
            );
        }
        
        noise_vec[i] = noise;
        
        if (noise > max_noise) {
            max_noise = noise;
        }
        
        else if (noise < min_noise) {
            min_noise = noise;
        }
        
        noise = 0;
    }
    
    //  3. normalize noise vec
    for (int i = 0; i < n_elements; i++) {
        noise_vec[i] = (noise_vec[i] - min_noise) / (max_noise - min_noise);
        
        if (noise_vec[i] < 0) {
            noise_vec[i] = 0;
        }
        else if (noise_vec[i] > 1) {
            noise_vec[i] = 1;
        }
    }
    
    return noise_vec;
}   /* __getNoise() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexMap :: __procedurallyGenerateTileTypes(void)
///
/// \brief Helper method to procedurally generate tile types and set tiles accordingly.
///

void HexMap :: __procedurallyGenerateTileTypes(void)
{
    //  1. get random cosine series noise vec
    std::vector<double> noise_vec = this->__getNoise(this->n_tiles);
    
    //  2. set initial tile types based on either random cosine series noise or white
    //     noise (decided by coin toss)
    int noise_idx = 0;
    
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
            if ((double)rand() / RAND_MAX > 0.5) {
                hex_map_iter_y->second->setTileType(noise_vec[noise_idx]);
            }
            else {
                hex_map_iter_y->second->setTileType((double)rand() / RAND_MAX);
            }
            noise_idx++;
        }
    }
    
    //  3. smooth tile types (majority rules)
    this->__smoothTileTypes();
    
    //  4. set border tile type to ocean
    for (size_t i = 0; i < this->border_tiles_vec.size(); i++) {
        this->border_tiles_vec[i]->setTileType(TileType :: OCEAN);
    }
    
    //  5. enforce ocean continuity (i.e. all lake tiles touching ocean become ocean)
    this->__enforceOceanContinuity();
    
    return;
}   /* __procedurallyGenerateTileTypes() */

// ---------------------------------------------------------------------------------- //


// ---------------------------------------------------------------------------------- //

///
/// \fn std::vector<double> HexMap :: __getValidMapIndexPositions(
///         double potential_x,
///         double potential_y
///     )
///
/// \brief Helper method to translate given position into valid index position for a
//      tile, or otherwise return sentinel values (-1).
///
/// \param potential_x The potential x position of the tile.
///
/// \param potential_y The potential y position of the tile.
///
/// \return A vector of positions, either valid for indexing into the hex map, or
///     sentinel values (-1) if invalid.
///

std::vector<double> HexMap :: __getValidMapIndexPositions(
    double potential_x,
    double potential_y
)
{
    std::vector<double> map_index_positions = {-1, -1};
    
    std::map<double, std::map<double, HexTile*>>::iterator hex_map_iter_x;
    std::map<double, HexTile*>::iterator hex_map_iter_y;
    HexTile* hex_ptr;
    
    double distance = 0;
    
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
            hex_ptr = hex_map_iter_y->second;
            
            distance = sqrt(
                pow(hex_ptr->position_x - potential_x, 2) + 
                pow(hex_ptr->position_y - potential_y, 2)
            );
            
            if (distance <= hex_ptr->minor_radius / 4) {
                map_index_positions = {hex_ptr->position_x, hex_ptr->position_y};
                return map_index_positions;
            }
        }
    }
    
    return map_index_positions;
}   /* __isInHexMap() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::vector<HexTile*> HexMap :: __getNeighboursVector(HexTile* hex_ptr)
///
/// \brief Helper method to assemble a vector pointers to all neighbours of the given
///     tile.
///
/// \param hex_ptr A pointer to the given tile.
///
/// \return A vector of pointers to all neighbours of the given tile.
///

std::vector<HexTile*> HexMap :: __getNeighboursVector(HexTile* hex_ptr)
{
    std::vector<HexTile*> neighbours_vec;
    
    //  1. build potential neighbour positions
    std::vector<double> potential_neighbour_x_vec(6, 0);
    std::vector<double> potential_neighbour_y_vec(6, 0);
    
    for (int i = 0; i < 6; i++) {
        potential_neighbour_x_vec[i] = hex_ptr->position_x +
            2 * hex_ptr->minor_radius * cos((60 * i) * (M_PI / 180));
        
        potential_neighbour_y_vec[i] = hex_ptr->position_y +
            2 * hex_ptr->minor_radius * sin((60 * i) * (M_PI / 180));
    }
    
    //  2. populate neighbours vector
    std::vector<double> map_index_positions;
    double potential_x = 0;
    double potential_y = 0;
    
    for (int i = 0; i < 6; i++) {
        potential_x = potential_neighbour_x_vec[i];
        potential_y = potential_neighbour_y_vec[i];
        
        map_index_positions = this->__getValidMapIndexPositions(
            potential_x,
            potential_y
        );
        
        if (not (map_index_positions[0] == -1)) {
            neighbours_vec.push_back(
                this->hex_map[map_index_positions[0]][map_index_positions[1]]
            );
        }
    }
    
    return neighbours_vec;
}   /* __getNeighbourVector() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn TileType HexMap :: __getMajorityTileType(HexTile* hex_ptr)
///
/// \brief Function to return majority tile type of a tile and its neighbours. If no
///     clear majority, simply returns the type of the given tile.
///
/// \param hex_ptr Pointer to the given tile.
///
/// \return The majority tile type of the tile and its neighbours. If no clear majority
///     type, then the type of the given tile is simply returned.
///

TileType HexMap :: __getMajorityTileType(HexTile* hex_ptr)
{
    //  1. init type count map
    std::map<TileType, int> type_count_map;
    type_count_map[hex_ptr->tile_type] = 1;
    
    //  2. survey neighbours, count type instances
    std::vector<HexTile*> neighbours_vec = this->__getNeighboursVector(hex_ptr);
    
    for (size_t i = 0; i < neighbours_vec.size(); i++) {
        if (type_count_map.count(neighbours_vec[i]->tile_type) <= 0) {
            type_count_map[neighbours_vec[i]->tile_type] = 1;
        }
        else {
            type_count_map[neighbours_vec[i]->tile_type] += 1;
        }
    }
    
    //  3. find majority tile type
    int max_count = -1 * std::numeric_limits<int>::infinity();
    TileType majority_tile_type = hex_ptr->tile_type;
    
    std::map<TileType, int>::iterator map_iter;
    for (
        map_iter = type_count_map.begin();
        map_iter != type_count_map.end();
        map_iter++
    ){
        if (map_iter->second > max_count) {
            max_count = map_iter->second;
            majority_tile_type = map_iter->first;
        }
    }
    
    //  4. detect ties
    for (
        map_iter = type_count_map.begin();
        map_iter != type_count_map.end();
        map_iter++
    ){
        if (
            map_iter->second == max_count and
            map_iter->first != majority_tile_type
        ) {
            majority_tile_type = hex_ptr->tile_type;
            break;
        }
    }
    
    return majority_tile_type;
}   /* __getMajorityTileType() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexMap :: __smoothTileTypes(void)
///
/// \brief Helper method to smooth tile types using a majority rules approach.
///

void HexMap :: __smoothTileTypes(void)
{
    std::cout << "smoothing ..." << std::endl;
    
    std::map<double, std::map<double, HexTile*>>::iterator hex_map_iter_x;
    std::map<double, HexTile*>::iterator hex_map_iter_y;
    HexTile* hex_ptr;
    TileType majority_tile_type;
    
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
            hex_ptr = hex_map_iter_y->second;
            majority_tile_type = this->__getMajorityTileType(hex_ptr);
            
            if (majority_tile_type != hex_ptr->tile_type) {
                hex_ptr->setTileType(majority_tile_type);
            }
        }
    }

    return;
}   /* __smoothTileTypes() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn bool __isLakeTouchingOcean(HexTile* hex_ptr)
///
/// \brief Helper method to check if given tile is a lake tile touching ocean.
///
/// \param hex_ptr A pointer to the given tile.
///
/// \return true if lake tile touching ocean, false otherwise.
///

bool HexMap :: __isLakeTouchingOcean(HexTile* hex_ptr)
{
    //  1. if not lake tile, return
    if (not (hex_ptr->tile_type == TileType :: LAKE)) {
        return false;
    }
    
    //  2. scan neighbours for ocean tiles
    std::vector<HexTile*> neighbours_vec = this->__getNeighboursVector(hex_ptr);
    
    for (size_t i = 0; i < neighbours_vec.size(); i++) {
        if (neighbours_vec[i]->tile_type == TileType :: OCEAN) {
            return true;
        }
    }
    
    return false;
}   /* __isLakeTouchingOcean() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn bool HexMap :: __enforceOceanContinuity(void)
///
/// \brief Helper method to scan tiles and enforce ocean continuity. That is to say,
///     if a lake tile is found to be in contact with an ocean tile, then it becomes
///     ocean.
///

void HexMap :: __enforceOceanContinuity(void)
{
    std::cout << "enforcing ocean continuity ..." << std::endl;
    
    bool tile_changed = false;
    
    //  1. scan tiles and enforce (where appropriate)
    std::map<double, std::map<double, HexTile*>>::iterator hex_map_iter_x;
    std::map<double, HexTile*>::iterator hex_map_iter_y;
    HexTile* hex_ptr;
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
            hex_ptr = hex_map_iter_y->second;
            
            if (this->__isLakeTouchingOcean(hex_ptr)) {
                hex_ptr->setTileType(TileType :: OCEAN);
                tile_changed = true;
            }
        }
    }
    
    if (tile_changed) {
        this->__enforceOceanContinuity();
    }
    else {
        return;
    }
}   /* __enforceOceanContinuity() */

// ---------------------------------------------------------------------------------- //


// ---------------------------------------------------------------------------------- //

///
/// \fn void HexMap :: __procedurallyGenerateTileResources(void)
///
/// \brief Helper method to procedurally generate tile resources and set tiles
///     accordingly.
///

void HexMap :: __procedurallyGenerateTileResources(void)
{
    //  1. get random cosine series noise vec
    std::vector<double> noise_vec = this->__getNoise(this->n_tiles);
    
    //  2. set tile resources based on random cosine series noise
    int noise_idx = 0;
    
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
            hex_map_iter_y->second->setTileResource(noise_vec[noise_idx]);
            noise_idx++;
        }
    }
    
    return;
}   /* __procedurallyGenerateTileResources() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexMap :: __assembleHexMap(void)
///
/// \brief Helper method to assemble the hex map.
///

void HexMap :: __assembleHexMap(void)
{
    //  1. seed RNG (using milliseconds since 1 Jan 1970)
    unsigned long long int milliseconds_since_epoch =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count();
    srand(milliseconds_since_epoch);
    
    //  2. lay tiles
    this->__layTiles();
    
    //  3. procedurally generate types
    this->__procedurallyGenerateTileTypes();
    
    //  4. procedurally generate resources
    this->__procedurallyGenerateTileResources();
    
    return;
}   /* __assembleHexMap() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn HexTile* HexMap :: __getSelectedTile(void)
///
/// \brief Helper method to get pointer to selected tile.
///
/// \return Pointer to selected tile (or NULL if no tile selected).
///

HexTile* HexMap :: __getSelectedTile(void)
{
    HexTile* selected_tile_ptr = NULL;
    
    bool break_flag = false;
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
            if (hex_map_iter_y->second->is_selected) {
                selected_tile_ptr = hex_map_iter_y->second;
                break_flag = true;
            }
            
            if (break_flag) {
                break;
            }
        }
        
        if (break_flag) {
            break;
        }
    }
    
    return selected_tile_ptr;
}   /* __getSelectedTile() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn HexMap :: HexMap(
///         int n_layers,
///         AssetsManager* assets_manager_ptr,
///         InputsHandler* inputs_handler_ptr,
///         MessagesHandler* messages_handler_ptr,
///         sf::RenderWindow* render_window_ptr
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
/// \param render_window_ptr Pointer to the render window.
///

HexMap :: HexMap(
    int n_layers,
    AssetsManager* assets_manager_ptr,
    InputsHandler* inputs_handler_ptr,
    MessagesHandler* messages_handler_ptr,
    sf::RenderWindow* render_window_ptr
)
{
    //  1. set attributes
    this->assets_manager_ptr = assets_manager_ptr;
    this->inputs_handler_ptr = inputs_handler_ptr;
    this->messages_handler_ptr = messages_handler_ptr;
    this->render_window_ptr = render_window_ptr;
    
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
/// \fn void HexMap :: assess(void)
///
/// \brief Method to assess the resource of the selected tile.
///

void HexMap :: assess(void)
{
    HexTile* selected_tile_ptr = this->__getSelectedTile();
    if (selected_tile_ptr != NULL) {
        selected_tile_ptr->assess();
    }

    return;
}   /* assess() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexMap :: process(void)
///
/// \brief Method to process HexMap. To be called once per frame;
///

void HexMap :: process(void)
{
    //  1. handle inputs
    //...
    
    //  2. process tiles
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
            hex_map_iter_y->second->process();
        }
    }
    
    return;
}   /* process() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexMap :: reroll(void)
///
/// \brief Method to re-roll the hex map.
///

void HexMap :: reroll(void)
{
    this->clear();
    this->__assembleHexMap();
    
    return;
}   /* reroll() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void HexMap :: toggleResourceOverlay(void)
///
/// \brief Method to toggle the hex map resource overlay.
///

void HexMap :: toggleResourceOverlay(void)
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
            hex_map_iter_y->second->toggleResourceOverlay();
        }
    }
    
    return;
}   /* toggleResourceOverlay() */

// ---------------------------------------------------------------------------------- //


// ---------------------------------------------------------------------------------- //

///
/// \fn void HexMap :: draw(void)
///
/// \brief Method to draw the hex map to the render window. To be called only once per
///     frame!
///

void HexMap :: draw(void)
{
    //  1. draw all tiles in order
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
            hex_map_iter_y->second->draw();
        }
    }
    
    //  2. redraw selected tile on top
    HexTile* selected_tile_ptr = this->__getSelectedTile();
    if (selected_tile_ptr != NULL) {
        selected_tile_ptr->draw();
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
    
    this->tile_position_x_vec.clear();
    this->tile_position_y_vec.clear();
    this->border_tiles_vec.clear();
    
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
