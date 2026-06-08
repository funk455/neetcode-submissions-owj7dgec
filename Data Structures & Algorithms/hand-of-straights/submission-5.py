class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0 :
            return False;
        count = {}
        for card in hand:
            count[card] = count.get(card,0)+1
        que = list(count.keys())
        heapq.heapify(que)
        while que:
            first = que[0]
            for i in range(first,first+groupSize):
                if i not in count:
                    return False
                count[i]-=1
                if count[i] == 0:
                    if i != que[0]:
                        return False
                    heapq.heappop(que)
        return True