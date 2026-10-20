# 🔐 C XOR Metin Gizleyici / Text Obfuscator (`c-xor-encoder`)

[TR] **Türkçe** | [EN] **English**

---

## 🇹🇷 Türkçe Dokümantasyon

Metinleri bit düzeyinde **XOR (**$\oplus$**) işlemleri** kullanarak gizleyen (obfuscation) ve çözen (deobfuscation), harici bağımlılığı olmayan (zero-dependency) C dili ile yazılmış hafif bir Komut Satırı Arayüzü (CLI) aracıdır.

**Red Team operasyonları**, **statik analiz engelleme araştırmaları** ve **exploit geliştirme** süreçlerinde; komutlar, IP adresleri ve API fonksiyon isimleri gibi statik verileri `strings` benzeri analiz araçlarından ve Antivirüs/EDR imzalarından gizlemek için tasarlanmıştır.

### 🎯 Siber Güvenlik Bağlamı ve Kullanım Senaryoları

Statik analiz sırasında güvenlik analistleri ve EDR/AV çözümleri, derlenmiş binary dosyalarının içindeki sabit metinleri (örneğin `"cmd.exe"`, `"192.168.1.100"`) tarar.

XOR bit düzeyinde gizleme tekniği operatörlere şu avantajları sağlar:

* **Statik İncelemeyi Atlatma:** Düz metinleri derlenmiş dosya içinde okunamayan bayt dizilerine dönüştürür.
* **Dinamik RAM Çözümleme:** Metinleri bellekte ($\text{RAM}$) tam çalıştırılma anında eski haline getirir.
* **Sıfır Bağımlılık (Zero Dependency):** Kriptografik Windows API'lerini (`Advapi32.dll` veya `Crypt32.dll` gibi) çağırmayarak sezgisel (heuristic) tespit mekanizmalarına takılmaz.

### ✨ Özellikler

* **İnteraktif CLI Menüsü:** Şifreleme ve çözme işlemleri için menü tabanlı kullanım.
* **Bit Düzeyinde XOR Mantığı:** Simetrik şifreleme yapısı ($A \oplus \text{Key} \oplus \text{Key} = A$).
* **Bellek Güvenliği:** Yığın tabanlı bellek taşmalarını (Stack Buffer Overflow) önleyen `%29s` sınır kontrolü.
* **Hafif ve Hızlı:** Sadece standart C kütüphaneleri (`stdio.h`, `stdlib.h`) kullanır.

### 🚀 Derleme ve Çalıştırma

#### Gereksinimler
* GCC, Clang veya MSVC C derleyicisi

#### Derleme
```bash
gcc -o c-xor-encoder main.c
```

#### Çalıştırma
```bash
./c-xor-encoder
```

### 💻 Kullanım Örneği

```text
----- XOR Sifreleme Programi -----
1 - XOR Encoder (Sifrele)
2 - XOR Decoder (Coz)
Seciminiz: 1
Lutfen Metninizi Giriniz: virus.exe

Sifreli (Gizlenmis) Hali: \x39\x37\x3E...
```

---

## 🇬🇧 English Documentation

A lightweight, zero-dependency Command Line Interface (CLI) tool written in **C** for string obfuscation and deobfuscation using bitwise **XOR (**$\oplus$**) operations**.

Designed for **Red Team operations**, **anti-analysis research**, and **exploit development** where hiding static strings (IPs, API functions, commands) from static analysis tools like `strings` or basic Antivirus/EDR signatures is required.

### 🎯 Security Context & Use Cases

During static analysis, security analysts and EDR/AV solutions scan executable binaries for hardcoded strings (e.g., `"cmd.exe"`, `"192.168.1.100"`).

Using XOR bitwise obfuscation allows operators to:

* **Bypass Static Inspection:** Obfuscate plain text into non-readable byte sequences inside the compiled binary.
* **Dynamic RAM Decryption:** Restore strings in memory ($\text{RAM}$) on-the-fly right before execution.
* **Zero Dependency Footprint:** Avoid importing cryptographic Windows APIs (like `Advapi32.dll` or `Crypt32.dll`) which can trigger heuristic detection flags.

### ✨ Features

* **Interactive CLI Interface:** Menu-driven interface for encoding and decoding workflows.
* **Bitwise XOR Logic:** Symmetric encryption scheme ($A \oplus \text{Key} \oplus \text{Key} = A$).
* **Memory Safety:** Built-in buffer bounds checking (`%29s` limit) to prevent stack-based buffer overflows.
* **Lightweight:** Pure C standard library (`stdio.h`, `stdlib.h`), compiled to a tiny executable footprint.

### 🚀 Getting Started

#### Compilation
```bash
gcc -o c-xor-encoder main.c
```

#### Execution
```bash
./c-xor-encoder
```

---

## 🛠️ Code Structure & Logic / Kod Yapısı

### 1. XOR Transformation Loop / Şifreleme Döngüsü

```c
for (i = 0; veriname[i] != '\0'; i++) {
    veriname[i] = veriname[i] ^ key;
}
```

* Null karakter (`\0`) görene kadar tüm baytları gezer.
* Her bayta tek baytlık XOR anahtarını (`0x5A`) uygular.

### 2. Buffer Bounds Safety / Sınır Kontrolü

```c
scanf("%29s", veriname);
```

* 30 baytlık bellek alanına en fazla 29 bayt veri kabul ederek **Buffer Overflow** zafiyetini engeller.

---

## ⚠️ Disclaimer / Sorumluluk Reddi

Bu araç yalnızca eğitim, savunma analizi ve izinli Red Team testleri amacıyla geliştirilmiştir. Yasa dışı kullanımlardan geliştirici sorumlu tutulamaz.

## 🧑‍💻 Author / Geliştirici

* **Siber Vatan 2027 Adayı** | Bilgisayar Programcılığı Öğrencisi & Red Team Meraklısı
