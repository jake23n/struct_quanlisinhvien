#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
#include <conio.h>
using namespace std;

/* tìm sinh viên có GPA cao và thất nhất                        xong
*  sắp xêp sinh viên có kí tự mssv giống cái cần tìm			xong
*  sắp xếp sinh viên theo tên
*
*/
void line()
{
	cout << endl;
	for (int i = 0; i < 80; i++)
	{
		cout << "-";
	}
	cout << endl;
}
struct max_min
{
	float max, min;
};
struct sinhvien
{
	string mssv ;
	string name;
	float GPA = 0;
	int year = 0;
};
void nhap(sinhvien& a)
{
	cout << "MSSV: "; cin >> a.mssv;
	cout << "ho va ten: ";
	cin.ignore();
	getline(cin, a.name);
	cout << "nam sinh: "; cin >> a.year;
	cout << "GPA: "; cin >> a.GPA;
	cout << endl;
}
void nhaps(sinhvien sv[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap thong tin sinh vien " << i + 1 << endl;
		nhap(sv[i]);
	}
}
void in(sinhvien a)
{
	cout << setw(14) << left << a.mssv;
	cout << setw(30) << left << a.name;
	cout << setw(15) << left << a.year;
	cout << setw(4) << right << a.GPA << endl;

}
void ins(sinhvien sv[], int& n)
{
	cout << setw(14) << left << "MSSV" << setw(30) << left << "thong tin sinh vien " << setw(15) << left << "nam sinh" << setw(4) << right << "GPA" << endl;
	for (int i = 0; i < n; i++)
	{
		in(sv[i]);
	}
}
// sap xep GPA max min
void GPAmax_min(sinhvien sv[], int n)
{
	max_min a;
	//a.max = -1;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sv[i].GPA < sv[j].GPA)
			{
				swap(sv[i].GPA, sv[j].GPA);
			}
		}
	}

	a.max = sv[0].GPA;
	a.min = sv[n - 1].GPA;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].GPA == a.max)
		{
			cout << "\n-------------sinh vien co GPA cao nhat------------------\n";
			in(sv[i]);
		}
		else if (sv[i].GPA == a.min)
		{
			cout << "\n-------------sinh vien co GPA thap nhat------------------\n";
			in(sv[i]);
		}
	}
}
// tim mssv
void inMSSV(sinhvien sv[], int n)
{
	int found;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].mssv.find("2212") != string::npos)
		{
			in(sv[i]);
			found = 1;
		}
	}
	if (found != 1)
		cout << "khong tim thay sinh vien vua nhap\n";
}
// hàm thực hiện loại sinh viên
void loai1sinhvien(sinhvien sv[], int& n, int k)
{
	for (int i = k; i < n; i++)
	{
		sv[i] = sv[i + 1];                         // dịch chuyển tất cả mảng bao gôm gpa, year, name, mssv
	}
	n--;
}
// hàm thực hiện thêm sinh viên
void them1sinhvien(sinhvien sv[], int& n, int k)
{
	line();
	// Neu k <= 0 => Them vao dau
	if (k < 0) {
		k = 0;
	}
	// Neu k >= n => Them vao cuoi
	else if (k > n) {
		k = n;
	}
	// dịch chuyển mảng để tạo ô trống trước khi thêm
	// đẩy giá trị từ phải qua trái trước đỡ bị trùng 
	for (int i = n + 1; i > k; i--)                  
	{
		sv[i] = sv[i - 1];							// dịch chuyển cả struct		

	}
	// thêm sinh viên tại vị trí k
	nhap(sv[k]);
	// Tang so luong phan tu sau khi chen.
	n++;
}
// tìm kiếm sinh viên theo tên
void timsinhvien_name(sinhvien sv[], int n)
{
	line();

	string name;
	cout << "nhap ten can tim: "; 
	cin.ignore();
	getline(cin, name);
	int found = 0;

	for (int i = 1; i < n; i++)
	{
		if (sv[i].name.find(name) != string::npos)
		{
			in(sv[i]);
			found = 1;
		}
	}
	if (found != 1)
		cout << "khong tim thay sinh vien da tim\n";
}
void sapxepsinhvien(sinhvien sv[], int n)
{
}
int main()
{
	sinhvien a, sv[100]; int n;
	cout << "nhap so luong sinh vien: ";
	cin >> n;

	nhaps(sv, n);
	ins(sv, n);

}