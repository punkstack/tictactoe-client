//
//  PacketParser.h
//  tictactoe
//
//  Created by Manoj Bojja on 22/02/24.
//

#ifndef PacketParser_h
#define PacketParser_h
#include "BasePacket.h"
#include "ConnectPacket.h"
#include "json/document.h"

using namespace rapidjson;


class PacketParser {
public:
    static BasePacket* parse(const std::string& json);
};


#endif /* PacketParser_h */
