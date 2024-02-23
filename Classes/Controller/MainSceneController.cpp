//
//  MainSceneController.cpp
//  tictactoe
//
//  Created by Manoj Bojja on 24/02/24.
//

#include "MainSceneController.h"
#include "Definations.h"
#include "ConnectPacket.h"
#include "Definations.h"
#include "PacketParser.h"
#include "BasePacket.h"
#include "SceneManager.h"
#include "PlayPacket.h"

USING_NS_CC;

MainSceneController* MainSceneController::init() {
    return new MainSceneController();
}

void MainSceneController::renderMainView() {
    
    m_mainScene = dynamic_cast<MainScene*>(MainScene::createScene());
    if (m_mainScene != nullptr) {
        m_mainScene->setPlayCallback(std::bind(&MainSceneController::play, this));
        SceneManager::SwitchScene(m_mainScene);
        this->connectToServer();
    }
}

bool MainSceneController::play() {
    PlayPacket playPacket(USERNAME);
    std::string message = playPacket.toJSONString();
    WebSocketController::getInstance()->sendMessage(message);
    return true;
}


void MainSceneController::connectToServer() {
    auto webSocketController = WebSocketController::getInstance();
    webSocketController->initWebSocket(SERVER_ADDRESS);
    
    ConnectPacket cP(USERNAME,DEVICEID);
    std::string message = cP.toJSONString();
    WebSocketController::getInstance()->sendMessage(message);
    if (m_mainScene != nullptr) {
        auto sc = Director::getInstance()->getScheduler();
        sc->schedule([this](float dt){
            this->m_mainScene->setPlayerButtonVisible();
        }, this, 0, 0, 1, false, "delayCall");
    }
}


void MainSceneController::onWebSocketMessage(network::WebSocket* ws, const network::WebSocket::Data& data)
{
    std::string message(data.bytes, data.bytes + data.len);
    
    BasePacket* packet = PacketParser::parse(message);
    
//    if (MatchFoundPacket* matchPacket = dynamic_cast<MatchFoundPacket*>(packet))
//    {
//        Director::getInstance()->replaceScene(GameScene::createScene());
//    }
    
}
