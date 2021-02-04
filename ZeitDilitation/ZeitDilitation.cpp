#include <iostream>
#include "ZeitDilitation.h"

using namespace std;

int main() {   
    programMain();
    while (true) {
        system("cls");
        cout << "Do you want to calculate another Time Dilation?\n(y) Yes\n(n) No\n";
        cout << "ProgramMain@input ~$ ";
        cin >> choice;
        if (choice == "y" || choice == "Y") {
            system("cls");
            programMain();
        }
        else {
            cout << "\nThanks for unsing my Program!\n\n";
            system("pause");
            return 0;
        }
    }
}
int programMain() {
    cout << "Unit of Velocity: \n(1) for Km/s\n(2) for Km/h\n";
    cout << "TimeDilation@input: ~$ ";
    cin >> unitVelocity;

    cout << "\nPlease enter the Velocity:\n";
    cout << "TimeDilation@input: ~$ ";
    cin >> velocityValue;

    switch (unitVelocity) {
    case 1:
        cout << "The Velocity is " << velocityValue << "Km/s";
        if (velocityValue >= 300000) {
            cout << "\nVelocity is equal or higher than the speed of Light. Canceling Operation.\n";
            system("pause");
        }
        break;
    case 2:
        cout << "The Velocity is " << velocityValue << "Km/h";
        velocityValue = velocityValue * 0.00027777777777778;
        if (velocityValue >= 300000) {
            cout << "\nVelocity is equal or higher than the speed of Light. Canceling Operation.\n";
            system("pause");
        }
        break;
    default:
        cout << "\nInvalid Velocity Unit! You have entered: " << unitVelocity << endl;
        system("pause");
        return 0;
        break;
    }
    cout << "\nUnit of the Time: \n(1) for hours\n(2) for minutes\n(3) for seconds\n";
    cout << "TimeDilation@input: ~$ ";
    cin >> timeUnit;
    cout << "\nEnter the Time traveled: \n";
    cout << "TimeDilation@input: ~$ ";
    cin >> timeTraveled;
    switch (timeUnit)
    {
    case 1:
        cout << "\nThe Time traveled entered is " << timeTraveled << "h\n";
        break;
    case 2:
        cout << "\nThe Time traveled entered is " << timeTraveled << "min\n";
        timeTraveled = timeTraveled / 60;
        break;
    case 3:
        cout << "\nThe Time traveled entered is " << timeTraveled << "sec\n";
        timeTraveled = timeTraveled / 60;
        timeTraveled = timeTraveled / 60;
        break;
    default:
        cout << "Invalid Time unit entered " << timeUnit << ". Canceling Operation." << endl;
        system("pause");
        return 0;
        break;
    }
    timeDilationCalc(timeTraveled, velocityValue);
    system("pause");
}

double timeDilationCalc(double time, double velocity) {
    timeHelper = timeTraveled * sqrt(1 - pow(velocityValue, 2) / pow(300000, 2));
    timeDilation = timeTraveled - timeHelper;
    cout << "Which unit do you want for your output?: \n(1) hours\n(2) minutes\n(3) seconds\n";
    cout << "TimeDilation@input: ~$ ";
    cin >> outputUnit;
    switch (outputUnit)
    {
    case 1:
        cout << "Your Time dilation is " << timeDilation << "h\n";
        break;
    case 2:
        timeDilation = timeDilation * 60;
        cout << "Your Time dilation is " << timeDilation << "min\n";
        break;
    case 3:
        timeDilation = timeDilation * 60;
        timeDilation = timeDilation * 60;
        cout << "Your Time dilation is " << timeDilation << "sec\n";
        break;
    default:
        cout << "Invalid output unit: " << outputUnit << ". Canceling Operation.";
        system("pause");
        return 0;
        break;
    }
    return 0;
}