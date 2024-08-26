#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution{
    public:
        std::unordered_map<int, std::unordered_set<int>> friends;
        std::vector<int> res;
        std::vector<int> solution(std::vector<std::vector<int>>& connections){
            res.resize(connections.size(), 0);
            for (const auto& connection: connections){
                friends[connection[0]].insert(connection[1]);
                friends[connection[1]].insert(connection[0]);
            }
            int index = 0;
            // for (const auto& friend_: friends){
            //     std::cout << "index " << index << "has friend: ";
            //     for (const auto& each: friend_){
            //         std::cout << each;
            //     }
            //     std::cout << std::endl;
            //     index++;
            // }
            for (const auto& each: friends){
                std::unordered_map<int, int> counter;
                int cur_ppl = each.first;
                for (const auto& each_friend: each.second){
                    for (const auto& each_friend_of_friend: friends[each_friend]){
                        if (each_friend_of_friend != cur_ppl){
                            counter[each_friend_of_friend]++;
                        }
                    }
                }
                int min_index = INT_MAX;
                int max_count = INT_MIN;
                for (const auto& each: counter){
                    if (each.second > max_count){
                        max_count = each.second;
                        if (each.first < min_index){
                            min_index = each.first;
                        }
                    }
                }
                // res.push_back(min_index);
                res[cur_ppl] = min_index;
            }
            return res;
        }
};
int main(){
    std::vector<std::vector<int>> connections = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3},
        {3, 4},
    };
    Solution sln;
    std::vector<int> res = sln.solution(connections);
    for (const auto& each: res){
        std::cout << each << std::endl;
    }
    return 0;
}