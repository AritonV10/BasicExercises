/* https://www.hackerrank.com/challenges/kangaroo/problem */

std::string kangaroo(int x1, int v1, int x2, int v2) {
    if(x1 <= x2 && v1 <= v2) return "NO";
    int distance_between = std::numeric_limits<int>::max(), distance = 0;
    for(;;) {
        x1 += v1;
        x2 += v2;
        distance = (x1 > x2 ? x1 - x2 : x2 - x1);
        if(x1 == x2) {
            break;
        }
        if(distance < distance_between) {
            distance_between = distance;
        } else {
            return "NO";
        }

    }
    return "YES";
}
