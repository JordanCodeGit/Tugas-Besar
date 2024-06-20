//Tugas Besar Struktur Data Algorithma
//Cflix program streaming platform menggunakan c++
// Anggota:
// - Sinta Sarwo (2311102132)
// - Jordan Angkawijaya (2311102139)
// - Mahija Danadyaksa Sadtomo (2311102157)

// Isi program menggunakan:
// - Pengulangan
// - Percabangan
// - Fungsi
// - Searching
// - Array
// - Linked List
// - Tipe Data


#include <iostream> // Library untuk fungsi input dan output
#include <string>   // Library untuk operasi pada string

using namespace std;

// Deklarasi variabel untuk operasi-operasi dalam sistem
string Username, Password;
int SearchChoice;
const int MaxMovies = 100; // Konstanta untuk jumlah maksimal film

// Struktur data untuk menyimpan informasi film
struct Movie 
{
    string title; // Judul film
    int year; // Tahun rilis film
    string genre; // Genre film
    string link; // Link ke film
};

// Struktur data untuk menyimpan informasi akun pengguna
struct Account 
{
    string Username; // Nama pengguna
    string Password; // Kata sandi
    bool Admin; // Status apakah akun adalah admin
};

// Deklarasi array untuk menyimpan daftar film
Movie movies[MaxMovies];
int NumMovies = 0; // Jumlah film yang ada

// Deklarasi array untuk menyimpan daftar akun
Account accounts[] = 
{
    {"admin", "admin123", true}, // Akun admin
    {"user", "user123", false} // Akun user
};

int NumAccounts = 2; // Jumlah akun yang ada

bool Authenticated; // Status apakah pengguna sudah terautentikasi
Account CurrentAccount; // Akun pengguna yang sedang login

// Struktur data linked list untuk menyimpan film top minggu ini
struct TopMovieNode 
{
    Movie movie; // Film
    TopMovieNode *next; // Pointer ke node berikutnya
};

TopMovieNode *head = nullptr; // Pointer ke awal linked list

// Fungsi untuk melakukan login
bool Login() 
{
    cout << "=============== CFlix - Login Page ================" << endl;
    cout << "\nUsername: ";
    cin >> Username;
    cout << "Password: ";
    cin >> Password;

    for (int i = 0; i < NumAccounts; ++i) // Perulangan untuk memeriksa akun yang ada
    {
        if (Username == accounts[i].Username && Password == accounts[i].Password) // Jika username dan password cocok
        {
            Authenticated = true; // Set status terautentikasi
            CurrentAccount = accounts[i]; // Set akun pengguna saat ini
            return true;
        }
    }

    cout << "\nSomething is wrong.. are you trying to hack us? Welp, goodbye." << endl;
    cout << "\n===================================================" << endl;
    return false;
}

// Fungsi untuk menampilkan semua film
void DisplayAllMovies() 
{
    cout << "\n================= CFlix Movie List ================" << endl;
    for (int i = 0; i < NumMovies; ++i) // Perulangan untuk menampilkan film satu per satu
    {
        cout << "\n• Title: " << movies[i].title << "\n• Year: " << movies[i].year << "\n• Genre: "
             << movies[i].genre << "\n• Link: " << movies[i].link << endl;
    }
    cout << "\n===================================================" << endl;
}

// Fungsi untuk mencari film berdasarkan judul
void SearchMovieTitle() 
{
    string SearchTitle;

    cout << "\nEnter the title to search: ";
    cin.ignore();
    getline(cin, SearchTitle);

    cout << "\n============== Search Results by Title =============" << endl;
    bool Found = false;
    for (int i = 0; i < NumMovies; ++i) // Perulangan untuk mencari film berdasarkan judul
    {
        if (movies[i].title.find(SearchTitle) != string::npos) // Jika judul ditemukan
        {
            cout << "\n• Title: " << movies[i].title << "\n• Year: " << movies[i].year << "\n• Genre: "
                 << movies[i].genre << "\n• Link: " << movies[i].link << endl;
            Found = true;
        }
    }

    if (!Found) // Jika film tidak ditemukan
    {
        cout << "\nNope, nothing, sorry" << endl;
    }
    cout << "\n===================================================" << endl;
}

