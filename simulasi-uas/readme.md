### Inisialisasi folder dan file
Pada step ini, buatlah folder uas dengan cara
`mkdir uas`

### 
Lalu masuk ke dalam direktori
`cd uas`

###
buat file .env dengan cara `touch .env dengan isinya
```
COMPOSE_PROJECT_NAME=uas
IMAGE_TAG=latest
```

___

### Inisialisai Docker
buat file `docker-compose.yml` dengan cara `touch docker-compose.yml` dengan isinya
```
version: '3'

services:
  mysql_cpp:
    image: mariadb:10.2
    container_name: mysql_cpp
    restart: unless-stopped
    tty: true
    ports:
      - "31235:3306"
    volumes:
      - ./database/data:/var/lib/mysql
      - ./database/conf.d:/etc/mysql/conf.d:ro
    environment:
      MYSQL_USER: root
      MYSQL_PASSWORD: 123
      MYSQL_ROOT_PASSWORD: 123
      SERVICE_TAGS: dev
      SERVICE_NAME: mysql
    read_only: false

  # phpmyadmin:
  #   image: phpmyadmin:latest
  #   container_name: phpmyadmin
  #   restart: always
  #   ports:
  #     - 9100:80
  #   environment:
  #     - PMA_ARBITRARY=1
```

###
setelah itu build dockernya dengan cara `docker-compose up -d --build`

___
### Create Database
jika docker telah berjalan, buka navicat lalu create new connection mysql ketentuan

```
connection name: uas
host : 127.0.0.1
password : 123
```
setelah itu buat database baru dengan nama `perpustakaan`

___

### Crate Table
masuk ke mysql dengan cara `docker exec -it mysql_cpp  mysql -u root -p`

passwordnya adalah : 123

masuk ke database yang telah dibuat
```
USE perpustakaan;
```

#### Create table users
```
CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    password VARCHAR(50) NOT NULL,
    role ENUM('admin', 'user') NOT NULL
);
```

#### Create table komik
```
CREATE TABLE IF NOT EXISTS komik (
    id INT AUTO_INCREMENT PRIMARY KEY,
    judul VARCHAR(100) NOT NULL,
    penulis VARCHAR(50) NOT NULL,
    studio VARCHAR(50) NOT NULL,
    tahun_terbit INT NOT NULL,
    stok INT NOT NULL,
    genre VARCHAR(100) NOT NULL
);
```

#### Create table peminjaman
```
CREATE TABLE IF NOT EXISTS peminjaman (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,
    comic_id INT,
    tanggal_peminjaman DATE,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (comic_id) REFERENCES komik(id)
);
```

#### Create table pengembalian
```
CREATE TABLE IF NOT EXISTS peminjaman (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,
    comic_id INT,
    tanggal_peminjaman DATE,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (comic_id) REFERENCES komik(id)
);
```

___

### CRUD
pastekan code pada file crud.cc

___

### Compile
lalu compile file crud.cc
` g++ -o crud crud.cc -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient -lssl -lcrypto`

| **Command**        | **Deskripsi** |
|-------------------|--------------|
| `g++`              | **Deskripsi**: `g++` adalah compiler C++ dari GNU Compiler Collection (GCC). Digunakan untuk mengkompilasi dan menghubungkan (link) kode sumber C++. |
| `-o crud`         | **Deskripsi**: Opsi `-o` diikuti dengan nama file output yang diinginkan, dalam hal ini `crud`. Ini menentukan nama file yang dihasilkan setelah proses kompilasi selesai. Tanpa opsi ini, output default adalah `a.out`. |
| `crud.cc`         | **Deskripsi**: `crud.cc` adalah file sumber C++ yang berisi kode program yang akan dikompilasi. Nama file yang berisi kode sumber C++ Anda. |
| `-I/usr/include/mysql` | **Deskripsi**: Opsi `-I` digunakan untuk menambahkan direktori ke dalam daftar lokasi header file yang dicari oleh compiler. `-I/usr/include/mysql` menyertakan direktori `/usr/include/mysql` dalam pencarian header file. Direktori ini biasanya berisi file header untuk MySQL Connector/C++. |
| `-L/usr/lib/mysql`  | **Deskripsi**: Opsi `-L` digunakan untuk menambahkan direktori ke dalam daftar lokasi library yang dicari oleh linker. `-L/usr/lib/mysql` menambahkan direktori `/usr/lib/mysql` dalam pencarian library. Direktori ini biasanya berisi file library yang diperlukan untuk MySQL. |
| `-lmysqlclient`   | **Deskripsi**: Opsi `-l` digunakan untuk menyertakan library dalam proses linking. `-lmysqlclient` menghubungkan program dengan library `libmysqlclient`, yang menyediakan API untuk berinteraksi dengan server MySQL. |
| `-lssl`           | **Deskripsi**: Opsi `-l` digunakan untuk menyertakan library dalam proses linking. `-lssl` menghubungkan program dengan library `libssl`, yang menyediakan dukungan untuk protokol SSL/TLS. |
| `-lcrypto`        | **Deskripsi**: Opsi `-l` digunakan untuk menyertakan library dalam proses linking. `-lcrypto` menghubungkan program dengan library `libcrypto`, yang menyediakan fungsi kriptografi yang digunakan oleh `libssl`. |
