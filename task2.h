#ifndef TASK2_H
#define TASK2_H

#include <iostream>
#include <queue>
#include <sstream> // Add this line
#include <stdexcept>
#include <string>

double calculateFormula(double x, int n);

// Function prototypes for other functions
void getInput(double& value, const std::string& prompt);
void getInput(int& value, const std::string& prompt);
void getNonNegativeStep(double& step, const std::string& prompt);
void getValidBounds(double& a, double& b);
bool askToRunAgain();


class InputRedirect {
public:
    explicit InputRedirect(std::queue<std::string> inputs) : inputs(std::move(inputs)) {}

    InputRedirect(const InputRedirect&) = delete;
    InputRedirect& operator=(const InputRedirect&) = delete;

    InputRedirect(InputRedirect&&) noexcept = default;
    InputRedirect& operator=(InputRedirect&&) noexcept = default;

    void getInput(double& value, const std::string& prompt) {
        simulateInput(value, prompt);
    }

    void getInput(int& value, const std::string& prompt) {
        simulateInput(value, prompt);
    }

    void getInput(std::string& value, const std::string& prompt) {
        simulateInput(value, prompt);
    }

    void getNonNegativeStep(double& step, const std::string& prompt) {
        simulateInput(step, prompt);
    }

    void getValidBounds(double& a, double& b) {
        simulateInput(a, "Enter the lower bound (a): ");
        simulateInput(b, "Enter the upper bound (b): ");
    }

private:
    std::queue<std::string> inputs;

    template <typename T>
    void simulateInput(T& value, const std::string& prompt) {
        if (!inputs.empty()) {
            std::cout << prompt;
            const std::string& input = inputs.front();
            inputs.pop();

            std::istringstream iss(input);  // This line requires <sstream>
            iss >> value;

            if (iss.fail() || !iss.eof()) {
                std::cout << "Error: Invalid input simulated!" << std::endl;
                value = T();  // Set value to default
            } else {
                std::cout << input << std::endl;  // Output the simulated input
            }
        } else {
            throw std::runtime_error("No more simulated inputs available!");
        }
    }
};

#endif // TASK2_H
