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
	for (int i = 0; i < 81; i++) {
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
		dongGachNgang();
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
	cout << "\nNhap ID Chu Ho : ";
	cin >> TTHK.idChuHo;
	cin.ignore();
	cout << "\nNhap dia chi : ";
	cin.getline(TTHK.diaChi, 20);
	nhapDSThanhVien(TTHK.dsThanhVien);
}
void xuatTTHoKhau(TTHK TTHK) {
	cout << "\n__________________________________________________[ HO KHAU ]_______________________________________________" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << "|"
		<< left << setw(10) << "MHK" << "|"
		<< left << setw(22) << "CHU HO" << "|"
		<< left << setw(22) << "ID CHU HO" << "|"
		<< left << setw(22) << "DIA CHI" << "|"
		<< left << setw(22) << "THANH VIEN" << "|" << endl;

	cout << "|"
		<< left << setw(10) << TTHK.maHoKhau << "|"
		<< left << setw(22) << TTHK.tenChuHo << "|"
		<< left << setw(22) << TTHK.idChuHo << "|"
		<< left << setw(22) << TTHK.diaChi << "|"
		<< left << setw(22) << demSoThanhVien(TTHK.dsThanhVien) << "|" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	dongGachNgang();
	dongTieuDe();
	dongGachNgang();
	xuatDSThanhVien(TTHK.dsThanhVien);

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
	string maHoKhau;
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
	if (thanhVienMoi.id == hoKhauNode->data.dsThanhVien->data.id)
	{
		cout << "\nMA ID DA TON TAI. KHONG THEM DUOC MA !" << endl;
	}
	else
	{
		ThanhVienPtr thanhVienNode = taoNodeThanhVien(thanhVienMoi);
		thanhVienNode->next = hoKhauNode->data.dsThanhVien;
		hoKhauNode->data.dsThanhVien = thanhVienNode;
	}
}
void themHoKhauMoi(Phuong& phuong) {
	TTHK hoKhauMoi;
	nhapTTHoKhau(hoKhauMoi);
	bool isMaHoKhauTrung = false;
	HoKhauPtr currentHoKhau = phuong.dsHoKhau;
	while (currentHoKhau != NULL) {
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
	string maTimKiem;
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
		file << p->data.idChuHo << endl;
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
		file >> newHoKhau.idChuHo;
		file.ignore();
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
void xoaHoKhauTheoMa(HoKhauPtr& danhSachHoKhau, string maHoKhau) {
	if (danhSachHoKhau == NULL) {
		cout << "Ho khau rong." << endl;
		return;
	}
	HoKhauPtr hkHienTai = danhSachHoKhau;
	HoKhauPtr hkTruoc = NULL;
	while (hkHienTai != NULL && (hkHienTai->data.maHoKhau != maHoKhau))
	{
		hkTruoc = hkHienTai;
		hkHienTai = hkHienTai->next;
	}
	if (hkHienTai == NULL) {
		cout << "Khong tim thay ma ho khau can xoa." << endl;
		return;
	}
	//thuc hien xoa co ma hk trung vs mk trong ds
	if (hkTruoc == NULL) {
		danhSachHoKhau = danhSachHoKhau->next;
	}
	else {
		hkTruoc->next = hkHienTai->next;
	}
	delete hkHienTai;
}
void swap(ThanhVienPtr a, ThanhVienPtr b) {
	TTTV temp = a->data;
	a->data = b->data;
	b->data = temp;
}
void sapXepTheoMaHoKhau(HoKhauPtr danhSachHoKhau, string maHoKhau) {
	HoKhauPtr hoKhau = danhSachHoKhau;

	while (hoKhau != NULL) {
		if (hoKhau->data.maHoKhau == maHoKhau) {
			ThanhVienPtr danhSachThanhVien = hoKhau->data.dsThanhVien;
			bool swapped;
			ThanhVienPtr ptr1;
			ThanhVienPtr lptr = NULL;
			if (danhSachThanhVien == NULL)
				return;
			do {
				swapped = false;
				ptr1 = danhSachThanhVien;
				while (ptr1->next != lptr) {
					//so sach chuoi
					if (strcmp(ptr1->data.hoTen, ptr1->next->data.hoTen) > 0) {
						swap(ptr1, ptr1->next);
						swapped = true;
					}
					ptr1 = ptr1->next;
				}
				lptr = ptr1;
			} while (swapped);
		}
		hoKhau = hoKhau->next;
	}
}
void xoaThanhVien(HoKhauPtr& dSachHoKhau, string maHoKhau, int idThanhVien)
{
	HoKhauPtr hkHienTai = dSachHoKhau;
	//tim hk can xoa tv
	while (hkHienTai != nullptr && hkHienTai->data.maHoKhau != maHoKhau)
	{
		hkHienTai = hkHienTai->next;
	}
	if (hkHienTai == nullptr)
	{
		cout << "HO KHAU KHONG TON TAI!!" << endl;
		return;
	}
	else
	{
		ThanhVienPtr tvHienTai = hkHienTai->data.dsThanhVien;
		ThanhVienPtr tvTruocDo = nullptr;
		// tim tv can xoa 
		while (tvHienTai != NULL && tvHienTai->data.id != idThanhVien)
		{
			tvTruocDo = tvHienTai;
			tvHienTai = tvHienTai->next;
		}
		if (idThanhVien == hkHienTai->data.idChuHo)
		{
			int idThanhVienThayThe;
			cout << "NHAP ID NGUOI THAY THE: ";
			cin >> idThanhVienThayThe;
			ThanhVienPtr thanhVienThayThe = timThanhVienTheoID(hkHienTai->data.dsThanhVien, idThanhVienThayThe);
			if (thanhVienThayThe == nullptr) {
				cout << "KHONG TIM THAY THANH VIEN THAY THE!!" << endl;
				return;
			}
			else
			{
				hkHienTai->data.idChuHo = idThanhVienThayThe;
				strncpy(hkHienTai->data.tenChuHo, thanhVienThayThe->data.hoTen, 20);
				// sau khi doi chu moi thanh vien do trong danh sach bi loai bo va dua tv khac len
				hkHienTai->data.dsThanhVien = thanhVienThayThe->next;
				delete thanhVienThayThe;
				cout << "THAY THE CHU HO THANH CONG!" << endl;
			}
		}
		else
		{
			if (tvHienTai == nullptr)
			{
				cout << "THANH VIEN KHONG TON TAI TRONG HO KHAU!!" << endl;
				return;
			}
			
			if (tvTruocDo == nullptr)
				hkHienTai->data.dsThanhVien = tvHienTai->next;
			else
				tvTruocDo->next = tvHienTai->next;
			delete tvHienTai;
			cout << "XOA THANH CONG THANH VIEN!" << endl;
		}
	}
}
ThanhVienPtr timThanhVienTheoID(ThanhVienPtr danhSach, int id) {
	ThanhVienPtr current = danhSach;
	while (current != nullptr) {
		if (current->data.id == id) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}