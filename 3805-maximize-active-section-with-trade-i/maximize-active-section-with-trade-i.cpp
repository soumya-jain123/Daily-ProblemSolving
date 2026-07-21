class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOne = 0;
        int n = s.length();
        int currentIdx = 0;
        int previousZeroSeg = INT_MIN;
        int maxZeroWin = 0;

        while(currentIdx < n){
            int segmentIdx = currentIdx + 1;
            while(segmentIdx < n && s[segmentIdx] == s[currentIdx])
                segmentIdx++;

            int segLen = segmentIdx - currentIdx;
            if(s[currentIdx] == '1')
                totalOne += segLen;
            else{
                maxZeroWin = max(maxZeroWin, previousZeroSeg + segLen);
                previousZeroSeg = segLen;
            }

            currentIdx = segmentIdx;
        }

        return totalOne + maxZeroWin;
    }
};