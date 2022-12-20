//
// Created by lizhi on 2022/12/20.
//
#include "gui.h"
#include <draw.h>


void nextStep(Graph &g, const std::vector<std::pair<int, int>> &operation, int &index, std::function<int ()> const &fun) {
    if (index >= operation.size()) {
        MessageBox(getHWnd(), (LPCSTR)"This is the last step!", (LPCSTR)"warning", MB_ICONWARNING | MB_OK | MB_SYSTEMMODAL);
        return;
    }
    std::cout << "next step" << std::endl;
    int start = operation[index].first, end = operation[index].second;
    std::cout << start << " -> " << end << std::endl;
    g.nodes[start].setVisibility(true);
    g.nodes[end].setVisibility(true);
//                drawNodes(g);
    cleardevice();
    fun();
    showOpNext(g, operation, index);
    index++;
}

void prevStep(Graph &g, const std::vector<std::pair<int, int>> &operation, int &index, std::function<int ()> const &fun) {
    if (index <= 0) {
        MessageBox(getHWnd(),(LPCSTR)"This is the fist step!", (LPCSTR)"warning", MB_ICONWARNING | MB_OK | MB_SYSTEMMODAL);
        return;
    }
    std::cout << "previous step" << std::endl;
    int end = operation[--index].second;
    g.nodes[end].setVisibility(false);
    cleardevice();
    fun();
    showOpPrev(g, operation, index);
}

bool button::onClick() {
    mouse_msg msg = getmouse();
//    std::cout << msg.x << " " << msg.y << std::endl;
//    std::cout << this->x << " " << this->y << " " << this->x + this->width << " " << this->y + this->height << std::endl;
//    std::cout << ((msg.x >= this->x) && (msg.y >= this->y) && (msg.x <= this->x + this->width) && (msg.y <= this->y + this->height)) << std::endl;
    return (msg.x >= this->x) && (msg.y >= this->y)
           && (msg.x <= this->x + this->width)
           && (msg.y <= this->y + this->height);
}

void button::show() {
    setfillcolor(0x38595E);
    bar(this->x, this->y, this->x + this->width, this->y + this->height);
    int label_x = this->x + this->width / 2;
    int label_y = this->y + this->height / 2;
    setbkmode(TRANSPARENT);
    setcolor(0x2CC0B3);
    setfont(20, 0, "黑体");
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    xyprintf(label_x, label_y, "%s", b_label);
}

void BFS(Graph &g) {
    setcaption("Visualization of BFS and DFS - BFS");
    cleardevice();
    setbkcolor(0xD0DFE6);

//    setbkcolor(WHITE);
    showGraph(g);


    char label[20] = "prev";
    button btn_prev(900, 100, label);
    char label1[20] = "next";
    button btn_next(900, 200, label1);
    char label2[20] = "back";
    button btn_back(900, 300, label2);

//    btn_prev.show();
//    btn_next.show();
//    btn_back.show();


    auto showMain = [&]() -> bool {
        setcolor(EGERGBA(0,0,0,255));
        ege_rectangle(20, 20, 860, 720);
        btn_prev.show();
        btn_next.show();
        btn_back.show();
        return true;
    };


    showMain();
    std::vector<std::pair<int, int>> operation{};
    bfs(g, operation);
    int index = 0;
    for (auto &each : g.nodes) {
        each.setVisibility(false);
    }

    for (; is_run(); delay_fps(20)) {
        while (mousemsg()) {
            mouse_msg msg = getmouse();
            if (msg.is_left()) {
                if (msg.is_down()) {
                    if (btn_next.onClick()) {
                        nextStep(g, operation, index, showMain);
                    } else if (btn_prev.onClick()) {
                        prevStep(g, operation, index, showMain);
                    } else if (btn_back.onClick()) {
                        Menu(g);
                    }
                }
            }
        }
    }

    getch();
    closegraph();
}

