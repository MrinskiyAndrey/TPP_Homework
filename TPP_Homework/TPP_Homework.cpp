#include"UnitTests.h"

    double z(double x1, double x2) {
        return pow(x1, 2) + 3 * pow(x2, 2);
    }
    double g1(double x1, double x2) {    
        return -x2 + 3 * pow(x1, 2) + 2;
    }
    double g2(double x1, double x2) {
        return x2 + x1 - 1;
    }
    double sum(double x1, double x2) {
        return x1 + x2;
    }   

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    Test_z();
    Test_g1();
    Test_g2();
    Test_sum();

    int N, m = 0, m1 = 0, r = 0, r1 = 0;
    double x1a, x1b, x2a, x2b, minz=0, minz1=0, e, d, alfa;

    cout << "N=";
    cin >> N;
    cout << "x1a=";
    cin >> x1a;
    cout << "x1b=";
    cin >> x1b;
    cout << "x2a=";
    cin >> x2a;
    cout << "x2b=";
    cin >> x2b;
    cout << "e=";
    cin >> e;
    cout << "alfa=";
    cin >> alfa;

    double* x1 = new double[N];
    double* x2 = new double[N];
    double* Z = new double[N];
    double* Z1 = new double[N];
    double* x1_1 = new double[N];
    double* x2_1 = new double[N];

    for (int i = 0; i < N; i++)
    {
        x1[i] = ((x1b - x1a) * ((double)rand() / RAND_MAX)) + x1a;
        x2[i] = ((x2b - x2a) * ((double)rand() / RAND_MAX)) + x2a;
        if (g1(x1[i], x2[i]) >= 0 and g2(x1[i], x2[i]) >= 0)
        {
            Z[i] = z(x1[i], x2[i]);
            if (m < 1) {
                minz = Z[i];
                m = m + 1;
            }
            if (minz > Z[i]) {
                r = i;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        x1_1[i] = (((x1[r] + e) - (x1[r] - e)) * ((double)rand() / RAND_MAX)) + (x1[r] - e);
        x2_1[i] = (((x2[r] + e) - (x2[r] - e)) * ((double)rand() / RAND_MAX)) + (x2[r] - e);
        if (g1(x1_1[i], x2_1[i]) >= 0 and g2(x1_1[i], x2_1[i]) >= 0) { 
            Z1[i] = z(x1_1[i], x2_1[i]);
            if (Z[r] - Z1[i] <= alfa) { 
                minz1 = Z1[i];
                r1 = i;
                cout << "Условие по alfa тоже выполнено" << endl;
                break;
            }
            if (m1 < 1) {
                minz1 = Z1[i];     
                m1 = m + 1;
            }
            if (minz1 > Z1[i]) {
                minz1 = Z1[i];
                r1 = i;
            }
        }
    }

    if (minz!=0 && minz1!=0)
    {
        cout << "minz=" << minz << " x1=" << x1[r] << " x2=" << x2_1[r1] << endl;
        cout << "minz1=" << minz1 << " x1_1=" << x1_1[r1] << " x2_1=" << x2_1[r1] << endl;
        cout << "minz-minz1=" << minz - minz1 << endl;
    }
    else
    {
        cout << "minz и minz1 не определены" << endl;
    }
    system("pause");
    return 0;
}