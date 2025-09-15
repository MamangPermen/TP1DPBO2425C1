#include <bits/stdc++.h>

using namespace std;

class barang
{

private: // atribut
    string id;
    string nama;
    int harga;
    int stok;

public: // method
    barang(){}

    barang(string id, string nama, int harga, int stok)
    {
        this->id = id;
        this->nama = nama;
        this->harga = harga;
        this->stok = stok;
    }

    void setid(string id) {this->id = id;} // setter id
    string getid() {return this->id;} // getter id

    void setnama(string nama) {this->nama = nama;} // setter nama
    string getnama() {return this->nama;} // getter nama

    void setharga(int harga) {this->harga = harga;} // setter harga
    int getharga() {return this->harga;} // getter harga

    void setstok(int stok) {this->stok = stok;} // setter stok
    int getstok() {return this->stok;} // getter stok

    void editData(string nama, int harga, int stok) // method edit data
    {
        this->nama = nama;
        this->harga = harga;
        this->stok = stok;
    }

    bool cariid(string id) {return this->id == id;} // method cari id

    ~barang() {}
};