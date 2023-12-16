/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Suite of tests for the HexMap class.
 *
 */


///
/// \file test_HexMap.cpp
///
/// \brief Suite of tests for the HexMap class.
///
/// A suite of tests for the HexMap class.
///


#include "../../header/ESC_core/constants.h"
#include "../../header/ESC_core/testing_utils.h"
#include "../../header/ESC_core/AssetsManager.h"
#include "../../header/ESC_core/InputsHandler.h"
#include "../../header/ESC_core/MessagesHandler.h"

#include "../../header/HexMap/HexMap.h"


// ---------------------------------------------------------------------------------- //

//...

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

int main(int argc, char** argv)
{
    #ifdef _WIN32
        activateVirtualTerminal();
    #endif  /* _WIN32 */
    
    printGold("\tTesting HexMap");
    std::cout << std::endl;
    
    srand(time(NULL));
    int n_dots = 8;
    
    
    try {
        //  1. construct
        AssetsManager assets_manager;
        InputsHandler inputs_handler;
        MessagesHandler messages_handler;
        
        HexMap hex_map(6, &assets_manager, &inputs_handler, &messages_handler);
        
        //  2. test game loop
        sf::Clock clock;
        sf::Event event;
        sf::RenderWindow window(sf::VideoMode(1200, 800), "Testing AssetsManager");
        
        double screen_width = window.getSize().x;
        double screen_height = window.getSize().y;
        
        testFloatEquals(
            screen_width,
            1200,
            __FILE__,
            __LINE__
        );
        
        testFloatEquals(
            screen_height,
            800,
            __FILE__,
            __LINE__
        );
        
        unsigned long long int frame = 0;
        double time_since_run_s = 0;
        
        //...
        
        while (window.isOpen()) {
            time_since_run_s = clock.getElapsedTime().asSeconds();
            
            if (
                time_since_run_s >= (frame + 1) * SECONDS_PER_FRAME
            ) {
                while (window.pollEvent(event))
                {
                    inputs_handler.process(&event);
                    
                    //...
                    
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
                
                hex_map.process();
                
                window.clear();
                
                hex_map.draw(&window);
                
                window.display();
                
                inputs_handler.reset();
                
                std::cout << frame << " : " << time_since_run_s << "\r" << std::flush;
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
