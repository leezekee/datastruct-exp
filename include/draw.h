//
// Created by lizhi on 2022/11/24.
//

#ifndef DATASTRUCT_EXP_DRAW_H
#define DATASTRUCT_EXP_DRAW_H
#include "GraphNode.h"
#include <cmath>
#include <xmath.h>

//void drawLine(GraphNode &na, GraphNode &nb, color_t RGB);// 画两个结点之间的线
//void drawNode(GraphNode &gn, color_t RGB, color_t FontRGB);

void drawArrowLine(const GraphNode &gn1, const GraphNode &gn2, char *label);
void drawNodes(Graph &g);
void showGraph(Graph &g);
void drawNode(GraphNode &gn);
void showOpNext(Graph &g, std::vector<std::pair<int, int>> operation, int index);
void showOpPrev(Graph &g, std::vector<std::pair<int, int>> operation, int index);
Graph CreateGraph();

void PrintPath(GraphNode** &gn);

Graph inputGraph();



// 调试用



#endif //DATASTRUCT_EXP_DRAW_H
