#include <stdio.h>

#define MOD 12345
int countSequences(int n) {
    if (n == 1) return 2; 
    if (n == 2) return 4;  
    int dp[n+1];
        dp[1] = 2;  
    dp[2] = 4;  
    dp[3] = 7; 
    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }
    return dp[n];
}
int main() {
    int n;
    printf("Введіть довжину послідовностей n (1 < n < 10000): ");
    scanf("%d", &n);

    if (n <= 1 || n >= 10000) {
        printf("Некоректне значення n. Повинно бути в діапазоні 1 < n < 10000.\n");
        return 1;
    }
    int result = countSequences(n);
    printf("Кількість послідовностей довжиною %d: %d\n", n, result);
    return 0;
}
