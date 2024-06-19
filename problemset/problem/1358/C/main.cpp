#include <iostream>
#include <vector>

int main() {
    long long x1, y1, x2, y2, t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << (x2 - x1) * (y2 - y1) + 1 << std::endl;
    }
    return 0;
}