void DFS(Graph &g) {
    setcaption("Visualization of BFS and DFS - DFS");
    cleardevice();
    setbkcolor(0xD0DFE6);

//    setbkcolor(WHITE);
    showGraph(g);


    char label[20] = "prev";
    button btn_prev(900, 100, label);
    char label1[20] = "next";
    button btn_next(900, 200, label1);
    char label2[20] = "back";
    button btn_back(900, 300, label2);
//    btn_prev.show();
//    btn_next.show();
//    btn_back.show();


    auto showMain = [&]() -> bool {
        setcolor(EGERGBA(0,0,0,255));
        ege_rectangle(20, 20, 860, 720);
        btn_prev.show();
        btn_next.show();
        btn_back.show();
        return true;
    };


    showMain();
    std::vector<std::pair<int, int>> operation{};
    dfs(g, operation);
    int index = 0;
    for (auto &each : g.nodes) {
        each.setVisibility(false);
    }

    for (; is_run(); delay_fps(20)) {
        while (mousemsg()) {
            mouse_msg msg = getmouse();
            if (msg.is_left()) {
                if (msg.is_down()) {
                    if (btn_next.onClick()) {
                        nextStep(g, operation, index, showMain);
                    } else if (btn_prev.onClick()) {
                        prevStep(g, operation, index, showMain);
                    } else if (btn_back.onClick()) {
                        Menu(g);
                    }
                }
            }
        }
    }

    getch();
    closegraph();
}

void init() {
    Graph g = CreateGraph();
    std::cout << g << std::endl;
    Menu(g);

}

void Menu(Graph &g) {
//    initgraph(1024 , 768, INIT_RENDERMANUAL);
    setcaption("Visualization of BFS and DFS - select mode");
    initgraph(1024 , 768, INIT_RENDERMANUAL);
    cleardevice();
    setbkcolor(0xD0DFE6);
//    Graph g = CreateGraph();
//    showGraph(g);


    char label[20] = "DFS";
    button btn(900, 100, label);
    char label1[20] = "BFS";
    button btn1(900, 200, label1);
    btn.show();
    btn1.show();

    auto showMain = [&]() -> bool {
        setcolor(EGERGBA(0,0,0,255));
        ege_rectangle(20, 20, 860, 720);
        btn.show();
        btn1.show();
        return true;
    };


    showMain();
    showMatrix(g);
    for (auto &each : g.nodes) {
        each.setVisibility(true);
    }

    for (; is_run(); delay_fps(20)) {
        while (mousemsg()) {
            mouse_msg msg = getmouse();
            if (msg.is_left()) {
                if (msg.is_down()) {
                    if (btn1.onClick()) {
                        BFS(g);
                    } else if (btn.onClick()) {
                        DFS(g);
                    }
                }
            }
        }
    }

    getch();
    closegraph();
}

void showMatrix(const Graph &g) {
    setbkmode(TRANSPARENT);
    setfont(18, 0, "黑体");
//    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(BLACK);
    xyprintf(150, 150, "Matrix of adjacency:\n");
    for (int i = 0; i < g.vertexNumber; i++) {
        xyprintf(250 + 50 * i, 200, "%d", i + 1);
    }
    for (int i = 0 ; i < g.vertexNumber; i++) {
        xyprintf(200 , 200 + 30 * (i + 1), "%d", i + 1);
        for (int j = 0; j < g.vertexNumber; j++) {
            if (g.adjMatrix[i][j] == INFIN || g.adjMatrix[i][j] == 0) {
                xyprintf(200 + 50 * (j + 1), 200 + 30 * (i + 1), " ");
            } else {
                xyprintf(200 + 50 * (j + 1), 200 + 30 * (i + 1), "%.2lf", g.adjMatrix[i][j]);
            }
        }
    }
}

