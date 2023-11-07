#include<iostream>

class A {
    int n;

public:
    void getInput() {
        std::cout << "Enter the number of terms: ";
        std::cin >> n;
    }

    void fibIterative() {
        int a = 0, b = 1, c;

        for (int i = 1; i <= n; i++) {
            std::cout << a << " ";
            c = a + b;
            a = b;
            b = c;
        }
    }

    int fibRecursive(int term) {
        if (term <= 1) {
            return term;
        }
        return fibRecursive(term - 1) + fibRecursive(term - 2);
    }

    void displayFibonacciRecursive() {
        for (int i = 0; i < n; i++) {
            std::cout << fibRecursive(i) << " ";
        }
    }
};

int main() {
    A obj;
    
    obj.getInput();

    std::cout << "Iterative Fibonacci: ";
    obj.fibIterative();
    std::cout << "\n\nRecursive Fibonacci: ";
    obj.displayFibonacciRecursive();

    return 0;
}
