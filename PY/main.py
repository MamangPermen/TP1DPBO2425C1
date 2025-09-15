from kelas import Barang  # Import class barang dari file barang.py

def tampilkan_menu():
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


def tambah_barang(daftar): # buat nambah barang
    print("Silahkan masukkan data")
    id = input("ID : ").strip()
    nama = input("Nama : ").strip()
    harga = int(input("Harga : ").strip())
    stok = int(input("Stok : ").strip())

    daftar.append(Barang(id, nama, harga, stok)) # tambahin barang ke list
    print("Data berhasil ditambahkan!\n")


def hapus_barang(daftar): # buat hapus barang
    id = input("Masukkan ID data yang ingin dihapus : ").strip()

    for i, barang in enumerate(daftar): # enumerate biar dapet index juga
        if barang.cocok_id(id): # kalo idnya cocok
            del daftar[i] # hapus barang dari list
            print("Data berhasil dihapus!\n")
            return
    print("Data gaada\n")


def update_barang(daftar): # buat update barang
    id = input("Masukkan ID yang ingin diupdate : ").strip() 

    for barang in daftar:
        if barang.cocok_id(id): # kalo id ketemu
            print(f"Nama : {barang.nama}")
            print(f"Harga : {barang.harga}")
            print(f"Stok : {barang.stok}\n")

            # minta data baru
            nama_baru = input("Masukkan Nama Baru : ").strip()
            harga_baru = int(input("Masukkan Harga Baru : ").strip())
            stok_baru = int(input("Masukkan Stok Baru : ").strip())

            barang.edit_data(nama_baru, harga_baru, stok_baru) # update data
            print("Data berhasil diupdate!\n")
            return
    print("Data gaada\n")


def tampilkan_semua_barang(daftar): # buat nampilin semua barang
    if not daftar: 
        print("Data kosong\n")
    else:
        print("ID, Nama, Harga, Stok:")
        for i, barang in enumerate(daftar, start=1): 
            print(f"{i}. {barang}")
        print()


def cari_barang(daftar): # buat cari barang
    id = input("Masukkan ID yang ingin dicari : ").strip()

    for barang in daftar:
        if barang.cocok_id(id): # kalo id ketemu
            print(f"Berikut data dengan ID {id} :")
            print(f"Nama : {barang.nama}")
            print(f"Harga : {barang.harga}")
            print(f"Stok : {barang.stok}\n")
            return
    print("Data gaada\n")


# Main
def main():
    daftar_barang = [] # list buat nampung barang
    menu = 0 # inisialisasi menu

    while menu != 6:
        tampilkan_menu() # nampilin menu
        try:
            menu = int(input("Masukkan perintah : ").strip()) # minta input menu
        except ValueError: # kalo inputnya bukan angka
            print("Input harus angka!\n")
            continue

        if menu == 1:
            tambah_barang(daftar_barang)
        elif menu == 2:
            hapus_barang(daftar_barang)
        elif menu == 3:
            update_barang(daftar_barang)
        elif menu == 4:
            tampilkan_semua_barang(daftar_barang)
        elif menu == 5:
            cari_barang(daftar_barang)
        elif menu == 6:
            print("dadah")
        else:
            print("menu gaada")


if __name__ == "__main__":
    main()