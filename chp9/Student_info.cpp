//Student_info.cpp
#include "Student_info.h"
#include <iostream>

//빈 생성자
Student_info::Student_info() : midterm(0), final(0) { }

// cin을 읽어 Student_info를 초기화
Student_info::Student_info(istream& is) { read(is); }

bool compare(const Student_info& x, const Student_info& y) {
    return x.getName < y.getName; // T / F (A-Z)
}

// 입력 스트림에서 과제 점수를 읽어서 vector<double>에 넣음.
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // 이전 내용을 제거
        hw.clear();

        // 입력을 위한 변수
        double x; // cin에서 사용하기 

        // 불변성: 지금까지 count개 점수를 입력받았으며
        // 입력받은 점수의 합은 sum
        while (in >> x) {
            hw.push_back(x);
        }

        // 다음 학생의 점수 입력 작업을 고려해 스트림을 지움
        in.clear();
    }
}

istream& Student_info::read(istream& in) {
	in >> name >> midterm >> final;
	// 과제 점수를 읽음
	read_hw(in, homework);
	return in;
}

