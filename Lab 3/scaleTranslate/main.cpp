#include <stdio.h>
#include <graphics.h>

void scaleTranslate(int *x, int *y, float sx, float sy, int tx, int ty) {
    *x = *x * sx + tx;
    *y *= *y * sy + ty;
}

void plotLines(int x1, int y1, int x2, int y2, int x3, int y3){
	line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void plotScaledTranslatedLines(int x1, int y1, int x2, int y2, int x3, int y3, float sx, float sy, int tx, int ty){
	line(x1*sx+tx, y1*sy+ty, x2*sx+tx, y2*sy+ty);
    line(x2*sx+tx, y2*sy+ty, x3*sx+tx, y3*sy+ty);
    line(x3*sx+tx, y3*sy+ty, x1*sx+tx, y1*sy+ty);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 130, y1 = 80;
    int x2 = 80, y2 = 180;
    int x3 = 180, y3 = 180;
    int tx,ty;
	float sx,sy;

    plotLines(x1,y1,x2,y2,x3,y3);
	
	outtextxy(x1-70, y1-20, "Original Triangle");

    outtextxy(30, 10, "Kushal Shah");
    
	printf("Enter the translation factors = ");
	scanf("%d%d",&tx,&ty);
	
    printf("Enter the scaling factors = ");
	scanf("%f%f",&sx,&sy);
	
	plotScaledTranslatedLines(x1,y1,x2,y2,x3,y3,sx,sy,tx,ty);

	scaleTranslate(&x1, &y1, sx, sy, tx, ty);
    scaleTranslate(&x2, &y2, sx, sy, tx, ty);
    scaleTranslate(&x3, &y3, sx, sy, tx, ty);

	outtextxy(170, 380, "Scaled Translated Triangle");

    delay(50000);
    closegraph();
    return 0;
}

