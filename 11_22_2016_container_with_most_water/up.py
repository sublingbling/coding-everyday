class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        x1, x2 = 0, len(height) - 1
        area = areaMax = 0
        
        while x1 < x2:
            y1, y2 = height[x1], height[x2]
            area = min(y1, y2) * (x2 - x1)
            areaMax = max(area, areaMax)
            if y1 < y2:
                x1 += 1
            else :
                x2 -= 1
                
        return areaMax
