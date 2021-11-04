
#include <iostream>
#include <limits>
#include <fstream>
using namespace std;

// void readfromfile(std::string filename){
//     std::ifstream fileinput{filename};
//     if (fileinput.fail()){
// 	std::cout << "Failed to open this file!" << std::endl;  system("pause");}
//     else cout<<"Success!";
//     while (!fileinput.eof())
// 	{
//     char temp[255];
// 	fileinput.getline(temp, 255);
// 	std::string line = temp;
// 	std::cout << line << std::endl;
// 	}
// 	std::cout << std::endl;
// 	fileinput.close();
//     system("pause");
// }
// void writetofile(std::string filename){
//     std::fstream fileOutput(filename,std::ios::out|std::ios::binary);

// 	if (fileOutput.fail())
// 	{
// 		std::cout << "Cannot open file at " << filename << std::endl;
// 		return;
// 	}

// 	fileOutput << "File has been changed" << std::endl;
// }
void readfromfile(string filename, int &n, int arr[])
{
    ifstream file{filename};
    if (file.fail())
    {
        cout << "Cannot relate to file";
        system("pause");
    }
    file >> n;
    int i = 0;
    while (!file.eof())
    {
        file >> arr[i];
        i++;
    }
    file.close();
}
void initfile(string filename)
{
    string s{"Load data"};
    ofstream file{filename};
    if (file.fail())
    {
        cout << "Cannot relate to file";
        system("pause");
    }
    file << s;
}
int main()
{
    int n;
    int *arr = new int[n];
    readfromfile("bai2.txt", n, arr);
    int s = arr[0];
    int max = arr[0];
    int end = 0;
    int begin = 0;
    for (int i = 1; i < n; i++)
    {
        if (s > 0)
            s = arr[i] + s;
        else
            s = arr[i];
        if (s > max)
        {
            max = s;
            end = i;
        }
    }
    int a = max;
    int i = end;
    while (a != 0)
    {
        a = a - arr[i];
        if (a == 0)
        {
            begin = i;
            break;
        }
        --i;
    }
    cout << max << endl;
    for (int k = begin; k <= end; k++)
        cout << arr[k] << " ";
    delete[] arr;
    system("pause");
    return 0;
    //    initfile("Test.txt");
    //    system("pause");
}