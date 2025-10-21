# PROBLEM
<img width="1027" height="452" alt="image" src="https://github.com/user-attachments/assets/3be31d81-a57a-495e-bfab-7ff8a7fafc14" />
<img width="822" height="368" alt="image" src="https://github.com/user-attachments/assets/1f54bd04-a3fe-42a6-8fe7-56bd6691574e" />
<img width="793" height="335" alt="image" src="https://github.com/user-attachments/assets/1aef087e-64af-4cab-a27e-4006980d5409" />
<img width="634" height="254" alt="image" src="https://github.com/user-attachments/assets/42ae85c5-9407-4a56-8f7c-df8fb7278687" />

# INTUITION
<img width="1179" height="499" alt="image" src="https://github.com/user-attachments/assets/5517382d-c05e-4d42-86f1-acf21e9a6992" />
<img width="1337" height="814" alt="image" src="https://github.com/user-attachments/assets/b2e74723-352c-4468-aa1e-fef3f744c2b6" />
<img width="1399" height="590" alt="image" src="https://github.com/user-attachments/assets/76c7bdac-2515-4cf6-b3a5-d55545279ef5" />

<img width="1500" height="721" alt="image" src="https://github.com/user-attachments/assets/a9df9f6a-3bb3-485d-b68a-dbf802b2319f" />
<img width="1570" height="338" alt="image" src="https://github.com/user-attachments/assets/6a80a417-1b16-4950-87fb-c1b73fa20965" />
<img width="1585" height="295" alt="image" src="https://github.com/user-attachments/assets/d34e0e9a-a7cf-49ef-b639-165fbaea7fd5" />
<img width="1576" height="701" alt="image" src="https://github.com/user-attachments/assets/b2aa6253-510b-45b7-8c81-52f0cd268743" />

`Total 6 elements are present in the range [8,18] check the array : {1,7,13,13,18,18,18}`


# CODE
```
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEl = *max_element(begin(nums), end(nums)) + k;

        vector<int> freq(maxEl + 1, 0);

        for(int &num : nums) {
            freq[num]++;
        }

        //cumulative sum of frequenceis
        for(int i = 1; i <= maxEl; i++) {
            freq[i] += freq[i-1];
        }

        int result = 0;
        for(int target = 0; target <= maxEl; target++) {
            if(freq[target] == 0)
                continue;
            
            int leftNum  = max(0, target-k); //l
            int rightNum = min(maxEl, target+k); //r

            int totalCount  = freq[rightNum] - (leftNum > 0 ? freq[leftNum-1] : 0);
            int targetCount = freq[target] - (target > 0 ? freq[target-1] : 0);
            int needConversion = totalCount - targetCount;
            int maxPossibleFreq = targetCount + min(needConversion, numOperations);
            result = max(result, maxPossibleFreq);
        }

        return result;
    }
};
```
