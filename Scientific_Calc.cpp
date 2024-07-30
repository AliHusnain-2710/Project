#include <iostream>
#include <cmath>

using namespace std;

class Calculator
{
public:
    virtual double calculate(double x, double y) = 0;
    ~Calculator() {}
};

class Addition : public Calculator
{
public:
    double calculate(double x, double y)
    {
        return x + y;
    }
};

class Subtraction : public Calculator
{
public:
    double calculate(double x, double y)
    {
        return x - y;
    }
};

class Multiplication : public Calculator
{
public:
    double calculate(double x, double y)
    {
        return x * y;
    }
};

class Division : public Calculator
{
public:
    double calculate(double x, double y)
    {
        if (y != 0)
        {
            return x / y;
        }
        else
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
};

class ScientificCalculator : public Calculator
{
public:
    virtual double calculate(double x) = 0;
};

class SquareRoot : public ScientificCalculator
{
public:
    double calculate(double x)
    {
        if (x >= 0)
        {
            return sqrt(x);
        }
        else
        {
            cout << "Error: Negative input for square root!" << endl;
            return 0;
        }
    }

    double calculate(double x, double y)
    {
        return 0;
    }
};

void useCalculator(Calculator *calc, double x, double y = 0)
{
    double result = calc->calculate(x, y);
    cout << "Result: " << result << endl;
}

void useScientificCalculator(ScientificCalculator *calc, double x)
{
    double result = calc->calculate(x);
    cout << "Result: " << result << endl;
}

int main()
{
    int choice;
    double num1, num2;

    while (true)
    {
        cout << "Scientific Calculator" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Square Root" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6)
            break;

        Calculator *calc = nullptr;
        switch (choice)
        {
        case 1:
            calc = new Addition();
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            useCalculator(calc, num1, num2);
            break;
        case 2:
            calc = new Subtraction();
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            useCalculator(calc, num1, num2);
            break;
        case 3:
            calc = new Multiplication();
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            useCalculator(calc, num1, num2);
            break;
        case 4:
            calc = new Division();
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            useCalculator(calc, num1, num2);
            break;
        case 5:
        {
            ScientificCalculator *sCalc = new SquareRoot();
            cout << "Enter a number: ";
            cin >> num1;
            useScientificCalculator(sCalc, num1);
            delete sCalc;
        }
        break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
