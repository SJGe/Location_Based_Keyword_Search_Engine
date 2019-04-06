#ifndef RTREE_H
#define RTREE_H

#include <iostream>
using namespace std;

class RTreeNode {
    double x;
    double y;
    RTreeNode **children;
    int size;

    RTreeNode();
};



#endif
