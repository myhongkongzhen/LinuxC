/*
 * =====================================================================================
 *
 *       Filename:  13-01main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月27日 15时36分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Z_Z.W (ZZW), myhongkongzhen@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <QApplication>
#include <QDialog>

int main(int args,char* argv[]){

	QApplication app(args,argv);

	QDialog dlg;
	dlg.setVisible(true);

	return app.exec();

}

