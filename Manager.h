//
// Created by shijig1 on 2019-03-20.
//

#ifndef KMEANS_MANAGER_H
#define KMEANS_MANAGER_H

#include "KMeans.h"

class Manager {
    Cluster *clusters;

public:
    Manager();
    void readData();
    void search(string keyword, double x, double y);
    void randomSearch();

};

#endif //KMEANS_MANAGER_H