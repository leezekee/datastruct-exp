//
// Created by lizhi on 2022/11/24.
//

// 在这里可以直接尝试你的代码

// 添加头文件到 include/public.h 中
#include "public.h"
int main() {
    initgraph(1128, 1024);
    int r = 30;

    GraphNode gn[10];

    for (int i = 0; i < 10; i++) {
        gn[i].setXYR(60 * i + 80, 60 * i + 80, r);
        gn[i].setRGB(255, 255, 255);
        char name[3];
        sprintf(name, "%d", i + 1);
        gn[i].setString(name);
//        std::cout << gn[i].getS() << std::endl;
        drawNode(gn[i], EGERGB(255, 0, 0), EGERGB(255,255,255));
    }

    for (int i = 0; i < 9; i++) {
        drawLine(gn[i], gn[i + 1], EGERGB(255, 0, 0));
    }


    getch();

    closegraph();
    return 0;
}