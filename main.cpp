#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <time.h>

void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void mouseFunction(int button, int state, int x, int y);
void resize(int, int);
void drawMainBuildingBody();
void drawSecondaryBuildingBody();
void drawHallBuildingBody();
void BagianDepan();
void BagianDepan2(int x, int y);
void BagianDepanAtas2(int x, int y);
void BagianDepanAtas2_2(int x2, int y2);
void PembatasBagianDepanAtas2_2(int x2, int y2);
void Box(int x, int y);
void Box2(int x, int y);
void Tengah3(int y);
void Tengah3_2(int y);
void SampingKiriPembatas(int y);
void SampingKiri(int x, int y, int z);
void Jendela(int x, int y, int z);
void PembatasTengah(int x);
void Puncak1();
void drawTree(int x, int y);
int is_depth;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("Freie Universität Berlin");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(resize);

    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    // gambar tanah
    glBegin(GL_QUADS);
    glColor3f(0.925f, 0.862f, 0.76f);
    glVertex3f(-200.0, 0.0, -200.0);
    glVertex3f(-200.0, 0.0, 200.0);
    glVertex3f(200.0, 0.0, 200.0);
    glVertex3f(200.0, 0.0, -200.0);
    glEnd();

    BagianDepan();
    int a = 0;
    int i;

    for (i = 1; i <= 4; i++)
    {
        if (i == 1)
        {
            glColor3f(0.529, 0.808, 0.921);
            BagianDepanAtas2(a, a);
            glColor3f(1.0, 0.549, 0.0);
            BagianDepanAtas2_2(a, a);
            PembatasBagianDepanAtas2_2(a, a);
            BagianDepan2(a, 0);
        }
        else if (i == 2 || i == 3)
        {
            a += 6;
            glColor3f(0.529, 0.808, 0.921);
            BagianDepanAtas2(0, 0);
            BagianDepanAtas2_2(a, 0);
            PembatasBagianDepanAtas2_2(a, 0);
        }
        else
        {
            a += 6;
            glColor3f(0.529, 0.808, 0.921);
            BagianDepanAtas2(a, 0);
            glColor3f(1.0, 0.549, 0.0);
            BagianDepanAtas2_2(a, 0);
            PembatasBagianDepanAtas2_2(a, 0);
            BagianDepan2(a, 0);
        }
    }

    a = 6;
    for (int i = 1; i <= 2; i++)
    {

        glColor3f(0.568, 0.286, 0.0);
        BagianDepanAtas2(a, -12);
        glColor3f(1.0, 0.549, 0.0);
        BagianDepanAtas2_2(a, -12);
        a += 6;
    }

    a = 0;
    int b;
    b = 36, 9;
    for (i = 1; i <= 3; i++)
    {
        if (i == 1)
        {
            glColor3f(0.529, 0.808, 0.921);
            BagianDepanAtas2(b, a);
            glColor3f(1.0, 0.549, 0.0);
            BagianDepanAtas2_2(b, a);
            PembatasBagianDepanAtas2_2(36.9, a);
            BagianDepan2(36.9, 0);
            BagianDepan2(36.9, -23);
        }
        else if (i == 2)
        {
            b += 10;
            glColor3f(0.529, 0.808, 0.921);
            BagianDepanAtas2(a, 0);
            glColor3f(0.529, 0.808, 0.921);
            BagianDepanAtas2_2(b, 0);
            PembatasBagianDepanAtas2_2(b, 0);
        }
        else
        {
            glColor3f(0.568, 0.286, 0.0);
            BagianDepanAtas2(b, -12);
            glColor3f(1.0, 0.549, 0.0);
            BagianDepanAtas2_2(b, -12);
        }
    }

    a = 0;
    b = 36, 9;
    for (i = 1; i <= 3; i++)
    {
        if (i == 1)
        {
            glColor3f(0.529, 0.808, 0.921);
            BagianDepanAtas2(b, a - 23);
            glColor3f(1.0, 0.549, 0.0);
            BagianDepanAtas2_2(b, a - 23);
            PembatasBagianDepanAtas2_2(36.9, a - 23);
        }
        else if (i == 2)
        {
            b += 10;
            glColor3f(0.529, 0.808, 0.921);
            BagianDepanAtas2(a, 0 - 23);
            glColor3f(0.529, 0.808, 0.921);
            BagianDepanAtas2_2(b, -23);
            PembatasBagianDepanAtas2_2(b, -23);
        }
        else
        {
            glColor3f(0.568, 0.286, 0.0);
            BagianDepanAtas2(b, -35);
            glColor3f(1.0, 0.549, 0.0);
            BagianDepanAtas2_2(b, -23);
        }
    }

    a = 0;
    b = 0;

    for (i = 1; i <= 17; i++)
    {
        if (i <= 2 || i == 5 || i == 6 || i >= 10 && i <= 11)
        {
            SampingKiri(0, 0, a);
            a -= 3.7;
        }
        else if (i >= 2 && i <= 4 || i >= 7 && i <= 9 || i >= 12 && i <= 14)
        {
            Jendela(0, 0, a);
            a -= 3.7;
        }
        else
        {
            SampingKiri(0, 0, a);
            a -= 3.7;
        }
    }

    a = 0;
    b = -23;
    int c = 0;
    for (i = 1; i <= 7; i++)
    {
        PembatasTengah(c);
        c -= 3.0;
    }

    for (i = 1; i <= 6; i++)
    {
        if (i <= 2 || i == 5 || i == 6)
        {
            SampingKiri(0, b, a);
            SampingKiriPembatas(0);
            SampingKiriPembatas(b);
            a -= 3.7;
            c -= 4.0;
        }
        else if (i >= 2 && i <= 4)
        {
            Jendela(0, b, a);
            a -= 3.7;
            c -= 40.0;
        }
        else
        {
            SampingKiri(0, b, a);
            a -= 3.7;
            c -= 4.0;
        }
    }

    Box(0, 0);
    Box(6, 0);
    Box(40, 0);
    Box2(46, 0);
    Box2(35.9, 0);
    Box(40, -23);
    Box2(35.9, -23);
    Box2(46, -23);
    Puncak1();
    Tengah3_2(0);
    Tengah3(0);
    Tengah3_2(-23);
    Tengah3(-23);
    drawMainBuildingBody();
    drawSecondaryBuildingBody();
    glutMouseFunc(mouseFunction);
    glutSwapBuffers();
}

void drawTree(int x, int y)
{
    //daun
    glColor3ub(46, 139, 87);
    glBegin(GL_TRIANGLES);
    glVertex3f(x - 1, y * 2, 50);
    glVertex3f(x + 6, y - 5, 50);
    glVertex3f(x - 9, y - 5, 50);
    glEnd();
    //pohon
    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);
    glVertex3f(x, 0, 50);
    glVertex3f(x, y, 50);
    glVertex3f(x - 3, y, 50);
    glVertex3f(x - 3, 0, 50);
    glEnd();
}

void drawMainBuildingBody()
{
    float y_axis = 40.0;

    glColor3f(0.568, 0.286, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10, y_axis, 50); /* front */
    glVertex3f(-10, 0.0, 50);
    glVertex3f(50, 0.0, 50);
    glVertex3f(50, y_axis, 50);

    glVertex3f(50, y_axis, -5); /* back */
    glVertex3f(50, 0.0, -5);
    glVertex3f(-10, 0.0, -5);
    glVertex3f(-10, y_axis, -5);

    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(50, y_axis, 50); /* right */
    glVertex3f(50, 0.0, 50);
    glVertex3f(50, 0.0, -5);
    glVertex3f(50, y_axis, -5);

    glVertex3f(-10, y_axis, -5); /* left */
    glVertex3f(-10, 0.0, -5);
    glVertex3f(-10, 0.0, 50);
    glVertex3f(-10, y_axis, 50);

    glVertex3f(-10, y_axis, 50); /* top */
    glVertex3f(50, y_axis, 50);
    glVertex3f(50, y_axis, -5);
    glVertex3f(-10, y_axis, -5);

    glColor3f(0.925f, 0.862f, 0.76f);
    glVertex3f(-10, 0.0, -5); /* bottom */
    glVertex3f(50, 0.0, -5);
    glVertex3f(50, 0.0, 50);
    glVertex3f(-10, 0.0, 50);
    glEnd();
}

