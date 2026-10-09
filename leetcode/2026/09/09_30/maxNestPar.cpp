class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // Initialize
        int lastStart = 0;
        int lastEnd = 0;
        vector<int> depthOutput = {};
        
        // Traverse Depth
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                if (lastStart == 1) {
                    depthOutput.push_back(0);
                    lastStart = 0;
                }
                else {
                    depthOutput.push_back(1);
                    lastStart = 1;
                }
            }
            else {
                if (lastEnd == 1) {
                    depthOutput.push_back(0);
                    lastEnd = 0;
                }
                else {
                    depthOutput.push_back(1);
                    lastEnd = 1;
                }
            }
        }

        return depthOutput;
    }
};