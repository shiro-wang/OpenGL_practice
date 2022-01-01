#include <GL\glew.h>
#include <GL\freeglut.h>
#include <time.h>
#include <string>
#include "glm.c"
#include "sgi.h"
#include "materials.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#pragma warning(disable:4996)
//#include "stb_image.h"
#define T(x) (model->triangles[(x)])
using namespace std;


#define STB_IMAGE_IMPLEMENTATION

#define WIDTH 935
#define HEIGHT 311

#define ANGLEMODE 0
#define STRENGTHMODE 1
#define SHOOTMODE 2
#define SHOWRESULT 3
#define XMOVEMODE 4

#define SHOOT_GENERALMODE 0
#define SHOOT_CHEATMODE 1
GLfloat PI = 3.14;
//camera position
float person_x = 50.0, person_y = 10.0, person_z = 10.0;
float save_px = 50.0;
float cam_x = person_x - 40.0, cam_y = person_y, cam_z = person_z - 10.0;
//texture
GLuint texName;
GLuint target_init;
//materail
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat low_shininess[] = { 1.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };
GLfloat mat_dice[] = { 0.5, 0.5 ,0.5 };
GLfloat mat_diffuse_dice[] = { 0.5, 0.5 ,0.50 };
//target
GLfloat target_x = person_x;
GLfloat target_y = person_y;
GLfloat target_z = person_z - 30.0;
//shoot
GLint shoot_mode = XMOVEMODE;
GLfloat shoot_angle = 0.0;
GLfloat shoot_speed = 5.0;
GLfloat gravity = 0.1;
GLfloat fly_time = 0.0;
GLfloat fly_height = 0.0;
GLfloat fly_way = 0.0;
//arrow
GLuint arrow_list;
GLuint stength_render_list;
//animation
int player_mode = SHOOT_GENERALMODE;
int angle_animate = 0;
int strength_animate = 0;
int xmove_animate = 0;

