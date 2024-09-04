#include <stdio.h>

#define MOD 998244353
#define MAXN 200005

int N, Q;
int parent[MAXN];
int A[MAXN];
int children[MAXN][2];
int hash_values[MAXN];

int dfs(int node) {
    if (children[node][0] == 0 && children[node][1] == 0) {
        return A[node];
    }

    hash_values[node] = A[node];
    if (children[node][0] != 0) {
        hash_values[node] += dfs(children[node][0]);
        hash_values[node] %= MOD;
    }
    if (children[node][1] != 0) {
        hash_values[node] += dfs(children[node][1]);
        hash_values[node] %= MOD;
    }

    return hash_values[node];
}

int main() {
    scanf("%d %d", &N, &Q);

    for (int i = 2; i <= N; i++) {
        scanf("%d", &parent[i]);
        if (children[parent[i]][0] == 0) {
            children[parent[i]][0] = i;
        } else {
            children[parent[i]][1] = i;
        }
    }

    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    dfs(1);

    for (int q = 0; q < Q; q++) {
        int v, x;
        scanf("%d %d", &v, &x);
        A[v] = x;
        printf("%d\n", hash_values[1]);
    }

    return 0;
}