// Fungsi untuk mencari film berdasarkan genre
void SearchMovieGenre() 
{
    string SearchGenre;

    cout << "\nEnter the genre to search: ";
    cin.ignore();
    getline(cin, SearchGenre);

    cout << "\n============== Search Results by Genre =============" << endl;
    bool Found = false;

    for (int i = 0; i < NumMovies; ++i) // Perulangan untuk mencari film berdasarkan genre
    {
        if (movies[i].genre.find(SearchGenre) != string::npos) // Jika genre ditemukan
        {
            cout << "\n• Title: " << movies[i].title << "\n• Year: " << movies[i].year << "\n• Genre: " << movies[i].genre << "\n• Link: " << movies[i].link << endl;
            Found = true;
        }
    }

    if (!Found) // Jika film tidak ditemukan
    {
        cout << "\nNope, nowhere to be found" << endl;
    }
    cout << "\n===================================================" << endl;
}

// Fungsi untuk mencari film (pilihan antara judul atau genre)
void SearchMovie() 
{
    cout << "\n=================== Search Movie =================== (Caps Sensitive)" << endl;
    cout << "\n1. Search by Title";
    cout << "\n2. Search by Genre";
    cout << "\nEnter your choice: ";
    cin >> SearchChoice;

    switch (SearchChoice) // Percabangan berdasarkan pilihan pencarian
    {
    case 1:
        SearchMovieTitle();
        break;
    case 2:
        SearchMovieGenre();
        break;
    default:
        cout << "\nWhat did you type??" << endl;
    }
}

// Fungsi untuk menambahkan film baru
void AddMovie() 
{
    cout << "\n================= Add a New Movie =================" << endl;
    Movie NewMovie;

    cout << "Movie Title: ";
    cin.ignore();
    getline(cin, NewMovie.title);

    cout << "Movie Release Year: ";
    cin >> NewMovie.year;
    cin.ignore();

    cout << "Movie Genre: ";
    getline(cin, NewMovie.genre);

    cout << "Movie Link: ";
    getline(cin, NewMovie.link);

    if (NumMovies < MaxMovies) // Jika jumlah film belum mencapai maksimal
    {
        movies[NumMovies++] = NewMovie; // Tambah film baru ke array
        cout << "\nMovie added! Great!" << endl;
    }
    else
    {
        cout << "\nYou wanna add more than 100 movies? At least change the const at line 8 first :(" << endl;
    }

    cout << "\n===================================================" << endl;
}

// Fungsi untuk mengedit film yang ada
void EditMovie() 
{
    string EditTitle;

    cout << "\n=================== Edit Movie ====================" << endl;
    cout << "\nAny changes? Type the title of the movie to edit: ";
    cin.ignore();
    getline(cin, EditTitle);

    bool Found = false;
    for (int i = 0; i < NumMovies; ++i) // Perulangan untuk mencari film yang akan diedit
    {
        if (movies[i].title == EditTitle) // Jika film ditemukan
        {
            cout << "NEW Title: ";
            getline(cin, movies[i].title);
            cout << "NEW Release Year: ";
            cin >> movies[i].year;
            cin.ignore();
            cout << "NEW Genre: ";
            getline(cin, movies[i].genre);
            cout << "NEW Link: ";
            getline(cin, movies[i].link);

            Found = true;
            cout << "\nMovie edited! Nice! " << endl;
            break;
        }
    }

    if (!Found) // Jika film tidak ditemukan
    {
        cout << "\n===================================================" << endl;
        cout << "\nEditing a movie requires the movie to be IN the list, fyi." << endl;
        cout << "\n===================================================" << endl;
    }

    cout << "\n===================================================" << endl;
}

