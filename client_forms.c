#include <forms.h>

int main(int argc, char **argv)
{
    FL_FORM *form;

    fl_initialize(&argc, argv, 0, 0, 0);

    form = fl_bgn_form(FL_UP_BOX, 230, 100);
    fl_add_button(FL_NORMAL_BUTTON, 20, 20, 190, 60, "Looks good!");
    fl_end_form();

    fl_show_form(form, FL_PLACE_MOUSE, FL_FULLBORDER, "Hello, world!");

    fl_do_forms();

    fl_hide_form(form);
    fl_finish();
    return 0;
}
