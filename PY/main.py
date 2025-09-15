from kelas import ManageBarang  # Import class manajemen barang dari file manajemen_barang.py

class App:
    def __init__(self):
        self.manager = ManageBarang()

    def tampilkan_menu(self): # Tampilkan menu
        print("xxxxxxxxxxxxxxxxxxxxx")
        print("x       Menu        x")
        print("xxxxxxxxxxxxxxxxxxxxx")
        print("x 1. Tambahkan Data x")
        print("x 2. Hapus Data     x")
        print("x 3. Update Data    x")
        print("x 4. Lihat Data     x")
        print("x 5. Cari Data      x")
        print("x 6. Exit           x")
        print("xxxxxxxxxxxxxxxxxxxxx")

    def run(self): # Jalankan aplikasi
        menu = 0
        while menu != 6:
            self.tampilkan_menu()
            try:
                menu = int(input("Pilih menu: "))
            except ValueError:
                print("Menu harus angka!")
                continue

            if menu == 1: # Tambah data
                id = input("Masukkan ID: ")
                nama = input("Masukkan Nama: ")
                harga = int(input("Masukkan Harga: "))
                stok = int(input("Masukkan Stok: "))
                self.manager.tambah(id, nama, harga, stok)
                print("Data berhasil ditambahkan!")

            elif menu == 2: # Hapus data
                id = input("Masukkan ID yang akan dihapus: ")
                if self.manager.hapus(id):
                    print("Data berhasil dihapus!")
                else:
                    print("Data gaada")

            elif menu == 3: # Update data
                id = input("Masukkan ID yang akan diupdate: ")
                nama = input("Masukkan Nama baru: ")
                harga = int(input("Masukkan Harga baru: "))
                stok = int(input("Masukkan Stok baru: "))
                if self.manager.update(id, nama, harga, stok):
                    print("Data berhasil diupdate!")
                else:
                    print("Data gaada")

            elif menu == 4: # Tampilkan data
                print("Daftar Barang:")
                print(self.manager.tampilkan())

            elif menu == 5: # Cari data
                id = input("Masukkan ID yang dicari: ")
                barang = self.manager.cari(id)
                if barang:
                    print("Berikut data dengan ID", id, ":")
                    print(f"Nama : {barang.nama}")
                    print(f"Harga : {barang.harga}")
                    print(f"Stok : {barang.stok}")
                else:
                    print("Data gaada")

            elif menu == 6: # Exit
                print("Dadah")
            else:
                print("Menu gaada")

if __name__ == "__main__":
    App().run()