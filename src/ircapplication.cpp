/*
 * ircapplication.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: justin
 */

#include "aboutwindow.h"
#include "ircapplication.h"
#include "mainwindow.h"
#include <iostream>

IRCApplication::IRCApplication()
: Gtk::Application("org.gtkmm.example.main_menu")
{
  Glib::set_application_name("jnIRC");
}

Glib::RefPtr<IRCApplication> IRCApplication::create()
{
  return Glib::RefPtr<IRCApplication>(new IRCApplication());
}

void IRCApplication::on_startup()
{
  Gtk::Application::on_startup();

  add_action("connect", sigc::mem_fun(*this, &IRCApplication::on_menu_file_connect));
  add_action("quit", sigc::mem_fun(*this, &IRCApplication::on_menu_file_quit));
  add_action("cut", sigc::mem_fun(*this, &IRCApplication::on_menu_edit_cut));
  add_action("copy", sigc::mem_fun(*this, &IRCApplication::on_menu_edit_copy));
  add_action("paste", sigc::mem_fun(*this, &IRCApplication::on_menu_edit_paste));
  add_action("preferences", sigc::mem_fun(*this, &IRCApplication::on_menu_edit_preferences));
  add_action("about", sigc::mem_fun(*this, &IRCApplication::on_menu_help_about));

  m_refBuilder = Gtk::Builder::create();

  //Layout the actions in a menubar and an application menu:
  Glib::ustring ui_info =
    "<interface>"
    "  <!-- menubar -->"
    "  <menu id='menu-example'>"
    "    <submenu>"
    "      <attribute name='label' translatable='yes'>_File</attribute>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Connect</attribute>"
    "          <attribute name='action'>app.connect</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;n</attribute>"
    "        </item>"
    "      </section>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Quit</attribute>"
    "          <attribute name='action'>app.quit</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;q</attribute>"
    "        </item>"
    "      </section>"
    "    </submenu>"
    "    <submenu>"
    "      <attribute name='label' translatable='yes'>_Edit</attribute>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>Cut</attribute>"
    "          <attribute name='action'>app.cut</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;x</attribute>"
    "        </item>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>Copy</attribute>"
    "          <attribute name='action'>app.copy</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;c</attribute>"
    "        </item>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>Paste</attribute>"
    "          <attribute name='action'>app.paste</attribute>"
	"          <attribute name='accel'>&lt;Primary&gt;v</attribute>"
    "        </item>"
    "      </section>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>Preferences</attribute>"
    "          <attribute name='action'>app.preferences</attribute>"
    "        </item>"
	"      </section>"
    "    </submenu>"
    "    <submenu>"
    "      <attribute name='label' translatable='yes'>_Help</attribute>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_About</attribute>"
    "          <attribute name='action'>app.about</attribute>"
    "        </item>"
    "      </section>"
    "    </submenu>"
    "  </menu>"
    "</interface>";

  try
  {
    m_refBuilder->add_from_string(ui_info);
  }
  catch (const Glib::Error& ex)
  {
    std::cerr << "Building menus failed: " << ex.what();
  }

  auto object = m_refBuilder->get_object("menu-example");
  auto gmenu = Glib::RefPtr<Gio::Menu>::cast_dynamic(object);
  object = m_refBuilder->get_object("appmenu");
  auto appMenu = Glib::RefPtr<Gio::Menu>::cast_dynamic(object);
  if (!gmenu) {
    g_warning("GMenu or AppMenu not found");
  }
  else
  {
    set_menubar(gmenu);
  }
}

void IRCApplication::on_activate()
{
  //std::cout << "debug1: " << G_STRFUNC << std::endl;
  // The application has been started, so let's show a window.
  // A real application might want to reuse this window in on_open(),
  // when asked to open a file, if no changes have been made yet.
  create_window();
}

void IRCApplication::create_window()
{
  auto win = new MainWindow();

  //Make sure that the application runs for as long this window is still open:
  add_window(*win);

  //Delete the window when it is hidden.
  //That's enough for this simple example.
  win->signal_hide().connect(sigc::bind<Gtk::Window*>(
    sigc::mem_fun(*this, &IRCApplication::on_window_hide), win));

  win->show_all();
}

void IRCApplication::on_window_hide(Gtk::Window* window)
{
  delete window;
}

void IRCApplication::on_menu_file_connect()
{
	  std::cout << "File|Connect was selected." << std::endl;
}

void IRCApplication::on_menu_edit_cut()
{
	  std::cout << "Edit|Cut was selected." << std::endl;
}

void IRCApplication::on_menu_edit_copy()
{
	  std::cout << "Edit|Copy was selected." << std::endl;
}

void IRCApplication::on_menu_edit_paste()
{
	  std::cout << "Edit|Paste was selected." << std::endl;
}

void IRCApplication::on_menu_edit_preferences()
{
	  std::cout << "Edit|Preferences was selected." << std::endl;
}

void IRCApplication::on_menu_file_quit()
{
  quit(); // Not really necessary, when Gtk::Widget::hide() is called.

  // Gio::Application::quit() will make Gio::Application::run() return,
  // but it's a crude way of ending the program. The window is not removed
  // from the application. Neither the window's nor the application's
  // destructors will be called, because there will be remaining reference
  // counts in both of them. If we want the destructors to be called, we
  // must remove the window from the application. One way of doing this
  // is to hide the window.
  std::vector<Gtk::Window*> windows = get_windows();
  if (windows.size() > 0)
    windows[0]->hide(); // In this simple case, we know there is only one window.
}

void IRCApplication::on_menu_help_about()
{
  std::cout << "App|Help|About was selected." << std::endl;
  //gtk_show_about_dialog(get_active_window(), "jnIRC", "ExampleCode", NULL);
  AboutWindow aboutwindow;
}
