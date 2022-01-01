#include <GL\glew.h>
#include <GL\freeglut.h>
#include <time.h>
#include <string>
#include "glm.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
//#include "stb_image.h"
#define T(x) (model->triangles[(x)])
using namespace std;

#pragma warning(disable:4996)
#define STB_IMAGE_IMPLEMENTATION

#define POINTER 1

#define DRAWARRAY 1

#define WIDTH 935
#define HEIGHT 311

int setupMethod = POINTER;
int derefMethod = DRAWARRAY;
GLfloat PI = 3.14;
//camera position
float cam_x = 0.0, cam_y = 0.0, cam_z = 10.0;
//texture
GLuint texName;
GLuint dice_init;
//materail
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat low_shininess[] = { 1.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };
GLfloat mat_dice[] = { 0.5, 0.5 ,0.5 };
GLfloat mat_diffuse_dice[] = { 0.5, 0.5 ,0.50 };
//dice
GLint dice_rotate = 1;
GLint dice_rotate_mode = 0;
GLfloat dice_rotate_angle0 = 0.0;
GLfloat dice_rotate_angle1 = 0.0;
GLfloat dice_rotate_angle2 = 0.0;
GLint dice_scala_open = 0;
GLint dice_scala_big = 0;
GLfloat dice_scalaf = 1.0;
int path = 0;

