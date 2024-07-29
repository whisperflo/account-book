#include"headFile/account_item.h"
#include"headFile/common.h"


int main(){
	//1.加载文件中的账目数据
	vector<AccountItem> accountBooks;
	loadDataFromFile(accountBooks);
	
	bool quit = false;
	while(!quit)
	{
		//2.显示主菜单
		showMainMenu();
		

		//3，读取键盘选择，进行合法性校验
	char key = readMenuSelection();
	
	switch(key){
		case '1' :// 1-记账
			showAccountMenu();	
			accounting(items);
			break;
		case '2':// 2-查询
			showQueryMenu();
			selectAccounts(items);
			break;
		case '3': // 3-退出
			cout << "\n确认退出？ (Y/N):";	
			if(readQuitConfirm() == 'Y') quit = true;
				break;
		default:
			break;
		cout<<endl;
			}
	}	


	return 0;
}
