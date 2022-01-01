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
float cam_x = 50.0, cam_y = -20.0, cam_z = 10.0;
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

#define FINAL_NOTYET 0
#define FINAL_GET 1
#define FINAL_SHOW 2

#define GUESS_BIG 1
#define GUESS_SMALL 2
#define GUESS_SAME 3

#define Gamble_S 1
#define Gamble_M 2
#define Gamble_L 3
#define WIN 0
#define LOSE 1
#define WIN_SAME 2

int rand_start = 1;
long long real_money = 1000;
long long player_money = 100;

int final_state = FINAL_NOTYET;
int final_start = 1;
int guess_mode = GUESS_BEFORE;
int guess = 0;
int gamble = 0;
//poker_point
int player_point = 0;
int CP_point = 0;
//result
int result = 0;
//poker_animation
float playercard_rotate = 180.0;
float CPcard_rotate = 180.0;

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
void draw_9(int flo) {
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
        glTranslatef(0.0, 1.2, 0.0);
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
void draw_10(int flo) {
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
        glTranslatef(0.0, 1.2, 0.0);
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
        glTranslatef(0.0, -1.2, 0.0);
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
void draw_11(int flo) {
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
        glTranslatef(0.0, 1.2, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
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
        glTranslatef(0.0, -1.2, 0.0);
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
void draw_12(int flo) {
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
        glTranslatef(0.0, 2.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 0.7, 0.0);
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
        glTranslatef(0.0, -0.7, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, -2.0, 0.0);
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
void draw_13(int flo) {
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
        glTranslatef(0.0, 2.2, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 1.0, 0.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
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
        glTranslatef(0.0, -1.0, 0.0);
        glRotatef(180.f, 0.0, 0.0, 1.0);
        draw_flo(flo);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, -2.2, 0.0);
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
        draw_9(num % 4);
        break;
    case 9:
        draw_10(num % 4);
        break;
    case 10:
        draw_11(num % 4);
        break;
    case 11:
        draw_12(num % 4);
        break;
    case 12:
        draw_13(num % 4);
        break;
    default:
        break;
    }
   
    glPopMatrix();

}
void set_rand() {
    player_point = (rand() % 52);
    do {
        CP_point = (rand() % 52);
    } while (CP_point == player_point);
    printf("player:%d CP: %d\n", player_point, CP_point);
}
void getmoney() {
    float tmp = player_money;
    if (result != LOSE) {
        printf("win\n");
        player_money *= 2;
        if (guess_mode == GUESS_BEFORE) {
            player_money *= 2;
        }
        if (result == WIN_SAME) {
            player_money *= 2;
        }
        player_money -= tmp;
    }
    else {
        if (gamble != Gamble_S) {
	        player_money = -1.f * tmp;
	    }
	    else {
	        player_money = 0;
	    }
    }
    
    
    printf("player money:%lld \n", player_money);
    real_money += player_money;
    printf("result money:%lld \n", real_money);
}
void getresult() {
    switch (guess) {
    case GUESS_BIG:
        if ((player_point / 4) > (CP_point / 4)) {
            result = WIN;
        }
        else {
            result = LOSE;
        }
        break;
    case GUESS_SAME:
        if ((player_point / 4) == (CP_point / 4)) {
            result = WIN_SAME;
        }
        else {
            result = LOSE;
        }
        break;
    case GUESS_SMALL:
        if ((player_point / 4) < (CP_point / 4)) {
            result = WIN;
        }
        else {
            result = LOSE;
        }
        break;
    }
    getmoney();
}
void reset_pokergame() {
    player_money = 100;
    player_point = 0;
    CP_point = 0;
    result = 0;
    guess_mode = GUESS_BEFORE;
    guess = 0;
    gamble = 0;
    final_state = FINAL_NOTYET;
    final_start = 1;
    playercard_rotate = 180.0;
    CPcard_rotate = 180.0;
    rand_start = 1;
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
        printf("Now is doen't show mode, now guessing then enter get double point, or using space to show what point you have now...\n");
    }
    glPushMatrix();
        glTranslatef(cam_x, cam_y, cam_z - 10.0);
        glPushMatrix();
            glRotatef(playercard_rotate, 0.0, 1.0, 0.0);
            set_card();
            set_flower(player_point);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-10.0, 10.0, -10.0);
            glRotatef(CPcard_rotate, 0.0, 1.0, 0.0);
            set_card();
            set_flower(CP_point);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
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
    case '4':
        guess = GUESS_SMALL;
        printf("guess small(1:1)\n");
        break;
    case '5':
        guess = GUESS_SAME;
        printf("guess same(1:2)\n");
        break;
    case '6':
        guess = GUESS_BIG;
        printf("guess big(1:1)\n");
        break;
    case '7':
        gamble = Gamble_S;
        player_money = 100;
        printf("gamble_s: free 100 point give\n");
        break;
    case '8':
        if (real_money >= 500) {
            gamble = Gamble_M;
            player_money = 500;
            printf("gamble_m: using 500 point to play\n");
        }
        else {
            printf("don't have 500\n");
        }
        break;
    case '9':
        if (real_money >= 1000) {
            gamble = Gamble_L;
            player_money = 1000;
            printf("gamble_m: using 1000 point to play\n");
        }
        else {
            printf("don't have 1000\n");
        }
        break;
    case ' ':
        if (guess_mode == GUESS_BEFORE) {
            guess_mode = GUESS_AFTER;
        }
        break;
    case 13:
        if (guess == 0) {
            printf("choose guessing big/same/small first!\n");
        }
        else if (gamble == 0) {
            printf("choose what gamle scheme first!\n");
        }
        else {
            if (final_state == FINAL_NOTYET) {
                final_state = FINAL_GET;
            }
            else if (final_state == FINAL_SHOW) {
                reset_pokergame();
                final_state = FINAL_NOTYET;
                glutPostRedisplay();
            }
        }
        break;
    default:
        break;
    }

}

void idle() {
    if (guess_mode == GUESS_AFTER) {
        if (playercard_rotate > 0.0) {
            playercard_rotate -= 10.0;
            glutPostRedisplay();
        }
    }
    if (final_state == FINAL_GET) {
        if (playercard_rotate > 0.0) {
            playercard_rotate -= 10.0;
            glutPostRedisplay();
        }
        else if (CPcard_rotate > 0.0) {
            CPcard_rotate -= 10.0;
            glutPostRedisplay();
        }
        else {
            if (final_start == 1) {
                getresult();
                final_start = 0;
                final_state = FINAL_SHOW;
            }
        }
    }
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
