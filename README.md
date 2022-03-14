# Matrix
The Matrix class is implemented to allow users to generate a Matrix object, and then be able to perform the following three actions upon it: 
* Print 
* Transpose
* Matrix Multiplication

Docs can be found in the doc folder of this project. It was generated using doxygen. 

## Interactive 
One can view and perform simple actions on the Matrix object by executing the following executable: 
* ./matrix.out
An example execution is as follows: 
```root@f5dc56d5bc4e:/workspace/Matrix_Final# ./matrix.out
A Matrix is being created.
Please enter the number of rows: 2
Please enter the number of columns: 2
Enter value for cell (0, 0): 1
Enter value for cell (0, 1): 2
Enter value for cell (1, 0): 3
Enter value for cell (1, 1): 4
The Matrix representation:
[1 2]
[3 4]
Please enter the number signifying the action to proceed:
0.) Print
1.) Transpose
2.) Matrix Multiplication
2
Multiplication Matrix with the Input Matrix will be done.
Please enter the data for the second matrix to multiply by :
Please enter the number of rows: 2
Please enter the number of columns: 2
Enter value for cell (0, 0): 1
Enter value for cell (0, 1): 2
Enter value for cell (1, 0): 3
Enter value for cell (1, 1): 4
The Matrix representation:
[1 2]
[3 4]
The Product of the two matrices are as follows:
[7 10]
[15 22]
```

## Tests
The unit tests are written using gtest. Please refer to the following link for more information on setup:  https://blog.zerokol.com/2012/10/installing-gtest-on-ubuntu-test.html 

To run the tests, one can navigate to the project directory and perform the following actions: 
* cmake CMakeLits.txt
* make
* ./executeTests
