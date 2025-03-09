#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << "Error: " << msg << " (" << word1 << " and " << word2 << ")" << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    if (abs((int)str1.length() - (int)str2.length()) > d){
        return false;
    }
    
    vector<vector<int>> dist(str1.length() + 1, vector<int>(str2.length() + 1));
    for (int i = 0; i <= str1.length(); i++) dist[i][0] = i;
    for (int j = 0; j <= str2.length(); j++) dist[0][j] = j;
    
    for (int i = 1; i <= str1.length(); i++){
        for (int j = 1; j <= str2.length(); j++){
            if (str1[i-1] == str2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            } 
            else{
                dist[i][j] = min({dist[i-1][j], dist[i][j-1], dist[i-1][j-1]}) + 1;
            }
        }
    }
    return dist[str1.length()][str2.length()] <= d;
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}