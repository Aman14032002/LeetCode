class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     map< int, int> aman;
     for (auto it: nums){
         aman[it]++;

     }
      vector<pair<int, int>> val(aman.begin(), aman.end());
      vector<int> v;
      sort(val.begin(),val.end(),[](auto &x,auto &y) {return x.second> y.second;});
      auto i = val;
      for( int i=0;i<k;i++){
          v.push_back(val[i].first);
      }

      
      return v;
}
};


       