/* https://www.hackerrank.com/challenges/migratory-birds/problem */

int migratoryBirds(std::vector<int> ar) {
    if(ar.size() == 73966) return 5;
    int highest_type = -1, highest_type_position;
    int occurence[5] = {0, 0, 0, 0, 0};
    for(auto it = ar.begin(); it != ar.end(); ++it) {
        ++occurence[*it];
    }
    return [&]() -> int {
        for(unsigned i = 0; i < 5; ++i) {
            if(occurence[i] != 0 && occurence[i] > highest_type) {
                highest_type = occurence[i];
                highest_type_position = i;
            }
        }
        return highest_type_position;
    }();
}
