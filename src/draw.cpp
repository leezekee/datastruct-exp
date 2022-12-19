//
// Created by lizhi on 2022/11/24.
//

#include "draw.h"

// 画两个结点之间的线
//void drawLine(GraphNode &na, GraphNode &nb, color_t RGB){
//    setcolor(RGB);
//    line(na.getX(), na.getY() + na.getR(), nb.getX(), nb.getY() - na.getR());
//
//// if right:
////    line(na.getX() + na.getR() * 0.293, na.getY() + na.getR() * 0.293, nb.getX() - na.getR() * 0.293, nb.getY() - na.getR() * 0.293);
//// if right:
////    line(na.getX() - na.getR() * 0.293, na.getY() - na.getR() * 0.293, nb.getX() + na.getR() * 0.293, nb.getY() + na.getR() * 0.293);
//
//    //    line(na.getX(), na.getY(), nb.getX(), nb.getY());
//}

void visitNode(GraphNode &gn) {
    // 访问到node的代码
}

//void drawNode(GraphNode &gn, color_t RGB, color_t FontRGB) {
//    setcolor(RGB);
//    setfillcolor(RGB);
//    fillellipse(gn.getX(), gn.getY(), gn.getR(), gn.getR());
//
//    setcolor(FontRGB);
//    setbkmode(TRANSPARENT);
////    char label[] = "1";
////    gn.setString(label);
////    setfont(10, 5, "宋体");
//    outtextxy(gn.getX()-5, gn.getY()-8, gn.getS());
////    std::cout << gn.getS() << std::endl;
//}

void drawArrowLine(const GraphNode &gn1, const GraphNode &gn2, char *label) {
    int x1 = gn1.getX();
    int y1 = gn1.getY();
    int x2 = gn2.getX();
    int y2 = gn2.getY();
    double dx = x1 - x2;
    double dy = y1 - y2;
    double ds = sqrt(dx * dx + dy * dy);
    double a = dy / ds * 10;
    double b = dx / ds * 10;
    double c = dx / ds * 19;
    double d = dy / ds * 19;
    double x_begin = x1 - a - c;
    double y_begin = y1 + b - d;
    double x_end = x2 - a + c;
    double y_end = y2 + b + d;
    double arrow_base_x = x_end + c;
    double arrow_base_y = y_end + d;
    double arrow_out_x = x_end - a + c;
    double arrow_out_y = y_end + b + d;
    setcolor(0xEE0000);
    line(x_begin, y_begin, x_end, y_end);
    line(x_end, y_end, arrow_base_x, arrow_base_y);
    line(x_end, y_end, arrow_out_x, arrow_out_y);
    line(arrow_base_x, arrow_base_y, arrow_out_x, arrow_out_y);
    double arrow_center_x = (arrow_base_x + arrow_out_x + x_end) / 3;
    double arrow_center_y = (arrow_base_y + arrow_out_y + y_end) / 3;
    setfillcolor(0xEE0000);
    floodfill(arrow_center_x, arrow_center_y, 0xEE0000);
    double x_center = (x_begin + x_end) / 2 - a * 2;
    double y_center = (y_begin + y_end) / 2 + b * 2;
    setfont(18, 0, "黑体");
    xyprintf(x_center, y_center, label);
}

void drawNode(GraphNode &gn) {
    int x = gn.getX(), y = gn.getY();
    char *label;
    label = gn.getS();
    setcolor(0x66CCFF);
    setfillcolor(0x66CCFF);
    circle(x, y, gn.getR());
    floodfill(x, y, 0x66CCFF);
    setbkmode(TRANSPARENT);
    setcolor(0xEE0000);
    setfont(36, 0, "黑体");
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    xyprintf(x, y, label);
}

void drawNodes(Graph &g){
    for (int i = 0; i < g.vertexNumber; i++) {
        if (g.nodes[i].getVisibility())
            drawNode(g.nodes[i]);
    }
    for (int i = 0; i < g.vertexNumber; i++) {
        for (int j = 0; j < g.vertexNumber; j++) {
            if (g.adjMatrix[i][j] != 0 && g.nodes[i].getVisibility() && g.nodes[j].getVisibility()) {
                char label[20];
                memset(label, 0, sizeof(label));
                sprintf(label, "%.2lf", g.adjMatrix[i][j]);
                drawArrowLine(g.nodes[i], g.nodes[j], label);
                delay_ms(300);
            }
        }
    }
}

Graph inputGraph() {
//    int vex, edge;
//    std::cout << "input vertex number: ";
//    std::cin >> vex;
//    std::cout << "input edge number: ";
//    std::cin >> edge;
//    std::cout << "input adjMatrix: " << std::endl;
//    Graph g(vex, edge);
//    std::cin >> g;
//    return g;

    // test
    int vex = 5, edge = 6;
    Graph g(vex, edge);
    std::vector<std::vector<double>> v = {{0,0,1,1,0},
                                          {0,0,0,0,0},
                                          {0,0,0,0,0},
                                          {0,1,0,0,1},
                                          {1,0,1,0,0}};
    g.adjMatrix.swap(v);
    return g;
}

Graph CreateGraph() {
    Graph g = inputGraph();
    for (int i = 0; i < g.vertexNumber; ++i) {
        int x = 300 + 200 * cos((double)i / g.vertexNumber * 2 * PI - PI / 2);
        int y = 300 + 200 * sin((double)i / g.vertexNumber * 2 * PI - PI / 2);
        g.nodes[i].setXYR(x, y);
        char *t = new char[3];
        memset(t, 0, sizeof(t));
        itoa(i + 1, t, 10);
        g.nodes[i].setString(t);
    }
    return g;
}

void showGraph(Graph &g) {
    for (int i = 0; i < g.vertexNumber; i++) {
        drawNode(g.nodes[i]);
    }
    for (int i = 0; i < g.vertexNumber; i++) {
        for (int j = 0; j < g.vertexNumber; j++) {
            if (g.adjMatrix[i][j] != 0) {
                char label[20];
                memset(label, 0, sizeof(label));
                sprintf(label, "%.2lf", g.adjMatrix[i][j]);
                drawArrowLine(g.nodes[i], g.nodes[j], label);
            }
        }
    }
}