// Fungsi untuk menghapus film yang ada
void DeleteMovie() 
{
    string DeleteTitle;

    cout << "\n=================== Delete Movie ===================" << endl;
    cout << "\nAww, enter the title of the movie to be DELETED: ";
    cin.ignore();
    getline(cin, DeleteTitle);

    for (int i = 0; i < NumMovies; ++i) // Perulangan untuk mencari film yang akan dihapus
    {
        if (movies[i].title == DeleteTitle) // Jika film ditemukan
        {
            for (int j = i; j < NumMovies - 1; ++j) // Perulangan untuk menggeser film yang tersisa
            {
                movies[j] = movies[j + 1];
            }
            NumMovies--; // Kurangi jumlah film
            cout << "\nMovie deleted! Yay?" << endl;
            return;
        }
    }

    cout << "\nHuh, deleting a movie that doesn't exist? Wow." << endl;
    cout << "\n===================================================" << endl;
}

// Fungsi untuk memasukkan film ke depan linked list
void InsertFront(const Movie &newMovie) 
{
    TopMovieNode *newNode = new TopMovieNode{newMovie, head};
    head = newNode;
    cout << "\nMovie inserted at the front!" << endl;
}

// Fungsi untuk memasukkan film ke tengah linked list
void InsertMiddle(const Movie &newMovie, int position)
{
    if (position <= 1)
    {
        InsertFront(newMovie); // Memanggil fungsi InsertFront jika posisi <= 1
        return;
    }

    TopMovieNode *current = head;
    for (int i = 1; i < position - 1 && current != nullptr; ++i)
    {
        current = current->next; // Iterasi mencari node sebelum posisi yang diminta
    }

    if (current == nullptr)
    {
        cout << "\nInvalid position!" << endl; // Pesan jika posisi tidak valid
        return;
    }

    TopMovieNode *newNode = new TopMovieNode{newMovie, current->next}; // Membuat node baru dengan data film baru
    current->next = newNode; // Menyambungkan node sebelumnya dengan node baru
    cout << "\nMovie inserted in the middle!" << endl; // Pesan konfirmasi setelah penyisipan
}

void InsertBack(const Movie &newMovie)
{
    TopMovieNode *newNode = new TopMovieNode{newMovie, nullptr}; // Membuat node baru dengan next nullptr

    if (head == nullptr)
    {
        head = newNode; // Jika linked list kosong, node baru menjadi head
    }
    else
    {
        TopMovieNode *current = head;
        while (current->next != nullptr)
        {
            current = current->next; // Iterasi mencari node terakhir dalam linked list
        }
        current->next = newNode; // Menyambungkan node terakhir dengan node baru
    }

    cout << "\nMovie inserted at the back!" << endl; // Pesan konfirmasi setelah penyisipan
}

void EditMiddle(int position)
{
    if (head == nullptr)
    {
        cout << "\nList is empty!" << endl; // Pesan jika linked list kosong
        return;
    }

    TopMovieNode *current = head;
    for (int i = 1; i < position && current != nullptr; ++i)
    {
        current = current->next; // Iterasi mencari node pada posisi yang diminta
    }

    if (current == nullptr)
    {
        cout << "\nInvalid position!" << endl; // Pesan jika posisi tidak valid
        return;
    }

    cout << "Editing the movie at position " << position << ":" << endl; // Pesan konfirmasi bahwa sedang mengedit film
    cout << "NEW Title: ";
    cin.ignore();
    getline(cin, current->movie.title); // Meminta dan mengupdate judul film
    cout << "NEW Release Year: ";
    cin >> current->movie.year; // Meminta dan mengupdate tahun rilis film
    cin.ignore();
    cout << "NEW Genre: ";
    getline(cin, current->movie.genre); // Meminta dan mengupdate genre film
    cout << "NEW Link: ";
    getline(cin, current->movie.link); // Meminta dan mengupdate link film

    cout << "\nMovie at position " << position << " edited!" << endl; // Pesan konfirmasi setelah pengeditan
}

