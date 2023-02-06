#include "DefineSolutionList.h"
#include <iostream>

using namespace std;

#ifdef 개인정보수집유효기간LV1

#include <string>
#include <sstream>
#include <unordered_map>

unordered_map<char, int> mTerms;
vector<int> priv;
int year;
int month;
int day;
int total;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    vector<int> answer;

    // 날짜 계산
    year = stoi(today.substr(0, 4));
    month = stoi(today.substr(5, 2));
    day = stoi(today.substr(8, 2));
    total = year * 12 * 28 + (month - 1) * 28 + day;

    // 약관 자르기
    for (int i = 0; i < terms.size(); i++)
    {
        char temp; int month;
        stringstream ss(terms[i]);
        ss >> temp >> month;
        mTerms[temp] = month;
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        int y = stoi(privacies[i].substr(0, 4));
        int m = stoi(privacies[i].substr(5, 2));
        int d = stoi(privacies[i].substr(8, 2));
        char a = privacies[i].back();

        int tmp = y * 12 * 28 + (m - 1) * 28 + d + (mTerms[a] * 28 - 1);

        priv.push_back(tmp);
    }

    for (int i = 0; i < priv.size(); i++)
    {
        if (priv[i] < total) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

#endif // 개인정보수집유효기간LV1

#ifdef 크기가작은부분문자열LV1
#include <string>
#include <vector>


int solution(string t, string p)
{
    int answer = 0;
    int tSize = t.size();
    int pSize = p.size();

    for (int i = 0; i < tSize - pSize + 1; i++)
    {
        string s1 = t.substr(i, pSize); // 비교할 부분 string
        bool same = true;

        for (int j = 0; j < pSize; j++)
        {
            if (s1[j] < p[j])
            {
                answer++;
                same = false;
                break;
            }
            else if (s1[j] > p[j])
            {
                same = false;
                break;
            }
        }

        if (same)
            answer++;
    }
    
    return answer;
}
#endif // 크기가작은부분문자열LV1

#ifdef 가장가까운같은글자LV1
#include <string>
#include <vector>
#include <unordered_map>

vector<int> solution(string s) 
{
    vector<int> answer;
    unordered_map<char, int> map;   // 인덱스 위치 담아줄 map

    // string 전체 돌아줌
    for (int i = 0; i < s.length(); i++)
    {
        if (map.find(s[i]) != map.end())
        {
            answer.push_back(i - map[s[i]]);
            map[s[i]] = i;
        }
        else
        {
            answer.push_back(-1);   // -1 담아주고
            map[s[i]] = i;          // 해당 문자를 키값으로 인덱스 최신화
        }
    }

    return answer;
}
#endif // 가장가까운같은글자LV1

#ifdef 문자열나누기LV1
#include <string>
#include <vector>

int solution(string s) 
{
    string s1 = s;
    int answer = 0;
    int sCount = 1;
    int dCount = 0;
    int idx = 1;
    char tmp = s[0];

    while (idx <= s1.size())
    {
        if (sCount == dCount)
        {
            answer++;
            s1.erase(0, idx);
            sCount = 1;
            dCount = 0;
            idx = 1;
            tmp = s1[0];
        }
        else
        {
            if (tmp == s1[idx])
                sCount++;
            else
                dCount++;

            idx++;
        }
    }

    if (!s1.empty())
        answer++;

    return answer;
}
#endif // 문자열나누기LV1

#ifdef 명예의전당1LV1
#include <string>
#include <vector>
#include <queue>

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순

    
    for (int i = 0; i < score.size(); i++)
    {
        if (pq.size() < k)
        {
            pq.push(score[i]);
        }
        else
        {
            if (pq.top() < score[i])
            {
                pq.pop();
                pq.push(score[i]);
            }
        }
        answer.push_back(pq.top());
    }

    return answer;
}
#endif // 명예의전당1LV1

#ifdef 기사단원의무기LV1
#include <string>
#include <vector>

int solution(int number, int limit, int power) 
{
    int answer = 0;

    for (int i = 1; i <= number; i++)
    {
        int tmp = 1;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
                tmp++;

            if (tmp > limit)
            {
                tmp = power;
                break;
            }
        }

        answer += tmp;
    }
    return answer;
}
#endif // 기사단원의무기LV1

#ifdef 과일장수LV1
#include <string>
#include <vector>
#include <algorithm>

int solution(int k, int m, vector<int> score)
{
    int answer = 0;
    vector<int> v = score;
    sort(v.begin(), v.end(), greater<int>());   // 내림차순 정렬
    int idx = 0;
    int min = v[idx];

    // 벡터 사이즈만큼 반복문 돌기
    while (m <= v.size())
    {
        idx = 0;
        min = v[idx];                 // 현재 상자에 담을 과일중에서 품질이 가장 낮은것
        for (int j = 0; j < m; j++)     // m개씩 담아주기
        {
            if (min > v[j])             // 담아준 과일의 품질이 가장 낮다면
                min = v[j];             // 최신화
        }

        answer += min * m;
        v.erase(v.begin(), v.begin() + m);
    }
    //for (int i = 0; i < v.size();)
    //{
    //    if (m > v.size())
    //        break;
    //
    //    int min = v[i];                 // 현재 상자에 담을 과일중에서 품질이 가장 낮은것
    //    for (int j = 0; j < m; j++)     // m개씩 담아주기
    //    {
    //        if (min > v[j])             // 담아준 과일의 품질이 가장 낮다면
    //            min = v[j];             // 최신화
    //    }
    //}

    return answer;
}
#endif // 과일장수LV1

