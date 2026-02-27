#include "Playlist.h"

// =======================
// Song implementation
// =======================

Song::Song(int id,
           string title,
           string artist,
           string album,
           int duration,
           int score,
           string url)
{
    // TODO: Student implementation
    this->id = id;
    this->title = title;
    this->artist = artist;
    this->album = album;
    this->duration = duration; 
    this->score = score;
    this->url = url;
}

int Song::getID() const
{
    // TODO: Student implementation
    return id;
}

int Song::getDuration() const
{
    // TODO: Student implementation
    return duration;
}

int Song::getScore() const
{
    // TODO: Student implementation
    return score;
}

string Song::toString() const
{
    // TODO: Student implementation
    return title + "-" + artist;
}

// =======================
// Playlist implementation
// =======================

Playlist::Playlist(string name)
{
    // TODO: Student implementation
    this->name = name;
    this->size = 0;
    this->currentIndex = 0;
}

Playlist::Playlist(const Playlist& other)
{
    // TODO: Student implementation
    name = other.name;
    size = other.size;
    currentIndex = other.currentIndex;

    for (int i = 0; i < size; i++)
        lstSong.add(other.lstSong.get(i));
}

int Playlist::getSize() const
{
    return size;

}

bool Playlist::empty() const
{
    // TODO: Student implementation
    return size == 0;
}

void Playlist::clear()
{
    // TODO: Student implementation
    while (size > 0)
    {
        lstSong.removeAt(0);
        size--;
    }
}

void Playlist::addSong(Song* s)
{
    // TODO: Student implementation
    lstSong.add(s);
    size ++;
    if (size == 1) currentIndex = 0;
}

void Playlist::removeSong(int index)
{
    // TODO: Student implementation
    if (index < 0 || index >= size)
        throw out_of_range("Index is invalid!");

    lstSong.removeAt(index);
    size--;

    if (size == 0)
    {
        currentIndex = 0;
        return;
    }

    if (index < currentIndex) currentIndex--;   
    if (currentIndex >= size) currentIndex = 0; 
}



Song* Playlist::getSong(int index) const
{
    // TODO: Student implementation
    if (index < 0 || index >= size)
        throw out_of_range("Index is invalid!");

    return lstSong.get(index);
}

// =======================
// Playing control
// =======================

Song* Playlist::playNext()
{
    // TODO: Student implementation
    if (size == 0) throw out_of_range("Index is invalid!");

    if (currentIndex == size - 1)
        currentIndex = 0;
    else
        currentIndex++;

    return lstSong.get(currentIndex);  
}

Song* Playlist::playPrevious()
{
    // TODO: Student implementation
    if (size == 0) throw out_of_range("Index is invalid!");

     if (currentIndex == 0)
        currentIndex = size - 1;
    else
        currentIndex--;

    return lstSong.get(currentIndex);
}

// =======================
// Score-related
// =======================

int Playlist::getTotalScore()
{
    // TODO: Student 
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        int minVal = lstSong.get(i)->getScore();
        int sum = 0;

        for (int j = i; j < size; j++)
        {
            int val = lstSong.get(j)->getScore();

            if (val < minVal)
                minVal = val;

            sum += val;
            total += minVal * sum;
        }
    }

    return total;
}

double Playlist::calculatePlaylistScore(int numSong) const
{
    double total = 0;
    int groupCount = size - numSong + 1;

    for (int i = 0; i < groupCount; i++)
    {
        int maxScore = lstSong.get(i)->getScore();

        for (int j = i + 1; j < i + numSong; j++)
        {
            int score = lstSong.get(j)->getScore();
            if (score > maxScore)
                maxScore = score;
        }

        total += maxScore;
    }

    return total / groupCount;
}

bool Playlist::compareTo(Playlist p, int numSong)
{
    // TODO: Student implementation
    if (numSong <= 0) return false;
    if (numSong > size || numSong > p.size) return false;

    double score1 = calculatePlaylistScore(numSong);
    double score2 = p.calculatePlaylistScore(numSong);

    if (score1 >= score2)
        return true;
    else
        return false;
}

// =======================
// Advanced playing modes
// =======================

void Playlist::findLeftGreater(int* left, int n) const
{
    int* stack = new int[n];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        int curDur = lstSong.get(i)->getDuration();

        while (top >= 0 &&
            lstSong.get(stack[top])->getDuration() <= curDur)
        {
            top--;
        }

        if (top >= 0)
            left[i] = stack[top];
        else
            left[i] = -1;

        top++;
        stack[top] = i;
    }

    delete[] stack;
}

void Playlist::findRightGreater(int* right, int n) const
{
    int* stack = new int[n];
    int top = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        int curDur = lstSong.get(i)->getDuration();

        while (top >= 0 &&
            lstSong.get(stack[top])->getDuration() <= curDur)
        {
            top--;
        }

        if (top >= 0)
            right[i] = stack[top];
        else
            right[i] = -1;

        top++;
        stack[top] = i;
    }

    delete[] stack;
}

int Playlist::selectNext(int cur, int leftIdx, int rightIdx) const
{
    if (leftIdx == -1)
        return rightIdx;

    if (rightIdx == -1)
        return leftIdx;

    int distLeft  = cur - leftIdx;
    int distRight = rightIdx - cur;

    if (distLeft <= distRight)
        return leftIdx;
    else
        return rightIdx;
}

void Playlist::playRandom(int index)
{
    // TODO: Student implementation
    int n = size;

    if (n == 0) return;
    if (index < 0 || index >= n) return;

    int* left  = new int[n];
    int* right = new int[n];

    findLeftGreater(left, n);
    findRightGreater(right, n);

    int cur = index;
    cout << lstSong.get(cur)->toString();

    while (true)
    {
        int next = selectNext(cur, left[cur], right[cur]);
        if (next == -1) break;

        cout << "," << lstSong.get(next)->toString();
        cur = next;
    }

    delete[] left;
    delete[] right;
}

int Playlist::playApproximate(int step)
{
    // TODO: Student implementation
    int n = size;
    if (n == 0) return 0;
    if (n == 1) return 0;

    int* dur = new int[n];
    for (int i = 0; i < n; i++)
        dur[i] = lstSong.get(i)->getDuration();

    const int INF = 1000000000;
    int* dp = new int[n];
    for (int i = 0; i < n; i++)
        dp[i] = INF;

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int left = i - step - 1;
        if (left < 0) left = 0;

        for (int j = i - 1; j >= left; j--)
        {
            int cost = dp[j] + abs(dur[i] - dur[j]);
            if (cost < dp[i])
                dp[i] = cost;
        }
    }

    int result = dp[n - 1];

    delete[] dur;
    delete[] dp;

    return result;
}
