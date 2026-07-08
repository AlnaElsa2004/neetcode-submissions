class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int i = 0; i < 32; i++) {
            res = res << 1;      // Make space for the next bit
            res = res | (n & 1); // Copy the last bit of n
            n = n >> 1;          // Remove the last bit from n
        }

        return res;
    }
};
