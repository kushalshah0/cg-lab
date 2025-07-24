#include <stdio.h>
#include <graphics.h>
#include <math.h>

void scaleTranslate(int *x, int *y, float sx, float sy, int tx, int ty) {
    *x = *x * sx + tx;
    *y = *y * sy + ty;
}

void rotate(int *x, int *y, float angle_deg, int xr, int yr) {
    float angle_rad = angle_deg * M_PI / 180.0;
    int x_old = *x, y_old = *y;
    *x = xr + (int)((x_old - xr) * cos(angle_rad) - (y_old - yr) * sin(angle_rad));
    *y = yr + (int)((x_old - xr) * sin(angle_rad) + (y_old - yr) * cos(angle_rad));
}

void reflect(int *x, int *y, char axis) {
    if(axis == 'x' || axis == 'X')
        *y = -(*y);
    else if(axis == 'y' || axis == 'Y')
        *x = -(*x);
}

void shear(int *x, int *y, float shx, float shy) {
    int x_old = *x, y_old = *y;
    *x = x_old + shx * y_old;
    *y = y_old + shy * x_old;
}

void plotLines(int x1, int y1, int x2, int y2, int x3, int y3){
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 130, y1 = 80;
    int x2 = 80, y2 = 180;
    int x3 = 180, y3 = 180;

    plotLines(x1, y1, x2, y2, x3, y3);
    outtextxy(x1-70, y1-20, "Original Triangle");
    outtextxy(30, 10, "Kushal Shah");

    // Translation and Scaling
    int tx, ty;
    float sx, sy;
    printf("Enter the translation factors = ");
    scanf("%d%d", &tx, &ty);
    printf("Enter the scaling factors = ");
    scanf("%f%f", &sx, &sy);

    int xt1 = x1, yt1 = y1, xt2 = x2, yt2 = y2, xt3 = x3, yt3 = y3;
    scaleTranslate(&xt1, &yt1, sx, sy, tx, ty);
    scaleTranslate(&xt2, &yt2, sx, sy, tx, ty);
    scaleTranslate(&xt3, &yt3, sx, sy, tx, ty);
    plotLines(xt1, yt1, xt2, yt2, xt3, yt3);
    outtextxy(170, 380, "Scaled & Translated");

    // Rotation
    float angle;
    printf("Enter angle for rotation (degrees): ");
    scanf("%f", &angle);
    int xr = x1, yr = y1; // Rotate about first vertex
    int xr1 = x1, yr1 = y1, xr2 = x2, yr2 = y2, xr3 = x3, yr3 = y3;
    rotate(&xr1, &yr1, angle, xr, yr);
    rotate(&xr2, &yr2, angle, xr, yr);
    rotate(&xr3, &yr3, angle, xr, yr);
    plotLines(xr1, yr1, xr2, yr2, xr3, yr3);
    outtextxy(300, 50, "Rotated");

    // Reflection
    char axis;
    printf("Enter axis for reflection (x/y): ");
    scanf(" %c", &axis);
    int rf1 = x1, rf2 = x2, rf3 = x3, rf4 = y1, rf5 = y2, rf6 = y3;
    reflect(&rf1, &rf4, axis);
    reflect(&rf2, &rf5, axis);
    reflect(&rf3, &rf6, axis);
    plotLines(rf1, rf4, rf2, rf5, rf3, rf6);
    outtextxy(30, 400, "Reflected");

    // Shearing
    float shx, shy;
    printf("Enter shearing factors (shx shy): ");
    scanf("%f%f", &shx, &shy);
    int sh1 = x1, sh2 = x2, sh3 = x3, sh4 = y1, sh5 = y2, sh6 = y3;
    shear(&sh1, &sh4, shx, shy);
    shear(&sh2, &sh5, shx, shy);
    shear(&sh3, &sh6, shx, shy);
    plotLines(sh1, sh4, sh2, sh5, sh3, sh6);
    outtextxy(400, 400, "Sheared");

    delay(50000);
    closegraph();
    return 0;
}
