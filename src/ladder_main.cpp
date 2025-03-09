#include "ladder.h"

int main() {
    set<string> word_list;
    //try {
    load_words(word_list, "words.txt");
    // } catch (const runtime_error& e) {
    //     cerr << e.what() << endl;
    //     return 1;
    // }
    
    string start_word, end_word;
    cout << "Enter start word: ";
    cin >> start_word;
    cout << "Enter end word: ";
    cin >> end_word;
    
    transform(start_word.begin(), start_word.end(), start_word.begin(), ::tolower);
    transform(end_word.begin(), end_word.end(), end_word.begin(), ::tolower);
    
    vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);
    print_word_ladder(ladder);
    cout << "\nRunning verification tests:\n";
    verify_word_ladder();
    
    return 0;
}