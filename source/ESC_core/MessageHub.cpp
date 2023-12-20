/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Implementation file for the MessageHub class.
 *
 */


///
/// \file MessageHub.cpp
///
/// \brief Implementation file for the MessageHub class.
///
/// A class which acts as a central hub for inter-object message traffic.
///


#include "../../header/ESC_core/MessageHub.h"


// ======== PRIVATE ================================================================= //

// ---------------------------------------------------------------------------------- //

///

// ---------------------------------------------------------------------------------- //

// ======== END PRIVATE ============================================================= //



// ======== PUBLIC ================================================================== //

// ---------------------------------------------------------------------------------- //

///
/// \fn MessageHub :: MessageHub(void)
///
/// \brief Constructor for the MessageHub class.
///

MessageHub :: MessageHub(void)
{
    //...
    
    std::cout << "MessageHub constructed at " << this << std::endl;
    
    return;
}   /* MessageHub() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn bool MessageHub :: hasTraffic(void)
///
/// \brief Method to determine if there remains any message traffic.
///

bool MessageHub :: hasTraffic(void)
{
    std::map<std::string, std::list<Message>>::iterator map_iter;
    for (
        map_iter = this->message_map.begin();
        map_iter != this->message_map.end();
        map_iter++
    ) {
        if (not map_iter->second.empty()) {
            return true;
        }
    }
    
    return false;
}   /* hasTraffic() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void MessageHub :: addChannel(std::string channel)
///
/// \brief Method to add channel to message map.
///
/// \param channel The key for the message channel being added.
///

void MessageHub :: addChannel(std::string channel)
{
    //  1. check if channel is in map (if so, throw error)
    if (this->message_map.count(channel) > 0) {
        std::string error_str = "ERROR  MessageHub::addChannel()  channel ";
        error_str += channel;
        error_str += " is already in message map";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. add channel to map
    this->message_map[channel] = {};
    
    std::cout << "Channel " << channel << " added to message hub" << std::endl;
    
    return;
}   /* addChannel() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void MessageHub :: removeChannel(std::string channel)
///
/// \brief Method to remove channel from message map.
///
/// \param channel The key for the message channel being removed.
///

void MessageHub :: removeChannel(std::string channel)
{
    //  1. check if channel is in map (if not, throw error)
    if (this->message_map.count(channel) <= 0) {
        std::string error_str = "ERROR  MessageHub::removeChannel()  channel ";
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
    
    std::cout << "Channel " << channel << " removed from message hub" << std::endl;
    
    return;
}   /* removeChannel() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void MessageHub :: sendMessage(Message message)
///
/// \brief Method to send a message to the message map. Channels are implemented
///     in a first in, first out manner (i.e. message queue).
///
/// \param message The message to be sent.
///

void MessageHub :: sendMessage(Message message)
{
    //  1. check if channel is in map (if not, throw error)
    std::string channel = message.channel;
    
    if (this->message_map.count(channel) <= 0) {
        std::string error_str = "ERROR  MessageHub::sendMessage()  channel ";
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
/// \fn bool MessageHub :: isEmpty(std::string channel)
///
/// \brief Method to check if channel is empty.
///
/// \param channel The key for the message channel being checked.
///
/// \return A boolean indicating whether the channel is empty or not.
///

bool MessageHub :: isEmpty(std::string channel)
{
    //  1. check if channel is in map (if not, throw error)
    if (this->message_map.count(channel) <= 0) {
        std::string error_str = "ERROR  MessageHub::isEmpty()  channel ";
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
/// \fn Message MessageHub :: receiveMessage(std::string channel)
///
/// \brief Method to receive the first message in the channel. Channels are implemented
///     in a first in, first out manner (i.e. message queue).
///
/// \param channel The key for the message channel being received from.
///
/// \return The first message in the given channel.
///

Message MessageHub :: receiveMessage(std::string channel)
{
    //  1. check if channel is in map (if not, throw error)
    if (this->message_map.count(channel) <= 0) {
        std::string error_str = "ERROR  MessageHub::receiveMessage()  channel ";
        error_str += channel;
        error_str += " is not in message map";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. check if channel is empty (if so, throw error)
    if (this->message_map[channel].empty()) {
        std::string error_str = "ERROR  MessageHub::receiveMessage()  channel ";
        error_str += channel;
        error_str += " is empty";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  3. receive message
    Message message = this->message_map[channel].front();
    
    return message;
}   /* receiveMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void MessageHub :: popMessage(std::string channel)
///
/// \brief Method to pop first message off of the given channel. Channels are
///     implemented in a first in, first out manner (i.e. message queue).
///
/// \param channel The key for the message channel being popped.
///

void MessageHub :: popMessage(std::string channel)
{
    //  1. check if channel is in map (if not, throw error)
    if (this->message_map.count(channel) <= 0) {
        std::string error_str = "ERROR  MessageHub::receiveMessage()  channel ";
        error_str += channel;
        error_str += " is not in message map";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  2. check if channel is empty (if so, throw error)
    if (this->message_map[channel].empty()) {
        std::string error_str = "ERROR  MessageHub::receiveMessage()  channel ";
        error_str += channel;
        error_str += " is empty";
        
        #ifdef _WIN32
            std::cout << error_str << std::endl;
        #endif  /* _WIN32 */
        
        throw std::runtime_error(error_str);
    }
    
    //  3. pop message
    this->message_map[channel].pop_front();
    
    return;
}   /* popMessage() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void MessageHub :: clearMessages(void)
///
/// \brief Method to clear messages from the MessageHub.
///

void MessageHub :: clearMessages(void)
{
    std::map<std::string, std::list<Message>>::iterator map_iter;
    for (
        map_iter = this->message_map.begin();
        map_iter != this->message_map.end();
        map_iter++
    ) {
        map_iter->second.clear();
    }
    
    return;
}   /* clearMessages() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void MessageHub :: clear(void)
///
/// \brief Method to clear the MessageHub.
///

void MessageHub :: clear(void)
{
    
    this->clearMessages();
    this->message_map.clear();
    
    return;
}   /* clear() */

// ---------------------------------------------------------------------------------- //


// ---------------------------------------------------------------------------------- //

///
/// \fn MessageHub :: ~MessageHub(void)
///
/// \brief Destructor for the MessageHub class.
///

MessageHub :: ~MessageHub(void)
{
    this->clear();
    
    std::cout << "MessageHub at " << this << " destroyed" << std::endl;
    
    return;
}   /* ~MessageHub() */

// ---------------------------------------------------------------------------------- //

// ======== END PUBLIC ============================================================== //
