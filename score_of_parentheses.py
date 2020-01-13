class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        '''
        Maintain depth of each ( as 0.
        
        As soon as a ) is encountered check for the current_top in stack.
        If its 0 then simply pop and add 1 to the prev val in stack.. signifies... ()
        If its not 0, then pop add the prev value + 2 * popped_element to the prev val in stack... signifies A + B and 2 * A operation
        '''
        if len(S) == 0 or len(S) == 1:
            return 0
        st = [0]
        
        for c in S:
            if c == '(':
                st.append(0)
            else:
                item = st.pop()
                result = st.pop()
                if item == 0:
                    result += 1
                else:
                    result += 2 * item
                st.append(result)
        return st.pop(0)