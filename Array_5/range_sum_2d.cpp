// class NumMatrix{
//     public:
//     int pre_arr[200][200];
//     NumMatrix(vector<vector<int>> & matrix){
//         int n=matrix.size();
//         int m=matrix[0].size();
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(i==0 && j==0){
//                     pre_arr[i][j]=matrix[i][j];
//                 }else if(i==0){
//                     pre_arr[i][j]=pre_arr[i][j-1]+matrix[i][j];
//                 }else if(j==0){
//                     pre_arr[i][j]=pre_arr[i-1][j]+matrix[i][j];
//                 }else{
//                     pre_arr[i][j]=pre_arr[i][j-1]+pre_arr[i-1][j]-pre_arr[i-1][j-1]+matrix[i][j];
//                 }
//             }
//         }
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2){
//         int ans=pre_arr[row2][col2];
//         if(row1>0) ans-=pre_arr[row1-1][col2];
//         if(col1>0) ans-=pre_arr[row2][col1-1];
//         if(col1>0 && row1>0) ans+=pre_arr[row1-1][col1-1];
//         return ans;
//     }
// };