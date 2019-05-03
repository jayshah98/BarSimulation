//
//  Event.hpp
//  Bar
//
//  Created by Jay Shah on 11/7/18.
//  Copyright © 2018 Jay Shah. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp
#include <iostream>
#include <stdio.h>
using namespace std;

class Event {
    public:
    // constructor requires time of event
    Event(){
        int time = 0;
    }
    
    Event (unsigned int t) : time(t) {}
    // time is a public data field
    unsigned int time;
    // execute event by invoking this method
    
    virtual void processEvent();
    
    friend ostream& operator<<(ostream& os, const Event *dom);
    
    friend bool operator> (const Event &x, const Event &y);
    friend bool operator< (const Event &x, const Event &y);
    friend bool operator== (const Event &x, const Event &y);
    //friend bool operator ( ) (const Event * left, const Event * right);
};

bool operator> (const Event &x, const Event &y){
    return (x.time > y.time);
}
bool operator< (const Event &x, const Event &y){
    return (x.time < y.time);
}
bool operator== (const Event &x, const Event &y){
    return (x.time == y.time);
}

ostream& operator<<(ostream& os, const Event *dom){
    return os << dom;
}


#endif /* Event_hpp */
