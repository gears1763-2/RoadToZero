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


#include "includes.h"


///
/// \class AssetsManager
///
/// \brief A class which manages visual and sound assets.
///

class AssetsManager {
    private:
        //  1. attributes
        std::map<std::string, sf::Font*> font_map;
        std::map<std::string, sf::Texture*> texture_map;
        std::map<std::string, sf::SoundBuffer*> soundbuffer_map;
        std::map<std::string, sf::Sound*> sound_map;
        std::map<std::string, sf::Music*>::iterator current_track;
        std::map<std::string, sf::Music*> track_map;
        
        
        //  2. methods
        //...
    
    
    public:
        //  1. attributes
        //...
        
        
        //  2. methods
        AssetsManager(void);
        
        void loadFont(std::string, std::string);
        void loadTexture(std::string, std::string);
        void loadSoundBuffer(std::string, std::string);
        void loadSound(std::string, std::string);
        void loadTrack(std::string, std::string);
        
        ~AssetsManager(void);
    
};  /* AssetsManager */


#endif  /* ASSETSMANAGER_H */
