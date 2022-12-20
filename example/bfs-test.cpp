//
// Created by lizhi on 2022/12/19.
//

#include "public.h"
int main() {

    initgraph(600, 600);
    std::vector<std::pair<int, int>> operation{};
    setbkcolor(WHITE);
    Graph g = CreateGraph();
    showGraph(g);
//    getch();
    bfs(g, operation);
    std::cout << "bfs finish" << std::endl;
    std::cout << g << std::endl;
    int index = 0;
    for (auto each : operation) {
        std::cout << each.first << " " << each.second << std::endl;
    }
    std::cout << "operation finish" << std::endl;
    for (auto &each : g.nodes) {
        each.setVisibility(false);
    }
    getch();
    for (; is_run(); delay_fps(60)) {
//        cleardevice();
        while (kbmsg()) {
            key_msg keyMsg = getkey();
            if (keyMsg.key == key_A && keyMsg.msg == key_msg_down) {
                nextStep(g, operation, index);
            } else if (keyMsg.key == key_Z  && keyMsg.msg == key_msg_down) {
                prevStep(g, operation, index);
            }
        }
    }
//    while (kbhit()) {
//        int ch = getch();
//        switch (ch) {
//            case 's': {
//                if (index >= operation.size()) {
//                    break;
//                }
//                int start = operation[index++].first, end = operation[index++].second;
//                g.nodes[start].setVisibility(true);
//                g.nodes[end].setVisibility(true);
//                cleardevice();
//                drawNodes(g);
//            }
//                break;
//            case 'b': {
//                if (index <= 0) break;
//                int end = operation[index++].second;
//                g.nodes[end].setVisibility(false);
//                cleardevice();
//                drawNodes(g);
//            }
//                break;
//        }
//    }
    getch();
    closegraph();
    return 0;
}