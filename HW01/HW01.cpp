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
double avgFunc(vector<int> v){
    double val = (double)addFunc(v)/v.size();

    return val;
}

//퀵정렬 함수
void quickSort(vector<int>& v, int start, int end, int command) {
    if(start >= end) return;
    int pivot = start;
    int i = start + 1;
    int j = end;

    while(i <= j){
        if(command == 1){
            while(i <= end && v[i] <= v[pivot]) i++;
            while(j > start && v[j] >= v[pivot]) j--;
        } 
        else {
            while(i <= end && v[i] >= v[pivot]) i++;
            while(j > start && v[j] <= v[pivot]) j--;
        }
        if(i > j) swap(v[pivot], v[j]);
        else swap(v[i], v[j]);
    }
    quickSort(v, start, j - 1, command);
    quickSort(v, j + 1, end, command);
}

void sortFunc(vector<int>& v, int command){

    //c가 1이면 오름차순 정렬,c가 2면 내림차순 정렬
    if(command == 1 || command == 2){
        quickSort(v, 0, v.size()-1, command);
        cout << "정렬된 배열 : ";
        for(int i=0; i<v.size(); ++i)
            cout << v[i] << ' ';
        if(command == 1)
            cout << "\n오름차순으로 정렬되었습니다";
        else
            cout << "\n내림차순으로 정렬되었습니다";
    }
    //그 외 커멘드 입력
    else{
        cout << "잘못된 정렬 커멘드 입력입니다";
        return ;
    }
}

int main(){
    //변수 선언
    vector<int> v;
    int x, n, c, add=0;
    double avg=0;
    //입력
    cout << "벡터의 크기 N값을 입력해주세요: ";
    cin >> n;
    cout << "n개의 수를 입력해주세요: ";
    for(int i=0; i<n; ++i){
        cin >> x;
        add+=x;
        v.push_back(x);
    }
    avg+=(double)add/v.size();
    cout << "정렬하고 싶은 방식을 입력해주세요 (1: 오름차순, 2: 내림차순): ";
    cin >> c;

    //출력
    cout << "필수과제 구현\n=================================================\n";
    cout << "배열에 저장된 숫자들의 합계: " << add << '\n';
    cout << "배열에 저장된 숫자들의 평균: " << avg << '\n';
    cout << "배열에 저장된 숫자들의 합계(함수호출): " << addFunc(v) << '\n';
    cout << "배열에 저장된 숫자들의 평균(함수호출): " << avgFunc(v) << '\n';
    cout << "=================================================\n도전과제 구현\n";
    sortFunc(v, c);
    return 0;
}