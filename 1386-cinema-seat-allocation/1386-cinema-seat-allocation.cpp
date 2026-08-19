class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int totalFamilies = n * 2;

        unordered_map<int, char> rowSeatsMap;

        for (int i = 0; i < reservedSeats.size(); i++)
        {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];

            if (seat > 1 && seat < 10)
            {
                int bitPosition = seat - 2;  
                rowSeatsMap[row] = rowSeatsMap[row] | (1 << bitPosition);
            }
        }

        for (auto it = rowSeatsMap.begin(); it != rowSeatsMap.end(); it++)
        {
            char seatMask = it->second;

            bool leftBlocked   = seatMask & 0b11110000;  
            bool midBlocked    = seatMask & 0b00111100;  
            bool rightBlocked  = seatMask & 0b00001111; 

            if (leftBlocked && midBlocked && rightBlocked)
            {
                totalFamilies -= 2;
            }
            else
            {
                totalFamilies -= 1;
            }
        }

        return totalFamilies;
        
    }
};