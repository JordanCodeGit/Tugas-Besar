#include <iostream>
#include <string>

using namespace std;

string Username, Password;
int SearchChoice;
const int MaxMovies = 100;

struct Movie // Aksa
{
    string title;
    int year;
    string genre;
    string link;
};

struct Account // Sinta
{
    string Username;
    string Password;
    bool Admin;
};

Movie movies[MaxMovies];
int NumMovies = 0;

// Array Jong
Account accounts[] =
{
    {"admin", "admin123", true},
    {"user", "user123", false}
};

int NumAccounts = 2;

bool Authenticated;
Account CurrentAccount;

// Linked list structure for Top Movies This Week
struct TopMovieNode {
    Movie movie;
    TopMovieNode* next;
};

TopMovieNode* head = nullptr;

// Fungsi Sinta
bool Login()
{
    cout << "=============== CFlix - Login Page ================" << endl;
    cout << "\nUsername: "; cin >> Username;
    cout << "Password: "; cin >> Password;

    for (int i=0; i<NumAccounts; ++i) // Perulangan Jong
    {
        if (Username == accounts[i].Username && Password == accounts[i].Password) // Percabangan
        {
            Authenticated = true;
            CurrentAccount = accounts[i];
            return true;
        }
    }

    cout << "\nSomething is wrong.. are you trying to hack us? Welp, goodbye." << endl;
    cout << "\n===================================================" << endl;
    return false;
}

// Prosedur Sinta
void DisplayAllMovies()
{
    cout << "\n================= CFlix Movie List ================" << endl;
    for (int i = 0; i<NumMovies; ++i) // Perulangan Jong
    {
        cout << "\n• Title: " << movies[i].title << "\n• Year: " << movies[i].year << "\n• Genre: "
        << movies[i].genre << "\n• Link: " << movies[i].link << endl;
    }
    cout << "\n===================================================" << endl;
}

// Prosedur Jong
void SearchMovieTitle()
{
    string SearchTitle;

    cout << "\nEnter the title to search: "; cin.ignore();
    getline(cin, SearchTitle);

    cout << "\n============== Search Results by Title =============" << endl;
    bool Found = false;
    for (int i = 0; i<NumMovies; ++i) // Perulangan
    {
    if (movies[i].title.find(SearchTitle) != string::npos) // Percabangan
        {
        cout << "\n• Title: " << movies[i].title << "\n• Year: " << movies[i].year << "\n• Genre: "
        << movies[i].genre << "\n• Link: " << movies[i].link << endl;
        Found = true;
        }
    }

    if (!Found) // Percabangan
    {
        cout << "\nNope, nothing, sorry" << endl;
    }
    cout << "\n===================================================" << endl;
}

// Prosedur JOng
void SearchMovieGenre()
{
    string SearchGenre;

    cout << "\nEnter the genre to search: "; cin.ignore();
    getline(cin, SearchGenre);

    cout << "\n============== Search Results by Genre =============" << endl;
    bool Found = false;

    for (int i = 0; i<NumMovies; ++i) // Perulangan Jong {
    if (movies[i].genre.find(SearchGenre) != string::npos) // Percabangan
    {
        cout << "\n• Title: " << movies[i].title << "\n• Year: " <<
        movies[i].year << "\n• Genre: " << movies[i].genre << "\n• Link: " << movies[i].link << endl;
        Found = true;
    }


    if (!Found)
    {
        cout << "\nNope, nowhere to be found" << endl;
    }
    cout << "\n===================================================" << endl;
}

