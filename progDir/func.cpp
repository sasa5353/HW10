//
// Created by alex on 23.03.2020.
//

#include "func.h"

double X_1[length];

double *f(double t, double *X) {

    X_1[0] = X[1];
    X_1[1] = kappa * ((double) 1.0 - X[0] * X[0]) * X[1] - X[0];
    // X_1[0] = (double) 2.0 * X[0] - X[1] - X[2];
    // X_1[1] = (double) 2.0 * X[0] - X[1] - (double) 2.0 * X[2];
    // X_1[2] = (double) 2.0 * X[2] - X[0] + X[1];

    // X_1[0] =  -0.05 * X[0] + (double) 10000.0 * X[1] * X[2];
    // X_1[1] = 0.05 * X[0] - (double) 10000.0 * X[1] * X[2] - (double) (1.0e+7) * X[1];
    // X_1[2] = (double) (1.0e+7) * X[1];
    
    return X_1;
}
