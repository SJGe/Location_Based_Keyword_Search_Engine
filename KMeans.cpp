//
// Created by shijig1 on 2019-03-20.
//
#include "KMeans.h"


KMeans::KMeans(double *data, int size) {
    this->size = size;
    objs = new Obj[size];
    for(int i=0;i<size;i++) {
        objs[i].data = data;
        objs[i].clusterNum = -1;
    }
}

double KMeans::calDis(double *data1, double *data2) {
    double res = 0;
    for(int i=0;i<D;i++) {
        res += (data1[i]-data2[i]) * (data1[i]-data2[i]);
    }
    return res;
}

void KMeans::clustering() {
    double **center = new double*[K];
    for(int i=0;i<K;i++) {
        center[i] = new double[D];
    }
    // initial the center
    for(int i=0;i<K;i++) {
        center[i] = objs[(i*size)/K].data;
    }

    // true->changed, false->unchanged
    bool flag = false;
    do {
        flag = false;
        // seperate the objs into clusters
        for(int i=0;i<size;i++) {
            double minDis = INT_MAX;
            int old = objs[i].clusterNum;
            for(int j=0;j<K;j++) {
                double tmp = calDis(objs[i].data, center[j]);
                if(tmp < minDis) {
                    minDis = tmp;
                    objs[i].clusterNum = j;
                }
            }
            if(old != objs[i].clusterNum) flag = true;
        }

        // recalculate the center of cluster
        int *count = new int[K];
        for(int i=0;i<K;i++) {
            count[i] = 0;
            for(int j=0;j<D;j++)
                center[i][j] = 0;
        }
        for(int i=0;i<size;i++) {
            int choice = objs[i].clusterNum;
            count[choice]++;
            for(int j=0;j<D;j++) {
                center[choice][j] += objs[i].data[j];
            }
        }
        for(int i=0;i<K;i++) {
            for(int j=0;j<D;j++) {
                center[i][j] /= count[i];
            }
        }
    } while(flag);
}
