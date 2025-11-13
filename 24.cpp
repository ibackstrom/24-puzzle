#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include "tinyexpr.h" 
using namespace std;

vector<string> gen(int n) {
    if (n == 1) return {"%d"};
    vector<string> res;
    for (int l = 1; l < n; ++l)
        for (const auto& a : gen(l))
            for (const auto& b : gen(n - l))
                res.emplace_back("(" + a + "%c" + b + ")");
    return res;
}
const vector<string> PATTERNS = gen(4);

string solve_24(vector<int> nums) {
    sort(nums.begin(), nums.end());
    do {
        int a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        for (char o1 : string("+-*/"))
        for (char o2 : string("+-*/"))
        for (char o3 : string("+-*/"))
        for (const auto& pat : PATTERNS) {
            char expr[100];
            snprintf(expr, sizeof(expr), pat.c_str(), a, o1, b, o2, c, o3, d);
            if (strstr(expr, "/0")) continue;
            double r = te_interp(expr, 0);
            if (fabs(r - 24) < 1e-9)
                return expr;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    return "No solution";
}

int main() {
    cout << solve_24({1, 3, 4, 6}) << '\n';
    return 0;
}
