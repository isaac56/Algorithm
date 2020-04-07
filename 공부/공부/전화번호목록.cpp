//��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
//��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.
//
//������ : 119
//���ؿ� : 97 674 223
//������ : 11 9552 4421
//��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, � ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.
//
//���� ����
//phone_book�� ���̴� 1 �̻� 1, 000, 000 �����Դϴ�.
//�� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.
//����� ����
//phone_book	return
//[119, 97674223, 1195524421]	false
//[123, 456, 789]	true
//[12, 123, 1235, 567, 88]	false
//����� �� ����
//����� �� #1
//�տ��� ������ ���� �����ϴ�.
//
//����� �� #2
//�� ��ȣ�� �ٸ� ��ȣ�� ���λ��� ��찡 �����Ƿ�, ���� true�Դϴ�.
//
//����� �� #3
//ù ��° ��ȭ��ȣ, ��12���� �� ��° ��ȭ��ȣ ��123���� ���λ��Դϴ�.���� ���� false�Դϴ�.
//https://programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map <string, bool> pMap;

bool compare(string a, string b) {
    if (a.length() < b.length())
        return true;
    return false;
}

bool solution(vector<string> phone_book) {

    sort(phone_book.begin(), phone_book.end(), compare);

    for (string s : phone_book) {
        for (int i = 1; i <= s.length(); i++) {
            string toCompare = s.substr(0, i);
            if (pMap.find(toCompare) != pMap.end()) {
                return false;
            }
        }
        pMap[s] = true;
    }

    return true;
}