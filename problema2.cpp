#include <iostream>
#include <vector>
#include <climits>

int minMonedas(int cantidad, const std::vector<int>& monedas) {
    std::vector<int> dp(cantidad + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= cantidad; ++i) {
        for (int moneda : monedas) {
            if (i >= moneda && dp[i - moneda] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - moneda] + 1);
            }
        }
    }

    return dp[cantidad] == INT_MAX ? -1 : dp[cantidad];
}

int main() {
    std::vector<int> monedas{1, 3, 4};
    int cantidad = 6;
    std::cout << "Mínimo número de monedas para " << cantidad << ": " << minMonedas(cantidad, monedas) << std::endl;
    return 0;
}

