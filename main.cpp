#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <random>

void draw_painting(Display* display, Window window, GC gc)
{
    // Colors
    unsigned long soft_red =      0xBA362F;
    unsigned long yellow =        0xFABD55;
    unsigned long moonlight =     0xF4F5CB;
    unsigned long light_green =   0x92BA8A;
    unsigned long green =         0x33522D;
    unsigned long dark_green =    0x141C13;
    unsigned long black =         0x000000;
    unsigned long dark_wood =     0x453028;
    unsigned long wood =          0x332F2D;
    unsigned long dark_sky =      0x253045;
    unsigned long light_wood =    0x363331;
    unsigned long dirt =          0x261C19;

    // *******************************
    // *     Painting background     *
    // *******************************
    XSetForeground(display, gc, dark_sky); //Sky
    XFillRectangle(display, window, gc, 0, 0, 800, 600);

    XSetForeground(display, gc, moonlight); //Stars
    for (size_t i = 0; i < 100; i++)
        XFillArc(display, window, gc, (0 + rand()%800), (425 - (rand()%425)), 5, 5, 0, 360*64);

    XSetForeground(display, gc, moonlight); //Moon
    XFillArc(display, window, gc, 250, 200, 100, 100, 0, 360*64);

    XSetForeground(display, gc, light_green); //Trees and bushes behind house
    XFillArc(display, window, gc, -50, 100, 150, 400, 0, 360*64);
    XFillArc(display, window, gc, 0, 110, 150, 400, 0, 360*64);

    XFillArc(display, window, gc, 230, 275, 100, 225, 0, 360*64);
    XFillArc(display, window, gc, 250, 250, 180, 300, 0, 360*64);

    XFillArc(display, window, gc, 600, 400, 25, 25, 0, 360*64);
    XFillArc(display, window, gc, 600, 100, 250, 400, 0, 360*64);

    XSetForeground(display, gc, dark_green); //Ground
    XFillRectangle(display, window, gc, 0, 425, 800, 175);

    // *******************************
    // *       Painting apples       *
    // *******************************
    XSetForeground(display, gc, soft_red);
    XFillArc(display, window, gc, 100, 200, 25, 25, 0, 360*64);
    XFillArc(display, window, gc, 70, 220, 25, 25, 0, 360*64);
    XFillArc(display, window, gc, 110, 300, 25, 25, 0, 360*64);
    XFillArc(display, window, gc, 40, 150, 25, 25, 0, 360*64);

    XFillArc(display, window, gc, 700, 200, 25, 25, 0, 360*64);
    XFillArc(display, window, gc, 670, 130, 25, 25, 0, 360*64);
    XFillArc(display, window, gc, 750, 120, 25, 25, 0, 360*64);
    XFillArc(display, window, gc, 600, 300, 25, 25, 0, 360*64);
    XFillArc(display, window, gc, 590, 320, 25, 25, 0, 360*64);

    // *******************************
    // *     Painting house          *
    // *******************************
    XSetForeground(display, gc, wood); // Roof and wall
    XPoint house[3] = {{200, 450}, {400, 100}, {600, 450}};
    XFillPolygon(display, window, gc, house, 3, Convex, CoordModeOrigin);

    house[0] = {225, 450};
    house[1] = {400, 150};
    house[2] = {575, 450};
    XSetForeground(display, gc, dark_wood);
    XFillPolygon(display, window, gc, house, 3, Convex, CoordModeOrigin);

    XSetForeground(display, gc, light_wood); // Door
    XFillRectangle(display, window, gc, 315, 300, 85, 150);
    XSetForeground(display, gc, wood); // Door handle
    XFillArc(display, window, gc, 375, 370,  15, 15, 0, 360*64);

    XSetForeground(display, gc, light_wood);
    XFillRectangle(display, window, gc, 408, 298, 79, 102); // Window frame

    XSetForeground(display, gc, yellow);
    XFillRectangle(display, window, gc, 410, 300, 75, 100); // Window
    XSetForeground(display, gc, light_wood);
    XFillRectangle(display, window, gc, 438, 300, 7, 100);
    XFillRectangle(display, window, gc, 410, 325, 28, 7);

    XSetForeground(display, gc, dark_wood); // Supports
    XFillRectangle(display, window, gc, 225, 450, 25, 25);
    XFillRectangle(display, window, gc, 550, 450, 25, 25);

    XSetForeground(display, gc, wood); // Stairs
    XFillRectangle(display, window, gc, 300, 450, 115, 15);
    XFillRectangle(display, window, gc, 295, 460, 125, 15);

    XSetForeground(display, gc, dirt); // Path
    XPoint way[4] = {{300, 475}, {415, 475}, {500, 600}, {200, 600}};
    XFillPolygon(display, window, gc, way, 4, Convex, CoordModeOrigin);

    // *******************************
    // *     Painting background     *
    // *******************************
    XSetForeground(display, gc, green); // Trees and bushes on foreground
    XFillArc(display, window, gc, -150, 200, 250, 450, 0, 360*64);
    XFillArc(display, window, gc, -100, 350, 350, 300, 0, 360*64);

    XFillArc(display, window, gc, 600, 225, 250, 375, 0, 360*64);
    XFillArc(display, window, gc, 700, 350, 200, 300, 0, 360*64);

    XSetForeground(display, gc, dark_green); // Close foreground
    XFillArc(display, window, gc, -150, 400, 250, 250, 0, 360*64);
    XFillArc(display, window, gc, 0, 475, 350, 175, 0, 360*64);
    XFillArc(display, window, gc, 0, 450, 125, 200, 0, 360*64);
    XFillArc(display, window, gc, 600, 400, 300, 250, 0, 360*64);
    XFillArc(display, window, gc, 725, 450, 175, 200, 0, 360*64);

    XSetForeground(display, gc, soft_red); //Close apples
    XFillArc(display, window, gc, 750, 300, 30, 30, 0, 360*64);
    XFillArc(display, window, gc, 650, 350, 30, 30, 0, 360*64);
    XFillArc(display, window, gc, 600, 400, 30, 30, 0, 360*64);
    XFillArc(display, window, gc, 650, 250, 30, 30, 0, 360*64);

    XFillArc(display, window, gc, 100, 350, 30, 30, 0, 360*64);
    XFillArc(display, window, gc, 150, 430, 30, 30, 0, 360*64);

    XPoint grass[82];

    for (size_t i = 0; i < 80; i++)
    {
        grass[i].x = i*10;
        grass[i].y = 600 - (rand()%100 + 50);
    }
    grass[80] = {800, 650};
    grass[81] = {0, 650};
    XSetForeground(display, gc, black); // Close grass
    XFillPolygon(display, window, gc, grass, 82, Complex, CoordModeOrigin);
}
int main()
{
    Display *main_display;
    GC gc;
    XEvent event;

    if ((main_display = XOpenDisplay(NULL)) == NULL)
        exit(1);

    int main_screen_number = DefaultScreen(main_display);

    Window main_window = XCreateSimpleWindow(main_display, RootWindow(main_display, main_screen_number), 10, 10, 800, 600, 1, 0xFFFFFF, 0);
    XSelectInput(main_display, main_window, ExposureMask | KeyPressMask| ButtonPressMask);
    XMapWindow(main_display, main_window);

    gc = XCreateGC(main_display, DefaultRootWindow(main_display), 0, 0);
    while(true)
    {
        XNextEvent(main_display, &event);

        if (event.type == Expose) draw_painting(main_display, main_window, gc);
        if ((event.type == KeyPress) && (XLookupKeysym(&event.xkey, 0) == XK_Escape)) break;
        if ((event.type == ButtonPress) && (event.xbutton.x < 10) && (event.xbutton.y < 10)) break;
    }
    XCloseDisplay(main_display);

    return 0;
}
