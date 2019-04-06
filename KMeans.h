//
// Created by shijig1 on 2019-03-20.
//

#ifndef KMEANS_KMEANS_H
#define KMEANS_KMEANS_H

#include <iostream>
using namespace std;

#define K 5
#define D 2

class Obj {
public:
    double *data;
    int clusterNum;
    Obj() {}
    Obj(double *data);
};

class KMeans {
private:
    Obj *objs;
    int size;

public:
    KMeans(double *data, int size);
    void clustering();

};



#endif //KMEANS_KMEANS_H
