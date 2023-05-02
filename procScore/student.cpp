#include <iostream>
#include <vector>
#include <iomanip>
#include "student.h"

using std::endl;
using std::istream;
using std::ostream;
using std::vector;

void rank(vector<Student>& students)
{
    for (auto it = students.begin(); it != students.end(); ++it) {
        it->rank_ = 1;
    }

    for (auto it = students.begin(); it != students.end(); ++it) {
        for (auto it2 = students.begin(); it2 != students.end(); ++it2) {
            if (it->sum_ < it2->sum_) ++it->rank_;
        }
    }

}

ostream& print(ostream& out, const vector<Student>& students)
{
    out << "------------------------------------------------" << endl;
    out << "        Name        Kor Eng Math Sum  Avg   Rank" << endl;
    out << "------------------------------------------------" << endl;
    for (vector<Student>::const_iterator it = students.cbegin(); it != students.cend(); ++it) {
        out << *it << endl;
    }
    out << "------------------------------------------------" << endl;
}

ostream& operator<<(ostream& out, const Student& s)
{
    out
            << std::setw(20) << s.name_
            << std::setw(4) << s.kor_
            << std::setw(4) << s.eng_
            << std::setw(4) << s.maths_
            << std::setw(4) << s.sum_
            << std::setw(7) << std::fixed << std::setprecision(2) << s.avg_
            << std::setw(4) << s.rank_;
}

Student::Student()
{

}

Student::Student(istream& in)
{

}

bool Student::operator>(const Student& rhs) const
{
    return rank_ > rhs.rank_;
}

bool Student::operator<(const Student& rhs) const
{
    return rank_ < rhs.rank_;
}

istream& Student::read(istream& in)
{
    in >> name_ >> kor_ >> eng_ >> maths_;

    return in;
}

void Student::sum()
{
    sum_ = kor_ + eng_ + maths_;
}

void Student::avg()
{
    avg_ = static_cast<double>(sum_) / 3.0;
}