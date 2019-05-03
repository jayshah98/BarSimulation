//
//  LeaveEvent.hpp
//  Bar
//
//  Created by Jay Shah on 11/7/18.
//  Copyright © 2018 Jay Shah. All rights reserved.
//

#ifndef LeaveEvent_hpp
#define LeaveEvent_hpp

#include <stdio.h>
#include "Event.hpp"

class LeaveEvent : public Event {
public:
    LeaveEvent (unsigned int time, unsigned int gs):Event(time), groupSize(gs) { }
    void processEvent ( );
protected:
    unsigned int groupSize;
};




#endif /* LeaveEvent_hpp */
