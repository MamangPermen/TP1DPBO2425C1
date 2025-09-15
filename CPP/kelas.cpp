#include <bits/stdc++.h>

using namespace std;

class barang
{

private:
    string id;
    string nama;
    int harga;
    int stok;

public:
    barang(){}

    barang(string id, string nama, int harga, int stok)
    {
        this->id = id;
        this->nama = nama;
        this->harga = harga;
        this->stok = stok;
    }

    void setid(string id) {this->id = id;}
    string getid() {return this->id;}

    void setnama(string nama) {this->nama = nama;}
    string getnama() {return this->nama;}

    void setharga(int harga) {this->harga = harga;}
    int getharga() {return this->harga;}

    void setstok(int stok) {this->stok = stok;}
    int getstok() {return this->stok;}

    void editData(string nama, int harga, int stok)
    {
        this->nama = nama;
        this->harga = harga;
        this->stok = stok;
    }

    bool cariid(string id) {return this->id == id;}

    ~barang() {}
};