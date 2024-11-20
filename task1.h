#ifndef TASK1_H
#define TASK1_H

#include <iostream>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <string>
 
// Прототипы функций
double calculateFormula(double x, int n);
void getInput(double& value, const std::string& prompt);
void getInput(int& value, const std::string& prompt);
bool askToRunAgain();

// Класс для эмуляции пользовательского ввода
class InputRedirect {
public:
    // Конструктор принимает очередь строк
    explicit InputRedirect(std::queue<std::string> inputs) : inputs(std::move(inputs)) {}

    InputRedirect(const InputRedirect&) = delete;
    InputRedirect& operator=(const InputRedirect&) = delete;

    InputRedirect(InputRedirect&&) noexcept = default;
    InputRedirect& operator=(InputRedirect&&) noexcept = default;

    // Метод для ввода double
    void getInput(double& value, const std::string& prompt) {
        simulateInput(value, prompt);
    }

    // Метод для ввода int
    void getInput(int& value, const std::string& prompt) {
        simulateInput(value, prompt);
    }

private:
    std::queue<std::string> inputs; // Используем очередь строк

    template <typename T>
    void simulateInput(T& value, const std::string& prompt) {
        if (!inputs.empty()) {
            std::cout << prompt;
            const std::string& input = inputs.front();
            inputs.pop();

            std::istringstream iss(input);
            iss >> value;

            if (iss.fail() || !iss.eof()) {
                std::cout << "Error: Invalid input simulated!" << std::endl;
                value = T(); // Устанавливаем значение по умолчанию
            } else {
                std::cout << input << std::endl; // Печатаем, что было введено
            }
        } else {
            throw std::runtime_error("No more simulated inputs available!");
        }
    }
};

#endif // TASK1_H
