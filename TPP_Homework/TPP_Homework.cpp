#include<iostream>
#include<iomanip>
#include<ctime>
#include<math.h>
#include<cassert>

using namespace std;

    double z(double x1, double x2) {
        return pow(x1, 2) + 3 * pow(x2, 2);
    }
    double g1(double x1, double x2) {    //результат положителен только при x1=0 и x2=0. minz и minz1 не будут заданны
        return -x2 - 3 * pow(x1, 2) + 2;
    }
    double g2(double x1, double x2) {
        return x2 + x1 - 1;
    }
    double sum(double x1, double x2) {
        return x1 + x2;
    }

    //Tests
    void Test_z() {
        assert(z(2, 3) == 31);
        assert(z(3, 2) == 21);
        assert(z(0, 2) == 12);
        assert(z(2, 0) == 4);
        assert(z(0, 0) == 0);
        assert(z(2, -3) == 31);
        assert(z(-2, 3) == 31);
        assert(z(-2, -3) == 31);
        cout << "Test z OK" << endl;
    }
    void Test_g1() {
        assert(g1(2, 3) == -13);
        assert(g1(3, 2) == -27);
        assert(g1(0, 2) == 0);
        assert(g1(2, 0) == -10);
        assert(g1(0, 0) == 2);
        assert(g1(-2, 3) == -13);
        assert(g1(2, -3) == -7);
        assert(g1(-2, -3) == -7);
        cout << "Test g1 OK" << endl;
    }
    void Test_g2() {
        assert(g2(2, 3) == 4);
        assert(g2(3, 2) == 4);
        assert(g2(0, 2) == 1);
        assert(g2(2, 0) == 1);
        assert(g2(0, 0) == -1);
        assert(g2(-2, 3) == 0);
        assert(g2(2, -3) == -2);
        assert(g2(-2, -3) == -6);
        cout << "Test g2 OK" << endl;
    }
    void Test_sum() {
        assert(sum(2, 3) == 5);
        assert(sum(3, 2) == 5);
        assert(sum(0, 2) == 2);
        assert(sum(2, 0) == 2);
        assert(sum(0, 0) == 0);
        assert(sum(-2, 3) == 1);
        assert(sum(2, -3) == -1);
        assert(sum(-2, -3) == -5);
        cout << "Test sum OK" << endl;
    }

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    Test_z();
    Test_g1();
    Test_g2();
    Test_sum();

    int N, m = 0, m1 = 0, r , r1;     //r и r1 отсутствуют значения по умолчанию
    double x1a, x1b, x2a, x2b, minz, minz1, e, d, alfa;

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
                minz = Z[i];    //инициализация minz маловероятна
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
        if (g1(x1_1[i], x2_1[i]) >= 0 and g2(x1_1[i], x2_1[i])) { //отсутствует сравнение для g2
            Z1[i] = z(x1_1[i], x2_1[i]);
            if (sqrt(pow(Z[r] - Z1[i], 2)) <= alfa) {
                minz1 = Z1[i]; //инициализация minz1 маловероятна
                r1 = i;
                cout << "Условие по alfa тоже выполнено" << endl;
                goto metka;
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
metka:
    cout << "minz=" << minz << " " << "x1=" << x1[r] << " " << "x2=" << x2_1[r1] << endl;
    cout << "minz1=" << minz1 << " " << "x1_1=" << x1_1[r1] << " " << "x2_1=" << x2_1[r1] << endl;
    cout << "minz-minz1=" << sqrt(pow(Z[r] - Z[r1], 2)) << endl;



    system("pause");
    return 0;
}