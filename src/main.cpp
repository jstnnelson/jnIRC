/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: justin
 */
#include "mainwindow.h"
#include <gtkmm.h>

int main(int argc, char *argv[]){
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	MainWindow main_window;

	//Shows the window and returns when it is closed.
	return app->run(main_window);
}



