#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include "world_type.h"
using namespace std;

/**
 * @brief IMPORTANT
 *
 * @param pt
 * @param dir
 * @return point_t
 */
point_t adjacentPoint(point_t pt, direction_t dir)
{
    if (dir == EAST)
    {
        pt.c++;
    }
    else if (dir == WEST)
    {
        pt.c--;
    }
    else if (dir == NORTH)
    {
        pt.r--;
    }
    else if (dir == SOUTH)
    {
        pt.r++;
    }
    return pt;
}
/**
 * @brief 判断是否在边界内 如果是, 则返回true
 *
 * @param world
 * @param pt
 * @param dir
 * @return true
 * @return false
 */
bool inside_bound(world_t &world, point_t pt, direction_t dir)
{
    point_t check_point = adjacentPoint(pt, dir);
    if (check_point.r >= 0 && check_point.c >= 0 && check_point.r < static_cast<int>(world.grid.height) && check_point.c < static_cast<int>(world.grid.width))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief 检查前方是否会超出边界与前方是否有其他creature
 * 若在下一步在边界内或者没有其他creature, 返回true
 *
 * @param world
 * @param pt
 * @param dir
 * @return true
 * @return false
 */
/**
 *
 */
void print_Operation(opcode_t &op)
{
    if (op == HOP)
    {
        cout << "hop";
    }
    else if (op == LEFT)
    {
        cout << "left";
    }
    else if (op == RIGHT)
    {
        cout << "right";
    }
    else if (op == INFECT)
    {
        cout << "infect";
    }
    else if (op == IFEMPTY)
    {
        cout << "ifempty ";
    }
    else if (op == IFENEMY)
    {
        cout << "ifenemy ";
    }
    else if (op == IFSAME)
    {
        cout << "ifsame ";
    }
    else if (op == IFWALL)
    {
        cout << "ifwall ";
    }
    else if (op == GO)
    {
        cout << "go ";
    }
}

bool is_Empty(world_t &world, point_t pt, direction_t dir)
{
    point_t check_point = adjacentPoint(pt, dir); // 指向下一个位置
    if (inside_bound(world, pt, dir))
    {
        if (world.grid.squares[check_point.r][check_point.c] == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/**
 * @brief Enemy_Warning
 *
 * @param world
 * @param pt
 * @param dir
 * @return true
 * @return false
 */
bool Enemy_Warning(world_t &world, point_t pt, direction_t dir)
{
    point_t check_point = adjacentPoint(pt, dir);
    if (inside_bound(world, pt, dir) && is_Empty(world, pt, dir) == false)
    {
        // 前方有东西, 且下一步的creature和当前不同
        if (world.grid.squares[check_point.r][check_point.c]->species != world.grid.squares[pt.r][pt.c]->species)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/**
 * @brief Friend_In_Front
 *
 * @param world
 * @param pt
 * @param dir
 * @return true
 * @return false
 */
bool Friend_In_Front(world_t &world, point_t pt, direction_t dir)
{
    point_t check_point = adjacentPoint(pt, dir);
    if (inside_bound(world, pt, dir) && is_Empty(world, pt, dir) == false)
    {
        // 前方有东西, 且下一步的creature和当前相同
        if (world.grid.squares[check_point.r][check_point.c]->species == world.grid.squares[pt.r][pt.c]->species)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/**
 * @brief go_To_Step Empty_With_Step Enemy_Warning_Steps
 *
 * @param world
 * @param pt
 * @param n
 */
void go_To_Step(world_t &world, point_t pt, int n)
{
    world.grid.squares[pt.r][pt.c]->programID = n - 1;
}

void Empty_With_Step(world_t &world, point_t pt, direction_t dir, int n)
{
    if (inside_bound(world, pt, dir) && is_Empty(world, pt, dir))
    {
        world.grid.squares[pt.r][pt.c]->programID = n - 1;
    }
    else
    {
        world.grid.squares[pt.r][pt.c]->programID++;
    }
}

void Enemy_Warning_Steps(world_t &world, point_t pt, direction_t dir, int n)
{
    if (Enemy_Warning(world, pt, dir))
    {
        world.grid.squares[pt.r][pt.c]->programID = n - 1;
    }
    else
    {
        world.grid.squares[pt.r][pt.c]->programID++;
    }
}

/**
 * @brief Wall_With_Step
 *
 * @param world
 * @param pt
 * @param dir
 * @param n
 */
void Wall_With_Step(world_t &world, point_t pt, direction_t dir, int n)
{
    if (!inside_bound(world, pt, dir))
    {
        world.grid.squares[pt.r][pt.c]->programID = n - 1;
    }
    else
    {
        world.grid.squares[pt.r][pt.c]->programID++;
    }
}

/**
 * @brief Same_With_Step
 *
 * @param world
 * @param pt
 * @param dir
 * @param n
 */
void Same_With_Step(world_t &world, point_t pt, direction_t dir, int n)
{
    if (Friend_In_Front(world, pt, dir))
    {
        world.grid.squares[pt.r][pt.c]->programID = n - 1;
    }
    else
    {
        world.grid.squares[pt.r][pt.c]->programID++;
    }
}
/**
 * @brief printInt2Enum
 *
 * @param output
 * @param flag
 */
void printInt2Enum(int output, bool flag = true)
{
    if (flag)
    {
        if (output == 0)
        {
            cout << "e"
                 << " ";
        }
        if (output == 1)
        {
            cout << "s"
                 << " ";
        }
        if (output == 2)
        {
            cout << "w"
                 << " ";
        }
        if (output == 3)
        {
            cout << "n"
                 << " ";
        }
    }
    if (!flag)
    {
        if (output == 0)
        {
            cout << "east"
                 << " ";
        }
        if (output == 1)
        {
            cout << "south"
                 << " ";
        }
        if (output == 2)
        {
            cout << "west"
                 << " ";
        }
        if (output == 3)
        {
            cout << "north"
                 << " ";
        }
    }
}

/**
 * @brief print_Grid
 *
 * @param world
 */
void print_Grid(world_t &world)
{
    for (int r = 0; r < static_cast<int>(world.grid.height); r++)
    {
        for (int c = 0; c < static_cast<int>(world.grid.width); c++)
        {
            if (world.grid.squares[r][c] != NULL)
            {
                string output = world.grid.squares[r][c]->species->name;
                cout << output.substr(0, 2) << "_"; // 输出前两个字符
                int output2 = world.grid.squares[r][c]->direction;
                printInt2Enum(output2);
            }
            else
            {
                cout << "____"
                     << " ";
            }
        }
        cout << endl;
    }
}

/**
 * @brief initialize
 *
 * @param world
 * @param speciesFile
 * @param creaturesFile
 * @return true
 * @return false
 */
bool initWorld(world_t &world, const string &speciesFile, const string &creaturesFile)
{
    // types to be used
    // 在initWorld函数内部

    string line;
    int i = 0;
    int i1 = 0;
    int j = 0;
    int k = 0;
    int row = 0;
    int col = 0;
    int height = 0;
    int width = 0;
    string Species_Name[MAXSPECIES];
    string Species_Instruction[MAXPROGRAM];
    string Creature_Properties[MAXCREATURES];
    world.species[i].program[j].address = 0;

    // 读取species文件的第一行,存储到dir_Name中
    ifstream inputFile(speciesFile);
    if (!inputFile)
    {
        cout << "Error: Cannot open file " << speciesFile << "!" << endl;
        return false;
    }
    getline(inputFile, line);
    string dir_Name = line;
    // cout<<dir_Name<<endl;
    world.numSpecies = 0;
    world.numCreatures = 0;
    // 从species中继续读取, 将读取结果存储到Species_Name中
    while (getline(inputFile, line))
    {
        Species_Name[i] = line;
        world.numSpecies++;
        if (world.numSpecies > MAXSPECIES)
        {
            cout << "Error: Too many species!" << endl;
            cout << "Maximal number of species is " << MAXSPECIES << "." << endl;
            return false;
        } // error 4

        world.species[i].name = Species_Name[i];

        // cout << Species_Name[i] << endl;
        // 打开speciesName对应的同名文件
        ifstream inFileCreature(dir_Name + '/' + Species_Name[i]);
        if (!inFileCreature)
        {
            cout << "Error: Cannot open file " << dir_Name + '/' + Species_Name[i] << "!" << endl;
            return false;
        }
        // cout<<"read success"<<endl;

        // 读取名为dir_Name/species_Name[]文件的每一行, 存储到每个species中的instruction_t program中
        // string line;
        // 当读到空行时停止

        while (getline(inFileCreature, line))
        {
            if (line == "")
            {
                break;
            }
            Species_Instruction[j] = line;
            world.species[i].programSize++;
            if (world.species[i].programSize > MAXPROGRAM)
            {
                cout << "Error: Too many instructions for species " << world.species[i].name << "!" << endl;
                cout << "Maximal number of instructions is " << MAXPROGRAM << "." << endl;
                return false;
            } // error check 5

            // species.program[j-1] = Species_Instruction[j-1];//然后还要拆分出来
            // 把Species_Instruction[j]中的前半部分存到world.species.program.op中, 后面的integer存到world.species.program.address中
            stringstream ss(line); // 将读取的字符串转换为 stringstream
            string str_part;
            int int_part;
            ss >> str_part >> int_part; // 从 stringstream 中分离字符串和整数
            world.species[i].program[j].address = int_part;
            // 将str_part和enum进行比较,
            //  将str_part和enum进行比较

            if (str_part == "hop")
            {
                world.species[i].program[k].op = HOP;
            }
            else if (str_part == "left")
            {
                world.species[i].program[k].op = LEFT;
            }
            else if (str_part == "right")
            {
                world.species[i].program[k].op = RIGHT;
            }
            else if (str_part == "infect")
            {
                world.species[i].program[k].op = INFECT;
            }
            else if (str_part == "ifempty")
            {
                world.species[i].program[k].op = IFEMPTY;
            }
            else if (str_part == "ifenemy")
            {
                world.species[i].program[k].op = IFENEMY;
            }
            else if (str_part == "ifsame")
            {
                world.species[i].program[k].op = IFSAME;
            }
            else if (str_part == "ifwall")
            {
                world.species[i].program[k].op = IFWALL;
            }
            else if (str_part == "go")
            {
                world.species[i].program[k].op = GO;
            }
            else
            {
                cout << "Error: Instruction " << str_part << " is not recognized!" << endl;
                return false;
            }
            k++; //
            // cout << Species_Instruction[j] << endl;
            j++; // world.species[i].program[j]
        }
        j = 0;
        k = 0; // world.species[i].program[j].op
        // cout << endl;
        i++; // 下一个species
    }
    // 读creature
    // 读grid
    ifstream inFileSmallCreature(creaturesFile);
    if (!inFileSmallCreature)
    {
        cout << "Error: Cannot open file " << creaturesFile << "!" << endl;
        return false;
    }
    getline(inFileSmallCreature, line);
    stringstream s2(line); // s2读取每个worldfile的height和width
    s2 >> height;
    if (height > static_cast<int>(MAXHEIGHT))
    {
        cout << "Error: The grid height is illegal!" << endl;
        return false;
    } // error check
    world.grid.height = height;
    getline(inFileSmallCreature, line);
    s2.clear();
    s2.str(line);
    s2 >> width;
    if (height > static_cast<int>(MAXWIDTH))
    {
        cout << "Error: The grid width is illegal!" << endl;
        return false;
    } // error check
    world.grid.width = width;

    // 读species_t *species
    // 逐行读取至当前string[i]
    // 第一个空格之前是*species, 第二个空格之前是方向, 第三个空格之前是坐标
    while (getline(inFileSmallCreature, line))
    {
        if (line == "")
        {
            break;
        }
        Creature_Properties[i1] = line; // i1要记得++和归零
        world.numCreatures++;
        if (static_cast<int>(world.numCreatures) > static_cast<int>(MAXCREATURES))
        {
            cout << "Error: Too many creatures!" << endl;
            cout << "Maximal number of creatures is" << MAXCREATURES << "." << endl;
            return false;
        }                      // error check 7
        stringstream s3(line); // s3读取每个creature的一整行property
        string species_part;
        string direction_part;
        s3 >> species_part >> direction_part >> row >> col;
        world.creatures[i1].location.r = row;
        world.creatures[i1].location.c = col;
        // 存到world.creatures[i1].location的r和c

        // 存到world.creatures[i1].direction
        if (direction_part == "east")
        {
            world.creatures[i1].direction = EAST;
        }
        else if (direction_part == "south")
        {
            world.creatures[i1].direction = SOUTH;
        }
        else if (direction_part == "west")
        {
            world.creatures[i1].direction = WEST;
        }
        else if (direction_part == "north")
        {
            world.creatures[i1].direction = NORTH;
        }
        else
        {
            cout << "Error: Direction " << direction_part << "is not recognized!" << endl;
            return false;
        } // error check

        // 读取creature对应的*species
        bool is_find = false;
        if (!is_find)
        {
            for (int j1 = 0; j1 < static_cast<int>(world.numSpecies); j1++)
            {
                if (species_part == world.species[j1].name)
                {
                    is_find = true;
                    world.creatures[i1].species = &world.species[j1];
                    // cout << "-------------------------------NAME: " << world.creatures[i1].species->name << "-----------------------" << endl;
                    break;
                }
            }
            if (!is_find)
            {
                cout << "Error: Species " << species_part << " not found!" << endl;
                return false;
            }
            is_find = false;
        }

        // 把所有grid中的*squares[][]设置为NULL
        for (unsigned int r = 0; r < MAXHEIGHT; r++) // 要加等号height=3, 0123全部存东西
        {
            for (unsigned int c = 0; c < MAXWIDTH; c++)
            {
                world.grid.squares[r][c] = NULL;
            }
        }
        // 读取grid_t中的creature_t *squares[MAXHEIGHT][MAXWIDTH];
        for (int j2 = 0; j2 < static_cast<int>(world.numCreatures); j2++)
        {
            int r = world.creatures[j2].location.r;
            int c = world.creatures[j2].location.c;
            if (world.grid.squares[r][c] != NULL)
            {
                cout << "Error: Creature (" << world.creatures[j2].species->name << " ";
                printInt2Enum(world.creatures[j2].direction, false);
                cout << r << " " << c << ") overlaps with creature (";
                cout << world.grid.squares[r][c]->species->name << " ";
                printInt2Enum(world.grid.squares[r][c]->direction, false);
                cout << r << " " << c << ")!" << endl;
                // cout << "Error: Square at (" << r << ", " << c << ") already has a creature." << endl;
                return false; // Exit the program with an error code
            }
            world.grid.squares[r][c] = &world.creatures[j2];
        }
        world.creatures[i1].programID = 0;

        if ((row > (static_cast<int>(world.grid.height) - 1)) || (col > (static_cast<int>(world.grid.width) - 1)) || (row < 0) || (col < 0))
        {
            cout << "Error: Creature (" << world.creatures[i1].species->name << " ";
            printInt2Enum(world.creatures[i1].direction, false);
            cout << world.creatures[i1].location.r << " " << world.creatures[i1].location.c << ") is out of bound!" << endl;
            // cout << "Error: Creature (" << world.grid.squares[row][col]->species->name << ") is out of bound!" << endl;

            cout << "The grid size is " << world.grid.height << "-by-" << world.grid.width << "." << endl;
            return false;
        } // error check

        i1++; // 下一个creature
    }

    i1 = 0;
    return true;
}

/**
 * @brief
 *
 * @param world
 * @param pt
 * @param dir
 */
void hop(world_t &world, point_t pt, direction_t dir)
{
    world.grid.squares[pt.r][pt.c]->programID++;
    if (inside_bound(world, pt, dir) && is_Empty(world, pt, dir))
    {
        point_t next_Point = adjacentPoint(pt, dir);
        world.grid.squares[next_Point.r][next_Point.c] = world.grid.squares[pt.r][pt.c];
        world.grid.squares[pt.r][pt.c]->location.r = next_Point.r;
        world.grid.squares[pt.r][pt.c]->location.c = next_Point.c;
        world.grid.squares[pt.r][pt.c] = NULL;
    }
}
/**
 * @brief LEFT
 *
 * @param world
 * @param pt
 */
void left(world_t &world, point_t pt)
{
    // direction_t temp_direction = world.grid.squares[pt.r][pt.c]->direction;
    world.grid.squares[pt.r][pt.c]->programID++;
    if (world.grid.squares[pt.r][pt.c]->direction == EAST)
    {
        world.grid.squares[pt.r][pt.c]->direction = NORTH;
    }
    else if (world.grid.squares[pt.r][pt.c]->direction == WEST)
    {
        world.grid.squares[pt.r][pt.c]->direction = SOUTH;
    }
    else if (world.grid.squares[pt.r][pt.c]->direction == NORTH)
    {
        world.grid.squares[pt.r][pt.c]->direction = WEST;
    }
    else if (world.grid.squares[pt.r][pt.c]->direction == SOUTH)
    {
        world.grid.squares[pt.r][pt.c]->direction = EAST;
    }
}
/**
 * @brief RIGHT
 *
 * @param world
 * @param pt
 */
void right(world_t &world, point_t pt)
{
    // direction_t temp_direction = world.grid.squares[pt.r][pt.c]->direction;
    world.grid.squares[pt.r][pt.c]->programID++;
    if (world.grid.squares[pt.r][pt.c]->direction == EAST)
    {
        world.grid.squares[pt.r][pt.c]->direction = SOUTH;
    }
    else if (world.grid.squares[pt.r][pt.c]->direction == WEST)
    {
        world.grid.squares[pt.r][pt.c]->direction = NORTH;
    }
    else if (world.grid.squares[pt.r][pt.c]->direction == NORTH)
    {
        world.grid.squares[pt.r][pt.c]->direction = EAST;
    }
    else if (world.grid.squares[pt.r][pt.c]->direction == SOUTH)
    {
        world.grid.squares[pt.r][pt.c]->direction = WEST;
    }
}

/**
 * @brief INFECT
 *
 * @param world
 * @param pt
 * @param dir
 */
void infect(world_t &world, point_t pt, direction_t dir)
{
    // world.grid.squares[pt.r][pt.c]->programID++;
    point_t next_point = adjacentPoint(pt, dir);
    if (Enemy_Warning(world, pt, dir))
    {
        world.grid.squares[next_point.r][next_point.c]->species = world.grid.squares[pt.r][pt.c]->species; // 指向的物种类别变成和现在的物种一样
        // ID_in_Infect = world.grid.squares[next_point.r][next_point.c]->programID;
        world.grid.squares[next_point.r][next_point.c]->programID = 0;
        world.grid.squares[pt.r][pt.c]->programID++;
        // world.grid.squares[next_point.r][next_point.c]->species->program[]
    }
    else
    {
        world.grid.squares[pt.r][pt.c]->programID++;
    }
}

/**
 * @brief SIMULATION
 *
 * @param world
 * @param round
 * @param difficulty
 */
void simulation(world_t &world, int round, bool difficulty)
{
    for (int rr = 1; rr <= round; rr++)
    { /////////////////////////////////round
        cout << "Round " << rr << endl;
        for (int number = 0; number < static_cast<int>(world.numCreatures); number++)
        { /////////////////////////////////creature
            // creature_t currrent_Creature = world.creatures[number];
            string current_Species = world.creatures[number].species->name;
            direction_t current_direction = world.creatures[number].direction;
            point_t current_point = world.creatures[number].location;

            cout << "Creature (" << current_Species << " ";
            printInt2Enum(current_direction, false);
            if (difficulty)
                cout << current_point.r << " " << current_point.c << ") takes action:" << endl;

            for (int counter = 0; counter < static_cast<int>(world.creatures[number].species->programSize); counter++)
            { ////////////////////instruction
                bool continueWithNextInstruction = true;
                int current_programID = world.creatures[number].programID;
                instruction_t current_instruction = world.creatures[number].species->program[current_programID];
                if (difficulty)
                {
                    cout << "Instruction " << current_programID + 1 << ": ";
                    print_Operation(current_instruction.op);
                }
                if (difficulty)
                {
                    if (current_instruction.op != HOP && current_instruction.op != LEFT && current_instruction.op != RIGHT && current_instruction.op != INFECT)
                    {
                        cout << current_instruction.address << endl;
                    }
                    else
                    {
                        cout << endl;
                    }
                }
                if (!difficulty)
                {
                    if (current_instruction.op == HOP || current_instruction.op == LEFT || current_instruction.op == RIGHT || current_instruction.op == INFECT)
                    {
                        cout << current_point.r << " " << current_point.c << ") takes action: ";
                        print_Operation(current_instruction.op);
                        cout << endl;
                    }
                }

                if (current_instruction.op == HOP)
                {
                    hop(world, current_point, current_direction);
                    continueWithNextInstruction = false;
                    if (difficulty)
                        print_Grid(world);
                }

                if (current_instruction.op == LEFT)
                {
                    left(world, current_point);
                    continueWithNextInstruction = false;
                    if (difficulty)
                        print_Grid(world);
                }
                if (current_instruction.op == RIGHT)
                {
                    right(world, current_point);
                    continueWithNextInstruction = false;
                    if (difficulty)
                        print_Grid(world);
                }

                if (current_instruction.op == INFECT)
                {
                    infect(world, current_point, current_direction); // 看看是所有都会改还是只有species会改
                    continueWithNextInstruction = false;
                    if (difficulty)
                        print_Grid(world);
                }

                if (current_instruction.op == GO)
                {
                    go_To_Step(world, current_point, current_instruction.address);
                }

                if (current_instruction.op == IFEMPTY)
                {
                    Empty_With_Step(world, current_point, current_direction, current_instruction.address);
                }

                if (current_instruction.op == IFSAME)
                {
                    Same_With_Step(world, current_point, current_direction, current_instruction.address);
                }
                if (current_instruction.op == IFWALL)
                {
                    Wall_With_Step(world, current_point, current_direction, current_instruction.address);
                }
                if (current_instruction.op == IFENEMY)
                {
                    Enemy_Warning_Steps(world, current_point, current_direction, current_instruction.address);
                }

                if (!continueWithNextInstruction)
                {
                    break; // Exit the instruction loop if no n
                }
            }
        }
        if (!difficulty)
        {
            print_Grid(world);
        }
    }
}
