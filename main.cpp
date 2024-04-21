#include <iostream>
#include <complex>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
    if(argc < 3) {
        std::cout << "Error: must include arguments for size and iterations respectively";
        return 1;
    }
    // gets the input from the command line for size (fractal will have 1:1 resolution)
    // and gets the input for the number of iterations
    char *endptr;
    int size = strtol(argv[1], &endptr, 10);
    int iterations = strtol(argv[2], &endptr, 10);

    // creates default cooridnates for fractal
    double start_real = -1.5, curr_real;
    double start_imag = 1.0, curr_imag;
    double range = 2.0;

    curr_imag = start_imag;
    for(int i =0; i < size; i++) {
        curr_real = start_real;
        for(int j =0; j < size*2; j++) {
            int color = 30;
            std::complex<double> z(curr_real,curr_imag);
            std::complex<double> c = z;
            for(int k=0; k < iterations; k++) {
                z = z*z + c;
                if(std::abs(z) > 2.0) {
                    color = (k % 8) + 31;
                    //std::cout << "\033[" << color << "m@ \033[0m";
                    break;
                }
            }
            std::stringstream str;
            str << "\033[" << color << "m\u2588\033[0m";
            std::cout << str.str();
            curr_real += range/(static_cast<double>(size)*2-1);
        }
        std::cout<< std::endl;
        curr_imag -= range/(static_cast<double>(size)-1);
    }
    return 0;
}