void Puncak1()
{
    int y_axis;
    y_axis = 40;

    glPushMatrix();
    glTranslatef(0, 23, 0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.1, 17, 50.0);
    glVertex3f(-1.1, 22, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-9.5, 22, 50); /* front */
    glVertex3f(-9.5, 17, 50);
    glVertex3f(-1, 17, 50.0);
    glVertex3f(-1, 22, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.7, 17, 50.0);
    glVertex3f(4.7, 22, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-0.5, 22, 50); /* front */
    glVertex3f(-0.5, 17, 50);
    glVertex3f(4.8, 17, 50.0);
    glVertex3f(4.8, 22, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(10.6, 17, 50.0);
    glVertex3f(10.6, 22, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(5.2, 22, 50); /* front */
    glVertex3f(5.2, 17, 50);
    glVertex3f(10.7, 17, 50.0);
    glVertex3f(10.7, 22, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(16.7, 17, 50.0);
    glVertex3f(16.7, 22, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(11.1, 22, 50); /* front */
    glVertex3f(11.1, 17, 50);
    glVertex3f(16.8, 17, 50.0);
    glVertex3f(16.8, 22, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(20.3, 17, 50.0);
    glVertex3f(20.3, 22, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(17.2, 22, 50); /* front */
    glVertex3f(17.2, 17, 50);
    glVertex3f(20.4, 17, 50.0);
    glVertex3f(20.4, 22, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(25.3, 17, 50.0);
    glVertex3f(25.3, 22, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(20.8, 22, 50); /* front */
    glVertex3f(20.8, 17, 50);
    glVertex3f(25.4, 17, 50.0);
    glVertex3f(25.4, 22, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(28.7, 17, 50.0);
    glVertex3f(28.7, 22, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(25.8, 22, 50); /* front */
    glVertex3f(25.8, 17, 50);
    glVertex3f(28.8, 17, 50.0);
    glVertex3f(28.8, 22, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(34.6, 17, 50.0);
    glVertex3f(34.6, 22, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(29.2, 22, 50); /* front */
    glVertex3f(29.2, 17, 50);
    glVertex3f(34.7, 17, 50.0);
    glVertex3f(34.7, 22, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(38.3, 17, 50.0);
    glVertex3f(38.3, 22, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(35.1, 22, 50); /* front */
    glVertex3f(35.1, 17, 50);
    glVertex3f(38.4, 17, 50.0);
    glVertex3f(38.4, 22, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(44.6, 17, 50.0);
    glVertex3f(44.6, 22, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(38.8, 22, 50); /* front */
    glVertex3f(38.8, 17, 50);
    glVertex3f(44.7, 17, 50.0);
    glVertex3f(44.7, 22, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(49.4, 17, 50.0);
    glVertex3f(49.4, 22, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(45.1, 22, 50); /* front */
    glVertex3f(45.1, 17, 50);
    glVertex3f(49.5, 17, 50.0);
    glVertex3f(49.5, 22, 50.0);
    glEnd();

    glColor3ub(210, 180, 140);
    glBegin(GL_QUADS);
    glVertex3f(-10, 22, 50); /* front */
    glVertex3f(-10, 17.0, 50);
    glVertex3f(50, 17.0, 50);
    glVertex3f(50, 22, 50);
    glEnd();
    glPopMatrix();

    glColor3f(0.568, 0.286, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10, y_axis, 50); /* front */
    glVertex3f(-10, 45.0, 50);
    glVertex3f(50, 45.0, 50);
    glVertex3f(50, y_axis, 50);

    glVertex3f(50, y_axis, -5); /* back */
    glVertex3f(50, 45.0, -5);
    glVertex3f(-10, 45.0, -5);
    glVertex3f(-10, y_axis, -5);

    glVertex3f(50, y_axis, 50); /* right */
    glVertex3f(50, 45.0, 50);
    glVertex3f(50, 45.0, -5);
    glVertex3f(50, y_axis, -5);

    glVertex3f(-10, y_axis, -5); /* left */
    glVertex3f(-10, 45.0, -5);
    glVertex3f(-10, 45.0, 50);
    glVertex3f(-10, y_axis, 50);

    glVertex3f(-10, y_axis, 50); /* top */
    glVertex3f(50, y_axis, 50);
    glVertex3f(50, y_axis, -5);
    glVertex3f(-10, y_axis, -5);

    glVertex3f(-10, 45.0, -5); /* bottom */
    glVertex3f(50, 45.0, -5);
    glVertex3f(50, 45.0, 50);
    glVertex3f(-10, 45.0, 50);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(-10, y_axis, 50); /* front */
    glVertex3f(-10, 45.0, 50);
    glVertex3f(50, 45.0, 50);
    glVertex3f(50, y_axis, 50);
    glEnd();
}

void drawSecondaryBuildingBody()
{
    float y_axis = 30.0;

    glPushMatrix();
    glTranslatef(0, 18, 0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.5, 12, 30);
    glVertex3f(-10.5, 17, 30);
    glVertex3f(-10.5, 17, 30);
    glVertex3f(-16, 17, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.280, 0.0);
    glVertex3f(-10.5, 17, 30); /* front */
    glVertex3f(-10.5, 12, 30);
    glVertex3f(-16, 12, 30);
    glVertex3f(-16, 17, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-16.3, 12, 30);
    glVertex3f(-16.3, 17, 30);
    glVertex3f(-16.3, 17, 30);
    glVertex3f(-25, 17, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-16.3, 17, 30); /* front */
    glVertex3f(-16.3, 12, 30);
    glVertex3f(-25, 12, 30);
    glVertex3f(-25, 17, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-25.3, 12, 30);
    glVertex3f(-25.3, 17, 30);
    glVertex3f(-25.3, 17, 30);
    glVertex3f(-30.8, 17, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-25.3, 17, 30); /* front */
    glVertex3f(-25.3, 12, 30);
    glVertex3f(-30.8, 12, 30);
    glVertex3f(-30.8, 17, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-31.1, 12, 30);
    glVertex3f(-31.1, 17, 30);
    glVertex3f(-31.1, 17, 30);
    glVertex3f(-34.3, 17, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-31.1, 17, 30); /* front */
    glVertex3f(-31.1, 12, 30);
    glVertex3f(-34.3, 12, 30);
    glVertex3f(-34.3, 17, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-34.6, 12, 30);
    glVertex3f(-34.6, 17, 30);
    glVertex3f(-34.6, 17, 30);
    glVertex3f(-40.1, 17, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-34.6, 17, 30); /* front */
    glVertex3f(-34.6, 12, 30);
    glVertex3f(-40.1, 12, 30);
    glVertex3f(-40.1, 17, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-40.4, 12, 30);
    glVertex3f(-40.4, 17, 30);
    glVertex3f(-40.4, 17, 30);
    glVertex3f(-46.1, 17, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-40.4, 17, 30); /* front */
    glVertex3f(-40.4, 12, 30);
    glVertex3f(-46.1, 12, 30);
    glVertex3f(-46.1, 17, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-46.4, 12, 30);
    glVertex3f(-46.4, 17, 30);
    glVertex3f(-46.4, 17, 30);
    glVertex3f(-51.1, 17, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-46.4, 17, 30); /* front */
    glVertex3f(-46.4, 12, 30);
    glVertex3f(-51.1, 12, 30);
    glVertex3f(-51.1, 17, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-51.5, 12, 30);
    glVertex3f(-51.5, 17, 30);
    glVertex3f(-51.5, 17, 30);
    glVertex3f(-55, 17, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-51.5, 17, 30); /* front */
    glVertex3f(-51.5, 12, 30);
    glVertex3f(-55, 12, 30);
    glVertex3f(-55, 17, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(210, 180, 140);
    glVertex3f(-10, 17, 30); /* front */
    glVertex3f(-10, 12, 30);
    glVertex3f(-55, 12, 30);
    glVertex3f(-55, 17, 30);
    glEnd();
    glPopMatrix();

    glColor3f(0.568, 0.286, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-1, y_axis, 30); /* front */
    glVertex3f(-1, 35.0, 30);
    glVertex3f(-4, 35.0, 30);
    glVertex3f(-4, y_axis, 30);

    glVertex3f(-10, y_axis, -55); /* back */
    glVertex3f(-10, 35.0, -55);
    glVertex3f(-55, 35.0, -55);
    glVertex3f(-55, y_axis, -55);

    glVertex3f(-10, y_axis, 30); /* right */
    glVertex3f(-10, 35.0, 30);
    glVertex3f(-10, 35.0, -55);
    glVertex3f(-10, y_axis, -55);

    glVertex3f(-55, y_axis, -55); /* left */
    glVertex3f(-55, 35.0, -55);
    glVertex3f(-55, 35.0, 30);
    glVertex3f(-55, y_axis, 30);

    glVertex3f(-55, y_axis, 30); /* top */
    glVertex3f(-10, y_axis, 30);
    glVertex3f(-10, y_axis, -55);
    glVertex3f(-55, y_axis, -55);

    glVertex3f(-55, 35.0, -55); /* bottom */
    glVertex3f(-10, 35.0, -55);
    glVertex3f(-10, 35.0, 30);
    glVertex3f(-55, 35.0, 30);
    glEnd();
    //////////////////////UJUNG ATAS//////////////////
    glColor3f(0.568, 0.286, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-1, y_axis, 30); /* front */
    glVertex3f(-1, 0.0, 30);
    glVertex3f(-4, 0.0, 30);
    glVertex3f(-4, y_axis, 30);

    glVertex3f(-10, y_axis, -55); /* back */
    glVertex3f(-10, 0.0, -55);
    glVertex3f(-55, 0.0, -55);
    glVertex3f(-55, y_axis, -55);

    glVertex3f(-10, y_axis, 30); /* right */
    glVertex3f(-10, 0.0, 30);
    glVertex3f(-10, 0.0, -55);
    glVertex3f(-10, y_axis, -55);

    glVertex3f(-55, y_axis, -55); /* left */
    glVertex3f(-55, 0.0, -55);
    glVertex3f(-55, 0.0, 30);
    glVertex3f(-55, y_axis, 30);

    glVertex3f(-55, y_axis, 30); /* top */
    glVertex3f(-10, y_axis, 30);
    glVertex3f(-10, y_axis, -55);
    glVertex3f(-55, y_axis, -55);

    glVertex3f(-55, 0.0, -55); /* bottom */
    glVertex3f(-10, 0.0, -55);
    glVertex3f(-10, 0.0, 30);
    glVertex3f(-55, 0.0, 30);
    glEnd();

    /////////////////////TEMBOK KANAN/////////////////////////
    glColor3ub(210, 180, 140);
    glBegin(GL_QUADS);
    glVertex3f(50, 23, 50);
    glVertex3f(50, 17, 50);
    glVertex3f(50.1, 17, -5);
    glVertex3f(50.1, 23, -5);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 17.5, 50);
    glVertex3f(50.1, 22.5, 50);
    glVertex3f(50.2, 22.5, 50);
    glVertex3f(50.2, 22.5, 47);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 17.5, 50);
    glVertex3f(50.1, 22.5, 50);
    glVertex3f(50.2, 22.5, 47);
    glVertex3f(50.2, 17.5, 47);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 17.5, 46);
    glVertex3f(50.1, 22.5, 46);
    glVertex3f(50.2, 22.5, 25);
    glVertex3f(50.2, 17.5, 25);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 17.5, 46);
    glVertex3f(50.1, 22.5, 46);
    glVertex3f(50.2, 22.5, 46);
    glVertex3f(50.2, 22.5, 25);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 17.5, 24.5);
    glVertex3f(50.1, 22.5, 24.5);
    glVertex3f(50.2, 22.5, 24.5);
    glVertex3f(50.2, 22.5, 19);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 17.5, 24.5);
    glVertex3f(50.1, 22.5, 24.5);
    glVertex3f(50.2, 22.5, 19);
    glVertex3f(50.2, 17.5, 19);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 17.5, -4.5);
    glVertex3f(50.1, 22.5, -4.5);
    glVertex3f(50.2, 22.5, 18.5);
    glVertex3f(50.2, 17.5, 18.5);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 17.5, 18.5);
    glVertex3f(50.1, 22.5, 18.5);
    glVertex3f(50.2, 22.5, 18.5);
    glVertex3f(50.2, 22.5, -4.5);
    glEnd();

    /////////////////////////////////KANAN BAWAH//////////////////////////////////////
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 0.5, 50);
    glVertex3f(50.1, 16.5, 50);
    glVertex3f(50.2, 16.5, 50);
    glVertex3f(50.2, 16.5, 47);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 0.5, 50);
    glVertex3f(50.1, 16.5, 50);
    glVertex3f(50.2, 16.5, 47);
    glVertex3f(50.2, 0.5, 47);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 0.5, 46);
    glVertex3f(50.1, 16.5, 46);
    glVertex3f(50.2, 16.5, 46);
    glVertex3f(50.2, 16.5, 39.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 0.5, 46);
    glVertex3f(50.1, 16.5, 46);
    glVertex3f(50.2, 16.5, 39.5);
    glVertex3f(50.2, 0.5, 39.5);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 0.5, 39);
    glVertex3f(50.1, 16.5, 39);
    glVertex3f(50.2, 16.5, 39);
    glVertex3f(50.2, 16.5, 32.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(50.1, 0.5, 39);
    glVertex3f(50.1, 16.5, 39);
    glVertex3f(50.2, 16.5, 32.5);
    glVertex3f(50.2, 0.5, 32.5);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 0.5, 32);
    glVertex3f(50.1, 16.5, 32);
    glVertex3f(50.2, 16.5, 32);
    glVertex3f(50.2, 16.5, 25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 0.5, 32);
    glVertex3f(50.1, 16.5, 32);
    glVertex3f(50.2, 16.5, 25);
    glVertex3f(50.2, 0.5, 25);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 0.5, 24.5);
    glVertex3f(50.1, 16.5, 24.5);
    glVertex3f(50.2, 16.5, 24.5);
    glVertex3f(50.2, 16.5, 19);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 0.5, 24.5);
    glVertex3f(50.1, 16.5, 24.5);
    glVertex3f(50.2, 16.5, 19);
    glVertex3f(50.2, 0.5, 19);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 0.5, 11.33);
    glVertex3f(50.1, 16.5, 11.33);
    glVertex3f(50.2, 16.5, 18.5);
    glVertex3f(50.2, 0.5, 18.5);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 0.5, 18.5);
    glVertex3f(50.1, 16.5, 18.5);
    glVertex3f(50.2, 16.5, 18.5);
    glVertex3f(50.2, 16.5, 11.33);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(50.1, 0.5, 3.66);
    glVertex3f(50.1, 16.5, 3.66);
    glVertex3f(50.2, 16.5, 10.83);
    glVertex3f(50.2, 0.5, 10.83);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 0.5, 10.83);
    glVertex3f(50.1, 16.5, 10.83);
    glVertex3f(50.2, 16.5, 10.83);
    glVertex3f(50.2, 16.5, 3.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 0.5, -4.5);
    glVertex3f(50.1, 16.5, -4.5);
    glVertex3f(50.2, 16.5, 3.16);
    glVertex3f(50.2, 0.5, 3.16);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 0.5, 3.16);
    glVertex3f(50.1, 16.5, 3.16);
    glVertex3f(50.2, 16.5, 3.16);
    glVertex3f(50.2, 16.5, -4.5);

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 23.5, 50);
    glVertex3f(50.1, 39.5, 50);
    glVertex3f(50.2, 39.5, 50);
    glVertex3f(50.2, 39.5, 47);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 39.5, 50);
    glVertex3f(50.1, 23.5, 50);
    glVertex3f(50.2, 23.5, 47);
    glVertex3f(50.2, 39.5, 47);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 39.5, 46);
    glVertex3f(50.1, 31, 46);
    glVertex3f(50.2, 31, 25);
    glVertex3f(50.2, 39.5, 25);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 31, 46);
    glVertex3f(50.1, 39.5, 46);
    glVertex3f(50.2, 39.5, 46);
    glVertex3f(50.2, 39.5, 25);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 23.5, 46);
    glVertex3f(50.1, 30.5, 46);
    glVertex3f(50.2, 30.5, 46);
    glVertex3f(50.2, 30.5, 39.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 30.5, 46);
    glVertex3f(50.1, 23.5, 46);
    glVertex3f(50.2, 23.5, 39.5);
    glVertex3f(50.2, 30.5, 39.5);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 23.5, 39);
    glVertex3f(50.1, 30.5, 39);
    glVertex3f(50.2, 30.5, 39);
    glVertex3f(50.2, 30.5, 32.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(50.1, 30.5, 39);
    glVertex3f(50.1, 23.5, 39);
    glVertex3f(50.2, 23.5, 32.5);
    glVertex3f(50.2, 30.5, 32.5);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 23.5, 32);
    glVertex3f(50.1, 30.5, 32);
    glVertex3f(50.2, 30.5, 32);
    glVertex3f(50.2, 30.5, 25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 30.5, 32);
    glVertex3f(50.1, 23.5, 32);
    glVertex3f(50.2, 23.5, 25);
    glVertex3f(50.2, 30.5, 25);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 23.5, 24.5);
    glVertex3f(50.1, 39.5, 24.5);
    glVertex3f(50.2, 39.5, 24.5);
    glVertex3f(50.2, 39.5, 22);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(50.1, 39.5, 24.5);
    glVertex3f(50.1, 23.5, 24.5);
    glVertex3f(50.2, 23.5, 22);
    glVertex3f(50.2, 39.5, 22);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 23.5, 21.5);
    glVertex3f(50.1, 39.5, 21.5);
    glVertex3f(50.2, 39.5, 21.5);
    glVertex3f(50.2, 39.5, 19);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(50.1, 39.5, 21.5);
    glVertex3f(50.1, 23.5, 21.5);
    glVertex3f(50.2, 23.5, 19);
    glVertex3f(50.2, 39.5, 19);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 39.5, -4.5);
    glVertex3f(50.1, 31, -4.5);
    glVertex3f(50.2, 31, 18.5);
    glVertex3f(50.2, 39.5, 18.5);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 31, 18.5);
    glVertex3f(50.1, 39.5, 18.5);
    glVertex3f(50.2, 39.5, 18.5);
    glVertex3f(50.2, 39.5, -4.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 30.5, 11.33);
    glVertex3f(50.1, 23.5, 11.33);
    glVertex3f(50.2, 23.5, 18.5);
    glVertex3f(50.2, 30.5, 18.5);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 23.5, 18.5);
    glVertex3f(50.1, 30.5, 18.5);
    glVertex3f(50.2, 30.5, 18.5);
    glVertex3f(50.2, 30.5, 11.33);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(50.1, 30.5, 3.66);
    glVertex3f(50.1, 23.5, 3.66);
    glVertex3f(50.2, 23.5, 10.83);
    glVertex3f(50.2, 30.5, 10.83);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 23.5, 10.83);
    glVertex3f(50.1, 30.5, 10.83);
    glVertex3f(50.2, 30.5, 10.83);
    glVertex3f(50.2, 30.5, 3.66);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(50.1, 30.5, -4.5);
    glVertex3f(50.1, 23.5, -4.5);
    glVertex3f(50.2, 23.5, 3.16);
    glVertex3f(50.2, 30.5, 3.16);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(50.1, 23.5, 3.16);
    glVertex3f(50.1, 30.5, 3.16);
    glVertex3f(50.2, 30.5, 3.16);
    glVertex3f(50.2, 30.5, -4.5);

    /////////////////////////BAGIAN KIRI/////////////////////

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 24.5, 26);
    glVertex3f(-55.1, 29.5, 26);
    glVertex3f(-55.2, 29.5, 26);
    glVertex3f(-55.2, 29.5, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-55.1, 29.5, 26); /* front */
    glVertex3f(-55.1, 24.5, 26);
    glVertex3f(-55.2, 24.5, 10);
    glVertex3f(-55.2, 29.5, 10);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 18.5, 26);
    glVertex3f(-55.1, 24, 26);
    glVertex3f(-55.2, 24, 26);
    glVertex3f(-55.2, 24, 18.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 24, 26); /* front */
    glVertex3f(-55.1, 18.5, 26);
    glVertex3f(-55.2, 18.5, 18.5);
    glVertex3f(-55.2, 24, 18.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 18.5, 18);
    glVertex3f(-55.1, 24, 18);
    glVertex3f(-55.2, 24, 18);
    glVertex3f(-55.2, 24, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 24, 18); /* front */
    glVertex3f(-55.1, 18.5, 18);
    glVertex3f(-55.2, 18.5, 10);
    glVertex3f(-55.2, 24, 10);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 24.5, 9);
    glVertex3f(-55.1, 29.5, 9);
    glVertex3f(-55.2, 29.5, 9);
    glVertex3f(-55.2, 29.5, -7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-55.1, 29.5, 9); /* front */
    glVertex3f(-55.1, 24.5, 9);
    glVertex3f(-55.2, 24.5, -7);
    glVertex3f(-55.2, 29.5, -7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 18.5, 9);
    glVertex3f(-55.1, 24, 9);
    glVertex3f(-55.2, 24, 9);
    glVertex3f(-55.2, 24, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 24, 9); /* front */
    glVertex3f(-55.1, 18.5, 9);
    glVertex3f(-55.2, 18.5, 1.5);
    glVertex3f(-55.2, 24, 1.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 18.5, 1);
    glVertex3f(-55.1, 24, 1);
    glVertex3f(-55.2, 24, 1);
    glVertex3f(-55.2, 24, -7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 24, 1); /* front */
    glVertex3f(-55.1, 18.5, 1);
    glVertex3f(-55.2, 18.5, -7);
    glVertex3f(-55.2, 24, -7);
    glEnd();

    ////////////////////////////////////PEMBATAS TENGAH ATAS///////////////

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 18.5, -8);
    glVertex3f(-55.1, 29.5, -8);
    glVertex3f(-55.2, 29.5, -8);
    glVertex3f(-55.2, 29.5, -11);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 29.5, -11); /* front */
    glVertex3f(-55.1, 18.5, -11);
    glVertex3f(-55.2, 18.5, -8);
    glVertex3f(-55.2, 29.5, -8);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 18.5, -11.5);
    glVertex3f(-55.1, 29.5, -11.5);
    glVertex3f(-55.2, 29.5, -11.5);
    glVertex3f(-55.2, 29.5, -14.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 29.5, -11.5); /* front */
    glVertex3f(-55.1, 18.5, -11.5);
    glVertex3f(-55.2, 18.5, -14.5);
    glVertex3f(-55.2, 29.5, -14.5);
    glEnd();

    /////////////////////////////JENDELA KIRI ATAS //////////////////////////////

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 24.5, -15.5);
    glVertex3f(-55.1, 29.5, -15.5);
    glVertex3f(-55.2, 29.5, -15.5);
    glVertex3f(-55.2, 29.5, -31.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-55.1, 29.5, -31.5); /* front */
    glVertex3f(-55.1, 24.5, -31.5);
    glVertex3f(-55.2, 24.5, -15.5);
    glVertex3f(-55.2, 29.5, -15.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 24.5, -31.8);
    glVertex3f(-55.1, 29.5, -31.8);
    glVertex3f(-55.2, 29.5, -31.8);
    glVertex3f(-55.2, 29.5, -34.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-55.1, 29.5, -34.8); /* front */
    glVertex3f(-55.1, 24.5, -34.8);
    glVertex3f(-55.2, 24.5, -31.8);
    glVertex3f(-55.2, 29.5, -31.8);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 24.5, -35.3);
    glVertex3f(-55.1, 29.5, -35.3);
    glVertex3f(-55.2, 29.5, -35.3);
    glVertex3f(-55.2, 29.5, -38.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-55.1, 29.5, -38.3); /* front */
    glVertex3f(-55.1, 24.5, -38.3);
    glVertex3f(-55.2, 24.5, -35.3);
    glVertex3f(-55.2, 29.5, -35.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 24.5, -38.8);
    glVertex3f(-55.1, 29.5, -38.8);
    glVertex3f(-55.2, 29.5, -38.8);
    glVertex3f(-55.2, 29.5, -54);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-55.1, 29.5, -54); /* front */
    glVertex3f(-55.1, 24.5, -54);
    glVertex3f(-55.2, 24.5, -38.8);
    glVertex3f(-55.2, 29.5, -38.8);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 18.5, -15.5);
    glVertex3f(-55.1, 24, -15.5);
    glVertex3f(-55.2, 24, -15.5);
    glVertex3f(-55.2, 24, -26.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 24, -15.5); /* front */
    glVertex3f(-55.1, 18.5, -15.5);
    glVertex3f(-55.2, 18.5, -26.5);
    glVertex3f(-55.2, 24, -26.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 18.5, -27);
    glVertex3f(-55.1, 24, -27);
    glVertex3f(-55.2, 24, -27);
    glVertex3f(-55.2, 24, -31.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 24, -27); /* front */
    glVertex3f(-55.1, 18.5, -27);
    glVertex3f(-55.2, 18.5, -31.5);
    glVertex3f(-55.2, 24, -31.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 18.5, -31.8);
    glVertex3f(-55.1, 24, -31.8);
    glVertex3f(-55.2, 24, -31.8);
    glVertex3f(-55.2, 24, -38.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 24, -31.8); /* front */
    glVertex3f(-55.1, 18.5, -31.8);
    glVertex3f(-55.2, 18.5, -38.3);
    glVertex3f(-55.2, 24, -38.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 18.5, -38.8);
    glVertex3f(-55.1, 24, -38.8);
    glVertex3f(-55.2, 24, -38.8);
    glVertex3f(-55.2, 24, -42.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 24, -38.8); /* front */
    glVertex3f(-55.1, 18.5, -38.8);
    glVertex3f(-55.2, 18.5, -42.3);
    glVertex3f(-55.2, 24, -42.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 18.5, -42.8);
    glVertex3f(-55.1, 24, -42.8);
    glVertex3f(-55.2, 24, -42.8);
    glVertex3f(-55.2, 24, -54);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 24, -42.8); /* front */
    glVertex3f(-55.1, 18.5, -42.8);
    glVertex3f(-55.2, 18.5, -54);
    glVertex3f(-55.2, 24, -54);
    glEnd();

    ///////////////////////////////////PEMBATAS TENGAH////////////////////////////

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 17.5, 30);
    glVertex3f(-55.1, 12.5, 30);
    glVertex3f(-55.2, 17.5, 30);
    glVertex3f(-55.2, 17.5, 27);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 12.5, 30); /* front */
    glVertex3f(-55.1, 17.5, 30);
    glVertex3f(-55.2, 17.5, 27);
    glVertex3f(-55.2, 12.5, 27);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 17.5, 26);
    glVertex3f(-55.1, 12.5, 26);
    glVertex3f(-55.2, 17.5, 26);
    glVertex3f(-55.2, 17.5, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 12.5, 26); /* front */
    glVertex3f(-55.1, 17.5, 26);
    glVertex3f(-55.2, 17.5, 10);
    glVertex3f(-55.2, 12.5, 10);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 17.5, 9);
    glVertex3f(-55.1, 12.5, 9);
    glVertex3f(-55.2, 17.5, 9);
    glVertex3f(-55.2, 17.5, -7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 12.5, 9); /* front */
    glVertex3f(-55.1, 17.5, 9);
    glVertex3f(-55.2, 17.5, -7);
    glVertex3f(-55.2, 12.5, -7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 17.5, -8);
    glVertex3f(-55.1, 12.5, -8);
    glVertex3f(-55.2, 17.5, -8);
    glVertex3f(-55.2, 17.5, -14.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 12.5, -8); /* front */
    glVertex3f(-55.1, 17.5, -8);
    glVertex3f(-55.2, 17.5, -14.5);
    glVertex3f(-55.2, 12.5, -14.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 17.5, -15.5);
    glVertex3f(-55.1, 12.5, -15.5);
    glVertex3f(-55.2, 17.5, -15.5);
    glVertex3f(-55.2, 17.5, -31.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 12.5, -15.5); /* front */
    glVertex3f(-55.1, 17.5, -15.5);
    glVertex3f(-55.2, 17.5, -31.5);
    glVertex3f(-55.2, 12.5, -31.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 17.5, -31.8);
    glVertex3f(-55.1, 12.5, -31.8);
    glVertex3f(-55.2, 17.5, -31.8);
    glVertex3f(-55.2, 17.5, -38.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 12.5, -31.8); /* front */
    glVertex3f(-55.1, 17.5, -31.8);
    glVertex3f(-55.2, 17.5, -38.3);
    glVertex3f(-55.2, 12.5, -38.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 17.5, -38.8);
    glVertex3f(-55.1, 12.5, -38.8);
    glVertex3f(-55.2, 17.5, -38.8);
    glVertex3f(-55.2, 17.5, -54);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 12.5, -38.8); /* front */
    glVertex3f(-55.1, 17.5, -38.8);
    glVertex3f(-55.2, 17.5, -54);
    glVertex3f(-55.2, 12.5, -54);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(210, 180, 140);
    glVertex3f(-55, 18, -55); /* front */
    glVertex3f(-55, 12, -55);
    glVertex3f(-55.1, 12, 30.5);
    glVertex3f(-55.1, 18, 30.5);
    glEnd();

    ////////////////////////////////JENDELA KANAN BAWAH//////////////////////////

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, 30);
    glVertex3f(-55.1, 0.5, 30);
    glVertex3f(-55.2, 11.5, 30);
    glVertex3f(-55.2, 11.5, 27);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 11.5, 30); /* front */
    glVertex3f(-55.1, 0.5, 30);
    glVertex3f(-55.2, 0.5, 27);
    glVertex3f(-55.2, 11.5, 27);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, 26);
    glVertex3f(-55.1, 6.5, 26);
    glVertex3f(-55.2, 11.5, 26);
    glVertex3f(-55.2, 11.5, 15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-55.1, 11.5, 26); /* front */
    glVertex3f(-55.1, 6.5, 26);
    glVertex3f(-55.2, 6.5, 15);
    glVertex3f(-55.2, 11.5, 15);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, 14.7);
    glVertex3f(-55.1, 6.5, 14.7);
    glVertex3f(-55.2, 11.5, 14.7);
    glVertex3f(-55.2, 11.5, 11.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-55.1, 11.5, 14.7); /* front */
    glVertex3f(-55.1, 6.5, 14.7);
    glVertex3f(-55.2, 6.5, 11.7);
    glVertex3f(-55.2, 11.5, 11.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, 11);
    glVertex3f(-55.1, 6.5, 11);
    glVertex3f(-55.2, 11.5, 11);
    glVertex3f(-55.2, 11.5, 8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-55.1, 11.5, 11); /* front */
    glVertex3f(-55.1, 6.5, 11);
    glVertex3f(-55.2, 6.5, 8);
    glVertex3f(-55.2, 11.5, 8);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, 7.3);
    glVertex3f(-55.1, 6.5, 7.3);
    glVertex3f(-55.2, 11.5, 7.3);
    glVertex3f(-55.2, 11.5, 4.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-55.1, 11.5, 7.3); /* front */
    glVertex3f(-55.1, 6.5, 7.3);
    glVertex3f(-55.2, 6.5, 4.3);
    glVertex3f(-55.2, 11.5, 4.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, 4);
    glVertex3f(-55.1, 6.5, 4);
    glVertex3f(-55.2, 11.5, 4);
    glVertex3f(-55.2, 11.5, -7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-55.1, 11.5, 4); /* front */
    glVertex3f(-55.1, 6.5, 4);
    glVertex3f(-55.2, 6.5, -7);
    glVertex3f(-55.2, 11.5, -7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 6, 26);
    glVertex3f(-55.1, 0.5, 26);
    glVertex3f(-55.2, 6, 26);
    glVertex3f(-55.2, 6, 18.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 6, 26); /* front */
    glVertex3f(-55.1, 0.5, 26);
    glVertex3f(-55.2, 0.5, 18.5);
    glVertex3f(-55.2, 6, 18.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 6, 18);
    glVertex3f(-55.1, 0.5, 18);
    glVertex3f(-55.2, 6, 18);
    glVertex3f(-55.2, 6, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 6, 18); /* front */
    glVertex3f(-55.1, 0.5, 18);
    glVertex3f(-55.2, 0.5, 1.5);
    glVertex3f(-55.2, 6, 1.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 6, 1);
    glVertex3f(-55.1, 0.5, 1);
    glVertex3f(-55.2, 6, 1);
    glVertex3f(-55.2, 6, -7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 6, 1); /* front */
    glVertex3f(-55.1, 0.5, 1);
    glVertex3f(-55.2, 0.5, -7);
    glVertex3f(-55.2, 6, -7);
    glEnd();

    ////////////////////////////////PEMBATAS TENGAH BAWAH//////////////////////////
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, -8);
    glVertex3f(-55.1, 0.5, -8);
    glVertex3f(-55.2, 11.5, -8);
    glVertex3f(-55.2, 11.5, -11);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 0.5, -11); /* front */
    glVertex3f(-55.1, 11.5, -11);
    glVertex3f(-55.2, 11.5, -8);
    glVertex3f(-55.2, 0.5, -8);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, -11.5);
    glVertex3f(-55.1, 0.5, -11.5);
    glVertex3f(-55.2, 11.5, -11.5);
    glVertex3f(-55.2, 11.5, -14.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 0.5, -11.5); /* front */
    glVertex3f(-55.1, 11.5, -11.5);
    glVertex3f(-55.2, 11.5, -14.5);
    glVertex3f(-55.2, 0.5, -14.5);
    glEnd();
    //////////////////////////////JENDELA KIRI BAWAH//////////////////////////////

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, -15.5);
    glVertex3f(-55.1, 6, -15.5);
    glVertex3f(-55.2, 11.5, -15.5);
    glVertex3f(-55.2, 11.5, -26.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-55.1, 6, -15.5); /* front */
    glVertex3f(-55.1, 11.5, -15.5);
    glVertex3f(-55.2, 11.5, -26.5);
    glVertex3f(-55.2, 6, -26.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, -27);
    glVertex3f(-55.1, 6, -27);
    glVertex3f(-55.2, 11.5, -27);
    glVertex3f(-55.2, 11.5, -31.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-55.1, 11.5, -27); /* front */
    glVertex3f(-55.1, 6, -27);
    glVertex3f(-55.2, 6, -31.5);
    glVertex3f(-55.2, 11.5, -31.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, -31.8);
    glVertex3f(-55.1, 6, -31.8);
    glVertex3f(-55.2, 11.5, -31.8);
    glVertex3f(-55.2, 11.5, -38.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-55.1, 11.5, -31.8); /* front */
    glVertex3f(-55.1, 6, -31.8);
    glVertex3f(-55.2, 6, -38.3);
    glVertex3f(-55.2, 11.5, -38.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, -38.8);
    glVertex3f(-55.1, 6, -38.8);
    glVertex3f(-55.2, 11.5, -38.8);
    glVertex3f(-55.2, 11.5, -42.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-55.1, 11.5, -38.8); /* front */
    glVertex3f(-55.1, 6, -38.8);
    glVertex3f(-55.2, 6, -42.3);
    glVertex3f(-55.2, 11.5, -42.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 11.5, -42.8);
    glVertex3f(-55.1, 6, -42.8);
    glVertex3f(-55.2, 11.5, -42.8);
    glVertex3f(-55.2, 11.5, -54);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-55.1, 11.5, -42.8); /* front */
    glVertex3f(-55.1, 6, -42.8);
    glVertex3f(-55.2, 6, -54);
    glVertex3f(-55.2, 11.5, -54);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 5.5, -15.5);
    glVertex3f(-55.1, 0.5, -15.5);
    glVertex3f(-55.2, 5.5, -15.5);
    glVertex3f(-55.2, 5.5, -31.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 5.5, -31.5); /* front */
    glVertex3f(-55.1, 0.5, -31.5);
    glVertex3f(-55.2, 0.5, -15.5);
    glVertex3f(-55.2, 5.5, -15.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 5.5, -31.8);
    glVertex3f(-55.1, 0.5, -31.8);
    glVertex3f(-55.2, 5.5, -31.8);
    glVertex3f(-55.2, 5.5, -34.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 5.5, -34.8); /* front */
    glVertex3f(-55.1, 0.5, -34.8);
    glVertex3f(-55.2, 0.5, -31.8);
    glVertex3f(-55.2, 5.5, -31.8);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 5.5, -35.3);
    glVertex3f(-55.1, 0.5, -35.3);
    glVertex3f(-55.2, 5.5, -35.3);
    glVertex3f(-55.2, 5.5, -38.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 5.5, -38.3); /* front */
    glVertex3f(-55.1, 0.5, -38.3);
    glVertex3f(-55.2, 0.5, -35.3);
    glVertex3f(-55.2, 5.5, -35.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-55.1, 5.5, -38.8);
    glVertex3f(-55.1, 0.5, -38.8);
    glVertex3f(-55.2, 5.5, -38.8);
    glVertex3f(-55.2, 5.5, -54);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-55.1, 5.5, -54); /* front */
    glVertex3f(-55.1, 0.5, -54);
    glVertex3f(-55.2, 0.5, -38.8);
    glVertex3f(-55.2, 5.5, -38.8);
    glEnd();
    ///////////////////////////////////////////////////////////////////////
    /////////////////////ELEMEN DEPAN/////////////////////////
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.5, 25, 30);
    glVertex3f(-10.5, 29.5, 30);
    glVertex3f(-10.5, 29.5, 30);
    glVertex3f(-16, 29.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-10.5, 29.5, 30); /* front */
    glVertex3f(-10.5, 25, 30);
    glVertex3f(-16, 25, 30);
    glVertex3f(-16, 29.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-16.3, 25, 30);
    glVertex3f(-16.3, 29.5, 30);
    glVertex3f(-16.3, 29.5, 30);
    glVertex3f(-19, 29.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-16.3, 29.5, 30); /* front */
    glVertex3f(-16.3, 25, 30);
    glVertex3f(-19, 25, 30);
    glVertex3f(-19, 29.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-19.3, 25, 30);
    glVertex3f(-19.3, 29.5, 30);
    glVertex3f(-19.3, 29.5, 30);
    glVertex3f(-22, 29.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-19.3, 29.5, 30); /* front */
    glVertex3f(-19.3, 25, 30);
    glVertex3f(-22, 25, 30);
    glVertex3f(-22, 29.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-22.3, 25, 30);
    glVertex3f(-22.3, 29.5, 30);
    glVertex3f(-22.3, 29.5, 30);
    glVertex3f(-25, 29.5, 30);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-22.3, 29.5, 30); /* front */
    glVertex3f(-22.3, 25, 30);
    glVertex3f(-25, 25, 30);
    glVertex3f(-25, 29.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-25.3, 25, 30);
    glVertex3f(-25.3, 29.5, 30);
    glVertex3f(-25.3, 29.5, 30);
    glVertex3f(-30.8, 29.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-25.3, 29.5, 30); /* front */
    glVertex3f(-25.3, 25, 30);
    glVertex3f(-30.8, 25, 30);
    glVertex3f(-30.8, 29.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.5, 18.5, 30);
    glVertex3f(-10.5, 21, 30);
    glVertex3f(-10.5, 21, 30);
    glVertex3f(-16, 21, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-10.5, 24.5, 30); /* front */
    glVertex3f(-10.5, 21.5, 30);
    glVertex3f(-16, 21.5, 30);
    glVertex3f(-16, 24.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.5, 21.5, 30);
    glVertex3f(-10.5, 24.5, 30);
    glVertex3f(-10.5, 24.5, 30);
    glVertex3f(-16, 24.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-10.5, 21, 30); /* front */
    glVertex3f(-10.5, 18.5, 30);
    glVertex3f(-16, 18.5, 30);
    glVertex3f(-16, 21, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-16.3, 18.5, 30);
    glVertex3f(-16.3, 24.5, 30);
    glVertex3f(-16.3, 24.5, 30);
    glVertex3f(-19, 24.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-16.3, 24.5, 30); /* front */
    glVertex3f(-16.3, 18.5, 30);
    glVertex3f(-19, 18.5, 30);
    glVertex3f(-19, 24.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-19.3, 18.5, 30);
    glVertex3f(-19.3, 24.5, 30);
    glVertex3f(-19.3, 24.5, 30);
    glVertex3f(-22, 24.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-19.3, 24.5, 30); /* front */
    glVertex3f(-19.3, 18.5, 30);
    glVertex3f(-22, 18.5, 30);
    glVertex3f(-22, 24.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-22.3, 18.5, 30);
    glVertex3f(-22.3, 24.5, 30);
    glVertex3f(-22.3, 24.5, 30);
    glVertex3f(-25, 24.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-22.3, 24.5, 30); /* front */
    glVertex3f(-22.3, 18.5, 30);
    glVertex3f(-25, 18.5, 30);
    glVertex3f(-25, 24.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-25.3, 21.5, 30);
    glVertex3f(-25.3, 24.5, 30);
    glVertex3f(-25.3, 24.5, 30);
    glVertex3f(-30.8, 24.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-25.3, 24.5, 30); /* front */
    glVertex3f(-25.3, 21.5, 30);
    glVertex3f(-30.8, 21.5, 30);
    glVertex3f(-30.8, 24.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-25.3, 18.5, 30);
    glVertex3f(-25.3, 21, 30);
    glVertex3f(-25.3, 21, 30);
    glVertex3f(-30.8, 21, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-25.3, 21, 30); /* front */
    glVertex3f(-25.3, 18.5, 30);
    glVertex3f(-30.8, 18.5, 30);
    glVertex3f(-30.8, 21, 30);
    glEnd();

    ////////////////////////////PEMBATAS TENGAH///////////////////////////////////////

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-31.3, 18.5, 30);
    glVertex3f(-31.3, 29.5, 30);
    glVertex3f(-31.3, 29.5, 30);
    glVertex3f(-34, 29.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-31.3, 29.5, 30); /* front */
    glVertex3f(-31.3, 18.5, 30);
    glVertex3f(-34, 18.5, 30);
    glVertex3f(-34, 29.5, 30);
    glEnd();

    ///////////////////////////////////JENDELA KIRI//////////////////////////////////

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-34.5, 25, 30);
    glVertex3f(-34.5, 29.5, 30);
    glVertex3f(-34.5, 29.5, 30);
    glVertex3f(-40.1, 29.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-34.6, 29.5, 30); /* front */
    glVertex3f(-34.6, 25, 30);
    glVertex3f(-40.1, 25, 30);
    glVertex3f(-40.1, 29.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-40.4, 25, 30);
    glVertex3f(-40.4, 29.5, 30);
    glVertex3f(-40.4, 29.5, 30);
    glVertex3f(-43.1, 29.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-40.4, 29.5, 30);
    glVertex3f(-40.4, 25, 30);
    glVertex3f(-43.1, 25, 30);
    glVertex3f(-43.1, 29.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-43.4, 25, 30);
    glVertex3f(-43.4, 29.5, 30);
    glVertex3f(-43.4, 29.5, 30);
    glVertex3f(-46.1, 29.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-43.4, 29.5, 30); /* front */
    glVertex3f(-43.4, 25, 30);
    glVertex3f(-46.1, 25, 30);
    glVertex3f(-46.1, 29.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-46.4, 25, 30);
    glVertex3f(-46.4, 29.5, 30);
    glVertex3f(-46.4, 29.5, 30);
    glVertex3f(-51.1, 29.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-46.4, 29.5, 30); /* front */
    glVertex3f(-46.4, 25, 30);
    glVertex3f(-51.1, 25, 30);
    glVertex3f(-51.1, 29.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-34.6, 18.5, 30);
    glVertex3f(-34.6, 24.5, 30);
    glVertex3f(-34.6, 24.5, 30);
    glVertex3f(-40.1, 24.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-34.6, 24.5, 30); /* front */
    glVertex3f(-34.6, 18.5, 30);
    glVertex3f(-40.1, 18.5, 30);
    glVertex3f(-40.1, 24.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-40.4, 18.5, 30);
    glVertex3f(-40.4, 24.5, 30);
    glVertex3f(-40.4, 24.5, 30);
    glVertex3f(-43.1, 24.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-40.4, 24.5, 30); /* front */
    glVertex3f(-40.4, 18.5, 30);
    glVertex3f(-43.1, 18.5, 30);
    glVertex3f(-43.1, 24.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-43.4, 18.5, 30);
    glVertex3f(-43.4, 24.5, 30);
    glVertex3f(-46.1, 24.5, 30);
    glVertex3f(-46.1, 24.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-43.4, 24.5, 30); /* front */
    glVertex3f(-43.4, 18.5, 30);
    glVertex3f(-46.1, 18.5, 30);
    glVertex3f(-46.1, 24.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-46.4, 18.5, 30);
    glVertex3f(-46.4, 24.5, 30);
    glVertex3f(-46.4, 24.5, 30);
    glVertex3f(-51.1, 24.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-46.4, 24.5, 30); /* front */
    glVertex3f(-46.4, 18.5, 30);
    glVertex3f(-51.1, 18.5, 30);
    glVertex3f(-51.1, 24.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-52, 18.5, 30);
    glVertex3f(-52, 29.5, 30);
    glVertex3f(-52, 29.5, 30);
    glVertex3f(-55, 29.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-52, 29.5, 30); /* front */
    glVertex3f(-52, 18.5, 30);
    glVertex3f(-55, 18.5, 30);
    glVertex3f(-55, 29.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-10, 30, 30); /* front */
    glVertex3f(-10, 18, 30);
    glVertex3f(-55, 18, 30);
    glVertex3f(-55, 30, 30);
    glEnd();

    ///////////////////////////PEMBATAS TENGAH///////////////////////////////////

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.5, 12, 30);
    glVertex3f(-10.5, 18, 30);
    glVertex3f(-10.5, 18, 30);
    glVertex3f(-16, 18, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.280, 0.0);
    glVertex3f(-10.5, 18, 30); /* front */
    glVertex3f(-10.5, 12, 30);
    glVertex3f(-16, 12, 30);
    glVertex3f(-16, 18, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-16.3, 12, 30);
    glVertex3f(-16.3, 18, 30);
    glVertex3f(-16.3, 18, 30);
    glVertex3f(-25, 18, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-16.3, 18, 30); /* front */
    glVertex3f(-16.3, 12, 30);
    glVertex3f(-25, 12, 30);
    glVertex3f(-25, 18, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-25.3, 12, 30);
    glVertex3f(-25.3, 18, 30);
    glVertex3f(-25.3, 18, 30);
    glVertex3f(-30.8, 18, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-25.3, 18, 30); /* front */
    glVertex3f(-25.3, 12, 30);
    glVertex3f(-30.8, 12, 30);
    glVertex3f(-30.8, 18, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-31.1, 12, 30);
    glVertex3f(-31.1, 18, 30);
    glVertex3f(-31.1, 18, 30);
    glVertex3f(-34.3, 18, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-31.1, 18, 30); /* front */
    glVertex3f(-31.1, 12, 30);
    glVertex3f(-34.3, 12, 30);
    glVertex3f(-34.3, 18, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-34.6, 12, 30);
    glVertex3f(-34.6, 18, 30);
    glVertex3f(-34.6, 18, 30);
    glVertex3f(-40.1, 18, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-34.6, 18, 30); /* front */
    glVertex3f(-34.6, 12, 30);
    glVertex3f(-40.1, 12, 30);
    glVertex3f(-40.1, 18, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-40.4, 12, 30);
    glVertex3f(-40.4, 18, 30);
    glVertex3f(-40.4, 18, 30);
    glVertex3f(-46.1, 18, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-40.4, 18, 30); /* front */
    glVertex3f(-40.4, 12, 30);
    glVertex3f(-46.1, 12, 30);
    glVertex3f(-46.1, 18, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-46.4, 12, 30);
    glVertex3f(-46.4, 18, 30);
    glVertex3f(-46.4, 18, 30);
    glVertex3f(-51.1, 18, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-46.4, 18, 30); /* front */
    glVertex3f(-46.4, 12, 30);
    glVertex3f(-51.1, 12, 30);
    glVertex3f(-51.1, 18, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-51.5, 12, 30);
    glVertex3f(-51.5, 18, 30);
    glVertex3f(-51.5, 18, 30);
    glVertex3f(-55, 18, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-51.5, 18, 30); /* front */
    glVertex3f(-51.5, 12, 30);
    glVertex3f(-55, 12, 30);
    glVertex3f(-55, 18, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(210, 180, 140);
    glVertex3f(-10, 18, 30); /* front */
    glVertex3f(-10, 12, 30);
    glVertex3f(-55, 12, 30);
    glVertex3f(-55, 18, 30);
    glEnd();

    //////////////////////////JENDELA KANAN BAWAH//////////////////////////////

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.5, 9, 30);
    glVertex3f(-10.5, 11.5, 30);
    glVertex3f(-10.5, 11.5, 30);
    glVertex3f(-16, 11.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-10.5, 9, 30); /* front */
    glVertex3f(-10.5, 11.5, 30);
    glVertex3f(-16, 11.5, 30);
    glVertex3f(-16, 9, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.5, 5, 30);
    glVertex3f(-10.5, 8.7, 30);
    glVertex3f(-10.5, 8.7, 30);
    glVertex3f(-16, 8.7, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-10.5, 5, 30); /* front */
    glVertex3f(-10.5, 8.7, 30);
    glVertex3f(-16, 8.7, 30);
    glVertex3f(-16, 5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.5, 0.5, 30);
    glVertex3f(-10.5, 4.7, 30);
    glVertex3f(-10.5, 4.7, 30);
    glVertex3f(-16, 4.7, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-10.5, 4.7, 30); /* front */
    glVertex3f(-10.5, 0.5, 30);
    glVertex3f(-16, 0.5, 30);
    glVertex3f(-16, 4.7, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-16.3, 9, 30);
    glVertex3f(-16.3, 11.5, 30);
    glVertex3f(-16.3, 11.5, 30);
    glVertex3f(-19, 11.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-16.3, 9, 30); /* front */
    glVertex3f(-16.3, 11.5, 30);
    glVertex3f(-19, 11.5, 30);
    glVertex3f(-19, 9, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-16.3, 0.5, 30);
    glVertex3f(-16.3, 8.7, 30);
    glVertex3f(-16.3, 8.7, 30);
    glVertex3f(-19, 8.7, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-16.3, 8.7, 30); /* front */
    glVertex3f(-16.3, 0.5, 30);
    glVertex3f(-19, 0.5, 30);
    glVertex3f(-19, 8.7, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-19.3, 9, 30);
    glVertex3f(-19.3, 11.5, 30);
    glVertex3f(-19.3, 11.5, 30);
    glVertex3f(-22, 11.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-19.3, 9, 30); /* front */
    glVertex3f(-19.3, 11.5, 30);
    glVertex3f(-22, 11.5, 30);
    glVertex3f(-22, 9, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-19.3, 0.5, 30);
    glVertex3f(-19.3, 8.7, 30);
    glVertex3f(-19.3, 8.7, 30);
    glVertex3f(-22, 8.7, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-19.3, 8.7, 30); /* front */
    glVertex3f(-19.3, 0.5, 30);
    glVertex3f(-22, 0.5, 30);
    glVertex3f(-22, 8.7, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-22.3, 9, 30);
    glVertex3f(-22.3, 11.5, 30);
    glVertex3f(-22.3, 11.5, 30);
    glVertex3f(-25, 11.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-22.3, 9, 30); /* front */
    glVertex3f(-22.3, 11.5, 30);
    glVertex3f(-25, 11.5, 30);
    glVertex3f(-25, 9, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-22.3, 0.5, 30);
    glVertex3f(-22.3, 8.7, 30);
    glVertex3f(-22.3, 8.7, 30);
    glVertex3f(-25, 8.7, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-22.3, 8.7, 30); /* front */
    glVertex3f(-22.3, 0.5, 30);
    glVertex3f(-25, 0.5, 30);
    glVertex3f(-25, 8.7, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-25.3, 9, 30);
    glVertex3f(-25.3, 11.5, 30);
    glVertex3f(-25.3, 11.5, 30);
    glVertex3f(-30.8, 11.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-25.3, 9, 30); /* front */
    glVertex3f(-25.3, 11.5, 30);
    glVertex3f(-30.8, 11.5, 30);
    glVertex3f(-30.8, 9, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-25.3, 5, 30);
    glVertex3f(-25.3, 8.7, 30);
    glVertex3f(-25.3, 8.7, 30);
    glVertex3f(-30.8, 8.7, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-25.3, 5, 30); /* front */
    glVertex3f(-25.3, 8.7, 30);
    glVertex3f(-30.8, 8.7, 30);
    glVertex3f(-30.8, 5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-25.3, 0.5, 30);
    glVertex3f(-25.3, 4.7, 30);
    glVertex3f(-25.3, 4.7, 30);
    glVertex3f(-30.8, 4.7, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-25.3, 4.7, 30); /* front */
    glVertex3f(-25.3, 0.5, 30);
    glVertex3f(-30.8, 0.5, 30);
    glVertex3f(-30.8, 4.7, 30);
    glEnd();

    /////////////////////////////GARIS TENGAH///////////////////

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-31.3, 0.5, 30);
    glVertex3f(-31.3, 11.5, 30);
    glVertex3f(-31.3, 11.5, 30);
    glVertex3f(-34, 11.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-31.3, 11.5, 30); /* front */
    glVertex3f(-31.3, 0.5, 30);
    glVertex3f(-34, 0.5, 30);
    glVertex3f(-34, 11.5, 30);
    glEnd();

    //////////////////////////////JENDELA KANAN BAWAH//////////////

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-34.6, 8, 30);
    glVertex3f(-34.6, 11.5, 30);
    glVertex3f(-34.6, 11.5, 30);
    glVertex3f(-43.1, 11.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-34.6, 11.5, 30); /* front */
    glVertex3f(-34.6, 8, 30);
    glVertex3f(-43.1, 8, 30);
    glVertex3f(-43.1, 11.5, 30);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-43.4, 8, 30);
    glVertex3f(-43.4, 11.5, 30);
    glVertex3f(-43.4, 11.5, 30);
    glVertex3f(-51.1, 11.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-43.4, 11.5, 30); /* front */
    glVertex3f(-43.4, 8, 30);
    glVertex3f(-51.1, 8, 30);
    glVertex3f(-51.1, 11.5, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-34.6, 5.5, 30);
    glVertex3f(-34.6, 7.7, 30);
    glVertex3f(-34.6, 7.7, 30);
    glVertex3f(-51.1, 7.7, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-34.6, 7.7, 30); /* front */
    glVertex3f(-34.6, 5.5, 30);
    glVertex3f(-51.1, 5.5, 30);
    glVertex3f(-51.1, 7.7, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-34.6, 0.5, 30);
    glVertex3f(-34.6, 5.2, 30);
    glVertex3f(-34.6, 5.2, 30);
    glVertex3f(-40.1, 5.2, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-34.6, 5.2, 30); /* front */
    glVertex3f(-34.6, 0.5, 30);
    glVertex3f(-40.1, 0.5, 30);
    glVertex3f(-40.1, 5.2, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-40.4, 0.5, 30);
    glVertex3f(-40.4, 5.2, 30);
    glVertex3f(-40.4, 5.2, 30);
    glVertex3f(-43.1, 5.2, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-40.4, 5.2, 30); /* front */
    glVertex3f(-40.4, 0.5, 30);
    glVertex3f(-43.1, 0.5, 30);
    glVertex3f(-43.1, 5.2, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-43.4, 0.5, 30);
    glVertex3f(-43.4, 5.2, 30);
    glVertex3f(-43.4, 5.2, 30);
    glVertex3f(-46.1, 5.2, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-43.4, 5.2, 30); /* front */
    glVertex3f(-43.4, 0.5, 30);
    glVertex3f(-46.1, 0.5, 30);
    glVertex3f(-46.1, 5.2, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-46.4, 0.5, 30);
    glVertex3f(-46.4, 5.2, 30);
    glVertex3f(-46.4, 5.2, 30);
    glVertex3f(-51.1, 5.2, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-46.4, 5.2, 30); /* front */
    glVertex3f(-46.4, 0.5, 30);
    glVertex3f(-51.1, 0.5, 30);
    glVertex3f(-51.1, 5.2, 30);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-52, 0.5, 30);
    glVertex3f(-52, 11.5, 30);
    glVertex3f(-52, 11.5, 30);
    glVertex3f(-55, 11.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-52, 11.5, 30); /* front */
    glVertex3f(-52, 0.5, 30);
    glVertex3f(-55, 0.5, 30);
    glVertex3f(-55, 11.5, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-10, 0, 30); /* front */
    glVertex3f(-10, 18, 30);
    glVertex3f(-55, 18, 30);
    glVertex3f(-55, 0, 30);
    glEnd();

    /////////////////////////////////////////////////////
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-55, 0, -55); /* front */
    glVertex3f(-55, 12, -55);
    glVertex3f(-55.1, 12, 30.5);
    glVertex3f(-55.1, 0, 30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-55, 30, -55); /* front */
    glVertex3f(-55, 18, -55);
    glVertex3f(-55.1, 18, 30.5);
    glVertex3f(-55.1, 30, 30.5);
    glEnd();
}

