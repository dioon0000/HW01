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

//������ �Լ�
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

    //c�� 1�̸� �������� ����,c�� 2�� �������� ����
    if(command == 1 || command == 2){
        quickSort(v, 0, v.size()-1, command);
        cout << "���ĵ� �迭 : ";
        for(int i=0; i<v.size(); ++i)
            cout << v[i] << ' ';
        if(command == 1)
            cout << "\n������������ ���ĵǾ����ϴ�";
        else
            cout << "\n������������ ���ĵǾ����ϴ�";
    }
    //�� �� Ŀ��� �Է�
    else{
        cout << "�߸��� ���� Ŀ��� �Է��Դϴ�";
        return ;
    }
}

int main(){
    //���� ����
    vector<int> v;
    int x, n, c, add=0, avg=0;
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
    cout << "�����ϰ� ���� ����� �Է����ּ��� (1: ��������, 2: ��������): ";
    cin >> c;

    //���
    cout << "�ʼ����� ����\n=================================================\n";
    cout << "�迭�� ����� ���ڵ��� �հ�: " << add << '\n';
    cout << "�迭�� ����� ���ڵ��� ���: " << avg << '\n';
    cout << "�迭�� ����� ���ڵ��� �հ�(�Լ�ȣ��): " << addFunc(v) << '\n';
    cout << "�迭�� ����� ���ڵ��� ���(�Լ�ȣ��): " << avgFunc(v) << '\n';
    cout << "=================================================\n�������� ����\n";
    sortFunc(v, c);
    return 0;
}