void DeleteTopMovie(int position)
{
    if (head == nullptr) // Jika linked list kosong
    {
        cout << "\nList is empty!" << endl; // Pesan bahwa linked list kosong
        return; // Keluar dari fungsi
    }
    
    if (position == 1) // Jika posisi adalah 1, hapus node pertama
    {
        TopMovieNode *deleteNode = head;
        head = head->next; // Mengubah head ke node selanjutnya
        delete deleteNode; // Menghapus node pertama
        cout << "\nMovie at position " << position << " deleted!" << endl; // Pesan konfirmasi setelah penghapusan
        return; // Keluar dari fungsi setelah penghapusan
    }

    TopMovieNode *temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; ++i) // Iterasi mencari node sebelum posisi yang diminta
    {
        temp = temp->next; // Berpindah ke node selanjutnya dalam linked list
    }
    if (temp == nullptr || temp->next == nullptr) // Jika posisi tidak valid
    {
        cout << "\nInvalid position!" << endl; // Pesan kesalahan posisi
        return; // Keluar dari fungsi
    }

    TopMovieNode *deleteNode = temp->next; // Menghapus node yang diinginkan
    temp->next = deleteNode->next; // Menghubungkan node sebelumnya dengan node setelahnya
    delete deleteNode; // Menghapus node yang diinginkan
    cout << "\nMovie at position " << position << " deleted!" << endl; // Pesan konfirmasi setelah penghapusan
}

void ClearList()
{
    while (head != nullptr) // Iterasi untuk menghapus semua node dalam linked list
    {
        TopMovieNode *temp = head;
        head = head->next; // Berpindah ke node selanjutnya dalam linked list
        delete temp; // Menghapus node saat ini
    }
    cout << "\nAll movies cleared from the list!" << endl; // Pesan konfirmasi setelah penghapusan semua node
}

void DisplayTopMovies()
{
    cout << "\n================= Top Movies This Week ================" << endl; // Header untuk menampilkan film teratas minggu ini
    TopMovieNode *current = head;
    int ranking = 1;
    while (current != nullptr) // Iterasi untuk menampilkan setiap film dalam linked list
    {
        cout << ranking << "• Title: " << current->movie.title << "\n • Year: " << current->movie.year << "\n • Genre: "
             << current->movie.genre << "\n • Link: " << current->movie.link << endl; // Menampilkan detail film
        cout << endl;
        current = current->next; // Berpindah ke node selanjutnya dalam linked list
        ranking++; // Menaikkan peringkat untuk film selanjutnya
    }
    cout << "\n=======================================================" << endl; // Footer setelah selesai menampilkan semua film
}

