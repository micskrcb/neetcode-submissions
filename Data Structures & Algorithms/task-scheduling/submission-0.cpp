class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int max_freq = 0;
        for (char t : tasks) {
            freq[t - 'A']++;
            max_freq = max(max_freq, freq[t - 'A']);
        }
        
        // Count how many tasks have the max frequency
        int max_freq_count = 0;
        for (int f : freq) {
            if (f == max_freq) max_freq_count++;
        }
        
        // The formula: 
        // We have (max_freq - 1) blocks of size (n + 1).
        // The last row has 'max_freq_count' tasks.
        int result = (max_freq - 1) * (n + 1) + max_freq_count;
        
        // The result cannot be smaller than the total number of tasks
        return max((int)tasks.size(), result);
    }
};