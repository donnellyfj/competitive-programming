# 207. Course Schedule
from typing import List
from collections import defaultdict
def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
    mapping = defaultdict(lambda: [])
    for course, pre in prerequisites:
        mapping[course].append(pre)

    # Traverse like a graph, look for cycles
    visited = [False] * numCourses
    stack = [False] * numCourses
    def dfs(course):
        if stack[course]:
            return False
        if visited[course]:
            return True
        
        # Add course to recursion stack and visited
        stack[course] = True
        visited[course] = True
        for pre in mapping[course]:
            if not visited[pre]:
                out = dfs(pre)
                if out == False:
                    return False
            if stack[pre]:
                return False
        
        # Remove course from recursion stack
        stack[course] = False
        
        return True
    
    for course, pre in prerequisites:
        if not visited[course] and dfs(course) == False:
            return False

    return True
