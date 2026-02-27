# 🎵 BOTKIFY – ỨNG DỤNG NGHE NHẠC – MUSIC PLAYER APPLICATION  

## 📌 Giới thiệu | Introduction

**BotKify** là ứng dụng nghe nhạc mô phỏng được xây dựng nhằm áp dụng cấu trúc dữ liệu **Danh sách liên kết (Linked List)** vào quản lý playlist.

**BotKify** is a simulated music player application developed to apply the **Linked List** data structure in playlist management.

---

## 🎯 Mục tiêu | Objectives

- Áp dụng cấu trúc dữ liệu danh sách liên kết
- Tối ưu độ phức tạp thuật toán
- Quản lý và xử lý playlist hiệu quả
- Rèn luyện kỹ năng lập trình C++

- Apply linked list data structure
- Optimize algorithm complexity
- Efficiently manage and process playlists
- Improve C++ programming skills

---

## 🏗 Cấu trúc chương trình | Project Structure

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

## 🎵 Chức năng chính | Main Features

### 🎶 Quản lý bài hát | Song Management
- Thêm bài hát vào playlist  
- Xóa bài hát khỏi playlist  
- Lấy thông tin bài hát  

- Add songs to playlist  
- Remove songs from playlist  
- Retrieve song information  

---

### ▶ Điều khiển phát nhạc | Playback Control
- Phát bài tiếp theo  
- Phát bài trước  
- Phát ngẫu nhiên theo tiêu chí thời lượng  

- Play next song  
- Play previous song  
- Random play based on duration rule  

---

### 📊 Tính toán & So sánh | Scoring & Comparison
- Tính tổng điểm playlist  
- Tính điểm trung bình theo nhóm bài hát  
- So sánh hai playlist  

- Calculate total playlist score  
- Calculate average score by group size  
- Compare two playlists  

---

## ⚙ Cấu trúc dữ liệu sử dụng | Data Structure Used

- Circular Doubly Linked List  
- Thuật toán Stack đơn điệu (Monotonic Stack)  
- Sliding Window Technique  
- Dynamic Programming (Approximate Play Mode)

---

## 🚀 Cách chạy chương trình | How to Run

### Compile
```bash
g++ main.cpp -o botkify
```

Bạn cần thêm phần Run và đóng block cho hoàn chỉnh:

````md
## 🚀 Cách chạy chương trình | How to Run

### Compile
```bash
g++ main.cpp -o botkify
```

### Run
```bash
./botkify
```

## 📈 Độ phức tạp thuật toán | Algorithm Complexity

| Function | Complexity |
|----------|------------|
| addSong | O(1) |
| removeSong | O(n) |
| playNext / playPrevious | O(1) |
| calculatePlaylistScore | O(n) |
| getTotalScore | O(n²) |
