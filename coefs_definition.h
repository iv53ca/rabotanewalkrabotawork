#pragma once
#include <iostream>

double a31(double Ka, double l1, double l2, double J){
    return(-Ka * l1 / (J * (l1 + l2)));
}
double a32(double Ka, double l1, double l2, double J){
    return(Ka * l1 / (J * (l1 + l2)));
}
double a33(double b1, double L, double M, double l1, double l2, double J){
    return(-b1 * L / (M * (l1 + l2))) - b1 * L * pow(l1,2) / (J * (l1 + l2));
}
double a34(double b2, double L, double M, double l1, double l2, double J){
    return(-b2 * L / (M * (l1 + l2))) + b2 * L * l1 * l2 / (J * (l1 + l2));
}
double a35(double kt1, double L, double M, double l1, double l2, double J){
    return(kt1 * L / (M * (l1 + l2))) + kt1 * L * pow(l1, 2) / (J * (l1 + l2));
}
double a36(double kt2, double L, double M, double l1, double l2, double J){
    return(kt2 * L / (M * (l1 + l2))) - kt2 * L * l1 * l2 / (J * (l1 + l2));
}
double a41(double Ka, double l1, double l2, double J){
    return(Ka * l2 / (J * (l1 + l2)));
}
double a42(double Ka, double l1, double l2, double J){
    return(-Ka * l2 / (J * (l1 + l2)));
}
double a43(double b1, double L, double M, double l1, double l2, double J){
    return(-b1 * L / (M * (l1 + l2))) + b1 * L * l1 * l2 / (J * (l1 + l2));
}
double a44(double b2, double L, double M, double l1, double l2, double J){
    return(-b2 * L / (M * (l1 + l2))) - b2 * L * pow(l2, 2) / (J * (l1 + l2));
}
double a45(double kt1, double L, double M, double l1, double l2, double J){
    return(kt1 * L / (M * (l1 + l2))) - kt1 * L * l1 * l2 / (J * (l1 + l2));
}
double a46(double kt2, double L, double M, double l1, double l2, double J){
    return(kt2 * L / (M * (l1 + l2))) + kt2 * L * pow(l2, 2) / (J * (l1 + l2));
}
double j(double M, double l1, double l2){
    return(M * (pow(l1, 2) - l1 * l2 + pow(l2, 2)) / 3);
}

