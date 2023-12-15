/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Suite of tests for the AssetsManager class.
 *
 */


///
/// \file test_AssetsManager.cpp
///
/// \brief Suite of tests for the AssetsManager class.
///
/// A suite of tests for the AssetsManager class.
///


#include "../../header/ESC_core/constants.h"
#include "../../header/ESC_core/testing_utils.h"
#include "../../header/ESC_core/AssetsManager.h"


// ---------------------------------------------------------------------------------- //

//...

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

int main(int argc, char** argv)
{
    #ifdef _WIN32
        activateVirtualTerminal();
    #endif  /* _WIN32 */
    
    printGold("\tTesting AssetsManager");
    std::cout << std::endl;
    
    srand(time(NULL));
    int n_dots = 8;
    
    
    try {
        //...
        
        sf::Clock clock;
        sf::Event event;
        sf::RenderWindow window(sf::VideoMode(800, 600), "Testing AssetsManager");
        
        unsigned long long int frame = 0;
        double time_since_run_s = 0;
        
        while (window.isOpen()) {
            time_since_run_s = clock.getElapsedTime().asSeconds();
            
            if (
                time_since_run_s >= (frame + 1) * SECONDS_PER_FRAME
            ) {
                while (window.pollEvent(event))
                {
                    //...
                    
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }
                
                window.clear();
                window.display();
                
                //...
                
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
