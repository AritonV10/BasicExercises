/* https://www.hackerrank.com/challenges/the-birthday-bar/problem */

int solve(std::vector<int> s, int d, int m) {
    int _count = 0, index = 0;
    int sum = [&]() -> int {
        int temp_sum = 0;
        for(unsigned i = 0; i < m; ++i)
            temp_sum += s.at(i);
        if(temp_sum == d) ++_count;
        return temp_sum;
    }();
    for(unsigned i = m; i < s.size(); ++i) {
        sum = (sum - s.at(index++)) + s.at(i);
        if (sum == d)
            ++_count;

    }
    return _count;
}
