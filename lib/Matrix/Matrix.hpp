#ifndef HTOOL_MATRIX_HPP
#define HTOOL_MATRIX_HPP
#if _OPENMP
#  include <omp.h>
#endif
#include <iostream>
#include "Generator.hpp"

class Matrix {
private:
    std::vector<int> data;
    IGenerator& generator;

public:
    Matrix(int n, IGenerator& generator0):data(n,0),generator(generator0){

        this->compute();

    }

    void compute(){
        #if _OPENMP
        #pragma omp parallel
        #endif
        {
            int tid = omp_get_thread_num();
            std::cout<<"Hello World from thread = "<<tid<<std::endl;
            std::vector<int>   local_data;
            #if _OPENMP
            #pragma omp for schedule(guided)
            #endif
            for(int i=0; i<data.size(); i++) {

                local_data.push_back(generator.compute(i));
            }
            #if _OPENMP
            #pragma omp critical
            #endif
            {
                data.insert(data.end(),local_data.begin(),local_data.end());
            }
        }
    }
};

#endif