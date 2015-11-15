#include <ctime>
#include <iostream>
#include <X11/Xlib.h>
#include <unistd.h>

int main()
{
    std::time_t result;

    Display *dpy;
    if (!(dpy = XOpenDisplay(NULL)))
    {
        std::cerr << "dwmstatus: cannot open display.\n";
        return 1;
    }

    for (;; sleep(1))
    {
        result = std::time(NULL);

        XStoreName(dpy, DefaultRootWindow(dpy), std::asctime(std::localtime(&result)) );
        XSync(dpy, False);
    }
    XCloseDisplay(dpy);
}
