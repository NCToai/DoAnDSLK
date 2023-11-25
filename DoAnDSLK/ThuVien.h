#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct TTTV {
    int id;
    char hoTen[20];
    int namSinh;
    char queQuan[20];
    bool gioiTinh;

};

struct ThanhVien {
    TTTV data;
    ThanhVien* next;
};
typedef ThanhVien* ThanhVienPtr;

struct TTHK {
    string maHoKhau;
    char tenChuHo[20] {};
    char diaChi[20] {};
    ThanhVienPtr dsThanhVien {};
};

struct HoKhau {
    TTHK data;
    HoKhau* next {};
};
typedef HoKhau* HoKhauPtr;

struct Phuong {
    char tenPhuong[20];
    HoKhauPtr dsHoKhau;
};

void khoiTaoDSTV(ThanhVienPtr& DSTV);
void khoiTaoDSHK(HoKhauPtr& DSHK);
void dongTieuDe();
void dongGachNgang();
ThanhVienPtr taoNodeThanhVien(TTTV x);
HoKhauPtr taoNodeHoKhau(TTHK x);

void nhapTTThanhVien(TTTV& tv);
void nhapDSThanhVien(ThanhVienPtr& DSTV);

void xuatTTThanhVien(TTTV tv);
void xuatDSThanhVien(ThanhVienPtr DSTV);

void nhapTTHoKhau(TTHK& hoKhau);
void xuatTTHoKhau(TTHK hoKhau);

void nhapDSHoKhau(HoKhauPtr& DSHK);
void xuatDSHoKhau(HoKhauPtr DSHK);

ThanhVienPtr ThemThanhVien(ThanhVienPtr& DSTV, TTTV x);
HoKhauPtr themHoKhau(HoKhauPtr& DSHK, TTHK x);

void nhapPhuong(Phuong& phuong);
void xuatPhuong(Phuong phuong);

void xoaThanhVien(HoKhauPtr& dsHoKhau, string maHoKhau, int idThanhVien);
void xoaHoKhauTheoMa(HoKhauPtr& danhSachHoKhau, string maHoKhau);

void themNguoiVaoHoKhau(Phuong& phuong);
void themHoKhauMoi(Phuong& phuong);
void swap(ThanhVienPtr a, ThanhVienPtr b);
void sapXepTheoMaHoKhau(HoKhauPtr danhSachHoKhau, string maHoKhau);


HoKhauPtr timHoKhau(Phuong phuong);

void ghiFile(string filename, Phuong phuong);
void xuatDSThanhVienFile(ThanhVienPtr DSTV, ofstream& file);
int demSoThanhVien(ThanhVienPtr DSTV);

void themNguoiVaoHoKhauFile(TTHK& hoKhau, TTTV x);
void themHoKhauMoiFile(Phuong& phuong, TTHK x);

void docFile(string filename, Phuong& phuong);
