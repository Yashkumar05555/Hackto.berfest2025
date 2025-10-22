class Solution {
public:

    string devowel(const string &s) {
        string t;
        t.reserve(s.size());
        for (char c : s) {
            char lc = tolower(c);
            if (lc=='a' || lc=='e' || lc=='i' || lc=='o' || lc=='u')
                t.push_back('*');
            else
                t.push_back(lc);
        }
        return t;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;                    
        unordered_map<string,string> lowermap;      
        unordered_map<string,string> vowmap;        

        
        for (string w : wordlist) {
            exact.insert(w);

            string lowerw = w;
            for (char &c : lowerw) c = tolower(c);
            if (!lowermap.count(lowerw)) lowermap[lowerw] = w;

            string dev = devowel(w);
            if (!vowmap.count(dev)) vowmap[dev] = w;
        }

        vector<string> ans;
        ans.reserve(queries.size());

  
        for (string q : queries) {
          
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

          
            string lowerq = q;
            for (char &c : lowerq) c = tolower(c);
            if (lowermap.count(lowerq)) {
                ans.push_back(lowermap[lowerq]);
                continue;
            }

            
            string devq = devowel(q);
            if (vowmap.count(devq)) {
                ans.push_back(vowmap[devq]);
                continue;
            }

          
            ans.push_back("");
        }
        return ans;
    }
};
