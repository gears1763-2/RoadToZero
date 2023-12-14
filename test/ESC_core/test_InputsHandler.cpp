/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Suite of tests for the InputsHandler class.
 *
 */


///
/// \file test_InputsHandler.cpp
///
/// \brief Suite of tests for the InputsHandler class.
///
/// A suite of tests for the InputsHandler class.
///


#include "../../header/ESC_core/constants.h"
#include "../../header/ESC_core/testing_utils.h"
#include "../../header/ESC_core/InputsHandler.h"


// ---------------------------------------------------------------------------------- //

//...

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

int main(int argc, char** argv)
{
    #ifdef _WIN32
        activateVirtualTerminal();
    #endif  /* _WIN32 */
    
    printGold("\tTesting InputsHandler");
    std::cout << std::flush;
    
    srand(time(NULL));
    int n_dots = 8;
    
    
    try {
        InputsHandler inputs_handler;
        
        testFloatEquals(
            int(sf::Keyboard::KeyCount),
            101,
            __FILE__,
            __LINE__
        );
        
        testFloatEquals(
            inputs_handler.key_press_vec.size(),
            int(sf::Keyboard::KeyCount),
            __FILE__,
            __LINE__
        );
        
        testFloatEquals(
            inputs_handler.key_pressed_once_vec.size(),
            int(sf::Keyboard::KeyCount),
            __FILE__,
            __LINE__
        );
        
        sf::Clock clock;
        sf::Event event;
        sf::RenderWindow window(sf::VideoMode(800, 600), "Testing InputsHandler");
        
        unsigned long long int frame = 0;
        double time_since_run_s = 0;
        
        while (window.isOpen()) {
            time_since_run_s = clock.getElapsedTime().asSeconds();
            
            if (
                time_since_run_s >= (frame + 1) * SECONDS_PER_FRAME
            ) {
                while (window.pollEvent(event))
                {
                    inputs_handler.process(&event);
                    
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
                
                window.clear();
                window.display();
                
                //inputs_handler.printKeysPressed();
                if (inputs_handler.key_pressed_once_vec[sf::Keyboard::Enter]) {
                    std::cout << "Enter" << std::endl;
                }
                
                std::cout << frame << " : " << time_since_run_s << "\r" << std::flush;
                
                inputs_handler.reset();
                frame++;
            }
        }
    }
    
    
    catch (...) {
        //...
        
        printGold(" ");
        for (int i = 0; i < n_dots; i++) {
            printGold(".");
        }
        printGold(" ");
        printRed("FAIL");
        std::cout << std::endl;
        throw;
    }
    
    
    //...
    
    printGold(" ");
    for (int i = 0; i < n_dots; i++) {
        printGold(".");
    }
    printGold(" ");
    printGreen("PASS");
    std::cout << std::endl;
    
    return 0;
}   /* main() */

// ---------------------------------------------------------------------------------- //
