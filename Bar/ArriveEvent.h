//
//  ArriveEvent.h
//  Bar
//
//  Created by Jay Shah on 11/7/18.
//  Copyright © 2018 Jay Shah. All rights reserved.
//

#ifndef ArriveEvent_h
#define ArriveEvent_h
#include "Event.hpp"

class ArriveEvent : public Event {
public: ArriveEvent (unsigned int time, unsigned int gs)
    : Event(time), groupSize(gs) { }
    void processEvent ( );
protected:
    unsigned int groupSize;
};

#endif /* ArriveEvent_h */
