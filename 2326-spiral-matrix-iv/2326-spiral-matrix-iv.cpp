
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int> (n, -1));
        
        int colLow = 0;
        int colHigh = n-1;
        int rowLow = 0;
        int rowHigh = m-1;
        
        while(head!=NULL and rowLow<=rowHigh and colLow<=colHigh){ 
            for(int i = colLow; i<colHigh and head!=NULL; i++){
                matrix[rowLow][i] = head->val;
                head = head->next;
            }
            for(int i=rowLow; i<rowHigh and head!=NULL; i++){
                matrix[i][colHigh] = head->val;
                head = head->next;
            }
            for(int i=colHigh; i>colLow and head!=NULL; i--){
                matrix[rowHigh][i] = head->val;
                head = head->next;            
            }
            for(int i=rowHigh; i>rowLow and head!=NULL; i--){
                matrix[i][colLow] = head->val;
                head = head->next;
            }
            colLow++;
            colHigh--;
            rowLow++;
            rowHigh--;
        }
        if(head!=NULL){
            matrix[rowLow-1][colLow-1] = head->val;
        }
        
        return matrix;
    }
};