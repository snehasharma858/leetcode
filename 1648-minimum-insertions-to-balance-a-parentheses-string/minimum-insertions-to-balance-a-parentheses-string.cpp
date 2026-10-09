
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open++;
            }
            else {
                // Check whether the next character is ')'
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;  // Consume both ')'

                    if (open > 0) {
                        open--;
                    } else {
                        insertions++; // Insert '('
                    }
                }
                else {
                    // Insert one ')' to complete the pair
                    insertions++;

                    if (open > 0) {
                        open--;
                    } else {
                        insertions++; // Insert '('
                    }
                }
            }
        }

        // Every remaining '(' needs two ')'
        insertions += open * 2;

        return insertions;
    }
};
