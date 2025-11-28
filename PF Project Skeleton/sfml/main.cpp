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

    if(!loadLevelFile()){
        cout<<"Level Failed to load"<<endl;
        return 0;
    }

    Printgrid();
    
    for(int i=0;i<6;i++){
        cout<<"Current Tick is: "<<currenttick<<endl;

        simulateOneTick();
        cout<<"active Trains"<<endl;
        for(int j=0;j<numacttrain;j++){
            if(trainisact[j]){
                cout<<"Slot is "<<j<<" at "<<actrow[j]<<" and "<<actcol[j]<<" Direction is: "<<actdir[j]<<" And colour is: "<<actcolour[j]<<endl;
            }
        }

    }

    return 0;
    
}
