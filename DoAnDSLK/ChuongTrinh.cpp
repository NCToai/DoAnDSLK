#include "ThuVien.h"

int main()
{
	Phuong phuong;
	khoiTaoDSHK(phuong.dsHoKhau);
	int option = 1;

	while (option)
	{
		cout << "\n1.Tao Phuong. ";
		cout << "\n2.Quan Ly Phuong.";
		cout << "\n3.Tim Thong Tin Ho Khau.";
		cout << "\n4.Them Ho Khau Moi.";
		cout << "\n5.Them Thanh Vien.";
		cout << "\n6.Xoa Thanh Vien. ";
		cout << "\n7.Xoa Ho Khau.";
		cout << "\n8.Sap Xep Ten Theo Alphabet.";
		cout << "\n9.Mo file.";
		cout << "\n10.Ghi file.";
		cout << "\n0.Dung Chuong Trinh.";

		cout << "\nNhap Lua Chon : ";
		cin >> option;
		system("cls");

		if (option == 1)
			nhapPhuong(phuong);
		else if (option == 2)
			xuatPhuong(phuong);
		else if (option == 3) {
			HoKhauPtr hoKhauTimThay = timHoKhau(phuong);
			if (hoKhauTimThay != NULL) {
				cout << "Ho khau duoc tim thay:" << endl;
				xuatTTHoKhau(hoKhauTimThay->data);
			}
			else {
				cout << "Khong tim thay ho khau" << endl;
			}
		}
		else if (option == 4)
			themHoKhauMoi(phuong);
		else if (option == 5)
			themNguoiVaoHoKhau(phuong);
		else if (option == 6)
		{
			xuatPhuong(phuong);
			//test
			/*string mshk="2930";
			int idtv=900 ;*/
			string mshk;
			int idtv;
			cout << "Nhap MHK: ";
			cin >> mshk;
			cout << "Nhap ID thanh vien: ";
			cin >> idtv;
			xoaThanhVien(phuong.dsHoKhau, mshk, idtv);
			xuatPhuong(phuong);
		}
		else if (option == 7)
		{
			xuatPhuong(phuong);
			string maXoa;
			cout << "Nhap MHK can xoa: ";
			cin >> maXoa;
			xoaHoKhauTheoMa(phuong.dsHoKhau, maXoa);
			cout << "\nXoa HK thanh cong!" << endl;
			xuatPhuong(phuong);
		}
		else if (option == 8)
		{
			xuatPhuong(phuong);
			string msx;
			cout << "Nhap MHK: ";
			cin >> msx;
			sapXepTheoMaHoKhau(phuong.dsHoKhau, msx);
			cout << "\nSap Xep Theo Ten Thanh Cong!" << endl;
			xuatPhuong(phuong);
		}
		else if (option == 9) {
			docFile("PhuongMoi.txt", phuong);
			cout << "\nDOC FILE THANH CONG!" << endl;
		}
		else if (option == 10)
		{
			ghiFile("PhuongMoi.txt", phuong);
			cout << "\nGHI FILE THANH CONG!" << endl;
		}

		else if (option == 0) break;
	}
	system("pause");
	return 0;
}