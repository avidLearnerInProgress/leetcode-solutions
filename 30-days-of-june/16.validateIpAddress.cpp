class Solution {
public:
    const string validIPv6Chars = "0123456789abcdefABCDEF";
    
    bool isValidIPv4Block(string& block) {
    	int num = 0;
    	if (block.size() > 0 && block.size() <= 3) {
    	    for (int i = 0; i < block.size(); i++) {
    	        char c = block[i];
    	        // special case: if c is a leading zero and there are characters left
    	        if (!isalnum(c) || (i == 0 && c == '0' && block.size() > 1))
    		        return false;
    	        else {
                    num *= 10;
                    num += c - '0';
    	        }
    	    }
    	    return num <= 255;
    	}
    	return false;
    }
    
    bool isValidIPv6Block(string& block) {
    	if (block.size() > 0 && block.size() <= 4) {
    	    for (int i = 0; i < block.size(); i++) {
    	        char c = block[i];
    	        if (validIPv6Chars.find(c) == string::npos)
    	    	    return false;
    	    }
    	    return true;
    	}
    	return false;
    }
    
    string validIPAddress(string IP) {
    	string ans[3] = {"IPv4", "IPv6", "Neither"};
    	stringstream ss(IP);
    	string block;
    	// ipv4 candidate
    	if (IP.substr(0, 4).find('.') != string::npos) {
    	    for (int i = 0; i < 4; i++) {
    		if (!getline(ss, block, '.') || !isValidIPv4Block(block))
    	   	    return ans[2];
    	    }
    	    return ss.eof() ? ans[0] : ans[2];
    	}
    	// ipv6 candidate
    	else if (IP.substr(0, 5).find(':') != string::npos) {
    	    for (int i = 0; i < 8; i++) {
    		if (!getline(ss, block, ':') || !isValidIPv6Block(block))
    		    return ans[2];
    	    }
    	    return ss.eof() ? ans[1] : ans[2];
    	}   
    	return ans[2];
    }
};



/*
My attempt - 
class Solution {
public:
   void split(const string& str, vector<string>& container, const char delim) {

        stringstream ss(str);
        string token;
        while (getline(ss, token, delim)) {
            container.push_back(token);
        }
    }

    string validIPAddress(string IP) {
        vector<string> returns = {"IPv4", "IPv6", "Neither"};
        if(IP.back() == '.' or IP.back() == ':' or IP.front() == '.' or IP.front() == ':') return returns[2];
        
        //if(IP.length() == 0) return returns[2];
        int count = 0;

        //cout<<IP.substr(0,5)<<"\n";
        auto search = IP.substr(0,5);

        if(search.find(".") != string::npos){ //colon doesnt exist, check for IPv4
            vector<string> words;
            split(IP, words, '.');
            //if(words[words.size() - 1].back() == '.') return returns[2];
            
            for(auto word : words){
                //cout<<word<<"\n--------";
                count++;

                if(count > 4 or (word.size() > 1 and word.front() == '0') or word.size() == 0 or word.size() > 4) return returns[2];

                for(auto character : word){
                    if(isdigit(character))continue;
                    else return returns[2];
                }
                int x = 0;
                stringstream toint(word);
                toint >> x;

                if(x > 255) return returns[2];
            }
            return count == 4 ? returns[0] : returns[2];
        }
        else if(search.find(":") != string::npos){
            vector<string> words = {};
            split(IP, words, ':');
            
           // auto last = words[words.size() - 1].back();
            //cout<<last<<"\n";
            
            //if(words[words.size() - 1].back() == ':') return returns[2];
            
            
            for(auto word : words){
                //cout<<word<<"\n-------------";

                count++;
                if(count > 8 or word.size() == 0 or word.size() > 4) return returns[2];

                for(auto character : word){
                    if((character >= 'a' and character <= 'f') or (character >= '0' and character <= '9') or (character >= 'A' and character <= 'F')) continue;
                    else return returns[2];
                }
            }
            return count == 8 ? returns[1] : returns[2];
        }
        return returns[2];
    }
};
*/
