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
point_t adjacentPoint(point_t pt, direction_t dir);
bool is_Empty(world_t &world, point_t pt, direction_t dir);
bool inside_bound(world_t &world, point_t pt, direction_t dir);
void print_Operation(opcode_t &op);
void simulation(world_t &world, int round, bool difficulty);
void hop(world_t &world, point_t pt, direction_t dir);
void left(world_t &world, point_t pt);
void right(world_t &world, point_t pt);
void infect(world_t &world, point_t pt, direction_t dir);
bool Enemy_Warning(world_t &world, point_t pt, direction_t dir);
bool Friend_In_Front(world_t &world, point_t pt, direction_t dir);
void go_To_Step(world_t &world, point_t pt, int n);
void Empty_With_Step(world_t &world, point_t pt, direction_t dir, int n);
void Enemy_Warning_Steps(world_t &world, point_t pt, direction_t dir, int n);
void Wall_With_Step(world_t &world, point_t pt, direction_t dir, int n);
void Same_With_Step(world_t &world, point_t pt, direction_t dir, int n);
void printInt2Enum(int output, bool flag = true);
void print_Grid(world_t &world);
#endif