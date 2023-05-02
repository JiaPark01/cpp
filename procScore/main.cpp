#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "student.h"

using std::cerr;        using std::endl;
using std::ifstream;    using std::ofstream;
using std::vector;
using std::string;

int main() {
    ifstream in("score.dat");
    ofstream out("score.out");

    if (!in) {
        std::cerr << "Cannot open input file\n" << endl;
        exit(1);
    }

    if (!out) {
        std::cerr << "Cannot open output file\n" << endl;
        exit(1);
    }

    vector<Student> students;

    Student s;
    while (s.read(in)) {
        s.sum();
        s.avg();
        students.push_back(s);
    }

    // rank
    rank(students);

    // sorting by name
    std::sort(students.begin(), students.end());

    // output
    ::print(out, students);

    return 0;
}
