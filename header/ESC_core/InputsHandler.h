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
        bool mouse_left_click; ///< A boolean which indicates if the mouse left button has been clicked.
        
        std::vector<bool> key_pressed_once_vec; ///< A vector (bool) which indicates which keys have been pressed once. Useful for discrete inputs.
        std::vector<bool> key_press_vec; ///< A vector <bool> which indicates which keys are currently pressed. Useful for smooth movement.
        
        std::map<sf::Keyboard::Key, std::string> key_code_map; ///< A map from key codes to corresponding string representations.
        
        
        //  2. methods
        InputsHandler(void);
        
        void process(sf::Event*);
        void printKeysPressed(void);
        void reset(void);
        
        ~InputsHandler(void);
    
};  /* InputsHandler */


#endif  /* INPUTSHANDLER_H */
