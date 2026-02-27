# 🎵 BOTKIFY – MUSIC PLAYER SIMULATION APPLICATION  

## 📖 Project Overview

**BotKify** is a simulated music player application developed to demonstrate the application of **linked list–based data structures** in playlist management.

The project focuses on designing and implementing a playlist system that supports efficient insertion, deletion, traversal, and advanced playback operations. It serves as an academic assignment aimed at strengthening understanding of data structures, algorithmic complexity, and modular C++ programming.

---

## 🎯 Project Objectives

The primary objectives of this project are:

- Apply linked list data structures in a practical application
- Design efficient playlist management mechanisms
- Analyze and optimize algorithmic time complexity
- Strengthen problem-solving skills using C++
- Practice modular design and testing-driven development

---

## 🏗 Project Structure

```
Botkify-Playlist-Linkedlist
├── .vscode/
│   ├── launch.json
│   ├── settings.json
│   └── tasks.json
│
├── src/
│   ├── BotkifyLinkedList.h
│   ├── Playlist.h
│   ├── Playlist.cpp
│   ├── main.h
│   └── utils.h
│
├── tests/
│   ├── doctest.h
│   ├── test_BotkifyLinkedList.cpp
│   └── test_play.cpp
│
├── Assignment 1 - Spec - EN.pdf
├── Assignment 1 - Spec - VI.pdf
├── .gitignore
├── main.cpp
└── README.md
```

## 🎵 Core Features

### 🎶 Song Management
- Insert songs into a playlist
- Remove songs from a playlist
- Retrieve song metadata and attributes

---

### ▶ Playback Control
- Play the next song
- Play the previous song
- Approximate (randomized) playback based on song duration constraints

---

### 📊 Scoring and Comparison
- Compute the total score of a playlist
- Calculate average scores for grouped songs
- Compare two playlists based on defined scoring rules

---

## ⚙ Data Structures and Algorithms Used

- **Circular Doubly Linked List** for playlist representation
- **Monotonic Stack** for efficient score computation
- **Sliding Window Technique** for grouped song evaluation
- **Dynamic Programming** for approximate playback mode

These techniques are used to ensure both correctness and performance efficiency.

---

## 🚀 How to Compile & Run

### Compile
```bash
g++ main.cpp -o botkify
```

### Run
```bash
./botkify
```

## 📈 Algorithm Complexity

| Function | Complexity |
|----------|------------|
| addSong | O(1) |
| removeSong | O(n) |
| playNext / playPrevious | O(1) |
| calculatePlaylistScore | O(n) |
| getTotalScore | O(n²) |
