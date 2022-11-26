//
// Created by lizhi on 2022/11/24.
//

// 在这里可以直接尝试你的代码

// 添加头文件到 include/public.h 中
#include "public.h"
int main() {
    int r = 30;
    GraphNode gn[10];
    for (int i = 0; i < 10; i++) {
        int s;
        std::cin >> s;
        char st[3];
        sprintf(st, "%d", s);
        gn[i].setString(st);
    }

    for (int i = 0; i < 10; i++) {
        gn[i].setXYR(60 * i + 90, 60 * i + 90, r);
        gn[i].setRGB(255, 255, 255);
//        char name[3];
//        sprintf(name, "%d", i + 1);
//        gn[i].setString(name);
//        std::cout << gn[i].getS() << std::endl;
        drawNode(gn[i], EGERGB(gn[i].red, gn[i].green, gn[i].blue), EGERGB(255-gn[i].red, 255-gn[i].green, 255-gn[i].blue));
    }

    initgraph(1128, 1024);
    for (int i = 0; i < 9; i++) {
        drawLine(gn[i], gn[i + 1], EGERGB(255,0,0));
    }


    getch();

    closegraph();
    return 0;
}