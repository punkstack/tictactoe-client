//
//  EventService.cpp
//  tictactoe
//
//  Created by Manoj Bojja on 24/02/24.
//

#include "EventService.h"


EventService* EventService::getInstance() {
    static EventService instance;
            return &instance;
}

template<typename T>
void EventService::addDispatcher(const std::string &eventType
                                 , T *instance, void (T::*memberFunction)()) {
    EventHandler handler = [instance, memberFunction]() {
        (instance->*memberFunction)();
    };
    eventHandlers[eventType].push_back(handler);
}

void EventService::publish(const std::string &eventType) {
    if (eventHandlers.find(eventType) != eventHandlers.end()) {
        for (auto& handler : eventHandlers[eventType]) {
            handler(); // Call the event handler
        }
    }
}
