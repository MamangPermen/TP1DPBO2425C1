<?php
require_once 'kelas.php'; // include class Barang
require_once 'function.php'; // include fungsi
session_start();

// FLASH MESSAGE
if (isset($_SESSION['flash'])) { 
    $pesan = $_SESSION['flash'];
    unset($_SESSION['flash']);
} else {
    $pesan = '';
}

// Inisialisasi session
if (!isset($_SESSION['barang'])) {
    $_SESSION['barang'] = [];
}

// Handle tambah barang
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['tambah'])) {
    $id = trim($_POST['id']); // trim untuk menghilangkan spasi di awal/akhir
    $nama = trim($_POST['nama']); 
    $harga = (int)$_POST['harga'];  // pastikan harga adalah integer
    $stok = (int)$_POST['stok']; // pastikan stok adalah integer

    $gambar = '';
    if (isset($_FILES['gambar']) && $_FILES['gambar']['error'] === UPLOAD_ERR_OK) { // cek apakah ada file yang diupload tanpa error
        $fileName = $_FILES['gambar']['name']; // nama file asli
        $fileTmp = $_FILES['gambar']['tmp_name']; // lokasi file sementara di server
        $fileExt = pathinfo($fileName, PATHINFO_EXTENSION); // ekstensi file
        $newFileName = uniqid() . '.' . strtolower($fileExt); // buat nama file unik untuk menghindari konflik
        $targetPath = 'gambar/' . $newFileName; // target path untuk menyimpan gambar

        if (move_uploaded_file($fileTmp, $targetPath)) { // pindahkan file ke folder tujuan
            $gambar = $targetPath;
        }
    }

    if ($id && $nama && $harga >= 0 && $stok >= 0 && $gambar) { // pastikan semua data terisi
        if (cekIdDuplikat($id)) {
            $_SESSION['flash'] = "<div class='alert error'>ID sudah digunakan. Gunakan ID lain.</div>";
            header("Location: index.php");
            exit;
        }

        $_SESSION['barang'][] = new Barang($id, $nama, $harga, $stok, $gambar); // tambahkan barang baru ke session
        $_SESSION['flash'] = "<div class='alert success'>Barang berhasil ditambahkan!</div>";
        header("Location: index.php");
        exit;

    } else {
        $_SESSION['flash'] = "<div class='alert error'>Gagal menambahkan barang. Pastikan semua data dan gambar diisi.</div>";
        header("Location: index.php");
        exit;
    }
}

// Handle hapus barang
if (isset($_GET['hapus'])) { // jika ada parameter hapus
    $id = $_GET['hapus'];
    foreach ($_SESSION['barang'] as $index => $barang) { // cari barang berdasarkan ID
        if ($barang->id === $id) { // jika ditemukan hapus file gambarnya juga
            if (file_exists($barang->gambar)) {
                unlink($barang->gambar);
            }
            unset($_SESSION['barang'][$index]); // hapus barang dari session
            $_SESSION['barang'] = array_values($_SESSION['barang']);
            $_SESSION['flash'] = "<div class='alert success'>Barang berhasil dihapus!</div>";
            header("Location: index.php");
            exit;
        }
    }
    $_SESSION['flash'] = "<div class='alert error'>Barang tidak ditemukan.</div>";
    header("Location: index.php");
    exit;
}

// Handle update barang
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['update'])) { // jika form update disubmit
    $index = (int)$_POST['index']; // index barang yang akan diupdate
    $id = trim($_POST['id']); // trim untuk menghilangkan spasi di awal/akhir
    $nama = trim($_POST['nama']);
    $harga = (int)$_POST['harga']; // pastikan harga adalah integer
    $stok = (int)$_POST['stok']; // pastikan stok adalah integer

    $gambar = $_SESSION['barang'][$index]->gambar; // default ke gambar lama

    if (isset($_FILES['gambar']) && $_FILES['gambar']['error'] === UPLOAD_ERR_OK) { // jika ada file gambar baru yang diupload
        if (file_exists($gambar)) { // hapus gambar lama jika ada
            unlink($gambar);
        }

        $fileName = $_FILES['gambar']['name']; // nama file asli
        $fileTmp = $_FILES['gambar']['tmp_name']; // lokasi file sementara di server
        $fileExt = pathinfo($fileName, PATHINFO_EXTENSION);
        $newFileName = uniqid() . '.' . strtolower($fileExt); // buat nama file unik
        $targetPath = 'gambar/' . $newFileName; // target path untuk menyimpan gambar

        if (move_uploaded_file($fileTmp, $targetPath)) { // pindahkan file ke folder tujuan
            $gambar = $targetPath; // update path gambar
        } else {
            $_SESSION['flash'] = "<div class='alert error'>Gagal upload gambar.</div>"; // jika gagal upload, tetap gunakan gambar lama
            $barangEdit = $_SESSION['barang'][$index]; // kembalikan data lama untuk form
            $indexEdit = $index;
            goto skip_redirect;
        }
    }

    if ($id && $nama && $harga >= 0 && $stok >= 0) { // pastikan semua data terisi
        if (cekIdDuplikat($id, $index)) {
            $_SESSION['flash'] = "<div class='alert error'>ID sudah digunakan oleh barang lain. Gunakan ID lain.</div>";
            $barangEdit = $_SESSION['barang'][$index];
            $indexEdit = $index;
            goto skip_redirect;
        }

        $_SESSION['barang'][$index] = new Barang($id, $nama, $harga, $stok, $gambar); // update barang di session
        $_SESSION['flash'] = "<div class='alert success'>Barang berhasil diupdate!</div>";
        header("Location: index.php");
        exit;

    } else {
        $_SESSION['flash'] = "<div class='alert error'>Gagal mengupdate barang. Pastikan semua data valid.</div>";
        $barangEdit = $_SESSION['barang'][$index];
        $indexEdit = $index;
        goto skip_redirect;
    }

    skip_redirect:
}

