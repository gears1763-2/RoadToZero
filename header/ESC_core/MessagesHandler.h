/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the MessagesHandler class.
 *
 */


///
/// \file MessagesHandler.h
///
/// \brief Header file for the MessagesHandler class.
///


#ifndef MESSAGESHANDLER_H
#define MESSAGESHANDLER_H


#include "constants.h"
#include "includes.h"


///
/// \struct Message
///
/// \brief A structure which defines a standard message format
///

struct Message {
    std::string sender_name = ""; ///< A string representation of the sender's class.
    unsigned long long int sender_address = 0; /// An int representation of the sender's memory address.
    
    std::string subject = ""; ///< A string describing the message subject.
    std::string channel = ""; ///< A string identifying the appropriate channel for this message.
    
    std::vector<bool> bool_payload_vec = {}; ///< A vector <bool> payload.
    std::vector<int> int_payload_vec = {}; ///< A vector <int> payload.
    std::vector<double> double_payload_vec = {}; ///< A vector <double> payload.
    
    std::string string_payload = ""; ///< A string payload.
};


///
/// \class MessagesHandler
///
/// \brief A class which handles message traffic between game objects.
///

class MessagesHandler {
    private:
        //  1. attributes
        std::map<std::string, std::list<Message>> message_map; ///< A map <string, list of Message> for sending and receiving messages. Here the key is the channel, and each channel maintains a list (history) of messages.
        
        
        //  2. methods
        //...
    
    
    public:
        //  1. attributes
        //...
        
        
        //  2. methods
        MessagesHandler(void);
        
        void addChannel(std::string);
        void removeChannel(std::string);
        
        void sendMessage(Message);
        bool isEmpty(std::string);
        Message receiveMessage(std::string);
        
        void process(void);
        
        void clear(void);
        ~MessagesHandler(void);
    
};  /* MessagesHandler */


#endif  /* MESSAGESHANDLER_H */
