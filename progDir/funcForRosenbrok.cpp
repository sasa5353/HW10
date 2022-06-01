//
// Created by alex on 24.03.2020.
//

#include "funcForRosenbrok.h"

double X_1_R[length];

double *f(double *X) {
    X_1_R[0] = X[1];
    X_1_R[1] = kappa * ((double) 1.0 - X[0] * X[0]) * X[1] - X[0];

    // X_1_R[0] = -0.05*X[0]+1.0e+1*X[1]*X[2];
    // X_1_R[1] = 0.05*X[0]-1.0e+1*X[1]*X[2]-(1.0e+2)*X[1];
    // // X_1_R[2] = (1.0e+2)*X[1];
    // X_1_R[0] = (double) 2.0 * X[0] - X[1] - X[2];
    // X_1_R[1] = (double) 2.0 * X[0] - X[1] - (double) 2.0 * X[2];
    // X_1_R[2] = (double) 2.0 * X[2] - X[0] + X[1];

    // X_1_R[0] = X[0];
    // X_1_R[1] = X[1];
    return X_1_R;
}
