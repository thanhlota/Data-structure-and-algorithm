#include <iostream>
#include <string.h>
#include <string>
#include <unistd.h>
using namespace std;
void printLine(int n);
void pressAnyKey();
int length(char c[]);
// Hàm kiểm tra tên sinh viên có bị bỏ trống
bool checkName(char name[]);
// Hàm kiem tra co sinh viên vào danh sách
bool themSV(char name[]);
// Hàm cấp phát động lại mảng 2 chiều
void realloc(char **arr, int soSV, int tenSV);
// Hàm lấy chuỗi con trong 1 chuỗi
void sub_string(char str[], int begin, int end, char temp[]);
// Hàm đảo xâu
char *convert_string(char s[]);
// Hàm sắp xếp sinh viên theo thứ tự bảng chữ cái dùng hàm đảo tên
void sapxepSV_daoten(char **arr, int soluongSV, int tenSV);
// Hàm in danh sách sinh viên
void inDS(char **arr, int soluongSV);
// Hàm xoá khoảng trắng không cần thiết
void xoa_khoang_trang(char s[]);
// Hàm viết hoa chữ cái đầU
void to_title(char str[]);
// Hàm trả lại bộ nhớ động cấp phát
void free(char **arr, int SoSV);
// Ham lấy vị trí tên trong 1 chuỗi
int location(char *arr, int end);
// Hàm so sánh tên lần lượt tên, tên đệm, họ
bool sosanhSV_lanluot(char *arr, char *brr, int end1, int end2);
// Hàm sắp xếp tên theo bảng chữ cái dùng hàm so sánh lần lượt
void sapxepSV_lanluot(char **arr, int soluongSV, int tenSV);
// Hàm main
int main()
{
    int soluongSV = 0; // Khởi tạo số lượng sinh viên
    int SoSV = 1;      // Số sinh viên lớn nhất có thể có trong danh sách
    int tenSV = 2;     //Độ dài lớn nhát của tên sinh viên trong danh sách
    char **arr = new char *[SoSV];
    for (int i = 0; i < SoSV; i++)
        arr[i] = new char[tenSV];
    char ***ptr = &arr;
    while (true)
    {
        cout << "Chuong trinh quan ly danh sach ho và ten SV don gian" << endl;
        cout << "1.Bo sung danh sach " << endl;
        cout << "2.Sap xep danh sach theo thu tu ABC " << endl;
        cout << "3.in danh sach" << endl;
        cout << "Bam phim 1-3 de chon , phim bat ky # de  KT" << endl;
        char s;
        cin >> s;
        cin.ignore();
        switch (s)
        {
        case '1':
            cout << "Moi ban bo sung sinh vien vao danh sach:" << endl;
            cout << "Moi ban nhap ten sinh vien: ";
            char *name;
            name = new char[255];
            cin.getline(name, 255);
            xoa_khoang_trang(name);
            to_title(name);
            int name_length;
            name_length = length(name);
            if (themSV(name))
            {

                if (soluongSV + 1 > SoSV)
                {
                    SoSV++;

                    realloc(arr, SoSV, tenSV);
                }
                soluongSV++;
                if (name_length > tenSV)
                {
                    tenSV = name_length;
                    realloc(arr, SoSV, tenSV);
                    arr[soluongSV - 1] = new char[name_length];
                  
                }
                arr[soluongSV - 1] = name;
                cout << "Sinh vien da duoc nhap vao thanh cong";
            }
            pressAnyKey();

            break;
        case '2':
            cout << "Sap xep danh sach sinh vien theo thu tu tu dien " << endl;
            // sapxepSV_daoten(arr, soluongSV, tenSV);
            sapxepSV_lanluot(arr,soluongSV,tenSV);
            cout << "Du lieu da duoc sap xep thanh cong";
            pressAnyKey();

            break;
        case '3':

            cout << "In danh sach \n";
            inDS(arr, soluongSV);
            pressAnyKey();

            break;
        default:
            free(arr, SoSV);
            system("cls");
            cout << "Doi 2 giay de thoat chuong trinh";
            sleep(2);
            return 0;
        }
    }
}
void printLine(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "_";
    }
    cout << endl;
}
void pressAnyKey()
{
    cout << "\n";
    system("pause");
    system("cls");
}
int length(char c[])
{
    int count = 0;
    while (c[count] != '\0')
        count++;
    return count;
}
bool checkName(char name[])
{
    int count = length(name);
    for (int i = 0; i < count; i++)
    {
        if (name[i] != 32)
            return true;
    }
    return false;
}
bool themSV(char name[])
{
    if (!checkName(name))
    {
        cout << "Khong co ten sinh vien nao duoc nhap vao";
        return false;
    }
    return true;
}
void realloc(char **arr, int soSV, int tenSV)
{
    char **brr = new char *[soSV];
    for (int i = 0; i < (soSV); i++)
        brr[i] = new char[tenSV];
    for (int i = 0; i < soSV - 1; i++)
        strcpy(brr[i], arr[i]);
    // for (int i = 0; i < soSV - 1; i++)
    //     delete[] arr[i];
    // delete[] arr;
    arr = brr;
}
void sub_string(char str[], int begin, int end, char temp[])
{
    int i = begin;
    int j = 0;
    while (i <= end)
    {
        temp[j] = str[i];
        j++;
        i++;
    }
}
char *convert_string(char s[])
{
    char *string_convert = new char[strlen(s)]{};
    int j = strlen(s) - 1;
    char temp[255];

    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            char temp[255]{};
            sub_string(s, i + 1, j, temp);
            strcat(string_convert, temp);
            strcat(string_convert, " ");
            j = i - 1;
        }
        if (i == 0)
        {
            char temp[255]{};
            sub_string(s, i, j, temp);
            strcat(string_convert, temp);
        }
    }
    return string_convert;
}
void sapxepSV_daoten(char **arr, int soluongSV, int tenSV)
{

    for (int i = 0; i < soluongSV - 1; i++)
        for (int j = i + 1; j < soluongSV; j++)
        {
            // Chỉ dùng 1 lần strcmp
            if (strcmp(convert_string(arr[i]), convert_string(arr[j])) > 0)
            {
                char *temp = new char[tenSV];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
}
void inDS(char **arr, int soluongSV)
{
    if (soluongSV == 0)
    {
        cout << "Danh sach rong!";
        return;
    }
    printLine(40);

    for (int i = 0; i < soluongSV; i++)
        cout << i + 1 << "." << arr[i] << endl;
}
void xoa_khoang_trang(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            for (int j = i; j < strlen(s); j++)
            {
                if (j == strlen(s) - 1)
                {
                    s[j] = '\0';
                    break;
                }
                s[j] = s[j + 1];
            }
            i--;
        }
    }

    if (s[0] == ' ')
        for (int j = 0; j < strlen(s); j++)
        {
            if (j == strlen(s) - 1)
            {
                s[j] = '\0';
                break;
            }
            s[j] = s[j + 1];
        }
    if (s[strlen(s) - 1] == ' ')
        s[strlen(s) - 1] = '\0';
}
void to_title(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if (str[i - 1] == ' ' || i == 0)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32;
        }
    }
}
void free(char **arr, int SoSV)
{
    for (int i = 0; i < SoSV; i++)
        delete[] arr[i];
    delete[] arr;
}
int location(char *arr, int end)
{
    int count = end;
    for (;; count--)
    {
        if (arr[count] == ' ' || count == 0)
            break;
    }
    return count;
}
bool sosanhSV_lanluot(char *arr, char *brr, int end1, int end2)
{
    if (end1 == 0 && end2 == 0)
        return false;
    char temp1[10]{};
    char temp2[10]{};
    int begin1 = location(arr, end1);
    int begin2 = location(brr, end2);
    sub_string(arr, begin1, end1, temp1);
    sub_string(brr, begin2, end2, temp2);
    if (strcmp(temp1, temp2) > 0)
        return true;
    else if (strcmp(temp1, temp2) < 0)
        return false;
    else
    {
        end1 = begin1 - 1;
        end2 = begin2 - 1;
        return sosanhSV_lanluot(arr, brr, end1, end2);
    }
}
void sapxepSV_lanluot(char **arr, int soluongSV, int tenSV)
{
    for (int i = 0; i < soluongSV - 1; i++)
        for (int j = i + 1; j < soluongSV; j++)
        {
            // Chỉ dùng 1 lần strcmp
            if (sosanhSV_lanluot(arr[i], arr[j], strlen(arr[i]) - 1, strlen(arr[j]) - 1))
            {
                char *temp = new char[tenSV];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
}