//
// Created by lizhi on 2022/12/20.
//

#ifndef DATASTRUCT_EXP_GUI_H
#define DATASTRUCT_EXP_GUI_H
#include <graphics.h>
#include <GraphNode.h>
#include <functional>
#include <my-algorithm.h>
#include <ege/sys_edit.h>

void nextStep(Graph &g, const std::vector<std::pair<int, int>> &operation, int &index, std::function<int ()> const &fun);
void prevStep(Graph &g, const std::vector<std::pair<int, int>> &operation, int &index, std::function<int ()> const &fun);

void BFS(Graph &g);
void DFS(Graph &g);
void Menu(Graph &g);
void init();
void initEditBox(sys_edit &editBox, bool multiline, int x, int y, int width, int height);

void showMatrix(const Graph &g);
void input(Graph &g);
void inputVexNumber(Graph &g);
void inputAdjMatrix(Graph& g);

class button {
private:
    int x;
    int y;
    int width;
    int height;
    char *b_label;
    bool isShow;
public:
    button() : x(0), y(0), width(110), height(50), isShow(true) { b_label = new char[20];}
    button(int _x, int _y, char *_label) : x(_x), y(_y), width(110), height(50), isShow(true){
        b_label = new char[sizeof(_label)];
        strcpy(b_label, _label);
    }
    button(int _x, int _y, int _width, int _height, char *_label) : x(_x), y(_y), width(_width), height(_height), isShow(true){
        b_label = new char[sizeof(_label)];
        strcpy(b_label, _label);
    }
//    ~button() {delete[] b_label;}
    void setx(int _x) {this->x = _x;}
    void sety(int _y) {this->y = _y;}
    void setWidth(int _width) {this->width = _width;}
    void setHeight(int _height) {this->height = _height;}
    void setShow(bool _isShow) {this->isShow = _isShow;}
    bool onClick();
    void show();
};

#endif //DATASTRUCT_EXP_GUI_H
