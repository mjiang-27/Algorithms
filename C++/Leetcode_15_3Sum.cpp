class Solution 
{
    public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {	
        vector<vector<int> > res;
		
 		if (num.size() <= 2)
		{
			return res;
		}
       
        std::sort(num.begin(), num.end());

        for (int index = 0; index < num.size(); index++) 
        {
            int target = -num[index];
            int left = index + 1;
            int right = num.size() - 1;

            while (left < right) 
            {
                int sum = num[left] + num[right];
                
                // Finding answer which start from number num[index]
                if (sum < target)
                {
                    left++;
                }
                else if (sum > target)
                {
                    right--;
                }
                else 
                {
                    vector<int> resElem(3, 0);
                    resElem[0] = num[index];
                    resElem[1] = num[left];
                    resElem[2] = num[right];
                    res.push_back(resElem);
                    
                    // Processing duplicates of second number
                    // Rolling the left pointer to the next different number forwards
                    while (left < right && num[left] == resElem[1]) 
                    {
                        left++;
                    }

                    // Processing duplicates of third number
                    // Rolling the right pointer to the next different number rightwards
                    while (left < right && num[right] == resElem[2]) 
                    {
                        right--;
                    }
                }
                
            }

            // Processing duplicates of first number
            while (index + 1 < num.size() && num[index + 1] == num[index]) 
            {
                index++;
            }
        }
        
        return res;
    }
};