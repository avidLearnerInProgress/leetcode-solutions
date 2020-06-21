class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        if len(dict) == 0:
            return ""
        '''        
        sentences = sentence.split()
        res_string = ""
    
        for i,word in enumerate(sentences):
            print(word)
            if word in dict: #directly append
                sentences[i] = word #pre dertermined optimisation   
            else:
                cword = ""
                for w in word: #check for each char in word
                    cword += w
                    if cword in dict:
                        sentences[i] = cword
        return " ".join(sentences)
        '''
        
        sentences = sentence.split(" ")
        for d in dict:
            for i,w in enumerate(sentences):
                if w.startswith(d):
                    sentences[i] = d
        return " ".join(sentences)
                    