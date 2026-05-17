# Botkify – Music Playlist Manager Using Linked Lists

## Project Overview

**Botkify** is a simulated music playlist management application implemented in **C++**.  
The project demonstrates how **linked list–based data structures** can be applied to efficiently manage dynamic playlists and support advanced playback operations.

The system models playlists using a **circular doubly linked list**, enabling efficient insertion, deletion, and bidirectional traversal of songs. Additional features such as playlist scoring, randomized playback, and grouped evaluation are implemented using algorithmic techniques including **monotonic stacks**, **sliding windows**, and **dynamic programming**.

This project was developed as part of a Data Structures and Algorithms (CO2003) to strengthen practical understanding of algorithm design, data structures, and modular programming.

---

## Key Features

### Playlist Management
- Insert songs into the playlist
- Remove songs from the playlist
- Traverse playlist forward and backward
- Retrieve song metadata

### Playback Simulation
- Play the next song
- Play the previous song
- Approximate playback using duration constraints

### Playlist Analysis
- Compute playlist score
- Evaluate grouped songs
- Compare multiple playlists using scoring metrics

---

## Data Structures and Algorithms

The project integrates several algorithmic techniques to support efficient playlist operations.

| Component | Technique |
|----------|-----------|
| Playlist Representation | Circular Doubly Linked List |
| Playlist Traversal | Bidirectional Iteration |
| Score Computation | Monotonic Stack |
| Grouped Song Evaluation | Sliding Window |
| Approximate Playback | Dynamic Programming |

These techniques ensure efficient execution while maintaining modular program design.

---

## Playlist Data Structure

The playlist is implemented using a **circular doubly linked list**, which enables efficient bidirectional traversal and continuous playback behavior.

```
        ┌───────────┐
        │  Song A   │
        └─────┬─────┘
              │ next
              ▼
        ┌───────────┐
        │  Song B   │
        └─────┬─────┘
              │ next
              ▼
        ┌───────────┐
        │  Song C   │
        └─────┬─────┘
              │
              ▼
           (back to Song A)

Traversal in reverse uses the `previous` pointers.
```

Each node stores:

- song information
- a pointer to the **next node**
- a pointer to the **previous node**

This design supports:

- **O(1)** traversal to the next or previous song  
- efficient insertion and deletion  
- continuous looping playback

---

## Playlist Operation Flow

```
Add Song
   ↓
Insert into Circular Doubly Linked List
   ↓
Update Playlist Structure
   ↓
Playback / Traversal
   ↓
Playlist Analysis (Scoring & Comparison)
```

---

## Example Usage

Example playlist operations:

```
Add Song: Song A
Add Song: Song B
Add Song: Song C

Current Playlist:
Song A → Song B → Song C

Play Next:
Now playing: Song B
```

---

## Project Structure

```
Botkify-Playlist-Linkedlist
│
├── src
│   ├── BotkifyLinkedList.h
│   ├── Playlist.h
│   ├── Playlist.cpp
│   ├── main.h
│   └── utils.h
│
├── tests
│   ├── doctest.h
│   ├── test_BotkifyLinkedList.cpp
│   └── test_play.cpp
│
├── main.cpp
├── Assignment 1 - Spec - EN.pdf
├── Assignment 1 - Spec - VI.pdf
├── .gitignore
└── README.md
```

---

## How to Compile and Run

### Compile

```bash
g++ main.cpp -o botkify
```

### Run

```bash
./botkify
```

---

## Algorithm Complexity

| Operation | Time Complexity |
|----------|----------------|
| addSong | O(1) |
| removeSong | O(n) |
| playNext / playPrevious | O(1) |
| calculatePlaylistScore | O(n) |
| getTotalScore | O(n²) |

---

## Learning Outcomes

This project demonstrates:

- Practical implementation of **linked list data structures**
- Application of **algorithmic techniques in playlist management**
- Modular **C++ programming** and code organization
- Complexity analysis and algorithm optimization

---

## Author

**Le Hien Vinh**  
Ho Chi Minh City University of Technology

