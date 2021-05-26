class SnapshotArray {
public:
    unordered_map<int, unordered_map<int, int>> database;
    unordered_map<int, int> cur_data;
    int snap_id;
    SnapshotArray(int length) {
      snap_id = -1;
    }
    
    void set(int index, int val) {
      cur_data[index] = val;
    }
    
    int snap() {
      snap_id++;
      database[snap_id] = cur_data;
      return snap_id;
    }
    
    int get(int index, int snap_id) {
      return database[snap_id][index];
    }
};
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
