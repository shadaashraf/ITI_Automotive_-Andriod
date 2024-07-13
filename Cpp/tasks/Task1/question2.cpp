#include <iostream>
using namespace std;

int main() {
    int input_seconds;
    int hours, minutes, seconds;

    cout << "Enter the number of seconds: ";
    cin >> input_seconds;

    // Calculate hours, minutes, and seconds
    hours =(input_seconds %60)/60;
    minutes = (input_seconds /60) / 60;
    seconds = input_seconds % 60;

    
    cout << "Time (H:M:S) - " << hours << ":" << minutes << ":" << seconds << endl;

    return 0;
}

