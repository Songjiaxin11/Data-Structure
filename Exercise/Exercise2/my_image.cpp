#include <iostream>
#include "my_image.h"
using namespace std;

void initImage(Image &image, size_t width, size_t height) // image传入image struct, width和height是size_t类型的
{
    image._width = width;
    image._height = height;
    for(size_t i=0;i<image._width;i++)
    {
        for(size_t j=0;j<image._height;j++)
        {
            image._pixels[i][j]._red = 0;
            image._pixels[i][j]._green = 0;
            image._pixels[i][j]._blue = 0;
        }
    }
}


