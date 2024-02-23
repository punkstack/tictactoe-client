//
// Created by Manoj Bojja on 22/02/24.
//

#ifndef TICTACTOE_BASEPACKET_H
#define TICTACTOE_BASEPACKET_H


#include <string>
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"
#include "json/error/en.h"

using namespace rapidjson;

class BasePacket {
public:
    std::string type;

    BasePacket(const std::string& type) : type(type) {}

    virtual std::string toJSONString() const = 0;

protected:
    void writeBase(Writer<rapidjson::StringBuffer> &writer) const;
};

#endif //TICTACTOE_BASEPACKET_H
