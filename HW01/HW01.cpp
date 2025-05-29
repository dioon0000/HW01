#include <iostream>
#include <vector>
using namespace std;

//벡터 안의 값들의 합을 구하는 함수
int addFunc(vector<int> v){
    int val = 0;
    for(int a : v)  val+=a;

    return val;
}
//벡터 안의 값들의 평균을 구하는 함수
int avgFunc(vector<int> v){
    int val = addFunc(v)/v.size();

    return val;
}
void sortFunc(vector<int>& v, int c){
    //c가 1이면 오름차순 정렬
    //c가 2면 내림차순 정렬
}
int main(){
    //변수 선언
    vector<int> v;
    int x, n, add=0, avg=0;
    //입력
    cout << "벡터의 크기 N값을 입력해주세요: ";
    cin >> n;
    cout << "n개의 수를 입력해주세요: ";
    for(int i=0; i<n; ++i){
        cin >> x;
        add+=x;
        v.push_back(x);
    }
    avg+=add/v.size();

    //출력
    cout << "배열에 저장된 숫자들의 합계: " << add << '\n';
    cout << "배열에 저장된 숫자들의 평균: " << avg << '\n';
    cout << "배열에 저장된 숫자들의 합계(함수호출): " << addFunc(v) << '\n';
    cout << "배열에 저장된 숫자들의 평균(함수호출): " << avgFunc(v) << '\n';
    return 0;
}