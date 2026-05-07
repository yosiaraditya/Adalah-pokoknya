#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> Matrix;

// Create Matrix
Matrix createMatrix(int rows, int cols){
	Matrix matrix(rows, vector<int>(cols));
	cout << "Input the element of Matrix [" << rows << "x" << cols << "]: \n";
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			cin >> matrix[i][j];
		}
	}
	return matrix;
}
// Display Matrix
void displayMatrix(const Matrix& matrix){
	for(const auto& rows : matrix){
		for(const auto& elem : rows){
			cout << elem << "\t";
		}
		cout << endl;
	}
}
// Add Operation
Matrix addMatrix(const Matrix& matrix1, const Matrix& matrix2){
	if(matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()){
		cout << "Error: The row and coloumn size of two matrices must be equal!!!.\n";
		return Matrix();
	}
	int rows = matrix1.size(), cols = matrix1[0].size();
	Matrix result(rows, vector<int>(cols));
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	return result;
}
// Multiply Operation
Matrix multiplyMatrix(const Matrix& matrix1, const Matrix& matrix2){
	if(matrix1[0].size() != matrix2.size()){
		cout << "Error: The coloumn size of first matrix must be equal to the row size of second matrix!!!.\n";
		return Matrix();
	}
	int rows = matrix1.size(), cols = matrix2[0].size(), inner = matrix1[0].size();
	Matrix result(rows, vector<int>(cols));
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			for(int k = 0; k < inner; ++k){
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return result;
}
// Diagonal Matrix
Matrix diagonalMatrix(const Matrix& matrix){
	int rows = matrix.size(), cols = matrix[0].size();
	Matrix result(rows, vector<int>(cols));
	for(int i = 0; i < rows && i < cols; ++i){
		result[i][i] = matrix[i][i];
	}
	return result;
}
// Lower Triangle Matrix
Matrix lowerTriangleMatrix(const Matrix& matrix){
	int rows = matrix.size(), cols = matrix[0].size();
	Matrix result(rows, vector<int>(cols));
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j <= i && j < cols; ++j){
			result[i][j] = matrix[i][j];
		}
	}
	return result;
}
// Upper Triangle Matrix
Matrix upperTriangleMatrix(const Matrix& matrix){
	int rows = matrix.size(), cols = matrix[0].size();
	Matrix result(rows, vector<int>(cols));
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j >= i && j < cols; ++j){
			result[i][j] = matrix[i][j];
		}
	}
	return result;
}
// Display Menu
void displayMenu(){
	cout << "The Menu: \n";
	cout << "1. Create Matrix: \n";
	cout << "2. Display Matrix: \n";
	cout << "3. Add Operation of two Matrices: \n";
	cout << "4. Multiply Operation of two Matrices: \n";
	cout << "5. Diagonal Matrix: \n";
	cout << "6. Lower Triangle Matrix: \n";
	cout << "7. Upper Triangle Matrix: \n";
	cout << "8. Exit the Program: \n";
}
// Main Program
int main(){
	Matrix matrix1, matrix2, matrix3, matrix4, matrix5, result;
	bool matricesCreated = false;
	int choice;
	while(true){
		displayMenu();
		cout << "Choose the Menu: \n";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "Create the Matrix: \n";
				matrix1 = createMatrix(3,4);
				matrix2 = createMatrix(3,4);
				matrix4 = createMatrix(2,3);
				matricesCreated = true;
				break;
			case 2:
				cout << "Display the Matrix: \n";
				cout << "Matrix 1: \n";
				displayMatrix(matrix1);
				cout << "Matrix 2: \n";
				displayMatrix(matrix2);
				cout << "Matrix 4: \n";
				displayMatrix(matrix4);
				break;
			case 3:
				if(!matricesCreated){
					cout << "Error: The Matrix has not yet been created!!!.\n";
					break;
				}
				cout << "The result of add operation two matrices: \n";
				matrix3 = addMatrix(matrix1, matrix2);
				if(!matrix3.empty()){
					displayMatrix(matrix3);
				}
				break;
			case 4:
				if(!matricesCreated){
					cout << "Error: The Matrix has not yet been created!!!.\n";
					break;
				}
				cout << "The result of multiply operation two matrices: \n";
				matrix5 = multiplyMatrix(matrix4, matrix1);
				if(!matrix5.empty()){
					displayMatrix(matrix5);
				}
				break;
			case 5:
				if(!matricesCreated){
					cout << "Error: The Matrix has not yet been created!!!.\n";
					break;
				}
				cout << "The Diagonal Matrix: \n";
				result = diagonalMatrix(matrix1);
				displayMatrix(result);
				break;
			case 6:
				if(!matricesCreated){
					cout << "Error: The Matrix has not yet been created!!!.\n";
					break;
				}
				cout << "The Lower Triangle Matrix: \n";
				result = lowerTriangleMatrix(matrix1);
				displayMatrix(result);
				break;
			case 7:
				if(!matricesCreated){
					cout << "Error: The Matrix has not yet been created!!!.\n";
					break;
				}
				cout << "The Upper Triangle Matrix: \n";
				result = upperTriangleMatrix(matrix1);
				displayMatrix(result);
				break;
			case 8:
				cout << "Exit the Program.\n";
				return 0;
			default:
				cout << "Input is invalid!!!.\n";
				break;
		}
	}
}