'''
Input: 'ab[cd]{2}'
Output: 'abcdcd'
Input: 'def[ab[cd]{2}]{3}ghi'
Output: 'defabcdcdabcdcdabcdcdghi'
'''
def decode(sudo):
    if sudo == None:
        return None
    if sudo == "":
        return ""
    lsudo = list(sudo)
    foo = [] #stack
    res = ''
    for i in range(len(lsudo)):
        if lsudo[i] == '[':
            partial = ""
            i += 1
            while i < len(lsudo) and lsudo[i] != ']' and lsudo[i] != '[':
                partial += lsudo[i]
                i += 1
            foo.append(partial) #lsudo[i] == ']' or lsudo[i] == '[' 
            i -= 1
        elif lsudo[i] == '{':
            i += 1
            if len(foo) == 0:
                return -1
            num = ''
            while i < len(lsudo) and lsudo[i] != '}':
                num += lsudo[i]
            top = foo.pop()
            re = top*int(num)
            res.append(re)
            if foo != []:
                popped = foo.pop()
                foo.append(popped + re)
            else:
                foo.append(re)
        elif lsudo[i] >= 'a' and lsudo[i] <= 'z':
            res += lsudo[i]
    return res

print(decode(str(input())))