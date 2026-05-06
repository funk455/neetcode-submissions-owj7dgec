class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if beginWord == endWord or endWord not in wordList:
            return 0
        adj = collections.defaultdict(list)
        for word in wordList:
            for j in range(len(word)):
                pattern = word[:j] + '*' + word[j+1:]
                adj[pattern].append(word)
        q = deque([beginWord])
        visited = set([beginWord])
        res = 1
        while q:
            for i in range(len(q)):
                word = q.popleft()
                if word == endWord:
                    return res
                for n in range(len(word)):
                    pattern = word[:n] + '*' + word[n+1:]
                    for nei in adj[pattern]:
                        if nei not in visited:
                            q.append(nei)
                            visited.add(nei)
            res += 1
        return 0