void initEditBox(sys_edit &editBox, bool multiline, int x, int y, int width, int height) {
    editBox.create(multiline);
    editBox.size(width, height + 8);
    editBox.setbgcolor(0xD0DFE6);
    editBox.setfont(18, 0, "黑体");
    editBox.move(x, y);
    editBox.visible(true);
    editBox.setfocus();
}

void input(Graph &g) {
    setcaption("Input Graph");
    initgraph(300, 400, INIT_RENDERMANUAL);
//    setbkcolor(WHITE);
    setbkcolor(0xD0DFE6);

//    cleardevice();
    inputVexNumber(g);
    inputAdjMatrix(g);
    closegraph();
}

void inputVexNumber(Graph &g) {
    cleardevice();
    sys_edit cinVertexNumber;
    char *vex = new char[20];
    *vex = '\0';

    setbkmode(TRANSPARENT);
    setcolor(BLACK);
    setfont(16, 0, "黑体");
    char label1[40] = "Input the number of vertex (1~20):";
    xyprintf(20, 50, label1);


    initEditBox(cinVertexNumber, false, 100, 100, 100, 20);
    char label[20] = "confirm";
    button btn_confirm(100, 150, label);
    btn_confirm.show();
    for (;is_run(); delay_fps(60)) {
        while (mousemsg()) {
            mouse_msg msg = getmouse();
            if (msg.is_left()) {
                if (msg.is_down()) {
                    if (btn_confirm.onClick()) {
                        cinVertexNumber.gettext(20, vex);
                        if (*vex != '\0') {
                            int vexNum = atoi(vex);
                            if (vexNum <= 0 || vexNum > 20) {
                                MessageBox(getHWnd(), (LPCSTR)"Incorrect input!", (LPCSTR)"warning", MB_OK | MB_ICONWARNING);
                                cinVertexNumber.settext("");
                                cinVertexNumber.setfocus();
                                continue;
                            }
                            g.setVertexNumber(vexNum);
//                            std::cout << g.vertexNumber << std::endl;
                            return;
                        }
                    }
                }
            }
        }
    }
}


void inputAdjMatrix(Graph& g) {
    cleardevice();
    sys_edit cinAdjMatrix;

    setbkmode(TRANSPARENT);
    setcolor(BLACK);
    setfont(16, 0, "黑体");
    char label1[40] = "Input Matrix of adjacency:";
    xyprintf(150, 20, label1);

    initEditBox(cinAdjMatrix, true, 20, 50, 250, 270);
    char *adj = new char[1024];
    *adj = '\0';
    char label[20] = "confirm";
    button btn_confirm(90, 340, label);
    btn_confirm.show();
    for (;is_run(); delay_fps(60)) {
        while(mousemsg()) {
            mouse_msg msg = getmouse();
            if (msg.is_left()) {
                if (msg.is_down()) {
                    if (btn_confirm.onClick()) {
                        cinAdjMatrix.gettext(1024, adj);
                        if (*adj != '\0') {
                            char *p = adj;
                            std::vector<std::vector<double>> matrix;
                            int count = 0;
                            std::cout << p << std::endl;
                            std::cout << g.vertexNumber << std::endl;
                            std::vector<double> row;
                            while(*p != '\0' || !matrix.empty()) {
                                if (isdigit(*p)) {
                                    double x = atof(p);
                                    row.push_back(x);
                                    count++;
                                } else if (*p == '\n' || *p == '\0') {
                                    matrix.push_back(row);
                                    std::vector<double> empty;
                                    row.swap(empty);
                                    if (*p == '\0') {
                                        break;
                                    }
                                }
                                *p++;
                            }
                            if (count != g.vertexNumber * g.vertexNumber) {
                                MessageBox(getHWnd(), (LPCSTR)"Incorrect input!", (LPCSTR)"warning", MB_OK | MB_ICONWARNING);
                                std::vector<std::vector<double>> empty;
                                matrix.swap(empty);
                                cinAdjMatrix.setfocus();
                            } else {
                                g.adjMatrix.swap(matrix);
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

