#include <iostream>
#include <vector>
using namespace std;

//���� ���� ������ ���� ���ϴ� �Լ�
int addFunc(vector<int> v){
    int val = 0;
    for(int a : v)  val+=a;

    return val;
}
//���� ���� ������ ����� ���ϴ� �Լ�
int avgFunc(vector<int> v){
    int val = addFunc(v)/v.size();

    return val;
}
void sortFunc(vector<int>& v, int c){
    //c�� 1�̸� �������� ����
    //c�� 2�� �������� ����
}
int main(){
    //���� ����
    vector<int> v;
    int x, n, add=0, avg=0;
    //�Է�
    cout << "������ ũ�� N���� �Է����ּ���: ";
    cin >> n;
    cout << "n���� ���� �Է����ּ���: ";
    for(int i=0; i<n; ++i){
        cin >> x;
        add+=x;
        v.push_back(x);
    }
    avg+=add/v.size();

    //���
    cout << "�迭�� ����� ���ڵ��� �հ�: " << add << '\n';
    cout << "�迭�� ����� ���ڵ��� ���: " << avg << '\n';
    cout << "�迭�� ����� ���ڵ��� �հ�(�Լ�ȣ��): " << addFunc(v) << '\n';
    cout << "�迭�� ����� ���ڵ��� ���(�Լ�ȣ��): " << avgFunc(v) << '\n';
    return 0;
}