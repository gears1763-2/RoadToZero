/*
 *  [ESC] Interactive
 *
 *  Implementation file for the AssetsManager class.
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
/// \file AssetsManager.cpp
///
/// \brief Implementation file for the AssetsManager class.
///
/// A class which manages visual and sound assets.
///


#include "../../header/ESC_core/AssetsManager.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void AssetsManager :: __loadSoundBuffer(
///         std::string path_2_sound,
///         std::string sound_key
///     )
///
/// \brief Helper method to load a soundbuffer and insert it into the soundbuffer map.
///     Should only be called by loadSound(), to create an sf::SoundBuffer corresponding
///     to the loaded sf::Sound.
///
/// \param path_2_sound A path (either relative or absolute) to the sound file.
///
/// \param sound_key A key associated with the sound (for indexing into the soundbuffer 
///     map).
///

void AssetsManager :: __loadSoundBuffer(
    std::string path_2_sound,
    std::string sound_key
)
{
    //  1. check key, throw error if already in use
    if (this->soundbuffer_map.count(sound_key) > 0) {
        std::string error_str = "ERROR  AssetsManager::__loadSoundBuffer()  sound key ";
        error_str += sound_key;
        error_str += " is already in use";
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    
    //  2. load from file, throw error on fail
    sf::SoundBuffer* soundbuffer_ptr = new sf::SoundBuffer();
    
    if (not soundbuffer_ptr->loadFromFile(path_2_sound)) {
        std::string error_str = "ERROR  AssetsManager::__loadSoundBuffer()  could not load ";
        error_str += "soundbuffer at ";
        error_str += path_2_sound;
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    
    //  3. insert into soundbuffer map
    this->soundbuffer_map.insert(
        std::pair<std::string, sf::SoundBuffer*>(sound_key, soundbuffer_ptr)
    );
    
    std::cout << "SoundBuffer " << sound_key << " inserted into soundbuffer map" <<
        std::endl;
    
    return;
}   /* __loadSoundBuffer() */

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
    
    std::cout << "Font " << font_key << " inserted into font map" << std::endl;
    
    return;
}   /* loadFont() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void AssetsManager :: loadTexture(std::string path_2_texture, std::string texture_key)
///
/// \brief Method to load a texture and insert it into the texture map.
///
/// \param path_2_texture A path (either relative or absolute) to the texture file.
///
/// \param texture_key A key associated with the texture (for indexing into the texture 
///     map).
///

void AssetsManager :: loadTexture(std::string path_2_texture, std::string texture_key)
{
    //  1. check key, throw error if already in use
    if (this->texture_map.count(texture_key) > 0) {
        std::string error_str = "ERROR  AssetsManager::loadTexture()  texture key ";
        error_str += texture_key;
        error_str += " is already in use";
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    
    //  2. load from file, throw error on fail
    sf::Texture* texture_ptr = new sf::Texture();
    
    if (not texture_ptr->loadFromFile(path_2_texture)) {
        std::string error_str = "ERROR  AssetsManager::loadTexture()  could not load ";
        error_str += "texture at ";
        error_str += path_2_texture;
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    
    //  3. insert into texture map
    this->texture_map.insert(
        std::pair<std::string, sf::Texture*>(texture_key, texture_ptr)
    );
    
    std::cout << "Texture " << texture_key << " inserted into texture map" << std::endl;
    
    return;
}   /* loadTexture() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void AssetsManager :: loadSound(std::string path_2_sound, std::string sound_key)
///
/// \brief Method to load a sound and insert it into the sound map. Automatically
///     creates a corresponding sf::SoundBuffer.
///
/// \param path_2_sound A path (either relative or absolute) to the sound file.
///
/// \param sound_key A key associated with the sound (for indexing into the sound map).
///

void AssetsManager :: loadSound(std::string path_2_sound, std::string sound_key)
{
    //  1. create an associated sf::SoundBuffer
    this->__loadSoundBuffer(path_2_sound, sound_key);
    
    //  2. associate sf::Sound with sf::SoundBuffer
    sf::Sound* sound_ptr = new sf::Sound();
    sound_ptr->setBuffer(*(this->soundbuffer_map[sound_key]));
    
    //  3. insert into sound map
    this->sound_map.insert(std::pair<std::string, sf::Sound*>(sound_key, sound_ptr));
    
    std::cout << "Sound " << sound_key << " inserted into sound map" << std::endl;
    
    return;
}   /* loadSound() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void AssetsManager :: loadTrack(std::string path_2_track, std::string track_key)
///
/// \brief Method to load a track (sf::Music) and insert it into the track map.
///
/// \param path_2_track A path (either relative or absolute) to the track file.
///
/// \param track_key A key associated with the track (for indexing into the track map).
///

void AssetsManager :: loadTrack(std::string path_2_track, std::string track_key)
{
    //  1. check key, throw error if already in use
    if (this->track_map.count(track_key) > 0) {
        std::string error_str = "ERROR  AssetsManager::loadTrack()  track key ";
        error_str += track_key;
        error_str += " is already in use";
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. open from file, throw error on fail
    sf::Music* track_ptr = new sf::Music();
    
    if (not track_ptr->openFromFile(path_2_track)) {
        std::string error_str = "ERROR  AssetsManager::loadTrack()  could not open ";
        error_str += "track at ";
        error_str += path_2_track;
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  3. insert into track map
    this->track_map.insert(std::pair<std::string, sf::Music*>(track_key, track_ptr));
    this->current_track = this->track_map.begin();
    
    std::cout << "Track " << track_key << " inserted into track map" << std::endl;
    
    return;
}   /* loadTrack() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn sf::Font* AssetsManager :: getFont(std::string font_key)
///
/// \brief Method to get font associated with given font key.
///
/// \param font_key A key associated with the font (for indexing into the font map).
///
/// \return A pointer to the corresponding font.
///

sf::Font* AssetsManager :: getFont(std::string font_key)
{
    //  1. check key, throw error if not found
    if (this->font_map.count(font_key) <= 0) {
        std::string error_str = "ERROR  AssetsManager::getFont()  font key ";
        error_str += font_key;
        error_str += " is not contained in font map";
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    return this->font_map[font_key];
}   /* getFont() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn sf::Texture* AssetsManager :: getTexture(std::string texture_key)
///
/// \brief Method to get texture associated with given texture key.
///
/// \param texture_key A key associated with the texture (for indexing into the texture
///     map).
///
/// \return A pointer to the corresponding texture.
///

sf::Texture* AssetsManager :: getTexture(std::string texture_key)
{
    //  1. check key, throw error if not found
    if (this->texture_map.count(texture_key) <= 0) {
        std::string error_str = "ERROR  AssetsManager::getTexture()  texture key ";
        error_str += texture_key;
        error_str += " is not contained in texture map";
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    return this->texture_map[texture_key];
}   /* getTexture() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn sf::SoundBuffer* AssetsManager :: getSoundBuffer(std::string sound_key)
///
/// \brief Method to get soundbuffer associated with given sound key.
///
/// \param sound_key A key associated with the soundbuffer (for indexing into the
///     soundbuffer map).
///
/// \return A pointer to the corresponding soundbuffer.
///

sf::SoundBuffer* AssetsManager :: getSoundBuffer(std::string sound_key)
{
    //  1. check key, throw error if not found
    if (this->soundbuffer_map.count(sound_key) <= 0) {
        std::string error_str = "ERROR  AssetsManager::getSoundBuffer()  sound key ";
        error_str += sound_key;
        error_str += " is not contained in soundbuffer map";
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    return this->soundbuffer_map[sound_key];
}   /* getSoundBuffer() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn sf::Sound* AssetsManager :: getSound(std::string sound_key)
///
/// \brief Method to get sound associated with given sound key.
///
/// \param sound_key A key associated with the sound (for indexing into the sound map).
///
/// \return A pointer to the corresponding sound.
///

sf::Sound* AssetsManager :: getSound(std::string sound_key)
{
    //  1. check key, throw error if not found
    if (this->sound_map.count(sound_key) <= 0) {
        std::string error_str = "ERROR  AssetsManager::getSound()  sound key ";
        error_str += sound_key;
        error_str += " is not contained in sound map";
        
        this->clear();
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    return this->sound_map[sound_key];
}   /* getSound() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void AssetsManager :: playTrack(void)
///
/// \brief Method to play the current track.
///

void AssetsManager :: playTrack(void)
{
    this->current_track->second->play();
    
    return;
}   /* playTrack() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void AssetsManager :: pauseTrack(void)
///
/// \brief Method to pause the current track.
///

void AssetsManager :: pauseTrack(void)
{
    this->current_track->second->pause();
    
    return;
}   /* pauseTrack() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void AssetsManager :: stopTrack(void)
///
/// \brief Method to stop the current track.
///

void AssetsManager :: stopTrack(void)
{
    this->current_track->second->stop();
    
    return;
}   /* stopTrack() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void AssetsManager :: nextTrack(void)
///
/// \brief Method to advance to the next track. Wraps around if the end of the track map
///     is reached.
///

void AssetsManager :: nextTrack(void)
{
    //  1. stop current track
    this->stopTrack();
    
    //  2. increment current track
    this->current_track++;
    
    //  3. handle wrap around
    if (this->current_track == this->track_map.end()) {
        this->current_track = this->track_map.begin();
    }
    
    return;
}   /* nextTrack() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void AssetsManager :: previousTrack(void)
///
/// \brief Method to return to the previous track. Wraps around if the beginning of the
///     track map is reached.
///

void AssetsManager :: previousTrack(void)
{
    //  1. stop current track
    this->stopTrack();
    
    //  2. handle wrap around
    if (this->current_track == this->track_map.begin()) {
        this->current_track = this->track_map.end();
    }
    
    //  3. decrement current track
    this->current_track--;
    
    return;
}   /* previousTrack() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn std::string AssetsManager :: getCurrentTrackKey(void)
///
/// \brief Method to get track key for current track.
///
/// \return The track key for the current track.
///

std::string AssetsManager :: getCurrentTrackKey(void)
{
    return this->current_track->first;
}   /* getCurrentTrackKey() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn sf::SoundSource::Status AssetsManager :: getTrackStatus(void)
///
/// \brief Method to get the status of the current track.
///
/// \return The status of the current track.
///

sf::SoundSource::Status AssetsManager :: getTrackStatus(void)
{
    return this->current_track->second->getStatus();
}   /* getTrackStatus */

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
        
        std::cout << "Font " << font_iter->first << " deleted from font map" <<
            std::endl;
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
        
        std::cout << "Texture " << texture_iter->first << " deleted from texture map" <<
            std::endl;
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
        
        std::cout << "SoundBuffer " << soundbuffer_iter->first <<
            " deleted from soundbuffer map" << std::endl;
    }
    this->soundbuffer_map.clear();
    
    
    //  4. clear sounds
    std::map<std::string, sf::Sound*>::iterator sound_iter;
    for (
        sound_iter = this->sound_map.begin();
        sound_iter != this->sound_map.end();
        sound_iter++
    ) {
        sound_iter->second->stop();
        delete sound_iter->second;
        
        std::cout << "Sound " << sound_iter->first << " deleted from sound map" <<
            std::endl;
    }
    this->sound_map.clear();
    
    
    //  5. clear tracks
    std::map<std::string, sf::Music*>::iterator track_iter;
    for (
        track_iter = this->track_map.begin();
        track_iter != this->track_map.end();
        track_iter++
    ) {
        track_iter->second->stop();
        delete track_iter->second;
        
        std::cout << "Track " << track_iter->first << " deleted from track map" <<
            std::endl;
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
