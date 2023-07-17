#include "DefineSolutionList.h"
#include <iostream>

using namespace std;

#ifdef Programmers
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
            for (int j = 0; j < v2.size(); j++)
            {
                if (v2[j].second < v2[idx].second)
                    idx = j;
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
#include <algorithm>

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


#ifdef 추억점수LV1
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;
    map<string, int> m;
    
    for (int i = 0; i < name.size(); i++)
        m[name[i]] = yearning[i];

    for (int i = 0; i < photo.size(); i++)
    {
        int total = 0;
        for (int j = 0; j < photo[i].size(); j++)
            total += m[photo[i][j]];

        answer.push_back(total);
    }

    return answer;
}

#endif // 추억점수LV1


#ifdef 시소짝꿍LV2
#include <string>
#include <vector>
#include <algorithm>
#include <map>
>>>>>>> origin/main

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

#ifdef 두원사이의정수쌍LV2
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int GetPointBesideCircle(int r1, int r2)
{
	if (r1 == r2)
		return 0;

	int cnt = 0;

	for (int x = 0; x <= r2; x++)
	{
		if (x == 0)
			cnt += r2 - r1 + 1;
		else
		{

		}
	}

	return cnt * 4;
}


long long solution(int r1, int r2) 
{
	long long answer = 0;

	answer = GetPointBesideCircle(r1, r2);

	return answer;
}
#endif //두원사이의정수쌍LV2
#endif // Programmers

#ifdef Backjun

#ifdef 캠핑_4796
void solution()
{
	int l, p, v, idx = 0;

	while (true)
	{
		cin >> l;	// 5
		cin >> p;	// 8
		cin >> v;	// 20

		int answer = (v / p) * l + min(v % p, l);

		cout << "Case " << ++idx << ": " << answer << endl;
	}
}
#endif // 캠핑_4796

#ifdef 설탕배달_2839

void solution()
{
	int k = 0;
	cin >> k;
	int answer = 0;

	while (k >= 0)
	{
		if (k % 5 == 0)
		{
			answer += k / 5;
			cout << answer << endl;
			return 0;
		}
		k -= 3;
		answer++;
	}

	cout << -1 << endl;

	return 0;
}

#endif // 설탕배달_2839

#ifdef 회의실배정_1931

#include <vector>
#include <algorithm>

void solution()
{
	int k;
	vector<pair<int, int>> timeTable;

	cin >> k;

	// 타임 테이블 담기
	for (int i = 0; i < k; i++)
	{
		int a, b = 0;
		cin >> a;
		cin >> b;

		timeTable.push_back({ b,a });
	}

	// 종료 시점으로 오름차순 정렬
	sort(timeTable.begin(), timeTable.end());

	int cnt = 1;					// 회의실 카운트
	int time = timeTable[0].second;	// 현재 회의실의 종료 시간

	// 타임테이블만큼 돌아서
	for (int i = 1; i < k; i++)
	{
		if (timeTable[i].first >= time)
		{
			cnt++;
			time = timeTable[i].second;
		}
	}

	cout << cnt << endl;
}

#endif // 회의실배정_1931

#ifdef 동전제로_11047
#include <vector>
void solution()
{
	int n, k, answer = 0;
	cin >> n >> k;

	vector<int> v;
	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int idx = n - 1;

	while (k > 0)
	{
		if (k / v[idx] > 0)
		{
			answer += k / v[idx];
			k %= v[idx];
		}
		--idx;
	}

	cout << answer << endl;
}

#endif // 동전제로_11047

#ifdef 잃어버린_괄호_1541

#include <string>

void solution()
{
	int answer = 0;
	int add = 0;
	string s = "";
	string num = "";
	bool isMinus = false;

	// 식 입력
	cin >> s;					

	// 입력받은 식 전부 조사
	for (int i = 0; i <= s.size(); i++)
	{
		// 문자 가져옴
		char c = s[i];

		// 숫자면 num에 넣어줌
		if ('0' <= c && c <= '9')
			num += c;
		// 아니라면
		else
		{
			if (isMinus)
				answer -= stoi(num);
			else
				answer += stoi(num);

			// -가 단한번이라도 나오면 변경해줌
			if (c == '-')
				isMinus = true;

			num = "";
		}
	}

	cout << answer << endl;
}

