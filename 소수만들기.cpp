#include <vector>
#include <iostream>
using namespace std;

int decimal_judge(int value){
    for(int i=2;i<value;i++)
        if(value%i==0)
            return 0;
    return 1;
}
vector <int> value_list;
void calculate(int start, vector<int>& nums, int count, int value){

    if(count==3){
    	printf("%d\n",value);
        value_list.push_back(value);
        return ;
    }
    else if(start+1>=nums.size())
        return ;
    else{
        for(int i=start+1;i<nums.size();i++)
            calculate(i,nums,count+1,value+nums[start]);
    }
  
}


int solution(vector<int> nums) {
    int answer=0;
    for(int i=0;i<nums.size()-2;i++)
    	calculate(i,nums,0,0);
    for(int i=0;i<value_list.size();i++){
    	if(decimal_judge(value_list[i])==1)
    		answer++;
	}

    cout << answer<< endl;

    return answer;
}


int main(){
	vector<int> list;
	for(int i=0;i<4;i++)
		list.push_back(i+1);
	solution(list);


}
