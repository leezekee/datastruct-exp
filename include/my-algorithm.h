//
// Created by lizhi on 2022/11/24.
//

#ifndef DATASTRUCT_EXP_MY_ALGORITHM_H
#define DATASTRUCT_EXP_MY_ALGORITHM_H
#include "GraphNode.h"

void _dfs(GraphNode **_vexes, int v0, int *_visited);
void dfs(GraphNode **vexes);


int findAdjVex(GraphNode **vexes, int v0, int *visited);
void _bfs(GraphNode **vexes, int v0, int *visited);
void bfs(GraphNode **vexes);

#endif //DATASTRUCT_EXP_MY_ALGORITHM_H
