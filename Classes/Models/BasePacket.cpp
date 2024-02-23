//
// Created by Manoj Bojja on 22/02/24.
//



#include "BasePacket.h"


void BasePacket::writeBase(Writer<rapidjson::StringBuffer> &writer) const {
    writer.Key("type");
    writer.String(type.c_str());
}