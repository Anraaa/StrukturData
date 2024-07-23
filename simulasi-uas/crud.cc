#include <iostream>
#include <mysql/mysql.h>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>  // Untuk std::setw()
#include <cstdlib>  // Untuk std::system()'
#include <limits>

using namespace std;

const char* hostname = "127.0.0.1";
const char* user = "root";
const char* pass = "123";
const char* dbname = "perpustakaan";
unsigned int port = 31235;
const char* unixsocket = NULL;
unsigned long clientflag = 0;

MYSQL* connect_db() {
    MYSQL* conn = mysql_init(0);
    if (conn) {
        conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
        if (conn) {
            cout << "Connected to the database successfully." << endl;
        } else {
            cerr << "Connection failed: " << mysql_error(conn) << endl;
        }
    } else {
        cerr << "mysql_init failed" << endl;
    }
    return conn;
}

// Fungsi untuk membersihkan layar konsol
void clear_screen() {
    #ifdef _WIN32
    std::system("cls");  // Windows
    #else
    std::system("clear");  // Unix/Linux/Mac
    #endif
}

// Fungsi untuk menunggu input pengguna untuk melanjutkan
void press_enter_to_continue() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void create_user(const string& username, const string& password, const string& role) {
    if (role != "user") {
        cout << "You cannot register as admin. Only users can register." << endl;
        return;
    }

    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "INSERT INTO users (username, password, role) VALUES ('" << username << "', '" << password << "', '" << role << "')";
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
        } else {
            cout << "User successfully added." << endl;
        }
        mysql_close(conn);
    }
}

bool login_user(const string& username, const string& password, string& role) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "SELECT role FROM users WHERE username = '" << username << "' AND password = '" << password << "'";
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return false;
        }

        MYSQL_RES* res = mysql_store_result(conn);
        if (res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return false;
        }

        MYSQL_ROW row = mysql_fetch_row(res);
        if (row) {
            role = row[0];
            mysql_free_result(res);
            mysql_close(conn);
            return true;
        } else {
            mysql_free_result(res);
            mysql_close(conn);
            return false;
        }
    }
    return false;
}

void create_comic(const string& judul, const string& penulis, const string& studio, int tahun_terbit, int stok, const string& genre) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "INSERT INTO komik (judul, penulis, studio, tahun_terbit, stok, genre) VALUES ('"
              << judul << "', '"
              << penulis << "', '"
              << studio << "', "
              << tahun_terbit << ", "
              << stok << ", '"
              << genre << "')";
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Comic successfully added." << endl;
        }
        mysql_close(conn);
    }
}

void get_comics() {
    MYSQL* conn = connect_db();
    if (conn) {
        if (mysql_query(conn, "SELECT * FROM komik")) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_RES* res = mysql_store_result(conn);
        if (res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        // Menampilkan header dengan lebar kolom yang disesuaikan
        cout << left << setw(5) << "ID" 
             << setw(30) << "Judul" 
             << setw(20) << "Penulis" 
             << setw(20) << "Studio" 
             << setw(15) << "Tahun Terbit" 
             << setw(10) << "Stok" 
             << setw(30) << "Genre" 
             << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;

        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            cout << left << setw(5) << row[0] 
                 << setw(30) << row[1] 
                 << setw(20) << row[2] 
                 << setw(20) << row[3] 
                 << setw(15) << row[4] 
                 << setw(10) << row[5] 
                 << setw(30) << row[6] 
                 << endl;
        }

        mysql_free_result(res);
        mysql_close(conn);
        press_enter_to_continue();  // Menunggu input untuk melanjutkan
    }
}

void show_comics_by_genre() {
    MYSQL* conn = connect_db();
    if (conn) {
        string genre;
        cout << "Enter Genre(s) (separate multiple genres with commas): ";
        cin.ignore();
        getline(cin, genre);

        stringstream query;
        query << "SELECT * FROM komik WHERE genre LIKE '%" << genre << "%'";
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_RES* res = mysql_store_result(conn);
        if (res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        // Menampilkan header dengan lebar kolom yang disesuaikan
        cout << left << setw(5) << "ID" 
             << setw(30) << "Judul" 
             << setw(20) << "Penulis" 
             << setw(20) << "Studio" 
             << setw(15) << "Tahun Terbit" 
             << setw(10) << "Stok" 
             << setw(30) << "Genre" 
             << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl;

        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            cout << left << setw(5) << row[0] 
                 << setw(30) << row[1] 
                 << setw(20) << row[2] 
                 << setw(20) << row[3] 
                 << setw(15) << row[4] 
                 << setw(10) << row[5] 
                 << setw(30) << row[6] 
                 << endl;
        }

        mysql_free_result(res);
        mysql_close(conn);
        press_enter_to_continue();  // Menunggu input untuk melanjutkan
    }
}


