#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m;
    cin >> m;
    if (m <= 1)
    {
        cerr << "Need at least 2 data points." << endl;
        return 1;
    }
    vector<double> X(m), Y(m);
    double sumX = 0, sumY = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> X[i] >> Y[i];
        sumX += X[i];
        sumY += Y[i];
    }
    double avgX = sumX / m;
    double avgY = sumY / m;
    double covXY = 0, varX = 0;
    for (int i = 0; i < m; i++)
    {
        covXY += (X[i] - avgX) * (Y[i] - avgY);
        varX += (X[i] - avgX) * (X[i] - avgX);
    }
    if (varX == 0)
    {
        cerr << "Variance of X is zero. Cannot compute regression." << endl;
        return 1;
    }
    double w1 = covXY / varX;
    double w0 = avgY - w1 * avgX;
    cout << "w0 = " << w0 << ", w1 = " << w1 << endl;
    double x;
    cin >> x;
    cout << "y = " << w0 + w1 * x << endl;
    return 0;
}