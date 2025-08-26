#include <iostream>
#include <string>


using namespace std;

/**큰 수)
 * 성냥개비 개수가 짝수 : n/2만큼 1로 채우기
 * 성냥개비 개수가 홀수 : n/2-1만큼 1로 채우고 가장 높은 숫자 7
 * 
 * 작은 수)
 *  dp[i] i개의 성냥개비로 만들 수 있는 가장 작은 수 
 */


const int useStickCnt[10] = {
   6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};
int T,n;
string bigNumber, smallNumber;
string dp[105];
const string NOT_VISITED = "-2";
const string INF = string(105, '9');

bool isLeftSmall (string a, string b) {
   if (a.size() == b.size()) return a<b;
   else return a.size()<b.size();
}

string calSmallNumber (int stickCnt, bool firstNum) {
   if (stickCnt<0) return INF;
   string & ret = dp[stickCnt];
   if (ret!=NOT_VISITED) return ret;
   if (stickCnt==0) {
      return "";
   }
   
   ret = INF;
   int num = (firstNum ? 1 : 0);
   for (num; num<=9; num++) {
      string tmp = (char ('0'+num)) + calSmallNumber(stickCnt-useStickCnt[num], false);
      if (isLeftSmall(tmp, ret)) {
         ret = tmp;
      }
   }

   if (ret>=INF) return ret = INF;
   return ret;
}

int main () {

   ios::sync_with_stdio(0); cin.tie(0);
   cin >> T;

   while (T--) {
      // 초기화
      cin >> n;
      bigNumber = "";
      smallNumber = "";
      for (int i=0; i<=n; i++) {
         dp[i] = NOT_VISITED;
      }

      // 큰 숫자
      if (n%2==0) {
         for (int i=0; i<n/2; i++) bigNumber += "1";
      }else {
         bigNumber += "7";
         for (int i=0; i<n/2-1; i++) bigNumber += "1";
      }

      // 작은 숫자
      smallNumber = calSmallNumber(n, true);
      cout << smallNumber << ' ' << bigNumber << '\n';

   }
   

   return 0;
}