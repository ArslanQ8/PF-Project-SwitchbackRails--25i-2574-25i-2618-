#include "grid.h"
#include "simulation_state.h"
#include <iostream>

using namespace std;
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

    if(row>=0 && row<gridrows && col>=0 && col<gridcol){
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
        check=0;
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
bool isSpawnPoint(int row, int col) {
    if(!isInBounds(row,col)){
        return 0;
    }
    
    int check=0;
    if(grid[row][col]=='S'){
        check=1;
    }
    return check;
}

// ----------------------------------------------------------------------------
// Check if a position is a destination.
// ----------------------------------------------------------------------------
// Returns true if x,y is a destination.
// ----------------------------------------------------------------------------
bool isDestinationPoint(int row, int col) {
    if(!isInBounds(row,col)){
        return 0;
    }
    
    int check=0;
    if(grid[row][col]=='D'){
        check=1;
    }
    return check;
}

// ----------------------------------------------------------------------------
// Toggle a safety tile.
// ----------------------------------------------------------------------------
// Returns true if toggled successfully.
// ----------------------------------------------------------------------------
bool toggleSafetyTile(int row,int col) {
    if(!isInBounds(row,col)){
        return 0;
    }

    char *tile=&grid[row][col];

    if(*tile=='='){//If already safety we change it to normal
        *tile='-';
        return 1;
    }

    if(isTrackTile(*tile)){
        *tile='=';
        return 1;
    }
    return 0;

}

//testing code

void printingrid(){
    cout<<"Grid "<<gridrows<<" and "<<gridcol<<endl;

    for (int i=0; i<gridrows;i++){
        for(int j=0; j<gridcol; j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }

}