void ManageTopMovies()
{
    int choice, position;
    Movie newMovie;

    do
    {
        cout << "\n=============== Manage Top Movies This Week ===============" << endl; // Header menu untuk mengelola film teratas minggu ini
        cout << "\n1. Insert Front"; // Pilihan untuk menyisipkan di depan
        cout << "\n2. Insert Middle"; // Pilihan untuk menyisipkan di tengah
        cout << "\n3. Insert Back"; // Pilihan untuk menyisipkan di belakang
        cout << "\n4. Edit Middle"; // Pilihan untuk mengedit film di tengah
        cout << "\n5. Delete Top Movies This Weekend"; // Pilihan untuk menghapus film teratas minggu ini
        cout << "\n6. Clear List Movies"; // Pilihan untuk menghapus semua film dalam linked list
        cout << "\n7. Display Top Movies This Weekend"; // Pilihan untuk menampilkan film teratas minggu ini
        cout << "\n8. Exit"; // Pilihan untuk keluar dari menu
        cout << "\n\nEnter your choice: ";
        cin >> choice; // Meminta pengguna memasukkan pilihan menu

        switch (choice) // Percabangan berdasarkan pilihan menu
        {
        case 1:
            cout << "\nEnter movie details to insert at the front:" << endl; // Meminta detail film yang akan disisipkan di depan
            cout << "Title: ";
            cin.ignore();
            getline(cin, newMovie.title); // Meminta dan menyimpan judul film
            cout << "Year: ";
            cin >> newMovie.year; // Meminta dan menyimpan tahun rilis film
            cin.ignore();
            cout << "Genre: ";
            getline(cin, newMovie.genre); // Meminta dan menyimpan genre film
            cout << "Link: ";
            getline(cin, newMovie.link); // Meminta dan menyimpan link film
            InsertFront(newMovie); // Memanggil fungsi untuk menyisipkan film di depan
            break;
        case 2:
            cout << "\nEnter position to insert in the middle: ";
            cin >> position; // Meminta posisi di tengah yang diminta pengguna
            cout << "\nEnter movie details to insert in the middle:" << endl; // Meminta detail film yang akan disisipkan di tengah
            cout << "Title: ";
            cin.ignore();
            getline(cin, newMovie.title); // Meminta dan menyimpan judul film
            cout << "Year: ";
            cin >> newMovie.year; // Meminta dan menyimpan tahun rilis film
            cin.ignore();
            cout << "Genre: ";
            getline(cin, newMovie.genre); // Meminta dan menyimpan genre film
            cout << "Link: ";
            getline(cin, newMovie.link); // Meminta dan menyimpan link film
            InsertMiddle(newMovie, position); // Memanggil fungsi untuk menyisipkan film di tengah
            break;
        case 3:
            cout << "\nEnter movie details to insert at the back:" << endl; // Meminta detail film yang akan disisipkan di belakang
            cout << "Title: ";
            cin.ignore();
            getline(cin, newMovie.title); // Meminta dan menyimpan judul film
            cout << "Year: ";
            cin >> newMovie.year; // Meminta dan menyimpan tahun rilis film
            cin.ignore();
            cout << "Genre: ";
            getline(cin, newMovie.genre); // Meminta dan menyimpan genre film
            cout << "Link: ";
            getline(cin, newMovie.link); // Meminta dan menyimpan link film
            InsertBack(newMovie); // Memanggil fungsi untuk menyisipkan film di belakang
            break;
        case 4:
            cout << "\nEnter position to edit in the middle: ";
            cin >> position; // Meminta posisi di tengah yang diminta pengguna untuk diedit
            EditMiddle(position); // Memanggil fungsi untuk mengedit film di tengah
            break;
        case 5:
            cout << "\nEnter position to delete top movie:";
            cin >> position; // Meminta posisi film teratas minggu ini yang akan dihapus
            DeleteTopMovie(position); // Memanggil fungsi untuk menghapus film teratas minggu ini
            break;
        case 6:
            ClearList(); // Memanggil fungsi untuk menghapus semua film dalam linked list
            break;
        case 7:
            DisplayTopMovies(); // Memanggil fungsi untuk menampilkan film teratas minggu ini
            break;
        case 8:
            return; // Keluar dari menu pengelolaan film teratas minggu ini
        default:
            cout << "\nInvalid choice! Please try again." << endl; // Pesan jika pilihan menu tidak valid
        }
    } while (true); // Melakukan loop menu pengelolaan film teratas minggu ini
}

