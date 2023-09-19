#include"UnitTests.h"

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
    assert(g1(2, 3) == 11);
    assert(g1(3, 2) == 27);
    assert(g1(0, 2) == 0);
    assert(g1(2, 0) == 14);
    assert(g1(0, 0) == 2);
    assert(g1(-2, 3) == 11);
    assert(g1(2, -3) == 17);
    assert(g1(-2, -3) == 17);
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