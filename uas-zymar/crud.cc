#include <iostream>
#include <mysql/mysql.h>
#include <sstream>
#include <cstring>

using namespace std;

const char* hostname = "127.0.0.1";
const char* user = "root";
const char* pass = "123";
const char* dbname = "perpus";
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

void create_book(const string& judul, const string& pengarang, const string& penerbit, int tahun_terbit) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "INSERT INTO buku (judul, pengarang, penerbit, tahun_terbit) VALUES ('" << judul << "', '" << pengarang << "', '" << penerbit << "', " << tahun_terbit << ")";
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Book successfully added." << endl;
        }
        mysql_close(conn);
    }
}

void get_all_books() {
    MYSQL* conn = connect_db();
    if (conn) {
        if (mysql_query(conn, "SELECT * FROM buku")) {
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

        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            cout << "ID: " << row[0] << ", Judul: " << row[1] << ", Pengarang: " << row[2] << ", Penerbit: " << row[3] << ", Tahun Terbit: " << row[4] << endl;
        }

        mysql_free_result(res);
        mysql_close(conn);
    }
}

void update_book(int book_id, const string& judul, const string& pengarang, const string& penerbit, int tahun_terbit) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "UPDATE buku SET judul = '" << judul << "', pengarang = '" << pengarang << "', penerbit = '" << penerbit << "', tahun_terbit = " << tahun_terbit << " WHERE id = " << book_id;
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "UPDATE failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Book successfully updated." << endl;
        }
        mysql_close(conn);
    }
}

void delete_book(int book_id) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "DELETE FROM buku WHERE id = " << book_id;
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "DELETE failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Book successfully deleted." << endl;
        }
        mysql_close(conn);
    }
}

bool register_user(const string& username, const string& password, bool isAdmin) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        // Konversi nilai isAdmin menjadi string 'true' atau 'false'
        string isAdminStr = isAdmin ? "true" : "false";
        query << "INSERT INTO users (username, password, is_admin) VALUES ('" << username << "', '" << password << "', '" << isAdminStr << "')";
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return false;
        } else {
            cout << "User registered successfully." << endl;
            mysql_close(conn);
            return true;
        }
    }
    return false;
}


bool login_user(const string& username, const string& password, bool& isAdmin) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "SELECT * FROM users WHERE username = '" << username << "' AND password = '" << password << "'";
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return false;
        } else {
            MYSQL_RES* res = mysql_store_result(conn);
            if (res == nullptr) {
                cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
                mysql_close(conn);
                return false;
            }

            int num_rows = mysql_num_rows(res);
            if (num_rows == 1) {
                MYSQL_ROW row = mysql_fetch_row(res);
                isAdmin = (strcmp(row[3], "true") == 0); // Periksa apakah pengguna adalah admin atau bukan
                mysql_free_result(res);
                mysql_close(conn);
                return true;
            } else {
                cout << "Login failed. Username or password incorrect." << endl;
                mysql_free_result(res);
                mysql_close(conn);
                return false;
            }
        }
    }
    return false;
}

int main() {
    int choice;
    bool isAdmin = false;
    string username, password;

    // Login or Register
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (!login_user(username, password, isAdmin)) {
            return 1; // Exit if login fails
        }
    } else if (choice == 2) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (!register_user(username, password, false)) { // Register as regular user
            return 1; // Exit if registration fails
        }
        isAdmin = false;
    } else {
        cout << "Invalid choice. Exiting program." << endl;
        return 1; // Exit if invalid choice
    }

    // Menu utama setelah login
    while (true) {
        cout << "\nMenu:\n";
        if (isAdmin) {
            cout << "1. Add Book\n";
            cout << "2. Show All Books\n";
            cout << "3. Update Book\n";
            cout << "4. Delete Book\n";
        } else {
            cout << "1. Show All Books\n";
        }
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (isAdmin) {
            if (choice == 1) {
                string judul, pengarang, penerbit;
                int tahun_terbit;
                cout << "Enter judul: ";
                cin.ignore();
                getline(cin, judul);
                cout << "Enter pengarang: ";
                getline(cin, pengarang);
                cout << "Enter penerbit: ";
                getline(cin, penerbit);
                cout << "Enter tahun terbit: ";
                cin >> tahun_terbit;
                create_book(judul, pengarang, penerbit, tahun_terbit);
            } else if (choice == 2) {
                get_all_books();
            } else if (choice == 3) {
                // Add update function here
            } else if (choice == 4) {
                // Add delete function here
            }
        } else {
            if (choice == 1) {
                get_all_books();
            }
        }

        if (choice == 5) {
            break;
        }
    }

    return 0;
}
