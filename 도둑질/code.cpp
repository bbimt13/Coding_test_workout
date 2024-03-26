#include <vector>
#include <algorithm>

int solution(std::vector<int> money) {
    int n = money.size();

    // 첫 번째 집을 터는 경우
    std::vector<int> dp1(n, 0);
    dp1[0] = money[0];
    dp1[1] = std::max(money[0], money[1]);
    for (int i = 2; i < n - 1; ++i) {  // 마지막 집은 털 수 없음
        dp1[i] = std::max(dp1[i - 1], dp1[i - 2] + money[i]);
    }

    // 마지막 집을 터는 경우
    std::vector<int> dp2(n, 0);
    dp2[0] = 0;  // 첫 번째 집을 털지 않음
    dp2[1] = money[1];
    for (int i = 2; i < n; ++i) {  // 마지막 집을 털 수 있음
        dp2[i] = std::max(dp2[i - 1], dp2[i - 2] + money[i]);
    }

    // 두 경우 중 더 큰 값을 선택
    return std::max(dp1[n - 2], dp2[n - 1]);
}