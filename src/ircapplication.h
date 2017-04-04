/*
 * ircapplication.h
 *
 *  Created on: Mar 25, 2017
 *      Author: justin
 */

#ifndef IRCAPPLICATION_H_
#define IRCAPPLICATION_H_

#include <gtkmm.h>

class IRCApplication : public Gtk::Application{
protected:
	IRCApplication();

public:
	static Glib::RefPtr<IRCApplication> create();

protected:
	//Overrides of default signal handlers
	void on_startup() override;
	void on_activate() override;

private:
	void create_window();
	void on_window_hide(Gtk::Window* window);
	void on_menu_file_connect();
	void on_menu_file_quit();
	void on_menu_edit_cut();
	void on_menu_edit_copy();
	void on_menu_edit_paste();
	void on_menu_edit_preferences();
	void on_menu_help_about();

	Glib::RefPtr<Gtk::Builder> m_refBuilder;
};


#endif /* IRCAPPLICATION_H_ */
