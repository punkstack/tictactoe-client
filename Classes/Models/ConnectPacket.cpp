//
//  ConnectPacket.cpp
//  tictactoe
//
//  Created by Manoj Bojja on 22/02/24.
//

#include "ConnectPacket.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"

using namespace rapidjson;

ConnectPacket::ConnectPacket(const std::string& username, const std::string& deviceId)
    : BasePacket("connect"), username(username), deviceId(deviceId) {}

ConnectPacket* ConnectPacket::parse(const std::string& json) {
    Document doc;
    doc.Parse(json.c_str());

    if (doc.HasParseError()) {
        // Handle parse error
        return nullptr;
    }

    std::string username = doc["username"].GetString();
    std::string deviceId = doc["deviceId"].GetString();

    return new ConnectPacket(username, deviceId);
}

std::string ConnectPacket::toJSONString() const {
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);

    writer.StartObject();
    this->writeBase(writer); // Write base packet fields
    writer.Key("username");
    writer.String(username.c_str());
    writer.Key("deviceId");
    writer.String(deviceId.c_str());
    writer.EndObject();

    return buffer.GetString();
}
