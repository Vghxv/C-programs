/*020 擲骰子遊戲

十八骰子是一種常見的擲骰子遊戲，用四顆骰子計點。
四顆一開始都是點數 1 朝上，點數 4 朝向玩家，點數 2 朝右，
骰子擺放示意圖如連結所示 (https://imgur.com/Ntds1Ri)，
骰子展開如連結所示 (https://imgur.com/xEVHA5h)。
=================
接下來 N 次修改操作，每次操作包含四個整數代表依序針對四個骰子操作。
輸入整數之操作意義如下：
1表示向前滾一次。(往玩家視角的前方滾動)
2表示向後滾一次。(往玩家視角的後方滾動)
3表示向右滾一次。
4表示向左滾一次。
註：以上修改操作，皆只針對骰子做操作，並不會改變玩家的視角方向

操作完成後輸出得分，計點方式如下：
1. 若四顆點數均相同，稱一色，計18分，例如6, 6, 6, 6 或 3, 3, 3, 3。
2. 若四顆點數均不同；或有三顆點數相同，一顆不同，計 0分，例如 1, 2, 3, 4 或 2, 2, 2, 6。
3. 若兩顆點數相同，另兩顆點數也相同，但兩組兩顆點數不同，則得分計算為：加總兩顆較大點數，例如 2, 2, 5, 5，加總兩顆較大點數為 5+5=10分。
4. 若兩顆點數相同，另兩顆點數不同，則得分計算為加總兩顆不同點數，例如 2, 2, 4, 5，加總兩顆不同點數為 4+5=9分。
註：骰子點數以操作後最終朝上的那面點數為準
=================
輸入說明：
先輸入一個自然數N代表接下來有N次修改操作，
接著輸入N行修改操作，每行皆由4個1~4的數字組成，數字間以空格區隔

輸出說明：
輸出骰子最終的得分
=================
範例輸入說明：
2
1 4 3 2
4 2 1 3

範例輸出說明：
第一次操作後4顆骰子朝上的那面分別是4253
第二次操作後4顆骰子朝上的那面分別是2345
由於最終點數皆不同，因此得分為0並輸出
=================
Sample Input 1：
0

Sample Output 1：
18
=================
Sample Input 2：
1
4 3 1 2

Sample Output 2：
0
=================
Sample Input 3：
1
3 3 3 3

Sample Output 3：
18
=================
Sample Input 4：
2
1 3 4 2
2 4 3 1

Sample Output 4：
18
=================
Sample Input 5：
2
3 2 4 1
1 4 1 4

Sample Output 5：
8
=================
Sample Input 6：
2
1 1 2 3
3 1 2 4

Sample Output 6：
6
=================
Sample Input 7：
2
4 1 2 4
3 1 2 4

Sample Output 7：
0
=================
Sample Input 8：
3
2 3 3 1
4 3 1 2
1 3 2 4

Sample Output 8：
6
=================
Sample Input 9：
3
1 4 2 3
1 3 1 3
2 2 4 1

Sample Output 9：
5
=================
Sample Input 10：
5
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
1 2 3 4

Sample Output 10：
0
=================
Sample Input 11：
10
4 2 2 1
4 2 2 4
1 2 3 4
2 2 3 2
3 2 1 2
3 4 4 2
3 3 1 3
1 4 1 1
4 1 4 2
1 1 4 4

Sample Output 11：
8
*/
#include<stdio.h>
int main(){
    int n;
    int arr[5][3];
    scanf("%d,",&n);
    for(int i=0;i<4;i++){
        arr[i][0] = 1;
        arr[i][1] = 2;
        arr[i][2] = 4;
    }
    int k;
    for(int t=0;t<n;t++){
        for(int i=0;i<4;i++){
            scanf("%d",&k);
            if(k == 1){
                int temp = 7 - arr[i][0];
                arr[i][0] = arr[i][2];
                arr[i][2] = temp;
            }
            else if(k == 2){
                int temp = 7 - arr[i][2];
                arr[i][2] = arr[i][0];
                arr[i][0] = temp;
            }
            else if(k == 3){
                int temp = 7 - arr[i][1];
                arr[i][1] = arr[i][0];
                arr[i][0] = temp;
            }
            else if(k == 4){
                int temp = 7 - arr[i][0];
                arr[i][0] = arr[i][1];
                arr[i][1] = temp;
            }
            // printf("%d ",arr[i][0]);
        }
        // puts("");
    }
    
    int ans[7] = {0};
    for (int i=0;i<4;i++){
        ans[arr[i][0]]++;
    }
    int mn = 0,flag=0,tmp=0;
    for(int i=1;i<=6;i++){
        if(ans[i]==4){
            puts("18");
            return 0;
        }
        if(ans[i]==2){
            if(flag)flag=6;
            flag += i;
            
        }
        else if(ans[i]==1){
            tmp+=i;
        }
        mn = (ans[i]>mn)?ans[i]:mn;
    }
    if(mn == 1 || mn == 3){
        puts("0");
        return 0;
    }
    if(flag > 6){
        printf("%d\n",2*flag-12);
        return 0;
    }
    printf("%d\n",tmp);
    return 0;

}