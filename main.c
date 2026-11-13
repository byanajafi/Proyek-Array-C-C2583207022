#include <stdio.h>
#include <string.h>

#define MAX_PRODUK 50

char namaProduk[MAX_PRODUK][50];
int harga[MAX_PRODUK];
int stok[MAX_PRODUK];
int jumlahTerjual[MAX_PRODUK];

int jumlahProduk = 5;

    void tampilkanProduk() {
        printf("\n========== DAFTAR PRODUK ==========\n");

    for (int i = 0; i < jumlahProduk; i++) {
        printf("%d. %s | Harga: Rp%d | Stok: %d | Terjual: %d\n",
               i + 1, namaProduk[i], harga[i],
               stok[i], jumlahTerjual[i]);
    }
}

    void tambahProduk() {
        if (jumlahProduk >= MAX_PRODUK) {
        printf("\nKapasitas produk sudah penuh!\n");
        return;
    }

    char namaBaru[50];
    int hargaBaru, stokBaru;

    printf("\n========== TAMBAH PRODUK ==========\n");

    printf("Nama produk: ");
    scanf(" %49[^\n]", namaBaru);

    printf("Harga produk: ");
    scanf("%d", &hargaBaru);

    printf("Stok produk: ");
    scanf("%d", &stokBaru);

    if (hargaBaru < 0 || stokBaru < 0) {
        printf("Harga dan stok tidak boleh negatif!\n");
        return;
    }

    strcpy(namaProduk[jumlahProduk], namaBaru);
    harga[jumlahProduk] = hargaBaru;
    stok[jumlahProduk] = stokBaru;
    jumlahTerjual[jumlahProduk] = 0;

    jumlahProduk++;

    printf("Produk berhasil ditambahkan!\n");
}

    void ubahProduk() {
        int nomor, hargaBaru, stokBaru;

    tampilkanProduk();

    printf("\nMasukkan nomor produk yang ingin diubah: ");
    scanf("%d", &nomor);

    if (nomor < 1 || nomor > jumlahProduk) {
        printf("Nomor produk tidak ditemukan!\n");
        return;
    }

    int index = nomor - 1;

    printf("Harga baru: ");
    scanf("%d", &hargaBaru);

    printf("Stok baru: ");
    scanf("%d", &stokBaru);

    if (hargaBaru < 0 || stokBaru < 0) {
        printf("Harga dan stok tidak boleh negatif!\n");
        printf("Data produk tidak jadi diubah.\n");
        return;
    }

    harga[index] = hargaBaru;
    stok[index] = stokBaru;

    printf("Data produk berhasil diubah!\n");
}

    void transaksiPenjualan() {
        int jumlahBeli[MAX_PRODUK] = {0};
        int nomor, jumlah;
        int total = 0;
        int subtotal;

    printf("\n========== TRANSAKSI PENJUALAN ==========\n");

    tampilkanProduk();

    printf("\nMasukkan 0 jika selesai memilih produk.\n");

    while (1) {
        printf("\nNomor produk: ");
        scanf("%d", &nomor);

        if (nomor == 0) {
            break;
        }

        if (nomor < 1 || nomor > jumlahProduk) {
            printf("Nomor produk tidak ditemukan!\n");
            continue;
        }

        int index = nomor - 1;

        printf("Jumlah pembelian: ");
        scanf("%d", &jumlah);

        if (jumlah <= 0) {
            printf("Jumlah harus lebih dari 0!\n");
            continue;
        }

        if (jumlah > stok[index] - jumlahBeli[index]) {
            printf("Stok tidak mencukupi!\n");
            printf("Stok tersedia: %d\n",
                   stok[index] - jumlahBeli[index]);
            continue;
        }

        jumlahBeli[index] += jumlah;

        subtotal = harga[index] * jumlah;

        printf("Produk: %s\n", namaProduk[index]);
        printf("Subtotal: Rp%d\n", subtotal);
    }

    for (int i = 0; i < jumlahProduk; i++) {
        total += harga[i] * jumlahBeli[i];
    }

    if (total == 0) {
        printf("\nTidak ada transaksi!\n");
        return;
    }

    for (int i = 0; i < jumlahProduk; i++) {
        stok[i] -= jumlahBeli[i];
        jumlahTerjual[i] += jumlahBeli[i];
    }

    printf("\n========== STRUK PEMBELIAN ==========\n");

    for (int i = 0; i < jumlahProduk; i++) {
        if (jumlahBeli[i] > 0) {
            printf("%s x %d = Rp%d\n",
                   namaProduk[i],
                   jumlahBeli[i],
                   harga[i] * jumlahBeli[i]);
        }
    }

    printf("-------------------------------------\n");
    printf("TOTAL PEMBAYARAN: Rp%d\n", total);
    printf("Transaksi berhasil!\n");
}

    void tambahStok() {
        int nomor, tambahan;

    printf("\n========== TAMBAH STOK ==========\n");

    tampilkanProduk();

    printf("\nMasukkan nomor produk: ");
    scanf("%d", &nomor);

    if (nomor < 1 || nomor > jumlahProduk) {
        printf("Nomor produk tidak ditemukan!\n");
        return;
    }

    printf("Jumlah stok tambahan: ");
    scanf("%d", &tambahan);

    if (tambahan <= 0) {
        printf("Jumlah tambahan harus lebih dari 0!\n");
        return;
    }

    stok[nomor - 1] += tambahan;

    printf("Stok berhasil ditambahkan!\n");
    printf("Stok sekarang: %d\n", stok[nomor - 1]);
}

    void cekStokMenipis() {
        int ditemukan = 0;

    printf("\n========== STOK MENIPIS ==========\n");

    for (int i = 0; i < jumlahProduk; i++) {
        if (stok[i] < 5) {
            printf("%s | Stok tersisa: %d\n",
                   namaProduk[i], stok[i]);
            ditemukan = 1;
        }
    }

    if (ditemukan == 0) {
        printf("Tidak ada produk dengan stok menipis.\n");
    }
}

    void cariProduk() {
        char cari[50];
        int ditemukan = 0;

    printf("\n========== CARI PRODUK ==========\n");
    printf("Masukkan nama produk: ");
    scanf(" %49[^\n]", cari);

    for (int i = 0; i < jumlahProduk; i++) {
        if (strcmp(namaProduk[i], cari) == 0) {
            printf("\nProduk ditemukan!\n");
            printf("Nama           : %s\n", namaProduk[i]);
            printf("Harga          : Rp%d\n", harga[i]);
            printf("Stok           : %d\n", stok[i]);
            printf("Jumlah Terjual : %d\n", jumlahTerjual[i]);

            ditemukan = 1;
            break;
        }
    }

    if (ditemukan == 0) {
        printf("Produk tidak ditemukan!\n");
    }
}

    void urutkanProduk() {
        int pilihan;

    printf("\n========== URUTKAN PRODUK ==========\n");
    printf("1. Harga Termurah\n");
    printf("2. Jumlah Terjual Terbanyak\n");
    printf("Pilih pengurutan: ");
    scanf("%d", &pilihan);

    if (pilihan != 1 && pilihan != 2) {
        printf("Pilihan tidak valid!\n");
        return;
    }

    for (int i = 0; i < jumlahProduk - 1; i++) {
        for (int j = 0; j < jumlahProduk - i - 1; j++) {

            int tukar = 0;

            if (pilihan == 1 && harga[j] > harga[j + 1]) {
                tukar = 1;
            }

            if (pilihan == 2 &&
                jumlahTerjual[j] < jumlahTerjual[j + 1]) {
                tukar = 1;
            }

            if (tukar) {
                int tempHarga = harga[j];
                harga[j] = harga[j + 1];
                harga[j + 1] = tempHarga;

                int tempStok = stok[j];
                stok[j] = stok[j + 1];
                stok[j + 1] = tempStok;

                int tempTerjual = jumlahTerjual[j];
                jumlahTerjual[j] = jumlahTerjual[j + 1];
                jumlahTerjual[j + 1] = tempTerjual;

                char tempNama[50];
                strcpy(tempNama, namaProduk[j]);
                strcpy(namaProduk[j], namaProduk[j + 1]);
                strcpy(namaProduk[j + 1], tempNama);
            }
        }
    }

    printf("\nPengurutan berhasil!\n");
    tampilkanProduk();
}

    void laporanPenjualan() {
        int totalUnit = 0;
        int totalPendapatan = 0;
        int indexTerlaris = 0;

    printf("\n========== LAPORAN PENJUALAN ==========\n");

    printf("\nDaftar Penjualan Produk:\n");

    for (int i = 0; i < jumlahProduk; i++) {
        int pendapatan = harga[i] * jumlahTerjual[i];

        printf("%s\n", namaProduk[i]);
        printf("Jumlah Terjual: %d\n", jumlahTerjual[i]);
        printf("Pendapatan: Rp%d\n\n", pendapatan);

        totalUnit += jumlahTerjual[i];
        totalPendapatan += pendapatan;

        if (jumlahTerjual[i] > jumlahTerjual[indexTerlaris]) {
            indexTerlaris = i;
        }
    }

    printf("=======================================\n");
    printf("Total Unit Terjual : %d\n", totalUnit);
    printf("Total Pendapatan   : Rp%d\n", totalPendapatan);

    if (totalUnit == 0) {
        printf("Produk Terlaris    : Belum ada penjualan\n");
    } else {
        printf("Produk Terlaris    : %s\n",
               namaProduk[indexTerlaris]);
        printf("Jumlah Terjual     : %d unit\n",
               jumlahTerjual[indexTerlaris]);
    }

    printf("=======================================\n");
}

