#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& curr){
  if (curr.size() == nums.size()){
    for (int x: curr) cout << x << " ";
    cout << endl;
    return;
  }

  for (size_t i = 0; i < nums.size(); i++){
    if (!used[i]){
      used[i] = true;
      curr.push_back(nums[i]);

      backtrack(nums, used, curr);

      // defaz, volta
      curr.pop_back();
      used[i] = false;
    }
  }
}

int main(){
  vector<int> numbers = {1, 2, 3};
  vector<bool> used(numbers.size(), false);
  vector<int> curr;

  backtrack(numbers, used, curr);

  return 0;
}