#define TEST_MODE
#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <cassert>
#include "task1.h"

// Macros for checking
#define ASSERT_EQUAL(actual, expected) \
    do { \
        if ((actual) != (expected)) { \
            std::cerr << "Assertion failed: " << #actual << " == " << #expected \
                      << " (actual: " << (actual) << ", expected: " << (expected) << ")\n"; \
            assert(false); \
        } \
        else { \
            std::cout << #actual << " == " << #expected << " - Passed" << std::endl; \
        } \
    } while (false)

#define ASSERT_NEAR(actual, expected, tolerance) \
    do { \
        if (std::abs((actual) - (expected)) > (tolerance)) { \
            std::cerr << "Assertion failed: " << #actual << " ≈ " << #expected \
                      << " (actual: " << (actual) << ", expected: " << (expected) \
                      << ", tolerance: " << (tolerance) << ")\n"; \
            assert(false); \
        } \
        else { \
            std::cout << #actual << " ≈ " << #expected << " - Passed" << std::endl; \
        } \
    } while (false)

// Tests
void testInputRedirectDouble() {
    std::queue<std::string> inputs(std::deque<std::string>{"5.0"});
    InputRedirect inputRedirect(std::move(inputs));

    double x;
    inputRedirect.getInput(x, "Enter a value of x: ");
    ASSERT_NEAR(x, 5.0, 0.01);
}

void testInputRedirectInt() {
    std::queue<std::string> inputs(std::deque<std::string>{"8"});
    InputRedirect inputRedirect(std::move(inputs));

    int n;
    inputRedirect.getInput(n, "Enter value for n (must be greater than 7): ");
    ASSERT_EQUAL(n, 8);
}

void testIntegration() {
    std::queue<std::string> inputs(std::deque<std::string>{"2.0", "8"});
    InputRedirect inputRedirect(std::move(inputs));

    double x;
    int n;
    inputRedirect.getInput(x, "Enter a value of x: ");
    inputRedirect.getInput(n, "Enter value for n (must be greater than 7): ");

    double result = calculateFormula(x, n);
    ASSERT_NEAR(result, -25.4317, 0.01); // Integration test
}

int main() {
    std::cout << "Running testInputRedirectDouble..." << std::endl;
    testInputRedirectDouble();

    std::cout << "Running testInputRedirectInt..." << std::endl;
    testInputRedirectInt();

    std::cout << "Running testIntegration..." << std::endl;
    testIntegration();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
