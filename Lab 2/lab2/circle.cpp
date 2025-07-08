#include <stdio.h>
#include <graphics.h>

void drawCirclePoints(int xc, int yc, int x, int y, int col) {
    putpixel(xc + x, yc + y, col);
    putpixel(xc - x, yc + y, col);
    putpixel(xc + x, yc - y, col);
    putpixel(xc - x, yc - y, col);
    putpixel(xc + y, yc + x, col);
    putpixel(xc - y, yc + x, col);
    putpixel(xc + y, yc - x, col);
    putpixel(xc - y, yc - x, col);
}

void midpointCircle(int xc, int yc, int r, int col) {
    int x = 0;
    int y = r;
    int p = 1 - r;

    drawCirclePoints(xc, yc, x, y, col);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawCirclePoints(xc, yc, x, y, col);
        delay(50);  // Delay for visualization
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xc, yc, r;
    
    printf("Created by Kushal Shah\nMid-Point Circle Drawing Algorithm\n");
    printf("Enter center of the circle (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius of the circle: ");
    scanf("%d", &r);
    
    outtextxy(20, 20, "Kushal Shah");
    
    for(int i=0;i<3;i++){
    	midpointCircle(xc, yc, r+i*15, i+2);
	}

    delay(50000);
    closegraph();
    return 0;
}


