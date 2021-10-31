from heapq import heappush, heappop
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letterLogs, digitLogs, result = [], [], []
		
        for log in logs:
            identifier, content = log.split(' ', 1)
            if content[0].isdigit():
                digitLogs.append(log)
            else:
                heappush(letterLogs, (content, identifier))  # heapify by lexicographical order of content and then identifier
			
        while letterLogs:
            content, identifier = heapq.heappop(letterLogs)  # lexicographically smallest element
            result.append(identifier + ' ' + content)
    
        return result + digitLogs
