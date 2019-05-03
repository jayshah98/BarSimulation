#include <iostream>
#include <stdio.h>
#include <random>
#include "SoftwareGurusBar.h"
#include "ArriveEvent.h"
#include "OrderEvent.hpp"
#include "SimulationFramework.hpp"
#include "randomInteger.h"

using namespace std;



int main() {
    
    // load queue with some number of initial events
    unsigned int t = 0;
    while (t < 30) {
        t = rand()%6;
        theSimulation.scheduleEvent(new ArriveEvent(t, 1 + randomizer(4)));
    }
    
    // then run simulation and print profits
    theSimulation.run();
    cout << "Total profits " << theBar.getProfit() << endl;
}
