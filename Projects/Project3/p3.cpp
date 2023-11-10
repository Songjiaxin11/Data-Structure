#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include "simulation.h"
using namespace std;

int main(int argc, char *argv[])
{
    bool difficulty = false;
    if (argc > 4)
    {
        string difficulty_test = argv[4];

        if ((difficulty_test == "v") || (difficulty_test == "verbose"))
            difficulty = true;
        else
            difficulty = false;
    }
    // cout << "difficulty: " << difficulty << endl;
    string line;
    ifstream iFile;
    stringstream iString;
    world_t world;
    species_t species;

    int round = atoi(argv[3]);
    // error checking started
    // error 1
    if (argc < 4)
    {
        cout << "Error: Missing arguments!" << endl;
        cout << "./p3 <species-summary> <world-file> <rounds> [v|verbose]" << endl;
        return 0;
    }
    // error 2
    if (atoi(argv[3]) < 0)
    {
        cout << "Error: Number of simulation rounds is negative!" << endl;
        return 0;
    }
    // error 3
    iFile.open(argv[1]);
    if (!iFile)
    {
        cout << "Error: Cannot open file " << argv[1] << endl;
        return 0;
    }
    // iFile.open(argv[2]);
    // if (!iFile)
    // {
    //     cout << "Error: Cannot open file " << argv[2] << endl;
    //     return 0;
    // }/

    bool status = initWorld(world, argv[1],
                            argv[2]);
    if (!status)
    {
        return 0;
    }

    cout << "Initial state" << endl;
    print_Grid(world);

    simulation(world, round, difficulty);

    return 0;
}
