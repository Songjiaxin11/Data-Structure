#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include "simulation.h"
using namespace std;
// point_t adjacentPoint(point_t pt, direction_t dir);
// bool is_Empty(world_t &world, point_t pt, direction_t dir);
// bool inside_bound(world_t &world, point_t pt, direction_t dir);

// void simulation(world_t &world, int round, bool difficulty);
// void hop(world_t &world, point_t pt, direction_t dir);









// 和上一个只有一个等号不一样





// creature_t *getCreature(const world_t &world, point_t &location)
// // // REQUIRES: location is inside the grid.
// // //
// // // EFFECTS: Returns a pointer to the creature at "location" in "grid".
// {
//     if (world.grid.squares[location.r][location.c] == NULL)
//     {
//         return NULL;
//     }
//     else
//     {
//         // cout << "name" << world.grid.squares[location.r][location.c]->species->name << endl;
//         // cout << world.grid.squares[location.r][location.c]->location.r << endl;
//         return world.grid.squares[location.r][location.c];
//     }
// }



// instruction_t getInstruction(const creature_t &creature)
// {
//     return creature.species->program[creature.programID];
// }

int main(int argc, char *argv[])
{
    bool difficulty = false;
    if (argc > 4)
    {
        string difficulty_test = argv[4];

        if (difficulty_test == "v" | difficulty_test == "verbose")
            difficulty = true;
        else
            difficulty = false;
    }
    // cout << "difficulty: " << difficulty << endl;
    int i = 0;
    string line;
    ifstream iFile;
    stringstream iString;
    world_t world;
    species_t species;
    instruction_t instruction;
    grid_t grid;
    point_t point;
    creature_t creatures[MAXCREATURES];
    creature_t creature;
    int round = atoi(argv[3]);
    // error checking started
    // error 1
    if (argc < 3)
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
    // }

    bool readFile = initWorld(world, argv[1],
                              argv[2]);

    cout << "Initial state" << endl;
    print_Grid(world);

    simulation(world, round, difficulty);

    return 0;
}





