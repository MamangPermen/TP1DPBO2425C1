# Manajemen Barang Toko Elektronik Ah Fung
## Janji
Saya Nadhif Arva Anargya dengan NIM 2404336 mengerjakan Tugas Praktikum 1 dalam mata kuliah Desain Pemrograman Berbasis Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.

Program ini merupakan aplikasi sederhana untuk mengelola data barang menggunakan Object-Oriented Programming (OOP) di C++, Java, Python, dan PHP. Program memudahkan user untuk CRUD dan mencari data barang elektronik untuk keberlangsungan toko elektronik koh Ah Fung.

## 🛠 ️Desain(C++, Java, Python)
### 1. Struktur Kelas barang
Kelas barang merupakan representasi dari entitas barang dalam sistem. Setiap objek barang memiliki atribut dan method sebagai berikut:
##### Entitas Utama: Barang
###### Setiap barang memiliki atribut:
- id → string, unik, sebagai kunci pencarian
- nama → string, nama barang
- harga → integer, harga satuan
- stok → integer, jumlah tersedia
###### Operasi yang Didukung:
- Tambah Data
Input: ID, Nama, Harga, Stok
Simpan ke koleksi (vector/list/array)
- Lihat Semua Data
Tampilkan nomor urut, ID, Nama, Harga, Stok
Jika kosong → tampilkan “Data kosong”
- Cari Data
Input: ID
Jika ditemukan → tampilkan detail
Jika tidak → tampilkan “Data gaada”
- Update Data
Input: ID → cari → tampilkan data lama → input data baru → simpan
Jika tidak ditemukan → tampilkan “Data gaada”
- Hapus Data
Input: ID → cari → hapus dari koleksi
Jika tidak ditemukan → tampilkan “Data gaada”
- Keluar
Hentikan program → tampilkan “dadah”

## 🧩 ️Struktur Kode
- Atribut: id, nama, harga, stok (private/protected)
- Konstruktor: menerima keempat atribut
- Getter & Setter: untuk akses dan modifikasi aman
- Method Khusus:
editData() → update nama, harga, stok sekaligus
cariid() / cocokId() / cocok_id() → cek kesesuaian ID
toString() / __str__() → representasi teks objek
- Program Utama
Koleksi Data: vector<Barang> (C++), ArrayList<Barang> (Java), List[Barang] (Python)
Loop Menu: while sampai pilih keluar
Input User: via cin (C++), Scanner (Java), input() (Python)
- Pencarian & Manipulasi:
Gunakan loop atau stream/filter untuk cari ID
Gunakan iterator (C++), removeIf (Java), enumerate (Python) untuk hapus/update
- Output

## ➤ PHP
### Struktur
- kelas.php → Class Barang
- function.php → Fungsi (cekIdDuplikat) biar id gaada yang duplikat
- index.php → Frontend + Backend 
### Fitur
- Full Web App dengan HTML, CSS, form, dan upload gambar
- Penyimpanan data via $_SESSION
- Upload dan simpan gambar ke folder gambar/
- Validasi duplikat ID
- Flash message untuk feedback pengguna
- Edit dan hapus via parameter URL (?edit=..., ?hapus=...)

## Dokumentasi
