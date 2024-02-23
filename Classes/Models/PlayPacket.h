//
//  PlayPacket.h
//  tictactoe
//
//  Created by Manoj Bojja on 24/02/24.
//

#ifndef PlayPacket_h
#define PlayPacket_h

#include "BasePacket.h"

class PlayPacket: public BasePacket {
    std::string username;
public:
    PlayPacket(const std::string& username);
    static PlayPacket* parse(const std::string& json);
    std::string toJSONString() const override;
};

#endif /* PlayPacket_h */
