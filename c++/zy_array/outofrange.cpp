/*
 * =====================================================================================
 *
 *       Filename:  outofrange.c
 *
 *    Description:   自定義異常類
 *
 *        Version:  1.0
 *        Created:  2014年08月02日 01时14分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "outofrange.h" 

ArrayException::ArrayException(int cur,int max){
	cout << "數組越界異常:"<< cur << "(" << max << ")" << endl;
	sprintf(msg,"數組下標%d無效，最大下標為%d\n",cur,max-1);
}

const char* ArrayException::what()const throw(){
	return msg;
}

