#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

string trim(string);
string trim2(string);
string ltrim(string &);
string rtrim(string &);
string trim_regex(string &);

int main() {
    string str;

    // 0. 입출력 속도 향상
    // stdio의 스트림과 동기화 해제
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    // 1. EOF 포함한 입력 받기
    // // 1-1. cin.eof()

    // while(!cin.eof()){
    //     cin >> str;
    //     cout << str;
    // }

    // // 1-2. getline으로 처리하기
    // // getline 사용 시에 개행 문자가 버퍼에 남으므로 cin.ignore()로 지워줘야함
    // while(getline(cin, str)){
    //     cout << str;
    // }


    // 2. 출력시에 소수점 포맷팅

    double n = 12.6374;
    cout<<fixed;
    cout.precision(0); // 일의 자리까지 반올림해서 출력
    cout << n << '\n';
    cout.precision(1); // 소수점 첫 자리까지 반올림해서 출력
    cout << n << '\n';
    cout.precision(2); // 소수점 둘째 자리까지 반올림해서 출력
    cout << n << '\n';


    // 3. 문자열 수정
    string ex = "abcd123 hello !@#$ abcd 1234";
    // 3-1. 특정 인덱스를 치환
    // str.replace(n, k, str2)
    // 인덱스 n부터 k개를 str2로 치환
    // 리턴 없이 str을 수정함
    cout << ex.replace(14, 4, "cpp") << '\n';

    // 3-2. 특정 인덱스 삭제
    cout << ex.replace(8, 6, "") << '\n';
    cout << ex.erase(7,1) << '\n'; // iterator도 오버로딩되어 있음.
    cout << ex.erase(7) << '\n'; // 갯수 안 쓰면 끝까지 삭제

    string ex2 = "abAB123!@#$";
    // 3-3. 문자의 대소문자 변환
    // 아스키 값 리턴
    cout << ex2[0] << " -> " << (char)toupper(ex[0]) << '\n';
    cout << ex2[2] << " -> " << (char)tolower(ex[2]) << '\n';
    cout << ex2[10] << " -> " << (char)toupper(ex[11]) << '\n'; // 알파벳 아닌 경우엔 l, L 리턴

    string ex3 = "int";
    // 3-4. 문자열 삽입
    // str.insert(n, str2) n번째 앞에 str2 삽입
    cout << ex3.insert(2, "ser") << '\n';


    // 4. 문자 판별
    // cctype 헤더
    string ex4 = "aA12 ";
    cout << ex4[0] << " is a digit : " << isdigit(ex4[0]) << '\n'; // a is a digit : 0
    cout << ex4[0] << " is a alpha : " << isalpha(ex4[0]) << '\n'; // a is a digit : 0

    cout << ex4[2] << " is a digit : " << isdigit(ex4[2]) << '\n'; // a is a digit : 0
    cout << ex4[2] << " is a alpha : " << isalpha(ex4[2]) << '\n'; // 1 is a alpha : 0

    cout << ex4[1] << " is a upper : " << isupper(ex4[1]) << '\n'; // A is a upper : 1
    cout << ex4[1] << " is a lower : " << islower(ex4[1]) << '\n'; // A is a lower : 0
    cout << ex4[4] << " is a space : " << isspace(ex4[4]) << '\n'; //   is a space : 1

    // 5. 문자열 탐색, 추출
    string ex5 = "hello string";

    // 5-1. 부분문자열 추출
    // str.substr(pos, count = npos)
    cout << ex5.substr(0, 5) << '\n';
    cout << ex5.substr(0) << '\n';
    cout << ex5.substr(0, string::npos) << '\n';

    // 5-2. 부분문자열 탐색
    string ex5_2 = "hello cpp world cpp";
    // 인덱스 반환, 없으면 string::npos 리턴
    // find(substr, n) n부터 substr의 인덱스
    cout << ex5_2.find("cpp") << '\n';
    cout << ex5_2.find("cpp", 7) << '\n';
    cout << (ex5_2.find("java") == string::npos) << '\n';
    cout << ex5_2.find_first_of("cpp") << '\n'; // 문자들이 처음 등장하는 시작 인덱스
    cout << ex5_2.find_first_not_of("cpp") << '\n'; // 문자들이 아닌 첫 인덱스
    cout << ex5_2.find_last_of("cpp") << '\n'; // 문자들 중 마지막 등장하는 마지막 인덱스
    cout << ex5_2.find_last_not_of("cpp") << '\n'; // 문자들 아닌 마지막 인덱스

    // 5-3. 특정문자열 갯수 카운트
    string ex5_3 = "hello java and spring boot";

    regex re("a"); // 타겟 문자열
    auto end = sregex_iterator();
    auto iter = sregex_iterator(ex5_3.begin(), ex5_3.end(), re);

    cout << "\'a\' count : " << distance(iter, end) << '\n'; // 'a' count : 3
}

// 6. split 함수 구현
// str : 타겟문자열, char : 구분자
vector<string> split(string str, char delimiter){
    istringstream iss(str); // 문자열 스트림
    string buffer; // 문자열 버퍼

    vector<string> result; // 결과 문자열들을 담을 벡터

    while(getline(iss, buffer, delimiter)){
        result.push_back(buffer);
    }

    return result;
}


// 7. trim 함수 구현
// 7-1. string 함수로 구현
// 전부 제거
string trim(string str){
    while (str.find(' ') != string::npos) str.erase(str.find(' '),1);

    return str;
}

// 7-2. 앞 뒤 제거
// 공백 말고도 가능
string trim2(string str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);

    return str;
}

// 7-3. regex로 구현
string ltrim(string str){
    return regex_replace(str, regex("^\\s+"), "");
}

string rtrim(string &str){
    return regex_replace(str, regex("\\s+$"), "");
}

string trim_regex(string &str){
    return ltrim(rtrim(str));
}