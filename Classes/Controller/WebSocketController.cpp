#include "WebSocketController.h"
#include "EventService.h"
#include "Definations.h"


// Initialize the static instance pointer
WebSocketController* WebSocketController::_instance = nullptr;

// Get the singleton instance of WebSocketController
WebSocketController* WebSocketController::getInstance() {
    if (!_instance) {
        _instance = new WebSocketController();
        // Retain the instance to prevent it from being auto-released
        _instance->retain();
    }
    return _instance;
}

// Constructor
WebSocketController::WebSocketController() : _webSocket(nullptr) {
}

// Destructor
WebSocketController::~WebSocketController() {
    if (_webSocket) {
        _webSocket->close();
        delete _webSocket;
        _webSocket = nullptr;
    }
}

// Initialize WebSocket with URL
bool WebSocketController::initWebSocket(const std::string& url) {
    if (!_webSocket) {
        _webSocket = new cocos2d::network::WebSocket();
        if (!_webSocket->init(*this, url)) {
            delete _webSocket;
            _webSocket = nullptr;
            return false;
        }
    }
    return true;
}

// Send message through WebSocket
void WebSocketController::sendMessage(const std::string& message) {
    if (_webSocket && _webSocket->getReadyState() == cocos2d::network::WebSocket::State::OPEN) {
        _webSocket->send(message);
    }
}

// Close the WebSocket connection
void WebSocketController::closeConnection() {
    if (_webSocket) {
        _webSocket->close();
    }
}

// WebSocket Delegate method implementations
void WebSocketController::onOpen(cocos2d::network::WebSocket* ws) {
    cocos2d::log("WebSocket opened");
    EventService::getInstance()->publish(CONNECTED);
}

void WebSocketController::onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data) {
    if (_onMessageCallback) {
        _onMessageCallback(ws, data);
    }
}

void WebSocketController::onClose(cocos2d::network::WebSocket* ws) {
    cocos2d::log("WebSocket closed");
}

void WebSocketController::onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error) {
    if (_onErrorCallback) {
        _onErrorCallback(ws, error);
    }
}

// Set the callback function for onMessage event
void WebSocketController::setOnMessageCallback(const std::function<void(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data)>& callback) {
    _onMessageCallback = callback;
}

// Set the callback function for onError event
void WebSocketController::setOnErrorCallback(const std::function<void(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error)>& callback) {
    _onErrorCallback = callback;
}
