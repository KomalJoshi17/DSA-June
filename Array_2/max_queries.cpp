// // not avaible on platforms
// #include <bits/stdc++.h>
// using namespace std;

// // Time: O(N + M)

// void answerQueries(int arr[], int queries[], int N, int M) {
//     int *pre = new int[N];
//     int *suf = new int[N];

//     // Fill up the pre array
//     for(int i = 0; i < N; ++i)
//         pre[i] = i == 0? arr[i] : max(pre[i-1], arr[i]);

//     // Fill up the suf array
//     for(int i = N - 1; i >= 0; --i)
//         suf[i] = i == N - 1? arr[i] : max(suf[i+1], arr[i]);

//     // Answer the queries
//     for(int i = 0; i < M; ++i) {
//         int ans, id = queries[i];

//         if(id == 0)
//             ans = suf[id+1];
//         else if(id == N - 1)
//             ans = pre[id-1];
//         else
//             ans = max(pre[id-1], suf[id+1]);

//         cout << ans << '\n';
//     }
// }

// int main() {
//     int N, M; 
//     cin >> N >> M;
//     int *arr = new int[N];
//     int *queries = new int[M];

//     for(int i = 0; i < N; ++i)
//         cin >> arr[i];

//     for(int i = 0; i < M; ++i)
//         cin >> queries[i];

//     answerQueries(arr, queries, N, M);
// 	return 0;
// }
