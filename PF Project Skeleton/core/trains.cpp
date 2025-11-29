#include "trains.h"
#include "simulation_state.h"
#include "grid.h"
#include "switches.h"
#include <cstdlib>

// ============================================================================
// TRAINS.CPP - Train logic
// ============================================================================

// Storage for planned moves (for collisions).

// Previous positions (to detect switch entry).

// ----------------------------------------------------------------------------
// SPAWN TRAINS FOR CURRENT TICK
// ----------------------------------------------------------------------------
// Activate trains scheduled for this tick.
// ----------------------------------------------------------------------------
void spawnTrainsForTick() {
    for(int i=0; i<ntrain;i++){
        if(isspawned[i]){
            continue;
        }
        
        if(currenttick<ttick[i]){//Adding Spawn check rules
            continue;
        }

        int sr=trow[i];//Spawn row
        int sc=tcol[i];

        bool occu=0;
        for(int j=0;j<numacttrain;j++){
            if(trainisact[j]&&actrow[j]==sr&&actcol[j]==sc){ //Checks all active trains then verifies rows and column are same or not
                occu=1;
                break;
            }
        }
        if(occu){//Moves to next tick when the current spawn tick is occupied
            continue;
        }

        int slot =-1;
        for(int j=i; j<mtrains;j++){
            if(!trainisact[j]){//if it finds a slot that is not active it takes that place
                slot=j;
                break;
            }
        }
        if(slot==-1){//if doesnt find slot
            continue;
        }
        trainisact[slot]=1;
        actrow[slot]=trow[i];
        actcol[slot]=tcol[i];
        actdir[ slot]=tdir[i];
        actcolour[slot]=tcolour[i];

        if(slot>=numacttrain){//counts no. of trains that are on the grid active
            numacttrain=slot+1;
        }

        isspawned[i]=1;
    
    }
}

// ----------------------------------------------------------------------------
// DETERMINE NEXT POSITION for a train
// ----------------------------------------------------------------------------
// Compute next position/direction from current tile and rules.
// ----------------------------------------------------------------------------
bool determineNextPosition() {
}

// ----------------------------------------------------------------------------
// GET NEXT DIRECTION based on current tile and direction
// ----------------------------------------------------------------------------
// Return new direction after entering the tile.
// ----------------------------------------------------------------------------
int getNextDirection() {
}

// ----------------------------------------------------------------------------
// SMART ROUTING AT CROSSING - Route train to its matched destination
// ----------------------------------------------------------------------------
// Choose best direction at '+' toward destination.
// ----------------------------------------------------------------------------
int getSmartDirectionAtCrossing() {
}

// ----------------------------------------------------------------------------
// DETERMINE ALL ROUTES (PHASE 2)
// ----------------------------------------------------------------------------
// Fill next positions/directions for all trains.
// ----------------------------------------------------------------------------
void determineAllRoutes() {
}

// ----------------------------------------------------------------------------
// MOVE ALL TRAINS (PHASE 5)
// ----------------------------------------------------------------------------
// Move trains; resolve collisions and apply effects.
// ----------------------------------------------------------------------------
void moveAllTrains() {
}

// ----------------------------------------------------------------------------
// DETECT COLLISIONS WITH PRIORITY SYSTEM
// ----------------------------------------------------------------------------
// Resolve same-tile, swap, and crossing conflicts.
// ----------------------------------------------------------------------------
void detectCollisions() {
}

// ----------------------------------------------------------------------------
// CHECK ARRIVALS
// ----------------------------------------------------------------------------
// Mark trains that reached destinations.
// ----------------------------------------------------------------------------
void checkArrivals() {
    for(int i=0;i<numacttrain;i++){
        if(!trainisact[i]){
            continue;
        }

        int r=actrow[i];
        int c=actcol[i];
        if(isDestinationPoint(r,c)){
            trainisact[i]=0;
            countarrived++;

        }

    }
    while(numacttrain>0&& !trainisact[numacttrain-1]){//Reduces number of active train count when if the last index is inactive
        numacttrain--;
    }
}

// ----------------------------------------------------------------------------
// APPLY EMERGENCY HALT
// ----------------------------------------------------------------------------
// Apply halt to trains in the active zone.
// ----------------------------------------------------------------------------
void applyEmergencyHalt() {
}

// ----------------------------------------------------------------------------
// UPDATE EMERGENCY HALT
// ----------------------------------------------------------------------------
// Decrement timer and disable when done.
// ----------------------------------------------------------------------------
void updateEmergencyHalt() {
}
