/*
 * =====================================================================================
 *
 *       Filename:  exception.cpp
 *
 *    Description:  異常
 *
 *        Version:  1.0
 *        Created:  2014年08月01日 10时35分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception{
	public:
		//表示這個函數不可能拋出異常
		const char* what()const throw(){
			return "My Exceptin Type!";	
		}
};
class myException{ };

class ME : public exception{
	char msg[100];
	public:
	ME(int n){
		sprintf(msg,"from line %d catch error",n);
	}
	const char* what()const throw(){
		return msg;
	}
};

//異常聲明，一個函數可能拋出的異常
//不聲明表明可能拋出任何類型的異常
int main() /* throw(MyException,myException,\
			  double,int,const char*) */{
				  try{
					  throw MyException();
					  throw myException();
					  throw "hello";
					  throw 12;
					  throw 23.5;
				  }catch(const char* e){
					  //異常對象即使是臨時的，
					  //也會直到處理后再銷毀
					  cout << "----char*----" << endl;
				  }catch(double e){
					  cout << "----double----" << endl;
				  }catch(int e){
					  cout << "----int----" << endl;
				  }catch(myException e){
					  cout << "----myException----" << endl;
				  }catch(MyException e){
					  cout << "----MyException----" << endl;
					  cout << e.what() << endl;
					  throw ME(__LINE__);
				  }catch(exception e){
					  cout << "----exception----" << endl;
				  }catch(...){//可以捕獲任何類型異常
					  //但是無法知道是什麼類型的異常
					  cout << "----every----" << endl;
					  //可以將當前捕獲的異常，重新拋出
					  throw;
				  }
				  cout << "====end of main()====" << endl;
				  return 0;
			  }

