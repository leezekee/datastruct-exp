//
// Created by lizhi on 2022/11/24.
//

#include "my-algorithm.h"

void dfs(Graph &g, int v0, int *_visited, std::vector<std::pair<int, int>> &operation){
    visit_dfs(g, v0, _visited, operation);
    for (int i = 0; i < g.vertexNumber; i++) {
        if (g.adjMatrix[v0][i] != 0 && !_visited[i]) {
            dfs(g, i, _visited, operation);
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
        visit_bfs(g, v0, visited, operation);
        int next = findAdjVex(g, p, visited);
        while (next != -1) {
            que.emplace(next);
            visit_bfs(g, next, visited, operation);
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

void visit_dfs(Graph &g, int v0, int *_visited, std::vector<std::pair<int, int>> &operation) {
    auto isEnd = ([&] {
        for (int i = 0; i < g.vertexNumber; i++) {
            if (!_visited[i])
                return false;
        }
        return true;
    });
    g.nodes[v0].setVisibility(true);
    std::pair<int, int> tmp = {v0, v0};
    std::cout << v0 + 1 << std::endl;
    operation.emplace_back(tmp);
//    drawNode(g.nodes[v0]);
    auto findStart = [&](int n) -> bool {
        for (auto each : operation) {
            if (each.first == n && each.second != n) {
                return true;
            }
        }
        return false;
    };
    auto findEnd = [&](int n) -> bool {
        for (auto each : operation) {
            if (each.second == n && each.first != n) {
                return true;
            }
        }
        return false;
    };
    for (int i = 0; i < g.vertexNumber; i++) {
        if (g.adjMatrix[i][v0] != 0 && g.nodes[i].getVisibility()) {
            if (!findStart(i) && !findEnd(v0)) {
                std::cout << i + 1 << " -> " << v0 + 1 << std::endl;
                std::pair<int, int> tmp = {i, v0};
                operation.emplace_back(tmp);
            }
        }
        if (isEnd()) {
            std::cout << "visit break" << std::endl;
            break;
        }
    }
    _visited[v0] = 1;
}

void visit_bfs(Graph &g, int v0, int *_visited, std::vector<std::pair<int, int>> &operation) {
    auto isEnd = ([&] {
        for (int i = 0; i < g.vertexNumber; i++) {
            if (!_visited[i])
                return false;
        }
        return true;
    });
    g.nodes[v0].setVisibility(true);
    std::pair<int, int> tmp = {v0, v0};
    std::cout << v0 + 1 << std::endl;
    operation.emplace_back(tmp);
//    drawNode(g.nodes[v0]);
    auto findStart = [&](int n) -> bool {
        for (auto each : operation) {
            if (each.first == n && each.second != n) {
                return true;
            }
        }
        return false;
    };
    auto findEnd = [&](int n) -> bool {
        for (auto each : operation) {
            if (each.second == n && each.first != n) {
                return true;
            }
        }
        return false;
    };
    for (int i = 0; i < g.vertexNumber; i++) {
        if (g.adjMatrix[i][v0] != 0 && g.nodes[i].getVisibility()) {
            if (!findEnd(v0)) {
                std::cout << i + 1 << " -> " << v0 + 1 << std::endl;
                std::pair<int, int> tmp = {i, v0};
                operation.emplace_back(tmp);
            }
        }
        if (isEnd()) {
            std::cout << "visit break" << std::endl;
            break;
        }
    }
    _visited[v0] = 1;

}