#endif // 잃어버린_괄호_1541

#ifdef 보물_1026

#include <vector>
#include <algorithm>

void solution()
{
	int s, answer = 0;
	vector<int> a;
	vector<int> b;
	cin >> s;

	a.resize(s);
	b.resize(s);

	for (int i = 0; i < s; i++)
		cin >> a[i];

	for (int i = 0; i < s; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	for (int i = 0; i < a.size(); i++)
		answer += a[i] * b[i];

	cout << answer << endl;
}

#endif // 보물_1026

#ifdef 거스름돈_5585
#include <vector>

void solution()
{
	vector<int> v = { 500, 100, 50, 10, 5 ,1 };
	int n, answer = 0;
	cin >> n;
	n = 1000 - n;

	for (int i = 0; i < v.size(); i++)
	{
		if (n / v[i] > 0)
		{
			answer += n / v[i];
			n %= v[i];
		}
	}

	cout << answer << endl;
}

#endif // 거스름돈_5585

#ifdef 로프_2217
#include <vector>
#include <algorithm>

void solution()
{
	vector<int> v1, v2;
	int n;

	cin >> n;
	v1.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v1[i];

	// 내림차순으로 정렬
	sort(v1.begin(), v1.end(), greater<int>());

	// 중량 순으로 로프를 묶어서 최대 하중을 구함
	for (int i = 0; i < v1.size(); i++)
		v2.push_back(v1[i] * (i + 1));

	// 구한 최대 하중을 내림차순으로 정렬
	sort(v2.begin(), v2.end(), greater<int>());

	// 가장 큰 값이 최대로 버틸 수 있는 무게이므로 맨 앞의 값을 출력
	cout << v2[0] << endl;
}


#endif // 로프_2217

#ifdef 수들의합_1789

void solution()
{
	long long n;
	long long k = 1;
	long long sum = 0;
	int cnt = 0;
	cin >> n;

	while (true)
	{
		sum += k;
		k++;
		if (sum > n)
		{
			k--;
			break;
		}
	}

	cout << k << endl;
}
#endif // 수들의합_1789

#ifdef 주유소_13305
#include <vector>


void solution()
{
	int n;						// 도시 개수
	int lowCost = 0;			// 가장 저렴한 주유소 가격
	int lowIdx = 0;				// 가장 저렴한 주유소 위치
	long long totalCost = 0;	// 총 이동 비용
	vector<int> dist;			// 도시 간의 거리
	vector<int> cost;			// 주유소의 리터당 가격

	cin >> n;
	dist.resize(n - 1);
	cost.resize(n);

	for (int i = 0; i < dist.size(); i++)
		cin >> dist[i];

	for (int i = 0; i < cost.size(); i++)
		cin >> cost[i];

	totalCost += dist[0] * cost[0];		// 첫 도시는 무조건 이동
	lowCost = cost[0];					// 가장 저렴한곳은 처음임

	for (int i = 1; i < dist.size(); i++)
	{
		// 가격 비교하기
		// 만약 가장 싼 주유소가 다음 주유소보다 저렴하다면
		if (lowCost < cost[i])
		{
			// 가장 싼 주유소 가격에 현재 거리만큼 곱해줌
			totalCost += dist[i] * lowCost;
		}
		// 아니라면
		else
		{
			// 가장 싼 주유소의 위치와 가격을 저장
			lowCost = cost[i];
			lowIdx = i;
			totalCost += dist[i] * lowCost;
		}
	}

	cout << totalCost << endl;
}

#endif // 주유소_13305

#ifdef 계산기_10162

void solution()
{
	int t;
	cin >> t;

	int a = 0;
	int b = 0;
	int c = 0;

	if (t % 10 != 0)
	{
		cout << -1 << endl;
	}
	else
	{
		while (t != 0)
		{
			if (t / 300 > 0)
			{
				a += t / 300;
				t %= 300;
			}
			else if (t / 60 > 0)
			{
				b += t / 60;
				t %= 60;
			}
			else if (t / 10 > 0)
			{
				c += t / 10;
				t %= 10;
			}
		}
		cout << a << " " << b << " " << c << endl;
	}
}

#endif // 계산기_10162

#ifdef 삼십_10610
#include <string>
#include <vector>
#include <algorithm>

void solution()
{
	string s = "";
	cin >> s;
	vector<int> v;
	int sum = 0;

	for (int i = 0; i < s.size(); i++)
	{
		v.push_back(s[i] - '0');
		sum += v[i];
	}

	sort(v.begin(), v.end(), greater<int>());

	if (sum % 3 == 0 && v[v.size() - 1] == 0)
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
	else
		cout << -1;
}

#endif // 삼십_10610

#ifdef A에서B_16953

void solution()
{
	int A, B;
	int cnt = 0;
	cin >> A >> B;

	while (true)
	{
		if (A > B)
		{
			cout << -1;
			break;
		}
		if (A == B)
		{
			cnt++;
			cout << cnt;
			break;
		}

		if (B % 10 == 1)
		{
			B--;
			B /= 10;
		}
		else if (B % 2 == 0)
		{
			B /= 2;
		}
		else
		{
			cout << -1;
			break;
		}

		cnt++;
	}
}

#endif // A에서B_16953

#ifdef 뒤집기_1439
#include <string>
#include <algorithm>>

void solution()
{
	string s = "";
	cin >> s;

	int zeroCount = 0;
	int firstCount = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == s[i+1])
		{
			if (s[i] == '0')
				++zeroCount;
			else
				++firstCount;
		}
	}

	cout << min(zeroCount, firstCount);
}

