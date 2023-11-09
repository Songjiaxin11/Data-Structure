#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include "simulation.h"
using namespace std;
point_t adjacentPoint(point_t pt, direction_t dir);
bool is_Empty(world_t &world, point_t pt, direction_t dir);
bool inside_bound(world_t &world, point_t pt, direction_t dir);
void print_Operation(opcode_t &op)
{
    if (op == HOP)
    {
        cout << "hop ";
    }
    else if (op == LEFT)
    {
        cout << "left ";
    }
    else if (op == RIGHT)
    {
        cout << "right ";
    }
    else if (op == INFECT)
    {
        cout << "infect ";
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
void simulation(world_t &world, int round);
void hop(world_t &world, point_t pt, direction_t dir);

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
 * @brief 检查前方是否会超出边界与前方是否有其他creature
 * 若在下一步在边界内或者没有其他creature, 返回true
 *
 * @param world
 * @param pt
 * @param dir
 * @return true
 * @return false
 */
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
    if (check_point.r < world.grid.height && check_point.c < world.grid.width)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Enemy_Warning(world_t &world, point_t pt, direction_t dir)
{
    point_t check_point = adjacentPoint(pt, dir);
    if (is_Empty(world, pt, dir) == false)
    {
        // 前方有东西, 且下一步的creature和当前不同
        if (world.grid.squares[check_point.r][check_point.c] != world.grid.squares[pt.r][pt.c])
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

// 和上一个只有一个等号不一样
bool Friend_In_Front(world_t &world, point_t pt, direction_t dir)
{
    point_t check_point = adjacentPoint(pt, dir);
    if (is_Empty(world, pt, dir) == false)
    {
        // 前方有东西, 且下一步的creature和当前相同
        if (world.grid.squares[check_point.r][check_point.c] == world.grid.squares[pt.r][pt.c])
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
 * @brief 运行instruction的第n步
 *
 * @param creature
 * @param n
 */
void go_To_Step(world_t &world, int n)
{
    world.creatures->programID += n;
}

// instructiond 顺序移动至下一步
void programID_Plus_Plus(world_t &world)
{
    world.creatures->programID++;
}

/**
 * @brief
 * rr represent the current round
 * @param world
 * @param round
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

void print_Grid(world_t &world)
{
    for (int r = 0; r < world.grid.height; r++)
    {
        for (int c = 0; c < world.grid.width; c++)
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

creature_t *getCreature(const world_t &world, point_t &location)
// // REQUIRES: location is inside the grid.
// //
// // EFFECTS: Returns a pointer to the creature at "location" in "grid".
{
    if (world.grid.squares[location.r][location.c] == NULL)
    {
        return NULL;
    }
    else
    {
        // cout << "name" << world.grid.squares[location.r][location.c]->species->name << endl;
        // cout << world.grid.squares[location.r][location.c]->location.r << endl;
        return world.grid.squares[location.r][location.c];
    }
}

bool initWorld(world_t &world, const string &speciesFile,
               const string &creaturesFile)
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

    // 从species中继续读取, 将读取结果存储到Species_Name中
    while (getline(inputFile, line))
    {
        Species_Name[i] = line;
        world.numSpecies++;
        world.species[i].name = Species_Name[i];

        // cout << Species_Name[i] << endl;
        // 打开speciesName对应的同名文件
        ifstream inFileCreature(dir_Name + '/' + Species_Name[i]);
        if (!inputFile)
        {
            cout << "Error: Cannot open file " << dir_Name + '/' + Species_Name[i] << endl;
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
                exit(0);
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
    world.grid.height = height;
    getline(inFileSmallCreature, line);
    s2.clear();
    s2.str(line);
    s2 >> width;
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
        stringstream s3(line); // s3读取每个creature的一整行property
        string species_part;
        string direction_part;
        s3 >> species_part >> direction_part >> row >> col;
        // 存到world.creatures[i1].location的r和c
        world.creatures[i1].location.r = row;
        world.creatures[i1].location.c = col;
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
            exit(0);
        }
        // 读取creature对应的*species
        for (int j1 = 0; j1 < world.numSpecies; j1++)
        {
            if (species_part == world.species[j1].name)
            {
                world.creatures[i1].species = &world.species[j1];
                // cout << "-------------------------------NAME: " << world.creatures[i1].species->name << "-----------------------" << endl;
                break;
            }
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
        for (int j2 = 0; j2 < world.numCreatures; j2++)
        {
            int r = world.creatures[j2].location.r;
            int c = world.creatures[j2].location.c;
            world.grid.squares[r][c] = &world.creatures[j2];
            // cout << "-------You are here " << world.grid.squares[r][c]->species->name << "------" << endl;
        }

        // 初始化programID应该是错的
        world.creatures[i1].programID = 0;

        i1++; // 下一个creature
    }
    i1 = 0;
    return true;
}

instruction_t getInstruction(const creature_t &creature)
{
    return creature.species->program[creature.programID];
}

int main(int argc, char *argv[])
{
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

    // cout << "!!!!!!" << endl;
    // inputFile.close();
    /*
    // test for instruction
    for (int i = 0; i < world.numCreatures; i++)
    {
        creature = world.creatures[i];
        cout << creature.species->name << " : ";
        instruction = getInstruction(creature);
        cout << instruction.op << " " << instruction.address << endl;
        cout<<"ProgramID: "<<creature.programID<<endl;
    }
    */
    /* test for getCreature
    // 提取每个grid中的creature
    for (int i = 0; i < world.numCreatures; i++)
    {
        for (int r = 0; r < world.grid.height; r++)
        {
            for (int c = 0; c < world.grid.width; c++)
            {
                creature_t *creature = getCreature(world, world.creatures[i].location);
                if (creature != NULL)
                {
                    cout << "name: " << creature->species->name << "  ";
                    cout << "location: "
                         << "[" << creature->location.r << "," << creature->location.c << "]" << endl;
                }
                else
                {
                    cout << "There's no creature on this grid" << endl;
                }
            }
        }
    }
    */
    cout << "Original World" << endl;
    print_Grid(world);

    simulation(world, 1);

    return 0;
}
void hop(world_t &world, point_t pt, direction_t dir)
{
    world.grid.squares[pt.r][pt.c]->programID++;
    if (inside_bound(world, pt, dir) && is_Empty(world, pt, dir))
    {
        point_t next_Point = adjacentPoint(pt, dir);
        world.grid.squares[next_Point.r][next_Point.c] = world.grid.squares[pt.r][pt.c];
        world.grid.squares[pt.r][pt.c] = NULL;
    }
}

void simulation(world_t &world, int round)
{
    for (int rr = 1; rr <= round; rr++)
    { /////////////////////////////////round
        cout << "Round " << rr << endl;
        for (int number = 0; number < world.numCreatures; number++)
        { /////////////////////////////////creature
            creature_t currrent_Creature = world.creatures[number];
            string current_Species = world.creatures[number].species->name;
            direction_t current_direction = world.creatures[number].direction;
            point_t current_point = world.creatures[number].location;

            cout << "Creature (" << current_Species << " ";
            printInt2Enum(current_direction, false);
            cout << current_point.r << " " << current_point.c << ") takes action:" << endl;

            for (int counter = 0; counter < world.creatures[number].species->programSize; counter++)
            { ////////////////////instruction
                bool continueWithNextInstruction = true;
                int current_programID = world.creatures[number].programID;
                instruction_t current_instruction = world.creatures[number].species->program[current_programID];

                // Instruction 1: hop
                cout << "Instruction " << counter + 1 << ": ";
                print_Operation(current_instruction.op);
                cout << current_instruction.address << " " << endl;

                if (current_instruction.op == HOP)
                {
                    hop(world, current_point, current_direction);
                   continueWithNextInstruction = false;
                }
                cout << "world after " << counter + 1 << " step" << endl;
                print_Grid(world);
                if (!continueWithNextInstruction)
                {
                    break; // Exit the instruction loop if no n
                }
            }
        }
    }
}
