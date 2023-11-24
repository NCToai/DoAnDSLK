#include "ThuVien.h"

void khoiTaoDSTV(ThanhVienPtr& DSTV) {
	DSTV = NULL;
}
void khoiTaoDSHK(HoKhauPtr& DSHK) {
	DSHK = NULL;
}
ThanhVienPtr taoNodeThanhVien(TTTV x) {
	ThanhVienPtr p = new ThanhVien;
	p->data = x;
	p->next = NULL;
	return p;
}
HoKhauPtr taoNodeHoKhau(TTHK x) {
	HoKhauPtr p = new HoKhau;
	p->data = x;
	p->next = NULL;
	return p;

}
void nhapTTThanhVien(TTTV& tv) {
	cout << "Nhap ID thanh vien: ";
	cin >> tv.id;
	cout << "Nhap ho ten thanh vien: ";
	cin.ignore();
	cin.getline(tv.hoTen, 30);

	bool isValidYear;
	do {
		cout << "Nhap nam sinh thanh vien: ";
		cin >> tv.namSinh;

		if (tv.namSinh >= 1900 && tv.namSinh <= 2023) {
			isValidYear = true;
		}
		else {
			cout << "Nam sinh khong hop le. Vui long nhap lai.\n";
			isValidYear = false;
		}
	} while (isValidYear == false);

	cout << "Nhap que quan thanh vien: ";
	cin.ignore();
	cin.getline(tv.queQuan, 30);
	cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
	int gender;
	cin >> gender;
	gender == 0 ? tv.gioiTinh = 0 : tv.gioiTinh = 1;
}

ThanhVienPtr ThemThanhVien(ThanhVienPtr& DSTV, TTTV x) {
	ThanhVienPtr p = taoNodeThanhVien(x);
	p->next = DSTV;
	DSTV = p;

	return p;
}
HoKhauPtr themHoKhau(HoKhauPtr& DSHK, TTHK x) {
	HoKhauPtr p = taoNodeHoKhau(x);
	p->next = DSHK;
	DSHK = p;
	return p;
}
void dongTieuDe() {
	cout << "|"
		<< left << setw(8) << "ID" << "|"
		<< left << setw(22) << "HO VA TEN" << "|"
		<< left << setw(10) << "NAM SINH" << "|"
		<< left << setw(11) << "GIOI TINH" << "|"
		<< left << setw(24) << "QUE QUAN" << "|";
	cout << endl;
}
void dongGachNgang() {
	for (int i = 0; i < 133; i++) {
		cout << "-";
	}
	cout << endl;
}

void nhapDSThanhVien(ThanhVienPtr& DSTV) {
	khoiTaoDSTV(DSTV);
	int option = 1;
	do {
		TTTV x;
		nhapTTThanhVien(x);
		ThemThanhVien(DSTV, x);
		cout << "\nNhap tiep thanh vien khac (0: Khong, 1: Co): ";
		cin >> option;
		option != 0 ? option = 1 : option = 0;
	} while (option != 0);
}

void xuatDSThanhVien(ThanhVienPtr DSTV) {
	ThanhVienPtr p = DSTV;
	while (p != NULL) {
		xuatTTThanhVien(p->data);
		p = p->next;
	}
}

void xuatTTThanhVien(TTTV tv) {
	cout << "|"
		<< right << setw(8) << tv.id << "|"
		<< left << setw(22) << tv.hoTen << "|"
		<< right << setw(10) << tv.namSinh << "|"
		<< left << setw(11) << (tv.gioiTinh ? "Nam" : "Nu") << "|"
		<< left << setw(24) << tv.queQuan << "|" << endl;

}
void nhapTTHoKhau(TTHK& TTHK) {
	cout << "\nNhap Ma Ho khau : ";
	cin >> TTHK.maHoKhau;
	cout << "\nNhap Ten Chu Ho : ";
	cin.ignore();
	cin.getline(TTHK.tenChuHo, 20);
	cout << "\nNhap dia chi : ";
	cin.getline(TTHK.diaChi, 20);
	nhapDSThanhVien(TTHK.dsThanhVien);

}

void xuatTTHoKhau(TTHK TTHK) {
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "|"
		<< left << setw(5) << "MHK" << "|"
		<< left << setw(22) << "CHU HO" << "|"
		<< left << setw(22) << "DIA CHI" << "|"
		<< left << setw(22) << "THANH VIEN" << "|" << endl;

	cout << "|"
		<< left << setw(5) << TTHK.maHoKhau << "|"
		<< left << setw(22) << TTHK.tenChuHo << "|"
		<< left << setw(22) << TTHK.diaChi << "|"
		<< left << setw(22) << demSoThanhVien(TTHK.dsThanhVien) << "|" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << endl;
	dongTieuDe();
	xuatDSThanhVien(TTHK.dsThanhVien);
	cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

}
void nhapDSHoKhau(HoKhauPtr& DSHK) {
	khoiTaoDSHK(DSHK);
	int option = 1;
	do {
		TTHK x;
		nhapTTHoKhau(x);
		themHoKhau(DSHK, x);
		cout << "\nNhap tiep ho khau khac (0: Khong, 1: Co): ";
		cin >> option;
		option != 0 ? option = 1 : option = 0;
	} while (option != 0);
}
void xuatDSHoKhau(HoKhauPtr DSHK) {
	HoKhauPtr p = DSHK;

	while (p != NULL) {
		xuatTTHoKhau(p->data);
		p = p->next;
	}
}

