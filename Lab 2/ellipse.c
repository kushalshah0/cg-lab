#include <stdio.h>
#include <graphics.h>

void drawEllipsePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void midpointEllipse(int xc, int yc, int rx, int ry) {
    int x = 0;
    int y = ry;

    // Initial decision parameter of region 1
    long long rxSq = (long long)rx * rx;
    long long rySq = (long long)ry * ry;
    long long twoRxSq = 2 * rxSq;
    long long twoRySq = 2 * rySq;

    long long px = 0;
    long long py = twoRxSq * y;

    // Region 1
    long long p = rySq - (rxSq * ry) + (0.25 * rxSq);

    while (px < py) {
        drawEllipsePoints(xc, yc, x, y);
        x++;
        px += twoRySq;
        if (p < 0) {
            p += rySq + px;
        } else {
            y--;
            py -= twoRxSq;
            p += rySq + px - py;
        }
        delay(20);
    }

    // Region 2
    p = rySq * (x + 0.5) * (x + 0.5) + rxSq * (y - 1) * (y - 1) - rxSq * rySq;

    while (y >= 0) {
        drawEllipsePoints(xc, yc, x, y);
        y--;
        py -= twoRxSq;
        if (p > 0) {
            p += rxSq - py;
        } else {
            x++;
            px += twoRySq;
            p += rxSq - py + px;
        }
        delay(20);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xc, yc, rx, ry;
    printf("Enter center of the ellipse (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius along x-axis (rx): ");
    scanf("%d", &rx);

    printf("Enter radius along y-axis (ry): ");
    scanf("%d", &ry);

    midpointEllipse(xc, yc, rx, ry);

    delay(500);
    closegraph();
    return 0;
}
