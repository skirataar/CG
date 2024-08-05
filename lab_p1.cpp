#include <cmath>
#include <GL/glut.h>

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void lineBres(int x0, int y0, int xEnd, int yEnd) {
    int dx = std::abs(xEnd - x0), dy = std::abs(yEnd - y0);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
    int x = x0, y = y0;

    if (x0 > xEnd) {
        swap(x0, xEnd);
        swap(y0, yEnd);
    }

    setPixel(x, y);

    while (x < xEnd) {
        x++;
        if (p < 0)
            p += twoDy;
        else {
            y++;
            p += twoDyMinusDx;
        }
        setPixel(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // White color
    lineBres(50, 100, 200, 300);
    glFlush();
}

void init() {
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
