/* https://www.hackerrank.com/challenges/sock-merchant/problem */

int sockMerchant(const int & number, std::vector<int> ar) {
    int pairs = 0;
    std::map<int, int> occurence;
    for(auto it = ar.begin(); it != ar.end(); ++it) {
        auto map_iter = occurence.find(*it);
        if(map_iter != occurence.end()) {
            map_iter->second++;
        } else {
            occurence.emplace(*it, 1);
        }
    }

    return [&]() -> int {
        for(auto it = occurence.begin(); it != occurence.end(); ++it) {
            if(it->second % 2 == 0) {
                pairs += (it->second/2);
            } else {
                pairs += (it->second-1)/2;
            }
        }
        return pairs;
    }();
}
