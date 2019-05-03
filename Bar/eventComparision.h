//
//  eventComparision.h
//  Bar
//
//  Created by Jay Shah on 11/7/18.
//  Copyright © 2018 Jay Shah. All rights reserved.
//

#ifndef eventComparision_h
#define eventComparision_h
#include "Event.hpp"


class eventComparison {
    public:
        bool operator ( ) (Event * left, Event * right)
        {
            return left->time > right->time;
        }

};
#endif /* eventComparision_h */
