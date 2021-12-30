/***************************
4108056004 王思正 第6-VI次作業12/22
***************************/
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <time.h>
#include <string>
//#include "glm.c"
//#include "sgi.h"
//#include "materials.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
//#include <ctime>
//#include "stdafx.h"
//#include <gdal_priv.h>
#pragma warning(disable:4996)
//#include "stb_image.h"
//#include "ImageShow.h"
#define T(x) (model->triangles[(x)])
using namespace std;

//#define Guess_Big 1
//#define Guess_Small 2
//#define Guessing 1
#define STB_IMAGE_IMPLEMENTATION

GLfloat PI = 3.14;
//camera position
float cam_x = 0.0, cam_y = 0.0, cam_z = 10.0;
//float person_x = 0.0, person_y = 10.0, person_z = 10.0;
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
//
/*unsigned int  texture;    // 紋理對象
unsigned char* imgBuf = nullptr;
int imgWidth;
int imgHeight;
*/
//poker
GLuint card_list;
GLuint poker_list;

//gamble
#define GUESS_BEFORE 0
#define GUESS_AFTER 1

#define POKER_NOTSHOW_STATE 0
#define POKER_SHOW_STATE 1
#define POKER_RESULT_STATE 2

#define GUESS_BIG 1
#define GUESS_SMALL 2
#define GUESS_SAME 3

#define Gamble_S 0
#define Gamble_M 1
#define Gamble_L 2
int poker_mode = POKER_NOTSHOW_STATE;
int guess_mode = GUESS_BEFORE;
int guess = 0;
int gamble = Gamble_S;
int rand_start = 1;
int player_point = 0;
int CP_point = 0;

