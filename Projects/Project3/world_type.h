#ifndef WORLD_TYPE_H
#define WORLD_TYPE_H

#include <string>

const unsigned int MAXSPECIES = 10;   // Max number of species in the
                                      // world
const unsigned int MAXPROGRAM = 40;   // Max size of a species program
const unsigned int MAXCREATURES = 50; // Max number of creatures in
                                      // the world
const unsigned int MAXHEIGHT = 20;    // Max height of the grid
const unsigned int MAXWIDTH = 20;     // Max width of the grid

struct point_t
{
    int r; // ok
    int c; // ok
};
/*
// Type: point_t
// ------------
// This type is used to represent a point in the grid.
// Its component r corresponds to the row number; its component
// c corresponds to the column number.
*/

enum direction_t
{
    EAST,
    SOUTH,
    WEST,
    NORTH
};
/*
// Type: direction_t
// ----------------
// This type is used to represent direction, which can take on
// one of the four values: East, South, West, and North.
*/

const std::string directName[] = {"east", "south", "west", "north"};
// An array of strings representing the direction name.

const std::string directShortName[] = {"e", "s", "w", "n"};
// An array of strings representing the direction short name.

enum opcode_t
{
    HOP,
    LEFT,
    RIGHT,
    INFECT,
    IFEMPTY,
    IFENEMY,
    IFSAME,
    IFWALL,
    GO
};
/*
// Type: opcode_t
// -------------
// The type opcode_t is an enumeration of all of the legal
// command names.
*/

const std::string opName[] = {"hop", "left", "right", "infect",
                              "ifempty", "ifenemy", "ifsame", "ifwall", "go"};
// An array of strings representing the command name.

struct instruction_t
{
    opcode_t op;          // ok
    unsigned int address; // ok
};
/*
// Type: instruction_t
// ------------------
// The type instruction_t is used to represent an instruction
// and consists of a pair of an operation code and an integer.
// For some operation code, the integer stores the address of
// the instruction it jumps to. The address is optional.
*/

struct species_t
{
    std::string name;                  // ok
    unsigned int programSize;          // ok
    instruction_t program[MAXPROGRAM]; // ok
};
/*
// Type: species_t
// ------------------
// The type species_t is used to represent a species
// and consists of a string, an unsigned int, and an array
// of instruction_t. The string gives the name of the
// species. The unsigned int gives the number of instructions
// in the program of the species. The array stores all the
// instructions in the program according to their sequence.
*/

struct creature_t
{
    point_t location;       // ok
    direction_t direction;  // ok
    species_t *species;     // ok
    unsigned int programID; /// I don't know
};
/*
// Type: creature_t
// ------------------
// The type creature_t is used to represent a creature.
// It consists of a point_t, a direction_t, a pointer to
// species_t and an unsigned int. The point_t gives the location of
// the species. The direction_t gives the direction of the species.
// The pointer to species_t points to the species the creature belongs
// to. The programID gives the index of the instruction to be
// executed in the instruction_t array of the species.
*/

struct grid_t
{
    unsigned int height;                      // ok
    unsigned int width;                       // ok
    creature_t *squares[MAXHEIGHT][MAXWIDTH]; // ok
};
/*
// Type: grid_t
// ------------------
// The type grid_t consists of the height and the width of the grid
// and a two-dimensional array of pointers to creature_t. If there is
// a creature at the point (r, c) in the grid, then squares[r][c]
// stores a pointer to that creature. If point (r, c) is not occupied
// by any creature, then squares[r][c] is a NULL pointer.
*/

struct world_t
{
    unsigned int numSpecies;       // ok
    species_t species[MAXSPECIES]; // ok

    unsigned int numCreatures; // ok
    creature_t creatures[MAXCREATURES];

    grid_t grid; // ok
};
/*
// Type: world_t
// --------------
// This type consists of two unsigned ints, an array of species_t,
// an array of creature_t, and a grid_t object. The first unsigned
// int numSpecies specifies the number of species in the creature
// world. The second unsigned int numCreatures specifies the number
// of creatures in the world. All the species are stored in the array
// species and all the creatures are stored in the array creatures.
// The grid is given in the object grid.
*/

#endif
