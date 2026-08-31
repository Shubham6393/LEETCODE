/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> criticalPoints;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;
        
        while (curr != NULL && curr->next != NULL) {
            
            ListNode* next = curr->next;
            
            // Check Local Maxima
            bool isMaxima = (curr->val > prev->val && 
                             curr->val > next->val);
            
            // Check Local Minima
            bool isMinima = (curr->val < prev->val && 
                             curr->val < next->val);
            
            // If current node is a critical point
            if (isMaxima || isMinima) {
                criticalPoints.push_back(index);
            }
            
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        // Less than 2 critical points
        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }
        
        int minDistance = INT_MAX;
        
        // Find minimum distance between consecutive critical points
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDistance = min(minDistance,
                              criticalPoints[i] - criticalPoints[i - 1]);
        }
        
        // Maximum distance = last critical point - first critical point
        int maxDistance = criticalPoints.back() - criticalPoints.front();
        
        return {minDistance, maxDistance};
    }
};
