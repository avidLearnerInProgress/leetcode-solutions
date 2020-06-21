class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        '''
        if len(nums1) == 0 or len(nums2) == 0:
            return []
        st = set()
        for ele in nums1:
            if ele in nums2:
                st.add(ele)
        return list(st)
        '''
        return list(set(nums1) & set(nums2))