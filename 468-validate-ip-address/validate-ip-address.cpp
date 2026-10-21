class Solution {
public:
    vector<string> split(string s, char delimiter) {
        vector<string> parts;
        string part;

        for (char c : s) {
            if (c == delimiter) {
                parts.push_back(part);
                part = "";
            } else {
                part += c;
            }
        }

        parts.push_back(part);
        return parts;
    }

    bool isIPv4(string s) {
        vector<string> parts = split(s, '.');

        if (parts.size() != 4)
            return false;

        for (string part : parts) {
            if (part.empty() || part.size() > 3)
                return false;

            if (part.size() > 1 && part[0] == '0')
                return false;

            int num = 0;

            for (char c : part) {
                if (!isdigit(c))
                    return false;

                num = num * 10 + (c - '0');
            }

            if (num > 255)
                return false;
        }

        return true;
    }

    bool isIPv6(string s) {
        vector<string> parts = split(s, ':');

        if (parts.size() != 8)
            return false;

        for (string part : parts) {
            if (part.empty() || part.size() > 4)
                return false;

            for (char c : part) {
                if (!isdigit(c) &&
                    !(c >= 'a' && c <= 'f') &&
                    !(c >= 'A' && c <= 'F')) {
                    return false;
                }
            }
        }

        return true;
    }

    string validIPAddress(string queryIP) {
        if (isIPv4(queryIP))
            return "IPv4";

        if (isIPv6(queryIP))
            return "IPv6";

        return "Neither";
    }
};