#include <bits/stdc++.h>
using namespace std;

// Create class Vemaybay
class Vemaybay
{
public:
    string tenchuyen;
    string ngaybay;
    int giave;

    Vemaybay()
    {
        cout << "Constructor Vemaybay created!" << endl;
    }

    ~Vemaybay()
    {
        cout << "Destructor Vemaybay called!" << endl;
    }

    int getgiave()
    {
        return giave;
    }

    void Nhap()
    {
        cin.ignore();
        cout << "Nhập vào tên chuyến bay: ";
        getline(cin, tenchuyen);
        cout << "Nhập vào ngày bay: ";
        getline(cin, ngaybay);
        cout << "Nhập vào giá vé $: ";
        cin >> giave;
    };

    void Xuat()
    {
        cout << "Tên chuyến bay: " << tenchuyen << endl;
        cout << "Ngày bay: " << ngaybay << endl;
        cout << "Giá vé: " << giave << endl;
    };
};

// Create class Nguoi
class Nguoi
{
public:
    string hoten;
    string gioitinh;
    int tuoi;

    Nguoi()
    {
        cout << "Constructor Nguoi created!" << endl;
    }

    ~Nguoi()
    {
        cout << "Destructor Nguoi called!" << endl;
    }

    void Nhap()
    {
        cin.ignore();
        cout << "Nhập vào họ tên: ";
        getline(cin, hoten);
        cout << "Nhập vào giới tính: ";
        getline(cin, gioitinh);
        cout << "Nhập vào tuổi: ";
        cin >> tuoi;
    };

    void Xuat()
    {
        cout << "Họ tên: " << hoten << endl;
        cout << "Giới tính: " << gioitinh << endl;
        cout << "Tuổi: " << tuoi << endl;
    };
};

// Create class hanhkhach
class hanhkhach : public Nguoi
{
public:
    Vemaybay ve;
    int soluong;

    hanhkhach()
    {
        cout << "Constructor hanhkhach created!" << endl;
    }

    ~hanhkhach()
    {
        cout << "Destructor hanhkhach called!" << endl;
    }

    void Nhap1()
    {
        this->Nhap();
        cout << "Nhập thông tin vé máy bay" << endl;
        ve.Nhap();
        cout << "Nhập số lượng vé máy bay: ";
        cin >> soluong;
    };

    void Xuat1()
    {
        this->Xuat();
        cout << "Thông tin vé máy bay" << endl;
        ve.Xuat();
        cout << "Số lượng vé máy bay: " << soluong << endl;
    };

    int tongtien()
    {
        int totalMoney = ve.getgiave() * soluong;
        return totalMoney;
    }
};

// Hàm sắp xếp danh sách hành khách theo tổng tiền giảm dần
void sorted(hanhkhach hanhkhachs[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (hanhkhachs[j].tongtien() < hanhkhachs[j + 1].tongtien())
                swap(hanhkhachs[j], hanhkhachs[j + 1]);
}

int main()
{
    // Nhập số lượng hành khách
    int n = 0;
    while (n <= 0)
    {
        cout << "Nhập số lượng hành khách: ";
        cin >> n;
    }

    // Nhập thông tin hành khách
    hanhkhach hanhkhachs[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhập thông tin hành khách thứ " << i + 1 << endl;
        hanhkhachs[i].Nhap1();
    }

    // Sắp xếp hành khách theo tổng số tiền giảm dần
    sorted(hanhkhachs, n);

    // Hiển thị danh sách hành khách;
    for (int i = 0; i < n; i++)
    {
        cout << "Thông tin hành khách thứ " << i + 1 << " là:" << endl;
        hanhkhachs[i].Xuat1();
        cout << "Tổng số tiền phải trả của hành khách là: " << hanhkhachs[i].tongtien() << endl;
    }

    return 0;
}