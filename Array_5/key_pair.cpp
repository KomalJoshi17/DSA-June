// class Solution{
// public:
// 	bool hasArrayTwoCandidates(int arr[], int n, int x) {
// 	    int my_memory[100001]={0};
// 	    for(int i=0;i<n;i++){
// 	        int curNum=arr[i];
// 	        int req_num=x-curNum;
// 	        if(req_num<=10000 && req_num>0 && my_memory[req_num]==1){
//                 return true;
//             }
//             my_memory[curNum]=1;
//       }
// 	    return false;
// 	}
// };
