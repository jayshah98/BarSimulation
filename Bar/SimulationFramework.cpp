//
//  SimulationFramework.cpp
//  Bar
//
//  Created by Jay Shah on 11/7/18.
//  Copyright © 2018 Jay Shah. All rights reserved.
//

#include "SimulationFramework.hpp"
void SimulationFramework::run( )
{
    // execute events until event queue becomes empty
    while (!eventQueue.isEmpty( )) {
        // copy & remove min-priority element (min time) from eventQueue
        Event nextEvent = eventQueue.peek( );
        eventQueue.del_min( );
        // update simulation’s current time
        currentTime = nextEvent.time;
        // process nextEvent
        nextEvent.processEvent( );
        // cleanup nextEvent object
    }
}

int SimulationFramework::weightedProbablility(std::vector<unsigned int> v){
    int sum = 0;
    for(int i = 0; i < v.size(); i ++){
        sum+=v[i];
    }
    
    int t = rand()%sum;
    if((sum * .15) > t){
        return 0;
    }
    if((sum * .75) > t){
        return 1;
    }
    else
        return 2;
  
}
