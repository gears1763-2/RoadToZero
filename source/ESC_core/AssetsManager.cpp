/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the AssetsManager class.
 *
 */


///
/// \file AssetsManager.cpp
///
/// \brief Implementation file for the AssetsManager class.
///
/// A class which manages visual and sound assets.
///


#include "../../header/ESC_core/AssetsManager.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

//...

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn AssetsManager :: AssetsManager(void)
///
/// \brief Constructor for the AssetsManager class.
///

AssetsManager :: AssetsManager(void)
{
    //...
    
    std::cout << "AssetsManager constructed at " << this << std::endl;
    
    return;
}   /* AssetsManager() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void AssetsManager :: loadFont(std::string path_2_font, std::string font_key)
///
/// \brief Method to load a font and insert it into the font map.
///
/// \param path_2_font A path (either relative or absolute) to the font file.
///
/// \param font_key A key associated with the font (for indexing into the font map).
///

void AssetsManager :: loadFont(std::string path_2_font, std::string font_key)
{
    //  1. check key, throw error if already in use
    if (this->font_map.count(font_key) > 0) {
        std::string error_str = "ERROR  AssetsManager::loadFont()  font key ";
        error_str += font_key;
        error_str += " is already in use";
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    
    //  2. load from file, throw error on fail
    sf::Font* font_ptr = new sf::Font();
    
    if (not font_ptr->loadFromFile(path_2_font)) {
        std::string error_str = "ERROR  AssetsManager::loadFont()  could not load ";
        error_str += "font at ";
        error_str += path_2_font;
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    
    //  3. insert into font map
    this->font_map.insert(std::pair<std::string, sf::Font*>(font_key, font_ptr));
    
    return;
}   /* loadFont() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void AssetsManager :: clear(void)
///
/// \brief Method to clear all loaded assets.
///

void AssetsManager :: clear(void)
{
    //  1. clear fonts
    std::map<std::string, sf::Font*>::iterator font_iter;
    for (
        font_iter = this->font_map.begin();
        font_iter != this->font_map.end();
        font_iter++
    ) {
        delete font_iter->second;
    }
    this->font_map.clear();
    
    
    //  2. clear textures
    std::map<std::string, sf::Texture*>::iterator texture_iter;
    for (
        texture_iter = this->texture_map.begin();
        texture_iter != this->texture_map.end();
        texture_iter++
    ) {
        delete texture_iter->second;
    }
    this->texture_map.clear();
    
    
    //  3. clear sound buffers
    std::map<std::string, sf::SoundBuffer*>::iterator soundbuffer_iter;
    for (
        soundbuffer_iter = this->soundbuffer_map.begin();
        soundbuffer_iter != this->soundbuffer_map.end();
        soundbuffer_iter++
    ) {
        delete soundbuffer_iter->second;
    }
    this->soundbuffer_map.clear();
    
    
    //  4. clear sounds
    std::map<std::string, sf::Sound*>::iterator sound_iter;
    for (
        sound_iter = this->sound_map.begin();
        sound_iter != this->sound_map.end();
        sound_iter++
    ) {
        delete sound_iter->second;
    }
    this->sound_map.clear();
    
    
    //  5. clear tracks
    std::map<std::string, sf::Music*>::iterator track_iter;
    for (
        track_iter = this->track_map.begin();
        track_iter != this->track_map.end();
        track_iter++
    ) {
        delete track_iter->second;
    }
    this->track_map.clear();
    
    return;
}   /* clear() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn AssetsManager :: ~AssetsManager(void)
///
/// \brief Destructor for the AssetsManager class.
///

AssetsManager :: ~AssetsManager(void)
{
    this->clear();
    
    std::cout << "AssetsManager at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~AssetsManager() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