void arrow_obj() {
    GLMmodel* pmodel = NULL;
    if (!pmodel) {
        char filename[] = "11750_throwing_dart_v1_L3.obj";
        pmodel = glmReadOBJ(filename);
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}
void target() {
    glBegin(GL_POLYGON); 
    int n = 720;
    glColor3f(1.0, 1.f, 1.f); 
    for (int i = 0; i < n; i++) {
        glVertex3f(10 * cos(2 * PI / n * i), 10 * sin(2 * PI / n * i), 0.f);
    }
    glEnd();
    glBegin(GL_POLYGON); 
    glColor3f(0.0, 0.f, 0.f); 
    for (int i = 0; i < n; i++) {
        glVertex3f(8 * cos(2 * PI / n * i), 8 * sin(2 * PI / n * i), 0.001f);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.4, 0.7);
    for (int i = 0; i < n; i++) {
        glVertex3f(6 * cos(2 * PI / n * i), 6 * sin(2 * PI / n * i), 0.002f);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.f, 0.f);
    for (int i = 0; i < n; i++) {
        glVertex3f(4 * cos(2 * PI / n * i), 4 * sin(2 * PI / n * i), 0.003f);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.f);
    for (int i = 0; i < n; i++) {
        glVertex3f(2 * cos(2 * PI / n * i), 2 * sin(2 * PI / n * i), 0.004f);
    }
    glEnd();
    for (int j = 1; j <= 10; j++) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.f, 0.f, 0.f);
        for (int i = 0; i < n; i++) {
            glVertex3f(j * cos(2 * PI / n * i), j * sin(2 * PI / n * i), 0.005f);
        }
        glEnd();
    }
}
void throw_line() {
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glColor3f(1.0, 1.0, 1.0);
    
    glBegin(GL_LINE_STRIP);
        glVertex3f(0.0, 0.0 , 0.0);
        glVertex3f(0.0, sin(PI / 180.0 * shoot_angle), - cos(PI / 180.0 * shoot_angle));
    glEnd();
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDisable(GL_LINE_STIPPLE);
}
void count_point() {
    int point = 0;
    printf("target pos: %f %f %f\n", person_x, person_y + fly_height, person_z - fly_way);
    if (person_x >= -1.0 + target_x && person_x <= 1.0 + target_x && person_y + fly_height >= -1.0 + target_y && person_y + fly_height <= 1.0 + target_y) {
        point = 10;
    }else if (person_x >= -2.0 + target_x && person_x <= 2.0 + target_x && person_y + fly_height >= -2.0 + target_y && person_y + fly_height <= 2.0 + target_y) {
        point = 9;
    }
    else if (person_x >= -3.0 + target_x && person_x <= 3.0 + target_x && person_y + fly_height >= -3.0 + target_y && person_y + fly_height <= 3.0 + target_y) {
        point = 8;
    }
    else if (person_x >= -4.0 + target_x && person_x <= 4.0 + target_x && person_y + fly_height >= -4.0 + target_y && person_y + fly_height <= 4.0 + target_y) {
        point = 7;
    }
    else if (person_x >= -5.0 + target_x && person_x <= 5.0 + target_x && person_y + fly_height >= -5.0 + target_y && person_y + fly_height <= 5.0 + target_y) {
        point = 6;
    }
    else if (person_x >= -6.0 + target_x && person_x <= 6.0 + target_x && person_y + fly_height >= -6.0 + target_y && person_y + fly_height <= 6.0 + target_y) {
        point = 5;
    }
    else if (person_x >= -7.0 + target_x && person_x <= 7.0 + target_x && person_y + fly_height >= -7.0 + target_y && person_y + fly_height <= 7.0 + target_y) {
        point = 4;
    }
    else if (person_x >= -8.0 + target_x && person_x <= 8.0 + target_x && person_y + fly_height >= -8.0 + target_y && person_y + fly_height <= 8.0 + target_y) {
        point = 3;
    }
    else if (person_x >= -9.0 + target_x && person_x <= 9.0 + target_x && person_y + fly_height >= -9.0 + target_y && person_y + fly_height <= 9.0 + target_y) {
        point = 2;
    }
    else if (person_x >= -10.0 + target_x && person_x <= 10.0 + target_x && person_y + fly_height >= -10.0 + target_y && person_y + fly_height <= 10.0 + target_y) {
        point = 1;
    }
    printf("point: %d\n", point);
}
void strength_render(float nyhealth_rm) {
    float remain_rate = nyhealth_rm / 5.0 * 1.0 - 0.5;
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    
    glTranslatef(person_x + 0.6, person_y + 0.7, person_z + 0.0);
    glScalef(0.5, 0.5, 0.5);
    //glTranslatef(cam_x, cam_y, cam_z);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5, -0.1, -0.09);
        glVertex3f(remain_rate, -0.1,  -0.09);
        glVertex3f(remain_rate, 0.1,  -0.09);
        glVertex3f(-0.5, 0.1,  -0.09);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5, -0.1, - 0.1);
        glVertex3f(0.5, -0.1, - 0.1);
        glVertex3f(0.5, 0.1, - 0.1);
        glVertex3f(-0.5, 0.1, - 0.1);
    glEnd();
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}
void shoot_reset() {
    angle_animate = 0;
    strength_animate = 0;
    xmove_animate = 0;
    person_x = 0.0; 
    person_y = 10.0; 
    person_z = 10.0;
    fly_height = 0.0;
    fly_way = 0.0;
    fly_time = 0.0;
    shoot_speed = 5.0;
}
void display(void)
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    if (shoot_mode == ANGLEMODE || shoot_mode == STRENGTHMODE) {
        gluLookAt(person_x - 0.5, person_y, person_z + 1.0, person_x, person_y, person_z - 100.0, 0.0, 1.0, 0.0);
    }
    else if (shoot_mode == XMOVEMODE){
        gluLookAt(person_x , person_y, person_z + 1.0, person_x, person_y, person_z - 100.0, 0.0, 1.0, 0.0);
    }
    else{
        gluLookAt(cam_x, cam_y, cam_z, cam_x + 10.0, cam_y, cam_z, 0.0, 1.0, 0.0);
    }
    glPushMatrix();
        glTranslatef(target_x, target_y, target_z);
        glCallList(target_init);
    glPopMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glPushMatrix();
        glTranslatef(person_x, person_y + fly_height, person_z - fly_way);
        throw_line();
        glCallList(arrow_list);
    glPopMatrix();
    glPushMatrix();
        if (shoot_mode != ANGLEMODE) {
            //glPushMatrix();
            strength_render(shoot_speed);
            //glPopMatrix();
        }
    glPopMatrix();
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
    
    //target
    target_init = glGenLists(1);
    glNewList(target_init,  GL_COMPILE);
        target();
    glEndList();
    //arrow
    arrow_list = glGenLists(1);
    glNewList(arrow_list, GL_COMPILE);
        arrow_obj();
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
            if (shoot_mode == XMOVEMODE) {
                shoot_mode = ANGLEMODE;
            }
            else if (shoot_mode == ANGLEMODE) {
                shoot_mode = STRENGTHMODE;
            }
            else if (shoot_mode == STRENGTHMODE) {
                shoot_mode = SHOOTMODE;
            }
            else if (shoot_mode == SHOOTMODE) {
                shoot_mode = SHOWRESULT;
            }
            else if (shoot_mode == SHOWRESULT){
                shoot_reset();
                shoot_mode = XMOVEMODE;
            }
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
        if (player_mode == SHOOT_CHEATMODE) {
            person_z -= 0.1;
            glutPostRedisplay();
        }
        break;
    case 's':
    case 'S':
        if (player_mode == SHOOT_CHEATMODE) {
            person_z += 0.1;
            glutPostRedisplay();
        }
        break;
    case 'a':
    case 'A':
        if (player_mode == SHOOT_CHEATMODE) {
            person_x -= 0.1;
            glutPostRedisplay();
        }
        break;
    case 'd':
    case 'D':
        if (player_mode == SHOOT_CHEATMODE) {
            person_x += 0.1;
            glutPostRedisplay();
        }
        break;
    case '+':
        if (player_mode == SHOOT_CHEATMODE && shoot_mode == STRENGTHMODE) {
            shoot_speed += 0.1;
        }
        else if (player_mode == SHOOT_CHEATMODE && shoot_mode == ANGLEMODE) {
            shoot_angle += 1.;
        }
        glutPostRedisplay();
        break;
    case '-':
        if (player_mode == SHOOT_CHEATMODE && shoot_mode == STRENGTHMODE) {
            shoot_speed -= 0.1;
        }
        else if (player_mode == SHOOT_CHEATMODE && shoot_mode == ANGLEMODE) {
            shoot_angle -= 1.;
        }
        glutPostRedisplay();
        break;
    case 'm':
    case 'M':
        if (player_mode == SHOOT_GENERALMODE) {
            player_mode = SHOOT_CHEATMODE;
        }
        else {
            player_mode = SHOOT_GENERALMODE;
        }
        break;
    default:
        break;
    }
    printf("shoot_angle:%f shoot_speed: %f \n", shoot_angle, shoot_speed);
}

