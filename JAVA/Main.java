import java.util.*; // Import untuk kelas Scanner, List, ArrayList, dan Optional
import java.util.stream.Collectors; // Import untuk stream API

public class Main 
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        List<Barang> daftarbarang = new ArrayList<>(); // Inisialisasi daftar barang sebagai ArrayList
        int menu;

        while (true)
        {
            tampilkanMenu();
            System.out.print("Masukkan perintah : ");
            menu = scanner.nextInt(); // Baca input menu
            if (menu < 1 || menu > 6)
            {
                System.out.println("Menu gaada\n");
                continue; // Jika menu tidak valid, lanjutkan ke iterasi berikutnya
            }
            scanner.nextLine(); // Konsumsi newline setelah nextInt()

            switch (menu) // Pilihan menu
            { 
                case 1:
                    tambahbarang(scanner, daftarbarang);
                    break;
                case 2:
                    hapusbarang(scanner, daftarbarang);
                    break;
                case 3:
                    updatebarang(scanner, daftarbarang);
                    break;
                case 4:
                    tampilkanSemuabarang(daftarbarang);
                    break;
                case 5:
                    caribarang(scanner, daftarbarang);
                    break;
                case 6:
                    System.out.println("dadah");
                    return;
                default:
                    System.out.println("menu gaada");
            }
        }
    }

    // === FUNGSI MENU ===
    private static void tampilkanMenu()
    {
        System.out.println("xxxxxxxxxxxxxxxxxxxxx");
        System.out.println("x       Menu        x");
        System.out.println("xxxxxxxxxxxxxxxxxxxxx");
        System.out.println("x 1. Tambahkan Data x");
        System.out.println("x 2. Hapus Data     x");
        System.out.println("x 3. Update Data    x");
        System.out.println("x 4. Lihat Data     x");
        System.out.println("x 5. Cari Data      x");
        System.out.println("x 6. Exit           x");
        System.out.println("xxxxxxxxxxxxxxxxxxxxx");
    }

    private static void tambahbarang(Scanner scanner, List<Barang> daftar) // Fungsi untuk menambahkan barang
    {
        System.out.println("Silahkan masukkan data");
        System.out.print("ID : ");
        String id = scanner.nextLine();
        System.out.print("Nama : ");
        String nama = scanner.nextLine();
        System.out.print("Harga : ");
        int harga = scanner.nextInt();
        System.out.print("Stok : ");
        int stok = scanner.nextInt();
        scanner.nextLine();

        daftar.add(new Barang(id, nama, harga, stok)); // Tambahkan barang baru ke daftar
        System.out.println("Data berhasil ditambahkan!\n");
    }

    private static void hapusbarang(Scanner scanner, List<Barang> daftar) // Fungsi untuk menghapus barang
    {
        System.out.print("Masukkan ID data yang ingin dihapus : ");
        String id = scanner.nextLine(); // Baca ID barang yang ingin dihapus

        boolean ditemukan = daftar.removeIf(barang -> barang.cocokId(id)); // Hapus barang berdasarkan ID

        if (ditemukan)
        {
            System.out.println("Data berhasil dihapus!\n");
        } else {
            System.out.println("Data gaada\n");
        }
    }

    private static void updatebarang(Scanner scanner, List<Barang> daftar) // Fungsi untuk mengupdate data barang
    {
        System.out.print("Masukkan ID yang ingin diupdate : ");
        String id = scanner.nextLine();

        Optional<Barang> barangOpt = daftar.stream() // Pake stream untuk mencari barang berdasarkan ID
            .filter(p -> p.cocokId(id))
            .findFirst();

        if (barangOpt.isPresent()) // Jika barang ditemukan
        {
            // Tampilkan data barang yang akan diupdate
            Barang p = barangOpt.get();
            System.out.println("Nama : " + p.getNama());
            System.out.println("Harga : " + p.getHarga());
            System.out.println("Stok : " + p.getStok() + "\n");

            // Minta input baru untuk update
            System.out.print("Masukkan Nama Baru : ");
            String namaBaru = scanner.nextLine();
            System.out.print("Masukkan Harga Baru : ");
            int hargaBaru = scanner.nextInt();
            System.out.print("Masukkan Stok Baru : ");
            int stokBaru = scanner.nextInt();
            scanner.nextLine(); // Konsumsi newline

            p.editData(namaBaru, hargaBaru, stokBaru); // Update data barang
            System.out.println("Data berhasil diupdate!\n");
        } else {
            System.out.println("Data gaada\n");
        }
    }

    private static void tampilkanSemuabarang(List<Barang> daftar) // Fungsi untuk menampilkan semua barang
    {
        if (daftar.isEmpty())
        {
            System.out.println("Data kosong\n");
        } else {
            System.out.println("ID, Nama, Harga, Stok:");
            for (int i = 0; i < daftar.size(); i++)
            {
                System.out.println((i + 1) + ". " + daftar.get(i));
            }
            System.out.println();
        }
    }

    private static void caribarang(Scanner scanner, List<Barang> daftar) // Fungsi untuk mencari barang berdasarkan ID
    {
        System.out.print("Masukkan ID yang ingin dicari : ");
        String id = scanner.nextLine();

        Optional<Barang> barangOpt = daftar.stream() // Pake stream untuk mencari barang berdasarkan ID
            .filter(p -> p.cocokId(id))
            .findFirst();

        if (barangOpt.isPresent()) // Jika barang ditemukan
        {
            // Tampilkan data barang yang ditemukan
            Barang p = barangOpt.get();
            System.out.println("Berikut data dengan ID " + id + " :");
            System.out.println("Nama : " + p.getNama());
            System.out.println("Harga : " + p.getHarga());
            System.out.println("Stok : " + p.getStok() + "\n");
        } else {
            System.out.println("Data gaada\n");
        }
    }
}