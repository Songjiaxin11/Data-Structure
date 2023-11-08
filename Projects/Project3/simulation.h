#include "world_type.h"
#ifndef STIMULATION_H
#define STIMULATION_H
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
using namespace std;
bool initWorld(world_t &world, const string &speciesFile, const string &creaturesFile);
void simulateCreature(creature_t &creature, grid_t &grid, bool verbose);
void printGrid(const grid_t &grid);
point_t adjacentPoint(point_t pt, direction_t dir);
direction_t leftFrom(direction_t dir);
direction_t rightFrom(direction_t dir);
instruction_t getInstruction(const creature_t &creature);
creature_t *getCreature(const grid_t &grid, point_t location);
#endif