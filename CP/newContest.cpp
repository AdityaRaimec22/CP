#include <iostream>
#include <vector>
#include <algorithm>

void solveTestCase() {
    int numberOfElements;
    std::cin >> numberOfElements;
    
    std::vector<long long int> elements(numberOfElements);
    long long int totalSum = 0;
    
    for (int i = 0; i < numberOfElements; ++i) {
        std::cin >> elements[i];
        totalSum += elements[i];
    }

    for (int i = 1; i < numberOfElements - 1; ++i) {
        if (elements[i - 1] != 0) {
            long long int previousValue = elements[i - 1];
            if (elements[i] - 2 * previousValue >= 0 && elements[i + 1] - previousValue >= 0) {
                elements[i] -= (2 * previousValue);
                elements[i + 1] -= previousValue;
                totalSum -= (4 * previousValue);
            }
        }
    }

    if (totalSum == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    int testCases;
    std::cin >> testCases;
    
    while (testCases--) {
        solveTestCase();
    }

    return 0;
}
