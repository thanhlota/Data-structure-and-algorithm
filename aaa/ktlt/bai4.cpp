#include <iostream>
#include <string.h>
#include <unistd.h>
#include<fstream>
using namespace std;
#define SoSV 100
#define tenSV 30
char arr[SoSV][tenSV];
int soluongSV = 0;
void to_title(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        if (str[i - 1] == ' ' || i == 0)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32;
        }
    }
}
void readfromfile(string s1){
    fstream f{s1,std::ios::in};
    if(f.fail()) {cout<<"File khong ton tai";return;}
    soluongSV=0;
    while(!f.eof()){
    char temp[SoSV];
    f.getline(temp,SoSV,'.');
    strcpy(temp,"");
    f.getline(temp,SoSV);
    strcpy(arr[soluongSV],temp);
    strcpy(temp,"");
    soluongSV++;
    }
    soluongSV--;
    f.close();
}
void printTofile(string s1){
    fstream f{s1,std::ios::out|std::ios::trunc};
    if(f.fail()) {cout<<"File khong ton tai";return;}
    int i=0;
    for(int i=0;i<soluongSV;i++) 
        f<<i+1<<"."<<arr[i]<<endl;
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
bool checkName(char name[])
{
    int count = 0;
    while (name[count] != '\0')
        count++;
    for (int i = 0; i < count; i++)
    {
        if (name[i] != 32)
            return true;
    }
    return false;
}
void themSV(char name[])
{

    if (!checkName(name))
    {
        cout << "Khong co du lieu sinh vien nao duoc nhap vao";
        return;
    }
    if ((soluongSV + 1) > SoSV)
    {
        cout << "Da vuot qua so luong "<<SoSV<<" sinh vien";
        return;
    }
    to_title(name);
    soluongSV = soluongSV + 1;
    strcpy(arr[soluongSV - 1], name);
    cout << "Du lieu sinh vien duoc nhap vao thanh cong";
    printTofile("input.txt");
}
void sapxepSV()
{
    for (int i = 0; i < soluongSV - 1; i++)
        for (int j = i + 1; j < soluongSV; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                char temp[tenSV];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
     printTofile("input.txt");
}
void inDS()
{
    readfromfile("input.txt");
    if (soluongSV == 0)
    {
        cout << "Danh sach rong!";
        return;
    }
    printLine(40);
    
     for (int i = 0; i < soluongSV; i++)
        cout << i + 1 <<"."<< arr[i] << endl;
}
int main()
{
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
            char name[tenSV];

            cin.getline(name, tenSV);
            themSV(name);
            pressAnyKey();
            break;
        case '2':
            cout << "Sap xep danh sach sinh vien theo thu tu tu dien " << endl;
            sapxepSV();
            cout << "Du lieu da duoc sap xep thanh cong";
            pressAnyKey();
            break;
        case '3':
            cout << "In danh sach \n";
            inDS();
            pressAnyKey();
            break;
        default:
            system("cls");
            cout << "Doi 2 giay de thoat chuong trinh";
            sleep(2);
            return 0;
        }
    }
}