void nhapPhuong(Phuong& phuong)
{
	cin.ignore();
	cout << "\nNhap ten phuong: ";
	cin.getline(phuong.tenPhuong, 20);
	nhapDSHoKhau(phuong.dsHoKhau);
}
void xuatPhuong(Phuong phuong)
{
	cout << "\nTen phuong: " << phuong.tenPhuong << endl;
	xuatDSHoKhau(phuong.dsHoKhau);
}

void themNguoiVaoHoKhau(Phuong& phuong) {
	int maHoKhau;
	cout << "\nNhap ma ho khau can them: ";
	cin >> maHoKhau;

	HoKhauPtr hoKhauNode = phuong.dsHoKhau;
	while (hoKhauNode != NULL) {
		if (hoKhauNode->data.maHoKhau == maHoKhau) {
			break;
		}
		hoKhauNode = hoKhauNode->next;
	}

	if (hoKhauNode == NULL) {
		cout << "Khong tim thay ho khau co ma " << maHoKhau << endl;
		return;
	}

	TTTV thanhVienMoi;
	nhapTTThanhVien(thanhVienMoi);

	ThanhVienPtr thanhVienNode = taoNodeThanhVien(thanhVienMoi);
	thanhVienNode->next = hoKhauNode->data.dsThanhVien;
	hoKhauNode->data.dsThanhVien = thanhVienNode;
}
void themHoKhauMoi(Phuong& phuong) {
	TTHK hoKhauMoi;
	nhapTTHoKhau(hoKhauMoi);

	bool isMaHoKhauTrung = false;
	HoKhauPtr currentHoKhau = phuong.dsHoKhau;
	while (currentHoKhau != nullptr) {
		if (currentHoKhau->data.maHoKhau == hoKhauMoi.maHoKhau) {
			isMaHoKhauTrung = true;
			break;
		}
		currentHoKhau = currentHoKhau->next;
	}

	if (isMaHoKhauTrung) {
		cout << "Ma ho khau da ton tai.\n";
	}
	else {
		HoKhauPtr hoKhauNode = taoNodeHoKhau(hoKhauMoi);
		themHoKhau(phuong.dsHoKhau, hoKhauMoi);
	}
}

