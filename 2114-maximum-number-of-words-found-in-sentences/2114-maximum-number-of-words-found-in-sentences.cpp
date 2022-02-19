class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
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