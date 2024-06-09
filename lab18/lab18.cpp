#include <iostream>

class Matrix {
private:
    int data[3][3];
public:
    Matrix() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                data[i][j] = 0;
    }

    Matrix(int arr[3][3]) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                data[i][j] = arr[i][j];
    }

    Matrix operator*(const Matrix& other) {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    void display() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int arr1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int arr2[3][3] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };

    Matrix mat1(arr1);
    Matrix mat2(arr2);

    std::cout << "Matrix 1:" << std::endl;
    mat1.display();
    std::cout << "Matrix 2:" << std::endl;
    mat2.display();

    Matrix result = mat1 * mat2;

    std::cout << "Result of multiplication:" << std::endl;
    result.display();

    return 0;
}

