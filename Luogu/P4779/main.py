import heapq

class edge:
    def __init__(self, v, w):
        self.v = v
        self.w = w

def dijkstra(s):
    vis = [False for i in range(n + 1)]
    dist[s] = 0;
    q = []
    heapq.heappush(q, (0, s))
    while q:
        u = q[0][1];
        heapq.heappop(q);
        if (vis[u] == True):
            continue
        vis[u] = True
        for e in G[u]:
            if vis[e.v] == False and dist[u] + e.w < dist[e.v]:
                dist[e.v] = dist[u] + e.w
                heapq.heappush(q, (dist[e.v], e.v))

INF = 0x3f3f3f3f
n, m, s = map(int, input().split())

dist = [INF for i in range(n + 1)]
G = [[] for i in range(n + 1)]

for i in range(m):
    u, v, w = map(int, input().split())
    G[u].append(edge(v, w))

dijkstra(s)

for i in range(1, n + 1):
    print(dist[i], end = ' ')
print('')
