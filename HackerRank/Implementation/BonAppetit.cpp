/* https://www.hackerrank.com/challenges/bon-appetit/problem */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    int nr_items, nr_f_n_eaten, money;
    std::vector<int> items;
    std::cin>>nr_items>>nr_f_n_eaten;
    for(unsigned i = 0; i < nr_items; ++i) {
        int item = 0;
        std::cin>>item;
        items.push_back(item);
    }
    std::cin>>money;
    int difference = [&]() -> int{
        int sum = 0;
        for(const auto & item : items) {
            sum += item;
        }
        return sum - items.at(nr_f_n_eaten);
    }();
    bool bon_appetit = difference/2 == money ? true : false;
    if(bon_appetit) {
        std::cout<<"Bon Appetit";
    } else {
        std::cout<< (money > difference/2 ? money - difference/2 : difference/2 - money);
    }
    return 0;
}
