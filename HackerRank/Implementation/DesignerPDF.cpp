/* https://www.hackerrank.com/challenges/designer-pdf-viewer/problem */

int letter_position(const char letter) {
    char first_letter = 'a';
    for(unsigned i = 1;;++i) {
        if(first_letter == letter) return i;
        ++first_letter;
    }
}
int designerPdfViewer(std::vector<int> h, std::string word) {
    int highest_letter = -1;
    std::unordered_set<char> chars_checked;
    for(const auto & letter : word) {
        if(chars_checked.find(letter) == chars_checked.end()) {
            int position = letter_position(letter) - 1;
            if(h[position] > highest_letter) {
                highest_letter = h[position];
            }
            chars_checked.emplace(letter);
        }
    }
    return word.size() * 1 * highest_letter;
}
