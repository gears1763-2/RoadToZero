/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for the MessageHub class.
 *
 */


/*
 *   **** 3-Clause BSD License ****
 *   ref: https://opensource.org/license/bsd-3-clause/
 *
 *
 *   Copyright 2023 - [ESC] Interactive (Anthony Truelove MASc, P.Eng.)
 *
 *   Redistribution and use in source and binary forms, with or without modification, are
 *   permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list of
 *   conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this list
 *   of conditions and the following disclaimer in the documentation and/or other materials
 *   provided with the distribution.
 *
 *   3. Neither the name of the copyright holder nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without specific prior
 *   written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY
 *   EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 *   THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 *   OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 *   TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
    
    std::map<std::string, bool> bool_payload = {}; ///< A boolean payload.
    std::map<std::string, int> int_payload = {}; ///< A vector payload.
    std::map<std::string, double> double_payload = {}; ///< A vector payload.
    std::map<std::string, std::string> string_payload = {}; ///< A string payload.
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
