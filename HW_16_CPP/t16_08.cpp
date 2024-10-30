#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

struct Dot {
    double x, y;
};

class Figure {
public:
    virtual ~Figure() = default;

    [[nodiscard]] virtual double area() const = 0;

    [[nodiscard]] virtual double perimeter() const = 0;
};

class Rectangle : public Figure {
    Dot left_upper, right_lower;

    double width{}, height{}; // width and height of the rectangle

    static inline double calculate_delta(double x, double y) {
        return abs(x - y);
    }

    void set_width_height(Dot a, Dot b) {
        this->width = calculate_delta(a.x, b.x);
        this->height = calculate_delta(a.y, b.y);
    }
public:
    Rectangle(double x1, double y1, double x2, double y2): left_upper({x1, y1}), right_lower({x2, y2}) {
        set_width_height(left_upper, right_lower);
    }
    Rectangle(Dot a, Dot b): left_upper(a), right_lower(b) {
        set_width_height(a, b);
    }

    [[nodiscard]] double inline area() const override {
        return width * height;
    }

    [[nodiscard]] double inline perimeter() const override {
        return (width + height) * 2;
    }

    [[nodiscard]] double inline get_width() const {
        return this->width;
    }

    [[nodiscard]] double inline get_height() const {
        return this->height;
    }
};

class Triangle: public Figure {
    Dot vertexes[3]{};
    double side1{}, side2{}, side3{}; // sides of the triangle

    void init_vertexes(Dot x, Dot y, Dot z) {
        vertexes[0] = x;
        vertexes[1] = y;
        vertexes[2] = z;
    }

    void set_sides() {
        side1 = calc_distance(vertexes[0], vertexes[1]);
        side2 = calc_distance(vertexes[1], vertexes[2]);
        side3 = calc_distance(vertexes[2], vertexes[0]);
    }

    static double calc_distance(Dot a, Dot b) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }

public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        init_vertexes({x1, y1}, {x2, y2}, {x3, y3});
        set_sides();
    }

    Triangle(Dot x, Dot y, Dot z) {
        init_vertexes(x, y, z);
        set_sides();
    }

    [[nodiscard]] double inline area() const override {
        double half_perimeter = perimeter() / 2;

        return sqrt(half_perimeter * (half_perimeter - side1) * (half_perimeter - side2) * (half_perimeter - side3));
    }

    [[nodiscard]] double inline perimeter() const override {
        return side1 + side2 + side3;
    }

    [[nodiscard]] double inline get_side1() const {
        return this->side1;
    }

    [[nodiscard]] double inline get_side2() const {
        return this->side2;
    }

    [[nodiscard]] double inline get_side3() const {
        return this->side3;
    }
};

class Pentagon : public Figure {
    Dot vertexes[5]{};
    double side[5]{}; // sides of the pentagon

    void init_vertexes(Dot a, Dot b, Dot c, Dot d, Dot e) {
        vertexes[0] = a;
        vertexes[1] = b;
        vertexes[2] = c;
        vertexes[3] = d;
        vertexes[4] = e;
    }

    void sort_vertexes() {
        // sort vertexes by distance: a -> b -> c -> d -> e -> a
        vector<Dot> sorted(5);
        sorted[0] = vertexes[0];

        vector<bool> visited(5, false);
        visited[0] = true;

        for(int i = 0; i < 4; i++) {
            int min_index = -1;
            double min_distance = numeric_limits<double>::max();

            for (int j = 0; j < 5; j++) {
                if (!visited[j]) {
                    double curr_distance = calc_distance(sorted[i], vertexes[j]);

                    if (curr_distance < min_distance) {
                        min_index = j;
                        min_distance = curr_distance;
                    }
                }
            }
            visited[min_index] = true;
            sorted[i + 1] = vertexes[min_index];
        }

        for (int i = 0; i < 5; i++) {
            vertexes[i] = sorted[i];
        }
    }

