class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<string, vector<string>> map_data;
        for (auto str_tmp : strs){
            string s_key = str_tmp;
            sort(s_key.begin(), s_key.end());
            if (map_data.count(s_key) > 0){
                map_data.at(s_key).push_back(str_tmp);
            }
            else
            {
                map_data.insert(std::make_pair(s_key, vector<string>(1, str_tmp)));
            }
        }

        vector<vector<string>> vct_ret;
        for (auto it_map = map_data.begin(); it_map != map_data.end(); ++ it_map){
            vct_ret.push_back(it_map->second);
        }

        return vct_ret;
    }
};