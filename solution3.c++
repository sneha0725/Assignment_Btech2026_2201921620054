#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student {
private:
    int scores[5]; // Array to hold scores (fixed size for 5 subjects)

public:
    // Function to read scores from input
    void input() {
        for (int i = 0; i < 5; i++) {
            cin >> scores[i];
        }
    }

    // Function to calculate the total score
    int calculateTotalScore() {
        int totalScore = 0;
        for (int i = 0; i < 5; i++) {
            totalScore += scores[i];
        }
        return totalScore;
    }
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