#ifdef 무인도여행LV2
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int visited[MAX][MAX] = { 0, };

int BFS(int n, int m, vector<string> maps);

vector<int> solution(vector<string> maps) 
{
    vector<int> answer;

    int X = maps.size();
    int Y = maps[0].size();

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] == 'X')
            {
                visited[i][j] = true;
            }
            else 
            {
                if (!visited[i][j])
                {
                    visited[i][j] = true;
                    answer.push_back(BFS(i, j, maps));
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    if (answer.empty())
        answer.push_back(-1);

    return answer;
}

int BFS(int n, int m, vector<string> maps)
{
    queue<pair<int, int>> q;
    q.push({ n, m });

    int add = maps[n][m] - '0';
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if (0 > nx || nx >= maps.size() ||
                0 > ny || ny >= maps[0].size())
                continue;

            if (maps[nx][ny] != 'X' && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                add += maps[nx][ny] - '0';
                q.push({ nx, ny });
            }
        }
    }

    return add;
}
#endif // 무인도여행LV2

#ifdef 뒤에있는큰수찾기LV2
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer.resize(numbers.size(), -1);
    stack<pair<int, int>> s;

    // 반복문 진행
    for (int i = 0; i < numbers.size(); i++)
    {
        // pair로 인덱스와 인덱스의 값 생성
        pair<int, int> p = make_pair(i, numbers[i]);

        // 만약 스텍이 비어있다면
        if (s.empty())
        {
            // 바로 넣어줌
            s.push(p);
        }
        // 아니라면
        else
        {
            // 비어있지 않을때까지 검사해서
            while (!s.empty())
            {
                // 스텍의 가장 윗부분 가져오기
                pair<int, int> tmp = s.top();

                // 스택의 가장 윗부분의 값이 들어온 값 이상이라면 (4 >= 3)
                if (tmp.second >= p.second)
                {
                    // 스택에 넣어주고 반복문 빠져나옴
                    s.push(p);
                    break;
                }
                // 값보다 작다면
                else
                {
                    // 가져온 스택의 인덱스에 현재 검사중인 인덱스 값을 넣어줌
                    answer[tmp.first] = p.second;

                    // 그 후 스텍에서 pop해줌
                    s.pop();

                    // pop한 뒤 스텍이 비어있다면 p를 넣어줌.
                    if (s.empty())
                        s.push(p);
                }
            }
        }

    }

    return answer;
}
#endif //뒤에있는큰수찾기LV2

#ifdef 호텔대실LV2
#include <string>
#include <vector>
#include <queue>

//using namespace std;

int solution(vector<vector<string>> book_time) 
{
    int answer = 0;

    //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> v1;  // 시간순으로 정렬할 vector
    vector<pair<int, int>> v2;  // 방 갯수 vector

    // 오름차순으로 정렬
    for (int i = 0; i < book_time.size(); i++)
    {
        // 시작 시간, 분
        int startHour = stoi(book_time[i][0].substr(0, 2));
        int startMin = stoi(book_time[i][0].substr(3, 2));

        // 종료 시간, 분
        int endHour = stoi(book_time[i][1].substr(0, 2));
        int endMin = stoi(book_time[i][1].substr(3, 2));

        // 종료시간은 +10분을 더해서 청소시간까지 합계되게 계산 (만약 50분이면 시간을 추가하고 분을 0으로 초기화)
        if (endMin >= 50)
        {
            endHour++;
            endMin %= 10;
        }
        else
            endMin += 10;

        // HH:MM -> HHMM으로 변경하기위헤 시간에 100을 곱해줌
        startHour *= 100;
        endHour *= 100;

        v1.push_back(make_pair(startHour + startMin, endHour + endMin));
    }

    sort(v1.begin(), v1.end());

    // 정렬된 방 사이즈만큼 돌기
    for (int i = 0; i < v1.size(); i++)
    {
        // 방 갯수가 비어있다면 바로 넣어줌
        if (v2.empty())
            v2.push_back(v1[i]);
        else
        {
            // 아니라면 v2만큼 돌아서 종료 시간이 가장 빠른곳의 인덱스랑 시간을 찾음
            int idx = -1;
            int fastTime = 2500;
            for (int j = 0; j < v2.size(); j++)
            {
                if (v2[j].second < fastTime)
                {
                    idx = j;
                    fastTime = v2[j].second;
                }
            }

            // 위에서 구한 가장 빠른 종료시각이랑 현재 시작 시간이랑 비교해서 같거나 크다면 그 방이랑 교체
            if (v2[idx].second <= v1[i].first)
                v2[idx] = v1[i];
            // 아니라면 넣어줌
            else
                v2.push_back(v1[i]);
        }

        int size = v2.size();
        answer = max(answer, size);
    }

    return answer;
}
#endif // 호텔대실LV2

