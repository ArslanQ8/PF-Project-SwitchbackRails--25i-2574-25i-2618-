#ifndef SIMULATION_STATE_H
#define SIMULATION_STATE_H

// ============================================================================
// SIMULATION_STATE.H - Global constants and state
// ============================================================================
// Global constants and arrays used by the game.
// ============================================================================

// ----------------------------------------------------------------------------
// GRID CONSTANTS
// ----------------------------------------------------------------------------

const int mrow=40;//Assigns Max rows and collumn
const int mcol=70;

// ----------------------------------------------------------------------------
// TRAIN CONSTANTS
// ----------------------------------------------------------------------------

const int mtrains=32;

const int dir_up=0;
const int dir_right=1;
const int dir_down=2;
const int dir_left=3;


// ----------------------------------------------------------------------------
// SWITCH CONSTANTS
// ----------------------------------------------------------------------------

const int mswitches=26;

// ----------------------------------------------------------------------------
// WEATHER CONSTANTS
// ----------------------------------------------------------------------------

extern int weather;

// ----------------------------------------------------------------------------
// SIGNAL CONSTANTS
// ----------------------------------------------------------------------------




// ----------------------------------------------------------------------------
// GLOBAL STATE: GRID
// ----------------------------------------------------------------------------


extern int gridrows; //Defining rows and columns that will be used in other files not this one.
extern int gridcol;

extern char grid[mrow][mcol];


// ----------------------------------------------------------------------------
// GLOBAL STATE: TRAINS
// ----------------------------------------------------------------------------

extern int ntrain;
//for getting train values from level files.
extern int ttick[mtrains];
extern int trow[mtrains];
extern int tcol[mtrains];
extern int tdir[mtrains];
extern int tcolour[mtrains];

extern bool isspawned[mtrains];

//for trains that are in the grid and moving

extern int numacttrain;

extern int currenttick;
extern bool trainisact[mtrains];
extern int actrow[mtrains];
extern int actcol[mtrains];
extern int actdir[mtrains];
extern int actcolour[mtrains];

extern int lasttick;

// ----------------------------------------------------------------------------
// GLOBAL STATE: SWITCHES (A-Z mapped to 0-25)
// ----------------------------------------------------------------------------

extern int smode[mswitches];

extern int sk_up[mswitches];
extern int sk_right[mswitches];
extern int sk_left[mswitches];
extern int sk_down[mswitches];

extern int sk_Global[mswitches];
extern int countsk_Global[mswitches];

extern int countsk[mswitches];
extern int sstate[mswitches];

extern bool nextwillFlip[mswitches];

// ----------------------------------------------------------------------------
// GLOBAL STATE: SPAWN POINTS
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// GLOBAL STATE: DESTINATION POINTS
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// GLOBAL STATE: SIMULATION PARAMETERS
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// GLOBAL STATE: METRICS
// ----------------------------------------------------------------------------

extern int countarrived;
extern int countcrashed;

// ----------------------------------------------------------------------------
// GLOBAL STATE: EMERGENCY HALT
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// INITIALIZATION FUNCTION
// ----------------------------------------------------------------------------
// Resets all state before loading a new level.
void initializeSimulationState();

#endif
