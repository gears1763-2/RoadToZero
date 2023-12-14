/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the InputsHandler class.
 *
 */


///
/// \file InputsHandler.h
///
/// \brief Header file for the InputsHandler class.
///


#ifndef INPUTSHANDLER_H
#define INPUTSHANDLER_H


#include "includes.h"


///
/// \class InputsHandler
///
/// \brief A class which handles inputs from peripherals (i.e., keyboard and mouse).
///

class InputsHandler {
    private:
        //  1. attributes
        //...
        
        
        //  2. methods
        void __constructKeyCodeMap(void);
    
    
    public:
        //  1. attributes
        std::vector<bool> key_pressed_once_vec;
        std::vector<bool> key_press_vec;
        
        std::map<sf::Keyboard::Key, std::string> key_code_map;
        
        
        //  2. methods
        InputsHandler(void);
        
        void process(sf::Event*);
        void printKeysPressed(void);
        void reset(void);
        
        ~InputsHandler(void);
    
};  /* InputsHandler */


#endif  /* INPUTSHANDLER_H */
