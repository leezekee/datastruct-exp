//
// Created by lizhi on 2022/12/19.
//

#include "public.h"
int main() {
    initgraph(600, 600);
    setbkcolor(WHITE);
    std::vector<std::pair<int, int>> operation;
    Graph g = CreateGraph();
    showGraph(g);
    getch();
    cleardevice();
    dfs(g, operation);
    getch();
    closegraph();
    return 0;
}