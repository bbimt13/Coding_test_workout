#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 계산 결과를 반환하는 함수
int calculate(const vector<int>& numbers, const vector<char>& operators, int n) {
    if (n == 1) {
        return numbers[0];
    }

    int result = INT_MIN;
    for (int i = 1; i < n; i++) {
        int left = calculate(numbers, operators, i);
        int right = calculate(vector<int>(numbers.begin() + i, numbers.end()), 
                              vector<char>(operators.begin() + i, operators.end()), 
                              n - i);
        int current = (operators[i - 1] == '+') ? left + right : left - right;
        result = max(result, current);
    }
    return result;
}

// 입력 배열을 숫자와 연산자로 분리하고 최대값을 계산하는 함수
int solution(vector<string>& arr) {
    vector<int> numbers;
    vector<char> operators;

    for (const string& item : arr) {
        if (isdigit(item[0])) {
            numbers.push_back(stoi(item));
        } else {
            operators.push_back(item[0]);
        }
    }

    return calculate(numbers, operators, numbers.size());
}

int main() {
    vector<string> arr1 = {"1", "-", "3", "+", "5", "-", "8"};
    vector<string> arr2 = {"5", "-", "3", "+", "1", "+", "2", "-", "4"};

    cout << "Maximum result for first expression: " << solution(arr1) << endl;
    cout << "Maximum result for second expression: " << solution(arr2) << endl;

    return 0;
}
