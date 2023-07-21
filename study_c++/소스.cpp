#include <iostream>
#include < string >
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include <math.h>
#include <unordered_map>

#define LEN_INPUT 1000001

using namespace std;

string solution(string my_string, int n) {
	string answer = "";
	for (int i = 0; i < n; ++i)
	{
		answer.push_back(my_string[i]);
	}
	return answer;
}

vector<int> solutiona(vector<int> numbers, string direction) {
	vector<int> answer;
	int n = 0;

	if (direction == "right")
	{
		n = numbers[numbers.size() - 1];
		answer.push_back(n);
		for (int i = 0; i < numbers.size()-1; ++i)
		{
			answer.push_back(numbers[i]);
		}
	}
	else
	{
		n = numbers[0];

		for (int i = 1; i < numbers.size(); ++i)
		{
			answer.push_back(numbers[i]);
		}
		answer.push_back(n);
	}
	return answer;
}

string solution_Mouse(string letter) {
	string answer = "";
	string go;
	int num = 0;
	int num1 = 0;
	// map에 담아둔다.
	map<string, string> mp{
		{".-","a"},{"-...","b"},{"-.-.","c"},{"-..","d"},
		{".","e"},{"..-.","f"},{"--.","g"},{"....","h"},
		{"..","i"},{".---","j"},{"-.-","k"},{".-..","l"},
		{"--","m"},{"-.","n"},{"---","o"},{".--.","p"},
		{"--.-","q"},{".-.","r"},{"...","s"},{"-","t"},
		{"..-","u"},{"...-","v"},{".--","w"},{"-..-","x"},
		{"-.--","y"},{"--..","z"}
	};
	while (num != letter.size())
	{

		if (letter[num] == ' ' || letter.size()-1 == num)
		{
			while (true)
			{
				
				if (letter[num1] != ' ' && letter.size() != num1)
				{
					go.push_back(letter[num1]);
				}
				else
				{
					answer += mp.find(go)->second;
					num1++;
					go.clear();
					break;
				}
				num1++;
			}
		}
		num++;
	}

	return answer;
}
int solution_Poketmon(vector<int> nums)
{
	vector<int> numsans; 
	if (nums.size() == 0)
		return 0;
	numsans.push_back(nums[0]);
	int Count = 1;
	int Count1 = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < numsans.size(); ++j)
		{
			if (numsans[j] == nums[i])
				Count1++;
		}
		if (Count1 == 0)
		{
			numsans.push_back(nums[i]);
			Count1 = 0;
			Count++;
			if (nums.size() / 2 <= Count)
				return Count;
		}
		else
		{
			Count1 = 0;
		}
	}
	return Count;
}

string atoA(string str)
{
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		// 소문자 변환
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] = tolower(str[i]);

		if ('a' <= str[i] && str[i] <= 'z')
			str[i] = toupper(str[i]);
	}

	cout << str;
	return str;
}
string solutionturn(string my_string, string overwrite_string, int s) {
	string answer = "";
	for (int i = 0; i < my_string.size(); ++i)
	{
		if (i == s)
		{
			--i;
			for (int j = 0; j < overwrite_string.size(); ++j)
			{
				answer.push_back(overwrite_string[j]);
				++i;
			}
		}
		else
		{
			answer.push_back(my_string[i]);
		}

	}

	return answer;
}

int solutionsqure(vector<vector<int>> sizes) {
	int answer = 0;
	int Cul = 0;
	int Row = 0;
	for (int i = 0; i < sizes.size(); ++i)
	{
		if (sizes[i][0] < sizes[i][1])
		{
			int a = sizes[i][1];
			sizes[i][1] = sizes[i][0];
			sizes[i][0] = a;
		}
		if (Row < sizes[i][0])
		{
			Row = sizes[i][0];
		}
		if (Cul < sizes[i][1])
		{
			Cul = sizes[i][1];
		}
	}
	return Row * Cul;
}


