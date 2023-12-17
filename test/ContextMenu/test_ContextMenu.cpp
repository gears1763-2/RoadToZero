/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Suite of tests for the ContextMenu class.
 *
 */


///
/// \file test_ContextMenu.cpp
///
/// \brief Suite of tests for the ContextMenu class.
///
/// A suite of tests for the ContextMenu class.
///


#include "../../header/ESC_core/constants.h"
#include "../../header/ESC_core/includes.h"
#include "../../header/ESC_core/testing_utils.h"
#include "../../header/ESC_core/AssetsManager.h"
#include "../../header/ESC_core/InputsHandler.h"
#include "../../header/ESC_core/MessagesHandler.h"

#include "../../header/HexMap/HexMap.h"
#include "../../header/ContextMenu/ContextMenu.h"


// ---------------------------------------------------------------------------------- //

//...

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

int main(int argc, char** argv)
{
    #ifdef _WIN32
        activateVirtualTerminal();
    #endif  /* _WIN32 */
    
    printGold("\tTesting ContextMenu");
    std::cout << std::endl;
    
    srand(time(NULL));
    int n_dots = 8;
    
    
    try {
        //  1. construct, load/open some test assets
        AssetsManager assets_manager;
        InputsHandler inputs_handler;
        MessagesHandler messages_handler;
        
        assets_manager.loadFont("assets/fonts/DroidSansMono.ttf", "DroidSansMono");
        assets_manager.loadFont("assets/fonts/Glass_TTY_VT220.ttf", "Glass_TTY_VT220");
        
        
        //  2. test game loop
        sf::Clock clock;
        sf::Event event;
        sf::RenderWindow window(
            sf::VideoMode(GAME_WIDTH, GAME_HEIGHT),
            "Testing ContextMenu"
        );
        
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
        
        ContextMenu context_menu(
            &assets_manager,
            &inputs_handler,
            &messages_handler,
            &window
        );
        
        HexMap hex_map(
            6,
            &assets_manager,
            &inputs_handler,
            &messages_handler,
            &window
        );
        
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
                
                context_menu.process();
                
                //...
                
                hex_map.process();
                
                if (inputs_handler.key_pressed_once_vec[sf::Keyboard::Q]) {
                    std::cout << "Q" << std::endl;
                    hex_map.reroll();
                }
                
                if (inputs_handler.key_pressed_once_vec[sf::Keyboard::R]) {
                    std::cout << "R" << std::endl;
                    hex_map.toggleResourceOverlay();
                }
                
                if (inputs_handler.key_pressed_once_vec[sf::Keyboard::A]) {
                    std::cout << "A" << std::endl;
                    hex_map.assess();
                }
                
                window.clear();
                
                context_menu.draw();
                hex_map.draw();
                
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