void BagianDepanAtas2(int x, int y)
{
    glPushMatrix();
    glTranslated(0.5, 0, 0);
    //Kolom 2 Dalam
    glBegin(GL_QUADS);
    glVertex3f(-7.0 + x, 38.5 + y, 50.0);
    glVertex3f(-7.0 + x, 35.5 + y, 50.0);
    glVertex3f(-2.0 + x, 35.5 + y, 50.0);
    glVertex3f(-2.0 + x, 38.5 + y, 50.0);
    glEnd();
    glPopMatrix();
}

void PembatasBagianDepanAtas2_2(int x2, int y2)
{
    glPushMatrix();
    glTranslated(0.5, 0, 0);
    //Kolom 2 Atas Luar
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(-7.5 + x2, 39.0 + y2, 50.0);
    glVertex3f(-7.5 + x2, 35.0 + y2, 50.0);
    glVertex3f(-1.5 + x2, 35.0 + y2, 50.0);
    glVertex3f(-1.5 + x2, 39.0 + y2, 50.0);
    glEnd();
    glPopMatrix();
}

void BagianDepanAtas2_2(int x2, int y2)
{
    glPushMatrix();
    glTranslated(0.5, 0, 0);
    //Kolom 2 Atas Luar
    glBegin(GL_QUADS);
    glVertex3f(-7.5 + x2, 39.0 + y2, 50.0);
    glVertex3f(-7.5 + x2, 35.0 + y2, 50.0);
    glVertex3f(-1.5 + x2, 35.0 + y2, 50.0);
    glVertex3f(-1.5 + x2, 39.0 + y2, 50.0);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-7.5 + x2, 39.7 + y2, 50.0);
    glVertex3f(-1.5 + x2, 39.7 + y2, 50.0);
    glEnd();

    glPopMatrix();
}

