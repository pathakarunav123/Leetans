class Solution {
set<int> uniqueNumbers;
void generateNumbers(vector<int>& digits, vector<bool>& visited, int num, int count) {
    if (count == 3) {
        if (num % 2 == 0) { 
            uniqueNumbers.insert(num);
        }
        return;
    }
    for (int i = 0; i < digits.size(); i++) {
        if (!visited[i]) {
            if (count == 0 && digits[i] == 0) continue; 
            
            visited[i] = true; 
            generateNumbers(digits, visited, num * 10 + digits[i], count + 1);
            visited[i] = false; 
        }
    }
}
public:
    int totalNumbers(vector<int>& digits) {
        vector<bool> visited(digits.size(), false);
    generateNumbers(digits, visited, 0, 0);
    return uniqueNumbers.size();

    }
};