int main() {

    strcpy(namaProduk[0], "Nasi Goreng");
    strcpy(namaProduk[1], "Mie Goreng");
    strcpy(namaProduk[2], "Ayam Geprek");
    strcpy(namaProduk[3], "Es Teh");
    strcpy(namaProduk[4], "Kopi Susu");

    harga[0] = 15000;
    harga[1] = 12000;
    harga[2] = 18000;
    harga[3] = 5000;
    harga[4] = 10000;

    stok[0] = 20;
    stok[1] = 15;
    stok[2] = 10;
    stok[3] = 30;
    stok[4] = 15;

    for (int i = 0; i < jumlahProduk; i++) {
        jumlahTerjual[i] = 0;
    }

    int pilihan;

    do {
        printf("\n====================================\n");
        printf(" SISTEM MONITORING STOK KANTIN\n");
        printf("====================================\n");
        printf("1. Lihat Daftar Produk\n");
        printf("2. Tambah Produk\n");
        printf("3. Ubah Produk\n");
        printf("4. Transaksi Penjualan\n");
        printf("5. Tambah Stok\n");
        printf("6. Cari Produk\n");
        printf("7. Urutkan Produk\n");
        printf("8. Laporan Penjualan\n");
        printf("9. Cek Stok Menipis\n");
        printf("0. Keluar\n");
        printf("====================================\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanProduk();
                break;
            case 2:
                tambahProduk();
                break;
            case 3:
                ubahProduk();
                break;
            case 4:
                transaksiPenjualan();
                break;
            case 5:
                tambahStok();
                break;
            case 6:
                cariProduk();
                break;
            case 7:
                urutkanProduk();
                break;
            case 8:
                laporanPenjualan();
                break;
            case 9:
                cekStokMenipis();
                break;
            case 0:
                printf("\nTerima kasih telah menggunakan program!\n");
                break;

            default:
                printf("\nMenu belum tersedia atau tidak valid!\n");
        }

    } while (pilihan != 0);

    return 0;
}

