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
    
    printGold("\tTesting AssetsManager");
    std::cout << std::endl;
    
    srand(time(NULL));
    int n_dots = 8;
    
    
    try {
        //  1. construct
        InputsHandler inputs_handler;
        AssetsManager assets_manager;
        
        
        //  2. load/open some test assets
        assets_manager.loadFont("assets/fonts/DroidSansMono.ttf", "DroidSansMono");
        assets_manager.loadTexture(
            "assets/ESC_brand/ESC_key_98x81.png",
            "ESC_key_98x81"
        );
        assets_manager.loadSound("assets/ESC_brand/key_press.ogg", "key_press");
        assets_manager.loadTrack(
            "assets/audio/tracks/AlexanderBlu_BackgroundElectronicModernMusic.ogg",
            "AlexanderBlu_BackgroundElectronicModernMusic"
        );
        
        
        //  3. test game loop
        sf::Clock clock;
        sf::Event event;
        sf::RenderWindow window(sf::VideoMode(800, 600), "Testing AssetsManager");
        
        double screen_width = window.getSize().x;
        double screen_height = window.getSize().y;
        
        testFloatEquals(
            screen_width,
            800,
            __FILE__,
            __LINE__
        );
        
        testFloatEquals(
            screen_height,
            600,
            __FILE__,
            __LINE__
        );
        
        unsigned long long int frame = 0;
        double time_since_run_s = 0;
        
        assets_manager.playTrack();
        
        sf::Sprite ESC_key(*(assets_manager.getTexture("ESC_key_98x81")));
        
        double sprite_width = ESC_key.getLocalBounds().width;
        double sprite_height = ESC_key.getLocalBounds().height;
        
        double sprite_velocity_x = 256 * (2 * ((double)rand() / RAND_MAX) - 1);
        double sprite_velocity_y = 256 * (2 * ((double)rand() / RAND_MAX) - 1);
        
        ESC_key.setOrigin(sprite_width / 2, sprite_height / 2);
        ESC_key.setPosition(
            (screen_width - sprite_width) * ((double)rand() / RAND_MAX) + sprite_width / 2,
            (screen_height - sprite_height) * ((double)rand() / RAND_MAX) + sprite_height / 2
        );
        
        sf::Text click_text(
            "CLICK!",
            *(assets_manager.getFont("DroidSansMono")),
            16
        );
        
        double text_width = click_text.getLocalBounds().width;
        double text_height = click_text.getLocalBounds().height;
        
        click_text.setOrigin(text_width / 2, text_height / 2);
        
        int alpha = 255;
        
        click_text.setFillColor(sf::Color(255, 255, 255, alpha));
        
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
                
                ESC_key.move(
                    sprite_velocity_x * SECONDS_PER_FRAME,
                    sprite_velocity_y * SECONDS_PER_FRAME
                );
                
                if (
                    ESC_key.getPosition().x <= sprite_width / 2 or
                    ESC_key.getPosition().x >= screen_width - sprite_width / 2
                ) {
                    sprite_velocity_x *= -1;
                    
                    assets_manager.getSound("key_press")->play();
                    
                    alpha = 255;
                    click_text.setPosition(
                        ESC_key.getPosition().x,
                        ESC_key.getPosition().y
                    );
                }
                
                if (
                    ESC_key.getPosition().y <= sprite_height / 2 or
                    ESC_key.getPosition().y >= screen_height - sprite_height / 2
                ) {
                    sprite_velocity_y *= -1;
                    
                    assets_manager.getSound("key_press")->play();
                    
                    alpha = 255;
                    click_text.setPosition(
                        ESC_key.getPosition().x,
                        ESC_key.getPosition().y
                    );
                }
                
                window.clear();
                
                window.draw(ESC_key);
                window.draw(click_text);
                
                window.display();
                
                alpha -= 8;
                if (alpha < 0) {
                    alpha = 0;
                }
                
                click_text.setFillColor(sf::Color(255, 255, 255, alpha));
                
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
