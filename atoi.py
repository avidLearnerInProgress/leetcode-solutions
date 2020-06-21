sclass Solution:
    def myAtoi(self, str: str) -> int:
        '''
        MAX_INT = 2 ** 31 -1
        MIN_INT = -(2 ** 31)
        
        def limit(integer):
            if integer > MAX_INT:
                return MAX_INT
            if integer < MIN_INT:
                return MIN_INT
            return integer
        
        isNegative = 1
        str = str.lstrip(' ')
        if not str:
            return 0
        
        if str[0] == '-':
            isNegative = -1
        
        if isNegative != 1 or str[0] == '+':
            str = str[1:]
        
    
        mapper = {'1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, '0':0}
        
        atoi = 0
        for ch in str:
            if ch in mapper:
                atoi = atoi * 10 + mapper[ch]
            else:
                return limit(atoi * isNegative)
        return limit(atoi * isNegative)
        '''
        str = str.strip()

        if str=='' or str[0] not in ['+','-','0','1','2','3','4','5','6','7','8','9']:
            return 0
        i,flag = 0,1
        
        if str[0] == '-':
            flag = -1
            i=1
        
        elif str[0] == '+':
            i=1
        
        while i< len(str) and str[i].isdigit():
            i+=1
        
        ans = str[:i]
        if ans[0] in ['+','-'] and ans[1:].isdigit():
            output = int(ans[1:])*flag
        
        elif ans[0] not in ['+','-'] and ans.isdigit():
            output = int(ans)
        
        else:
            output = 0
        
        if output >= 2147483647:
            return 2147483647
        elif output<= -2147483648:
            return -2147483648
        return output
            
        