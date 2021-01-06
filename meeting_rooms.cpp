struct meeting {
    int start, end, position;    
};


bool comparator(struct meeting m1, struct meeting m2) {
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.position < m2.position) return true;
    else return false;
}


int maxMeetings(int start[], int end[], int n) {
    // Your code here
    struct meeting meetings[n];
    for(int i=0; i<n; i++) {
        meetings[i].start = start[i], meetings[i].end = end[i], meetings[i].position = i+1;
    }
    
    
    sort(meetings, meetings+n, comparator);
    int current_end = meetings[0].end;
    int result = 1;
    
    for(int i=1; i<n; i++) {
        
        if(meetings[i].start > current_end) {
            current_end = meetings[i].end;
            result++;
        }
    }
    
    return result;
    
    
}
