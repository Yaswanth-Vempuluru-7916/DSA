#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::vector<int>> ans = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Find max and min elements in the inner iterator
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        if (!it->empty()) {
            auto max_it = std::max_element(it->begin(), it->end());
            auto min_it = std::min_element(it->begin(), it->end());

            int max_element = *max_it;
            int min_element = *min_it;

            std::cout << "Max in inner iterator: " << max_element << std::endl;
            std::cout << "Min in inner iterator: " << min_element << std::endl;
        }
    }

    return 0;
}
