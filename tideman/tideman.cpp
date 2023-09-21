// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>

#define MAX 9

int preferences[MAX][MAX];
bool locked[MAX][MAX];

struct Pair {
    int winner;
    int loser;
};

std::string candidates[MAX];
Pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

bool vote(int rank, const std::string& name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs();
void sort_pairs();
void lock_pairs();
void print_winner();
void swap(int a, int b);
bool circle(int a, int b);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: tideman [candidate ...]" << std::endl;
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        std::cout << "Maximum number of candidates is " << MAX << std::endl;
        return 2;
    }

    for (int i = 0; i < candidate_count; i++) {
        candidates[i] = argv[i + 1];
    }

    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count;
    std::cout << "Number of voters: ";
    std::cin >> voter_count;

    for (int i = 0; i < voter_count; i++) {
        int ranks[candidate_count];

        for (int j = 0; j < candidate_count; j++) {
            std::string name;
            std::cout << "Rank " << j + 1 << ": ";
            std::cin >> name;

            if (!vote(j, name, ranks)) {
                std::cout << "Invalid vote." << std::endl;
                return 3;
            }
        }

        record_preferences(ranks);

        std::cout << std::endl;
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    return 0;
}

bool vote(int rank, const std::string& name, int ranks[]) {
    for (int x = 0; x < candidate_count; x++) {
        if (name == candidates[x]) {
            ranks[rank] = x;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[]) {
    for (int x = 0; x < candidate_count - 1; x++) {
        for (int y = x + 1; y < candidate_count; y++) {
            preferences[ranks[x]][ranks[y]]++;
        }
    }
}

void add_pairs() {
    int p = 0;
    for (int y = 0; y < candidate_count; y++) {
        for (int z = 0; z < candidate_count; z++) {
            if (preferences[y][z] > preferences[z][y]) {
                pairs[p].winner = y;
                pairs[p].loser = z;
                pair_count++;
                p++;
            }
        }
    }
}

void sort_pairs() {
    int count = 0;
    int place = 0;
    for (int y = 0; y < pair_count; y++) {
        for (int z = 0; z < pair_count; z++) {
            if (preferences[pairs[y].winner][pairs[y].loser] > preferences[pairs[z].winner][pairs[z].loser]) {
                count++;
            }
        }
        if (count == pair_count - (place + 1)) {
            swap(place, y);
            place++;
        }
        count = 0;
    }
}

void lock_pairs() {
    for (int x = 0; x < pair_count; x++) {
        if (!circle(pairs[x].winner, pairs[x].loser)) {
            locked[pairs[x].winner][pairs[x].loser] = true;
        }
    }
}

void print_winner() {
    for (int x = 0; x < candidate_count; x++) {
        bool neverloser = true;
        for (int y = 0; y < candidate_count; y++) {
            if (locked[y][x] == true) {
                neverloser = false;
            }
        }
        if (neverloser == true) {
            std::cout << candidates[x] << std::endl;
            break;
        }
    }
}

void swap(int a, int b) {
    Pair temp = pairs[a];
    pairs[a] = pairs[b];
    pairs[b] = temp;
}

bool circle(int a, int b) {
    if (locked[b][a] == true) {
        return true;
    }

    for (int x = 0; x < pair_count; x++) {
        if (locked[x][a] == true) {
            return circle(x, b);
        }
    }

    return false;
}
