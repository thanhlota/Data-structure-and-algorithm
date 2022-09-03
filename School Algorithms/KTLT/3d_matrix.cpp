#include<iostream>
// Hàm cấp phát vùng nhớ cho ma trận 3 chiều
bool init_Array(int ****a, int x, int y, int z)
{
    *a = new (std::nothrow) int **[x];
    if (!*a)
    {
        std::cout << "Cap phat bo nho that bai";
        delete[] (* a);
        return false;
    }

    for (int i = 0; i < x; i++)
    {
        (*a)[i] = new (std::nothrow) int *[y];
        if (!(*a)[i])
        {
            std::cout << "Cap phat bo nho that bai";
            for (int u = 0; u < i; u++)
                delete[] (*a)[i];
            delete[] (* a);
            return false;
        }
        for (int j = 0; j < y; j++)
        {
            (*a)[i][j] = new (std::nothrow) int[z];
            if (!(*a)[i][j])
            {
                std::cout << "Cap phat bo nho that bai";
                for (int u = 0; u < x; u++)
                {
                    for (int o = 0; o < j; o++)
                        delete[] (*a)[u][j];
                }
                for (int u = 0; u < y; u++)
                    delete[] (*a)[i];
                delete[] (*a);
                return false;
            }
        }
    }
    return true;
}
// Hàm nhập vào ma trận cấp 3
void input_Array(int ***a, int x, int y, int z)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                std::cin >> a[i][j][k];
    }
}
// Hàm giải phóng vùng nhớ cho ma trận cấp 3
void free_Data(int ***a,int x,int y)
{
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++) delete[]a[i][j];
    }
    for(int i=0;i<x;i++) delete[]a[i];
    delete[]a;
}
int main(){
//Nhap ma trận 3 chiều và giải phóng bộ nhớ
    int ***new_arr;
    if(!init_Array(&new_arr,2,2,2)) std::cout<<"Khong du bo nho de cap phat ma tran 3 chieu";
    else input_Array(new_arr,2,2,2);
    free_Data(new_arr,2,2);
}