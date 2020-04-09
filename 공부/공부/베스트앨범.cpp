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
#include <set>

using namespace std;

vector<string> genres;
vector<int> plays;
unordered_map<string, int> genreNum;
unordered_map<string, vector<int>> genreMusic;
vector<string> genreNames;

bool compMusic(int i, int j) {
    if (plays[i] == plays[j]) {
        return i < j;
    }
    else {
        return plays[i] > plays[j];
    }
}

bool compGenre(string a, string b) {
    return genreNum[a] > genreNum[b];
}

vector<int> solution(vector<string> gen, vector<int> pl) {
    vector<int> answer;

    genres = gen;
    plays = pl;

    for (int i = 0; i < genres.size(); i++) {
        if (genreNum.find(genres[i]) == genreNum.end()) {
            genreNum[genres[i]] = plays[i];
            genreMusic[genres[i]] = vector<int>(0);
            genreMusic[genres[i]].push_back(i);
        }
        else {
            genreNum[genres[i]] += plays[i];
            genreMusic[genres[i]].push_back(i);
        }
    }

    for (pair<string, vector<int>> p : genreMusic) {
        genreNames.push_back(p.first);
    }

    sort(genreNames.begin(), genreNames.end(), compGenre);

    for (string s : genreNames) {
        sort(genreMusic[s].begin(), genreMusic[s].end(), compMusic);
        if (genreMusic[s].size() >= 2) {
            answer.push_back(genreMusic[s][0]);
            answer.push_back(genreMusic[s][1]);
        }
        else {
            answer.push_back(genreMusic[s][0]);
        }
    }


    return answer;
}