//
//  PlayPacket.cpp
//  tictactoe
//
//  Created by Manoj Bojja on 24/02/24.
//

#include "PlayPacket.h"

#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"

using namespace rapidjson;

PlayPacket::PlayPacket(const std::string& username)
    : BasePacket("play"), username(username) {}

PlayPacket* PlayPacket::parse(const std::string& json) {
    Document doc;
    doc.Parse(json.c_str());

    if (doc.HasParseError()) {
        // Handle parse error
        return nullptr;
    }

    std::string username = doc["username"].GetString();

    return new PlayPacket(username);
}

std::string PlayPacket::toJSONString() const {
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);

    writer.StartObject();
    this->writeBase(writer); // Write base packet fields
    writer.Key("username");
    writer.String(username.c_str());
    writer.EndObject();

    return buffer.GetString();
}
