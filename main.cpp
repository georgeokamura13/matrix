#include "Matrix.h"
#include <iostream>
using namespace std;

int promptRows() {
    int rowsInput;
    cout << "Please enter the number of rows: ";
    while (!(cin >> rowsInput)) {
        cout << "The number of rows set was not an integer, please provide a valid input: ";
        cin.clear();
        cin.ignore(40, '\n');
    }
    return rowsInput;
}

int promptColumns() {
    int columnsInput;
    cout << "Please enter the number of columns: ";
    while (!(cin >> columnsInput)) {
        cout << "The number of columns set was not an integer, please provide a valid input: ";
        cin.clear();
        cin.ignore(40, '\n');
    }
    return columnsInput;
}

double** promptMatrixData(int rowsInput, int columnsInput) {

    double** array_data;
    array_data = new double* [rowsInput];
    for (int i = 0; i < rowsInput; i++) {
        array_data[i] = new double[columnsInput];
    }

    for (int i = 0; i < rowsInput; i++) {
        for (int j = 0; j < columnsInput; j++) {
            cout << "Enter value for cell (" << i << ", " << j << "): ";
            cin >> array_data[i][j];
        }
    }
    return array_data;
}

int promptAction() {
    int actionInput;
    cout << "Please enter the number signifying the action to proceed: " << endl;
    cout << "0.) Print" << endl;
    cout << "1.) Transpose" << endl;
    cout << "2.) Matrix Multiplication" << endl;
    cin >> actionInput;
    return actionInput;
}

int main(int argc, char* argv[]) {

    cout << "A Matrix is being created. " << endl;
    int rows_input = promptRows();
    int cols_input = promptColumns();
    double** array_data = promptMatrixData(rows_input, cols_input);

    Matrix<double> matrix = Matrix<double>(array_data, rows_input, cols_input);
    cout << "The Matrix representation: " << endl;
    cout << matrix;
    int repeat = 1;

    while (repeat == 1) {
        int action_id = promptAction();
        if (action_id == 0) {
            cout << "Displaying Current Matrix: " << endl;
            cout << matrix;
        }
        else if (action_id == 1) {
            cout << "The Transpose of the Input Matrix is as follows: " << endl;
            cout << matrix.transpose();
        }
        else if (action_id == 2) {
            cout << "Multiplication Matrix with the Input Matrix will be done. " << endl;
            cout << "Please enter the data for the second matrix to multiply by : " << endl;
            int rows_input2 = promptRows();
            int cols_input2 = promptColumns();
            double** array_data2 = promptMatrixData(rows_input2, cols_input2);
            Matrix<double> other = Matrix<double>(array_data2, rows_input2, cols_input2);
            cout << "The Matrix representation: " << endl;
            cout << other;
            
            try {
                Matrix<double> product = matrix * other;
                cout << "The Product of the two matrices are as follows: " << endl;
                cout << product;
            }
            catch (const invalid_argument &e) {
                cout << e.what() << endl;;
            }
            
        }
        else {
            cout << "Invalid action option. ";
        }

        cout << "Would you like to perform another action? " << endl;
        cout << "1: Yes" << endl;
        cout << "2: No" << endl;
        while (!(cin >> repeat)) {
            cout << "The number of columns set was not valid";
            cin.clear();
            cin.ignore(40, '\n');
        }
    }

    delete array_data;
    
}