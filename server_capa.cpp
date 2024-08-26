#include <iostream>
#include <vector>

class Solution{
    public:
        int solution(std::vector<int>& capa){
            int width = capa.size();
            std::vector<std::vector<int>> dp(width, std::vector<int>(width, 0));
            dp[0][0] = capa[0];
            int count = 0;
            for (int left = 0; left < width; left++){
                for (int right = left + 1; right < width; right++){
                    if (dp[left][right - 1]){
                        dp[left][right] = dp[left][right - 1] + capa[right];
                    }
                    else if (dp[left - 1][right]){
                        dp[left][right] = dp[left - 1][right] - capa[left];
                    }
                    
                }
            }
            for (int row = 0; row < width; row++){
                for (int col = 0; col < width; col++){
                    if (dp[row][col] == 0){
                        continue;
                    }
                    else{
                        if (capa[row] == capa[col] && capa[row] == dp[row][col]){
                            count++;
                        }
                    }
                }
            }
            return count;
        }
};
int main(){
    std::vector<int> capa = {9, 3, 3, 3, 9};
    Solution sln;
    int res = sln.solution(capa);
    std::cout<< "the ans is : " << res << std::endl;
    return 0;
}