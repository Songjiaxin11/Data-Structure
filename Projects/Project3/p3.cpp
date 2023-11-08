#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include "simulation.h"
using namespace std;

bool initWorld(world_t &world, const string &speciesFile,
               const string &creaturesFile)
{
    // types to be used
    string line;
    int i = 0;
    int j = 0;
    int k = 0;
    int row = 0;
    int col = 0;
    int height = 0;
    int width = 0;
    string Species_Name[MAXSPECIES];
    string Species_Instruction[MAXPROGRAM];
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

        cout << Species_Name[i] << endl;
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
            cout << Species_Instruction[j] << endl;
            j++; // world.species[i].program[j]
        }
        j = 0;
        k = 0; // world.species[i].program[j].op
        cout << endl;
        i++; // 下一个species
    }
    // 读creature
    // 读grid
    ifstream inputFile2(creaturesFile);
    if (!inputFile2)
    {
        cout << "Error: Cannot open file " << creaturesFile << "!" << endl;
        return false;
    }
    getline(inputFile2, line);
    stringstream s2(line);
    s2 >> height;
    world.grid.height = height;
    
    getline(inputFile2, line);
    s2.clear();
    s2.str(line);
    s2>>width;
    world.grid.width = width;
    // cout<<world.numSpecies<<endl;
    return true;
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
    cout << "!!!!!!" << endl;
    // inputFile.close();

    return 0;
}