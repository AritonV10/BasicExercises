/* https://www.hackerrank.com/challenges/counting-valleys/problem */

int countingValleys(int n, std::string steps) {
    int sea_level = 0, valleys = 0;
    bool is_valley = false;
    for(auto const & step : steps) {
        if(step == 'D') {
            --sea_level;
            if(sea_level < 0 && !is_valley)
                is_valley = true;
        } else {
            ++sea_level;
        }
        if(sea_level == 0 && is_valley) {
            ++valleys;
            is_valley = false;
            continue;
        }

    }
    return valleys;
}
