#include <bits/stdc++.h>
#include "kelas.cpp"

using namespace std;

int main()
{
    vector<barang> daftarbarang; // vector untuk menyimpan data barang

    int menu = 0; // variabel untuk menyimpan pilihan menu
    string id, nama; // variabel untuk menyimpan data barang
    int harga, stok; // variabel untuk menyimpan data barang

    while (menu != 6) 
    {

        cout << "xxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << "x       Menu        x" << endl;
        cout << "xxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << "x 1. Tambahkan Data x" << endl;
        cout << "x 2. Hapus Data     x" << endl;
        cout << "x 3. Update Data    x" << endl;
        cout << "x 4. Lihat Data     x" << endl;
        cout << "x 5. Cari Data      x" << endl;
        cout << "x 6. Exit           x" << endl;
        cout << "xxxxxxxxxxxxxxxxxxxxx" << endl;
        cout << "Masukkan perintah : ";
        cin >> menu;

        if (menu == 1) // menu nambah data Data
        {
            cout << "Silahkan masukkan data" << endl;
            cout << "ID : ";
            cin >> id;
            cout << "Nama : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, nama);
            cout << "Harga : ";
            cin >> harga;
            cout << "Stok : ";
            cin >> stok;

            barang temp(id, nama, harga, stok); // buat objek barang dengan data yang dimasukkan
            daftarbarang.push_back(temp); // tambahkan objek barang ke vector daftarbarang
            cout << "Data berhasil ditambahkan!" << endl << endl;

        } else if (menu == 2) // menu hapus data
        {
            cout << "Masukkan ID data yang ingin dihapus : ";
            cin >> id;

            bool ketemu = false; // variabel untuk menandai apakah data ditemukan atau tidak
            auto it = daftarbarang.begin(); // iterator untuk traversing vector
            while (it != daftarbarang.end()) // gunakan iterator untuk traversing vector
            {
                if (it->cariid(id)) // jika id yang dicari ditemukan
                {
                    it = daftarbarang.erase(it); // hapus data dari vector
                    ketemu = true;
                    cout << "Data berhasil dihapus!" << endl << endl;
                    break;
                } else {
                    ++it; // jika id tidak ditemukan, lanjutkan ke data berikutnya
                }
            }

            if (!ketemu) // jika data tidak ditemukan
            {
                cout << "Data gaada" << endl << endl;
            }

        } else if (menu == 3) // buat menu update data
        {
            cout << "Masukkan ID yang ingin diupdate : ";
            cin >> id;

            barang* barangketemu = nullptr; // pointer untuk menyimpan alamat barang yang ditemukan
            auto it = daftarbarang.begin(); // iterator untuk traversing vector
            while (it != daftarbarang.end()) // gunakan iterator untuk traversing vector
            {
                if (it->cariid(id)) // jika id yang dicari ditemukan
                {
                    barangketemu = &(*it); // simpan alamat barang yang ditemukan
                    break;
                }
                ++it; // jika id tidak ditemukan, lanjutkan ke data berikutnya
            }

            if (barangketemu != nullptr) // jika barang ditemukan
            {
                cout << "Nama : " << barangketemu->getnama() << endl;
                cout << "Harga : " << barangketemu->getharga() << endl;
                cout << "Stok : " << barangketemu->getstok() << endl << endl;

                cout << "Masukkan Nama Baru : ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, nama);
                cout << "Masukkan Harga Baru : ";
                cin >> harga;
                cout << "Masukkan Stok Baru : ";
                cin >> stok;

                barangketemu->editData(nama, harga, stok); // update data barang yang ditemukan
                cout << "Data berhasil diupdate!" << endl << endl;

            } else {
                cout << "Data gaada" << endl << endl;
            }

        } else if (menu == 4) // buat menu lihat data
        {
            if (daftarbarang.empty()) // jika vector daftarbarang kosong
            {
                cout << "Data kosong" << endl << endl;
            } else {
                cout << "No, ID, Nama, Harga, Stok:" << endl;
        int nomor = 1;
        for (barang& p : daftarbarang) // pake range-based for loop untuk traversing vector
        {
            cout << nomor << ". " 
                 << p.getid() << ", " 
                 << p.getnama() << ", " 
                 << p.getharga() << ", " 
                 << p.getstok() << " Barang" << endl;
            ++nomor;
        }
        cout << endl;
    }

        } else if (menu == 5) // buat menu cari data
        {
            cout << "Masukkan ID yang ingin dicari : ";
            cin >> id;

            barang* barangketemu = nullptr; // pointer untuk menyimpan alamat barang yang ditemukan
            auto it = daftarbarang.begin(); // iterator untuk traversing vector
            while (it != daftarbarang.end()) // gunakan iterator untuk traversing vector
            {
                if (it->cariid(id))  // jika id yang dicari ditemukan
                {
                    barangketemu = &(*it);
                    break;
                }
                ++it; // jika id tidak ditemukan, lanjutkan ke data berikutnya
            }

            if (barangketemu != nullptr) // jika barang ditemukan
            {
                cout << "Ini data dengan ID " << id << " :" << endl;
                cout << "Nama : " << barangketemu->getnama() << endl;
                cout << "Harga : " << barangketemu->getharga() << endl;
                cout << "Stok : " << barangketemu->getstok() << endl << endl;
            } else {
                cout << "Data gaada" << endl << endl;
            }

        } else if (menu == 6) // menu keluar
        {
            cout << "dadah" << endl;
        } else {
            cout << "menu gaada" << endl;
        }

    }
    return 0;    
}