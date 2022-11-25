//
// Created by lizhi on 2022/11/24.
//

#ifndef DATASTRUCT_EXP_GRAPHNODE_H
#define DATASTRUCT_EXP_GRAPHNODE_H
#include <graphics.h>
#include <iostream>

class GraphNode {
public:
    int adjInfo;
    BYTE red;
    BYTE blue;
    BYTE green;
//    class RGBcolor{
//    public:
//        int red;    // 结点RGB数据
//        int green;
//        int blue;
//    };
private:
    int x; // 坐标x y值
    int y;
    int radius;  // 结点圆的半径
    char name[3]{};  // 结点的内容
    bool isVisible; // 结点是否可见
    static int nodeNumber; // 所有结点数量
//    RGBcolor RGB; // 结点RGB数据
//    color_t RGB;
public:
    GraphNode();    // 无参构造
    GraphNode(int x, int y);    // 含参构造
    GraphNode(int x, int y, int r);
    GraphNode(GraphNode &other);    // 拷贝构造
    ~GraphNode();   // 析构函数
    int getX() const {return this->x;}  // 获取x y坐标 半径 结点内容 是否可见
    int getY() const {return this->y;}
    int getR() const {return this->radius;}
    const char *getS() const {return this->name;}
    bool getVisibility() const {return this->isVisible;}
    void setXYR(int _x, int _y, int _radius); // 设置坐标和半径
    void setString(char *_name);  // 设置结点内容
    void setRGB(BYTE R, BYTE G, BYTE B);   // 设置RGB值
    void setVisibility(bool _visibility);  // 设置是否可见
    void changeVisibility(); // 改变可见度
//    color_t getRGB() const; // 返回RGB值
//    color_t getFontColor() const;
    // 运算符重载
    GraphNode& operator=(int adj);
    bool operator==(int adj) const;
    friend std::ostream & operator<<(std::ostream &out, GraphNode &G);
    friend std::istream & operator>>(std::istream &in, GraphNode &G);
};

#endif //DATASTRUCT_EXP_GRAPHNODE_H
