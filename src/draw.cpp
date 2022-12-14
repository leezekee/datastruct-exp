//
// Created by lizhi on 2022/11/24.
//

#include "draw.h"
#include <gui.h>

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
    setcolor(0xFF6D31);
    line(x_begin, y_begin, x_end, y_end);
    line(x_end, y_end, arrow_base_x, arrow_base_y);
    line(x_end, y_end, arrow_out_x, arrow_out_y);
    line(arrow_base_x, arrow_base_y, arrow_out_x, arrow_out_y);
    double arrow_center_x = (arrow_base_x + arrow_out_x + x_end) / 3;
    double arrow_center_y = (arrow_base_y + arrow_out_y + y_end) / 3;
    setfillcolor(0xFF6D31);
    floodfill(arrow_center_x, arrow_center_y, 0xFF6D31);
    double x_center = (x_begin + x_end) / 2 - a * 2;
    double y_center = (y_begin + y_end) / 2 + b * 2;
    setfont(18, 0, "黑体");
    xyprintf(x_center, y_center, label);
}

void drawNode(GraphNode &gn) {
    int x = gn.getX(), y = gn.getY(), l = gn.getLabel();
    char *label = new char[20];
    sprintf(label, "%d", l);
    setcolor(0x29A2C6);
    setfillcolor(0x29A2C6);
    circle(x, y, gn.getR());
    floodfill(x, y, 0x29A2C6);
    setbkmode(TRANSPARENT);
    setcolor(0xFFCB18);
    setfont(36, 0, "黑体");
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    xyprintf(x, y, label);
}

void drawVisibleNode(GraphNode &gn) {
    int x = gn.getX(), y = gn.getY(), l = gn.getLabel();
    char *label = new char[20];
    sprintf(label, "%d", l);
    setcolor(0x73B66B);
    setfillcolor(0x73B66B);
    circle(x, y, gn.getR());
    floodfill(x, y, 0x73B66B);
    setbkmode(TRANSPARENT);
    setcolor(0xFFCB18);
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
//                delay_ms(300);
            }
        }
    }
}

Graph inputGraph() {
    Graph g;
    input(g);
    return g;
}

Graph CreateGraph() {
    Graph g = inputGraph();
    for (int i = 0; i < g.vertexNumber; ++i) {
        int x = 430 + 300 * cos((double)i / g.vertexNumber * 2 * PI - PI / 2);
        int y = 380 + 300 * sin((double)i / g.vertexNumber * 2 * PI - PI / 2);
        g.nodes[i].setXYR(x, y);
//        char *t = new char[20];
//        memset(t, 0, sizeof(t));
//        sprintf(t, "%d", i + 1);
//        g.nodes[i].setString(t);
        g.nodes[i].setLabel(i + 1);
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
                char label[20] = "";
                sprintf(label, "%.2lf", g.adjMatrix[i][j]);
                drawArrowLine(g.nodes[i], g.nodes[j], label);
            }
        }
    }
}

void showOpNext(Graph &g, std::vector<std::pair<int, int>> operation, int index) {
    for (int i = 0; i < g.vertexNumber; i++) {
        if (g.nodes[i].getVisibility())
            drawVisibleNode(g.nodes[i]);
        else
            drawNode(g.nodes[i]);
    }
    for (int i = 0; i <= index; i++) {
        char label[20] = "";
        sprintf(label, "%.2lf", g.adjMatrix[operation[i].first][operation[i].second]);
        if (operation[i].first != operation[i].second)
            drawArrowLine(g.nodes[operation[i].first], g.nodes[operation[i].second], label);
    }
}

void showOpPrev(Graph &g, std::vector<std::pair<int, int>> operation, int index) {
    for (int i = 0; i < g.vertexNumber; i++) {
        if (g.nodes[i].getVisibility())
            drawVisibleNode(g.nodes[i]);
        else
            drawNode(g.nodes[i]);
    }
    for (int i = 0; i < index; i++) {
        char label[20] = "";
        sprintf(label, "%.2lf", g.adjMatrix[operation[i].first][operation[i].second]);
        if (operation[i].first != operation[i].second)
            drawArrowLine(g.nodes[operation[i].first], g.nodes[operation[i].second], label);
    }
}

