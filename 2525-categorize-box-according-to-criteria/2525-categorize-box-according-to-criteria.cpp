class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long vol = static_cast<long long>(length) * width * height;
        if ((length >= 1e4 || width >= 1e4 || height >= 1e4 || vol >= 1e9) &&
            mass >= 100)
            return "Both";
        else if (length >= 1e4 || width >= 1e4 || height >= 1e4 || vol >= 1e9)
            return "Bulky";
        else if (mass >= 100)
            return "Heavy";
        else
            return "Neither";
    }
};