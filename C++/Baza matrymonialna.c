#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct User {
    string name;
    string surname;
    string gender;
    int age;
    vector<string> interests;
};

vector<User> users;

void printAllUsers() {
    for (int i = 0; i < users.size(); i++) {
        std::cout <<"indeks: " <<i<< std::endl;
        cout << "Imie: " << users[i].name << endl;
        cout << "Naziwsko: " << users[i].surname << endl;
        cout << "Plec: " << users[i].gender << endl;
        cout << "Wiek: " << users[i].age << endl;
        cout << "Zainteresowania: ";
        for (int j = 0; j < users[i].interests.size(); j++) {
            cout << users[i].interests[j] << " ";
        }
        cout << endl;
    }
}

void printUser(int index) {
    if (index >= users.size() || index < 0) {
        cout << "Uzytkownik nie znalezony " << endl;
        return;
    }

    cout << "Imie: " << users[index].name << endl;
    cout << "Nazwisko: " << users[index].surname << endl;
    cout << "Plec: " << users[index].gender << endl;
    cout << "Wiek: " << users[index].age << endl;
    cout << "Zainteresowania: ";
    for (int j = 0; j < users[index].interests.size(); j++) {
        cout << users[index].interests[j] << " ";
    }
    cout << endl;
}

void matchUsers() {
    for (int first = 0;
         first < users.size(); first++) {
        for (int next = first + 1; next < users.size(); next++) {
            bool If = false;
            for (string firstinter: users[first].interests) {
                for (string nextinter: users[next].interests) {
                    if (firstinter == nextinter) {
                        If = true;
                        cout << "Match: " << users[first].name << " "
                             << users[first].surname << " and " << users[next].name
                             << " " << users[next].surname << endl;
                    }

                    if (If) {
                        break;
                    }
                }

                if (If) {
                    break;
                }
            }
        }
    }
};

User createUser() {
    User user;
    cout << "Podaj imie: ";
    cin >> user.name;
    cout << endl;
    cout << "Nazwisko: ";
    cin >> user.surname;
    cout << endl;
    cout << "Plec: ";
    cin >> user.gender;
    cout << endl;
    cout << "Wiek: ";
    cin >> user.age;

    cout << "Zainteresowania: ";
    string interest;
    while (cin >> interest) {
        if (interest == "end") {
            break;
        }
        user.interests.push_back(interest);
        cout << "Zainteresowania: ";
    }

    cout << endl;

    return user;
}

void saveUsersToFile(string fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Blad otwierania pliku : " << fileName << endl;
        return;
    }

    for (int i = 0; i < users.size(); i++) {
        file << users[i].name << " " << users[i].surname << " " << users[i].gender << " " << users[i].age;

        for (int j = 0; j < users[i].interests.size(); j++) {
            file << " " << users[i].interests[j];
        }
        file << endl;
    }
}

void loadUsersFromFile(string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Blad otwierania pliku: " << fileName << endl;
        return;
    }
    string line;

    vector<User> usersFromFile;

    while(getline(file, line)) {
        istringstream iss(line);
        string name;
        string surname;
        string gender;
        int age;
        vector <string> interests;
        iss >> name;
        iss >> surname;
        iss >> gender;
        iss >> age;
        string interest;
        while (iss >> interest) {
            interests.push_back(interest);
        }
        User user;
        user.name = name;
        user.surname = surname;
        user.gender = gender;
        user.age = age;
        user.interests = interests;

        usersFromFile.push_back(user);
    }

    users = usersFromFile;
}

int main() {
//    User user;
//    user.name = "Jan";
//    user.surname = "Kowalski";
//    user.gender = "M";
//    user.age = 20;
//    user.interests.push_back("sport");
//    user.interests.push_back("muzyka");
//    users.push_back(user);
//
//    saveUsersToFile("users.txt");
//    loadUsersFromFile("users.txt");
//
//    printAllUsers();

    cout << "******************" << endl;
    cout << "Witaj w aplikacji" << endl;
    cout << "******************" << endl;
    while(true) {
        cout << "1. Dodaj uzytkownika" << endl;
        cout << "2. Wyswietl uzytkownikow" << endl;
        cout << "3. Wyswietl uzytkownika" << endl;
        cout << "4. Znajdz pasujace uzytkownikow" << endl;
        cout << "5. Zapisz uzytkownikow do pliku" << endl;
        cout << "6. Wczytaj uzytkownikow z pliku" << endl;
        cout << "7. Wyjdz z aplikacji" << endl;

        int choice;
        cin >> choice;
        string fileNameToSave;
        string fileNameToLoad;

        switch (choice) {
            case 1:
                users.push_back(createUser());
                break;
            case 2:
                printAllUsers();
                break;
            case 3:
                cout << "Podaj indeks uzytkownika: ";
                int index;
                cin >> index;
                printUser(index);
                break;
            case 4:
                matchUsers();
                break;
            case 5:
                cout << "Podaj nazwe pliku do zapisywania: ";
                cin >> fileNameToSave;
                saveUsersToFile(fileNameToSave);
                break;
            case 6:
                cout << "Podaj nazwe pliku do wczytywania: ";
                cin >> fileNameToLoad;
                loadUsersFromFile(fileNameToLoad);
                break;
            case 7:
                return 0;
        }
    }
}
