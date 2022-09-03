
#include <iostream>
// Hàm nhân 2 ma trận 2 chiều
void multiply_two_matrices(double **a, double **b, int n1, int m1, int n2, int m2, double **c)
{
    if (m1 != n2)
    {
        std::cout << "Hai ma tran khong nhan duoc voi nhau";
        return;
    }
    std::cout << "-------------------------------"<<std::endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            int k = 0;
            while (k < m1)
            {
                c[i][j] += a[i][k] * b[k][j];
                k++;
            }
        }
    }
}

// Hàm hiển thị kết quả tích của 2 ma trạn 2 chiều
void display_matrix(double **a, int n1, int m2)
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}
// Hàm giải phóng vùng nhớ cho ma trận 2 chiều
void free_data1(double **a, int n)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}


int main()
{
    int n1, m1, n2, m2;
    std::cout << "Nhap vao so hang cua ma tran thu nhat:";
    std::cin >> n1;
    std::cout << "Nhap vao so cot cua ma tran thu nhat:";
    std::cin >> m1;
    std::cout << "Nhap du lieu cua ma tran thu nhat\n";
    double **arr1 = new double *[n1];
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = new double[m1];
        for (int j = 0; j < m1; j++)
        {
            std::cout << "arr1[" << i << "]"
                      << "[" << j << "]=";
            std::cin >> arr1[i][j];
            std::cout << "\n";
        }
    }
    std::cout << "Nhap vao so hang cua ma tran thu hai:";
    std::cin >> n2;
    std::cout << "Nhap vao so cot cua ma tran thu hai:";
    std::cin >> m2;
    std::cout << "Nhap du lieu cua ma tran thu hai\n";
    double **arr2 = new double *[n2];
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = new double[m2];
        for (int j = 0; j < m2; j++)
        {
            std::cout << "arr2[" << i << "]"
                      << "[" << j << "]=";
            std::cin >> arr2[i][j];
            std::cout << "\n";
        }
    }
    double **c = new double *[n1];
    for (int i = 0; i < n1; i++)
        c[i] = new double[m2];
    multiply_two_matrices(arr1, arr2, n1, m1, n2, m2, c);
    display_matrix(c, n1, m2);
    free_data1(arr1, n1);
    free_data1(arr2, n2);
    free_data1(c, n1);
    
    system("pause");
    return 0;
}
