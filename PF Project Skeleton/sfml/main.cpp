#include "app.h"
#include "../core/simulation_state.h"
#include "../core/simulation.h"
#include "../core/grid.h"
#include "../core/io.h"
#include <iostream>

using namespace std;
// ============================================================================
// MAIN.CPP - Entry point of the application (NO CLASSES)
// ============================================================================

// ----------------------------------------------------------------------------
// MAIN ENTRY POINT
// ----------------------------------------------------------------------------
// This function is the main entry point of the application. It handles command
// line arguments to specify the level file to load, loads the level file using
// loadLevelFile, initializes the simulation system, initializes the SFML
// application window, prints control instructions to the console, runs the
// main application loop, cleans up resources, and prints final simulation
// statistics. Returns 0 on success, 1 on error (e.g., failed to load level
// file or initialize application).
// ----------------------------------------------------------------------------
int main() {
    initializeSimulationState();//Reset all values

    gridrows=3;
    gridcol=5;

    const char* r[]={"S---D","--A-=","-----"};

    for (int i=0; i<gridrows;i++){
        for(int j=0; j<gridcol; j++){
            grid[i][j]=r[i][j];
        }
        
    }

    printingrid(); //to test print our grid

    cout<<"Testing false in bound: "<<isInBounds(5,0)<<endl;
    cout<<"Testing True in bound: "<<isInBounds(1,3)<<endl;

    cout<<"Testing false Track tile: "<<isTrackTile('{')<<endl;
    cout<<"Testing True Track Tile: "<<isTrackTile('-')<<endl;
    

    
}
