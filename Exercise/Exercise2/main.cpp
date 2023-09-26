#include <iostream>
#include "my_image.h"
using namespace std;
int main()
{
    // 输出imageSize()中每个坐标的像素值
    Image image;
    initImage(image, 2, 2);
    // for (size_t i = 0; i < image._width; i++)
    // {
    //     for (size_t j = 0; j < image._height; j++)
    //     {
    //         cout<<"("<<static_cast<int>(image._pixels[i][j]._red)<<","<<static_cast<int>(image._pixels[i][j]._green)<<","<<static_cast<int>(image._pixels[i][j]._blue)<<")";
    //     }
    //     cout<<endl;
    // }
    setPixel(image, {0, 0}, {7,8,90});
    setPixel(image, {1, 0}, {0, 255, 0});
    // setPixel(image, {2, 0}, {0, 0, 255});
    setPixel(image, {0, 1}, {7,8,90});
    setPixel(image, {1, 1}, {7,8,90});
    // setPixel(image, {2, 1}, {0, 255, 255});
    // setPixel(image, {0, 2}, {255, 255, 255});
    // setPixel(image, {1, 2}, {0, 0, 0});
    // setPixel(image, {2, 2}, {128, 128, 128});
    // setPixel (image,{3,3},{7,8,90});
    printImage(image, true);
    cout<<"Image Size: "<<imageSize(image)<<endl;
    return 0;
}