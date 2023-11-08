#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include "world_type.h"
using namespace std;
bool initWorld(world_t &world, const string &speciesFile,
               const string &creaturesFile)
{
    //types to be used
    string line;


    // 读取species文件的第一行,存储到dir_Name中
    ifstream inputFile(speciesFile);
    if (!inputFile)
    {
        cout << "Error: Cannot open file " << speciesFile<<"!" << endl;
        return false;
    }
    getline(inputFile, line);
    string dir_Name = line;
    // cout<<dir_Name<<endl;

    // 从species中继续读取, 将读取结果存储到Species_Name中
    while (getline(inputFile, line))
    {
        string Species_Name[MAXSPECIES];
        int i = 0;
        Species_Name[i++] = line;
        world.numSpecies++;
        // cout<<Species_Name[i-1]<<endl;
        // 打开speciesName对应的同名文件
        ifstream inFileCreature(dir_Name + '/' + Species_Name[i - 1]);
        if (!inputFile)
        {
            cout << "Error: Cannot open file " << dir_Name + '/' + Species_Name[i - 1] << endl;
            return false;
        }
        // cout<<"read success"<<endl;

        // 读取名为dir_Name/species_Name[]文件的每一行, 存储到每个species中的instruction_t program中
        // string line;
        while (getline(inFileCreature, line))
        {
            string Species_Instruction[MAXPROGRAM];
            int j = 0;
            Species_Instruction[j++] = line;
            world.species[i - 1].programSize++;
            cout << Species_Instruction[j - 1] << endl;
        }
    }
    // cout<<world.numSpecies<<endl;
    return true;
}
// MODIFIES: world
//
// EFFECTS: Initialize "world" given the species summary file
// "speciesFile" and the world description file
// "creaturesFile". This initializes all the components of
// "world". Returns true if initialization is successful.
void simulateCreature(creature_t &creature, grid_t &grid, bool verbose);
// REQUIRES: creature is inside the grid.
//
// MODIFIES: creature, grid, cout.
//
// EFFECTS: Simulate one turn of "creature" and update the creature,
// the infected creature, and the grid if necessary.
// The creature programID is always updated. The function
// also prints to the stdout the procedure. If verbose is
// true, it prints more information.
void printGrid(const grid_t &grid);
// MODIFIES: cout.
//
// EFFECTS: print a grid representation of the creature world.
point_t adjacentPoint(point_t pt, direction_t dir);
// EFFECTS: Returns a point that results from moving one square
// in the direction "dir" from the point "pt".
direction_t leftFrom(direction_t dir);
// EFFECTS: Returns the direction that results from turning
// left from the given direction "dir".
direction_t rightFrom(direction_t dir);
// EFFECTS: Returns the direction that results from turning
// right from the given direction "dir".
instruction_t getInstruction(const creature_t &creature);
// EFFECTS: Returns the current instruction of "creature".
creature_t *getCreature(const grid_t &grid, point_t location);
// REQUIRES: location is inside the grid.
//
// EFFECTS: Returns a pointer to the creature at "location" in "grid".