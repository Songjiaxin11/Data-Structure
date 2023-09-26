#include <iostream>
#include "my_image.h"
using namespace std;
int main()
{
    // 输出imageSize()中每个坐标的像素值
    Image image;
    initImage(image, 3, 3);
    for (size_t i = 0; i < image._width; i++)
    {
        for (size_t j = 0; j < image._height; j++)
        {//如何让它输出到width, 自动换行?
            cout<<"("<<static_cast<int>(image._pixels[i][j]._red)<<","<<static_cast<int>(image._pixels[i][j]._green)<<","<<static_cast<int>(image._pixels[i][j]._blue)<<")";
        }
        cout<<endl;
    }
    return 0;
}