//
// Created by alex on 23.03.2020.
//

#ifndef TASK9_FUNC_H
#define TASK9_FUNC_H

const unsigned short length = 2; // порядок системы

const double a = (double) 0.0;
const double b = (double) 500.0;
const double h = 1e-2;
const unsigned long long n = 10;

const long long kappa = (double) 0.0;//5000000000.0;

const double X_0[length] = {(double) 1.0, (double) 1.0};//, (double) 1.0};

double *f(double, double *);

#endif //TASK9_FUNC_H
