#include "simulation_state.h"
#include <cstring>

// ============================================================================
// SIMULATION_STATE.CPP - Global state definitions
// ============================================================================

// ----------------------------------------------------------------------------
// GRID
// ----------------------------------------------------------------------------

int gridrows=0;//initializze the variables made in .h file
int gridcol=0;

char grid[mrow][mcol];

// ----------------------------------------------------------------------------
// TRAINS
// ----------------------------------------------------------------------------

int ntrain=0;

int ttick[mtrains];//Train variables
int trow[mtrains];
int tcol[mtrains];
int tdir[mtrains];
int tcolour[mtrains];

bool isspawned[mtrains];


int actrow[mtrains];//Active trains on grid variables
int currenttick=0;
int numacttrain=0;
bool trainisact[mtrains];
int actcol[mtrains];
int actdir[mtrains];
int actcolour[mtrains];

int lasttick=0;

int weather=0;

// ----------------------------------------------------------------------------
// SWITCHES
// ----------------------------------------------------------------------------

int smode[mswitches];

int sk_up[mswitches];
int sk_right[mswitches];
int sk_left[mswitches];
int sk_down[mswitches];

int countsk_up[mswitches];
int countsk_right[mswitches];
int countsk_left[mswitches];
int countsk_down[mswitches];

int sk_Global[mswitches];
int countsk_Global[mswitches];

int sstate[mswitches];

bool nextwillFlip[mswitches];
// ----------------------------------------------------------------------------
// SPAWN AND DESTINATION POINTS
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SIMULATION PARAMETERS
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// METRICS
// ----------------------------------------------------------------------------

int countarrived=0;
int countcrashed=0;

// ----------------------------------------------------------------------------
// EMERGENCY HALT
// ----------------------------------------------------------------------------

// ============================================================================
// INITIALIZE SIMULATION STATE
// ============================================================================
// ----------------------------------------------------------------------------
// Resets all global simulation state.
// ----------------------------------------------------------------------------
// Called before loading a new level.
// ----------------------------------------------------------------------------
void initializeSimulationState() {
    gridrows=0;
    gridcol=0;

    for(int i=0;i<mrow;i++){//for reseting grid
        for(int j=0;j<mcol;j++){
            grid[i][j]=' ';
        }
    }

    //for resetting train variables

    ntrain=0;
    for(int i=0; i<mtrains;i++){
        ttick[i]=0;
        trow[i]=0;
        tcol[i]=0;
        tdir[i]=0;
        tcolour[i]=0;
        actrow[i]=0;
        actcol[i]=0;
        actdir[i]=0;
        actcolour[i]=0;
        trainisact[i]=0;
        isspawned[i]=0;
    }
    weather=0;

    currenttick=0;
    lasttick=0;
    numacttrain=0;

    countarrived=0;
    countcrashed=0;

    for(int i=0;i<mswitches;i++){
        smode[i]=0;
        sstate[i]=0;
        sk_up[i]=0;
        sk_down[i]=0;
        sk_left[i]=0;
        sk_right[i]=0;
        countsk_up[i]=0;
        countsk_down[i]=0;
        countsk_left[i]=0;
        countsk_right[i]=0;

        sk_Global[i]=0;
        countsk_Global[i]=0;
        nextwillFlip[i]=0;
    }

}
