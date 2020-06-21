class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        
        openSet = ["(", "{", "["] #can be a set, but okay. not many i/o operations on this list. Just one time mapping to k->v
        closeSet = [")","}", "]"]

        mapper = dict(zip(openSet, closeSet))
        inv_mapper = {v: k for k, v in mapper.items()} #fuck this is needed, for c in mapper :- will compare key with the popped item.. Then better to invert it before #better to zip it v->k but difficult to get this inutition before one dry run...
        
        for i, c in enumerate(s):
            #if we encounter tc as opening braces
            if c in inv_mapper.values():
                #print(c)
                stack.append(c)
                
            #if we encounter c as closing braces
            elif c in inv_mapper.keys():
                if stack == [] or stack.pop() != inv_mapper[c]: #empty stack in between the processing meaning invalid string. Top != key of dict so invalid pair of braces.
                    return False
            else: #interesting testcase for this 
                return False
        return stack == [] #in the end everything is empty and all went well.