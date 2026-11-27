class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        sp = []

        for c in s:
            if c.isalnum():
                sp.append(c)
        
        l = 0
        r = len(sp) - 1

        while (l <= r):
            if sp[l] != sp[r]:
                return False
            l += 1
            r -= 1
        
        return True