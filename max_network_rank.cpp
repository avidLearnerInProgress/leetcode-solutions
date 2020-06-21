int solution(vector<int>&A, vector<int>&B,int N){
	vector<int> mymap(N+1,0);
	for(int i = 0 ; i < A.size() ; i++){
		mymap[A[i]]++;
		mymap[B[i]]++;
	}
	int res = INT_MIN;
	for(int i = 0 ; i < A.size() ; i++)
		res = max(res,mymap[A[i]]+mymap[B[i]]-1);
	return res;
}