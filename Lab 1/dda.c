#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int x, y, x1, y1, x2, y2, dx, dy, steps, m;
	printf("Created by Kushal Shah\nDDA Algorithm\n");
	printf("Enter the initial point\n");
	scanf("%d %d", &x1, &y1);
	printf("Enter the final point\n");
	scanf("%d %d", &x2, &y2);

	dx = x2 - x1;
	dy = y2 - y1;
	m = dy / dx;

	if (dx >= dy)
	{
		steps = dx;
	}
	else
	{
		steps = dy;
	}

	if (m < 1) {
		x = x1 + 1;
		y = y1 + m;
	}
	else if (m > 1) {
		x = x1 + (1 / m);
		y = y1 + m;
	}
	else {
		x = x1 + 1;
		y = y1 + 1;
	}

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	outtextxy(70, 70, "Kushal Shah");
	for (int i = 0; i < steps; i++)
	{
		putpixel(x1, y1, 5);
		x1 += x;
		y1 += y;
		delay(100);
	}

	delay(500000);
	closegraph();
	return 0;
}
