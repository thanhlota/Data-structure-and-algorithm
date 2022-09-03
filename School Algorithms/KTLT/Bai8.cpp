#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
struct mon_hoc
{
    string maMH;
    int sotinchi;
    int sotinchiLT;
    int sotinchiTH;
    int sotinchihocphi;
    string loaigio;
};
typedef mon_hoc MH;
struct Hoc_Sinh
{
    string mahocvien;
    string ten;
    int soluongmonhoc;
    int sotien1tinchi;
    int hocphi;
    int sotiendanop;
    int sotienconlai;
};
typedef Hoc_Sinh HS;
int soluonghs = 0;
int soluongmonhoc = 0;
vector<MH> thongtinmonhoc;
vector<HS> thongtinhocsinh;
void pressAnyKey()
{
    cout << "\n";
    system("pause");
    system("cls");
}
void on_screen()
{
    cout << "De2_6_IT3040_20211" << endl;
    cout << "Thi sinh thi bu:" << endl;
    cout << "Ta Huu Tien Thanh - MSSV: 20194175 - Ma lop TH: 710822" << endl;
    cout << "** CHUONG TRINH QUAN LY HOC PHI **" << endl;
    cout << "**1. Nhap cac sinh vien va mon hoc " << endl;
    cout << "**2. In ds sinh vien va hoc phi cac mon **" << endl;
    cout << "**0. Thoat                              **" << endl;
    cout << "******************************************" << endl;
    cout << "**Nhap lua chon cua ban*******************" << endl;
}
bool check_hocvien(HS hocsinhmoi)
{
    for (int i = 0; i < soluonghs; i++)
    {
        if (thongtinhocsinh[i].mahocvien == hocsinhmoi.mahocvien)
            return false;
    }
    return true;
}
bool check_monhoc(MH monhocmoi)
{
    for (int i = 0; i < soluongmonhoc; i++)
    {
        if (thongtinmonhoc[i].maMH == monhocmoi.maMH)
            return false;
    }
    return true;
}
int main()
{
    while (1)
    {
        system("cls");
        on_screen();
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "Ban da lua chon nhap sinh vien va mon hoc tuong ung"
                 << "\n";
            cout << "Nhap thong tin cua sv : " << '\n';
            cout << "Nhap ma ten cua sv: "<< "\n";
            cout << "Nhap ho va ten cua sv: ";
            string tmp1;
            getline(cin, tmp1);
            cout << "Nhap so mon hoc: ";
            int tmp2;
            cin >> tmp2;
            cout << "So tien mot tin chi: ";
            int tmp3;
            cin >> tmp3;
            for (int i = 0; i < tmp2; i++)
            {
                cout << "Mon hoc thu " << i + 1 << endl;
                cout << "Ma mon hoc: ";
                string maMH1;
                getline(cin, maMH1);
            }
        }
        }
    }
}