/*void ReadImage()
{
    GDALAllRegister();

    GDALDataset* img = (GDALDataset*)GDALOpen("lena.bmp", GA_ReadOnly);
    //GDALDataset* img = (GDALDataset *)GDALOpen("dst.tif", GA_ReadOnly);
    if (img == nullptr)
    {
        return;
    }

    imgWidth = img->GetRasterXSize();  //圖像寬度
    imgHeight = img->GetRasterYSize();  //圖像高度
    int bandNum = img->GetRasterCount();    //波段數
    int depth = GDALGetDataTypeSize(img->GetRasterBand(1)->GetRasterDataType()) / 8;    //圖像深度

    //申請buf
    size_t imgBufNum = (size_t)imgWidth * imgHeight * bandNum * depth;
    size_t imgBufOffset = (size_t)imgWidth * (imgHeight - 1) * bandNum * depth;
    imgBuf = new GByte[imgBufNum];
    //讀取
    img->RasterIO(GF_Read, 0, 0, imgWidth, imgHeight, imgBuf + imgBufOffset, imgWidth, imgHeight,
        GDT_Byte, bandNum, nullptr, bandNum * depth, -imgWidth * bandNum * depth, depth);

    GDALClose(img);
}

void InitGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glShadeModel(GL_SMOOTH);      //平滑著色
    glEnable(GL_DEPTH_TEST);      //深度測試
    glEnable(GL_CULL_FACE);    //只渲染某一面
    glFrontFace(GL_CCW);    //逆時針正面

    glEnable(GL_TEXTURE_2D);    //啟用2D紋理映射

    //載入紋理圖像：
    ReadImage();

    //生成紋理對象：
    glGenTextures(1, &texture);
}*/
/*void setPoker() {
    glBindTexture(GL_TEXTURE_2D, texture);    //綁定紋理：

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); //支持4字節對齊

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);      //S方向上貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);      //T方向上貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);      //放大紋理過濾方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);      //縮小紋理過濾方式

    glTexImage2D(GL_TEXTURE_2D, 0, 3, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imgBuf);  //載入紋理：

    glMatrixMode(GL_MODELVIEW);                        // 選擇模型觀察矩陣
    glLoadIdentity();                                  // 重置模型觀察矩陣
    glMatrixMode(GL_PROJECTION);                        // 選擇投影矩陣
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);    //啟用2D紋理映射
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}*/
void draw_circle(float R) {
    glBegin(GL_POLYGON);
    int n = 720;
    for (int i = 0; i < n; i++)
        glVertex3f(R * cos(2 * PI / n * i), R * sin(2 * PI / n * i), 0.01f);//計算坐標
    glEnd();
    glFlush();//強制刷新緩衝，保證命令被執行
}
void flower_1() {
    glPushMatrix();
        glScalef(0.5, 0.5, 0.5);
        glColor3f(0.0, 0.0, 0.0);
        glPushMatrix();
            glTranslatef(0.4, 0.0, 0.0);
            draw_circle(0.5);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0, 0.5, 0.01);
            draw_circle(0.5);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.4, 0.0, 0.02);
            draw_circle(0.5);
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_TRIANGLES);
              glVertex3f(0.0, -0.2, 0.03);
              glVertex3f(0.2, -0.8, 0.03);
              glVertex3f(-0.2, -0.8, 0.03);
            glEnd();
        glPopMatrix();
    glPopMatrix();
}
void flower_2() {
    glPushMatrix();
        glScalef(0.6, 0.6, 0.6);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
          glVertex3f(0.4, 0.0, 0.0);
          glVertex3f(0.0, 0.8, 0.0);
          glVertex3f(-0.4, 0.0, 0.0);
          glVertex3f(0.0, -0.8, 0.0);
        glEnd();
    glPopMatrix();
}
void flower_3() {
    glPushMatrix();
        glScalef(0.5, 0.5, 0.5);
        glColor3f(1.0, 0.0, 0.0);
        glPushMatrix();
            glTranslatef(0.4, 0.0, 0.0);
            draw_circle(0.5);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.4, 0.0, 0.0);
            draw_circle(0.5);
        glPopMatrix();
        glPushMatrix();
            glBegin(GL_POLYGON);
              glVertex3f(0.9, 0.0, 0.0);
              glVertex3f(0.7, -0.42, 0.0);
              glVertex3f(0.0, -1.0, 0.0);
              glVertex3f(-0.7, -0.42, 0.0);
              glVertex3f(-0.9, 0.0, 0.0);
            glEnd();
        glPopMatrix();
    glPopMatrix();
}
void flower_4() {
    glPushMatrix();
      glScalef(0.5, 0.5, 0.5);
      glColor3f(0.0, 0.0, 0.0);
      glPushMatrix();
        glRotatef(180.0, 0.0, 0.0, 1.0);
        glPushMatrix();
          glTranslatef(0.4, 0.0, 0.0);
          draw_circle(0.5);
        glPopMatrix();
        glPushMatrix();
          glTranslatef(-0.4, 0.0, 0.0);
          draw_circle(0.5);
        glPopMatrix();
        glPushMatrix();
          glBegin(GL_POLYGON);
          glVertex3f(0.9, 0.0, 0.0);
          glVertex3f(0.7, -0.42, 0.0);
          glVertex3f(0.0, -1.0, 0.0);
          glVertex3f(-0.7, -0.42, 0.0);
          glVertex3f(-0.9, 0.0, 0.0);
          glEnd();
        glPopMatrix();
        glPushMatrix();
          glBegin(GL_POLYGON);
          glVertex3f(0.0, 0.2, 0.0);
          glVertex3f(0.2, 0.6, 0.0);
          glVertex3f(-0.2, 0.6, 0.0);
          glEnd();
        glPopMatrix();
      glPopMatrix();
    glPopMatrix();
}
void draw_flo(int flo) {
    switch (flo) {
    case 0:
        flower_1();
        break;
    case 1:
        flower_2();
        break;
    case 2:
        flower_3();
        break;
    case 3:
        flower_4();
        break;
    default:
        break;
    }

}
void draw_1(int flo) {
    glPushMatrix();
        draw_flo(flo);
    glPopMatrix();
}
void draw_2(int flo) {
    glPushMatrix();
        glTranslatef(0.0, 1.8, 0.0);
        draw_flo(flo);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(0.0, -1.8, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
}
void draw_3(int flo) {
    glPushMatrix();
        glTranslatef(0.0, 1.8, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, -1.8, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
}
void draw_4(int flo) {
    glPushMatrix();
        glTranslatef(-1.0, 1.8, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.0, 1.8, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.0, -1.8, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(1.0, -1.8, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
}
void draw_5(int flo) {
    glPushMatrix();
        glTranslatef(-1.0, 1.8, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.0, 1.8, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.0, -1.8, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(1.0, -1.8, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
}
void draw_6(int flo) {
    glPushMatrix();
        glTranslatef(-1.0, 1.8, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.0, 1.8, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.0, 0.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.0, -1.8, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(1.0, -1.8, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
}
void draw_7(int flo) {
    glPushMatrix();
        glTranslatef(-1.2, 2.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.2, 2.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.2, 0.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.2, 0.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 0.5, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.2, -2.0, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(1.2, -2.0, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
}
void draw_8(int flo) {
    glPushMatrix();
        glTranslatef(-1.2, 2.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.2, 2.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.2, 0.7, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.2, 0.7, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.2, -0.7, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.2, -0.7, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.2, -2.0, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(1.2, -2.0, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
}
void set_card() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
      glVertex3f(2.0, 3.0, -0.01);
      glVertex3f(-2.0, 3.0, -0.01);
      glVertex3f(-2.0, -3.0, -0.01);
      glVertex3f(2.0, -3.0, -0.01);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
      glVertex3f(2.0, 3.0, -0.02);
      glVertex3f(-2.0, 3.0, -0.02);
      glVertex3f(-2.0, -3.0, -0.02);
      glVertex3f(2.0, -3.0, -0.02);
    glEnd();
}
void set_flower(int num) {
    glPushMatrix();
    switch (num / 4) {
    case 0:
        draw_1(num % 4);
        break;
    case 1:
        draw_2(num % 4);
        break;
    case 2:
        draw_3(num % 4);
        break;
    case 3:
        draw_4(num % 4);
        break;
    case 4:
        draw_5(num % 4);
        break;
    case 5:
        draw_6(num % 4);
        break;
    case 6:
        draw_7(num % 4);
        break;
    case 7:
        draw_8(num % 4);
        break;
    case 8:
        break;
    case 9:
        break;
    }
   
    glPopMatrix();
    /*switch (num / 4) {
    case 0:
        draw_1(num % 4);
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    }*/

}
void set_rand() {
    player_point = (rand() % 52);
    do {
        CP_point = (rand() % 52);
    } while (CP_point == player_point);
    printf("player:%d CP: %d\n", player_point, CP_point);
}
void display(void)
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(cam_x, cam_y, cam_z, cam_x, cam_y, cam_z - 100.0, 0.0, 1.0, 0.0);
    if (rand_start == 1) {
        set_rand();
        rand_start = 0;
    }
    /*glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 0.0); glVertex3f(0.0,0.0,0.0);
        glTexCoord2d(1.0, 0.0); glVertex3f(1.0,0.0,0.0);
        glTexCoord2d(1.0, 1.0); glVertex3f(1.0,1.0,0.0);
        glTexCoord2d(0.0, 1.0); glVertex3f(0.0,1.0,0.0);
        glEnd();
    glPopMatrix();*/
    glPushMatrix();
        //glRotatef(180.f, 0.0, 1.0, 0.0);
        set_card();
        set_flower(28);
    glPopMatrix();
    glPushMatrix();
        //glScalef(0.5, 0.5, 0.5);
        //flower_1();
    glPopMatrix();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //glPushMatrix();

    //glPopMatrix();
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

    //arrow
    //int i = 0;
    // for (int i = 0; i < 52; i++) {
         //poker_list[i] = glGenLists(1);
    // }
    
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

    default:
        break;
    }

}

void idle() {

    //glutPostRedisplay();
}
int main(int argc, char** argv)
{
    srand(time(NULL));
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
