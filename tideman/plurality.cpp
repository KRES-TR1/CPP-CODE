#include <iostream>
#include <string>
#include <cstring>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
struct Candidate {
    std::string name;
    int votes;
};

// Array of candidates
Candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(const std::string& name);
void print_winner();

int main(int argc, char* argv[]) {
    // Check for invalid usage
    if (argc < 2) {
        std::cout << "Usage: plurality [candidate ...]" << std::endl;
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        std::cout << "Maximum number of candidates is " << MAX << std::endl;
        return 2;
    }

    for (int i = 0; i < candidate_count; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;
    std::cout << "Number of voters: ";
    std::cin >> voter_count;

    // Loop over all voters
    for (int i = 0; i < voter_count; i++) {
        std::string name;
        std::cout << "Vote: ";
        std::cin >> name;

        // Check for invalid vote
        if (!vote(name)) {
            std::cout << "Invalid vote." << std::endl;
        }
    }

    // Display winner of election
    print_winner();

    return 0;
}

// Update vote totals given a new vote
bool vote(const std::string& name) {
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].name == name) {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner() {
    int highest = 0;
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > highest) {
            highest = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes == highest) {
            std::cout << candidates[i].name << std::endl;
        }
    }
}
