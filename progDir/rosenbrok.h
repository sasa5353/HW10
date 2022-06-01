//
// Created by alex on 24.03.2020.
//

#ifndef TASK10_ROSENBROK_H
#define TASK10_ROSENBROK_H

#include "rungeKuttas.h"
#include "quad/Gauss.h"
#include "funcForRosenbrok.h"
#include "newtonsMethod.h"

const double alpha = (double) 1.077;
const double betta = (double) -0.372;
const double gamlet = (double) -0.577;

void rosenbrok(std::string);

#endif //TASK10_ROSENBROK_H
