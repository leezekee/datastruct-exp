//
// Created by lizhi on 2022/11/24.
//

#ifndef DATASTRUCT_EXP_DRAW_H
#define DATASTRUCT_EXP_DRAW_H
#include "GraphNode.h"

void drawLine(GraphNode &na, GraphNode &nb, color_t RGB);// 画两个结点之间的线
void visitNode(GraphNode &gn);
void drawNode(GraphNode &gn, color_t RGB, color_t FontRGB);


#endif //DATASTRUCT_EXP_DRAW_H