#endif // 뒤집기_1439

#ifdef 세탁소사장동혁_2720

void solution()
{
	int T;

	cin >> T;

	while (T--)
	{
		int money;
		cin >> money;

		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;

		while (money)
		{
			if (money / 25 > 0)
			{
				a = money / 25;
				money %= 25;
			}
			else if (money / 10 > 0)
			{
				b = money / 10;
				money %= 10;
			}
			else if (money / 5 > 0)
			{
				c = money / 5;
				money %= 5;
			}
			else if (money / 1 > 0)
			{
				d = money / 1;
				money %= 1;
			}
		}
		cout << a << " " << b << " " << c << " " << d << endl;
	}
}

#endif // 세탁소사장동혁_2720

#ifdef 기타줄_1049

#include <algorithm>

void solution()
{
	int n, m;
	int minSetPrice = 1001, minUnitPrice = 1001;
	int totalMoney = 0;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int curSetPrice, curUnitPrice;
		cin >> curSetPrice >> curUnitPrice;

		minSetPrice  = min(minSetPrice, curSetPrice);
		minUnitPrice = min(minUnitPrice, curUnitPrice);
	}

	while (true)
	{
		// 기타줄이 6개 이상일 때
		if (n >= 6)
		{
			
			if (minSetPrice > minUnitPrice * 6)			// 세트 가격이 낱개 * 6보다 비싸다면
				totalMoney += minUnitPrice * 6;			// 총 가격에 낱개 * 6 가격을 더해줌
			else										// 세트 가격이 낱개 * 6보다 싸다면
				totalMoney += minSetPrice;				// 총 가격에 세트 가격을 더해줌

			n -= 6;										// 계산해야되는 기타줄 개수 -6
		}
		// 기타줄이 6개 미만일 때
		else
		{
			int totalUnitPrice = minUnitPrice * n;		// 낱개 총 가격을 구해줌

			if (minSetPrice > totalUnitPrice)			// 세트 가격이 낱개 총 가격보다 비싸다면
				totalMoney += totalUnitPrice;			// 총 가격에 낱개 총 가격을 더해줌
			else										// 세트 가격이 낱개 총 가격보다 싸다면
				totalMoney += minSetPrice;				// 총 가격에 세트 가격을 더해줌

			// 더이상 기타줄 가격 계산을 안해도 되므로 break
			break;
		}
	}

	cout << totalMoney << endl;
}

#endif // 기타줄_1049

#ifdef 수묶기_1744
#include <vector>
#include <algorithm>

