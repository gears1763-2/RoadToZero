/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the MessagesHandler class.
 *
 */


///
/// \file MessagesHandler.cpp
///
/// \brief Implementation file for the MessagesHandler class.
///
/// A class which handles message traffic between game objects.
///


#include "../../header/ESC_core/MessagesHandler.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn MessagesHandler :: MessagesHandler(void)
///
/// \brief Constructor for the MessagesHandler class.
///

MessagesHandler :: MessagesHandler(void)
{
    //...
    
    std::cout << "MessagesHandler constructed at " << this << std::endl;
    
    return;
}   /* MessagesHandler() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void MessagesHandler :: process(void)
///
/// \brief Method to process messages. To be called once per frame.
///

void MessagesHandler :: process(void)
{
    //...
    
    return;
}   /* process() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn MessagesHandler :: ~MessagesHandler(void)
///
/// \brief Destructor for the MessagesHandler class.
///

MessagesHandler :: ~MessagesHandler(void)
{
    std::cout << "MessagesHandler at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~MessagesHandler() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
