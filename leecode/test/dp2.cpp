#include <vector>
#include <iostream>
using namespace std; 

void test_1_wei_bag_problem() {
 vector<int> weight = {1, 3, 3};
 vector<int> value = {15, 20, 30};
 int bagWeight = 4;
 // 初始化
 vector<int> dp(bagWeight + 1, 0);
//  for(int i = 0; i < weight.size(); i++) { // 遍历物品
//  for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
 for(int j = bagWeight; j >= 0; j--) { // 遍历背包容量
for(int i = 0; i < weight.size(); i++) { // 遍历物品
    if(j >= weight[i])
 dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
 cout << "i = " << i << " " << "j = " << j << "**  ";
 for(int k = 0; k <= bagWeight; k ++)
 {
     cout << dp[k] << " ";
 }
 cout << endl;
 }
 }
 cout << dp[bagWeight] << endl;

 for(int j = 0; j <= bagWeight; j ++)
    cout << dp[j] << " ";
}
int main() {
 test_1_wei_bag_problem();
}