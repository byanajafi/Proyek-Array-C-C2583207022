Sistem Monitoring Stok dan Penjualan Kantin Kampus

Identitas
- Nama: Bya Hujjattul Ridho Najafi
- NIM: C2583207022
- Kelas: PTI 3B
- Mata Kuliah: Algoritma dan Pemrograman Lanjutan

Deskripsi Proyek
Program ini merupakan aplikasi berbasis console yang dibuat menggunakan bahasa pemrograman C untuk membantu mengelola stok produk dan transaksi penjualan kantin kampus.

Program menggunakan array sebagai struktur data utama untuk menyimpan nama produk, harga, stok, dan jumlah produk yang terjual.

Fitur Program
1. Menampilkan daftar produk.
2. Menambahkan produk baru.
3. Mengubah harga dan stok produk.
4. Mencari produk berdasarkan nama.
5. Melakukan transaksi beberapa produk sekaligus.
6. Menambahkan stok produk.
7. Menampilkan peringatan stok menipis (kurang dari 5).
8. Menampilkan laporan penjualan.
9. Mengurutkan produk berdasarkan harga termurah dan penjualan tertinggi.
10. Memvalidasi input agar harga dan stok tidak bernilai negatif serta mencegah transaksi melebihi stok.

Implementasi Array
Program menggunakan:
- Array 2 dimensi (`namaProduk[50][50]`) untuk menyimpan nama produk.
- Array 1 dimensi (`harga[50]`) untuk menyimpan harga produk.
- Array 1 dimensi (`stok[50]`) untuk menyimpan jumlah stok produk.
- Array 1 dimensi (`terjual[50]`)** untuk menyimpan jumlah produk yang terjual.

Kapasitas maksimum program adalah 50 produk.

Cara Menjalankan Program
1. Buka file `main.c` menggunakan Code::Blocks.
2. Compile program.
3. Jalankan program dengan menekan tombol Run.
4. Pilih menu yang tersedia sesuai kebutuhan.

Dokumentasi Pengujian
1. Pengujian Tambah Produk
![Pengujian Tambah Produk](Screenshot%202026-11-11%20203652.png)
2. Transaksi Penjualan Beberapa Produk
3. Pengujian Perubahan Stok dan Jumlah Produk Terjual
4. Pengujian Penolakan Transaksi Karena Stok Tidak Cukup
5. Pengujian Laporan Penjualan
6. Pengujian Pengurutan Produk Berdasarkan Harga Termurah
7. Pengujian Pengurutan Produk Berdasarkan Penjualan Tertinggi
8. Pengujian Pencarian Produk
9. Pengujian Peringatan Stok Menipis
