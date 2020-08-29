//��Ʈ���� ����Ʈ���� �帣 ���� ���� ���� ����� �뷡�� �� ���� ��� ����Ʈ �ٹ��� ����Ϸ� �մϴ�.�뷡�� ���� ��ȣ�� �����ϸ�, �뷡�� �����ϴ� ������ ������ �����ϴ�.
//
//���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
//�帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
//�帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.
//�뷡�� �帣�� ��Ÿ���� ���ڿ� �迭 genres�� �뷡�� ��� Ƚ���� ��Ÿ���� ���� �迭 plays�� �־��� ��, ����Ʈ �ٹ��� �� �뷡�� ���� ��ȣ�� ������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.
//
//���ѻ���
//genres[i]�� ������ȣ�� i�� �뷡�� �帣�Դϴ�.
//plays[i]�� ������ȣ�� i�� �뷡�� ����� Ƚ���Դϴ�.
//genres�� plays�� ���̴� ������, �̴� 1 �̻� 10, 000 �����Դϴ�.
//�帣 ������ 100�� �̸��Դϴ�.
//�帣�� ���� ���� �ϳ����, �ϳ��� � �����մϴ�.
//��� �帣�� ����� Ƚ���� �ٸ��ϴ�.
//����� ��
//genres	plays	return
//[classic, pop, classic, classic, pop][500, 600, 150, 800, 2500][4, 1, 3, 0]
//����� �� ����
//classic �帣�� 1, 450ȸ ����Ǿ�����, classic �뷡�� ������ �����ϴ�.
//
//���� ��ȣ 3: 800ȸ ���
//���� ��ȣ 0 : 500ȸ ���
//���� ��ȣ 2 : 150ȸ ���
//pop �帣�� 3, 100ȸ ����Ǿ�����, pop �뷡�� ������ �����ϴ�.
//
//���� ��ȣ 4 : 2, 500ȸ ���
//���� ��ȣ 1 : 600ȸ ���
//���� pop �帣��[4, 1]�� �뷡�� ����, classic �帣��[3, 0]�� �뷡�� �״����� �����մϴ�.
//https://programmers.co.kr/learn/courses/30/lessons/42579


#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> totalNum;
    unordered_map<string, int> first;
    unordered_map<string, int> second;

    for (int i = 0; i < genres.size(); i++) {
        string genre = genres[i];
        int playNum = plays[i];
        totalNum[genre] += playNum;
        if (first.find(genre) == first.end()) {
            first[genre] = i;
        }
        else {
            int f = first[genre];
            if (playNum > plays[f])
            {
                second[genre] = f;
                first[genre] = i;
            }
            else {
                if (second.find(genre) == second.end()) {
                    second[genre] = i;
                }
                else {
                    int s = second[genre];
                    if (playNum > plays[s]) {
                        second[genre] = i;
                    }
                }
            }
        }
    }

    vector<pair<string, int>> genreInfo = vector<pair<string,int>>(totalNum.begin(), totalNum.end());
    sort(genreInfo.begin(), genreInfo.end(), compare);

    for (pair<string, int> p : genreInfo) {
        answer.push_back(first[p.first]);
        if (second.find(p.first) != second.end()) {
            answer.push_back(second[p.first]);
        }
    }

    return answer;
}