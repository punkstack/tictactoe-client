#ifndef __WEBSOCKET_CONTROLLER_H__
#define __WEBSOCKET_CONTROLLER_H__

#include "cocos2d.h"
#include "network/WebSocket.h"
#include <functional>

class WebSocketController : public cocos2d::Ref, public cocos2d::network::WebSocket::Delegate {
public:
    // Get the singleton instance of WebSocketController
    static WebSocketController* getInstance();

    // Initialize WebSocket connection with the given URL
    bool initWebSocket(const std::string& url);

    // Send a message through the WebSocket
    void sendMessage(const std::string& message);

    // Close the WebSocket connection
    void closeConnection();

    // Set the callback function for onMessage event
    void setOnMessageCallback(const std::function<void(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data)>& callback);

    // Set the callback function for onError event
    void setOnErrorCallback(const std::function<void(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error)>& callback);

    // WebSocket Delegate methods
    virtual void onOpen(cocos2d::network::WebSocket* ws) override;
    virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data) override;
    virtual void onClose(cocos2d::network::WebSocket* ws) override;
    virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error) override;

protected:
    // Constructor is protected to prevent instantiation outside of getInstance()
    WebSocketController();

    // Destructor
    virtual ~WebSocketController();

private:
    // Singleton instance
    static WebSocketController* _instance;

    // Pointer to the WebSocket instance
    cocos2d::network::WebSocket* _webSocket;

    // Callback functions for onMessage and onError events
    std::function<void(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data)> _onMessageCallback;
    std::function<void(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error)> _onErrorCallback;
};

#endif // __WEBSOCKET_CONTROLLER_H__
