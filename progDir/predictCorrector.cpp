//
// Created by alex on 24.03.2020.
//

#include "predictCorrector.h"


double *X_i;
double *tmp;
double *B;
double t_i;


void predictCorrector(std::string s) {
    double A[n];
    A[0] = (double) 1.0 / fact(n - 1);
    for (long long unsigned i = 1; i < n; i++) {
        A[i] = -A[i - 1] * ((double) (n - i)) / (double) i;
    }
    for (unsigned int i = 0; i < n; i++) {
        A[i] *= integralForAdams(i, false);
    }
    
    double C[n];
    B = C + 1;
    B[-1] = (double) 1.0 / fact(n - 1);
    for (long long unsigned i = 0; i < n - 1; i++) {
        B[i] = -B[i - 1] * ((double) (n - 1 - i)) / (double) (i + 1);
    }
    for (int i = -1; i < ((long long ) (n)) - 1; i++) {
        B[i] *= integralForAdams(i, true);
    }
    rungeKuttas(s, true, false);
    double t_i;
    std::ifstream in;
    in.open(s);
    const unsigned long long p = ((b - a) / h);
    const int devid = n;
    double **X;
    X = new double *[devid];
    for (long long unsigned i = 0; i < devid; i++) {
        in >> t_i;
        X[i] = new double[length];
        for (int j = 0; j < length; j++) {
            in >> X[i][j];
        }
    }
    in.close();
    std::ofstream out;
    out.setf(std::ios::scientific);
    out.precision(10);
    out.open(s, std::ios::app);
    tmp = new double[length];
    double *X_i_1;
    X_i_1 = new double[length];
    for (long long unsigned i = devid - 1; i < p; i++) {
        for (int j = 0; j < length; j++) {
            tmp[j] = 0.0;
        }
        for (long long unsigned j = 0; j < devid; j++) {
            t_i = a + (i - j) * h;
            for (int k = 0; k < length; k++) {
                tmp[k] += A[j] * f(t_i, X[(i - j) % devid])[k];
            }
        }
        for (int j = 0; j < length; j++) {
            X_i_1[j] = X[i % devid][j] + h * tmp[j];
            tmp[j] = 0.0;
        }
        for (long long unsigned j = 0; j < n - 1; j++) {
            t_i = a + (i - j) * h;
            for (int k = 0; k < length; k++) {
                tmp[k] += B[j] * f(t_i, X[(i - j) % devid])[k];
            }
        }
        t_i = a + i * h;
        X_i = X[i % devid];
        delete[] X[(i + 1) % devid];
        X[(i + 1) % devid] = newtonMethod(funcForPredict, X_i_1, 10);
        t_i = a + (i + 1) * h;
        out << t_i << " ";
        for (int j = 0; j < length; j++) {
            out << X[(i + 1) % devid][j] << " ";
        }
        out << std::endl;
    }
    delete[] tmp;
    delete[] X_i_1;
    out.close();
    for (long long unsigned i = 0; i < devid; i++) {
        delete[] X[i];
    }
    delete[] X;
    // return X;
}

double fact(unsigned int p) {
    return (p == 0) ? 1 : p * fact(p - 1);
}

double Y[n];
double *funcForPredict(double *X) {
    for (int j = 0; j < length; j++) {
        Y[j] = X_i[j] + h * tmp[j] + h * B[-1] * f(t_i + h, X)[j] - X[j];
    }
    return Y;
};
