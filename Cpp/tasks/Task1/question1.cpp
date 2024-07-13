#include <iostream>
using namespace std;

int main() {
    int num;
    int sum = 0;

    cout << "Enter numbers to add (enter 0 to stop):" << endl;

    while (true) {
        cout << "Number: ";
        cin >> num;

        if (num == 0) {
            break;
        }

        sum += num;
    }

    cout << "Sum = " << sum << endl;

    return 0;
}

