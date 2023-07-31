class Solution {
public:
    // isme basically hum eak copy matrix create kar rahe hai and jaise hi matrix[i][j] == 0 hota hai to hum uske corresponding copy matrix ke rows and columns ko 0 kar dete hai and finally woh copy ki values ko original matrix mai assign kardenge . TC - 0(n*m) 0(n+m) SC - 0(n*m) so we need to minizise space 

    // eak aur approach ho sakta hai ki jaise hi matrix[i][j] == 0 hota hai to hum uske poore row and poore column ko -1 se mark kar denge and agar column and row mai zero aa raha hai to usko -1 se mark nhi karenge finally aaise karne ke baad again matrix traverse karo aur jaha bhi -1 hai usko 0 zero kardo and final matrix return kardo . yeh logic iss question mai work nhi karega kyuki iss matrix mai all int ki values pehle se hi present hai agar matrix sirf 0 and 1 ko contain kar raha hota to hum isko try kar sakte the. yeh approach mai space 0(1) hoga.

    /*
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> ans = matrix;
        
        for(int i = 0; i < row; i++){

            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k < col; k++){
                        ans[i][k] = 0;
                    }
                    for(int k = 0; k < row; k++){
                        ans[k][j] = 0;
                    }
                }
            }

        }

        matrix = ans;
    }
    */

    // below approach mai TC to 0(n*m) * 0(n*m) and SC - 0(n+m) isme basically humne eak row matrix and eak column matrix create kari hai jo ki check karta hai matrix ke andar agar 0 hai to fir hum inn dono matrix ke andar 1 mark kar denge eak flag ki tarah takki jab hum again hum us matri ko travel kare to agar ith ya jth mai koi bhi flag 1 hai to uss cell ko hum 0 se mark kardenge to understand it better take u forward ka 30min wala video ka approacch 2nd(better solution) dekhlo.
    /*
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowMatrix[col];
        int colMatrix[row];

        // dono matrix ke cells ko 0 se assign kardiya
        for(int i = 0; i < col; i++){
            rowMatrix[i] = 0;
        }
        for(int j = 0; j < row; j++){
            colMatrix[j] = 0;
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    colMatrix[i] = 1;
                    rowMatrix[j] = 1;
                }
            }
        }

        for(int i = 0; i < row;  i++){
            for(int j = 0; j < col; j++){
                if(colMatrix[i] || rowMatrix[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    */

    // below approach mai space 0(1) constant hai kyuki isme humne flag ke liye koi arrays create nhi kara balki matrix ka 0th row and 0th column ko hi flag ke tarah assume kardiya .

    void setZeroes(vector<vector<int>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();

        int x = 1; // yeh 0th row ke liye hai
        int y = 1; // yeh 0th col ke liye hai .

        // below loop mai bas hum yahi check kar rahe hai ki agar 0th row ke andar agar koi bhi value 0 hoti hai to hum x ko zero kardenge 
        for(int j=0;j<col;j++){
            if(matrix[0][j]==0)x=0;  
        }

        // below loop mai bas hum yahi check kar rahe hai ki agar 0th col ke andar agar koi bhi value 0 hoti hai to hum y ko zero kardenge 
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0)y=0;
        }
        
        // isme agar hamari matrix 4*4 ki hai to hum internal 3*3 ke elements mai koi bhi 0 hota hai to uski hum marking kar rahe hai .
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0; // marking at 0th col
                    matrix[0][j]=0; // marking at 0th row
                }
            }
        }
        
        // isme hum 0th row ke marking ko check kar rahe hai agar koi bhi 0 hota hai to fir internal 3*3 ke sare col elements ko 0 kardiya jayega.
        for(int j=1;j<col;j++){
           if(matrix[0][j]==0){
               for(int i=1;i<row;i++)
                   matrix[i][j]=0;
           }
        }
        
        // isme hum 0th col ke marking ko check kar rahe hai agar koi bhi 0 hota hai to fir internal 3*3 ke sare row elements ko 0 kardiya jayega.
        for(int i=1;i<row;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<col;j++)
                    matrix[i][j]=0;
            }
        }
        
        // isme hum 0th column ke sare cells ko 0 se mark kar rahe hai 
        if(y==0){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
        
        // isme hum 0th row ke sare cells ko 0 se mark kar rahe hai 
        if(x==0){  
            for(int j=0;j<col;j++)
            matrix[0][j]=0;
        }
    }


};