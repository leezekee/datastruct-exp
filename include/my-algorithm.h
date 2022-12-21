//
// Created by lizhi on 2022/11/24.
//

#ifndef DATASTRUCT_EXP_MY_ALGORITHM_H
#define DATASTRUCT_EXP_MY_ALGORITHM_H
#include "GraphNode.h"
#include <draw.h>
#include <queue>
#include <utility>


void dfs(Graph &g, int v0, int *_visited, std::vector<std::pair<int, int>> &operation);
void dfs(Graph &g, std::vector<std::pair<int, int>> &operation);


int findAdjVex(Graph &g, int v0, int *visited);
void bfs(Graph &g, int v0, int *visited, std::vector<std::pair<int, int>> &operation);
void bfs(Graph &g, std::vector<std::pair<int, int>> &operation);

void visit_dfs(Graph &g, int v0, int *_visited, std::vector<std::pair<int, int>> &vector);
void visit_bfs(Graph &g, int v0, int *_visited, std::vector<std::pair<int, int>> &operation);

#endif //DATASTRUCT_EXP_MY_ALGORITHM_H