void solution()
{
	//내 답 (오답)
	{
		/*vector<int> v;
		int n;
		cin >> n;

		v.resize(n);

		for (int i = 0; i < n; i++)
			cin >> v[i];

		sort(v.begin(), v.end(), greater<int>());
		int sum = 0;

		while (true)
		{
			if (v.size() == 1)
			{
				sum += v.front();
				break;
			}
			else if (v.empty())
			{
				break;
			}
			else
			{
				int a = v[0];
				int b = v[1];

				if (a > 0)
				{
					if (b > 0)
					{
						sum += (a * b);
						v.erase(v.begin());
						v.erase(v.begin());
					}
					else
					{
						sum += a;
						v.erase(v.begin());
					}
				}
				else if (a == 0)
				{
					if (v.size() > 2)
						v.erase(v.begin());
					else
					{
						sum += (a * b);
						v.erase(v.begin());
						v.erase(v.begin());
					}
				}
				else
				{
					sum += (a * b);
					v.erase(v.begin());
					v.erase(v.begin());
				}
			}
		}*/
	}

	// 정답
	// 알고리즘
	// 양수, 음수 끼리 모아주고 0의 갯수도 따로 카운트
	// 1이면 그냥 sum에 더해줌
	// 양수는 내림차순으로 정렬해서 원소 갯수가 짝수면 가장 앞 원소랑 그 다음 원소끼리 곱해줌
	// 음수는 오름차순으로 정렬해서 원소 갯수가 짝수면 가장 앞 원소랑 그 다음 원소끼리 곱해줌
	// 남은 음수 갯수가 홀수일 때 0 갯수만큼 곱해서 남은 음수를 0으로 만들어줌

	vector<int> p;		// 양수 모음
	vector<int> m;		// 음수 모음
	int zeroCnt = 0;	// 0의 갯수
	int sum = 0;		// 총 더한 값

	int n, k;			// 수열 크기, 입력받을 수열 값
	cin >> n;			// 수열 크기 입력

	// 들어온 값 분류
	for (int i = 0; i < n; i++)
	{
		cin >> k;				// 수열 값 입력
		if (k > 1)				// 위의 알고리즘 대로 분류
			p.push_back(k);
		else if (k == 1)
			sum += 1;
		else if (k == 0)
			zeroCnt++;
		else
			m.push_back(k);
	}

	sort(p.begin(), p.end(), greater<int>());	// 양수 내림차순 정렬
	sort(m.begin(), m.end());					// 음수 오름차순 정렬

	// 양수
	while (true)
	{
		if (p.size() > 1)
		{
			if (p[0] != 1)
			{
				sum += (p[0] * p[1]);
				p.erase(p.begin());
				p.erase(p.begin());
			}
			else
			{
				sum += 1;
				p.erase(p.begin());
			}
		}
		else
		{
			if (p.size() == 1)
				sum += p[0];

			break;
		}
	}

	// 음수
	while (true)
	{
		if (m.size() > 1)
		{
			sum += (m[0] * m[1]);
			m.erase(m.begin());
			m.erase(m.begin());
		}
		else
		{
			if (m.size() == 1)
			{
				if (!zeroCnt)
					sum += m[0];
			}
			break;
		}
	}


	cout << sum << endl;
}

#endif // 수묶기_1744

#ifdef 강의실배정_11000
#include <vector>
#include <algorithm>
#include <queue>

bool cmp(pair<int, int> p, pair<int, int> q)
{
	if (p.second < q.second)
		return true;
	
	return false;
}

