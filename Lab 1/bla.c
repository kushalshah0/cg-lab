// Bresenham's Line Algorithm to draw a line.

// Including preprocessor directives.
#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Declaring main function.
int main(int argc, char const *argv[])
{
    // Declaring variables.
    int x1, y1, x2, y2, dx, dy, p, x, y;

    // Asking for initial point.
    printf("Enter the initial point (x1 y1):\n");
    scanf("%d %d", &x1, &y1);

    // Asking for final point.
    printf("Enter the final point (x2 y2):\n");
    scanf("%d %d", &x2, &y2);

    // Initializing graphics variables.
    int gd = DETECT, gm;

    // Initializing graphics.
    initgraph(&gd, &gm, NULL);

    // Calculating differences.
    dx = x2 - x1;
    dy = y2 - y1;

    // Initializing starting point.
    x = x1;
    y = y1;

    // Decision parameter
    p = 2 * dy - dx;

    // Drawing the line
    for (int i = 0; i <= dx; i++)
    {
        putpixel(x, y, WHITE); // Draw pixel
        delay(100); // Delay for visualization

        // Increment x coordinate
        x++;

        // Check the decision parameter
        if (p < 0)
        {
            // If the decision parameter is less than 0, do not increment y
            p = p + 2 * dy;
        }
        else
        {
            // If the decision parameter is greater than or equal to 0, increment y
            y++;
            p = p + 2 * (dy - dx);
        }
    }

    // Concluding the program.
    delay(5000);
    closegraph();
    return 0;
}