int supo(vector<int> _student, vector<int> _answer, int _sort)
{
	int a = 0;
	int re = 0;
	for (int i = 0; i < _answer.size(); ++i)
	{
		if (_answer[i] == _student[a])
			++re;

		if (_student.size() > a)
			++a;
		else
			a = 0;			
	}
	return re;
}


// https://school.programmers.co.kr/learn/courses/30/lessons/42840
vector<int> solutionsupo(vector<int> answers) {
	vector<int> answer;
	vector<int> answer1;
	vector<vector<int>> student = { {1,2,3,4,5}, { 2,1,2,3,2,4,2,5 },{ 3,3,1,1,2,2,4,4,5,5 } };
	
	if (supo(student[0], answers, 0) != 0)
	{
		answer.push_back(1);
	}
		
	if (supo(student[1], answers, 1) != 0)
	{
		answer.push_back(2);
	}
	if (supo(student[2], answers, 2) != 0)
	{
		answer.push_back(3);
	}

	

	sort(answer.begin(), answer.end());



	return answer;
}

void testpercent()
{
	// 랜덤성 검사
	srand(time(nullptr));
	int a = rand();


	int arr = 0;
	vector<int> arr1;
	vector<int> average;
	int count = 0;
	int count1 = 0;
	int breakcount = 0;
	// 벡터 리사이즈
	arr1.resize(28);
	// 모든 벡터 0으로 초기화
	for (int i = 0; i < arr1.size(); ++i)
	{
		arr1[i] = 0;
	}
	// 횟수 진행
	while (true)
	{
		count++;
		// 27개의 숫자 중 랜덤생성
		arr = rand() % 28;

		// 27개의 숫자 중 하나 선택
		if (arr1[arr] == 0)
		{
			arr1[arr] = arr;
		}

		// 모든 숫자가 차있으면 멈춤
		for (int i = 0; i < arr1.size(); ++i)
		{
			if (arr1[i] != 0)
			{
				++breakcount;
			}
		}
		// count1숫자 만큼 반복
		if (breakcount == 27)
		{
			if (count1 == 10000000)
				break;

			++count1;

			arr1.clear();
			arr1.resize(28);
			//cout << count  << "\n";
			average.push_back(count);
			count = 0;
		}
		breakcount = 0;
	}
	int aver = 0;
	for (int i = 0; i < average.size(); ++i)
	{
		aver += average[i];
	}
	aver /= average.size();
}

double Vec2Dist(int x, int y, int _x, int _y)
{
	return sqrt((_x - x) * (_x - x) + (_y - y) * (_y - y));
}

int back_1002(int x1, int y1, int r1, int x2, int y2, int r2)
{
	double dist = Vec2Dist(x1,y1,x2,y2);

	if (dist == 0 && r1 == r2) return -1;
	else if (r1 + r2 == dist || abs(r1 - r2) == dist) return 1;
	else if (abs(r1 - r2) < dist && r1 + r2 > dist) return 2;
	else return 0;
}

int fibonacci(int n) {

	int result = 0;
	int iterA = 0, iterB = 1;

	for (int i = 2; i <= n; i++) {

		
		iterA = iterB;
		iterB = result;
		result = iterA + iterB;
	}

	return result;
}

void fibonacci1(int N)
{
	int last, current, result;
	current = 1, last = result = 0;
	int i;
	for (i = 0; i <= N; i++)
	{
		last = current;
		current = result;
		result = last + current;
	}
	printf("%d %d\n", last, current);
}

int main() {
	
	int num;
	cin >> num;
	int a = 0;
	int b = 0;
	int x;


	for (int i = 0; i < num; ++i)
	{
		cin >> x;
		if (x == 0)
		{
			printf("%d %d\n", 1, 0);
			continue;

		}
		a = fibonacci(x-1);
		b = fibonacci(x);
		printf("%d %d\n", a, b);
	}
	return 0;
}
// float maxValue = std::numeric_limits<float>::max();
