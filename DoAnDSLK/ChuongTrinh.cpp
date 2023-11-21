#include "ThuVien.h"

int main()
{
	Phuong phuong ;
    khoiTaoDSHK(phuong.dsHoKhau);
	int option = 1;

	while (option)
	{
        cout << "\n1.Tao Phuong. ";
        cout << "\n2.Quan Ly Phuong.";
        cout << "\n3.Nhap Thong Tin Phuong. ";
        cout << "\n4.Xuat Thong Tin Phuong. ";
        cout << "\n5.Tim Thong Tin Ho Khau.";
        cout << "\n6.Them Ho Khau Moi.";
        cout << "\n7.Them Thanh Vien.";
        cout << "\n8.Xoa Thanh Vien. ";
        cout << "\n9.Xoa Ho Khau.";
        cout << "\n10.Mo file.";
        cout << "\n11.Ghi file.";
        cout << "\n0.Dung Chuong Trinh.";

        cout << "\nNhap Lua Chon : ";
        cin >> option;
        system("cls");

        if (option == 1)
            nhapPhuong(phuong);
        else if (option == 2)
            xuatPhuong(phuong);
        else if (option == 5) {
            HoKhauPtr hoKhauTimThay = timHoKhau(phuong);
            if (hoKhauTimThay != NULL) {
                cout << "Ho khau duoc tim thay:" << endl;
                xuatTTHoKhau(hoKhauTimThay->data);
            }
            else {
                cout << "Khong tim thay ho khau" << endl;
            }
            
        }
        else if (option == 6)
            themHoKhauMoi(phuong);
        else if (option == 7)
            themNguoiVaoHoKhau(phuong);
        else if (option == 10) {
            docFile("PhuongMoi.txt", phuong);
        }
        else if (option == 11)
            ghiFile("PhuongMoi.txt", phuong);
        else if (option == 0) break;
	}
	system("pause");
	return 0;
}