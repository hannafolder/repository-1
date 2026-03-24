import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

target_berat_mean = 250.0  # dalam gram
standar_deviasi = 2.0  # dalam gram
jumlah_sampel = 10000

berat_aktual_sampel = np.random.normal(
    loc=target_berat_mean,      # loc adalah mean atau pusat distribusi
    scale=standar_deviasi,    # scale adalah standar deviasi
    size=jumlah_sampel        # size adalah jumlah data yang ingin dihasilkan
)

print("Membuat visualisasi distribusi berat kopi...")
sns.set_theme(style="whitegrid") 
plt.figure(figsize=(12, 7))

sns.histplot(berat_aktual_sampel, kde=True, bins=50, color='saddlebrown')

plt.axvline(target_berat_mean, color='red', linestyle='--', label=f'Target Rata-rata: {target_berat_mean:.2f}g')
plt.axvline(target_berat_mean + standar_deviasi, color='green', linestyle=':', label=f'+1 Standar Deviasi')
plt.axvline(target_berat_mean - standar_deviasi, color='green', linestyle=':', label=f'-1 Standar Deviasi')

plt.title(f'Simulasi Distribusi Berat untuk {jumlah_sampel} Kantong Kopi')
plt.xlabel('Berat Aktual (gram)')
plt.ylabel('Frekuensi')
plt.legend() 
plt.savefig('distribusi_berat_kopi.png')
plt.show()

jumlah_cacat = np.sum(berat_aktual_sampel < 245)
probabilitas_cacat = (jumlah_cacat / jumlah_sampel) * 100

print(f"\n--- Analisis Probabilitas Kontrol Kualitas ---")
print(f"Dari {jumlah_sampel} sampel, ditemukan {jumlah_cacat} kantong di bawah spesifikasi (245g).")
print(f"Perkiraan probabilitas produk cacat: {probabilitas_cacat:.2f}%")
