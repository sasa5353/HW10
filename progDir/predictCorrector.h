//
// Created by alex on 24.03.2020.
//

#ifndef TASK10_PREDICTCORRECTOR_H
#define TASK10_PREDICTCORRECTOR_H

#include "quadGauss.h"
#include "rungeKuttas.h"
#include "newtonsMethod.h"

void predictCorrector(std::string);
double fact(unsigned int);
double *funcForPredict(double *);

#endif //TASK10_PREDICTCORRECTOR_H
