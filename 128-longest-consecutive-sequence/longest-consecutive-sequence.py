class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        d = {}
        seq = 0
        longest_seq = 0
        for num in nums:
            d[num] = 1 # load the dic
        for num in d:
            prev = num - 1
            if (prev not in d):
                seq = num
                while (1):
                    if (seq in d):
                        seq += 1
                        if ((seq - prev) - 1 > longest_seq):
                            longest_seq = (seq - prev) - 1
                    else:
                        break
        return longest_seq
            
