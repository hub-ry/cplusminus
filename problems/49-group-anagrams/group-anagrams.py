class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        dih = {}
        for s in strs:
            sorted_text = "".join(sorted(s))
            if sorted_text in dih:
                dih[sorted_text].append(s)
            else:
                dih[sorted_text] = [s]

        return list(dih.values())