    static double inline calc_distance(Dot a, Dot b) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }

    static double cross_product(const Dot &a, const Dot &b, const Dot &c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

public:
    Pentagon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x5, double y5) {
        init_vertexes({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}, {x5, y5});
        sort_vertexes();
    }

    Pentagon(Dot a, Dot b, Dot c, Dot d, Dot e) {
        init_vertexes(a, b, c, d, e);
        sort_vertexes();
    }

    [[nodiscard]] bool is_convex() const {
        bool is_positive = cross_product(vertexes[0], vertexes[1], vertexes[2]) > 0;

        for (int i = 1; i < 5; i++) {
            bool current_positive = cross_product(vertexes[i], vertexes[(i + 1) % 5], vertexes[(i + 2) % 5]) > 0;

            if (current_positive != is_positive) {
                return false;
            }
        }
        return true;
    }

    [[nodiscard]] double inline area() const override {
        double area = 0;

        for (int i = 0; i < 5; i++) {
            area += vertexes[i].x * vertexes[(i + 1) % 5].y - vertexes[(i + 1) % 5].x * vertexes[i].y;
        }
        return abs(area) / 2;
    }

    [[nodiscard]] double inline perimeter() const override {
        double perimeter = 0;

        for (int i = 0; i < 5; i++) {
            perimeter += calc_distance(vertexes[i], vertexes[(i + 1) % 5]);
        }
        return perimeter;
    }
};

class Polygon : public Figure {
    vector<Dot> vertexes;

    void init_vertexes(const vector<Dot> &points) {
        vertexes = points;
    }

    void sort_vertexes() {
        vector<Dot> sorted(vertexes.size());
        sorted[0] = vertexes[0];

        vector<bool> visited(vertexes.size(), false);
        visited[0] = true;

        for (size_t i = 0; i < vertexes.size() - 1; i++) {
            int min_index = -1;
            double min_distance = numeric_limits<double>::max();

            for (size_t j = 0; j < vertexes.size(); j++) {
                if (!visited[j]) {
                    double curr_distance = calc_distance(sorted[i], vertexes[j]);

                    if (curr_distance < min_distance) {
                        min_index = j;
                        min_distance = curr_distance;
                    }
                }
            }
            visited[min_index] = true;
            sorted[i + 1] = vertexes[min_index];
        }

        vertexes = sorted;
    }

    static double inline calc_distance(const Dot &a, const Dot &b) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }

    static double cross_product(const Dot &a, const Dot &b, const Dot &c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

public:
    Polygon(const vector<Dot> &points) {
        init_vertexes(points);
        sort_vertexes();
    }

    [[nodiscard]] bool is_convex() const {
        bool is_positive = cross_product(vertexes[0], vertexes[1], vertexes[2]) > 0;

        for (size_t i = 1; i < vertexes.size(); i++) {
            bool current_positive = cross_product(vertexes[i], vertexes[(i + 1) % vertexes.size()], vertexes[(i + 2) % vertexes.size()]) > 0;

            if (current_positive != is_positive) {
                return false;
            }
        }
        return true;
    }

    [[nodiscard]] double inline area() const override {
        double area = 0;

        for (size_t i = 0; i < vertexes.size(); i++) {
            area += vertexes[i].x * vertexes[(i + 1) % vertexes.size()].y - vertexes[(i + 1) % vertexes.size()].x * vertexes[i].y;
        }
        return abs(area) / 2;
    }

    [[nodiscard]] double inline perimeter() const override {
        double perimeter = 0;

        for (size_t i = 0; i < vertexes.size(); i++) {
            perimeter += calc_distance(vertexes[i], vertexes[(i + 1) % vertexes.size()]);
        }
        return perimeter;
    }
};

void test_figures() {
    // Test Rectangle
    Rectangle rect(0, 0, 4, 3);
    cout << "Rectangle Area: " << rect.area() << endl;
    cout << "Rectangle Perimeter: " << rect.perimeter() << endl;

    // Test Triangle
    Triangle tri(0, 0, 3, 0, 3, 4);
    cout << "Triangle Area: " << tri.area() << endl;
    cout << "Triangle Perimeter: " << tri.perimeter() << endl;

    // Test Pentagon
    Pentagon pent(0, 0, 2, 4, 4, 3, 3, 1, 1, -1);
    cout << "Pentagon Area: " << pent.area() << endl;
    cout << "Pentagon Perimeter: " << pent.perimeter() << endl;
    cout << "Pentagon is Convex: " << (pent.is_convex() ? "Yes" : "No") << endl;

    // Test Polygon (Hexagon)
    vector<Dot> hexagon_points = {{0, 0}, {2, 0}, {3, 1}, {2, 3}, {0, 4}, {-1, 2}};
    Polygon hexagon(hexagon_points);
    cout << "Hexagon Area: " << hexagon.area() << endl;
    cout << "Hexagon Perimeter: " << hexagon.perimeter() << endl;
    cout << "Hexagon is Convex: " << (hexagon.is_convex() ? "Yes" : "No") << endl;
}

int main() {
    test_figures();
}
