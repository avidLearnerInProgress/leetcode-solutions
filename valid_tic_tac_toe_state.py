class Solution:
    
    winner = [[i for i in range(3)], [i for i in range(3,6)], [i for i in range(6,9)], [1, 4, 7], [2, 5, 8], [0, 3, 6], [0, 4, 8], [2, 4, 6]]
    
    def invalidStarts(self, boardStr):
            return True if boardStr[0] == 'O' else False
    
    def checkWinner(self, boardStr, c):
        for i in range(8):
            if boardStr[self.winner[i][0]] == c and boardStr[self.winner[i][1]] == c and boardStr[self.winner[i][2]] == c:
                return True
        return False
        
    def validTicTacToe(self, board: List[str]) -> bool:
        boardStr = ''.join(board)
        boardStr = boardStr.replace(" ", "-")
        print(boardStr)
        # if not self.invalidStarts(boardStr):
        # print("*********")
        countX = boardStr.count("X")
        countO = boardStr.count("O")
        print(countX, countO)
        if countX - 1 > countO or countO > countX: return False

        if countX == countO or countX == countO + 1: #either in state X or state O
            print("Inside...")
            if self.checkWinner(boardStr, "O") : # if O is the winner

                print("O is the winner ...")
                if self.checkWinner(boardStr, "X"): # if X is also the winner
                    print("Double winners ...")
                    return False

                if countX == countO:
                    return True
                else:
                    print("countO cant be greater than countX if O is the winner ...")
                    return False
                # return True if countX == countO else False

            if self.checkWinner(boardStr, "X"):   
                print("x is the winner..")
                if countX == countO + 1:
                    return True
                else:
                    print("countX === countO + 1 if X is the winner ...")
                    return False 

        # if boardStr.count("-") in [0, 1, 9]: return True
        # else: return False
        return True
