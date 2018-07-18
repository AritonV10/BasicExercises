/* https://www.hackerrank.com/challenges/apple-and-orange/problem */

void countApplesAndOranges(int s, int t, int a, int b, std::vector<int> apples, vector<int> oranges) {
    int num_apples = 0, num_oranges = 0;
    for(auto apple = apples.begin(); apple != apples.end(); ++apple) {
        if(a + *apple >= s && a + *apple <= t) ++num_apples;
    }
    for(auto orange = oranges.begin(); orange != oranges.end(); ++orange) {
        if(b + *orange <= t && b + *orange >= s) ++num_oranges;
    }
    
    std::cout<<num_apples<<'\n';
    std::cout<<num_oranges;
}
