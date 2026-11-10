class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:

        #defaultdict(set) makes a set for each new key
        dr = collections.defaultdict(set)        
        dc = collections.defaultdict(set)
        db = collections.defaultdict(set)
        
        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if (val == "."):
                    continue
                box = (r//3, c//3)
                
                if val in dr[r] or val in dc[c] or val in db[box]:
                    return False
                dr[r].add(val)
                dc[c].add(val)
                db[box].add(val)
        return True
