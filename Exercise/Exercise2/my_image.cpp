#include <iostream>
#include "my_image.h"
using namespace std;

void initImage(Image &image, size_t width, size_t height) // image传入image struct, width和height是size_t类型的
{
    image._width = width;
    image._height = height;
    for (size_t i = 0; i < image._width; i++)
    {
        for (size_t j = 0; j < image._height; j++)
        {
            image._pixels[i][j]._red = 0;
            image._pixels[i][j]._green = 0;
            image._pixels[i][j]._blue = 0;
        }
    }
}

void setPixel(Image &image, Vec2 pos, Pixel pixel)
{
    if (pos._x < image._width && pos._y < image._height)
        image._pixels[pos._x][pos._y] = pixel;
    else
        cout << "Error: pixel out of range!" << endl;
}

int imageSize(Image &image)
{
    return image._width * image._height;
}

void printImage(Image &image, bool decOut)
{
    if (decOut == false)
    {
        for (size_t i = 0; i < image._width; i++)
        {
            for (size_t j = 0; j < image._width; j++)
            {
                cout << "(" << static_cast<int>(image._pixels[i][j]._red) << "," << static_cast<int>(image._pixels[i][j]._green) << "," << static_cast<int>(image._pixels[i][j]._blue) << ")";
            }
            cout << endl;
        }
    }
    if (decOut == true)
    {
        for (size_t i = 0; i < image._width; i++)
        {
            for (size_t j = 0; j < image._width; j++)
            {
                image._pixels[i][j]._red = static_cast<float>(image._pixels[i][j]._red) / 255.0f;
                image._pixels[i][j]._green = static_cast<float>(image._pixels[i][j]._green) / 255.0f;
                image._pixels[i][j]._blue = static_cast<float>(image._pixels[i][j]._blue) / 255.0f;
                cout << "(" << static_cast<int>(image._pixels[i][j]._red) << "," << static_cast<int>(image._pixels[i][j]._green) << "," << static_cast<int>(image._pixels[i][j]._blue) << ")";
            }
            cout << endl;
        }
    }
}
