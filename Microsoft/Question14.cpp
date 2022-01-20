class Solution{
public:
    int minSteps(int D){
        int totalD =0;
        int step =0;
        while(true){
            totalD += step;
            step++;
            if(totalD == D){
                return step-1;
                break;
            }
            if(totalD > D && (totalD -D)%2 ==0){
                return step-1;
                break;
            }
        }
        return 0;
    }
};