#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float x[8] = {3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8};
    float y[8] = {2.527, 2.635, 2.655, 2.563, 2.361, 2.048, 1.638, 1.118};
    int length = sizeof(x)/sizeof(x[0]);
    double xi = 0;
    double yi = 0;
    double xi2 = 0;
    double xiyi = 0;
    double xi3 = 0;
    double xi4 = 0;
    double xi2yi = 0;
    double linQ = 0;
    double quadroQ = 0;

    cout << "xi" << "\t" << "yi" << "\t" << "xi2" << "\t" << "xi3" << "\t" << "xi4" << "\t" << "xiyi" << "\t" << "xi2yi" << endl;
    for(int i = 0; i < length; i++)
    {
        xi += x[i];
        yi += y[i];
        xi2 += x[i] * x[i];
        xiyi += x[i] * y[i];
        xi2yi += x[i] * x[i] * y[i];
        xi3 += x[i] * x[i] * x[i];
        xi4 += x[i] * x[i] * x[i] * x[i];

        cout << x[i] << "\t" << y[i] << "\t" << x[i] * x[i] << "\t" << x[i] * x[i] * x[i] << "\t" << x[i] * x[i] * x[i] * x[i] << "\t" << x[i] * y[i] << "\t" << x[i] * x[i] * y[i] << endl;
    }

    cout << "Sum xi" << "\t" <<"Sum yi" << "\t" << "Sum xi2" << "\t" << "Sum xi3" << "\t" << "Sum xi4" << "\t" << "Sum xiyi" << "\t" << "Sum xi2yi" << endl;
    cout << xi << "\t" << yi << "\t" << xi2 << "\t" << xi3 << "\t" << xi4 << "\t" << xiyi << "\t" << xi2yi << endl;

    double linb = (xiyi * xi - xi2*yi) / (xi * xi - xi2 * length);
    double lina = (yi - linb * length) / xi;
    double delta0 = (xi4 * xi2 * length + xi3 * xi * xi2 + xi2 * xi3 * xi - xi2 * xi2 * xi2 - xi4 * xi * xi - xi3 * xi3 * length);
    double delta1 = (xi2yi * xi2 * length + xi3 * xi * yi + xi2 * xiyi * xi - xi2 * xi2 * yi - xi2yi * xi * xi - xi3 * xiyi * length);
    double delta2 = (xi4 * xiyi * length + xi2yi * xi * xi2 + xi2 * xi3 * yi - xi2 * xiyi * xi2 - xi4 * xi * yi - xi2yi * xi3 * length);
    double delta3 = (xi4 * xi2 * yi + xi3 * xiyi * xi2 + xi2yi * xi3 * xi - xi2yi * xi2 * xi2 - xi4 * xiyi * xi - xi3 * xi3 * yi);
    double quadroa = delta1 / delta0;
    double quadrob = delta2 / delta0;
    double quadroc = delta3 / delta0;

    for(int i = 0; i < length; i++)
    {
        linQ += pow((y[i] - (lina * x[i]) - linb), 2);
        quadroQ += pow((y[i] - quadroa * x[i] * x[i] - quadrob * x[i] - quadroc),2);
    }

    cout << "Approksimirovali eksperimental'nye dannye linejnoj zavisimost'yu  y = " << lina << " " << "x + " << linb << " " << " c nevyazkoj Q = " << linQ << " " << " i kvadratichnoj zavisimost'yu y = " << quadroa << " " << "x2 + " << quadrob << " " << "x " << quadroc << " " << " c  nevyazkoj Q = " << quadroQ << endl;
    return 0;
}