void validate_input() {
    if (cin.fail()) {
        cin.clear(); // Clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}

void update_comic(int comic_id) {
    MYSQL* conn = connect_db();
    if (conn) {
        string judul, penulis, studio, genre;
        int tahun_terbit = 0, stok = 0;
        bool update_judul = false, update_penulis = false, update_studio = false, update_tahun = false, update_stok = false, update_genre = false;

        // Debugging
        cout << "Debug: Entered update_comic function with ID " << comic_id << endl;

        // Check if comic with ID exists
        stringstream check_query;
        check_query << "SELECT * FROM komik WHERE id = " << comic_id;
        if (mysql_query(conn, check_query.str().c_str())) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_RES* res = mysql_store_result(conn);
        if (res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_ROW row = mysql_fetch_row(res);
        if (!row) {
            cout << "Comic with ID " << comic_id << " does not exist." << endl;
            mysql_free_result(res);
            mysql_close(conn);
            return;
        }

        cout << "Comic with ID " << comic_id << " exists. Enter new details." << endl;
        mysql_free_result(res);

        // Input new details
        cout << "Enter new Judul (leave empty to keep current): ";
        getline(cin, judul);
        if (!judul.empty()) {
            update_judul = true;
        } else {
            judul = row[1]; // keep current value
        }

        cout << "Enter new Penulis (leave empty to keep current): ";
        getline(cin, penulis);
        if (!penulis.empty()) {
            update_penulis = true;
        } else {
            penulis = row[2]; // keep current value
        }

        cout << "Enter new Studio (leave empty to keep current): ";
        getline(cin, studio);
        if (!studio.empty()) {
            update_studio = true;
        } else {
            studio = row[3]; // keep current value
        }

        cout << "Enter new Tahun Terbit (leave 0 to keep current): ";
        cin >> tahun_terbit;
        cin.ignore(); // Clear newline character from the input buffer
        if (tahun_terbit != 0) {
            update_tahun = true;
        } else {
            tahun_terbit = atoi(row[4]); // keep current value
        }

        cout << "Enter new Stok (leave 0 to keep current): ";
        cin >> stok;
        cin.ignore(); // Clear newline character from the input buffer
        if (stok != 0) {
            update_stok = true;
        } else {
            stok = atoi(row[5]); // keep current value
        }

        cout << "Enter new Genre(s) (leave empty to keep current): ";
        getline(cin, genre);
        if (!genre.empty()) {
            update_genre = true;
        } else {
            genre = row[6]; // keep current value
        }

        // Construct the update query
        stringstream query;
        query << "UPDATE komik SET ";
        if (update_judul) query << "judul = '" << judul << "', ";
        if (update_penulis) query << "penulis = '" << penulis << "', ";
        if (update_studio) query << "studio = '" << studio << "', ";
        if (update_tahun) query << "tahun_terbit = " << tahun_terbit << ", ";
        if (update_stok) query << "stok = " << stok << ", ";
        if (update_genre) query << "genre = '" << genre << "', ";
        query.seekp(-2, query.cur); // Remove last comma and space
        query << " WHERE id = " << comic_id;

        // Debugging
        cout << "Debug: Judul = '" << judul << "'" << endl;
        cout << "Debug: Penulis = '" << penulis << "'" << endl;
        cout << "Debug: Studio = '" << studio << "'" << endl;
        cout << "Debug: Tahun Terbit = " << tahun_terbit << endl;
        cout << "Debug: Stok = " << stok << endl;
        cout << "Debug: Genre = '" << genre << "'" << endl;
        cout << "Update Query: " << query.str() << endl;

        if (mysql_query(conn, query.str().c_str())) {
            cerr << "UPDATE failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Comic successfully updated." << endl;
        }

        mysql_close(conn);
    }
}


void delete_comic(int comic_id) {
    MYSQL* conn = connect_db();
    if (conn) {
        // Cek apakah komik dengan ID yang diberikan ada
        stringstream check_query;
        check_query << "SELECT * FROM komik WHERE id = " << comic_id;
        if (mysql_query(conn, check_query.str().c_str())) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_RES* res = mysql_store_result(conn);
        if (res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_ROW row = mysql_fetch_row(res);
        if (!row) {
            cout << "Comic with ID " << comic_id << " does not exist." << endl;
            mysql_free_result(res);
            mysql_close(conn);
            return;
        }
        mysql_free_result(res);

        // Hapus komik dengan ID yang diberikan
        stringstream query;
        query << "DELETE FROM komik WHERE id = " << comic_id;
        if (mysql_query(conn, query.str().c_str())) {
            if (mysql_errno(conn) == 1451) { // Error code for foreign key constraint
                cerr << "DELETE failed: Cannot delete or update a parent row: a foreign key constraint fails" << endl;
            } else {
                cerr << "DELETE failed: " << mysql_error(conn) << endl;
            }
        } else {
            cout << "Comic successfully deleted." << endl;
        }

        mysql_close(conn);
    }
}


// Tambahkan fungsi untuk meminjam komik
void borrow_comic(const string& username) {
    MYSQL* conn = connect_db();
    if (conn) {
        int comic_id;
        cout << "Enter Comic ID to borrow: ";
        cin >> comic_id;

        // Cek stok komik
        stringstream check_query;
        check_query << "SELECT stok FROM komik WHERE id = " << comic_id;
        if (mysql_query(conn, check_query.str().c_str())) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_RES* res = mysql_store_result(conn);
        if (res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_ROW row = mysql_fetch_row(res);
        if (!row) {
            cout << "Comic not found." << endl;
            mysql_free_result(res);
            mysql_close(conn);
            return;
        }

        int stok = atoi(row[0]);
        if (stok > 0) {
            // Kurangi stok komik
            stringstream update_query;
            update_query << "UPDATE komik SET stok = stok - 1 WHERE id = " << comic_id;
            if (mysql_query(conn, update_query.str().c_str())) {
                cerr << "UPDATE failed: " << mysql_error(conn) << endl;
                mysql_free_result(res);
                mysql_close(conn);
                return;
            }

            // Ambil user_id dari username
            stringstream user_query;
            user_query << "SELECT id FROM users WHERE username = '" << username << "'";
            if (mysql_query(conn, user_query.str().c_str())) {
                cerr << "SELECT failed: " << mysql_error(conn) << endl;
                mysql_free_result(res);
                mysql_close(conn);
                return;
            }

            MYSQL_RES* user_res = mysql_store_result(conn);
            if (user_res == nullptr) {
                cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
                mysql_free_result(res);
                mysql_close(conn);
                return;
            }

            MYSQL_ROW user_row = mysql_fetch_row(user_res);
            if (!user_row) {
                cout << "User not found." << endl;
                mysql_free_result(user_res);
                mysql_free_result(res);
                mysql_close(conn);
                return;
            }

            int user_id = atoi(user_row[0]);
            mysql_free_result(user_res);

            // Catat peminjaman
            stringstream borrow_query;
            borrow_query << "INSERT INTO peminjaman (user_id, comic_id, tanggal_peminjaman) VALUES ("
                        << user_id << ", " << comic_id << ", CURDATE())";
            if (mysql_query(conn, borrow_query.str().c_str())) {
                cerr << "INSERT failed: " << mysql_error(conn) << endl;
            } else {
                cout << "Comic successfully borrowed." << endl;
            }
        } else {
            cout << "No stock available for this comic." << endl;
        }

        mysql_free_result(res);
        mysql_close(conn);
    }
}

// Tambahkan fungsi untuk mengembalikan komik
void return_comic(const string& username) {
    MYSQL* conn = connect_db();
    if (conn) {
        int comic_id;
        cout << "Enter Comic ID to return: ";
        cin >> comic_id;

        // Ambil user_id dari username
        stringstream user_query;
        user_query << "SELECT id FROM users WHERE username = '" << username << "'";
        if (mysql_query(conn, user_query.str().c_str())) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_RES* user_res = mysql_store_result(conn);
        if (user_res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_ROW user_row = mysql_fetch_row(user_res);
        if (!user_row) {
            cout << "User not found." << endl;
            mysql_free_result(user_res);
            mysql_close(conn);
            return;
        }

        int user_id = atoi(user_row[0]);
        mysql_free_result(user_res);

        // Cek apakah ada peminjaman yang sesuai
        stringstream check_query;
        check_query << "SELECT id FROM peminjaman WHERE user_id = " << user_id << " AND comic_id = " << comic_id << " AND tanggal_pengembalian IS NULL";
        if (mysql_query(conn, check_query.str().c_str())) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_RES* check_res = mysql_store_result(conn);
        if (check_res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_ROW check_row = mysql_fetch_row(check_res);
        if (!check_row) {
            cout << "No borrowing record found for this comic." << endl;
            mysql_free_result(check_res);
            mysql_close(conn);
            return;
        }

        int peminjaman_id = atoi(check_row[0]);
        mysql_free_result(check_res);

        // Update stok komik
        stringstream update_query;
        update_query << "UPDATE komik SET stok = stok + 1 WHERE id = " << comic_id;
        if (mysql_query(conn, update_query.str().c_str())) {
            cerr << "UPDATE failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        // Catat pengembalian
        stringstream return_query;
        return_query << "INSERT INTO pengembalian (peminjaman_id, tanggal_pengembalian) VALUES ("
                    << peminjaman_id << ", CURDATE())";
        if (mysql_query(conn, return_query.str().c_str())) {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Comic successfully returned." << endl;
        }

        mysql_close(conn);
    }
}


void ensure_admin_exists() {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream check_query;
        check_query << "SELECT COUNT(*) FROM users WHERE username = 'admin' AND role = 'admin'";
        if (mysql_query(conn, check_query.str().c_str())) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_RES* res = mysql_store_result(conn);
        if (res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_ROW row = mysql_fetch_row(res);
        int count = atoi(row[0]);

        if (count == 0) {
            stringstream create_admin_query;
            create_admin_query << "INSERT INTO users (username, password, role) VALUES ('admin', 'admin', 'admin')";
            if (mysql_query(conn, create_admin_query.str().c_str())) {
                cerr << "INSERT failed: " << mysql_error(conn) << endl;
            } else {
                cout << "Admin user created." << endl;
            }
        }

        mysql_free_result(res);
        mysql_close(conn);
    }
}

int main() {
    ensure_admin_exists();

    while (true) {
        clear_screen();  // Membersihkan layar setiap kali menu ditampilkan
        cout << "\nWelcome to Perpustakaan System\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        int main_choice;
        cin >> main_choice;

        if (main_choice == 1) {
            string username, password, role = "user";
            cout << "Enter Username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Enter Password: ";
            getline(cin, password);
            // Role is always 'user' for registration
            create_user(username, password, role);
        } else if (main_choice == 2) {
            string username, password, role;
            cout << "Enter Username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Enter Password: ";
            getline(cin, password);
            if (login_user(username, password, role)) {
                clear_screen();  // Membersihkan layar setelah login
                if (role == "admin") {
                    cout << "Logged in as Admin.\n";
                    while (true) {
                        clear_screen();
                        cout << "\nAdmin Menu:\n";
                        cout << "1. Add Comic\n";
                        cout << "2. Show All Comics\n";
                        cout << "3. Update Comic\n";
                        cout << "4. Delete Comic\n";
                        cout << "5. Show Comics by Genre\n";
                        cout << "6. Log Out\n";
                        cout << "Enter choice: ";
                        int admin_choice;
                        cin >> admin_choice;

                        if (admin_choice == 1) {
                            clear_screen();
                            string judul, penulis, studio, genre;
                            int tahun_terbit, stok;
                            cout << "Enter Judul: ";
                            cin.ignore();
                            getline(cin, judul);
                            cout << "Enter Penulis: ";
                            getline(cin, penulis);
                            cout << "Enter Studio: ";
                            getline(cin, studio);
                            cout << "Enter Tahun Terbit: ";
                            cin >> tahun_terbit;
                            cout << "Enter Stok: ";
                            cin >> stok;
                            cout << "Enter Genre(s) (separate multiple genres with commas): ";
                            cin.ignore();
                            getline(cin, genre);
                            create_comic(judul, penulis, studio, tahun_terbit, stok, genre);
                        } else if (admin_choice == 2) {
                            clear_screen();
                            get_comics();
                        } else if (admin_choice == 3) {
                            clear_screen();
                            int comic_id;
                            cout << "Enter comic ID to update: ";
                            cin >> comic_id;
                            validate_input();
                            cin.ignore(); 
                            update_comic(comic_id);
                            press_enter_to_continue();
                        } else if (admin_choice == 4) {
                            clear_screen();
                            int comic_id;
                            cout << "Enter comic ID to delete: ";
                            cin >> comic_id;
                            delete_comic(comic_id);
                            press_enter_to_continue();  // Perbaikan: Menambahkan ; di sini
                        } else if (admin_choice == 5) {
                            clear_screen();
                            show_comics_by_genre();
                        } else if (admin_choice == 6) {
                            break;
                        } else {
                            cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                } else if (role == "user") {
                    cout << "Logged in as User.\n";
                    while (true) {
                        clear_screen();
                        cout << "\nUser Menu:\n";
                        cout << "1. Show All Comics\n";
                        cout << "2. Show Comics by Genre\n";
                        cout << "3. Borrow Comic\n";
                        cout << "4. Return Comic\n";
                        cout << "5. Log Out\n";
                        cout << "Enter choice: ";
                        int user_choice;
                        cin >> user_choice;

                        if (user_choice == 1) {
                            clear_screen();
                            get_comics();
                        } else if (user_choice == 2) {
                            clear_screen();
                            show_comics_by_genre();
                        } else if (user_choice == 3) {
                            clear_screen();
                            borrow_comic(username);
                            press_enter_to_continue();  // Perbaikan: Menambahkan ; di sini
                        } else if(user_choice == 4) {
                            clear_screen();
                            return_comic(username);
                            press_enter_to_continue();
                        } else if (user_choice == 5) {
                            break;
                        } else {
                            cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                } else {
                    cout << "Invalid role." << endl;
                }
            } else {
                cout << "Login failed. Check your username and password." << endl;
            }
        } else if (main_choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}