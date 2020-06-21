#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)
#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long

int main()
 {

    FAST_INP;
    ll no_books, no_libraries, no_days;
    cin>>no_books>>no_libraries>>no_days;
    
    vector<ll> book_scores(no_books);

    for(int i=0; i<no_books; i++) cin>>book_scores[i];

    /*
    For each libary => map all the books || 5 books || 2 days || 2 books per day
    */
    ll vector<vector<ll>> library_mp;
    ll vector<vector<ll>> library_books;
    for(int i=0; i<no_libraries; i++){

        ll lb, sp, ls; //no books, signup and shipping

        cin>>lb>>sp>>ls;
        vector<ll> curr_lib;
        curr_lib.push_back(lb);
        curr_lib.push_back(sp);
        curr_lib.push_back(ls);
        library_mp.push_back(curr_lib);

        vector<ll> clib_books(lb);
        for(int j = 0; j <lb; j++) cin>>clib_books[i];
        library_books.push_back(clib_books);
        
    }

    for(int i=0; i< library_mp.size(); i++){
        cout<<"Library -"<<i<<"\n";
        for(int j=0; j<library_mp[i].size(); j++){
            cout<<library_mp[j]<<"\t";
        }
        cout<<"\n";
        for(int j=0; j<library_books[i].size(); j++){
            cout<<library_books[j]<<"\t";
        }
        cout<<"\n";
    }










    



    return 0;

 }


/*
6 2 7
1 2 3 6 5 4
5 2 2
0 1 2 3 4
4 3 1
0 2 3 5
*/