void BagianDepan2(int x, int y)
{
    glPushMatrix();
    glTranslated(0.5, 0, 0);

    //Kolom 2 Bawah Dalam
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-7.0 + 45.9, 28.5 - 23, 50.0);
    glVertex3f(-7.0 + 45.9, 23.5 - 23, 50.0);
    glVertex3f(-2.0 + 45.9, 23.5 - 23, 50.0);
    glVertex3f(-2.0 + 45.9, 28.5 - 23, 50.0);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-7.0 + 45.9, 28.5 - 23, 50.0);
    glVertex3f(-7.0 + 45.9, 23.5 - 23, 50.0);
    glVertex3f(-2.0 + 45.9, 23.5 - 23, 50.0);
    glVertex3f(-2.0 + 45.9, 28.5 - 23, 50.0);
    glEnd();

    //Kolom 2 Bawah Luar
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-7.5 + 45.9, 29.0 - 23, 50.0);
    glVertex3f(-7.5 + 45.9, 23.0 - 23, 50.0);
    glVertex3f(-1.5 + 45.9, 23.0 - 23, 50.0);
    glVertex3f(-1.5 + 45.9, 29.0 - 23, 50.0);
    glEnd();

    //Kolom 2 Bawah Luar
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-7.5 + 45.9, 29.0 - 23, 50.0);
    glVertex3f(-7.5 + 45.9, 23.0 - 23, 50.0);
    glVertex3f(-1.5 + 45.9, 23.0 - 23, 50.0);
    glVertex3f(-1.5 + 45.9, 29.0 - 23, 50.0);
    glEnd();

    ////////////////////////////////////////////////
    //Kolom 2 Bawah Dalam
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-7.0 + x, 28.5 + y, 50.0);
    glVertex3f(-7.0 + x, 23.5 + y, 50.0);
    glVertex3f(-2.0 + x, 23.5 + y, 50.0);
    glVertex3f(-2.0 + x, 28.5 + y, 50.0);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-7.0 + x, 28.5 + y, 50.0);
    glVertex3f(-7.0 + x, 23.5 + y, 50.0);
    glVertex3f(-2.0 + x, 23.5 + y, 50.0);
    glVertex3f(-2.0 + x, 28.5 + y, 50.0);
    glEnd();

    //Kolom 2 Bawah Luar
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-7.5 + x, 29.0 + y, 50.0);
    glVertex3f(-7.5 + x, 23.0 + y, 50.0);
    glVertex3f(-1.5 + x, 23.0 + y, 50.0);
    glVertex3f(-1.5 + x, 29.0 + y, 50.0);
    glEnd();

    //Kolom 2 Bawah Luar
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-7.5 + x, 29.0 + y, 50.0);
    glVertex3f(-7.5 + x, 23.0 + y, 50.0);
    glVertex3f(-1.5 + x, 23.0 + y, 50.0);
    glVertex3f(-1.5 + x, 29.0 + y, 50.0);
    glEnd();
    ///////////////////////////////////////////////

    //Kolom 2 Tengah
    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-7.5 + 18, 35.0, 50.0);
    glVertex3f(-7.5 + 18, 29.0, 50.0);
    glVertex3f(-1.5 + 18, 29.0, 50.0);
    glVertex3f(-1.5 + 18, 35.0, 50.0);
    glEnd();
    glPopMatrix();

    //Kolom 2 Tengah
    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-7.5 + 36.5, 35.0 + y, 50.0);
    glVertex3f(-7.5 + 36.5, 29.0 + y, 50.0);
    glVertex3f(-1.5 + 36.5, 29.0 + y, 50.0);
    glVertex3f(-1.5 + 36.5, 35.0 + y, 50.0);
    glEnd();
    glPopMatrix();

    //Kolom 2 Tengah
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.490, 0.490);
    glVertex3f(-6.8 + x, 35.0 + y, 50.0);
    glVertex3f(-6.8 + x, 29.0 + y, 50.0);
    glVertex3f(-1.1 + x, 29.0 + y, 50.0);
    glVertex3f(-1.1 + x, 35.0 + y, 50.0);
    glEnd();
    glPopMatrix();
}