#ifdef 둘만의암호LV1
#include <string>
#include <vector>

using namespace std;


char GetAlphabet(char c, string skip, int idx)
{
    int tmp = c;
    int size = skip.size();

    for (int i = 1; i <= idx; i++)
    {
        tmp++;
        if (tmp > 'z')
            tmp = 'a';

        int idx = 0;
        while (idx < size)
        {
            if (tmp > 'z')
                tmp = 'a';
            if (tmp == skip[idx])
            {
                tmp++;
                idx = 0;
            }
            else
                idx++;
        }
    }

    return tmp;
}

string solution(string s, string skip, int index) {
    string answer = "";

    for (int i = 0; i < s.size(); i++)
        answer.push_back(GetAlphabet(s[i], skip, index));

    return answer;
}
#endif // 둘만의암호LV1

#ifdef 숫자변환하기LV2
#include <string>
#include <vector>

using namespace std;

vector<int> dp;

bool IsDivided(int a, int b)
{
    return a / b > 0 && a % b == 0;
}

int solution(int x, int y, int n) 
{
    dp.resize(y + 1, INT_MAX);
    dp[x] = 0;

    for (int i = x + 1; i < y + 1; i++)
    {
        int a = INT_MAX;
        int b = INT_MAX;
        int c = INT_MAX;

        if (IsDivided(i, 2) && (i / 2) >= x)
            a = dp[i / 2];
        if (IsDivided(i, 3) &&  (i / 3) >= x)
            b = dp[i / 3];
        if ((i - n) >= x)
            c = dp[i  - n];

        int d = min(a, b);
        d = min(d, c);

        dp[i] = d < INT_MAX ? d + 1 : INT_MAX;                                     
    }

    if (dp[y] < INT_MAX)
        return dp[y];
    else
        return -1;
}

#endif // 숫자변환하기LV2

#ifdef 시소짝꿍LV2
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<int> v1 = weights;
    sort(v1.begin(), v1.end());

    for (int i = 0; i < v1.size() - 1; i++)
    {
    }

    return answer;
}
#endif // 시소짝꿍LV2


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef 개인정보수집유효기간LV1
    string today = "2020.01.01";
    vector<string> terms = 
    { "Z 3", 
      "D 5" };
    vector<string> privacies = 
    {   "2019.01.01 D",
        "2019.11.15 Z",
        "2019.08.02 D",
        "2019.07.01 D",
        "2018.12.28 Z" };

    vector<int> answer = solution(today, terms, privacies);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i];

    cout << endl;


#endif // 개인정보수집유효기간LV1
#ifdef 크기가작은부분문자열LV1
    string t = "500220839878";
    string p = "7";

#endif // 크기가작은부분문자열LV1LV1LV1
#ifdef 가장가까운같은글자LV1
    vector<int> answer = solution("baaab");

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;

#endif // 가장가까운같은글자LV1
#ifdef 문자열나누기LV1
    cout << solution("abracadabra") << endl;
    //cout << solution("aaabbaccccabba") << endl;
#endif // 문자열나누기LV1
#ifdef 명예의전당1LV1

    vector<int> tmp = { 10, 100, 20, 150, 1, 100, 200 };
    vector<int> ans = solution(3, tmp);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;


#endif // 명예의전당1LV1
#ifdef 기사단원의무기LV1
    cout << solution(10, 3, 2);
#endif // 기사단원의무기LV1
#ifdef 과일장수LV1
    vector<int> score = { 4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2 };
    cout << solution(4, 3, score);

#endif // 과일장수LV1
#ifdef 무인도여행LV2

    vector<string> maps = { "X591X","X1X5X","X231X", "1XXX1" };
    vector<int> ans = solution(maps);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }

#endif // 무인도여행LV2
#ifdef 뒤에있는큰수찾기LV2
#endif // 뒤에있는큰수찾기LV2
#ifdef 호텔대실LV2

    vector<vector<string>> v =
    {
        //{"15:00", "17:00"} ,{"16:40", "18:20"},{"14:20", "15:20"},{"14:10", "19:20"},{"18:20", "21:20"}
        {"10:00", "10:10"}, {"10:20", "10:30"}
    };

    cout << solution(v) << endl;


#endif // 호텔대실
#ifdef 둘만의암호LV1

    string s = "z";
    string skip = "abcdefghij";
    int index = 20;

    //string s = "aukks";
    //string skip = "wbqd";
    //int index = 5;

    cout << solution(s, skip, index);
#endif // 둘만의암호
#ifdef 숫자변환하기LV2
    cout << solution(2, 5, 4) << endl;
#endif // 숫자변환하기LV2

}