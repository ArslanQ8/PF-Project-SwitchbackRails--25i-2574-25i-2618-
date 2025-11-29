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
        if(justspawned[i]){
            justspawned[i]=0;
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
            countcrashed++;
            continue;
        }

        char tile= grid[r][c];

        if(isTrackTile(tile)){
            actrow[i]=r;
            actcol[i]=c;
        }
        else{
            trainisact[i]=0;
            countcrashed++;
        }

    }
    checkArrivals();

    currenttick+=1;
}

// ----------------------------------------------------------------------------
// CHECK IF SIMULATION IS COMPLETE
// ----------------------------------------------------------------------------

bool isSimulationComplete() {

    bool checkcomplete=1;

    if(currenttick<=lasttick){
        checkcomplete= 0;
    }

    for(int i=0; i<numacttrain;i++){
        if(trainisact[i]){
            checkcomplete= 0;
        }
    }
    return checkcomplete;
}
