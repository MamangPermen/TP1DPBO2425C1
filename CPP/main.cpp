#include <bits/stdc++.h>
#include "kelas.cpp"

using namespace std;

int main()
{
    vector<barang> daftarbarang;

    int menu = 0;
    string id, nama;
    int harga, stok;

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

        if (menu == 1)
        {
            cout << "Silahkan masukkan data" << endl;
            cout << "ID : ";
            cin >> id;
            cout << "Nama : ";
            cin >> nama;
            cout << "Harga : ";
            cin >> harga;
            cout << "Stok : ";
            cin >> stok;

            barang temp(id, nama, harga, stok);
            daftarbarang.push_back(temp);
            cout << "Data berhasil ditambahkan!" << endl << endl;

        } else if (menu == 2)
        {
            cout << "Masukkan ID data yang ingin dihapus : ";
            cin >> id;

            bool ketemu = false;
            auto it = daftarbarang.begin();
            while (it != daftarbarang.end())
            {
                if (it->cariid(id))
                {
                    it = daftarbarang.erase(it);
                    ketemu = true;
                    cout << "Data berhasil dihapus!" << endl << endl;
                    break;
                } else {
                    ++it;
                }
            }

            if (!ketemu)
            {
                cout << "Data gaada" << endl << endl;
            }

        } else if (menu == 3)
        {
            cout << "Masukkan ID yang ingin diupdate : ";
            cin >> id;

            barang* barangketemu = nullptr;
            auto it = daftarbarang.begin();
            while (it != daftarbarang.end())
            {
                if (it->cariid(id))
                {
                    barangketemu = &(*it);
                    break;
                }
                ++it;
            }

            if (barangketemu != nullptr)
            {
                cout << "Nama : " << barangketemu->getnama() << endl;
                cout << "Harga : " << barangketemu->getharga() << endl;
                cout << "Stok : " << barangketemu->getstok() << endl << endl;

                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan Harga Baru : ";
                cin >> harga;
                cout << "Masukkan Stok Baru : ";
                cin >> stok;

                barangketemu->editData(nama, harga, stok);
                cout << "Data berhasil diupdate!" << endl << endl;

            } else {
                cout << "Data gaada" << endl << endl;
            }

        } else if (menu == 4)
        {
            if (daftarbarang.empty())
            {
                cout << "Data kosong" << endl << endl;
            } else {
                cout << "No, ID, Nama, Harga, Stok:" << endl;
        int nomor = 1;
        for (barang& p : daftarbarang)
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

        } else if (menu == 5)
        {
            cout << "Masukkan ID yang ingin dicari : ";
            cin >> id;

            barang* barangketemu = nullptr;
            auto it = daftarbarang.begin();
            while (it != daftarbarang.end())
            {
                if (it->cariid(id)) 
                {
                    barangketemu = &(*it);
                    break;
                }
                ++it;
            }

            if (barangketemu != nullptr)
            {
                cout << "Ini data dengan ID " << id << " :" << endl;
                cout << "Nama : " << barangketemu->getnama() << endl;
                cout << "Harga : " << barangketemu->getharga() << endl;
                cout << "Stok : " << barangketemu->getstok() << endl << endl;
            } else {
                cout << "Data gaada" << endl << endl;
            }

        } else if (menu == 6)
        {
            cout << "dadah" << endl;
        } else {
            cout << "menu gaada" << endl;
        }

    }
    return 0;    
}