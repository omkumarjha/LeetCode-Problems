class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2){

		/* 
		// First approach jisme pehle dono arrays ko sort karliya uske baad wahi concept "Intesection of two sorted arrays" wala concept laga diya
        
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());

    vector<int> output;
		int i = 0, j = 0;
    int n = nums1.size();
    int m = nums2.size();

		while(i < n && j < m){
			if(nums1[i] == nums2[j]){
				output.push_back(nums1[i]);
				i++;
				j++;
			}
			else if(nums1[i] < nums2[j]){
				i++;
			}
			else{
				j++;
			}
		}
	    return output;

		*/

		// Second approach jims hum space use karenge (hash Map)

		map<int,int> m;
		vector<int> output;

		// first array ke elements ki occurence ko hum store kar rahe hai 
		for(auto num : nums1){
				m[num]++;
		}

		// bas isme mai num2 ka individual element nikal raha hoon aur check kar raha hoon ki agar woh element map mai hua to fir uski jo occurence value hai usko eak se decrement kardo and uss element ko vector mai add bhi kardo because that is one of the answer.

		for(auto num : nums2){
				if(m.count(num)){
						auto itr = m.find(num);

						if(itr->second > 0){
							itr->second = itr->second - 1;
							output.push_back(num);
						}

				}
		}


		return output;
		
  }

};