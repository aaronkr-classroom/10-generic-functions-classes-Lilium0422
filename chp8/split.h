#pragma once
#ifndef GUARD_split_h
#define GUARD_split_h

#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

//인수가 공백일 때는 true, 그렇지 않을 때는 false;
inline bool space(char c) {
	return isspace(c);
}

inline bool not_space(char c) {
	return !isspace(c);
}

template<class Out>
void split(const string& str, Out os) {
	typedef string::const_iterator iter;
	iter i = str.begin();

	//for(iter i = str.begin(); i != str.end(); i++ ) 랑 비슷함
	while (i != str.end()) {

		//선행 공백을 무시
		//지금 i 위치부터 첫 번째 뛰어쓰기 아닌 문자 찾기
		i = find_if(i, str.end(), not_space);

		//다음 단어의 끝을 찾음
		//while 반복할 때 항상 새로운 반복자 j를 생성
		//지금 i 위치부터 첫 번째 뛰어쓰기 찾기
		iter j = find_if(i, str.end(), space);
		//[i, j] 범위의 문자를 복사
		if (i != str.end()) {
			*os++ = string(i, j);
		}
			

		//i 반복자 위치가 j반복자에 위치를 저장 (i부터 j 까지 복사했으므로 j부터 시작)
		i = j;
	}
}



#endif // !GUARD_split_h
