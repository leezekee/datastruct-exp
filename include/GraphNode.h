//
// Created by lizhi on 2022/11/24.
//

#ifndef DATASTRUCT_EXP_GRAPHNODE_H
#define DATASTRUCT_EXP_GRAPHNODE_H
#include <graphics.h>
#include <string>
#include <ostream>

class GraphNode {
public:
    int adjInfo;
private:
    int x; // 坐标x y值
    int y;
    int radius;  // 结点圆的半径
    std::string name;  // 结点的内容
    bool isVisible; // 结点是否可见
    int red;    // 结点RGB数据
    int green;
    int blue;
    static int nodeNumber; // 所有结点数量
public:
    GraphNode();    // 无参构造
    GraphNode(int x, int y);    // 含参构造
    GraphNode(int x, int y, int r);
    GraphNode(GraphNode &other);    // 拷贝构造
    ~GraphNode();   // 析构函数
    int getX() const {return this->x;}  // 获取x y坐标 半径 结点内容 是否可见
    int getY() const {return this->y;}
    int getR() const {return this->radius;}
    std::string getS() const {return this->name;}
    bool getVisibility() const {return this->isVisible;}
    void setXYR(int _x, int _y, int _radius); // 设置坐标和半径
    void setString(std::string _name);  // 设置结点内容
    void setRGB(int R, int G, int B);   // 设置RGB值
    void setVisibility(bool _visibility);  // 设置是否可见
    void changeVisibility(); // 改变可见度
    color_t getRGB(); // 返回RGB值
    // 运算符重载
    GraphNode& operator=(int adj);
    bool operator==(int adj) const;
    friend std::ostream & operator<<(std::ostream &out, GraphNode &G);
    friend std::istream & operator>>(std::istream &in, GraphNode &G);
};

#endif //DATASTRUCT_EXP_GRAPHNODE_H
