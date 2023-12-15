/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the AssetsManager class.
 *
 */


///
/// \file AssetsManager.cpp
///
/// \brief Implementation file for the AssetsManager class.
///
/// A class which manages visual and sound assets.
///


#include "../../header/ESC_core/AssetsManager.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

//...

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn AssetsManager :: AssetsManager(void)
///
/// \brief Constructor for the AssetsManager class.
///

AssetsManager :: AssetsManager(void)
{
    //...
    
    std::cout << "AssetsManager constructed at " << this << std::endl;
    
    return;
}   /* AssetsManager() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

//...

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn AssetsManager :: ~AssetsManager(void)
///
/// \brief Destructor for the AssetsManager class.
///

AssetsManager :: ~AssetsManager(void)
{
    std::cout << "AssetsManager at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~AssetsManager() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
