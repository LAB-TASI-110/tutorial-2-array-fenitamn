#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN (nilai integer maksimum dan minimum)

int main() {
    int n; // Variabel untuk menyimpan jumlah baris masukan berikutnya
    int num; // Variabel untuk menyimpan setiap bilangan yang dibaca
    int min_val = INT_MAX; // Inisialisasi min_val dengan nilai integer maksimum agar bilangan pertama pasti lebih kecil
    int max_val = INT_MIN; // Inisialisasi max_val dengan nilai integer minimum agar bilangan pertama pasti lebih besar

    // 1. Membaca jumlah baris masukan berikutnya (n)
    if (scanf("%d", &n) != 1) {
        // Penanganan kesalahan jika input n tidak valid
        fprintf(stderr, "Error: Gagal membaca jumlah baris (n).\n");
        return 1; // Keluar dengan kode error
    }

    // Memastikan n positif untuk menghindari loop tak terbatas atau perilaku tak terdefinisi
    if (n <= 0) {
        // Penanganan kasus di mana n bukan bilangan bulat positif
        fprintf(stderr, "Error: Jumlah baris (n) harus bilangan bulat positif.\n");
        return 1;
    }

    // 2. Melakukan perulangan sebanyak n kali untuk membaca setiap bilangan
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &num) != 1) {
            // Penanganan kesalahan jika input bilangan tidak valid
            fprintf(stderr, "Error: Gagal membaca bilangan ke-%d.\n", i + 1);
            return 1;
        }

        // 3. Membandingkan dan memperbarui nilai terkecil (min_val)
        if (num < min_val) {
            min_val = num;
        }

        // 4. Membandingkan dan memperbarui nilai terbesar (max_val)
        if (num > max_val) {
            max_val = num;
        }
    }

    // 5. Menampilkan hasil nilai terkecil dan terbesar
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0; // Menandakan program berakhir dengan sukses
}
