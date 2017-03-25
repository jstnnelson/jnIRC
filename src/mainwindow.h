/*
 * mainwindow.h
 *
 *  Created on: Mar 23, 2017
 *      Author: justin
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/paned.h>
#include <gtkmm/textview.h>
#include <gtkmm/window.h>
#include <gtkmm.h>

class MainWindow : public Gtk::ApplicationWindow
{
public:
	MainWindow();
	virtual ~MainWindow();

private:
	//Member widgets:
	Gtk::Entry msg_entry_box;
	Gtk::Paned main_pane, chat_pane;
	Gtk::TextView chat_text, user_list;
	Gtk::Label a;
};


#endif /* MAINWINDOW_H_ */
