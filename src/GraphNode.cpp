//
// Created by lizhi on 2022/11/24.
//

#include <GraphNode.h>

#include "public.h"

int GraphNode::nodeNumber = 0;

GraphNode::GraphNode() {
    this->adjInfo = 0;
    this->x = 0;
    this->y = 0;
    this->radius = 5;
    this->name = "undefined" + std::to_string(nodeNumber);
    this->isVisible = false;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    nodeNumber++;
}

GraphNode::GraphNode(int x, int y) {
    this->adjInfo = 0;
    this->x = x;
    this->y = y;
    this->radius = 5;
    this->name = "undefined" + std::to_string(nodeNumber);
    this->isVisible = false;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    nodeNumber++;
}

GraphNode::GraphNode(int x, int y, int r) {
    this->adjInfo = 0;
    this->x = x;
    this->y = y;
    this->radius = r;
    this->name = "undefined" + std::to_string(nodeNumber);
    this->isVisible = false;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    nodeNumber++;
}

GraphNode::GraphNode(GraphNode &other) {
    this->adjInfo = 0;
    this->x = other.x;
    this->y = other.y;
    this->radius = other.radius;
    if (other.name == "undefined" + std::to_string(nodeNumber - 1)) {
        this->name = "undefined" + std::to_string(nodeNumber);
    } else {
        this->name = other.name;
    }
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

void GraphNode::setString(std::string _name) {
    this->name = std::move(_name);
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




