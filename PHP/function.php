<?php

function cekIdDuplikat($id, $index_abaikan = null) // buat cek apakah ID sudah digunakan oleh barang lain
{
    foreach ($_SESSION['barang'] as $index => $barang) {
        // Jika sedang update, abaikan barang dengan index ini
        if ($index_abaikan !== null && $index == $index_abaikan) {
            continue;
        }
        if ($barang->id === $id) {
            return true; // ID sudah ada
        }
    }
    return false; // ID unik
}