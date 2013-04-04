#include <xview/xview.h>

int main()
{
    Frame frame;

    frame = (Frame)xv_create(XV_NULL, FRAME, XV_NULL);
    xv_main_loop(frame);
    return 0;
}
