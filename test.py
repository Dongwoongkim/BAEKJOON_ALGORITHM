import sys
input = sys.stdin.readline
import heapq

n, m, x= map(int, input().split())
graph = [[]for i in range(n+1)]

for i in range(m):
    a, b, c = map(int, input().split())
    graph[a].append([b,c])

def dijkstra(start, destination):
    que = []
    dist = [float('inf') for i in range(n + 1)]
    dist[start] = 0
    heapq.heappush(que, (0, start))

    while que:
        cost, node = heapq.heappop(que)
        if dist[node] < cost:
            continue
        for newnode, newcost in graph[node]:
            newdist = cost + newcost
            if newdist < dist[newnode]:
                dist[newnode] = newdist
                heapq.heappush(que, (newdist, newnode))

    return dist[destination]

answer = 0
for i in range(1, n+1):
    '''
    왔다갔다 한번에 다익스트라 해서 계산
    '''
    answer = max(dijkstra(i, x) + dijkstra(x, i), answer)

print(answer)