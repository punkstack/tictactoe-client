//
// Created by Manoj Bojja on 22/02/24.
//


#ifndef TICTACTOE_CONNECTPACKET_H
#define TICTACTOE_CONNECTPACKET_H

#include "BasePacket.h"


class ConnectPacket : public BasePacket {
public:
    std::string username;
    std::string deviceId;
    
    ConnectPacket(const std::string& username, const std::string& deviceId);
    static ConnectPacket* parse(const std::string& json);
    std::string toJSONString() const override;
};



#endif //TICTACTOE_CONNECTPACKET_H
