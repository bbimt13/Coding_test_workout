#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::max, std::min 사용
#include <climits>   // INT_MAX, INT_MIN 사용

using namespace std;

int solution(vector<string> arr) {
    int n = (arr.size() + 1) / 2; // 숫자의 개수
    vector<vector<int>> maxDP(n, vector<int>(n, INT_MIN)); // 최댓값 저장
    vector<vector<int>> minDP(n, vector<int>(n, INT_MAX)); // 최솟값 저장

    // 숫자만 있는 경우 초기화
    for (int i = 0; i < n; i++) {
        int num = stoi(arr[i * 2]);
        maxDP[i][i] = num;
        minDP[i][i] = num;
    }

    // 서브표현식을 통해 DP 테이블 채우기
    for (int len = 2; len <= n; len++) { // 서브표현식의 길이
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                int left = k;
                int right = k + 1;
                int opIndex = 2 * k + 1;

                if (arr[opIndex] == "+") {
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i][left] + maxDP[right][j]);
                    minDP[i][j] = min(minDP[i][j], minDP[i][left] + minDP[right][j]);
                } else { // "-"
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i][left] - minDP[right][j]);
                    minDP[i][j] = min(minDP[i][j], minDP[i][left] - maxDP[right][j]);
                }
            }
        }
    }

    return maxDP[0][n - 1]; // 전체 표현식에 대한 최댓값 반환
}

int main() {
    vector<string> arr1 = {"1", "-", "3", "+", "5", "-", "8"};
    cout << "Maximum result of [\"1\", \"-\", \"3\", \"+\", \"5\", \"-\", \"8\"]: " << solution(arr1) << endl;

    vector<string> arr2 = {"5", "-", "3", "+", "1", "+", "2", "-", "4"};
    cout << "Maximum result of [\"5\", \"-\", \"3\", \"+\", \"1\", \"+\", \"2\", \"-\", \"4\"]: " << solution(arr2) << endl;

    return 0;
}
