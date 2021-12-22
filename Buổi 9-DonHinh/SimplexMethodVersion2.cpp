#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Simplex
{
public:
    int rows, cols;
    vector<vector<float>> A;
    vector<float> B;
    vector<float> C;
    float minimum;
    bool isUnBounded;

public:
    Simplex(vector<vector<float>> matrix, vector<float> b, vector<float> c)
    {
        minimum = 0;
        isUnBounded = false;
        rows = matrix.size();
        cols = matrix[0].size();
        A.resize(rows, vector<float>(cols, 0));
        B.resize(b.size());
        C.resize(c.size());

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                A[i][j] = matrix[i][j];
            }
        }

        for (int i = 0; i < c.size(); i++)
        {
            C[i] = c[i];
        }

        for (int i = 0; i < b.size(); i++)
        {
            B[i] = b[i];
        }
    }
    bool simplexMethodCalculation()
    {
        if (checkOptimize() == true)
        {
            return true;
        }

        int pivotColumn = findPivotColumn();

        if (isUnBounded == true)
        {
            cout << "Error unbounded" << endl;
            return true;
        }

        int pivotRow = findPivotRow(pivotColumn);

        doPivotting(pivotRow, pivotColumn);

        return false;
    }

    bool checkOptimize()
    {
        bool isOptimal = false;
        int positveValueCount = 0;
        for (int i = 0; i < C.size(); i++)
        {
            float value = C[i];
            if (value >= 0)
            {
                positveValueCount++;
            }
        }
        if (positveValueCount == C.size())
        {
            isOptimal = true;
            printMatrix();
        }
        return isOptimal;
    }

    void doPivotting(int pivotRow, int pivotColumn)
    {
        float pivetValue = A[pivotRow][pivotColumn];
        float pivotRowValue[cols];
        float pivotColValue[rows];
        float rowNew[cols];

        minimum = minimum - (C[pivotColumn] * (B[pivotRow] / pivetValue));
        for (int i = 0; i < cols; i++)
        {
            pivotRowValue[i] = A[pivotRow][i];
        }
        for (int j = 0; j < rows; j++)
        {
            pivotColValue[j] = A[j][pivotColumn];
        }

        for (int k = 0; k < cols; k++)
        {
            rowNew[k] = pivotRowValue[k] / pivetValue;
        }

        B[pivotRow] = B[pivotRow] / pivetValue;

        for (int i = 0; i < rows; i++)
        {
            if (i != pivotRow)
            {
                for (int j = 0; j < cols; j++)
                {
                    float multiplyValue = pivotColValue[i];
                    A[i][j] = A[i][j] - (multiplyValue * rowNew[j]);
                }
            }
        }

        for (int i = 0; i < B.size(); i++)
        {
            if (i != pivotRow)
            {
                float multiplyValue = pivotColValue[i];
                B[i] = B[i] - (multiplyValue * B[pivotRow]);
            }
        }

        float multiplyValue = C[pivotColumn];
        for (int i = 0; i < C.size(); i++)
        {
            C[i] = C[i] - (multiplyValue * rowNew[i]);
        }

        for (int i = 0; i < cols; i++)
        {
            A[pivotRow][i] = rowNew[i];
        }
    }

    void printMatrix()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int findPivotColumn()
    {

        int location = 0;
        float min = C[0];

        for (int i = 1; i < C.size(); i++)
        {
            if (C[i] < min)
            {
                min = C[i];
                location = i;
            }
        }

        return location;
    }

    int findPivotRow(int pivotColumn)
    {
        float positiveValues[rows];
        vector<float> result(rows, 0);
        int negativeValueCount = 0;

        for (int i = 0; i < rows; i++)
        {
            if (A[i][pivotColumn] > 0)
            {
                positiveValues[i] = A[i][pivotColumn];
            }
            else
            {
                positiveValues[i] = 0;
                negativeValueCount += 1;
            }
        }
        if (negativeValueCount == rows)
        {
            isUnBounded = true;
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {
                float value = positiveValues[i];
                if (value > 0)
                {
                    result[i] = B[i] / value;
                }
                else
                {
                    result[i] = 0;
                }
            }
        }
        float minimum = 99999999;
        int location = 0;
        for (int i = 0; i < sizeof(result) / sizeof(result[0]); i++)
        {
            if (result[i] > 0)
            {
                if (result[i] < minimum)
                {
                    minimum = result[i];

                    location = i;
                }
            }
        }
        return location;
    }
    void CalculateSimplex()
    {
        bool end = false;

        cout << "initial array(Not optimal)" << endl;
        printMatrix();

        cout << " " << endl;
        cout << "final array(Optimal solution)" << endl;

        while (!end)
        {

            bool result = simplexMethodCalculation();

            if (result == true)
            {

                end = true;
            }
        }
        cout << "Answers for the Constraints of variables" << endl;
        
        for (int i = 0; i < B.size(); i++)
        {
            cout << "variable " << i + 1 << " in final = " << B[i] << endl;
        }

        cout << "" << endl;
        cout << "minimum value: " << -1 * minimum << endl;
    }
};

int main()
{
    int colSizeA = 4;
    int rowSizeA = 2;

    float c[] = {-5, -8, 0, 0};
    float b[] = {1, 2};

    float a[rowSizeA][colSizeA] = {
        {1, 2, 1, 0},
        {1, 1, 0, 1}};

    vector<vector<float>> A(rowSizeA, vector<float>(colSizeA, 0));
    vector<float> B(rowSizeA, 0);
    vector<float> C(colSizeA, 0);

    for (int i = 0; i < rowSizeA; i++)
    {
        for (int j = 0; j < colSizeA; j++)
        {
            A[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < rowSizeA; i++)
    {
        B[i] = b[i];
    }

    for (int i = 0; i < colSizeA; i++)
    {
        C[i] = c[i];
    }

    Simplex simplex(A, B, C);
    simplex.CalculateSimplex();

    return 0;
}