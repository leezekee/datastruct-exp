//
// Created by lizhi on 2022/11/24.
//

#include "my-algorithm.h"

void dfs(Graph &g, int v0, int *_visited, std::vector<std::pair<int, int>> &operation){
    visit(g, v0, _visited, operation);
//    drawNodes(g);
//    getch();
    for (int i = 0; i < g.vertexNumber; i++) {
        for (int j = 0; j < g.vertexNumber; j++) {
            if (g.adjMatrix[i][j] != 0 && !_visited[j]) {
                dfs(g, j, _visited, operation);
            }
        }
    }
}

void dfs(Graph &g, std::vector<std::pair<int, int>> &operation){
    for (auto &each : g.nodes) {
        each.setVisibility(false);
    }
    int visited[g.vertexNumber] = {0};
    for (int i = 0; i < g.vertexNumber; i++) {
        if (!visited[i]) {
            dfs(g, i, visited, operation);
        }
    }
}

int findAdjVex(Graph &g, int v0, int *visited){
    for (int i = 0; i < g.vertexNumber; i++) {
        if (g.adjMatrix[v0][i] != 0 && !visited[i]) {
            return i;
        }
    }
    return -1;
}

void bfs(Graph &g, int v0, int *visited, std::vector<std::pair<int, int>> &operation) {
    std::queue<int> que;
    que.push(v0);
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        visit(g, v0, visited, operation);
        int next = findAdjVex(g, p, visited);
        while (next != -1) {
            que.emplace(next);
            visit(g, next, visited, operation);
            next = findAdjVex(g, p, visited);
        }
    }
}

void bfs(Graph &g, std::vector<std::pair<int, int>> &operation) {
    for (auto &each : g.nodes) {
        each.setVisibility(false);
    }
    int visited[g.vertexNumber] = {0};
    for (int i = 0; i < g.vertexNumber; i++) {
        if (!visited[i]) {
            bfs(g, i, visited, operation);
        }
    }
}

void visit(Graph &g, int v0, int *_visited, std::vector<std::pair<int, int>> &operation) {
    auto isEnd = ([&] {
        for (int i = 0; i < g.vertexNumber; i++) {
            if (!_visited[i])
                return false;
        }
        return true;
    });
    g.nodes[v0].setVisibility(true);
//    drawNode(g.nodes[v0]);
    for (int i = 0; i < g.vertexNumber; i++) {
        if (g.adjMatrix[i][v0] != 0 && g.nodes[i].getVisibility()) {
//            char b_label[20];
//            memset(b_label, 0, sizeof(b_label));
//            sprintf(b_label, "%.2lf", g.adjMatrix[i][v0]);
//            drawArrowLine(g.nodes[i], g.nodes[v0], b_label);
//            delay_ms(300);
            std::cout << i + 1 << " -> " << v0 + 1 << std::endl;
            std::pair<int, int> tmp = {i, v0};
            operation.emplace_back(tmp);
        }
        if (isEnd()) {
            break;
        }
    }
    _visited[v0] = 1;
}