#include <Eigen/Dense>
#include <iostream>
// following tutorial https://www.youtube.com/watch?v=XmtNr1TuO-E
int main() {
  // an simple fixed size matrix
  Eigen::Matrix<double, 3, 3> matrix1;
  // Eigen::Matrix3d also works
  matrix1.setZero();
  std::cout << matrix1 << std::endl;

  // dynamic size matrix
  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;
  matrix_dynamic.resize(2, 2);
  matrix_dynamic(0, 0) = 1.0;
  matrix_dynamic(0, 1) = 2.0;
  matrix_dynamic(1, 0) = 3.0;
  matrix_dynamic(1, 1) = 4.0;
  std::cout << std::endl << matrix_dynamic << std::endl;
  matrix_dynamic.resize(2, 3);  // resize will set all entries to zero
  std::cout << std::endl << matrix_dynamic << std::endl;
  // another way to manually set matrix data
  matrix_dynamic << 1, 2, 3,  //
      4, 5, 6;
  std::cout << std::endl << matrix_dynamic << std::endl;
  // dynamic matrix can be resized using set functions
  matrix_dynamic.setIdentity(3, 3);
  std::cout << std::endl << matrix_dynamic << std::endl;

  // set diagonal matrix using a vector
  Eigen::Matrix<double, 3, 1> vector1;
  vector1 << 1, 2, 3;
  Eigen::MatrixXd matrix_diag;
  matrix_diag = vector1.asDiagonal();
  std::cout << std::endl << matrix_diag << std::endl;

  // Now we try to take a block from the matrix
  std::cout << std::endl << matrix_diag.block(0, 1, 2, 2) << std::endl;
  std::cout << std::endl << matrix_diag.block(1, 1, 2, 2) << std::endl;
  // We can modify the original matrix using this method
  matrix_diag.block(1, 1, 2, 2) =
      Eigen::Matrix<double, 2, 1>(6, 2).asDiagonal();
  std::cout << std::endl << matrix_diag << std::endl;

  // Basic Matrix operations:
  // matrix addition
  Eigen::MatrixXd A1(2, 2);
  Eigen::MatrixXd B1(2, 2);

  A1 << 1, 2, 3, 4;
  B1 << 3, 4, 5, 6;
  Eigen::MatrixXd C1 = A1 + B1;
  std::cout << " \n\n The sum of A1 and B1 is\n\n" << C1 << std::endl;
  // similarly you can subtract A1 and B1

  // matrix multiplication
  Eigen::MatrixXd D1 = A1 * B1;
  std::cout << " \n\n The matrix product of A1 and B1 is\n\n"
            << D1 << std::endl;

  // multiplication by a scalar
  int s1 = 2;
  Eigen::MatrixXd F1;
  F1 = s1 * A1;
  std::cout
      << " \n\n The matrix product of the scalar 2 and the matrix A1 is\n\n"
      << F1 << std::endl;
  // matrix transpose
  Eigen::MatrixXd At;
  Eigen::MatrixXd R1;
  // we can obain a transpose of A1 as follows
  At = A1.transpose();
  std::cout << "\n\n Original matrix A1\n\n" << A1 << std::endl;
  std::cout << "\n\n Its transpose\n\n " << At << std::endl;

  // we can use a transpose operator in expressions
  R1 = A1.transpose() + B1;
  std::cout << "\n\n Matrix R1=A1^{T}+B1 is\n\n" << R1 << std::endl;

  // here we should be careful, the operation .transpose() might lead to
  // unexpected results in this scenarios
  //	A1 = A1.transpose();
  // cout << " \n\n This should be a transpose of the matrix A1\n\n" << A1 <<
  // endl;

  // the correct and safe way to do the matrix transpose is the following
  A1.transposeInPlace();
  std::cout << " \n\n This should be a transpose of the matrix A1\n\n"
            << A1 << std::endl;
  // restore A1 matrix to its original state
  A1.transposeInPlace();
  // matrix inverse
  Eigen::MatrixXd G1;
  G1 = A1.inverse();
  std::cout << "\n\n The inverse of the matrix A1 is\n\n" << G1 << std::endl;
  std::cout << "\n\n Double check A1^{-1}*A1=\n\n" << G1 * A1 << std::endl;
  return 0;
}