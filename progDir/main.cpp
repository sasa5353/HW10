#include <iostream>
#include <fstream>
#include <sstream>
#include "func.h"
#include "rosenbrok.h"
#include "predictCorrector.h"

int main(int argc, char *argv[]) {
    std::srand(time(NULL));
    int variant =  - 1;
    if (argv[1]) {
        std::stringstream convert(argv[1]);
        convert >> variant;
    } else {
        std::cout << "Please, enter some number between 0 and 1." << std::endl;
    }
    
    std::ofstream out;
    out.setf(std::ios::scientific);
    out.precision(10);
    switch (variant) {
        case 0 : {
            rosenbrok("rosen.dat");
            break;
        }
        case 1 : {
            predictCorrector("precor.dat");
            break;
        }
        default : {
            std::cout << "Wrong argument! 0 - rosen, 1 - precor.";
        }
    }
    fclose (stdin);
    fclose (stdout);
    fclose (stderr);   
    return 0;
}
