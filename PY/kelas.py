class Barang:
    def __init__(self, id, nama, harga, stok):
        """Inisialisasi data produk"""
        self.id = id
        self.nama = nama
        self.harga = harga
        self.stok = stok

    def edit_data(self, nama, harga, stok):
        """Update data produk"""
        self.nama = nama
        self.harga = harga
        self.stok = stok

    def cocok_id(self, id):
        """Cek apakah ID produk cocok"""
        return self.id == id

    def __str__(self):
        """Representasi string untuk tampilan """
        return f"{self.id}, {self.nama}, {self.harga}, {self.stok}"