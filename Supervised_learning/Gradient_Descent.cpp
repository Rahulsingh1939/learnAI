#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Gradient Descent for Univariate Linear Regression
double computeCost(const vector<double> &X, const vector<double> &Y, double w0, double w1)
{
    int m = X.size();
    double cost = 0.0;
    for (int i = 0; i < m; ++i)
    {
        double y_pred = w0 + w1 * X[i];
        cost += pow(y_pred - Y[i], 2);
    }
    return cost / (2 * m);
}

void gradientDescent(const vector<double> &X, const vector<double> &Y, double &w0, double &w1, double alpha, int iterations)
{
    int m = X.size();
    for (int iter = 0; iter < iterations; ++iter)
    {
        double dw0 = 0.0, dw1 = 0.0;
        for (int i = 0; i < m; ++i)
        {
            double y_pred = w0 + w1 * X[i];
            dw0 += (y_pred - Y[i]);
            dw1 += (y_pred - Y[i]) * X[i];
        }
        w0 -= alpha * dw0 / m;
        w1 -= alpha * dw1 / m;
        if (iter % 100 == 0)
        {
            cout << "Iteration " << iter << ": Cost = " << computeCost(X, Y, w0, w1) << endl;
        }
    }
}

int main()
{
    int m;
    cout << "Enter number of data points: ";
    cin >> m;
    vector<double> X(m), Y(m);
    cout << "Enter X and Y values:\n";
    for (int i = 0; i < m; ++i)
    {
        cin >> X[i] >> Y[i];
    }
    double w0 = 0.0, w1 = 0.0;
    double alpha = 0.01;
    int iterations = 1000;
    gradientDescent(X, Y, w0, w1, alpha, iterations);
    cout << "Final parameters: w0 = " << w0 << ", w1 = " << w1 << endl;
    double x;
    cout << "Enter x to predict y: ";
    cin >> x;
    cout << "Predicted y = " << w0 + w1 * x << endl;
    return 0;
}
