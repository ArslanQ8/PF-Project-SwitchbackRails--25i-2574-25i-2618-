#include "io.h"
#include "simulation_state.h"
#include "grid.h"
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>//Good when working with strings and used for stoi to convert str to int

using namespace std;

// ============================================================================
// IO.CPP - Level I/O and logging
// ============================================================================

// ----------------------------------------------------------------------------
// LOAD LEVEL FILE
// ----------------------------------------------------------------------------
// Load a .lvl file into global state.
// ----------------------------------------------------------------------------
bool loadLevelFile() {

    ifstream in("data/levels/hard_level.lvl");//Reading the file
    
    if(!in){
        cout<<"File Failed to Open"<<endl;
        return 0;
    }

    initializeSimulationState();

    string line;

    while(getline(in,line)){

        bool check=1;
        for(int i=0; i<(int)line.size();i++){
            if(line[i]!=' '&&line[i]!='\t'&&line[i]!='\r'&&line[i]!='\n'){//checks if the current element is a word or letter
                check=0;
                break;
            }
        }
        if(check){ //if string is not word or letter
            continue;
        }
        if(line=="ROWS:"){
            getline(in,line);//To get items of the next line
            gridrows=stoi(line);
        }
        else if(line=="COLS:"){
            getline(in,line);//To get items of the next line
            gridcol=stoi(line);
        }
        else if(line=="MAP:"){
            break;
        }

    }
    bool check=0;

    if(gridrows>0&&gridrows<=mrow&&gridcol>0&&gridcol<=mcol){ //To check if the rows and col fall inside our limit
        check=1;
    }
    if(check){
        int tempi;
        while(getline(in,line)){
            if(line=="\0"){
                break;
            }
            for(int j=0; j<gridcol;j++){
                if(j<(int)line.size()){
                    grid[tempi][j]=line[j];
                }
            }
            tempi++;
        }

    }
    else{
        cout<<"Invalid Row/Column Size. Try again."<<endl;
    }
    in.close();
    return true;
    
}

// ----------------------------------------------------------------------------
// INITIALIZE LOG FILES
// ----------------------------------------------------------------------------
// Create/clear CSV logs with headers.
// ----------------------------------------------------------------------------
void initializeLogFiles() {
}

// ----------------------------------------------------------------------------
// LOG TRAIN TRACE
// ----------------------------------------------------------------------------
// Append tick, train id, position, direction, state to trace.csv.
// ----------------------------------------------------------------------------
void logTrainTrace() {
}

// ----------------------------------------------------------------------------
// LOG SWITCH STATE
// ----------------------------------------------------------------------------
// Append tick, switch id/mode/state to switches.csv.
// ----------------------------------------------------------------------------
void logSwitchState() {
}

// ----------------------------------------------------------------------------
// LOG SIGNAL STATE
// ----------------------------------------------------------------------------
// Append tick, switch id, signal color to signals.csv.
// ----------------------------------------------------------------------------
void logSignalState() {
}

// ----------------------------------------------------------------------------
// WRITE FINAL METRICS
// ----------------------------------------------------------------------------
// Write summary metrics to metrics.txt.
// ----------------------------------------------------------------------------
void writeMetrics() {
}
