﻿#include "ThuVien.h"

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
    cout << "Nhap nam sinh thanh vien: ";
    cin >> tv.namSinh;
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

    cout << "ID thanh vien: " << tv.id << endl;
    cout << "Ten thanh vien: " << tv.hoTen << endl;
    cout << "Nam sinh thanh vien: " << tv.namSinh << endl;
    cout << "Que quan thanh vien: " << tv.queQuan << endl;
    cout << "Gioi tinh thanh vien: " << (tv.gioiTinh ? "Nam" : "Nu") << endl;
    cout << endl;
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
    cout << "------------------------" << endl;
    cout << "\nMa ho khau: " << TTHK.maHoKhau << endl;
    cout << "\nTen chu ho:" << TTHK.tenChuHo<<endl;
    cout << "\nDia chi: " << TTHK.diaChi << endl;
    cout << "\nDem So thanh vien : " << demSoThanhVien(TTHK.dsThanhVien) << endl;
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

    HoKhauPtr hoKhauNode = taoNodeHoKhau(hoKhauMoi);
    themHoKhau(phuong.dsHoKhau, hoKhauMoi);
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
        
        if(n!=0)themHoKhauMoiFile(phuong, newHoKhau);
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


