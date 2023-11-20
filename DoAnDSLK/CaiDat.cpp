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
    cout << "Nhap ID: ";
    cin >> tv.id;
    cout << "Nhap ho ten: ";
    cin.ignore();
    cin.getline(tv.hoTen, 30);
    cout << "Nhap nam sinh: ";
    cin >> tv.namSinh;
    cout << "Nhap que quan: ";
    cin.ignore();
    cin.getline(tv.queQuan, 30);
    cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
    int gender;
    cin >> gender;
    gender ==0 ? tv.gioiTinh = 0 : tv.gioiTinh = 1;
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
    cout << "ID: " << tv.id << endl;
    cout << "Ho ten: " << tv.hoTen << endl;
    cout << "Nam sinh: " << tv.namSinh << endl;
    cout << "Que quan: " << tv.queQuan << endl;
    cout << "Gioi tinh: " << tv.gioiTinh << endl;
    cout << endl;
}
void nhapTTHoKhau(TTHK& TTHK) {
    cout << "\nNhap Ma Ho khau : ";
    cin >> TTHK.maHoKhau;
    cout << "\nNhap Ten Chu Ho : ";
    cin.ignore();
    cin.getline(TTHK.tenChuHo, 20);
    cout << "\nNhap dia chi : ";
    cin.ignore();
    cin.getline(TTHK.diaChi, 20);
    nhapDSThanhVien(TTHK.dsThanhVien);

}

void xuatTTHoKhau(TTHK TTHK) {
    cout << "------------------------" << endl;
    cout << "\nMa ho khau: " << TTHK.maHoKhau << endl;
    cout << "\nTen chu ho:" << TTHK.tenChuHo<<endl;
    cout << "\nDia chi: " << TTHK.diaChi << endl;;
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