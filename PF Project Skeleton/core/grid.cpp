#include "grid.h"
#include "simulation_state.h"

// ============================================================================
// GRID.CPP - Grid utilities
// ============================================================================

// ----------------------------------------------------------------------------
// Check if a position is inside the grid.
// ----------------------------------------------------------------------------
// Returns true if x,y are within bounds.
// ----------------------------------------------------------------------------
bool isInBounds(int row, int col) {//To check if position is within the max rows and max col.
    bool check=0;

    if(row>=0 && row<mrow && col>=0 && col<mcol){
        check=1;
    }

    return check;

}

// ----------------------------------------------------------------------------
// Check if a tile is a track tile.
// ----------------------------------------------------------------------------
// Returns true if the tile can be traversed by trains.
// ----------------------------------------------------------------------------
bool isTrackTile(char tile) {
    bool check=0;

    if(tile==' '|| tile=='\n'){
        check=1;
    }
    if(tile=='-'|| tile=='/' || tile=='\\' || tile=='+'|| tile=='='){//Checks all types of tracks elements
        check=1;
    }
    if(tile=='D'||tile=='S'|| (tile>='A'&& tile<='Z')){//Checks spawn, dest and all switches
        check=1;
    }


    return check;
}

// ----------------------------------------------------------------------------
// Check if a tile is a switch.
// ----------------------------------------------------------------------------
// Returns true if the tile is 'A'..'Z'.
// ----------------------------------------------------------------------------
bool isSwitchTile(char tile) {
    bool check=0;

    if(tile>='A'&& tile<='Z'){
        check=1;
    }

    return check;
}

// ----------------------------------------------------------------------------
// Get switch index from character.
// ----------------------------------------------------------------------------
// Maps 'A'..'Z' to 0..25, else -1.
// ----------------------------------------------------------------------------
int getSwitchIndex(char tile) {
    if(!(isSwitchTile(tile))){
        return -1;
    }
    int index;
    index= tile-65;

    return index;
}

// ----------------------------------------------------------------------------
// Check if a position is a spawn point.
// ----------------------------------------------------------------------------
// Returns true if x,y is a spawn.
// ----------------------------------------------------------------------------
bool isSpawnPoint() {
}

// ----------------------------------------------------------------------------
// Check if a position is a destination.
// ----------------------------------------------------------------------------
// Returns true if x,y is a destination.
// ----------------------------------------------------------------------------
bool isDestinationPoint() {
}

// ----------------------------------------------------------------------------
// Toggle a safety tile.
// ----------------------------------------------------------------------------
// Returns true if toggled successfully.
// ----------------------------------------------------------------------------
bool toggleSafetyTile() {
}