int main()
{ // Array
    movies[NumMovies++] = {"Oppenheimer", 2023, "Documentary, History, Drama", "https://tv6.lk21official.wiki/oppenheimer-2023/"};
    movies[NumMovies++] = {"Doctor Strange in the Multiverse of Madness", 2022, "Marvel, Fantasy, Horror", "https://ww4.fmovies.co/film/doctor-strange-in-the-multiverse-of-madness-1630853347/"};
    movies[NumMovies++] = {"Guardians of the Galaxy Vol. 3", 2023, "Marvel, Action, Comedy", "https://ww4.fmovies.co/film/guardians-of-the-galaxy-vol-3-1630855140/"};
    movies[NumMovies++] = {"Barbie", 2023, "Adventure, Comedy, Fantasy", "https://ww4.fmovies.co/film/barbie-1630855502/"};
    movies[NumMovies++] = {"Miracle in Cell No. 7", 2022, "Drama, Comedy", "https://tv6.lk21official.wiki/miracle-in-cell-no-7-2019/"};
    movies[NumMovies++] = {"Hereditary", 2018, "Drama, Mystery, Horror", "https://ww4.fmovies.co/film/hereditary-25351/"};
    movies[NumMovies++] = {"Evil Dead Rise", 2023, "Horror", "https://ww4.fmovies.co/film/evil-dead-rise-1630855095/"};
    movies[NumMovies++] = {"Sonic The Hedgehog 2", 2022, "Animation, Action, Adventure", "https://ww4.fmovies.co/film/sonic-the-hedgehog-2-1630853162/"};
    movies[NumMovies++] = {"Avatar: The Way of Water", 2022, "Sci-fi, Action, Fantasy", "https://ww4.fmovies.co/film/avatar-the-way-of-water-1630854576/"};
    movies[NumMovies++] = {"The Conjuring 3", 2021, "Horror, Thriller, Mystery", "https://ww4.fmovies.co/film/the-conjuring-the-devil-made-me-do-it-1621869065/"};

    do // Perulangan
    {
        if (!Authenticated) // Percabangan aksa
        {
            if (!Login())
            {
                break;
            }
        }

        if (CurrentAccount.Admin) // Percabangan Sinta
        {
            cout << "\n========== CFlix Movie Streaming - ADMIN ==========" << endl;
            cout << "\n1. Display All Movies";
            cout << "\n2. Search Movie";
            cout << "\n3. Add a New Movie";
            cout << "\n4. Edit Movie";
            cout << "\n5. Delete Movie";
            cout << "\n6. Manage Top Movies This Week";
            cout << "\n7. Logout";
            cout << "\n8. Exit";
            cout << "\n\nEnter your choice: ";
        }
        else
        {
            cout << "\n========== CFlix Movie Streaming - USER ===========" << endl;
            cout << "\n1. Display All Movies";
            cout << "\n2. Search Movie";
            cout << "\n3. Display Top Movies This Week";
            cout << "\n4. Logout";
            cout << "\n5. Exit";
            cout << "\n\nEnter your choice: ";
        }

        int Choice;
        cin >> Choice;

        switch (Choice) // Percabangan Aksa
        {
        case 1:
            DisplayAllMovies();
            break;
        case 2:
            SearchMovie();
            break;
        case 3:
            if (CurrentAccount.Admin)
            {
                AddMovie();
                break;
            }
            else
            {
                DisplayTopMovies();
            }
            break;
        case 4:
            if (CurrentAccount.Admin)
            {
                EditMovie();
                break;
            }
            else
            {
                Authenticated = false;
                cout << "\n===================================================" << endl;
                cout << "\nLogged out, goodbye!" << endl;
                cout << "\n===================================================" << endl;
            }
            break;
        case 5:
            if (CurrentAccount.Admin)
            {
                DeleteMovie();
                break;
            }
            else
            {
                cout << "\n===================================================" << endl;
                cout << "\nGoodbye forever! Thank you for using CFlix!" << endl;
                cout << "\n===================================================" << endl;
                return 0;
            }
        case 6:
            if (CurrentAccount.Admin)
            {
                ManageTopMovies();
                break;
            }
        case 7:
            Authenticated = false;
            cout << "\n===================================================" << endl;
            cout << "\nLogged out, goodbye!" << endl;
            cout << "\n===================================================" << endl;
            break;
        case 8:
            cout << "\n===================================================" << endl;
            cout << "\nGoodbye forever! Thank you for using CFlix!" << endl;
            cout << "\n===================================================" << endl;
            return 0;
        default:
            cout << "\n..What did you just input??" << endl;
        }

    } while (true);

    return 0;
}