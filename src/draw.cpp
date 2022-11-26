//
// Created by lizhi on 2022/11/24.
//

#include "draw.h"

// 画两个结点之间的线
void drawLine(GraphNode &na, GraphNode &nb, color_t RGB){
    setcolor(RGB);
//    line(na.getX(), na.getY() + na.getR(), nb.getX(), nb.getY() - na.getR());

// if right:
    line(na.getX() + na.getR() * 0.293, na.getY() + na.getR() * 0.293, nb.getX() - na.getR() * 0.293, nb.getY() - na.getR() * 0.293);
// if right:
//    line(na.getX() - na.getR() * 0.293, na.getY() - na.getR() * 0.293, nb.getX() + na.getR() * 0.293, nb.getY() + na.getR() * 0.293);

    //    line(na.getX(), na.getY(), nb.getX(), nb.getY());
}

void visitNode(GraphNode &gn) {
    // 访问到node的代码
}

void drawNode(GraphNode &gn, color_t RGB, color_t FontRGB) {
    setcolor(RGB);
    setfillcolor(RGB);
    fillellipse(gn.getX(), gn.getY(), gn.getR(), gn.getR());

    setcolor(FontRGB);
    setbkmode(TRANSPARENT);
//    char name[] = "1";
//    gn.setString(name);
//    setfont(10, 5, "宋体");
    outtextxy(gn.getX()-5, gn.getY()-8, gn.getS());
//    std::cout << gn.getS() << std::endl;
}

void deleteNode(){

}