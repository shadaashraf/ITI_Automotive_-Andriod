#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile) {
        std::cerr << "Unable to open input file" << std::endl;
        return 1;
    }

    if (!outputFile) {
        std::cerr << "Unable to open output file" << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    int number;

    while (inputFile >> number) {
        if (number > 100000) {
            std::cerr << "Error: Number exceeds 100000" << std::endl;
            return 1;
        }
        numbers.push_back(number);
    }

    if (numbers.empty()) {
        std::cerr << "No valid numbers in input file" << std::endl;
        return 1;
    }

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    double avg = static_cast<double>(sum) / numbers.size();
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());

    outputFile << "------------------------------------\n";
    outputFile << "| Sum      | Average  | Min   | Max   |\n";
    outputFile << "------------------------------------\n";
    outputFile << "| " << std::setw(8) << sum << " | " << std::setw(8) << avg << " | " << std::setw(5) << min << " | " << std::setw(5) << max << " |\n";
    outputFile << "------------------------------------\n";

    inputFile.close();
    outputFile.close();

    return 0;
}

