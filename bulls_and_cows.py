class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        d = {}
        bull, cow = 0,0

        for index,s in enumerate(secret):
            if guess[index] == s:
                bull += 1
            else:
                d[s] = d.get(s,0) + 1

        for index,s in enumerate(secret):
            if (guess[index] != s) & (d.get(guess[index],0) != 0):
        	    cow += 1
        	    d[guess[index]] -= 1
        	    
        return str(bull) + "A" + str(cow) + "B"
