//
// Created by alex on 19.03.2020.
//

#include "Gauss.h"

double *gaussMod(double **a, double *b, int n) {
    double *x, maxVal;
    const double eps = 1.0e-15;
    x = new double[n];
    double tmp;
    int indexOfMaxVal;

    double *xTemp = new double[n];
    double **matrix = new double *[n];
    for (int i = 0; i < n; i++ ) {
        matrix[i] = new double[n];
        for (int j = 0; j < n; j++ ) {
            matrix[i][j] = a[i][j];
        }
        xTemp[i] = b[i];
    }

    // int *otv = new int[n + 1]; //Отвечает за порядок корней
    // //Сначала все корни по порядку
    // for (int i = 0; i <= n; i++ ) {
    //     otv[i] = i;
    // }
    // for (int i = 0; i < n; i++ ) {
    //     matrix[i] = new double[n + 1];
    //     for (int j = 0; j < n; j++ ) {
    //         matrix[i][j] = a[i][j];
    //     }
    //     matrix[i][n] = b[i];
    // } 

    // //Прямой ход метода Гаусса
    // for (int k = 0; k < n; k++) { //На какой позиции должен стоять главный элемент
    //     int i_max = k, j_max = k; //Установка главного элемента
    //     //Ищем максимальный по модулю элемент
    //     for (int i = k; i < n; i++) {
    //         for (int j = k; j < n; j++) {
    //             if (fabs( matrix[i_max][j_max]) < fabs(matrix[i][j])) {
    //                 i_max = i;
    //                 j_max = j;
    //             }
    //         }
    //     }
        
    //     for (int j = k; j < n + 1; j++) {
    //         tmp = matrix[k][j];
    //         matrix[k][j] = matrix[i_max][j];
    //         matrix[i_max][j] = tmp;
    //     }
    //     //Переставляем столбцы
    //     for (int i = 0; i < n; i++) {
    //         tmp = matrix[i][k];
    //         matrix[i][k] = matrix[i][j_max];
    //         matrix[i][j_max] = tmp;
    //     }
    //     //Учитываем изменение порядка корней
    //     int tempor = otv[k];
    //     otv[k] = otv[j_max];
    //     otv[j_max] = tempor;
    //     for (int j = n; j >= k; j--) {
    //         matrix[k][j] /= matrix[k][k];
    //     }
    //     for (int i = k + 1; i < n; i++) {
    //         for (int j = n; j >= k; j--) {
    //             matrix[i][j] -= matrix[k][j] * matrix[i][k];
    //         }
    //     }
    // }
    // //Обратный ход
    // for (int i = 0; i < n; i++) {
    //     x[i] = matrix[i][n];
    // }
    // for (int i = n - 2; i >= 0; i--) {
    //     for (int j = i + 1; j < n; j++) {
    //         x[i] -= x[j] * matrix[i][j];
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     xTemp[i] = x[i];
    // }
    // //Вывод результата
    // for (int i = 0; i < n; i++) {
    //     x[otv[i]] = xTemp[i];
    // }
    // delete[] otv;
    // delete[] xTemp;
    

    for (int i = 0; i < n; i++) {
        // maxVal = fabs(matrix[i][i]);
        // indexOfMaxVal = i;
        // for (int j = i + 1; j < n; j++) {
        //     if (fabs(matrix[j][i]) > maxVal) {
        //         maxVal = fabs(matrix[j][i]);
        //         indexOfMaxVal = j;
        //     }
        // }
        
        // for (int j = 0; j < n; j++) {
        //     tmp = matrix[i][j];
        //     matrix[i][j] = matrix[indexOfMaxVal][j];
        //     matrix[indexOfMaxVal][j] = tmp;
        // }
        // tmp = xTemp[i];
        // xTemp[i] = xTemp[indexOfMaxVal];
        // xTemp[indexOfMaxVal] = tmp;
        for (int j = i; j < n; j++) {
            tmp = matrix[j][i];
            if (fabs(tmp) > eps) {
                for (int k = 0; k < n; k++) {
                    matrix[j][k] /= tmp;
                }
                xTemp[j] /= tmp;
                if (i != j) {
                    for (int k = 0; k < n; k++) {
                        matrix[j][k] -= matrix[i][k];
                    }
                    xTemp[j] -= xTemp[i];
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        x[i] = xTemp[i];
        for (int j = 0; j < i; j++) {
            xTemp[j] -= matrix[j][i] * x[i];
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] xTemp;
    return x;
}
