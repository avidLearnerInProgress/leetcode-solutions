#include<bits/stdc++.h>
using namespace std;

void printMat(vector<vector<int>>& G){
    int m = G.size();
    int n = G[0].size();

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int T;
    cin>>T;
    while(T-- > 0){
        int R,C,r,c,i,j,k,l;
        cin>>R>>C;

        vector<vector<char> > G, P;
        
        G.resize(R, vector<char>(C, 0));
        for(i=0; i<R; i++){
            for(j=0; j<C; j++){
                cin>>G[i][j];
            }
        }
        cin>>r>>c;
        P.resize(r, vector<char>(c, 0));

        for(i=0; i<r; i++){
            for(j=0; j<c; j++){
                cin>>P[i][j];
            }
        }

        //printMat(G);
        //printMat(P);
        int cflag = 0, final_flag = 0;

        for(i=0; i<=R-r; i++){
            for(j=0; j<=C-c; j++){
                if(G[i][j] == P[0][0]){
                    cflag = 1;
                    for(k=0; k<r; k++){
                        if(cflag == 0)
                            break;
                        for(l=0; l<c; l++){
                            if(P[k][l] == G[i+k][j+l]){
                                if(k==r-1 && l==c-1 && cflag==1)
                                    final_flag = 1;
                                cflag = 1;
                            }
                            else{
                                cflag = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(final_flag == 1)
                cout<<"YES\n";
            else
                cout<<"NO\n";

    }
    return 0;
}
