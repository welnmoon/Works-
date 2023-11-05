#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    Point(int x, int y) : x(x), y(y) {}
    Point(int x1, int x2, int y1, int y2) : x1(x1), x2(x2), y1(y1), y2(y2) {}

    double distanceBetween(int x1, int y1, int x2, int y2) {
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }

    double distanceStart() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    virtual void print() {
        cout << "point x: " << x << endl << "point y: " << y << endl;
    }

protected:
    int x;
    int y;
    int x1;
    int x2;
    int y1;
    int y2;
};

class DistanceBetweenClass : public Point {
public:
    DistanceBetweenClass(int x1, int x2, int y1, int y2) : Point(x1, x2, y1, y2) {}

    void print() override {
        cout << "x1: " << x1 << ", y1: " << y1 << ", x2: " << x2 << ", y2: " << y2 << endl;
    }
};

int main() {
    DistanceBetweenClass point(1, 2, 3, 4);
    point.print();

    double distanceToStart = point.distanceStart();
    cout << "Расстояние до начала координат: " << distanceToStart << endl;

    double distanceBetweenPoints = point.distanceBetween(1, 3, 2, 4);
    cout << "Расстояние между точками: " << distanceBetweenPoints << endl;

    return 0;
}