void BagianDepan()
{
    //Bagian Tengah

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.1, 17, 50.0);
    glVertex3f(-1.1, 23, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-9.5, 23, 50); /* front */
    glVertex3f(-9.5, 17, 50);
    glVertex3f(-1, 17, 50.0);
    glVertex3f(-1, 23, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.7, 17, 50.0);
    glVertex3f(4.7, 23, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-0.5, 23, 50); /* front */
    glVertex3f(-0.5, 17, 50);
    glVertex3f(4.8, 17, 50.0);
    glVertex3f(4.8, 23, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(10.6, 17, 50.0);
    glVertex3f(10.6, 23, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(5.2, 23, 50); /* front */
    glVertex3f(5.2, 17, 50);
    glVertex3f(10.7, 17, 50.0);
    glVertex3f(10.7, 23, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(16.7, 17, 50.0);
    glVertex3f(16.7, 23, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(11.1, 23, 50); /* front */
    glVertex3f(11.1, 17, 50);
    glVertex3f(16.8, 17, 50.0);
    glVertex3f(16.8, 23, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(20.3, 17, 50.0);
    glVertex3f(20.3, 23, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(17.2, 23, 50); /* front */
    glVertex3f(17.2, 17, 50);
    glVertex3f(20.4, 17, 50.0);
    glVertex3f(20.4, 23, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(25.3, 17, 50.0);
    glVertex3f(25.3, 23, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(20.8, 23, 50); /* front */
    glVertex3f(20.8, 17, 50);
    glVertex3f(25.4, 17, 50.0);
    glVertex3f(25.4, 23, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(28.7, 17, 50.0);
    glVertex3f(28.7, 23, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(25.8, 23, 50); /* front */
    glVertex3f(25.8, 17, 50);
    glVertex3f(28.8, 17, 50.0);
    glVertex3f(28.8, 23, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(34.6, 17, 50.0);
    glVertex3f(34.6, 23, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(29.2, 23, 50); /* front */
    glVertex3f(29.2, 17, 50);
    glVertex3f(34.7, 17, 50.0);
    glVertex3f(34.7, 23, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(38.3, 17, 50.0);
    glVertex3f(38.3, 23, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(35.1, 23, 50); /* front */
    glVertex3f(35.1, 17, 50);
    glVertex3f(38.4, 17, 50.0);
    glVertex3f(38.4, 23, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(44.6, 17, 50.0);
    glVertex3f(44.6, 23, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(38.8, 23, 50); /* front */
    glVertex3f(38.8, 17, 50);
    glVertex3f(44.7, 17, 50.0);
    glVertex3f(44.7, 23, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(49.4, 17, 50.0);
    glVertex3f(49.4, 23, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(45.1, 23, 50); /* front */
    glVertex3f(45.1, 17, 50);
    glVertex3f(49.5, 17, 50.0);
    glVertex3f(49.5, 23, 50.0);
    glEnd();

    glColor3ub(210, 180, 140);
    glBegin(GL_QUADS);
    glVertex3f(-10, 23, 50); /* front */
    glVertex3f(-10, 17.0, 50);
    glVertex3f(50, 17.0, 50);
    glVertex3f(50, 23, 50);
    glEnd();
    /////////////////////////////////OBJEK///////////////////////////////
    for (int i = 4; i <= 7; i++)
    {
        drawTree(i * 20, 18);
    }

    for (int i = 4; i <= 7; i++)
    {
        drawTree(i * -20, 18);
    }

    ///papan tulis dasar
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(20, 18, -4);
    glVertex3f(20, 10, -4);
    glVertex3f(35, 10, -4);
    glVertex3f(35, 18, -4);
    glEnd();
    ///papan tulis
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(19, 19, -4);
    glVertex3f(19, 9, -4);
    glVertex3f(36, 9, -4);
    glVertex3f(36, 19, -4);
    glEnd();
    //meja kotak panjang
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(0, 6, -4);
    glVertex3f(0, 5, -4);
    glVertex3f(15, 5, -4);
    glVertex3f(15, 6, -4);
    glEnd();
    //kaki kiri
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(1.5, 6, -4);
    glVertex3f(1.5, 0, -4);
    glVertex3f(2.5, 0, -4);
    glVertex3f(2.5, 6, -4);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(2.5, 6, -4);
    glVertex3f(2.5, 0, -4);
    glVertex3f(2.8, 0.2, -4);
    glVertex3f(2.8, 6, -4);
    glEnd();

    //kaki kanan
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(13.5, 6, -4);
    glVertex3f(13.5, 0, -4);
    glVertex3f(12.5, 0, -4);
    glVertex3f(12.5, 6, -4);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(12.5, 6, -4);
    glVertex3f(12.5, 0, -4);
    glVertex3f(12.2, 0.2, -4);
    glVertex3f(12.2, 6, -4);
    glEnd();

    //buku
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(3, 8.42, -4);
    glVertex3f(2.78, 6.3, -4);
    glVertex3f(3, 6.3, -4);
    glVertex3f(3.2, 8.35, -4);
    glEnd();

    //rak buku
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(1.8, 8.35, -4);
    glVertex3f(1.8, 6.3, -4);
    glVertex3f(13.2, 6.3, -4);
    glVertex3f(13.2, 8.35, -4);
    glEnd();

    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(1.8, 10.7, -4);
    glVertex3f(1.8, 8.65, -4);
    glVertex3f(13.2, 8.65, -4);
    glVertex3f(13.2, 10.7, -4);
    glEnd();

    //tempatbuku
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(1.5, 11, -4);
    glVertex3f(1.5, 6, -4);
    glVertex3f(13.5, 6, -4);
    glVertex3f(13.5, 11, -4);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(1.5, 11, -4);
    glVertex3f(1.5, 6, -4);
    glVertex3f(13.5, 6, -4);
    glVertex3f(13.5, 11, -4);
    glEnd();

    // pot bunga
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(44, 2, -4);
    glVertex3f(45, 0, -4);
    glVertex3f(46, 0, -4);
    glVertex3f(47, 2, -4);
    glEnd();

    // gagang
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(45.3, 2.8, -4);
    glVertex3f(45.3, 2, -4);
    glVertex3f(45.6, 2, -4);
    glVertex3f(45.6, 2.8, -4);
    glEnd();

    // bunga atas
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(44.9, 4.5, -4);
    glVertex3f(44.9, 3.5, -4);
    glVertex3f(45.9, 3.5, -4);
    glVertex3f(45.9, 4.5, -4);
    glEnd();

    // bunga kiri
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(44.45, 3.8, -4);
    glVertex3f(44.45, 2.8, -4);
    glVertex3f(45.45, 2.8, -4);
    glVertex3f(45.45, 3.8, -4);
    glEnd();

    // bunga kanan
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(46.45, 3.8, -4);
    glVertex3f(46.45, 2.8, -4);
    glVertex3f(45.45, 2.8, -4);
    glVertex3f(45.45, 3.8, -4);
    glEnd();

    //titik jam
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex3f(27.5, 23.5, -4);
    glEnd();

    //JARUM JAM
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(26, 23.5, -4);
    glVertex3f(27.5, 23.5, -4);
    glVertex3f(27.5, 24.5, -4);
    glEnd();

    //jam
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(25.5, 25, -4);
    glVertex3f(25.5, 22, -4);
    glVertex3f(29.5, 22, -4);
    glVertex3f(29.5, 25, -4);
    glEnd();

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////PINTU//////////////////////////////////////////
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(16.5, 12.5, 50.0);
    glVertex3f(16.5, 16.5, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(4.5, 12.5, 50.0);
    glVertex3f(4.5, 16.5, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-6.5, 16.5, 50); /* front */
    glVertex3f(-6.5, 12.5, 50);
    glVertex3f(4.5, 12.5, 50);
    glVertex3f(4.5, 16.5, 50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(5.5, 16.5, 50); /* front */
    glVertex3f(5.5, 12.5, 50);
    glVertex3f(16.5, 12.5, 50);
    glVertex3f(16.5, 16.5, 50);
    glEnd();

    glColor3f(1.0, 0.549, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-7, 17, 50); /* front */
    glVertex3f(-7, 12.0, 50);
    glVertex3f(17, 12.0, 50);
    glVertex3f(17, 17, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-6.6, 6.5, 50); /* front */
    glVertex3f(-6.6, 10.9, 50);
    glVertex3f(-1.4, 10.9, 50);
    glVertex3f(-1.4, 6.5, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-6.6, 1.5, 50); /* front */
    glVertex3f(-6.6, 6, 50);
    glVertex3f(-1.4, 6, 50);
    glVertex3f(-1.4, 1.5, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-1, 1.5, 50); /* front */
    glVertex3f(-1, 6, 50);
    glVertex3f(4.3, 6, 50);
    glVertex3f(4.3, 1.5, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-1, 6.5, 50); /* front */
    glVertex3f(-1, 10.9, 50);
    glVertex3f(4.3, 10.9, 50);
    glVertex3f(4.3, 6.5, 50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(4.7, 1, 50); /* front */
    glVertex3f(4.7, 11.5, 50);
    glVertex3f(5.4, 11.5, 50.0);
    glVertex3f(5.4, 1, 50.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(5.8, 6.5, 50); /* front */
    glVertex3f(5.8, 10.9, 50);
    glVertex3f(10.9, 10.9, 50);
    glVertex3f(10.9, 6.5, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(11.3, 6.5, 50); /* front */
    glVertex3f(11.3, 10.9, 50);
    glVertex3f(16.3, 10.9, 50);
    glVertex3f(16.3, 6.5, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(11.3, 1.5, 50); /* front */
    glVertex3f(11.3, 6, 50);
    glVertex3f(16.3, 6, 50);
    glVertex3f(16.3, 1.5, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(5.8, 1.5, 50); /* front */
    glVertex3f(5.8, 6, 50);
    glVertex3f(10.9, 6, 50);
    glVertex3f(10.9, 1.5, 50);
    glEnd();

    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);
    glVertex3f(-7, 0, 50); /* front */
    glVertex3f(-7, 1, 50);
    glVertex3f(16.5, 1, 50);
    glVertex3f(16.5, 0, 50);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-7, 1, 50); /* front */
    glVertex3f(-7, 11.5, 50);
    glVertex3f(16.5, 11.5, 50);
    glVertex3f(16.5, 1, 50);
    glEnd();

    /////////////////////////////////////////////////////////////////////////////////////////
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-10.0, 0.8, 50.0);
    glVertex3f(-10.0, 16.5, 50.0);
    glVertex3f(-8.2, 16.5, 50.0);
    glVertex3f(-8.2, 0.8, 50.0);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-8.2, 16.5, 50.0);
    glVertex3f(-8.2, 0.8, 50.0);
    glEnd();

    //Pojok Kiri Luar
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-10.0, 0, 50.0);
    glVertex3f(-10.0, 17, 50.0);
    glVertex3f(-7.5, 17, 50.0);
    glVertex3f(-7.5, 0, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-7.5, 17, 50.0);
    glVertex3f(-7.5, 0, 50.0);
    glEnd();

    //Pojok Kiri Dalam
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-10.0, 39.4, 50.0);
    glVertex3f(-10.0, 23.6, 50.0);
    glVertex3f(-8.2, 23.6, 50.0);
    glVertex3f(-8.2, 39.4, 50.0);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-8.2, 23.6, 50.0);
    glVertex3f(-8.2, 39.4, 50.0);
    glEnd();

    //Pojok Kiri Luar
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-10.0, 40.0, 50.0);
    glVertex3f(-10.0, 23.0, 50.0);
    glVertex3f(-7.5, 23.0, 50.0);
    glVertex3f(-7.5, 40.0, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-7.5, 23.0, 50.0);
    glVertex3f(-7.5, 40.0, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 40.0, 50.0);
    glVertex3f(-7.5, 40.0, 50.0);
    glEnd();

    //Garis Pembatas
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-7.5, 40.0, 50.0);
    glVertex3f(-7.5, 23.0, 50.0);
    glVertex3f(-7.0, 23.0, 50.0);
    glVertex3f(-7.0, 40.0, 50.0);
    glEnd();

    //Garis Pembatas
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-7.5 + 12.3, 40.0, 50.0);
    glVertex3f(-7.5 + 12.3, 23.0, 50.0);
    glVertex3f(-7.0 + 12.3, 23.0, 50.0);
    glVertex3f(-7.0 + 12.3, 40.0, 50.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-7.5 + 12.3, 40.0, 50.0);
    glVertex3f(-7.5 + 12.3, 23.0, 50.0);
    glVertex3f(-7.0 + 12.3, 23.0, 50.0);
    glVertex3f(-7.0 + 12.3, 40.0, 50.0);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-7.5, 40.0, 50.0);
    glVertex3f(-7.5, 23.0, 50.0);
    glVertex3f(-7.0, 23.0, 50.0);
    glVertex3f(-7.0, 40.0, 50.0);
    glEnd();
}

void Box(int x, int y)
{
    glPushMatrix();
    glTranslated(0.5, 0, 0);
    glColor3ub(139, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(-1 + x, 35 + y, 53); /* front */
    glVertex3f(-1 + x, 26.5 + y, 53);
    glVertex3f(4 + x, 26.5 + y, 53);
    glVertex3f(4 + x, 35 + y, 53);

    glVertex3f(4 + x, 35 + y, 53); /* right */
    glVertex3f(4 + x, 26.5 + y, 53);
    glVertex3f(4 + x, 26.5 + y, 50);
    glVertex3f(4 + x, 35 + y, 50);

    glVertex3f(-1 + x, 35 + y, 50); /* left */
    glVertex3f(-1 + x, 26.5 + y, 50);
    glVertex3f(-1 + x, 26.5 + y, 53);
    glVertex3f(-1 + x, 35 + y, 53);

    glVertex3f(-1 + x, 35 + y, 53); /* top */
    glVertex3f(4 + x, 35 + y, 53);
    glVertex3f(4 + x, 35 + y, 50);
    glVertex3f(-1 + x, 35 + y, 50);

    glVertex3f(-1 + x, 26.5 + y, 50); /* bottom */
    glVertex3f(4 + x, 26.5 + y, 50);
    glVertex3f(4 + x, 26.5 + y, 53);
    glVertex3f(-1 + x, 26.5 + y, 53);
    glEnd();

    glPopMatrix();
}

void Box2(int x, int y)
{
    glPushMatrix();
    glTranslated(0.5, 0, 0);
    glColor3ub(139, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(-1 + x, 35 + y, 53); /* front */
    glVertex3f(-1 + x, 26.5 + y, 53);
    glVertex3f(2.5 + x, 26.5 + y, 53);
    glVertex3f(2. + x, 35 + y, 53);

    glVertex3f(2.5 + x, 35 + y, 53); /* right */
    glVertex3f(2.5 + x, 26.5 + y, 53);
    glVertex3f(2.5 + x, 26.5 + y, 50);
    glVertex3f(2.5 + x, 35 + y, 50);

    glVertex3f(-1 + x, 35 + y, 50); /* left */
    glVertex3f(-1 + x, 26.5 + y, 50);
    glVertex3f(-1 + x, 26.5 + y, 53);
    glVertex3f(-1 + x, 35 + y, 53);

    glVertex3f(-1 + x, 35 + y, 53); /* top */
    glVertex3f(2.5 + x, 35 + y, 53);
    glVertex3f(2.5 + x, 35 + y, 50);
    glVertex3f(-1 + x, 35 + y, 50);

    glVertex3f(-1 + x, 26.5 + y, 50); /* bottom */
    glVertex3f(2.5 + x, 26.5 + y, 50);
    glVertex3f(2.5 + x, 26.5 + y, 53);
    glVertex3f(-1 + x, 26.5 + y, 53);
    glEnd();

    glPopMatrix();
}

void Tengah3_2(int y)
{
    //Layer 1
    glLineWidth(4.0);
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(17.5, 39.5 + y, 50.0);
    glVertex3f(17.5, 23.5 + y, 50.0);
    glVertex3f(20.0, 23.5 + y, 50.0);
    glVertex3f(20.0, 39.5 + y, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(20.0, 23.5 + y, 50.0);
    glVertex3f(20.0, 39.5 + y, 50.0);
    glEnd();

    //Layer 2
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(21.0, 39.5 + y, 50.0);
    glVertex3f(21.0, 23.5 + y, 50.0);
    glVertex3f(25.0, 23.5 + y, 50.0);
    glVertex3f(25.0, 39.5 + y, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(25.0, 23.5 + y, 50.0);
    glVertex3f(25.0, 39.5 + y, 50.0);
    glEnd();

    //Layer 3
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(26.0, 39.5 + y, 50.0);
    glVertex3f(26.0, 23.5 + y, 50.0);
    glVertex3f(28.3, 23.5 + y, 50.0);
    glVertex3f(28.3, 39.5 + y, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(28.3, 23.5 + y, 50.0);
    glVertex3f(28.3, 39.5 + y, 50.0);
    glEnd();

    //Layer 4
    glLineWidth(4.0);
    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(26.0 + 9.7, 39.5 + y, 50.0);
    glVertex3f(26.0 + 9.7, 35.5 + y, 50.0);
    glVertex3f(28.3 + 9.7, 35.5 + y, 50.0);
    glVertex3f(28.3 + 9.7, 39.5 + y, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(28.3 + 9.7, 35.5 + y, 50.0);
    glVertex3f(28.3 + 9.7, 39.5 + y, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(26.2 + 19.9, 38.5 - 11.9 + y, 50.0);
    glVertex3f(26.2 + 19.9, 35.5 - 11.9 + y, 50.0);
    glVertex3f(28.1 + 19.9, 35.5 - 11.9 + y, 50.0);
    glVertex3f(28.1 + 19.9, 38.5 - 11.9 + y, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(28.1 + 19.9, 35.5 - 11.9 + y, 50.0);
    glVertex3f(28.1 + 19.9, 38.5 - 11.9 + y, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(25.8 + 19.9, 39.0 - 11.9 + y, 50.0);
    glVertex3f(25.8 + 19.9, 35.0 - 11.9 + y, 50.0);
    glVertex3f(28.5 + 19.9, 35.0 - 11.9 + y, 50.0);
    glVertex3f(28.5 + 19.9, 39.0 - 11.9 + y, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(25.8 + 19.9, 39.0 - 11.9 + y, 50.0);
    glVertex3f(25.8 + 19.9, 35.0 - 11.9 + y, 50.0);
    glVertex3f(28.5 + 19.9, 35.0 - 11.9 + y, 50.0);
    glVertex3f(28.5 + 19.9, 39.0 - 11.9 + y, 50.0);
    glEnd();

    //Layer 5
    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(26.0 + 19.9, 39.5 + y, 50.0);
    glVertex3f(26.0 + 19.9, 35.5 + y, 50.0);
    glVertex3f(28.3 + 19.9, 35.5 + y, 50.0);
    glVertex3f(28.3 + 19.9, 39.5 + y, 50.0);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(4.0);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(28.3 + 19.9, 35.5 + y, 50.0);
    glVertex3f(28.3 + 19.9, 39.5 + y, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(26.2 + 9.7, 38.5 - 11.9 + y, 50.0);
    glVertex3f(26.2 + 9.7, 35.5 - 11.9 + y, 50.0);
    glVertex3f(28.1 + 9.7, 35.5 - 11.9 + y, 50.0);
    glVertex3f(28.1 + 9.7, 38.5 - 11.9 + y, 50.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(28.1 + 9.7, 35.5 - 11.9 + y, 50.0);
    glVertex3f(28.1 + 9.7, 38.5 - 11.9 + y, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(25.8 + 9.7, 39.0 - 11.9 + y, 50.0);
    glVertex3f(25.8 + 9.7, 35.0 - 11.9 + y, 50.0);
    glVertex3f(28.5 + 9.7, 35.0 - 11.9 + y, 50.0);
    glVertex3f(28.5 + 9.7, 39.0 - 11.9 + y, 50.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(25.8 + 9.7, 39.0 - 11.9 + y, 50.0);
    glVertex3f(25.8 + 9.7, 35.0 - 11.9 + y, 50.0);
    glVertex3f(28.5 + 9.7, 35.0 - 11.9 + y, 50.0);
    glVertex3f(28.5 + 9.7, 39.0 - 11.9 + y, 50.0);
    glEnd();
}

void Tengah3(int y)
{
    //Layer 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(17.1, 40.0 + y, 50.0);
    glVertex3f(17.1, 23.0 + y, 50.0);
    glVertex3f(20.5, 23.0 + y, 50.0);
    glVertex3f(20.5, 40.0 + y, 50.0);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(17.1, 40.0 + y, 50.0);
    glVertex3f(17.1, 23.0 + y, 50.0);
    glVertex3f(20.5, 23.0 + y, 50.0);
    glVertex3f(20.5, 40.0 + y, 50.0);
    glEnd();

    //Layer 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(20.5, 40.0 + y, 50.0);
    glVertex3f(20.5, 23.0 + y, 50.0);
    glVertex3f(25.5, 23.0 + y, 50.0);
    glVertex3f(25.5, 40.0 + y, 50.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(20.5, 40.0 + y, 50.0);
    glVertex3f(20.5, 23.0 + y, 50.0);
    glVertex3f(25.5, 23.0 + y, 50.0);
    glVertex3f(25.5, 40.0 + y, 50.0);
    glEnd();

    //Layer 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(25.5, 40.0 + y, 50.0);
    glVertex3f(25.5, 23.0 + y, 50.0);
    glVertex3f(28.8, 23.0 + y, 50.0);
    glVertex3f(28.8, 40.0 + y, 50.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(25.5, 40.0 + y, 50.0);
    glVertex3f(25.5, 23.0 + y, 50.0);
    glVertex3f(28.8, 23.0 + y, 50.0);
    glVertex3f(28.8, 40.0 + y, 50.0);
    glEnd();

    //Layer 4
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(25.5 + 9.7, 35.0 + y, 50.0);
    glVertex3f(25.5 + 9.7, 23.0 + y, 50.0);
    glVertex3f(28.8 + 9.7, 23.0 + y, 50.0);
    glVertex3f(28.8 + 9.7, 35.0 + y, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(25.5 + 9.7, 40.0 + y, 50.0);
    glVertex3f(25.5 + 9.7, 23.0 + y, 50.0);
    glVertex3f(28.8 + 9.7, 23.0 + y, 50.0);
    glVertex3f(28.8 + 9.7, 40.0 + y, 50.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(25.5 + 9.7, 40.0 + y, 50.0);
    glVertex3f(25.5 + 9.7, 23.0 + y, 50.0);
    glVertex3f(28.8 + 9.7, 23.0 + y, 50.0);
    glVertex3f(28.8 + 9.7, 40.0 + y, 50.0);
    glEnd();

    //Layer 5
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(25.5 + 19.9, 35.0 + y, 50.0);
    glVertex3f(25.5 + 19.9, 23.0 + y, 50.0);
    glVertex3f(28.8 + 19.9, 23.0 + y, 50.0);
    glVertex3f(28.8 + 19.9, 35.0 + y, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(25.5 + 19.9, 40.0 + y, 50.0);
    glVertex3f(25.5 + 19.9, 23.0 + y, 50.0);
    glVertex3f(28.8 + 19.9, 23.0 + y, 50.0);
    glVertex3f(28.8 + 19.9, 40.0 + y, 50.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(25.5 + 19.9, 40.0 + y, 50.0);
    glVertex3f(25.5 + 19.9, 23.0 + y, 50.0);
    glVertex3f(28.8 + 19.9, 23.0 + y, 50.0);
    glVertex3f(28.8 + 19.9, 40.0 + y, 50.0);
    glEnd();
}

void SampingKiriPembatas(int y)
{

    //Pojok Kiri Dalam
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-10.0, 39.4 + y, 50.0);
    glVertex3f(-10.0, 23.6 + y, 50.0);
    glVertex3f(-10.0, 23.6 + y, 48.2);
    glVertex3f(-10.0, 39.4 + y, 48.2);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 23.6 + y, 48.2);
    glVertex3f(-10.0, 39.4 + y, 48.2);
    glEnd();

    //Pojok Kiri Luar
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-10.0, 40.0 + y, 50.0);
    glVertex3f(-10.0, 23.0 + y, 50.0);
    glVertex3f(-10.0, 23.0 + y, 47.5);
    glVertex3f(-10.0, 40.0 + y, 47.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 40.0 + y, 50.0);
    glVertex3f(-10.0, 23.0 + y, 50.0);
    glVertex3f(-10.0, 23.0 + y, 47.5);
    glVertex3f(-10.0, 40.0 + y, 47.5);
    glEnd();

    //Tengah Pembatas
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-10.0, 17.0, 50.0);
    glVertex3f(-10.0, 23.0, 50.0);
    glVertex3f(-10.0, 23.0, 30);
    glVertex3f(-10.0, 17.0, 30);
    glEnd();
}

void PembatasTengah(int x)
{
    glBegin(GL_QUADS);
    glColor3ub(210, 180, 140);
    glVertex3f(-10.0, 17.0, 49.0 + x);
    glVertex3f(-10.0, 23.0, 49.0 + x);
    glVertex3f(-10.0, 23.0, 50.0 + x);
    glVertex3f(-10.0, 17.0, 50.0 + x);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 17.0, 49.0 + x);
    glVertex3f(-10.0, 23.0, 49.0 + x);
    glVertex3f(-10.0, 23.0, 48.7 + x);
    glVertex3f(-10.0, 17.0, 48.7 + x);
    glEnd();
}

void Jendela(int x, int y, int z)
{
    glLineWidth(4.0);

    //Dalam Kotak 2
    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-10.0, 39.1 + y, 46.0 + z);
    glVertex3f(-10.0, 36.5 + y, 46.0 + z);
    glVertex3f(-10.0, 36.5 + y, 44.8 + z);
    glVertex3f(-10.0, 39.1 + y, 44.8 + z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 39.1 + y, 46.0 + z);
    glVertex3f(-10.0, 36.5 + y, 46.0 + z);
    glEnd();

    //Dalam Kotak 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-10.0, 39.3 + y, 46.3 + z);
    glVertex3f(-10.0, 36.0 + y, 46.3 + z);
    glVertex3f(-10.0, 36.0 + y, 44.5 + z);
    glVertex3f(-10.0, 39.3 + y, 44.5 + z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 39.3 + y, 46.3 + z);
    glVertex3f(-10.0, 36.0 + y, 46.3 + z);
    glVertex3f(-10.0, 36.0 + y, 44.5 + z);
    glVertex3f(-10.0, 39.3 + y, 44.5 + z);
    glEnd();

    //Kotak Tengah
    glBegin(GL_QUADS);
    glColor3f(0.529, 0.808, 0.921);
    glVertex3f(-10.0, 36.0 + y, 46.3 + z);
    glVertex3f(-10.0, 30.0 + y, 46.3 + z);
    glVertex3f(-10.0, 30.0 + y, 44.5 + z);
    glVertex3f(-10.0, 36.0 + y, 44.5 + z);
    glEnd();

    //Kotak Cokelat
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-10.0, 39.4 + y, 46.3 + z);
    glVertex3f(-10.0, 23.6 + y, 46.3 + z);
    glVertex3f(-10.0, 23.6 + y, 44.5 + z);
    glVertex3f(-10.0, 39.4 + y, 44.5 + z);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 39.4 + y, 46.3 + z);
    glVertex3f(-10.0, 23.6 + y, 46.3 + z);
    glEnd();

    //Luar Kotak
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-10.0, 40.0 + y, 47.0 + z);
    glVertex3f(-10.0, 23.0 + y, 47.0 + z);
    glVertex3f(-10.0, 23.0 + y, 44.0 + z);
    glVertex3f(-10.0, 40.0 + y, 44.0 + z);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 40.0 + y, 47.0 + z);
    glVertex3f(-10.0, 23.0 + y, 47.0 + z);
    glVertex3f(-10.0, 23.0 + y, 44.0 + z);
    glVertex3f(-10.0, 40.0 + y, 44.0 + z);
    glEnd();
}

void SampingKiri(int x, int y, int z)
{
    //Dalam Kotak
    glBegin(GL_QUADS);
    glColor3f(0.568, 0.286, 0.0);
    glVertex3f(-10.0, 39.4 + y, 46.3 + z);
    glVertex3f(-10.0, 23.6 + y, 46.3 + z);
    glVertex3f(-10.0, 23.6 + y, 44.5 + z);
    glVertex3f(-10.0, 39.4 + y, 44.5 + z);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 39.4 + y, 46.3 + z);
    glVertex3f(-10.0, 23.6 + y, 46.3 + z);
    glEnd();

    //Luar Kotak
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.549, 0.0);
    glVertex3f(-10.0, 40.0 + y, 47.0 + z);
    glVertex3f(-10.0, 23.0 + y, 47.0 + z);
    glVertex3f(-10.0, 23.0 + y, 44.0 + z);
    glVertex3f(-10.0, 40.0 + y, 44.0 + z);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.0, 40.0 + y, 47.0 + z);
    glVertex3f(-10.0, 23.0 + y, 47.0 + z);
    glVertex3f(-10.0, 23.0 + y, 44.0 + z);
    glVertex3f(-10.0, 40.0 + y, 44.0 + z);
    glEnd();
}

void keyboard(unsigned char key, int x, int y)
{
    /* This time the controls are:

      "a": move left
      "d": move right
      "w": move forward
      "s": move back
      "t": toggle depth-testing

    */
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(5.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-5.0, 0.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 5.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -5.0);
        break;
    case '7':
        glTranslatef(0.0, 3.0, 0.0); //ke atas
        break;
    case '9':
        glTranslatef(0.0, -3.0, 0.0); // ke bawah
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0); // memutar sebanyak 2 koorninat di sumbu x. Putar depan karena +
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0); // putar atas
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0); // putar kanan
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0); // putar kiri
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0); // putar nyamping x berlawanan jarum jam karena +
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0); // putar searag jarum jam
        break;
    case 't':
    case 'T':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}

void mouseFunction(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            glRotatef(-16.0, 0.0, 1.0, 0.0);
        }
    }
    else if (button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            glRotatef(16.0, 0.0, 1.0, 0.0);
        }
    }
    display();
}

void resize(int width, int height)
{
    if (height == 0)
        height = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, width / height, 1.0, 400.0);

    glTranslatef(0.0, -5.0, -150.0);

    glMatrixMode(GL_MODELVIEW);
}
