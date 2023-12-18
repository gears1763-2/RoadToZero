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
/// \fn void MessagesHandler :: addChannel(std::string channel)
///
/// \brief Method to add channel to message map.
///
/// \param channel The key for the message channel being added.
///

void MessagesHandler :: addChannel(std::string channel)
{
    //  1. check if channel is in map (if so, throw error)
    if (this->message_map.count(channel) > 0) {
        std::string error_str = "ERROR  MessagesHandler::addChannel()  channel ";
        error_str += channel;
        error_str += " is already in message map";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. add channel to map
    this->message_map[channel] = {};
    
    return;
}   /* addChannel() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void MessagesHandler :: removeChannel(std::string channel)
///
/// \brief Method to remove channel from message map.
///
/// \param channel The key for the message channel being removed.
///

void MessagesHandler :: removeChannel(std::string channel)
{
    //  1. check if channel is in map (if not, throw error)
    if (this->message_map.count(channel) <= 0) {
        std::string error_str = "ERROR  MessagesHandler::removeChannel()  channel ";
        error_str += channel;
        error_str += " is not in message map";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. remove channel from map
    this->message_map[channel].clear();
    this->message_map.erase(channel);
    
    return;
}   /* removeChannel() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void MessagesHandler :: sendMessage(Message message)
///
/// \brief Method to send a message to the message map.
///
/// \param message The message to be sent.
///

void MessagesHandler :: sendMessage(Message message)
{
    //  1. check if channel is in map (if not, throw error)
    std::string channel = message.channel;
    
    if (this->message_map.count(channel) <= 0) {
        std::string error_str = "ERROR  MessagesHandler::sendMessage()  channel ";
        error_str += channel;
        error_str += " is not in message map";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. send message to message map
    this->message_map[channel].push_back(message);
    
    return;
}   /* sendMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn bool MessagesHandler :: isEmpty(std::string channel)
///
/// \brief Method to check if channel is empty.
///
/// \param channel The key for the message channel being checked.
///
/// \return A boolean indicating whether the channel is empty or not.
///

bool MessagesHandler :: isEmpty(std::string channel)
{
    //  1. check if channel is in map (if not, throw error)
    if (this->message_map.count(channel) <= 0) {
        std::string error_str = "ERROR  MessagesHandler::isEmpty()  channel ";
        error_str += channel;
        error_str += " is not in message map";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    if (this->message_map[channel].empty()) {
        return true;
    }
    else {
        return false;
    }
}   /* isEmpty() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn Message MessagesHandler :: receiveMessage(std::string channel)
///
/// \brief Method to receive the latest message in the given channel.
///
/// \param channel The key for the message channel being received from.
///
/// \return The latest message in the given channel.
///

Message MessagesHandler :: receiveMessage(std::string channel)
{
    //  1. check if channel is in map (if not, throw error)
    if (this->message_map.count(channel) <= 0) {
        std::string error_str = "ERROR  MessagesHandler::receiveMessage()  channel ";
        error_str += channel;
        error_str += " is not in message map";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. check if channel is empty (if so, throw error)
    if (this->message_map[channel].empty()) {
        std::string error_str = "ERROR  MessagesHandler::receiveMessage()  channel ";
        error_str += channel;
        error_str += " is empty";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  3. receive message
    Message message = this->message_map[channel].back();
    
    return message;
}   /* receiveMessage() */

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
/// \fn void MessagesHandler :: clear(void)
///
/// \brief Method to clear the MessagesHandler.
///

void MessagesHandler :: clear(void)
{
    
    std::map<std::string, std::list<Message>>::iterator map_iter;
    for (
        map_iter = this->message_map.begin();
        map_iter != this->message_map.end();
        map_iter++
    ) {
        map_iter->second.clear();
    }
    this->message_map.clear();
    
    return;
}   /* clear() */

// ---------------------------------------------------------------------------------- //


// ---------------------------------------------------------------------------------- //

///
/// \fn MessagesHandler :: ~MessagesHandler(void)
///
/// \brief Destructor for the MessagesHandler class.
///

MessagesHandler :: ~MessagesHandler(void)
{
    this->clear();
    
    std::cout << "MessagesHandler at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~MessagesHandler() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
