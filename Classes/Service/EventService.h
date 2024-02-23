//
//  EventService.h
//  tictactoe
//
//  Created by Manoj Bojja on 24/02/24.
//

#ifndef EventService_h
#define EventService_h
#include <iostream>
#include <map>
#include <vector>
#include <functional>

class EventService {
public:
    using EventHandler = std::function<void()>;
    
    static EventService* getInstance();
    template<typename T>
    void addDispatcher(const std::string& eventType, T* instance, void (T::*memberFunction)());
    void publish(const std::string& eventType);
    
private:
    EventService() {}
    EventService(const EventService&) = delete;
    EventService& operator=(const EventService&) = delete;
    std::map<std::string, std::vector<EventHandler>> eventHandlers;
};

#endif /* EventService_h */
