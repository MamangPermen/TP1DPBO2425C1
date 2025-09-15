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
    
class ManageBarang: 
    def __init__(self): # Inisialisasi daftar barang
        self.daftar_barang = []

    def tambah(self, id, nama, harga, stok): # Tambah barang baru
        self.daftar_barang.append(Barang(id, nama, harga, stok))

    def hapus(self, id): # Hapus barang berdasarkan ID
        for i, barang in enumerate(self.daftar_barang):
            if barang.cocok_id(id):
                del self.daftar_barang[i]
                return True
        return False

    def update(self, id, nama, harga, stok): # Update data barang berdasarkan ID
        for barang in self.daftar_barang:
            if barang.cocok_id(id):
                barang.edit_data(nama, harga, stok)
                return True
        return False

    def cari(self, id): # Cari barang berdasarkan ID
        for barang in self.daftar_barang:
            if barang.cocok_id(id):
                return barang
        return None

    def tampilkan(self): # Nampilin barang
        if not self.daftar_barang:
            return "Data kosong"
        
        lines = ["ID, Nama, Harga, Stok:"]
        for i, barang in enumerate(self.daftar_barang, start=1):
            lines.append(f"{i}. {barang}")
        return "\n".join(lines)