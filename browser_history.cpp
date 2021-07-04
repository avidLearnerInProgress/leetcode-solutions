class BrowserHistory {
public:
    stack<string> history;
    stack<string> future;
	
    BrowserHistory(string homepage) {
        history.push(homepage);
        future = stack<string>();           // Reset the forward stack.
    }
    
    void visit(string url) {
        history.push(url);
        future = stack<string>();           // Reset the forward stack.
    }
    
    string back(int steps) {
        while(steps > 0 && history.size() > 1) { // Always keep at least one element in the stack. 
            future.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps > 0 && future.size() > 0) {
            history.push(future.top());
            future.pop();
            steps--;
        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */



/*
>start on homepage
>visit a url
>go back -- number of steps 
>move forward -- number of steps

*/
