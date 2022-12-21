//
// Created by lizhi on 2022/11/24.
//

#ifndef DATASTRUCT_EXP_DRAW_H
#define DATASTRUCT_EXP_DRAW_H
#include "GraphNode.h"
#include <cmath>
#include <xmath.h>

void drawArrowLine(const GraphNode &gn1, const GraphNode &gn2, char *label);
void drawNodes(Graph &g);
void drawNode(GraphNode &gn);
void drawVisibleNode(GraphNode &gn);
Graph inputGraph();

Graph CreateGraph();
void showGraph(Graph &g);
void showOpNext(Graph &g, std::vector<std::pair<int, int>> operation, int index);
void showOpPrev(Graph &g, std::vector<std::pair<int, int>> operation, int index);

#endif //DATASTRUCT_EXP_DRAW_H
