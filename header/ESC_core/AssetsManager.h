/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the AssetsManager class.
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
