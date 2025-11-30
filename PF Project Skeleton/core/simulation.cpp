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
        char ctile=grid[actrow[i]][actcol[i]];

        if(isSwitchTile(ctile)){
            int index =getSwitchIndex(ctile);
            if(index>=0&&index<mswitches){
                if(smode[index]==0){//For per Dir mode
                    if(actdir[i]==dir_up){
                        countsk[index]++;
                        if(sk_up[index]>0 &&(countsk[index]>=sk_up[index])){
                            nextwillFlip[index]=1;
                            countsk[index]=0;
                        }
                    }
                    else if(actdir[i]==dir_right){
                        countsk[index]++;
                        if(sk_right[index]>0 &&(countsk[index]>=sk_right[index])){
                            nextwillFlip[index]=1;
                            countsk[index]=0;
                        }
                    }
                    else if(actdir[i]==dir_down){
                        countsk[index]++;
                        if(sk_down[index]>0 &&(countsk[index]>=sk_down[index])){
                            nextwillFlip[index]=1;
                            countsk[index]=0;
                        }
                    }
                    else if(actdir[i]==dir_left){
                        countsk[index]++;
                        if(sk_left[index]>0 &&(countsk[index]>=sk_left[index])){
                            nextwillFlip[index]=1;
                            countsk[index]=0;
                        }
                    }
                }
                else{//For Global
                    countsk_Global[index]++;
                    if(sk_Global[index]>0 &&(countsk_Global[index]>=sk_Global[index])){
                        nextwillFlip[index]=1;
                        countsk_Global[index]=0;
                    }
                }

                actdir[i]=getSwitchStateForDirection(index,actdir[i]);//Gets new direction, if state gets updated when count reaches the K value
            }
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

    applyDeferredFlips();
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