// Prosedur Sinta
void SearchMovie()
{
    cout << "\n=================== Search Movie =================== (Caps Sensitive)" << endl;
    cout << "\n1. Search by Title";
    cout << "\n2. Search by Genre";
    cout << "\nEnter your choice: ";
    cin >> SearchChoice;

    switch (SearchChoice) // Percabangan Sinta
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

// Prosedur Sinta
void AddMovie()
{
    cout << "\n================= Add a New Movie =================" << endl;
    Movie NewMovie;

    cout << "Movie Title: "; cin.ignore();
    getline(cin, NewMovie.title);

    cout << "Movie Release Year: "; cin >> NewMovie.year;
    cin.ignore();

    cout << "Movie Genre: ";
    getline(cin, NewMovie.genre);

    cout << "Movie Link: ";
    getline(cin, NewMovie.link);

    if (NumMovies < MaxMovies) // Percabangan
    {
        movies[NumMovies++] = NewMovie;
        cout << "\nMovie added! Great!" << endl;
    } else {
        cout << "\nYou wanna add more than 100 movies? At least change the const at line 8 first :(" << endl;
    }

    cout << "\n===================================================" << endl;
}

// Prosedur Sinta
void EditMovie()
{
    string EditTitle;

    cout << "\n=================== Edit Movie ====================" << endl;
    cout << "\nAny changes? Type the title of the movie to edit: "; cin.ignore();
    getline(cin, EditTitle);

    bool Found = false;
    for (int i = 0; i<NumMovies; ++i) // Perulangan
    {
        if (movies[i].title == EditTitle) // Percabangan
        {
            cout << "NEW Title: "; getline(cin, movies[i].title);
            cout << "NEW Release Year: "; cin >> movies[i].year;
            cin.ignore();
            cout << "NEW Genre: "; getline(cin, movies[i].genre);
            cout << "NEW Link: "; getline(cin, movies[i].link);

            Found = true;
            cout << "\nMovie edited! Nice! " << endl;
            break;
        }
    }

    if (!Found) // Percabangan
    {
        cout << "\n===================================================" << endl;
        cout << "\nEditing a movie requires the movie to be IN the list, fyi." << endl;
        cout << "\n===================================================" << endl;
    }

    cout << "\n===================================================" << endl;
}

// Prosedur
void DeleteMovie()
{
    string DeleteTitle;

    cout << "\n=================== Delete Movie ===================" << endl;
    cout << "\nAww, enter the title of the movie to be DELETED: "; cin.ignore();
    getline(cin, DeleteTitle);

    for (int i=0; i<NumMovies; ++i) // Perulangan
    {
        if (movies[i].title == DeleteTitle) // Percabangan
        {
            for (int j=i; j<NumMovies-1; ++j) // Perulangan
            {
                movies[j] = movies[j+1];
            }
            NumMovies--;
            cout << "\nMovie deleted! Yay?" << endl;
            return;
        }
    }

    cout << "\nHuh, deleting a movie that doesn't exist? Wow." << endl;
    cout << "\n===================================================" << endl;
}

// Linked list functions for Top Movies This Week
void InsertFront(const Movie& newMovie) {
    TopMovieNode* newNode = new TopMovieNode{newMovie, head};
    head = newNode;
    cout << "\nMovie inserted at the front!" << endl;
}

void InsertMiddle(const Movie& newMovie, int position) {
    if (position <= 1) {
        InsertFront(newMovie);
        return;
    }

    TopMovieNode* current = head;
    for (int i = 1; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "\nInvalid position!" << endl;
        return;
    }

    TopMovieNode* newNode = new TopMovieNode{newMovie, current->next};
    current->next = newNode;
    cout << "\nMovie inserted in the middle!" << endl;
}

void InsertBack(const Movie& newMovie) {
    TopMovieNode* newNode = new TopMovieNode{newMovie, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        TopMovieNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << "\nMovie inserted at the back!" << endl;
}

void EditMiddle(int position) {
    if (head == nullptr) {
        cout << "\nList is empty!" << endl;
        return;
    }

    TopMovieNode* current = head;
    for (int i = 1; i < position && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "\nInvalid position!" << endl;
        return;
    }

    cout << "Editing the movie at position " << position << ":" << endl;
    cout << "NEW Title: "; cin.ignore();
    getline(cin, current->movie.title);
    cout << "NEW Release Year: "; cin >> current->movie.year;
    cin.ignore();
    cout << "NEW Genre: "; getline(cin, current->movie.genre);
    cout << "NEW Link: "; getline(cin, current->movie.link);

    cout << "\nMovie at position " << position << " edited!" << endl;
}

void DeleteFront() {
    if (head == nullptr) {
        cout << "\nList is empty!" << endl;
        return;
    }

    TopMovieNode* temp = head;
    head = head->next;
    delete temp;

    cout << "\nFront movie deleted!" << endl;
}

void DeleteMiddle(int position) {
    if (head == nullptr) {
        cout << "\nList is empty!" << endl;
        return;
    }

    if (position <= 1) {
        DeleteFront();
        return;
    }

    TopMovieNode* current = head;
    for (int i = 1; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "\nInvalid position!" << endl;
        return;
    }

    TopMovieNode* temp = current->next;
    current->next = current->next->next;
    delete temp;

    cout << "\nMiddle movie deleted!" << endl;
}

void DeleteBack() {
    if (head == nullptr) {
        cout << "\nList is empty!" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        TopMovieNode* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    cout << "\nBack movie deleted!" << endl;
}

void ClearList() {
    while (head != nullptr) {
        TopMovieNode* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "\nAll movies cleared from the list!" << endl;
}

void DisplayTopMovies() {
    cout << "\n================= Top Movies This Week ================" << endl;
    TopMovieNode* current = head;
    while (current != nullptr) {
        cout << "\n• Title: " << current->movie.title << "\n• Year: " << current->movie.year << "\n• Genre: "
        << current->movie.genre << "\n• Link: " << current->movie.link << endl;
        current = current->next;
    }
    cout << "\n=======================================================" << endl;
}

void ManageTopMovies() {
    int choice, position;
    Movie newMovie;

    do {
        cout << "\n=============== Manage Top Movies This Week ===============" << endl;
        cout << "\n1. Insert Front";
        cout << "\n2. Insert Middle";
        cout << "\n3. Insert Back";
        cout << "\n4. Edit Middle";
        cout << "\n5. Delete Front";
        cout << "\n6. Delete Middle";
        cout << "\n7. Delete Back";
        cout << "\n8. Clear List";
        cout << "\n9. Display Top Movies";
        cout << "\n10. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter movie details to insert at the front:" << endl;
                cout << "Title: "; cin.ignore(); getline(cin, newMovie.title);
                cout << "Year: "; cin >> newMovie.year; cin.ignore();
                cout << "Genre: "; getline(cin, newMovie.genre);
                cout << "Link: "; getline(cin, newMovie.link);
                InsertFront(newMovie);
                break;
            case 2:
                cout << "\nEnter position to insert in the middle: ";
                cin >> position;
                cout << "\nEnter movie details to insert in the middle:" << endl;
                cout << "Title: "; cin.ignore(); getline(cin, newMovie.title);
                cout << "Year: "; cin >> newMovie.year; cin.ignore();
                cout << "Genre: "; getline(cin, newMovie.genre);
                cout << "Link: "; getline(cin, newMovie.link);
                InsertMiddle(newMovie, position);
                break;
            case 3:
                cout << "\nEnter movie details to insert at the back:" << endl;
                cout << "Title: "; cin.ignore(); getline(cin, newMovie.title);
                cout << "Year: "; cin >> newMovie.year; cin.ignore();
                cout << "Genre: "; getline(cin, newMovie.genre);
                cout << "Link: "; getline(cin, newMovie.link);
                InsertBack(newMovie);
                break;
            case 4:
                cout << "\nEnter position to edit in the middle: ";
                cin >> position;
                EditMiddle(position);
                break;
            case 5:
                DeleteFront();
                break;
            case 6:
                cout << "\nEnter position to delete in the middle: ";
                cin >> position;
                DeleteMiddle(position);
                break;
            case 7:
                DeleteBack();
                break;
            case 8:
                ClearList();
                break;
            case 9:
                DisplayTopMovies();
                break;
            case 10:
                return;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (true);
}

int main()
{   // Array
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
                } else
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