void draw_circle(float R) {
    glBegin(GL_POLYGON);
    int n = 720;
    for (int i = 0; i < n; i++)
        glVertex3f(R * cos(2 * PI / n * i), R * sin(2 * PI / n * i), 0.01f);//計算坐標
    glEnd();
    glFlush();//強制刷新緩衝，保證命令被執行
}
void dice_point_1() {
    glPushMatrix();
        glTranslatef(0.f, 0.f, 2.f);
        glColor3f(1.0, 0.0, 0.0);
        draw_circle(0.5);
    glPopMatrix(); 
}
void dice_point_2() {
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glRotatef(90.0, -1.0, 0.0, 0.0);
        glPushMatrix();
            glTranslatef(1.f, -1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(-1.f, 1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
    glPopMatrix();
}
void dice_point_3() {
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        glPushMatrix();
            glTranslatef(1.f, -1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(-1.f, 1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(0.f, 0.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
    glPopMatrix();
}
void dice_point_4() {
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glRotatef(90.0, 0.0, -1.0, 0.0);
        glPushMatrix();
            glTranslatef(1.f, -1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(-1.f, 1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(1.f, 1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(-1.f, -1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
    glPopMatrix();
}
void dice_point_5() {
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glPushMatrix();
            glTranslatef(1.f, -1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(-1.f, 1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(1.f, 1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(-1.f, -1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(0.f, 0.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
    glPopMatrix();
}
void dice_point_6() {
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glRotatef(180.0, 0.0, -1.0, 0.0);
        glPushMatrix();
            glTranslatef(1.f, -1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(-1.f, 1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(1.f, 1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(-1.f, -1.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(1.f, 0.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
        glPushMatrix();
            glTranslatef(-1.f, 0.f, 2.f);
            draw_circle(0.5);
        glPopMatrix(); 
    glPopMatrix();
}
void dice_init_point() {
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glPushMatrix();
        dice_point_1();
        dice_point_2();
        dice_point_3();
        dice_point_4();
        dice_point_5();
        dice_point_6();
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}
void dice_init_total() {
    glTranslatef(0.f, 5.f, 0.f);
    if (dice_rotate == 1) {
         glRotatef(dice_rotate_angle0, 1.f, 1.f, 0.f);
         glRotatef(dice_rotate_angle1, 0.f, 1.f, 1.f);
         glRotatef(dice_rotate_angle2, 1.f, 0.f, 1.f);  
    }
    
    glCallList(dice_init);
}

void get_path() {
    srand(time(0));
    path = (rand() % 6) + 1;
    //printf("%d\n", path);
}
void dice_jump() {
    glTranslatef(0.f, 5.f, 0.f);
    glScalef(dice_scalaf, dice_scalaf, dice_scalaf);
    switch (path) {
    case 1:
        break;
    case 2:
        glRotatef(90, -1.0, 0.0, 0.0);
        break;
    case 3:
        glRotatef(90, 0.0, 1.0, 0.0);
        break;
    case 4:
        glRotatef(90, 0.0, -1.0, 0.0);
        break;
    case 5:
        glRotatef(90, 1.0, 0.0, 0.0);
        break;
    case 6:
        glRotatef(180, -1.0, 0.0, 0.0);
        break;
    default:
        break;
    }
    glCallList(dice_init);
}
void dice() {
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_dice);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_dice);
        glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
        glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
        glutSolidCube(4.0);
    glPopMatrix();
    glPushMatrix();
        dice_init_point();
    glPopMatrix();
}
void display(void)
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(cam_x, cam_y, cam_z , cam_x, cam_y, cam_z - 100.0, 0.0, 1.0, 0.0);
    setupMethod = POINTER;
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    if (dice_rotate == 1) {
        glPushMatrix();
            dice_init_total();
            //dice_init_point();
        glPopMatrix();
    }
    else {
        glPushMatrix();
            dice_jump();
        glPopMatrix();
    }
    
    
    glutSwapBuffers();
    glFlush();
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glDisable(GL_DEPTH_TEST);
}
void init(void)
{
    GLfloat ambient[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat position[] = { 50.0, 50.0, 50.0, 0.0 };
    glewInit();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, 1.0, 0.01, 200.0);
    glMatrixMode(GL_MODELVIEW);
    //light
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    //fog
    GLfloat fogColor[4] = { 0.0, 0.25, 0.25, 1.0 };
    glFogi(GL_FOG_MODE, GL_EXP2);
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogf(GL_FOG_DENSITY, 0.7);
    glHint(GL_FOG_HINT, GL_DONT_CARE);
    glFogf(GL_FOG_START, 0.1);
    glFogf(GL_FOG_END, 5.0);
    
    //dice
    dice_init = glGenLists(1);
    glNewList(dice_init,  GL_COMPILE);
        dice();
    glEndList();
    //dicepoint
    
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (GLfloat)w / (GLfloat)h, 1.0, 50.0);
    glMatrixMode(GL_MODELVIEW);


    gluLookAt(cam_x, cam_y, cam_z, cam_x, cam_y, cam_z - 50.0, 0.0, 1.0, 0.0);
}

void mouse(int button, int state, int x, int y)
{
    switch (button) {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            
        }
        break;
    default:
        break;
    }

}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    case 'w':
    case 'W':
        cam_z -= 0.1;
        glutPostRedisplay();
        break;
    case 's':
    case 'S':
        cam_z += 0.1;
        glutPostRedisplay();
        break;
    case 'a':
    case 'A':
        cam_x -= 0.1;
        glutPostRedisplay();
        break;
    case 'd':
    case 'D':
        cam_x += 0.1;
        glutPostRedisplay();
        break;
    case 32:
        if (dice_rotate == 1) {
            dice_rotate = 0;
            dice_scala_open = 1;
            dice_scala_big = 1;
            get_path();
        }
        else {
            dice_rotate = 1;
        }
    default:
        break;
    }

}

void idle() {
    if (dice_rotate == 1) {
        switch (dice_rotate_mode) {
        case 0:
            dice_rotate_angle0 += 1.f;
            if (dice_rotate_angle0 == 275.f) {
                dice_rotate_mode = 1;
               // printf("0->1\n");
            }
            break;
        case 1:
            dice_rotate_angle1 += 1.f;
            if (dice_rotate_angle1 == 205.f) {
                dice_rotate_mode = 2;
               // printf("1->2\n");
            }
            break;
        case 2:
            dice_rotate_angle2 += 1.f;
            if (dice_rotate_angle2 == 182.f) {
                dice_rotate_mode = 0;
              //  printf("2->0\n");
            }
            break;
        }
        if (dice_rotate_angle0 == 360.f) {
            dice_rotate_angle0 = 0.f;
        }
        if (dice_rotate_angle1 == 360.f) {
            dice_rotate_angle1 = 0.f;
        }
        if (dice_rotate_angle2 == 360.f) {
            dice_rotate_angle2 = 0.f;
        }
    }
    if (dice_scala_open == 1) {
        if (dice_scala_big == 1) {
            if (dice_scalaf < 1.3f) {
                dice_scalaf += 0.002f;
            }
            else {
                dice_scala_big = 0;
            }
        }
        else {
            if (dice_scalaf > 1.0f) {
                dice_scalaf -= 0.002f;
            }
            else {
                dice_scala_open = 0;
                dice_scalaf = 1.f;
            }
        }
        //printf("%f\n", dice_scalaf);
    }
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    //srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1280, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
