class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        //Using count() STL
        
        int maxCount=0;
        
        //traverse to the string index
        for(int i=0; i<sentences.size(); i++)
        {
            //keep track of count for each sentence going from its beg. to the end
            //if we hit ' ' it means a word ended so we increase count by 1
            int sCount = count(sentences[i].begin(), sentences[i].end(), ' ');
            maxCount=max(maxCount, sCount+1); //sCount starts from 0 so we do sCount+1
        }
        return maxCount;
    }
};
//TC: O(n*m) [traverse array string * for each string count() takes O(m) TC]
//SC: O(1)

/*---------------------------------------------------------------------------------------
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        //Brute Force: without STL
        
        int maxCount=0;
        
        //traverse to the string index
        for(int i=0; i<sentences.size(); i++)
        {
            int count=1; //keep counter for each sentence[i] ie. at ith index
            
            //traverse words as charecters in each sentence 
            for(int j=0; j<sentences[i].length(); j++)
            {
                if(sentences[i][j]==' ') //not " " because we are searching for charecter
                    count++;
            }
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};
//TC: O(n*m) [traverse array string * traverse words in each string/sentence]
//SC: O(1)
*/