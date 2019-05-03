//
//  SimulationFramework.hpp
//  Bar
//
//  Created by Jay Shah on 11/7/18.
//  Copyright © 2018 Jay Shah. All rights reserved.
//

#ifndef SimulationFramework_hpp
#define SimulationFramework_hpp
#include <stdio.h>
#include "Event.hpp"
#include "priority_queue.hpp"
#include <vector>
#include <random>

class SimulationFramework {
public:
    SimulationFramework ( ) : eventQueue(),currentTime(0) { }
    void scheduleEvent (Event * newEvent)
    {
        // insert newEvent into eventQueue (Priority Queue)
        // Priority Queue is based on MinHeap using newEvent’s time
        eventQueue.insert(*newEvent);
    }
    
    int weightedProbablility(std::vector<unsigned int> v);
    
    void run( );
    unsigned int currentTime;
protected:
    Priority_Queue eventQueue;
};


#endif
