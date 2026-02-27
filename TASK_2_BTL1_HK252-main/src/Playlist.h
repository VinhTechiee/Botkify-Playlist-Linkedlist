#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "main.h"
#include "BotkifyLinkedList.h"

// =======================
// Class Song
// =======================
class Song
{
#ifdef TESTING
    friend class TestHelper;
#endif

private:
    int id;
    string title;
    string artist;
    string album;
    int duration;
    int score;
    string url;

public:
    Song(int id,
         string title,
         string artist,
         string album,
         int duration,
         int score,
         string url);

    int getID() const;
    int getDuration() const;
    int getScore() const;

    string toString() const;
};

// =======================
// Class Playlist
// =======================
class Playlist
{
#ifdef TESTING
    friend class TestHelper;
#endif

private:
    string name;
    BotkifyLinkedList<Song*> lstSong;
    int size;
    int currentIndex;
    double calculatePlaylistScore(int numSong) const;
    void findLeftGreater(int* left, int n) const;
    void findRightGreater(int* right, int n) const;
    int selectNext(int cur, int leftIdx, int rightIdx) const;

public:
    Playlist(string name);
    Playlist(const Playlist& other); 

    int getSize() const;
    bool empty() const;
    void clear();

    void addSong(Song* s);
    void removeSong(int index);
    Song* getSong(int index) const;

    Song* playNext();
    Song* playPrevious();

    int getTotalScore();
    bool compareTo(Playlist p, int numSong);

    void playRandom(int index);
    int playApproximate(int step);
};

#endif // PLAYLIST_H