HoKhauPtr timHoKhau(Phuong phuong) {
	int maTimKiem;
	cout << "Nhap ma ho khau can tim: ";
	cin >> maTimKiem;
	HoKhauPtr p = phuong.dsHoKhau;
	while (p != NULL) {
		if (p->data.maHoKhau == maTimKiem) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}
/*Xoa theo vi tri va chi so*/
//void xoaThanhVien(HoKhauPtr& dsHoKhau, int chiSoHoKhau, int chiSoThanhVien) {
//	if (chiSoHoKhau == -1) {
//		cout << "Ho khau khong ton tai!!" << endl;
//	}
//	else {
//		HoKhauPtr currentHoKhau = dsHoKhau;
//		int hoKhauIndex = 0;
//
//		// Tìm ho khau cần xóa thành viên
//		while (currentHoKhau != nullptr && hoKhauIndex < chiSoHoKhau) {
//			currentHoKhau = currentHoKhau->next;
//			hoKhauIndex++;
//		}
//
//		if (currentHoKhau == nullptr) {
//			cout << "Ho khau khong ton tai!!" << endl;
//		}
//		else {
//			ThanhVienPtr currentThanhVien = currentHoKhau->data.dsThanhVien;
//			ThanhVienPtr previousThanhVien = nullptr;
//			int thanhVienIndex = 0;
//
//			// Tìm thành viên cần xóa trong ho khau
//			while (currentThanhVien != nullptr && thanhVienIndex < chiSoThanhVien) {
//				previousThanhVien = currentThanhVien;
//				currentThanhVien = currentThanhVien->next;
//				thanhVienIndex++;
//			}
//
//			if (currentThanhVien == nullptr) {
//				cout << "Thanh vien khong ton tai!!" << endl;
//			}
//			else {
//				// Xóa thành viên
//				if (previousThanhVien == nullptr) {
//					// Thành viên cần xóa là thành viên đầu tiên trong danh sách
//					currentHoKhau->data.dsThanhVien = currentThanhVien->next;
//				}
//				else {
//					previousThanhVien->next = currentThanhVien->next;
//				}
//
//				delete currentThanhVien;
//				cout << "Xoa thanh vien thanh cong!" << endl;
//			}
//		}
//	}
//}
/*xoa theo id va mhk*/
void xoaThanhVien(HoKhauPtr& dsHoKhau, int maHoKhau, int idThanhVien) {
	HoKhauPtr currentHoKhau = dsHoKhau;

	// Tìm ho khau cần xóa thành viên
	while (currentHoKhau != nullptr && currentHoKhau->data.maHoKhau != maHoKhau) {
		currentHoKhau = currentHoKhau->next;
	}

	if (currentHoKhau == nullptr) {
		cout << "Ho khau khong ton tai!!" << endl;
		return;
	}

	ThanhVienPtr currentThanhVien = currentHoKhau->data.dsThanhVien;
	ThanhVienPtr previousThanhVien = nullptr;

	// Tìm thành viên cần xóa trong ho khau
	while (currentThanhVien != nullptr && currentThanhVien->data.id != idThanhVien) {
		previousThanhVien = currentThanhVien;
		currentThanhVien = currentThanhVien->next;
	}

	if (currentThanhVien == nullptr) {
		cout << "Thanh vien khong ton tai!!" << endl;
		return;
	}

	// Xóa thành viên
	if (previousThanhVien == nullptr) {
		// Thành viên cần xóa là thành viên đầu tiên trong danh sách
		currentHoKhau->data.dsThanhVien = currentThanhVien->next;
	}
	else {
		previousThanhVien->next = currentThanhVien->next;
	}

	delete currentThanhVien;
	cout << "Xoa thanh vien thanh cong!" << endl;
}
void ghiFile(string filename, Phuong phuong) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file." << endl;
		return;
	}
	file << phuong.tenPhuong << endl;
	HoKhauPtr p = phuong.dsHoKhau;
	while (p != NULL) {
		file << p->data.maHoKhau << endl;
		file << p->data.tenChuHo << endl;
		file << p->data.diaChi << endl;
		file << demSoThanhVien(p->data.dsThanhVien) << endl;
		xuatDSThanhVienFile(p->data.dsThanhVien, file);
		p = p->next;
	}
	file.close();
}

void xuatDSThanhVienFile(ThanhVienPtr DSTV, ofstream& file) {
	ThanhVienPtr p = DSTV;
	while (p != NULL) {
		file << p->data.id << endl;
		file << p->data.hoTen << endl;
		file << p->data.namSinh << endl;
		file << p->data.queQuan << endl;
		file << p->data.gioiTinh << endl;
		p = p->next;
	}
}

int demSoThanhVien(ThanhVienPtr DSTV) {
	int dem = 0;
	ThanhVienPtr p = DSTV;
	while (p != NULL) {
		dem++;
		p = p->next;
	}
	return dem;
}
void docFile(string filename, Phuong& phuong) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Khong the mo file." << endl;
		return;
	}
	khoiTaoDSHK(phuong.dsHoKhau);
	TTHK newHoKhau;

	file.ignore();
	file >> phuong.tenPhuong;
	file.ignore();

	while (!file.eof()) {
		int n;
		file >> newHoKhau.maHoKhau;
		file.ignore();
		file.getline(newHoKhau.tenChuHo, 20);
		//file.ignore();
		file.getline(newHoKhau.diaChi, 20);


		file >> n;
		file.ignore();
		khoiTaoDSTV(newHoKhau.dsThanhVien);
		for (int i = 0; i < n; i++) {
			TTTV newThanhVien;
			file >> newThanhVien.id;
			file.ignore();
			file.getline(newThanhVien.hoTen, 30);

			file >> newThanhVien.namSinh;
			file.ignore();
			file.getline(newThanhVien.queQuan, 30);

			int gioiTinh;
			file >> gioiTinh;
			file.ignore();
			newThanhVien.gioiTinh = gioiTinh != 0;
			themNguoiVaoHoKhauFile(newHoKhau, newThanhVien);
		}

		if (n != 0)themHoKhauMoiFile(phuong, newHoKhau);
		n = 0;

	}
	file.close();
}
void themHoKhauMoiFile(Phuong& phuong, TTHK x) {
	HoKhauPtr p = taoNodeHoKhau(x);
	p->next = phuong.dsHoKhau;
	phuong.dsHoKhau = p;
}
void themNguoiVaoHoKhauFile(TTHK& hoKhau, TTTV x) {
	ThanhVienPtr newThanhVien = taoNodeThanhVien(x);
	newThanhVien->next = hoKhau.dsThanhVien;
	hoKhau.dsThanhVien = newThanhVien;
}