void idle() {
    if (player_mode == SHOOT_GENERALMODE) {
        if (shoot_mode == XMOVEMODE) {
            if (xmove_animate == 0) {
                person_x += 0.2;
                if (person_x > save_px + 10.0) {
                    xmove_animate = 1;
                }
            }
            if (xmove_animate == 1) {
                person_x -= 0.2;
                if (person_x < save_px - 10.0) {
                    xmove_animate = 0;
                }
            }
        }
        if (shoot_mode == ANGLEMODE) {
            if (angle_animate == 0) {
                shoot_angle += 0.2;
                if (shoot_angle > 85.0) {
                    angle_animate = 1;
                }
            }
            if (angle_animate == 1) {
                shoot_angle -= 0.2;
                if (shoot_angle < 0.0) {
                    angle_animate = 0;
                }
            }
            //printf("%f \n", (shoot_angle));
        }
        if (shoot_mode == STRENGTHMODE) {
            if (strength_animate == 0) {
                shoot_speed -= 0.05;
                if (shoot_speed <= 0.0) {
                    strength_animate = 1;
                }
            }
            if (strength_animate == 1) {
                shoot_speed += 0.05;
                if (shoot_speed >= 5.0) {
                    strength_animate = 0;
                }
            }
            //printf("%f \n", (shoot_speed));
        }
    }
    
    if (shoot_mode == SHOOTMODE) {
        float y_speed = sin(PI / 180.0 * shoot_angle) * shoot_speed;
        float z_speed = cos(PI / 180.0 * shoot_angle) * shoot_speed;
        fly_height = y_speed * fly_time - gravity * fly_time * fly_time / 2;
        fly_way = z_speed * fly_time;
        fly_time += 0.05;
        if (person_y + fly_height <= 0. || person_z - fly_way <= target_z) {
            count_point();
            shoot_mode = SHOWRESULT;
        }
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
