#include <iostream>
#include <sstream>
#include <cmath>
#include <mathfunc.cpp>

using namespace std;
double binomialpdf(int, int, double );
double binomialcdf(int, int, double );
double normalpdf(double, double, double);
double normalcdf(double, double, double);
double bernoullipdf(int, double);
double bernoullicdf(double, double);
double poissonpdf(int, double);
double poissoncdf(int, double);


int main(){
    return 0;
}

double binomialpdf(int k, int n, double p)
{
    return nchoosek(n, k)*pow(p,k)*pow(1-p, n-k);
}

double normalpdf(double x, double u, double s)
{
    return exp(-1*pow(x-u, 2)/(2 * pow(s,2)))*(1/sqrt(2*M_PI*pow(s,2)));
}

double bernoullicdf(int k, double p)
{
    if (p > 1 || p < 0)
    {
        throw std::invalid_argument( "the parameter for the bernoulli distribution should be in [0, 1]." );
    }
    if (k == 1)
    {
        return p;
    }
    else if (k == 0)
    {
        return 1-p;
    }
    else
    {
        cout << "Error, k must be an integer either 0 or 1" << endl;
        return 1;
    }
}

double poissonpdf(int x, double l)
{
    return exp(-1*l)*pow(l, x)/factorial(x);
}

double normalcdf(double x, double u, double s)
{
    return erf((x-u)/s);
} 

double poissoncdf(int x, double l)
{
    int i = 0;
    double sum = 0;
    double s = 1;
    for (i = 1; i <= x; i++)
    {
        s = s*l/i;
        sum += s;   
    };
    return sum*exp(-1*l);
}

double binomialcdf(int k, int n, double p)
{
    int i = 0;
    double sum = 0;
    for (i = 0; i < k; i++)
    {
        sum = sum + nchoosek(n, i)*pow(p,i)*pow(1-p, n-i);
    }
    return sum;
}

double bernoullipdf(int k, double p)
{
    if (k == 0)
    {
        return p;
    }
    else if (k == 1)
    {
        return 1-p;
    }
}