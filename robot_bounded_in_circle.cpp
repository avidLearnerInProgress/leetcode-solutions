class Solution {
    enum Directions{ NORTH, SOUTH, EAST, WEST };
public:
    bool isRobotBounded(string instructions) {
        
        if(instructions.size() == 0) return false;
        int x = 0, y = 0;
        
        Directions d = NORTH;
        
        for(auto &instruction : instructions) {
            if(instruction == 'G') {
                
                switch(d) {
                    case NORTH:
                        y++;
                        break;
                    case SOUTH:
                        y--;
                        break;
                    case WEST:
                        x--;
                        break;
                    case EAST:
                        x++;
                        break;
                }
            }
            else if(instruction == 'L') {
                switch(d) {
                    case NORTH:
                        d = WEST;
                        break;
                    case SOUTH:
                        d = EAST;
                        break;
                    case EAST:
                        d = NORTH;
                        break;
                    case WEST:
                        d = SOUTH;
                        break;
                }
            }
            else {
                switch(d) {
                    case NORTH:
                        d = EAST;
                        break;
                    case SOUTH:
                        d = WEST;
                        break;
                    case EAST:
                        d = SOUTH;
                        break;
                    case WEST:
                        d = NORTH;
                        break;
                }
            }
        }
        if((x == 0 and y == 0) or !(d == NORTH)) return true;
        
        return false;
    }
};
