/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the MessageHub class.
 *
 */


///
/// \file MessageHub.h
///
/// \brief Header file for the MessageHub class.
///


#ifndef MESSAGEHUB_H
#define MESSAGEHUB_H


#include "constants.h"
#include "includes.h"


///
/// \struct Message
///
/// \brief A structure which defines a standard message format
///

struct Message {
    std::string channel = ""; ///< A string identifying the appropriate channel for this message.
    std::string subject = ""; ///< A string describing the message subject.
    
    std::vector<bool> bool_payload_vec = {}; ///< A vector <bool> payload.
    std::vector<int> int_payload_vec = {}; ///< A vector <int> payload.
    std::vector<double> double_payload_vec = {}; ///< A vector <double> payload.
    std::string string_payload = ""; ///< A string payload.
};  /* Message */


///
/// \class MessageHub
///
/// \brief A class which acts as a central hub for inter-object message traffic.
///

class MessageHub {
    private:
        //  1. attributes
        std::map<std::string, std::list<Message>> message_map; ///< A map <string, list of Message> for sending and receiving messages. Here the key is the channel, and each channel maintains a list (history) of messages.
        
        
        //  2. methods
        //...
    
    
    public:
        //  1. attributes
        //...
        
        
        //  2. methods
        MessageHub(void);
        
        bool hasTraffic(void);
        
        void addChannel(std::string);
        void removeChannel(std::string);
        
        void sendMessage(Message);
        
        bool isEmpty(std::string);
        Message receiveMessage(std::string);
        void popMessage(std::string);
        
        void clearMessages(void);
        void clear(void);
        ~MessageHub(void);
    
};  /* MessageHub */


#endif  /* MESSAGEHUB_H */
