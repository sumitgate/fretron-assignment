

#include <iostream>
#include <vector>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

struct Point {
    double x, y;
};

void pFlightPath(const std::vector<Point>& flight, const std::string& color) {
    std::vector<double> x, y;
    for (const auto& point : flight) {
        x.push_back(point.x);
        y.push_back(point.y);
    }
    plt::plot(x, y, color);
    plt::scatter(x, y, 50, color);
}

int main() {
    std::vector<std::vector<Point>> flights = {
        {{1, 1}, {2, 2}, {3, 3}},
        {{1, 1}, {2, 4}, {3, 2}},
        {{1, 1}, {4, 2}, {3, 4}}
    };

    std::vector<std::string> colors = {"blue", "red", "yellow"};

    for (size_t i = 0; i < flights.size(); ++i) {
        pFlightPath(flights[i], colors[i]);
    }

    plt::grid(true);
    plt::show();

    return 0;
}

