/*
 *  [ESC] Interactive
 *
 *  Header file for the AssetsManager class.
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
/// \file AssetsManager.h
///
/// \brief Header file for the AssetsManager class.
///


#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H


#include "constants.h"
#include "includes.h"


///
/// \class AssetsManager
///
/// \brief A class which manages visual and sound assets.
///

class AssetsManager {
    private:
        //  1. attributes
        //...
        
        
        //  2. methods
        void __loadSoundBuffer(std::string, std::string);
    
    
    public:
        //  1. attributes
        std::map<std::string, sf::Font*> font_map; ///< A map of pointers to loaded fonts.
        std::map<std::string, sf::Texture*> texture_map; ///< A map of pointers to loaded textures.
        std::map<std::string, sf::SoundBuffer*> soundbuffer_map; ///< A map of pointers to sound buffers.
        std::map<std::string, sf::Sound*> sound_map; ///< A map of pointers to loaded sounds.
        std::map<std::string, sf::Music*>::iterator current_track; ///< A map iterator which corresponds to the current track (i.e., the track currently being played).
        std::map<std::string, sf::Music*> track_map; ///< A map of pointers to opened tracks (i.e. sf::Music).
        
        
        //  2. methods
        AssetsManager(void);
        
        void loadFont(std::string, std::string);
        void loadTexture(std::string, std::string);
        void loadSound(std::string, std::string);
        void loadTrack(std::string, std::string);
        
        sf::Font* getFont(std::string);
        sf::Texture* getTexture(std::string);
        sf::SoundBuffer* getSoundBuffer(std::string);
        sf::Sound* getSound(std::string);
        
        void playTrack(void);
        void pauseTrack(void);
        void stopTrack(void);
        void nextTrack(void);
        void previousTrack(void);
        
        std::string getCurrentTrackKey(void);
        sf::SoundSource::Status getTrackStatus(void);
        
        void clear(void);
        
        ~AssetsManager(void);
    
};  /* AssetsManager */


#endif  /* ASSETSMANAGER_H */
