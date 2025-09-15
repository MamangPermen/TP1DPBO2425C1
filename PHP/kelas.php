<?php

class Barang {
    public $id;
    public $nama;
    public $harga;
    public $stok;
    public $gambar; // path lokal, misal: "uploads/produk1.jpg"

    public function __construct($id, $nama, $harga, $stok, $gambar) {
        $this->id = $id;
        $this->nama = $nama;
        $this->harga = $harga;
        $this->stok = $stok;
        $this->gambar = $gambar;
    }
}