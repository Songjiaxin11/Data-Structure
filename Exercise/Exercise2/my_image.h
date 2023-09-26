#ifndef MY_IMAGE_H
#define MY_IMAGE_H
#include <cstddef>
typedef unsigned char Channel;//把unsigned char这个数据类型换个名字, 叫Channel, 所以色域是没有符号的正数
//unsigned char 只有正数, 表示无符号字符类型 [0,255]
//signed char, 表示有符号字符类型 [-128,127]

const int MAX_WIDTH=64;
const int MAX_HEIGHT=64;
struct Vec2
{
    size_t _x,_y;//to represent a 2D vector, 无符号整数类型变量, 用来表示对象的大小, 以字节数为单位
};

struct Pixel
{
    Channel _red, _green, _blue;//to represent a pixel
};

struct Image
{
    size_t _width, _height;//to represent an image
    Pixel _pixels[MAX_WIDTH][MAX_HEIGHT];//to represent an array of pixels
};
void initImage(Image &image, size_t width, size_t height);

#endif