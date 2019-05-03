//
//  ArriveEvent.cpp
//  Bar
//
//  Created by Jay Shah on 11/7/18.
//  Copyright © 2018 Jay Shah. All rights reserved.
//

#include <stdio.h>
#include "ArriveEvent.h"
#include "OrderEvent.hpp"
#include <random>
#include "randomInteger.h"


void ArriveEvent::processEvent( )
{
    if (theBar.canSeat(groupSize))
        // place an order within 2 & 10 minutes
        theSimulation.scheduleEvent (new OrderEvent(theSimulation.currentTime + randBetween(2,10), groupSize));
}
