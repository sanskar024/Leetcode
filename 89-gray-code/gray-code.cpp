class Solution {
public:
    vector<int> grayCode(int n) {
        // Calculate the number of Gray Code values
        int size = 1 << n;

        // Create a vector to store the result
        vector<int> res;
        res.reserve(size);

        // Generate Gray Codes using XOR and right shift
        for (int i = 0; i < size; ++i)
        {
            res.push_back(i ^ (i >> 1));
        }

        // Return the generated sequence
        return res;
    }
};