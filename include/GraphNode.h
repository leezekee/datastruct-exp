//
// Created by lizhi on 2022/11/24.
//

#ifndef DATASTRUCT_EXP_GRAPHNODE_H
#define DATASTRUCT_EXP_GRAPHNODE_H
#include <graphics.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <xmath.h>

#define INFIN 1.0 / 0.0

class GraphNode {
public:
    BYTE red;
    BYTE blue;
    BYTE green;
private:
    int x; // 坐标x y值
    int y;
    int radius;  // 结点圆的半径
//    char *b_label;  // 结点的内容
    int label;
    bool isVisible; // 结点是否可见
public:
    GraphNode();    // 无参构造
    GraphNode(int x, int y);    // 含参构造
    GraphNode(int x, int y, int r);
//    GraphNode(GraphNode &other);    // 拷贝构造
    ~GraphNode();   // 析构函数
    int getX() const {return this->x;}  // 获取x y坐标 半径 结点内容 是否可见
    int getY() const {return this->y;}
    int getR() const {return this->radius;}
//    char * getS() {return this->b_label;}
    int getLabel() const {return this->label;}
    bool getVisibility() const {return this->isVisible;}
    void setXYR(int _x, int _y, int _radius = 20); // 设置坐标和半径
//    void setString(char *_name);  // 设置结点内容
    void setLabel(int label);
    void setRGB(BYTE R, BYTE G, BYTE B);   // 设置RGB值
    void setVisibility(bool _visibility);  // 设置是否可见
    void changeVisibility(); // 改变可见度
    GraphNode& operator=(int adj);
    bool operator==(int adj) const;
//    friend std::ostream & operator<<(std::ostream &out, GraphNode &G);
//    friend std::istream & operator>>(std::istream &in, GraphNode &G);
};

class Graph {
public:
    int vertexNumber;
    int edgeNumber;
    std::vector<std::vector<double>> adjMatrix;
    std::vector<GraphNode> nodes;
public:
    Graph() : vertexNumber(0), edgeNumber(0) {}
    Graph(int vex, int edge) : vertexNumber(vex), edgeNumber(edge) {
        std::vector<std::vector<double>> initialization(vex, std::vector<double>(vex));
        adjMatrix.swap(initialization);
        for (auto &row : adjMatrix) {
            for (auto &each : row) {
                each = 0;
            }
        }
        std::vector<GraphNode> v(vertexNumber);
        nodes.swap(v);
        for (int i = 1; i <= vertexNumber; i++) {
//            char *t = (char*)malloc(sizeof(char) * 3);
//            itoa(i, t, 10);
//            nodes[i].setString(t);
            nodes[i].setLabel(i + 1);
        }
    }
    void setVertexNumber(int vex) {
        this->vertexNumber = vex;
        std::vector<std::vector<double>> initialization(vex, std::vector<double>(vex));
        adjMatrix.swap(initialization);
        for (auto &row : adjMatrix) {
            for (auto &each : row) {
                each = 0;
            }
        }
        std::vector<GraphNode> v(vertexNumber);
        nodes.swap(v);
        for (int i = 1; i <= vertexNumber; i++) {
//            char *t = (char*)malloc(sizeof(char) * 3);
//            itoa(i, t, 10);
//            nodes[i].setString(t);
            nodes[i].setLabel(i + 1);
        }
//        std::cout << this->vertexNumber << std::endl;
    }
    friend std::istream & operator>>(std::istream &is, Graph &g);
    friend std::ostream & operator<<(std::ostream &os, const Graph &g);
};

#endif //DATASTRUCT_EXP_GRAPHNODE_H
