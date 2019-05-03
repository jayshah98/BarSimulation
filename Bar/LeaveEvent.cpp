//
//  LeaveEvent.cpp
//  Bar
//
//  Created by Jay Shah on 11/7/18.
//  Copyright © 2018 Jay Shah. All rights reserved.
//

#include "LeaveEvent.hpp"
#include "SoftwareGurusBar.h"

void LeaveEvent::processEvent ( )
{
    theBar.leave(groupSize);
}
