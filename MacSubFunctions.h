#ifndef MACSUBFUNCTIONS_H_INCLUDED
#define MACSUBFUNCTIONS_H_INCLUDED

double Mac_Get_alpha(double Manning, double Slope,double Cn, double Dx);
double Mac_Get_ck(double alpha,double Q);
double Mac_Get_lambda(double ck,double dt, double dx);
double Mac_Get_Q(double alpha, double A);
double Mac_Get_A(double alpha, double Q);


#endif // MACSUBFUNCTIONS_H_INCLUDED
