public class Barang {
    private String id;
    private String nama;
    private int harga;
    private int stok;

    // Constructor
    public Barang(String id, String nama, int harga, int stok) {
        this.id = id;
        this.nama = nama;
        this.harga = harga;
        this.stok = stok;
    }

    // Getter
    public String getId() { return id; }
    public String getNama() { return nama; }
    public int getHarga() { return harga; }
    public int getStok() { return stok; }

    // Setter
    public void setId(String id) { this.id = id; }
    public void setNama(String nama) { this.nama = nama; }
    public void setHarga(int harga) { this.harga = harga; }
    public void setStok(int stok) { this.stok = stok; }

    // Cek apakah ID cocok
    public boolean cocokId(String id) {
        return this.id.equals(id);
    }

    // Edit data
    public void editData(String nama, int harga, int stok) {
        this.nama = nama;
        this.harga = harga;
        this.stok = stok;
    }

    // Override toString() untuk tampilan simpel
    @Override
    public String toString() {
        return id + ", " + nama + ", " + harga + ", " + stok;
    }
}