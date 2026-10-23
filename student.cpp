#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student {
private:
    string hoTen;
    double diemKy1;
    double diemKy2;

public:
    Student() : hoTen(""), diemKy1(0), diemKy2(0) {}

    void nhap() {
        cout << "Ho ten: ";
        getline(cin >> ws, hoTen);

        cout << "Diem ky 1: ";
        cin >> diemKy1;

        cout << "Diem ky 2: ";
        cin >> diemKy2;
    }

    double diemTrungBinhCaNam() const {
        return (diemKy1 + 2 * diemKy2) / 3;
    }

    bool datYeuCau() const {
        return diemTrungBinhCaNam() >= 5;
    }

    void hienThi() const {
        cout << left << setw(25) << hoTen
             << right << setw(12) << fixed << setprecision(2) << diemKy1
             << setw(12) << diemKy2
             << setw(18) << diemTrungBinhCaNam() << '\n';
    }
};

void hienThiTieuDe() {
    cout << left << setw(25) << "Ho ten"
         << right << setw(12) << "Diem ky 1"
         << setw(12) << "Diem ky 2"
         << setw(18) << "Diem ca nam" << '\n';
    cout << string(67, '-') << '\n';
}

int main() {
    const int SO_LUONG_SINH_VIEN = 5;
    Student danhSach[SO_LUONG_SINH_VIEN];

    cout << "=== NHAP THONG TIN SINH VIEN ===\n";
    for (int i = 0; i < SO_LUONG_SINH_VIEN; i++) {
        cout << "\nSinh vien thu " << i + 1 << ":\n";
        danhSach[i].nhap();
    }

    cout << "\n=== DANH SACH 5 SINH VIEN ===\n";
    hienThiTieuDe();
    for (const Student& student : danhSach) {
        student.hienThi();
    }

    cout << "\n=== SINH VIEN CO DIEM TRUNG BINH CA NAM >= 5 ===\n";
    hienThiTieuDe();

    bool coSinhVienDat = false;
    for (const Student& student : danhSach) {
        if (student.datYeuCau()) {
            student.hienThi();
            coSinhVienDat = true;
        }
    }

    if (!coSinhVienDat) {
        cout << "Khong co sinh vien dat yeu cau.\n";
    }

    return 0;
}