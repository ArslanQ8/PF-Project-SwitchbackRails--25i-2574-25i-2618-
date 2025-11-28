#include "simulation.h"
#include "simulation_state.h"
#include "trains.h"
#include "switches.h"
#include "io.h"
#include "grid.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

// ============================================================================
// SIMULATION.CPP - Implementation of main simulation logic
// ============================================================================

// ----------------------------------------------------------------------------
// INITIALIZE SIMULATION
// ----------------------------------------------------------------------------

void initializeSimulation() {
}

// ----------------------------------------------------------------------------
// SIMULATE ONE TICK
// ----------------------------------------------------------------------------

void simulateOneTick() {

    spawnTrainsForTick();

    for(int i=0; i<numacttrain;i++){
        if(!trainisact[i]){
            continue;
        }

        int r= actrow[i];
        int c=actcol[i];

        if(actdir[i]==dir_up){
            r-=1;
        }
        else if(actdir[i]==dir_down){
            r+=1;
        }
        else if(actdir[i]==dir_left){
            c-=1;
        }
        else if(actdir[i]==dir_right){
            c+=1;
        }

        if(!isInBounds(r,c)){//Checks if new value is within the grid
            trainisact[i]=0;
            continue;
        }

        char tile= grid[r][c];

        if(isDestinationPoint(r,c)){
            trainisact[i]=false;
            continue;
        }

        if(isTrackTile(tile)){
            actrow[i]=r;
            actcol[i]=c;
        }
        else{
            trainisact[i]=0;
        }

    }

    currenttick+=1;
}

// ----------------------------------------------------------------------------
// CHECK IF SIMULATION IS COMPLETE
// ----------------------------------------------------------------------------

bool isSimulationComplete() {
}
