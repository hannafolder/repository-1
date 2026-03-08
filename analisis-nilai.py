data_nilai = [
    {'nama': 'Andi', 'mata_pelajaran': 'Matematika', 'nilai': 85},
    {'nama': 'Budi', 'mata_pelajaran': 'Matematika', 'nilai': 92},
    {'nama': 'Citra', 'mata_pelajaran': 'Matematika', 'nilai': 78},
    {'nama': 'Andi', 'mata_pelajaran': 'Fisika', 'nilai': 90},
    {'nama': 'Budi', 'mata_pelajaran': 'Fisika', 'nilai': 88},
    {'nama': 'Citra', 'mata_pelajaran': 'Fisika', 'nilai': 82},
    {'nama': 'Andi', 'mata_pelajaran': 'Kimia', 'nilai': 76},
    {'nama': 'Budi', 'mata_pelajaran': 'Kimia', 'nilai': 80},
    {'nama': 'Citra', 'mata_pelajaran': 'Kimia', 'nilai': 95},
]

def hitung_rata_rata_per_mapel(data, mata_pelajaran):
    """Fungsi untuk menghitung nilai rata-rata untuk mata pelajaran tertentu."""
    total_nilai = 0
    jumlah_siswa = 0
    for entri in data:
        if entri['mata_pelajaran'] == mata_pelajaran:
            total_nilai += entri['nilai']
            jumlah_siswa += 1

    return total_nilai / jumlah_siswa

def temukan_mata_pelajaran_unik(data):
    """Fungsi untuk menemukan semua mata pelajaran unik dari dataset menggunakan Set."""
    semua_mapel = []
    for entri in data:
        semua_mapel.append(entri['mata_pelajaran'])

    mapel_unik = set(semua_mapel)
    return mapel_unik


print("--- Sistem Analisis Nilai Sederhana ---")

daftar_mapel_unik = temukan_mata_pelajaran_unik(data_nilai)
print(f"Mata Pelajaran yang Tersedia untuk Dianalisis: {daftar_mapel_unik}")
print("-" * 40)

for mapel in daftar_mapel_unik:
    rata_rata = hitung_rata_rata_per_mapel(data_nilai, mapel)
    print(f"Rata-rata nilai untuk mata pelajaran {mapel}: {rata_rata:.2f}")
