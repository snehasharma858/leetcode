class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       
        vector<int> result;
        
        for (int i = 0; i < nums1.size(); i++) {

            int j = 0;

            while (nums2[j] != nums1[i]) {
                j++;
            }
             int ans = -1;

       
            for (int k = j + 1; k < nums2.size(); k++) {

                if (nums2[k] > nums1[i]) {
                    ans = nums2[k];
                    break;
                }

           
     }
      result.push_back(ans);
        }
            return result;
    }
};