void solution()
{
	/*
		알고리즘
		준비물 : 타임테이블 담을 벡터, 수업중인 강의실 담을 벡터, 총 강의실 갯수

		1. 타임 테이블을 입력받아서 수업 시작시간, 종료시간을 pair로 vector에 저장한다.
		2. 종료시간이 가장 빠른 순으로 정렬한다.
		3. 현재 수업과 현재 강의중인 강의실을 조사해서 종료시간이 가장 빠른 강의실을 찾는다.
		4. 해당 강의실의 수업 종료시간보다 현재 수업의 시작시간이 크다면 (2 < 4)
		5. 해당 강의실에 이 수업을 넣는다 (해당 수업이 종료되고 바로 현재 수업을 진행할 수 있음)
		6. 아니라면 새 강의실을 잡아준다 (push_back)
	*/

	// 내 풀이 (오답인데 왜?)
	{
		//vector<pair<int, int>> timeTable;	// 타임테이블 담을 벡터
		//vector<pair<int, int>> classRoom;	// 수업중인 강의실
		//int a, b, c;						// 수업 갯수, 수업 시작 시간, 수업 종료 시간
		//int maxClassRoom = 0;				// 총 강의실 갯수

		//// 전부 입력 받기
		//cin >> a;
		//for (int i = 0; i < a; i++)
		//{
		//	cin >> b >> c;
		//	timeTable.push_back({ b,c });
		//}

		//sort(timeTable.begin(), timeTable.end(), cmp);	// 종료시간이 빠른 순으로 정렬
		//classRoom.push_back(timeTable[0]);				// 첫 수업은 바로 강의실 잡아줌

		//// 수업 배치하기
		//for (int i = 1; i < timeTable.size(); i++)
		//{
		//	int idx = 0;											// 종료시간이 가장 빠른 강의실 인덱스 저장용
		//	for (int j = 0; j < classRoom.size(); j++)				// 현재 수업중인 강의실 조사해서
		//	{
		//		if (classRoom[j].second < classRoom[idx].second)	// 저장해놨던 종료 시간이 현재 저장한 가장 빠른강의실보다 빠르다면
		//			idx = j;										// 해당 강의실의 인덱스 저장해줌
		//	}

		//	if (classRoom[idx].second <= timeTable[i].first)		// 종료시간이 가장 빠른 강의실 <= 현재 수업 시작 시간 (2 <= 3)
		//	{
		//		classRoom[idx] = timeTable[i];						// 해당 강의실을 현재 수업으로 변경
		//	}
		//	else													// 종료시간이 가장 빠른 강의실 > 현재 수업 시작 시간 (2 > 1)
		//	{
		//		classRoom.push_back(timeTable[i]);					// 강의실을 새로 잡아줌
		//	}
		//	int curClassRoomSize = classRoom.size();				// 현재 수업중인 강의실 갯수
		//	maxClassRoom = max(maxClassRoom, curClassRoomSize);		// 큰값 저장
		//}

		//cout << maxClassRoom << endl;
	}

	// pq로 풀기
	vector<pair<int, int>> timeTable;						// 수업 시간표
	priority_queue<int, vector<int>, greater<int>> pq;		// 우선순위큐 (종료시간이 가장 빠른 순)
	int a, b, c;	// 입력받을 값

	cin >> a;

	for (int i = 0; i < a; i++)
	{
		cin >> b >> c;
		timeTable.push_back({ b,c });
	}

	sort(timeTable.begin(), timeTable.end());
	pq.push(timeTable[0].second);

	for (int i = 1; i < timeTable.size(); i++)
	{
		pq.push(timeTable[i].second);

		if (pq.top() <= timeTable[i].first)
			pq.pop();
	}

	cout << pq.size() << endl;
}

#endif // 강의실배정_11000

#ifdef 수리공항승_1449
// 다시한번 풀것
#ifdef 행렬_1080
#include <vector>

void solution()
{
	vector<vector<int>> v1;
	vector<vector<int>> v2;
	int cnt = 0;
	int n, m;
	cin >> n >> m;

	v1.resize(n, vector<int>(m, 0));
	v2.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> v1[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> v2[i][j];
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (v1[i][j] != v2[i][j])
			{
				for (int k = i; k <= i + 2; k++)
				{
					for (int l = j; l <= j + 2; l++)
					{
						v1[k][l] = 1 - v2[k][l];
					}
				}
				cnt++;
			}
			else
				continue;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v1[i][j] != v2[i][j])
			{
				cout << "-1" << endl;
				break;
			}
		}
	}

	cout << cnt << endl;
}

#endif // 행렬_1080

#ifdef 거스름돈_14916

void solution()
{
	int n, ans = 0;
	cin >> n;

	while (n > 0)
	{
		if (n % 5 == 0)
		{
			cout << (n / 5) + ans << endl;
			break;
		}
		ans++;
		n -= 2;
	}

	cout << -1 << endl;
}

#endif // 거스름돈_14916

#ifdef 저울_2437
>>>>>>> origin/main
#include <vector>
#include <algorithm>

