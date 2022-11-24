//
// Created by lizhi on 2022/11/24.
//

// 在这里可以直接尝试你的代码

// 添加头文件到 include/public.h 中
#include "public.h"
int main() {
    initgraph(600, 800);

    GraphNode gn(100, 200, 30);
    gn.setRGB(255, 255, 255);



    setfillcolor(gn.getRGB());
    fillellipse(gn.getX(), gn.getY(), gn.getR(), gn.getR());

    getch();

    closegraph();
    return 0;
}