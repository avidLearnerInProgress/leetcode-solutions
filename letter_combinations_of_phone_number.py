class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfsSearch(number,stringToPassDown):
            for each in number:
                tempString = stringToPassDown
                tempString = tempString + each

                if len(tempString) < len(digits):
                    dfsSearch(dict[digits[len(tempString)]],tempString)
                elif len(tempString) == len(digits):
                    answer.append(tempString)
                else:
                    None
        answer = []
        dict = {'2':['a','b','c'],'3':['d','e','f'],'4':['g','h','i'],'5':['j','k','l'],'6':['m','n','o'],'7':['p','q','r','s'],'8':['t','u','v'],'9':['w','x','y','z']}
        if len(digits) == 0:
            return answer
        
        stringToPassDown = ""
        dfsSearch(dict[digits[0]],stringToPassDown)
        return answer