//
//  MainSceneController.h
//  tictactoe
//
//  Created by Manoj Bojja on 24/02/24.
//

#ifndef MainSceneController_h
#define MainSceneController_h
#include "extensions/cocos-ext.h"
#include "WebSocketController.h"
#include "MainScene.h"


class MainSceneController {
    MainScene* m_mainScene = nullptr;
public:
    MainSceneController* init();
    void renderMainView();
    void connectToServer();
    bool play();
    void onWebSocketMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data);
};

#endif /* MainSceneController_h */
