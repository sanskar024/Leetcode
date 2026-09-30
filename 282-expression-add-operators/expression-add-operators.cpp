    class Solution {
public:
    void backtrack(string num, long long target, int index,
                   long long value, long long prev,
                   string expression, vector<string>& ans) {

        if (index == num.length()) {
            if (value == target) {
                ans.push_back(expression);
            }
            return;
        }

        for (int i = index; i < num.length(); i++) {

            // Avoid numbers with leading zeros
            if (i > index && num[index] == '0') {
                break;
            }

            long long curr = stoll(num.substr(index, i - index + 1));

            // First number
            if (index == 0) {

                backtrack(
                    num, target, i + 1,
                    curr, curr,
                    expression + to_string(curr),
                    ans
                );

            } else {

                // Addition
                backtrack(
                    num, target, i + 1,
                    value + curr, curr,
                    expression + "+" + to_string(curr),
                    ans
                );

                // Subtraction
                backtrack(
                    num, target, i + 1,
                    value - curr, -curr,
                    expression + "-" + to_string(curr),
                    ans
                );

                // Multiplication
                backtrack(
                    num, target, i + 1,
                    value - prev + prev * curr,
                    prev * curr,
                    expression + "*" + to_string(curr),
                    ans
                );
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;

        backtrack(
            num,
            target,
            0,
            0,
            0,
            "",
            ans
        );

        return ans;
    }
};