/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the InputsHandler class.
 *
 */


///
/// \file InputsHandler.cpp
///
/// \brief Implementation file for the InputsHandler class.
///
/// A class which handles inputs from peripherals (i.e., keyboard and mouse).
///


#include "../../header/ESC_core/InputsHandler.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///
/// \fn void InputsHandler :: __constructKeyCodeMap(void)
///
/// \brief Helper method to construct a map from sf::Keyboard::Key to a string
///     representation of the corresponding key.
///

void InputsHandler :: __constructKeyCodeMap(void)
{
    //  1. unknown keys
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Unknown, "Unknown")
    );
    
    
    //  2. alpha keys
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::A, "A")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::B, "B")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::C, "C")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::D, "D")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::E, "E")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F, "F")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::G, "G")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::H, "H")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::I, "I")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::J, "J")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::K, "K")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::L, "L")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::M, "M")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::N, "N")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::O, "O")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::P, "P")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Q, "Q")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::R, "R")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::S, "S")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::T, "T")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::U, "U")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::V, "V")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::W, "W")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::X, "X")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Y, "Y")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Z, "Z")
    );
    
    
    //  3. numeric keys
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Num0, "0")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Num1, "1")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Num2, "2")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Num3, "3")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Num4, "4")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Num5, "5")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Num6, "6")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Num7, "7")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Num8, "8")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Num9, "9")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Numpad0, "0")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Numpad1, "1")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Numpad2, "2")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Numpad3, "3")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Numpad4, "4")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Numpad5, "5")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Numpad6, "6")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Numpad7, "7")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Numpad8, "8")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Numpad9, "9")
    );
    
    
    //  4. direction keys
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Left, "Left")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Right, "Right")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Up, "Up")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Down, "Down")
    );
    
    
    //  5. function keys
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F1, "F1")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F2, "F2")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F3, "F3")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F4, "F4")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F5, "F5")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F6, "F6")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F7, "F7")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F8, "F8")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F9, "F9")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F10, "F10")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F11, "F11")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F12, "F12")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F13, "F13")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F14, "F14")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::F15, "F15")
    );
    
    
    //  6. other keys
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Escape, "Escape")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::LControl, "LCtrl")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::LShift, "LShift")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::LAlt, "LAlt")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::LSystem, "LSystem")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::RControl, "RCtrl")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::RShift, "RShift")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::RAlt, "RAlt")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::RSystem, "RSystem")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Menu, "Menu")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::LBracket, "LBracket")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::RBracket, "RBracket")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Semicolon, "Semicolon")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Comma, "Comma")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Period, "Period")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Quote, "Quote")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Slash, "Slash")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Backslash, "Backslash")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Tilde, "Tilde")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Equal, "Equal")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Hyphen, "Hyphen")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Space, "Space")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Enter, "Enter")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Backspace, "Backspace")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Tab, "Tab")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::PageUp, "PageUp")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::PageDown, "PageDown")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::End, "End")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Home, "Home")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Insert, "Insert")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Delete, "Delete")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Add, "Add")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Subtract, "Subtract")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Multiply, "Multiply")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Divide, "Divide")
    );
    this->key_code_map.insert(
        std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Pause, "Pause")
    );
    
    return;
}   /* __constructKeyCodeMap() */

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn InputsHandler :: InputsHandler(void)
///
/// \brief Constructor for the InputsHandler class.
///

InputsHandler :: InputsHandler(void)
{
    this->key_pressed_once_vec.resize(sf::Keyboard::KeyCount, false);
    this->key_press_vec.resize(sf::Keyboard::KeyCount, false);
    
    this->__constructKeyCodeMap();
    
    std::cout << "InputsHandler constructed at " << this << std::endl;
    
    return;
}   /* InputsHandler() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn process(sf::Event* event_ptr)
///
/// \brief Method to process input events. To be called once per event.
///
/// \param event_ptr A pointer to the sf::Event class.
///

void InputsHandler :: process(sf::Event* event_ptr)
{
    //  1. update state of key press vectors
    switch (event_ptr->type) {
        case (sf::Event::KeyPressed): {
            if (not this->key_press_vec[event_ptr->key.code]) {
                this->key_pressed_once_vec[event_ptr->key.code] = true;
            }
            
            this->key_press_vec[event_ptr->key.code] = true;
            
            break;
        }
        
        case (sf::Event::KeyReleased): {
            this->key_pressed_once_vec[event_ptr->key.code] = false;
            this->key_press_vec[event_ptr->key.code] = false;
            
            break;
        }
        
        case (sf::Event::MouseButtonPressed): {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->mouse_left_click = true;
                
                std::cout << "left click        " << std::endl;
            }
            
            break;
        }
        
        case (sf::Event::MouseButtonReleased): {
            this->mouse_left_click = false;
            
            break;
        }
        
        default: {
            //  do nothing!
            
            break;
        }
    }
    
    return;
}   /* process() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void InputsHandler :: printKeysPressed(void)
///
/// \brief Method to print out which keys are currently pressed.
///

void InputsHandler :: printKeysPressed(void)
{
    std::string print_str = "";
    
    for (size_t i = 0; i < this->key_press_vec.size(); i++) {
        if (this->key_press_vec[i]) {
            print_str += this->key_code_map[sf::Keyboard::Key(i)];
            print_str += ", ";
        }
    }
    
    if (not print_str.empty()) {
        std::cout << "Keys pressed: " << print_str << std::endl;
    }
    
    return;
}   /* printKeysPressed() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void InputsHandler :: reset(void)
///
/// \brief Method to reset InputsHandler. To be called once per frame (at end of frame!).
///

void InputsHandler :: reset(void)
{
    this->mouse_left_click = false;
    
    for (size_t i = 0; i < this->key_press_vec.size(); i++) {
        this->key_pressed_once_vec[i] = false;
    }
    
    return;
}   /* reset() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn InputsHandler :: ~InputsHandler(void)
///
/// \brief Destructor for the InputsHandler class.
///

InputsHandler :: ~InputsHandler(void)
{
    std::cout << "InputsHandler at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~InputsHandler() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
