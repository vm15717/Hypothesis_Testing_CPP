double powerof(double, double);
double newtonraphsonpow(double, double);
double exp(double);
double nchoosek(int, int);
int factorial(int);
double cos(double);
double sin(double);
double log(double);
double abs(double);

double powerof(double x, double y)
{
    if (y)
    {
        return newtonraphsonpow(x, y);
    }
    else
    {

    }
}
double newtonraphsonpow(double x, double y)
{
    double xnew = 0;
    double x = 0;
    while (abs(xnew-x) > 1.0E-14)
    {
        xnew = x - powerof(x, y)/powerof(x,y);
    }
}

double abs(double x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}

double exp(double x){
    double s = x;
    double sum = 0;
    for (int i = 1; s < -1.0E-14 || s > 1.0E-14; i++)
    {
        s = s/i;
        sum += s;
    }
    return sum;
}

double cos(double x){
    double s = 1;
    double sum = 1;
    for (int i = 1; s < -1.0E-14 || s > 1.0E-14; i++)
    {
        s = -s*x*x/((i+1)*i);
        sum += s;
    }
    return sum; 
}

double sin(double x){
    double s = x;
    double sum = x;
    for (int i = 1; s < -1.0E-14 || s > 1.0E-14; i++)
    {
        s = -s*x*x/((2*i+1)*(2*i));
        sum += s;
    }
    return sum; 
}


int factorial(int n){
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        int prod = 1;
        for (int i = 1; i <= n; i++)
        {
            prod = prod* i;
        }
        return prod;
    }
}



double nchoosek(int n, int k)
{
    double ret = 1;
    int n1 = n;
    int k1 = k;
    for(int i = k; i > 0; i--)
    {
        ret = n1/k1 * ret;
        n1 = n - 1;
        k1 = k - 1;
    }
    return ret;
}