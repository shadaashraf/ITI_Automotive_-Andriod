#include <iostream>
#include <cmath>

class Calculator {
private:
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b != 0) return a / b;
        std::cout << "Error: Division by zero.\n";
        return 0;
    }

    double power(double a, double b) {
        return pow(a, b);
    }

    double sqrt(double a) {
        return std::sqrt(a);
    }

public:
    void calculate() {
        double num1, num2;
        char op;
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter operator (+, -, *, /, ^, S for sqrt): ";
        std::cin >> op;

        switch (op) {
            case '+':
                std::cout << "Enter second number: ";
                std::cin >> num2;
                std::cout << "Result: " << add(num1, num2) << "\n";
                break;
            case '-':
                std::cout << "Enter second number: ";
                std::cin >> num2;
                std::cout << "Result: " << subtract(num1, num2) << "\n";
                break;
            case '*':
                std::cout << "Enter second number: ";
                std::cin >> num2;
                std::cout << "Result: " << multiply(num1, num2) << "\n";
                break;
            case '/':
                std::cout << "Enter second number: ";
                std::cin >> num2;
                std::cout << "Result: " << divide(num1, num2) << "\n";
                break;
            case '^':
                std::cout << "Enter second number: ";
                std::cin >> num2;
                std::cout << "Result: " << power(num1, num2) << "\n";
                break;
            case 'S':
                std::cout << "Result: " << sqrt(num1) << "\n";
                break;
            default:
                std::cout << "Invalid operator.\n";
                break;
        }
    }
};

int main() {
    Calculator calc;
    calc.calculate();
    return 0;
}
