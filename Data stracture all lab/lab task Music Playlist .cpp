#include <iostream>
#include <string>
using namespace std;

const int MAX_SONGS = 100;

class Song {
public:
    string name;
    string singer;
    double duration;
    int release_year;

    Song() : name(""), singer(""), duration(0), release_year(0) {}
    Song(string n, string s, double d, int r)
        : name(n), singer(s), duration(d), release_year(r) {}
};

void createPlaylist(Song playlist[], int& songCount) {
    playlist[songCount++] = Song("Song A", "Singer X", 3.5, 2020);
    playlist[songCount++] = Song("Song B", "Singer Y", 4.0, 2018);
    playlist[songCount++] = Song("Song C", "Singer X", 2.8, 2021);
    playlist[songCount++] = Song("Song D", "Singer Z", 3.2, 2019);
}

void addSongToPlaylist(Song playlist[], int& songCount) {
    if (songCount >= MAX_SONGS) {
        cout << "Playlist is full!" << endl;
        return;
    }

    string name, singer;
    double duration;
    int release_year;

    cout << "Enter song name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter singer name: ";
    getline(cin, singer);
    cout << "Enter duration (in minutes): ";
    cin >> duration;
    cout << "Enter release year: ";
    cin >> release_year;

    playlist[songCount++] = Song(name, singer, duration, release_year);
}

void sortByName(Song playlist[], int songCount) {
    for (int i = 1; i < songCount; i++) {
        Song temp = playlist[i];
        int j = i - 1;
        while (j >= 0 && playlist[j].name > temp.name) {
            playlist[j + 1] = playlist[j];
            j--;
        }
        playlist[j + 1] = temp;
    }
}

void sortBySinger(Song playlist[], int songCount) {
    for (int i = 1; i < songCount; i++) {
        Song temp = playlist[i];
        int j = i - 1;
        while (j >= 0 && playlist[j].singer > temp.singer) {
            playlist[j + 1] = playlist[j];
            j--;
        }
        playlist[j + 1] = temp;
    }
}

void sortByDuration(Song playlist[], int songCount) {
    for (int i = 1; i < songCount; i++) {
        Song temp = playlist[i];
        int j = i - 1;
        while (j >= 0 && playlist[j].duration < temp.duration) {
            playlist[j + 1] = playlist[j];
            j--;
        }
        playlist[j + 1] = temp;
    }
}

void sortByReleaseYear(Song playlist[], int songCount) {
    for (int i = 1; i < songCount; i++) {
        Song temp = playlist[i];
        int j = i - 1;
        while (j >= 0 && playlist[j].release_year < temp.release_year) {
            playlist[j + 1] = playlist[j];
            j--;
        }
        playlist[j + 1] = temp;
    }
}

void displayPlaylist(const Song playlist[], int songCount) {
    for (int i = 0; i < songCount; i++) {
        cout << "Name: " << playlist[i].name << ", Singer: " << playlist[i].singer
             << ", Duration: " << playlist[i].duration << " mins, Release Year: " << playlist[i].release_year << endl;
    }
}

void sortPlaylist(Song playlist[], int songCount) {
    int choice;
    cout << "Select sorting criteria:\n";
    cout << "1. Name (Ascending)\n";
    cout << "2. Singer (Ascending)\n";
    cout << "3. Duration (Descending)\n";
    cout << "4. Release Year (Descending)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            sortByName(playlist, songCount);
            break;
        case 2:
            sortBySinger(playlist, songCount);
            break;
        case 3:
            sortByDuration(playlist, songCount);
            break;
        case 4:
            sortByReleaseYear(playlist, songCount);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
    }

    cout << "Sorted Playlist:\n";
    displayPlaylist(playlist, songCount);
}

int main() {
    Song playlist[MAX_SONGS];
    int songCount = 0;

    createPlaylist(playlist, songCount);

    int option;
    do {
        cout << "\nMenu:\n";
        cout << "1. View Playlist\n";
        cout << "2. Add Song to Playlist\n";
        cout << "3. Sort Playlist\n";
        cout << "4. Back\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Current Playlist:\n";
                displayPlaylist(playlist, songCount);
                break;
            case 2:
                addSongToPlaylist(playlist, songCount);
                break;
            case 3:
                sortPlaylist(playlist, songCount);
                break;
            case 4:
                cout << "Back\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (option != 4);

return 0;
}
