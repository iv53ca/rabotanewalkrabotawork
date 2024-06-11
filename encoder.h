#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
//double diracDelta(double t) {
//    if (t == 0) {
//        return INFINITY; // Дельта-функция Дирака в t=0 равна бесконечности
//    } else {
//        return 0.0; // Дельта-функция Дирака равна нулю при t != 0
//    }
//}

double encoder_transfer_function(double lambda0, double f0, double N, double R, double D, double Di, double Do, double L, double delta_L, double ne, double ns, int i, int k, double f){
    // defines the complex i
    std::complex<double> I(0.0, 1.0);
    // sound velocity
    double c = 330000;
    double delta_tau = ne * delta_L / c;
    std::complex<double> H_i_k_f = 0;
    if(std::abs(std::sin(3.1415 * ((i + k) / N + delta_tau * f))) < 0.01){
        H_i_k_f = 16.05;
    }
    else{
        H_i_k_f = std::exp(-I * 2.0 * 3.1415 * ne * L / c * f) * std::exp(-I * 3.1415 * ((i + k) / N + delta_tau * f) * (N - 1)) * std::sin(3.1415 * (i + k + N + N * delta_tau * f)) / std::sin(3.1415 * ((i + k) / N + delta_tau * f));
    }
    std::complex<double> H_i_k_f_conjugate = std::conj(H_i_k_f);
    std::complex<double> HH_i_k_f = H_i_k_f * H_i_k_f_conjugate;

    return (HH_i_k_f.real());
}

std::vector<double> impulse_intensity(double lambda0, double f0, double N, double R, double D, double Di, double Do, double L, double delta_L, double ne, double ns, int i, int k, double F){

    double df = 0.0001 * pow(10, 8);

    std::vector<double> f_mass(int(F/df) + 1);
    std::vector<double> intensity_mass(int(F/df) + 1);

    for(size_t e = 0; e < f_mass.size(); e++){
        f_mass[e] = e * df;
        intensity_mass[e] = encoder_transfer_function(lambda0, f0, N, R, D, Di, Do, L, delta_L, ne, ns, i, k, f_mass[e]);
    }

    return(intensity_mass);
}