#ifndef _FDCL_CLEBSCH_GORDON_HPP
#define _FDCL_CLEBSCH_GORDON_HPP

#include <iostream>
#include <vector>
#include <math.h> // pow
#include <array>
#include <Eigen/Dense>

#include "fdcl_FFTSO3_matrix.hpp"
#include "fdcl_tictoc.hpp"

namespace fdcl
{
    class Clebsch_Gordon_complex;
    class Clebsch_Gordon_real;
}

class fdcl::Clebsch_Gordon_complex
{
    public:
        Clebsch_Gordon_complex(){};
        Clebsch_Gordon_complex(int l1, int l2);
        void init(int l1, int l2);
        ~Clebsch_Gordon_complex(){};
        int l1, l2;
        Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> C;

        double& operator()(int l, int m, int l1, int m1, int l2, int m2); 

        int row(int l, int m, int l1, int m1, int l2, int m2);
        int col(int l, int m, int l1, int m1, int l2, int m2);
        void assert_index(int l, int m, int l1, int m1, int l2, int m2);
        void compute_sub(int l, int m, int l1, int l2);
        void compute(int l1, int l2);
    protected:
        fdcl::FFTSO3_matrix_complex matrix2rsph(int );
};

class fdcl::Clebsch_Gordon_real : public fdcl::Clebsch_Gordon_complex
{
    public:
        Clebsch_Gordon_real(){};
        Clebsch_Gordon_real(int l1, int l2);
        void init(int l1, int l2);
        ~Clebsch_Gordon_real(){};

        Eigen::Matrix<std::complex<double>,Eigen::Dynamic,Eigen::Dynamic> c;
        Eigen::Matrix<std::complex<double>,Eigen::Dynamic,Eigen::Dynamic> X;
        complex<double>& operator()(int l, int m, int l1, int m1, int l2, int m2); 
        void compute(int l1, int l2);
        void print();
    private:
        void compute_0(int l1, int l2);
        void compute_sub_01(int l1, int m1, int l2, int m2, complex<double> ratio0, complex<double> ratio1);
        void compute_sub_23(int l1, int m1, int l2, int m2, complex<double> ratio2, complex<double> ratio3);

};

#endif
