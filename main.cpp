#include <gtkmm/application.h>
#include <gtkmm/applicationwindow.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/builder.h>
#include <gtkmm/image.h>

#include "pog.h"
#include <iostream>

class SenkoWindow : public Gtk::ApplicationWindow {
    Gtk::Box *cont;
    Glib::RefPtr<Gtk::Label> display_label;
    Glib::RefPtr<Gtk::Button> display_btn;
    Glib::RefPtr<Gtk::Image> display_image;
    Glib::RefPtr<Gtk::Builder> ui;

public:
    SenkoWindow()
            : ui{Gtk::Builder::create_from_file("simple.glade")} {
        if(ui) {
            ui->get_widget<Gtk::Box>("cont", cont);
            display_label = Glib::RefPtr<Gtk::Label>::cast_dynamic(
                    ui->get_object("display_label")
            );
            display_btn = Glib::RefPtr<Gtk::Button>::cast_dynamic(
                    ui->get_object("display_button")
            );
            display_image = Glib::RefPtr<Gtk::Image>::cast_dynamic(
                    ui->get_object("display_image")
            );

            if(cont && display_label && display_btn && display_image) {
                display_btn->signal_clicked().connect(
                        [this]() {
                            display_image->set("resource:///org/image.png");
                            // std::cout << GResource << '/n';
                        });
                display_label->set_text("Are You Pog?");
                add(*cont);
            }
        }
        set_title("Are you pog?");
        set_default_size(400, 400);
        show_all();
    }
};

int main(int argc, char *argv[]) {
    pog_register_resource();
    auto app = Gtk::Application::create(
            argc, argv,
            "org.gtkmm.example.HelloApp"
    );
    SenkoWindow sw;
    return app->run(sw);
}