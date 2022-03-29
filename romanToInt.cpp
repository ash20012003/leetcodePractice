class Solution {
public:
   
    int romanToInt(string s) {
         int n = s.length();
        int sum = 0;
		
		//Creating a map 
        map<char, int> roman;
		
		// Inserting the respective values as a pair inside the map.
        roman.insert(make_pair('I', 1));
        roman.insert(make_pair('V', 5));
        roman.insert(make_pair('X', 10));
        roman.insert(make_pair('L', 50));
        roman.insert(make_pair('C', 100));
        roman.insert(make_pair('D', 500));
        roman.insert(make_pair('M', 1000));

        //Traversing the roman number from back
        for (int j = n - 1; j >=0; j--)
        {
		    //if previous symbol is greater than current then add it to the sum ex:- ( VI = 5+1=6 )
            if(j>0 && roman[s[j]]<=roman[s[j-1]]){
                sum+=roman[s[j]];
            }
			//if previous symbol is lesser than current then reduct them and add it to the sum ex:- ( IV = 5-1=4 )
            else if(j>0 && roman[s[j]]>roman[s[j-1]]){
                sum+=(roman[s[j]]-roman[s[j-1]]);
                j--;
            }
            else{
                sum+=roman[s[0]];
            }
        }
        return sum;
    }
};