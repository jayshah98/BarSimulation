//
//  OrderEvent.hpp
//  Bar
//
//  Created by Jay Shah on 11/7/18.
//  Copyright © 2018 Jay Shah. All rights reserved.
//

#ifndef OrderEvent_hpp
#define OrderEvent_hpp

#include <stdio.h>
#include "Event.hpp"
#include "SoftwareGurusBar.h"
#include "LeaveEvent.hpp"
#include "randomInteger.h"


class OrderEvent : public Event {
public: OrderEvent (unsigned int time, unsigned int gs)
    : Event(time), groupSize(gs) { }
     void processEvent ( ){
         for (int i = 0; i < groupSize; i++)
             theBar.order(randBetween(1,3));
         int t = theSimulation.currentTime + randBetween(15,35);
         theSimulation.scheduleEvent (new LeaveEvent(t, groupSize));
         

     }
protected:
    unsigned int groupSize;
};

#endif
