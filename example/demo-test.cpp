//
// Created by lizhi on 2022/11/24.
//

// 在这里可以直接尝试你的代码

// 添加头文件到 include/public.h 中
#include "public.h"

void openSubWindow(HWND hwnd) {
    attachHWND(hwnd);
    initgraph(200, 300, INIT_NOBORDER | INIT_CHILD);
    setbkcolor(WHITE);
    getchar();
    closegraph();
}

int main() {
//    initgraph(600, 800, INIT_RENDERMANUAL);
//    HWND hwnd = getHWnd();
//
//    getchar();
//    closegraph();
    initgraph(600, 600);
    setbkcolor(WHITE);
    Graph g = CreateGraph();
    showGraph(g);
    getch();
    cleardevice();
    for (int i = 0; i < g.vertexNumber; i++) {
//        cleardevice();
        g.nodes[i].setVisibility(true);
        drawNodes(g);
//        delay_fps(180);
//        getch();
        delay_ms(500);
    }
    getch();

    closegraph();
    return 0;
}