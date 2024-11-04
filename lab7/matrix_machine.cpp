#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Matrix {
private:
    vector<vector<int>> a_matrix;
    int size_of_matrix;

public:
    Matrix(int matrix_size_n) : size_of_matrix(matrix_size_n) {
        a_matrix.resize(matrix_size_n, vector<int>(matrix_size_n));
    }

    void read_from_file(ifstream& file) {
        for (int i = 0; i < size_of_matrix; ++i) {
            for (int j = 0; j < size_of_matrix; ++j) {
                file >> a_matrix[i][j];
            }
        }
    }

    Matrix operator+(Matrix& other) {
        Matrix sum_result(size_of_matrix);
        for (int i = 0; i < size_of_matrix; ++i) {
            for (int j = 0; j < size_of_matrix; ++j) {
                sum_result.a_matrix[i][j] = a_matrix[i][j] + other.a_matrix[i][j];
            }
        }
        return sum_result;
    }

    Matrix operator*(Matrix& other) {
        Matrix product_result(size_of_matrix);
        for (int i = 0; i < size_of_matrix; ++i) {
            for (int j = 0; j < size_of_matrix; ++j) {
                product_result.a_matrix[i][j] = 0;
                for (int k = 0; k < size_of_matrix; ++k) {
                    product_result.a_matrix[i][j] += a_matrix[i][k] * other.a_matrix[k][j];
                }
            }
        }
        return product_result;
    }

    void display_matrix() {
        for (auto& row : a_matrix) {
            for (auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    int sum_of_diagonals() {
        int sum = 0;
        for (int i = 0; i < size_of_matrix; ++i) {
            sum += a_matrix[i][i]; // Main diagonal
            sum += a_matrix[i][size_of_matrix - i - 1]; // Secondary diagonal
        }
        return sum;
    }

    bool is_two_rows() {
        return size_of_matrix == 2;
    }

    void swap_rows() {
        if (size_of_matrix == 2) {
            for (int j = 0; j < size_of_matrix; ++j) {
                swap(a_matrix[0][j], a_matrix[1][j]);
            }
        }
    }
};


int main() {
    cout << "Welcome to the Matrix Machine" << endl;
    cout << "To begin the program, please enter your sample file: ";
    string file_name;
    cin >> file_name;

    ifstream file(file_name);

    int matrix_size;
    file >> matrix_size;
    Matrix first_matrix(matrix_size);
    Matrix second_matrix(matrix_size);

    first_matrix.read_from_file(file);
    second_matrix.read_from_file(file);
    file.close();

    cout << "Your First Matrix:" << endl;
    first_matrix.display_matrix();
    cout << "Your Second Matrix:" << endl;
    second_matrix.display_matrix();

    int user_choice;
    while (true) {
        cout << "Here are your options from your 2 matrix inputs:" << endl;
        cout << "1) Sum of your two matrices" << endl;
        cout << "2) Product of your two matrices" << endl;
        cout << "3) Sum of the diagonal for your two matrices" << endl;
        cout << "4) Flip rows of a two-row matrix" << endl;
        cout << "5) Quit" << endl;
        cout << "Your selection: ";
        cin >> user_choice;

        if (user_choice == 1) {
            Matrix user_sum = first_matrix + second_matrix;
            cout << "Your Sum of your two matrices:" << endl;
            user_sum.display_matrix();
        } 
        else if (user_choice == 2) {
            Matrix user_product = first_matrix * second_matrix;
            cout << "Your product of your two matrices:" << endl;
            user_product.display_matrix();
        } 
        else if (user_choice == 3) {
            int sum_diagnol_1 = first_matrix.sum_of_diagonals();
            int sum_diagnol_2 = second_matrix.sum_of_diagonals();
            cout << "The sum of the diagonal elements of your two matrices: " << sum_diagnol_1 + sum_diagnol_2 << endl;
        } 
        else if (user_choice == 4) {
            if (first_matrix.is_two_rows() || second_matrix.is_two_rows()) {
                if (first_matrix.is_two_rows()) {
                    first_matrix.swap_rows();
                    cout << "Matrix 1 after flipping rows:" << endl;
                    first_matrix.display_matrix();
                } 
                else {
                    cout << "Sorry, your first Matrix does not have two rows." << endl;
                }
                if (second_matrix.is_two_rows()) {
                    second_matrix.swap_rows();
                    cout << "Matrix 2 after flipping rows:" << endl;
                    second_matrix.display_matrix();
                } 
                else {
                    cout << "Sorry, your second Matrix does not have two rows." << endl;
                }
            }
            else {
                cout << "Sorry, neither of your matricies has two rows to flip." << endl;
            }
        }
        else if (user_choice == 5) {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid selection, please try again." << endl;
        }
    }

    return 0;
}