// Handle edit
$barangEdit = null;
if (isset($_GET['edit'])) { // jika ada parameter edit
    $id = $_GET['edit'];
    foreach ($_SESSION['barang'] as $index => $barang) { // cari barang berdasarkan ID
        if ($barang->id === $id) {
            $barangEdit = $barang;
            $indexEdit = $index;
            break;
        }
    }
}
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="style.css">
    <title>Manajemen Barang</title>
</head>
<body>
    <div class="container">
        <h1>📦 Manajemen Barang Toko Ah Fung</h1>

        <?php if (isset($pesan)) echo $pesan; ?>

        <!-- FORM TAMBAH / UPDATE -->
        <div class="form-container">
            <h3>
                <?php echo $barangEdit ? 'Edit Barang' : 'Tambah Barang Baru'; ?> <!-- Jika sedang edit, tampilkan form edit -->
            </h3>

            <form method="POST" enctype="multipart/form-data">
                <?php if ($barangEdit): ?>
                    <input type="hidden" name="index" value="<?php echo $indexEdit; ?>">
                <?php endif; ?>

                <label>ID Barang:</label> <!-- ID harus unik -->
                <input type="text" name="id" required value="<?php echo $barangEdit ? htmlspecialchars($barangEdit->id) : ''; ?>">

                <label>Nama Barang:</label>
                <input type="text" name="nama" required value="<?php echo $barangEdit ? htmlspecialchars($barangEdit->nama) : ''; ?>">

                <label>Harga:</label>
                <input type="text" name="harga" required inputmode="numeric" pattern="[0-9]*" value="<?php echo $barangEdit ? number_format($barangEdit->harga, 0, ',', '.') : ''; ?>" oninput="this.value = this.value.replace(/[^0-9]/g, '')">

                <label>Stok:</label>
                <input type="number" name="stok" required min="0" value="<?php echo $barangEdit ? $barangEdit->stok : ''; ?>">

                <label>Gambar Barang:</label>
                <input type="file" name="gambar" <?php echo $barangEdit ? '' : 'required'; ?>>
                <?php if ($barangEdit && $barangEdit->gambar): ?>
                    <p>Gambar saat ini: <img src="<?php echo htmlspecialchars($barangEdit->gambar); ?>" alt="Gambar Barang"></p>
                <?php endif; ?>

                <button type="submit" name="<?php echo $barangEdit ? 'update' : 'tambah'; ?>">
                    <?php echo $barangEdit ? 'Update Barang' : 'Tambah Barang'; ?>
                </button>

                <?php if ($barangEdit): ?>
                    <a href="index.php" style="display:inline-block; margin-top:10px;">← Batal Edit</a>
                <?php endif; ?>
            </form>
        </div>

        <!-- TABEL DATA BARANG -->
        <h3>📋 Daftar Barang</h3>
        <?php if (empty($_SESSION['barang'])): ?> <!-- Jika tidak ada barang -->
            <p>Belum ada barang.</p>
        <?php else: ?>
            <table>
                <thead>
                    <tr> 
                        <th>Gambar</th>
                        <th>ID</th>
                        <th>Nama</th>
                        <th>Harga</th>
                        <th>Stok</th>
                        <th>Aksi</th>
                    </tr>
                </thead>
                <tbody>
                    <?php foreach ($_SESSION['barang'] as $barang): ?>
                    <tr>
                        <td><img src="<?php echo htmlspecialchars($barang->gambar); ?>" alt="Gambar"></td> <!-- Menampilkan gambar -->
                        <td><?php echo htmlspecialchars($barang->id); ?></td> <!-- Escape output untuk keamanan -->
                        <td><?php echo htmlspecialchars($barang->nama); ?></td> 
                        <td>Rp <?php echo number_format($barang->harga, 0, ',', '.'); ?></td> <!-- Format harga -->
                        <td><?php echo $barang->stok; ?></td>
                        <td>
                            <a class="btn btn-edit" href="?edit=<?php echo urlencode($barang->id); ?>">Edit</a> <!-- Gunakan urlencode untuk keamanan -->
                            <a class="btn btn-hapus" href="?hapus=<?php echo urlencode($barang->id); ?>" onclick="return confirm('Yakin hapus?')">Hapus</a> <!-- Konfirmasi sebelum hapus -->
                        </td>
                    </tr>
                    <?php endforeach; ?>
                </tbody>
            </table>
        <?php endif; ?>
    </div>
</body>
</html>