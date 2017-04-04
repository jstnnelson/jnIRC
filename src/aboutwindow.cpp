/*
 * aboutwindow.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: justin
 */

#include "aboutwindow.h"
#include <vector>

AboutWindow::AboutWindow(){
	set_program_name("jnIRC");
	set_comments("Simple IRC program");

	set_authors(std::vector<Glib::ustring> {"Justin Nelson"});
	run();
}

AboutWindow::~AboutWindow(){

}
