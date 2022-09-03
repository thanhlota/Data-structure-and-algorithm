
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#define MAX 100
 
/*
    hàm kiểm tra ma trận có phải ma trận chéo không
*/
bool is_diagonal(int a[][100], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // Nếu có một phần tử bất kỳ nằm ngoài đường chéo chính khác 0 => sai
            // Vì các phần tử ngoài đường chéo chính sẽ có chỉ số hàng(i) khác chỉ số cột (j) nên có điều kiện i != j
            if(i != j && a[i][j] != 0) return false;
        }
    }
    // Nếu không xảy ra if trên kia, thì đây là ma trận đường chéo.
    return true;
}
 
 
/*
    hàm này đọc ma trận từ file text
    string file: đường dẫn file text
    int arr[][]: Ma trận 2 chiều sẽ lưu ma trận đọc được, ma trận mặc định truyền theo tham chiếu
    int &size: Kích thước của ma trận, vì là ma trận vuông nên số hàng = số cột. 
    Dùng tham chiếu để biến trong hàm main cũng bị thay đổi
 
*/
bool matrix_reader(string file, int arr[][MAX], int &size){
    size = -1; // Khởi tạo kích thước ma trận là -1. Tức là chưa biết kích thước
    std::ifstream input(file);
    string line;
    // Dòng này bỏ qua tên ma trận, đọc tên ma trận làm gì đâu :(((
    getline( input, line );
    // Đọc lần lượt từng dòng còn lại
    int rows, cols; // Khai báo chỉ số hàng, cột
    // Vòng for này sẽ tăng dần chỉ số hàng
    for(rows = 0; getline( input, line ); ++rows)
    {
        string element = "";
        cols = 0; // Bắt đầu mỗi hàng, cho chỉ số cột khởi tạo = 0
        for(int t = 0; t < line.length(); ++t){
            if(line[t] != ' '){
                // Nếu ký tự hiện tại khác dấu cách => nối vào biến element
                element += line[t];
            }
            // Nếu ký tự hiện tại là dấu cách, hoặc là ký tự cuối của hàng
            if(line[t] == ' ' || t == line.length() - 1){
                // Thực hiện chuyển string thành số int dùng hàm atoi
                // Hàm atoi nhận vào biến kiểu char*, nên cần dùng .c_str() để chuyển từ string về char*
                arr[rows][cols] = atoi(element.c_str());
                // Tăng chỉ số cột
                cols++;
                // Đặt lại giá trị element
                element = ""; 
            }
        }
        // Nếu chưa gán giá trị kích thước ma trận thì gán trước.
        // Hiểu luôn là nó lấy số phần tử của hàng đầu tiên làm giá trị khởi tạo cho kích thước ma trận
        if(size == -1) size = cols;
        // Nếu số cột của một hàng bất kỳ khác kích thước => ko phải ma trận vuông
        if(size != cols) return false;
    }
    // Nếu số hàng của ma trận khác kích thước => ko phải ma trận vuông
    if(size != rows) return false;
    return true;
}
 
/*
    hàm này xuất ma trận ra thôi
*/
void print_matrix(int a[][MAX], int size){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; j++){
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
}
 
 
int main(){
    int arr[MAX][MAX];
    int size;
    int n,m;
    if(matrix_reader("input.txt", arr, size)){
        // Nếu ko muốn xuất ma trận thì xóa dòng này đi
        print_matrix(arr, size);
        // Nếu là ma trận đường chéo
        if(is_diagonal(arr, size)){
            cout << "Day la ma tran duong cheo!";
        }else{
            cout << "Day khong phai ma tran duong cheo!";
        }
    }else{
        cout << "Day khong phai ma tran vuong!";
    }
    int **ptr = new int*[n];
    for(int i=0;i<n;i++) ptr[i]=new int[m];
    system("pause");
}