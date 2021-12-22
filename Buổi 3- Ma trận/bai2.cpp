// #include <iostream>
// #include <math.h>
// using namespace std;

// void nhap(float matrix[][100], int n, int m) {
//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < m; j++) {
//       cout<<"nhap a["<<i<<"]["<<j<<"]: ";
//       cin>> matrix[i][j];
//     }
//   }
// }

// void xuat(float matrix[][100], int n, int m) {
//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < m; j++) {
//       cout<<matrix[i][j]<<" ";
//     }
//     cout<<endl;
//   }
// }

// void calcEigValue(float matrix[][100], float eigValueMatrix[][100], int n) {// tinh tri rieng
//   float b = -matrix[0][0] + -matrix[1][1];
//   float c = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
//   float delta = b*b - 4*c;
//   eigValueMatrix[0][0] = (-b + sqrt(delta))/2;
//   eigValueMatrix[0][1] = (-b - sqrt(delta))/2;
// }

// void calcEigVector(float matrix[][100], float eigValueMatrix[][100], float eigVector1[][100], float eigVector2[][100], int n) {// tinh vector rieng
//   float specialMatrix[100][100];
//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) { // tao ma tran dac trung ung voi moi lamda
//       for(int k = 0; k < n; k++) {
//         if(j == k) {
//           specialMatrix[j][j] = matrix[j][j] - eigValueMatrix[0][i];
//         }
//         else specialMatrix[j][k] = matrix[j][k];
//       }
//     }

//     if(i == 0) {
//       eigVector1[0][0] = 1;
//       eigVector1[1][0] = (specialMatrix[1][0] * (specialMatrix[0][1] - 1)) / specialMatrix[1][1] - specialMatrix[0][0];
//     }
//     else {
//       eigVector2[0][0] = 1;
//       eigVector2[1][0] = (specialMatrix[1][0] * (specialMatrix[0][1] - 1)) / specialMatrix[1][1] - specialMatrix[0][0];
//     }
//   }
// }

// void buildMatrixV(float matrixV[][100], float eigVector1[][100], float eigVector2[][100], int n) {//dung ma tran V
//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) {
//       if(j == 0) {
//         matrixV[i][j] = eigVector1[i][0];
//       }
//       else matrixV[i][j] = eigVector2[i][0];
//     }
//   }
// }

// void buildMatrixDCC(float matrixDCC[][100], float eigValueMatrix[][100], int n) {//dung ma tran duong cheo chinh
//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) {
//       if(i == j) {
//         matrixDCC[i][j] = eigValueMatrix[0][i];
//       }
//       else matrixDCC[i][j] = 0;
//     }
//   }
// }

// void chuyenVi(float matrix[][100], int n) {
//   float b[100][100];

//   for(int i = 0; i < n; i++) {
//     for(int j = 0; j < n; j++) {
//       b[i][j] = matrix[i][j];
//     }
//   }

//   for(int i = 0; i < n-1; i++) {
//     for(int j = i + 1; j < n; j++) {
//       float t = b[i][j];
//       b[i][j] = b[j][i];
//       b[j][i] = t;
//     }
//   }
//   xuat(b, n, n);
// }

// int main() {
//   float matrix[100][100], eigValueMatrix[100][100], eigVector1[100][100], eigVector2[100][100], matrixV[100][100], matrixDCC[100][100];
//   int n;
//   cout<<"nhap n: ";
//   cin>>n;
//   nhap(matrix, n, n);
//   xuat(matrix, n, n);
//   calcEigValue(matrix, eigValueMatrix, 2);
//   cout<<"lamda1: "<<eigValueMatrix[0][0]<<endl;
//   cout<<"lamda2: "<<eigValueMatrix[0][1]<<endl;
//   calcEigVector(matrix, eigValueMatrix, eigVector1, eigVector2, n);
//   cout<<"Eig Vector1: "<<endl;
//   xuat(eigVector1, n, 1);
//   cout<<"Eig Vector2: "<<endl;
//   xuat(eigVector2, n, 1);
//   cout<<"A = V*diag(lamda)*V^T, trong do: "<<endl;
//   cout<<"Matrix V:"<<endl;
//   buildMatrixV(matrixV, eigVector1, eigVector2, n);
//   xuat(matrixV, n, n);
//   cout<<"Matrix DCC:"<<endl;
//   buildMatrixDCC(matrixDCC, eigValueMatrix, n);
//   xuat(matrixDCC, n, n);
//   cout<<"Matrix V^T: "<<endl;
//   chuyenVi(matrixV, n);
// }
