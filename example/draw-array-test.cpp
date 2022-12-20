//
// Created by lizhi on 2022/12/1.
//

#include <public.h>

#define MaxSize 10
#define INF 1.0 / 0.0

typedef struct {
    double edge[MaxSize][MaxSize];
    int vertexNum, edgeNum;
    int predecessor[MaxSize];
} MGraph;

double x[MaxSize];
double y[MaxSize];

void CreateGraph(MGraph *G) {
    int i, j, k;
    double p;
    for (i = 0; i < MaxSize; ++i) {
        for (j = 0; j < MaxSize; ++j) {
            G->edge[i][j] = INF;
        }
        G->edge[i][i] = 0;
        G->predecessor[i] = 0;
    }
////    printf("请输入图的顶点个数：");
////    scanf("%d", &G->vertexNum);
//    G->vertexNum = 10;
//    G->edgeNum = 5;
////    printf("请输入边的个数：");
////    scanf("%d", &G->edgeNum);
//    for (i = 0; i < G->edgeNum; ++i) {
//        printf("请输入第%d条边(共%d条)的起止顶点序号(1-%d)和权值：", i + 1, G->edgeNum, G->vertexNum);
//        scanf("%d%d%lf", &j, &k, &p);
//        G->edge[j - 1][k - 1] = p;
//    }

    // input






    for (i = 0; i < G->vertexNum; ++i) {
        x[i] = 300 + 200 * cos((double)i / G->vertexNum * 2 * PI - PI / 2);
        y[i] = 300 + 200 * sin((double)i / G->vertexNum * 2 * PI - PI / 2);
    }
}


void DrawVertex(int x, int y, char *label) {
    setcolor(0x66CCFF);
    setfillcolor(0x66CCFF);
    circle(x, y, 20);
    floodfill(x, y, 0x66CCFF);
    setbkmode(TRANSPARENT);
    setcolor(0xEE0000);
    setfont(36, 0, "黑体");
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    xyprintf(x, y, label);
}

void DrawArrowLine(int x1, int y1, int x2, int y2, char *label) {
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

void PrintGraph(MGraph *G) {
    int i, j;
    char name[40];
    printf("\n邻接矩阵：\n        ");
    for (i = 0; i < G->vertexNum; ++i) {
        printf("%8d", i + 1);
    }
    printf("\n");
    for (i = 0; i < G->vertexNum; ++i) {
        printf("%8d", i + 1);
        for (j = 0; j < G->vertexNum; ++j) {
            if (G->edge[i][j] == INF) {
                printf("        ");
            } else {
                printf("%8.2lf", G->edge[i][j]);
            }
        }
        printf("\n");
    }


    initgraph(600, 600, 0);
    for (i = 0; i < G->vertexNum; ++i) {
        sprintf(name, "%d", i + 1);
        DrawVertex(x[i], y[i], name);
    }
    for (i = 0; i < G->vertexNum; ++i) {
        for (j = 0; j < G->vertexNum; ++j) {
            if (G->edge[i][j] == INF) {
                continue;
            }
            if (i == j) {
                continue;
            }
            sprintf(name, "%.2lf", G->edge[i][j]);
            DrawArrowLine(x[i], y[i], x[j], y[j], name);
        }
    }
    getch();
    closegraph();
}

void PrintPath(MGraph *G, int startV, int endV) {
    char name[80];
    if (G->predecessor[endV] == startV) {
        printf("%d -> %d", startV + 1, endV + 1);
        sprintf(name, "%d", endV + 1);
        DrawVertex(x[endV], y[endV], name);
        sprintf(name, "%d", startV + 1);
        DrawVertex(x[startV], y[startV], name);
        sprintf(name, "%.2lf", G->edge[startV][endV]);
        DrawArrowLine(x[startV], y[startV], x[endV], y[endV], name);
        return;
    }
    int pre = G->predecessor[endV];
    PrintPath(G, startV, pre);
    printf(" -> %d", endV + 1);
    sprintf(name, "%d", endV + 1);
    DrawVertex(x[endV], y[endV], name);
    sprintf(name, "%.2lf", G->edge[pre][endV]);
    DrawArrowLine(x[pre], y[pre], x[endV], y[endV], name);
}

void BellmanFord(MGraph *G) {
    int i, j, k, endV, startV;
    double distance[MaxSize];
    for (i = 0; i < G->vertexNum; ++i) {
        distance[i] = INF;
    }
    printf("请输入两个顶点：");
    scanf("%d%d", &startV, &endV);
    endV--;
    startV--;
    distance[startV] = 0;
    for (i = 0; i < G->vertexNum - 1; ++i) {
        int hasChange = 0;
        for (j = 0; j < G->vertexNum; ++j) {
            for (k = 0; k < G->vertexNum; ++k) {
                if (distance[k] > distance[j] + G->edge[j][k]) {
                    distance[k] = distance[j] + G->edge[j][k];
                    hasChange = 1;
                    G->predecessor[k] = j;
                }
            }
        }
        if (!hasChange) {
            break;
        }
    }
    for (j = 0; j < G->vertexNum; ++j) {
        for (k = 0; k < G->vertexNum; ++k) {
            if (distance[k] > distance[j] + G->edge[j][k]) {
                printf("图中存在负环路，无法求解！\n");
                return;
            }
        }
    }
    if (distance[endV] == INF) {
        printf("顶点%d和顶点%d不连通！\n", startV + 1, endV + 1);
        return;
    }
    cleardevice();
    initgraph(600, 600, 0);
    printf("从顶点%d到顶点%d的最短距离是%.2lf，最短路径是 ", startV + 1, endV + 1, distance[endV]);
    PrintPath(G, startV, endV);
    printf("\n");
    getch();
    closegraph();
}

int main() {
    MGraph G;
    CreateGraph(&G);
    PrintGraph(&G);
    BellmanFord(&G);
    return 0;
}