void solution()
{
	// 재료 및 입력받기
	vector<int> v;
	int N, L;
	cin >> N >> L;
	vector<int> v;
	int N, ans = 0;

	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	// 오름차순으로 정렬
	sort(v.begin(), v.end());

	// 길이 구하기
	int start = v[0];		// 시작 위치
	int ans = 0;			// 테이크 갯수

	// 누수 위치만큼 조사
	for (int i = i; i < v.size(); i++)
	{
		if (L <= v[i] - start)		// 테이프 길이 <= 조사지역 - 시작지역 (3 <= 2 - 1이면 길이가 1 모자름)
		{
			ans++;
			start = v[i];
		}
	sort(v.begin(), v.end());
	
	// 누적합 계산이라는데 좀 더 공부할 것
	// https://novlog.tistory.com/entry/CC-BOJ%EB%B0%B1%EC%A4%80-2437-%EC%A0%80%EC%9A%B8-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > ans + 1)
			break;

		ans += v[i];
	}

	cout << ans + 1 << endl;
}

#endif // 저울_2437

#ifdef 게임을만든동준이_2847
#include <vector>

void solution()
{
	vector<int> v;
	int n, ans = 0;
	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = v.size() - 2; i >= 0;)
	{
		if (v[i] >= v[i + 1])
		{
			--v[i];
			++ans;
		}
		else
			--i;
	}

	cout << ans << endl;
}
#endif // 수리공항승_1449

#ifdef 오와육의차이_2864

void solution()
{
	int A, B;
	cin >> A >> B;

	int minA = 0, minB = 0, maxA = 0, maxB = 0;
	int pow = 1;

	// A
	while (A > 0)
	{
		int digit = A % 10;

		if (digit == 5)
		{
			minA += digit * pow;
			maxA += 6 * pow;
		}
		else if (digit == 6)
		{
			minA += 5 * pow;
			maxA += digit * pow;
		}
		else
		{
			minA += digit * pow; 
			maxA += digit * pow;
		}
		A /= 10;
		pow *= 10;
	}

	pow = 1;
	// B
	while (B > 0)
	{
		int digit = B % 10;

		if (digit == 5)
		{
			minB += digit * pow;
			maxB += 6 * pow;
		}
		else if (digit == 6)
		{
			minB += 5 * pow;
			maxB += digit * pow;
		}
		else
		{
			minB += digit * pow;
			maxB += digit * pow;
		}
		B /= 10;
		pow *= 10;
	}

	cout << minA + minB << " " << maxA + maxB << endl;
}

#endif // 오와육의차이_2864

#define 팰린드롬만들기_1213
#include <string>

void solution()
{
	int alphabet[26] = { 0, };
	int oddcnt = 0;
	int mid_idx = 999;

	string s = "";
	cin >> s;

	for (int i = 0; i < s.size(); i++)
		alphabet[s[i] - 'A']++;

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] > 0)
		{
			if (alphabet[i] % 2 == 1)
			{
				alphabet[i]--;
				oddcnt++;
				mid_idx = i;
			}
		}
	}

	if (oddcnt > 1)
	{
		cout << "I'm Sorry Hansoo" << endl;
		return;
	}
	
	string ans = "";
	string rev = "";

	for (int i = 0; i < 26; i++)
		if (alphabet[i] > 0)
			for (int j = 0; j < alphabet[i] / 2; j++)
				ans += i + 'A';

	rev = ans;
	reverse(rev.begin(), rev.end());

	if (mid_idx != 999)
		ans += alphabet[mid_idx] + 'A';

	ans += rev;

	cout << rev << endl;
}

#endif // 게임을만든동준이_2847

#endif // Backjun

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
    { "2019.01.01 D",
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
        //string s = "z";
        //string skip = "abcdefghij";
        //int index = 20;
    string s = "z";
    string skip = "abcdefghij";
    int index = 20;

        //string s = "aukks";
        //string skip = "wbqd";
        //int index = 5;

        char c = 'z';
    c += 20;
    c -= 26;
    c += 10;
    c -= 26;
    cout << c << endl;

    //cout << solution(s, skip, index);
    cout << solution(s, skip, index);
#endif // 둘만의암호
#ifdef 숫자변환하기LV2
    cout << solution(2, 5, 4) << endl;
#endif // 숫자변환하기LV2

#ifdef 추억점수LV1
    vector<string> name = { "may", "kein", "kain", "radi" };
    vector<int> yearning = { 5, 10, 1, 3 };
    vector<vector<string>> photo =
    { {"may", "kein", "kain", "radi"}, {"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"} };

    vector<int> answer = solution(name, yearning, photo);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;


#endif // 추억점수LV1


	
	solution();
	system("pause");

}