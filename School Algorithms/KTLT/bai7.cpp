#include <iostream>
using namespace std;
struct matrix
{
    int dong;
    int cot;
    float **matran;
    void operator=(const matrix &obj)
    {
        for (int i = 0; i < dong; i++)
        {
            delete[] matran[i];
            delete[] matran;
        }
        dong = obj.dong;
        cot = obj.cot;
        matran = new float *[dong];
        for (int i = 0; i < dong; i++)
            matran[i] = new float[cot];
        matran = obj.matran;
    }
};
void allocate_mem(matrix &mt, int dong, int cot)
{
    mt.dong = dong;
    mt.cot = cot;
    mt.matran = new float *[dong];
    for (int i = 0; i < dong; i++)
        mt.matran[i] = new float[cot];
}
matrix operator+(matrix a, matrix b)
{
    matrix c;
    allocate_mem(c, a.dong, a.cot);
    for (int i = 0; i < a.dong; i++)
    {
        for (int j = 0; j < b.cot; j++)
        {
            (c.matran)[i][j] = (a.matran)[i][j] + (b.matran)[i][j];
        }
    }
    return c;
}
matrix operator*(matrix &a, matrix &b)
{
    matrix c;
    allocate_mem(c, a.dong, b.cot);
    // std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < a.dong; i++)
    {
        for (int j = 0; j < b.cot; j++)
        {
            int k = 0;
            while (k < a.dong)
            {
                (c.matran)[i][j] += (a.matran)[i][k] * (b.matran)[k][j];
                k++;
            }
        }
    }
    return c;
}
std::istream &operator>>(std::istream &is, matrix &obj)
{
    std::cout << "Nhap so dong ma tran: ";
    is >> obj.dong;
    std::cout << "Nhap so cot ma tran: ";
    is >> obj.cot;
    allocate_mem(obj, obj.dong, obj.cot);
    for (int i = 0; i < obj.dong; i++)
    {

        for (int j = 0; j < obj.cot; j++)
        {
            std::cout << "arr1[" << i << "]"
                      << "[" << j << "]=";
            is >> obj.matran[i][j];
        }
    }
    return is;
}
std::ostream &operator<<(std::ostream &os, matrix obj)
{
    for (int i = 0; i < obj.dong; i++)
    {
        for (int j = 0; j < obj.cot; j++)
            os << obj.matran[i][j] << " ";
        os << "\n";
    }
    return os;
}

void free_data1(float **a, int n)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

int main()
{
    matrix mt1, mt2;
    std::cin >> mt1 >> mt2;
    // std::cout << mt1 << mt2;
    matrix mt3;
    allocate_mem(mt3, mt1.cot, mt1.dong);
    for (int i = 0; i < 1000; i++)
        mt3 = mt1 * mt2;
    std::cout << mt3;
    free_data1(mt1.matran, mt1.dong);
    free_data1(mt2.matran, mt2.dong);
    free_data1(mt3.matran, mt3.dong);
    system("pause");
}