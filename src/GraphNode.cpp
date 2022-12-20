//
// Created by lizhi on 2022/11/24.
//

#include "GraphNode.h"

GraphNode::GraphNode() {
//    this->b_label = new char[20];
//    memset(this->b_label, 0, 3 * sizeof(char));
    this->x = 0;
    this->y = 0;
    this->radius = 20;
    this->isVisible = false;
    this->red = 255;
    this->green = 255;
    this->blue = 255;
//    this->RGB = EGERGB(255, 255, 255);
}

GraphNode::GraphNode(int x, int y) {
//    this->b_label = new char[20];
//    memset(this->b_label, 0, 3 * sizeof(char));
    this->x = x;
    this->y = y;
    this->radius = 5;
    this->isVisible = false;
//    this->RGB = EGERGB(255, 255, 255);
    this->red = 255;
    this->green = 255;
    this->blue = 255;
}

GraphNode::GraphNode(int x, int y, int r) {
//    this->b_label = new char[20];
//    memset(this->b_label, 0, 3 * sizeof(char));
    this->x = x;
    this->y = y;
    this->radius = r;
    this->isVisible = false;
//    this->RGB = EGERGB(255, 255, 255);
    this->red = 255;
    this->green = 255;
    this->blue = 255;
}

//GraphNode::GraphNode(GraphNode &other) {
//    memset(this->b_label, 0, 3 * sizeof(char));
//    this->x = other.x;
//    this->y = other.y;
//    this->radius = other.radius;
//    this->isVisible = other.isVisible;
////    this->RGB = other.RGB;
//    this->red = other.red;
//    this->green = other.green;
//    this->blue = other.blue;
//}

GraphNode::~GraphNode() {
//    delete[] this->b_label;
}

void GraphNode::setXYR(int _x, int _y, int _radius) {
    this->x = _x;
    this->y = _y;
    this->radius = _radius;
}

void GraphNode::setRGB(BYTE R, BYTE G, BYTE B) {
//    this->RGB.red = R;
//    this->RGB.blue = G;
//    this->RGB.red = B;
//    this->RGB = EGERGB(R, G, B);
    this->red = R;
    this->blue = B;
    this->green = G;
}

void GraphNode::setVisibility(bool _visibility) {
    this->isVisible = _visibility;
}

void GraphNode::changeVisibility() {
    this->isVisible = !this->isVisible;
}

void GraphNode::setLabel(int _label) {
    this->label = _label;
}

//color_t GraphNode::getRGB() const {
//    return this->RGB;
//}

//void GraphNode::setString(char *_name) {
//    memcpy(this->b_label, _name, sizeof(_name));
//    memmove(this->b_label, _name, sizeof _name);
//    strcpy_s(this->b_label, sizeof(_name), _name);
//    char *p = this->b_label;
//    while (*_name != '\0') {
//        *p = *_name;
//        *p++;
//        *_name++;
//    }
//    *p = '\0';
//}


//color_t GraphNode::getFontColor() const {
//    return ~this->RGB;
//}


std::istream &operator>>(std::istream &is, Graph &g) {
    std::vector<std::vector<double>> adjMatrix;
    for (int i = 0; i < g.vertexNumber; i++) {
        std::vector<double> row;
        for (int j = 0; j < g.vertexNumber; j++) {
            double tmp;
            is >> tmp;
            row.emplace_back(tmp);
        }
        adjMatrix.emplace_back(row);
    }
    g.adjMatrix.swap(adjMatrix);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Graph &g) {
    std::cout << "adjMatrix:" << std::endl;
    std::cout << "        ";
    for (int i = 0; i < g.vertexNumber; i++) {
        std::cout << std::setw(8) << std::left << i + 1;
    }
    std::cout << std::endl;
    for (int i = 0 ; i < g.vertexNumber; i++) {
        std::cout << std::setw(8) << std::left << i + 1;
        for (int j = 0; j < g.vertexNumber; j++) {
            if (g.adjMatrix[i][j] == INFIN || g.adjMatrix[i][j] == 0) {
                std::cout << "        ";
            } else {
                std::cout << std::fixed << std::setprecision(2) << std::setw(8) << std::left << g.adjMatrix[i][j];
            }
        }
        std::cout << std::endl;
    }
    return os;
}
