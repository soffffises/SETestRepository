#include <iostream>
#include <cmath>
using namespace std;

double calculateFormula(double x, int n) {
    if (n <= 7) {
        cout << "n must be greater than 7!" << endl;
        return 0;
    }
    double result = 0.0;
    if (x < 3) {
        result = 5 * x - 2;
        double doubleSum = 0.0;

        for (int i = 2; i <= n - 5; ++i) {
            for (int j = 0; j <= n; ++j) {
                doubleSum += 2 * i + (pow(x, 2) / (j + 2)) - j;
            }
        }
        result -= doubleSum;
    } else {
        double product = 1.0;
        for (int j = 0; j <= n + 4; ++j) {
            product *= (4 * x - j);
        }
        double sum = 0.0;
        for (int j = -4; j <= n + 2; ++j) {
            sum += (1 / x) - 2 * j;
        }
        result = product + x * sum;
    }
    return result;
}

void getInput(double& value, const string& prompt) {
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail()) {
            break;
        } else {
            cout << "Error: Please enter a valid number!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void getInput(int& value, const string& prompt) {
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail() && value > 7) {
            break;
        } else {
            cout << "Error: Please enter a valid integer greater than 7!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool askToRunAgain() {
    char choice;
    cout << "Do you want to run the program again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    do {
        double x;
        int n;

        cout <<"Enter a value of x:" ;
        cin >> x;
        getInput(n, "Enter value for n (must be greater than 7): ");

        double result = calculateFormula(x, n);
        cout << "x = " << x << ", Result: " << result << endl;

    } while (askToRunAgain());

    return 0;
}
