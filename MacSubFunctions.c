/** ----------------------------------------------------------------
   This code was used for kinematic wave computation using the
   explicit-implicit MacCormack proposed by Ming-Hseng Tseng(2010)
   ------------------------------------------------------------- **/
#include <math.h>

/*  Cn is 1.49 for English unites (ft/s) while 1.0 for metric units(m/s) */
/*  Reference to Eq.5 */
double Mac_Get_alpha(double Manning,double Slope,double Cn, double Dx)
{
     double beta = 3./5.;
     double alpha = pow(Manning *pow(Dx,(double)(2./3.))/sqrt(Slope)/Cn, (double)beta);
     return alpha;
}

/*  ck is kinematic wave speed (also called kinematic celerity) */
/*  ck = dx/dt = ck=1/(alpha*beta*Power(Q,beta-1)), Reference to Eq.8 */
double Mac_Get_ck(double alpha,double Q)
{
    double beta=3./5.;
    return 1./(alpha*beta*pow(Q,beta-1));
}

/*  lambda=max(0,abs(ck)-dx/dt) */
/*  Reference to Eq.18 */
double Mac_Get_lambda(double ck,double dt, double dx)
{
    double lambda;
    lambda = (fabs(ck)-dx/dt);
    lambda = lambda < 0? 0: lambda;
    return lambda;
}

/*  A=alpha*pow(Q, beta),Q: m^3/s */
double Mac_Get_Q(double alpha, double A)
{
    double beta=3./5.;
    return pow(A/alpha,1/beta);
}

/*  A=alpha*pow(Q, beta),Q: m^3/s */
double Mac_Get_A(double alpha, double Q)
{
    double beta=3./5.;
    return alpha*pow(Q, beta);
}
