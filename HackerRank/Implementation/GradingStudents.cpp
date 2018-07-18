/* https://www.hackerrank.com/challenges/grading/problem */

std::vector<int> gradingStudents(std::vector<int>& grades) {
    int multiple_of_five = 0;
    for(auto it = grades.begin(); it != grades.end(); ++it) {
        if(*it < 38) continue;
        multiple_of_five = *it;
        for(;;) {
            ++multiple_of_five;
            if(multiple_of_five % 5 == 0) break;
        }
        *it = (multiple_of_five - *it < 3 ?  multiple_of_five : *it);
    }

    return grades;
}
