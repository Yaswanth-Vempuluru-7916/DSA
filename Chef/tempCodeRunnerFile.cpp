long long countSubarrays(vector<long long> v) {
//     long long even = 0;
//     vector<vector<long long>> ans;

//     for (long long i = 0; i < v.size(); i++) {
//         vector<long long> sub;
//         for (long long j = i; j < v.size(); j++) {
//             sub.push_back(v[j]);  // Fixed the index to v[j]
//             even += (v[j] % 2 == 0);  // Increment even if element is even
//         }
//         ans.push_back(sub);
//     }

//     return even;
// }