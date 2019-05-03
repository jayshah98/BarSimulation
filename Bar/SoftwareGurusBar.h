#ifndef SoftwareGurusBar_h
#define SoftwareGurusBar_h

#include "SimulationFramework.hpp"
#include <random>
#include "Event.hpp"

class SoftwareGurusBar {
    public:
        SoftwareGurusBar()
        :freeChairs(50),profit(0.0){ }
    
        bool canSeat (unsigned int numberOfPeople);
        void order(unsigned int numberOfScoops);
        void leave(unsigned int numberOfPeople);
        double getProfit();
    
    private:
        unsigned int freeChairs;
        double profit;
};
SoftwareGurusBar theBar;
SimulationFramework theSimulation;


#endif
