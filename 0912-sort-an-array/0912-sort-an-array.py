class Solution(object):
    def merge_sort(self,arr):
        if len(arr) > 1:
            # Step 1: Divide the array into two halves
            mid = len(arr) // 2
            left_half = arr[:mid]
            right_half = arr[mid:]

            # Step 2: Recursively sort the halves
            self.merge_sort(left_half)
            self.merge_sort(right_half)

            # Step 3: Merge the sorted halves
            i = j = k = 0

            while i < len(left_half) and j < len(right_half):
                if left_half[i] < right_half[j]:
                    arr[k] = left_half[i]
                    i += 1
                else:
                    arr[k] = right_half[j]
                    j += 1
                k += 1

            # Check for any remaining elements in the left half
            while i < len(left_half):
                arr[k] = left_half[i]
                i += 1
                k += 1

            # Check for any remaining elements in the right half
            while j < len(right_half):
                arr[k] = right_half[j]
                j += 1
                k += 1
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        # Selection Sort 
        """     
        n = len(nums)
        for i in range(n):
            mini = i
            for j in range(i+1,n):
                if nums[j]<nums[mini]:
                    mini = j
            nums[i] , nums[mini] = nums[mini] , nums[i]
        
        return nums
        """

        # Bubble Sort 
        """
        n = len(nums)
        for i in range(n-1,0,-1):
            for j in range(0,i):
                if nums[j]>nums[j+1]:
                    nums[j] , nums[j+1] = nums[j+1] , nums[j]

        return nums
        """
        self.merge_sort(nums)
        return nums
