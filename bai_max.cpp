#include <iostream>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int max(const int arr[], int n) {
    int ketQua = arr[0];
    for (int i = 1; i < n; i++) {
        ketQua = max(ketQua, arr[i]);
    }
    return ketQua;
}

int main() {
    int a, b, c;

    cout << "=== SO LON HON TRONG HAI SO ===\n";
    cout << "Nhap a, b: ";
    cin >> a >> b;
    cout << "So lon hon = " << max(a, b) << '\n';

    cout << "\n=== SO LON NHAT TRONG BA SO ===\n";
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;
    cout << "So lon nhat = " << max(a, b, c) << '\n';

    int n;
    cout << "\n=== SO LON NHAT TRONG DAY SO ===\n";
    cout << "Nhap so phan tu n: ";
    cin >> n;

    if (n <= 0) {
        cout << "So phan tu phai lon hon 0.\n";
        return 0;
    }

    int* arr = new int[n];
    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "So lon nhat trong day = " << max(arr, n) << '\n';

    delete[] arr;
    return 0;
}
