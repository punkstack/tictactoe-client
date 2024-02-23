//
//  PacketParser.cpp
//  tictactoe
//
//  Created by Manoj Bojja on 22/02/24.
//


#include "PacketParser.h"
#include "Definations.h"
#include "ConnectPacket.h"

BasePacket* PacketParser::parse(const std::string& json) {
    Document doc;
    doc.Parse(json.c_str());
    
    if (doc.HasParseError()) {
        return nullptr;
    }
    
    std::string type = doc["type"].GetString();
    
    if (type == "connect") {
        std::string username = doc["username"].GetString();
        std::string deviceId = doc["deviceId"].GetString();
        return new ConnectPacket(username, deviceId);
    }
    
    return nullptr;
}
