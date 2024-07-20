#include <iostream>
#include <algorithm>

class point {
public:
    int x, y;
    // Constructor for convenience
    point(int x_val, int y_val) : x(x_val), y(y_val) {}
};

// Comparison function
bool mycap(const point& p1, const point& p2) {
    return p1.y >= p2.y; // Changed to "<" for sorting in ascending order

}

int main() {
    point arr[] = {{3, 10}, {2, 8}, {5, 4}};
    const size_t arr_size = sizeof(arr) / sizeof(arr[0]); // Calculate array size
    std::sort(arr, arr + arr_size, mycap); // Sort the array

    std::cout << "Sorted Points:\n";
    for (const auto& p : arr)
        std::cout << "x: " << p.x << ", y: " << p.y << std::endl; // Better output formatting

    return 0;
}
// Time complexity of this code is  O(n log n) due to sort operation which uses merge sort algorithm.
// Space Complexity is O(1).