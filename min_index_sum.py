        if len(list1) < len(list2):
            l = list1
            m = {k:i for i,k in enumerate(list2)}
        else:
            l = list2
            m = {k:i for i,k in enumerate(list1)}
        
        min_sum = float('inf')
        output = []
        
        for i in range(len(l)):
            item = l[i]
            index = m.get(item, 10001)
            new_sum = index + i
            if new_sum < min_sum:
                min_sum = new_sum
                output = [item]
            elif new_sum == min_sum:
                output.append(item)
        
        return output