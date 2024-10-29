#include <iostream>
#include <cmath>

using namespace std;

class Dot {
public:
    float x, y;

    Dot(): x(0), y(0) {}
    Dot(float x, float y): x(x), y(y) {}

    void input() {
        cin >> x >> y;
    }

    void output() const {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

class Segment {
public:
    Dot d1, d2;

    Segment(Dot d1, Dot d2): d1(d1), d2(d2) {}
    Segment() : d1(0, 0), d2(0, 0) {}
    Segment(float a1, float a2, float b1, float b2) : d1(a1, a2), d2(b1, b2) {
        if (a1 == b1 && a2 == b2) {
            cout << "Error: a and b are the same" << endl;
        }
    }

    void input() {
        cout << "First dot: ";
        d1.input();
        cout << "Second dot: ";
        d2.input();
    }

    void output() const {
        cout << "Segment: ";
        d1.output();
        d2.output();
    }

    float length() const {
        return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));
    }

    Dot mid_dot() const {
        return Dot((d1.x + d2.x) / 2, (d1.y + d2.y) / 2);
    }

    Dot intersection(const Segment &segment) const {
        float A1 = d2.y - d1.y;
        float B1 = d1.x - d2.x;
        float C1 = A1 * d1.x + B1 * d1.y;

        float A2 = segment.d2.y - segment.d1.y;
        float B2 = segment.d1.x - segment.d2.x;
        float C2 = A2 * segment.d1.x + B2 * segment.d1.y;

        float det = A1 * B2 - A2 * B1;

        if (det == 0) {
            return Dot(); // Return an empty dot if there's no intersection
        }
        float x = (B2 * C1 - B1 * C2) / det;
        float y = (A1 * C2 - A2 * C1) / det;
        return Dot(x, y);
    }
};

class Triangle {
public:
    Dot d1, d2, d3;

    Triangle() : d1(0, 0), d2(0, 0), d3(0, 0) {}
    Triangle(Dot d1, Dot d2, Dot d3) : d1(d1), d2(d2), d3(d3) {}

    void input() {
        cout << "Enter first dot: ";
        d1.input();
        cout << "Enter second dot: ";
        d2.input();
        cout << "Enter third dot: ";
        d3.input();
    }

    void output() const {
        cout << "Triangle vertices:" << endl;
        d1.output();
        d2.output();
        d3.output();
    }

    float perimeter() const {
        Segment s1(d1, d2), s2(d2, d3), s3(d3, d1);
        return s1.length() + s2.length() + s3.length();
    }

    float area() const {
        return abs((d1.x * (d2.y - d3.y) + d2.x * (d3.y - d1.y) + d3.x * (d1.y - d2.y)) / 2.0);
    }
};

int main() {
    Segment s1, s2;
    s1.input();
    s2.input();
    Dot intersection = s1.intersection(s2);
    cout << "Intersection: ";
    intersection.output();

    Triangle t;
    t.input();
    cout << "Triangle perimeter: " << t.perimeter() << endl;
    cout << "Triangle area: " << t.area() << endl;

    return 0;
}
