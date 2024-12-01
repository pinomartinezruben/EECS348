#include <iostream>
#include <iomanip>
#include <string>
// using std to avoid repeating std::
using namespace std;
// function will combine before and after period the multiply by the sign
double extract_numeric(const string& str) {
    // counter for periods
    int period_counters = 0;
    // variable checks if there are digits
    bool has_digits = false;
    // iterate through each element in string
    for (int i = 0; i < str.length(); i++) {
        // if char is period, increment counter
        if (str[i] == '.') {
            period_counters++;
        }
        // more than one period is not allowed
        if (period_counters > 1) {
            return -999999.99;
        }
        // + or - should be at start only since it determines the sign
        if ((str[i] == '+' || str[i] == '-') && i != 0) {
            return -999999.99;
        }
        // element must be digit, a period, or a + or -
        if (isdigit(str[i]) == false && str[i] != '.' && str[i] != '+' && str[i] != '-') {
            return -999999.99;
        }
        // change the variable to be true since we have a digit
        if (isdigit(str[i]) == true) {
            has_digits = true;
        }
    }
    // if no digits were found
    if (has_digits == false) {
        return -999999.99;
    }
    // Manually converting string to number
    double result = 0.0;
    double fractional_part = 0.0;
    int sign = 1;
    size_t i = 0;
    // determine the sign
    if (str[i] == '+' || str[i] == '-') {
        // If it's -, set sign to -1. otherwise, set sign to 1
        if (str[i] == '-') { 
            sign = -1; 
        } else { 
            sign = 1; 
        } 
        // Move to the next element 
        i++; 
    }
    // handle the integers of the string
    while (i < str.length() && isdigit(str[i]) == true) {
        // C++ has trick to turn a string to an integer
        int digit_value = str[i] - '0'; // essentially 'int' - '0' turns 'int' to int
    
        // to add digit to right, multiply result by 10, then add your value
        result = (result * 10) + digit_value;  // If result is 12 and digit is 3, then 12 * 10 + 3 = 123
    
        // Go to the next element
        i++;
    }
    // check if there's a decimal point
    if (str[i] == '.' && i < str.length()) {
        // move past the decimal point
        i++;
        // start with divisor as 10
        double divisor = 10.0;
        
        // Process digits after the decimal point
        while (i < str.length() && isdigit(str[i]) == true) {
            // Convert the character to number and add to fractional part
            fractional_part += (str[i] - '0') / divisor;
            // Increase divisor by 10 for next decimal place
            divisor *= 10.0;
            // Move to the next element
            i++;
        }
    }
    // return the result with sign
    return (result + fractional_part) * sign;
}
int main() {
    // declare string for user input
    string user_input;

    // loop until user types "END"
    while (true) {
        // prompt user for input
        cout << "Enter a string (or 'END' to quit): ";
        cin >> user_input;
        // if user wants to quit
        if (user_input == "END") {
            std::cout << "Goodbye! Program Terminating . . ." << std::endl;
            break;
        }
        // extract number from input
        double number = extract_numeric(user_input);

        // if number is valid
        if (number != -999999.99) {
            // print number with 4 decimal places
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            // if input is invalid
            cout << "The input is invalid." << endl;
        }
    }
    // program ends
    return 0;
}
