# --- Program Kalkulator Indeks Massa Tubuh (IMT) Sederhana ---

# 1. Menampilkan judul dan penjelasan singkat kepada pengguna.
print("--- Selamat Datang di Kalkulator IMT ---")
print("Program ini akan membantu Anda menghitung Indeks Massa Tubuh Anda.")

# 2. Mengambil input berat badan dari pengguna.
# Fungsi input() akan menampilkan pertanyaan dan menunggu pengguna mengetik.
berat_str = input("Silakan masukkan berat badan Anda (dalam kg): ")

# 3. Mengambil input tinggi badan dari pengguna.
tinggi_str = input("Sekarang, masukkan tinggi badan Anda (dalam cm): ")

# 4. Mengkonversi tipe data input dari string menjadi float (bilangan desimal).
# Ini adalah langkah yang sangat penting untuk bisa melakukan perhitungan.
berat_kg = float(berat_str)
tinggi_cm = float(tinggi_str)

# 5. Melakukan konversi dan perhitungan.
# Mengubah tinggi dari cm ke meter.
tinggi_m = tinggi_cm / 100

# Menghitung IMT sesuai rumus: berat / (tinggi dalam meter kuadrat).
# Kita menggunakan operator pangkat ** untuk kuadrat.
imt = berat_kg / (tinggi_m ** 2)


# 6. Menampilkan hasil akhir kepada pengguna.
# Kita menggunakan f-string untuk menampilkan output yang rapi.
# Sintaks ':.2f' digunakan untuk memformat angka IMT agar hanya menampilkan 2 angka di belakang koma.
print("-----------------------------------------")
print(f"Berat Badan Anda: {berat_kg} kg")
print(f"Tinggi Badan Anda: {tinggi_m} m")
print(f"Indeks Massa Tubuh (IMT) Anda adalah: {imt:.2f}")
print("-----------------------------------------")