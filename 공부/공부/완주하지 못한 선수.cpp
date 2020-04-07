//���� ����
//������ ������ �������� �����濡 �����Ͽ����ϴ�.�� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.
//
//�����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 completion�� �־��� ��, �������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
//
//���ѻ���
//������ ��⿡ ������ ������ ���� 1�� �̻� 100, 000�� �����Դϴ�.
//completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.
//�������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
//������ �߿��� ���������� ���� �� �ֽ��ϴ�.
//����� ��
//participant	completion	return
//[leo, kiki, eden][eden, kiki]	leo
//[marina, josipa, nikola, vinko, filipa][josipa, filipa, marina, nikola]	vinko
//[mislav, stanko, mislav, ana][stanko, ana, mislav]	mislav
//����� �� ����
//���� #1
//leo�� ������ ��ܿ��� ������, ������ ��ܿ��� ���� ������ �������� ���߽��ϴ�.
//
//���� #2
//vinko�� ������ ��ܿ��� ������, ������ ��ܿ��� ���� ������ �������� ���߽��ϴ�.
//
//���� #3
//mislav�� ������ ��ܿ��� �� ���� ������, ������ ��ܿ��� �� ��ۿ� ���� ������ �Ѹ��� �������� ���߽��ϴ�.
//https://programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> completion_map;

    for (string s : completion) {
        if (completion_map.find(s) == completion_map.end()) {
            completion_map[s] = 1;
        }
        else {
            completion_map[s]++;
        }
    }

    for (string s : participant) {
        if (completion_map.find(s) == completion_map.end() || completion_map[s] == 0) {
            answer = s;
            break;
        }
        else {
            completion_map[s]--;
        }
    }

    return answer;
}