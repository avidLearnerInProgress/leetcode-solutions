class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = 0; i < nestedList.size(); i++){
            if(nestedList[i].isInteger()){
                items.push_back(nestedList[i].getInteger()); //If this one is integer, push back into vector
            }else{
                auto j = NestedIterator(nestedList[i].getList()); //If this one is a list, recurse with the new list
                while (j.hasNext()) items.push_back(j.next()); //Get the elements from new list and push into current vector (This is from given code)
            }
        }
    }
    
    int next() {
        return items[cur++]; //Return next item
    }
    
    bool hasNext() {
        return (cur < items.size()); //Check if index is smaller than vector size
    }
    
private:
    vector<int> items; //Vector for all items
    int cur = 0; //Current index
};
