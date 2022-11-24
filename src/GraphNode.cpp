//
// Created by lizhi on 2022/11/24.
//

#include "GraphNode.h"

int GraphNode::nodeNumber = 0;

GraphNode::GraphNode() {
    memset(this->name, 0, sizeof(this->name));
    this->adjInfo = 0;
    this->x = 0;
    this->y = 0;
    this->radius = 5;
    itoa(nodeNumber * - 1, this->name, 10);
    this->isVisible = false;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    nodeNumber++;
}

GraphNode::GraphNode(int x, int y) {
    memset(this->name, 0, sizeof(this->name));
    this->adjInfo = 0;
    this->x = x;
    this->y = y;
    this->radius = 5;
    itoa(nodeNumber * - 1, this->name, 10);
    this->isVisible = false;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    nodeNumber++;
}

GraphNode::GraphNode(int x, int y, int r) {
    memset(this->name, 0, sizeof(this->name));
    this->adjInfo = 0;
    this->x = x;
    this->y = y;
    this->radius = r;
    itoa(nodeNumber * - 1, this->name, 10);
    this->isVisible = false;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    nodeNumber++;
}

GraphNode::GraphNode(GraphNode &other) {
    memset(this->name, 0, sizeof(this->name));
    this->adjInfo = 0;
    this->x = other.x;
    this->y = other.y;
    this->radius = other.radius;
    itoa(nodeNumber * - 1, this->name, 10);
    this->isVisible = other.isVisible;
    this->red = other.red;
    this->green = other.green;
    this->blue = other.blue;
    nodeNumber++;
}

GraphNode::~GraphNode() {
    nodeNumber--;
}

void GraphNode::setXYR(int _x, int _y, int _radius) {
    this->x = _x;
    this->y = _y;
    this->radius = _radius;
}

void GraphNode::setRGB(int R, int G, int B) {
    this->red = R;
    this->green = G;
    this->blue = B;
}

void GraphNode::setVisibility(bool _visibility) {
    this->isVisible = _visibility;
}

void GraphNode::changeVisibility() {
    this->isVisible = !this->isVisible;
}

color_t GraphNode::getRGB() {
    return EGERGB(this->red, this->green, this->blue);
}

void GraphNode::setString(char *_name) {
    memcpy(this->name, _name, sizeof(_name));
}

bool GraphNode::operator==(const int adj) const {
    return this->adjInfo == adj;
}

std::istream &operator>>(std::istream &in, GraphNode &G) {
    in >> G.adjInfo;
    return in;
}

std::ostream &operator<<(std::ostream &out, GraphNode &G) {
    out << G.adjInfo;
    return out;
}

GraphNode &GraphNode::operator=(int adj) {
    this->adjInfo = adj;
    return *this;
}

color_t GraphNode::getFontColor() const {
    return EGERGB(255-this->red, 255-this->green, 255-this->blue);
}




