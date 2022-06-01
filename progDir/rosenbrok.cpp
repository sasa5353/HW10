//
// Created by alex on 24.03.2020.
//

#include "rosenbrok.h"

void rosenbrok(std::string s) {
    std::ofstream out;
    out.setf(std::ios::scientific);
    out.precision(15);
    out.open(s);
    const unsigned long long p = (b - a) / h;
    const int devid = 2;
    double **X;
    X = new double *[devid];
    for (int i = 0; i < devid; i++) {
        X[i] = new double[length];
    }
    for (int i = 0; i < length; i++) {
        X[0][i] = X_0[i];
    }
    double t_i = a;
    out << t_i << " ";
    for (int j = 0; j < length; j++) {
        out << X[0][j] << " ";
    }
    out << std::endl;
    
    
    double tmp[length];
    double **jacobiMatrix;
    double jacobiSquare[length][length];
    double *vector = new double[length];
    double **matrix = new double *[length];
    double E[length][length];
    for (int i = 0; i < length; i++) {
        matrix[i] = new double[length];
        for (int j = 0; j < length; j++) {
            E[i][j] = (double) ((i == j)? (double) 1.0: (double) 0.0);
        }
    }
    // double t_i;
    for (long long unsigned i = 0; i < p; i++) {
        // X[i + 1] = new double[length];
        t_i = a + h * i;
        jacobiMatrix = jacobi(f, X[i % devid]);
        for (int j = 0; j < length; j++) {
            for (int k = 0; k < length; k++) {
                jacobiSquare[j][k] = (double) 0.0;
            }
        }
        for (int j = 0; j < length; j++) {
            for (int k = 0; k < length; k++) {
                for (int l = 0; l < length; l++) {
                    jacobiSquare[j][k] += jacobiMatrix[j][l] * jacobiMatrix[l][k];
                }
            }
        }
        for (int j = 0; j < length; j++) {
            for (int k = 0; k < length; k++) {
                matrix[j][k] = E[j][k] -alpha * h * jacobiMatrix[j][k] -betta * h * h * jacobiSquare[j][k];
            }
        }
        for (int j = 0; j < length; j++) {
            delete[] jacobiMatrix[j];
            vector[j] = X[i % devid][j] + gamlet * h * f(X[i % devid])[j];
        }
        delete[] jacobiMatrix;
        delete[] X[(i + 1) % devid];
        
        X[(i + 1) % devid] = gaussMod(matrix, f(vector), length);
        // for (int j = 0; j < length; j++) {
        //     tmp[j] = f(vector)[j];
        //     for (int k = 0; k < length; k++) {
        //         tmp[j] -= matrix[j][k] * X[(i + 1) % devid][k];
        //     }
        // }
        // std::cout << sqrt(tmp[0] * tmp[0] + (tmp[1] * tmp[1])) << std::endl;
        // printf("<\\---- %llu ----\n", i);
        // std::cout << "jacobiMatrix" << std::endl;
        // for (int j = 0; j < length; j++) {
        //     for (int k = 0; k < length; k++) {
        //         std::cout << jacobiMatrix[j][k] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << "matrix" << std::endl;
        // for (int j = 0; j < length; j++) {
        //     for (int k = 0; k < length; k++) {
        //         std::cout << matrix[j][k] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << "gaussMod" << std::endl;
        // for (int j = 0; j < length; j++) {
        //     std::cout << X[(i + 1) % devid][j] << " ";
        //     std::cout << std::endl;
        // }
        
        // printf("---- %llu ----\\>\n", i);
        
        
        for (int j = 0; j < length; j++) {
            X[(i + 1) % devid][j] *= h;
            X[(i + 1) % devid][j] += X[i % devid][j];
        }
        t_i += h;
        out << t_i << " ";
        for (int j = 0; j < length; j++) {
            out << X[(i + 1) % devid][j] << " ";
        }
        out << std::endl;
    }

    delete[] vector;

    for (int i = 0; i < length; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    for (long long unsigned i = 0; i < devid; i++) {
        delete[] X[i];
    }
    out.close();
    delete[] X;

    // return X;
}
