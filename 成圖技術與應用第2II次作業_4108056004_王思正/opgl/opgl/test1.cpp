/***************************
4108056004 王思正 第IV次作業11/10
***************************/
#include <GL\glew.h>
#include <GL\glut.h>

#include <GL\freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifdef GL_VERSION_1_1
#define POINTER 1

#define DRAWARRAY 1

#define WIDTH 935
#define HEIGHT 311

int setupMethod = POINTER;
int derefMethod = DRAWARRAY;
int rotateMethod = 0;
//multi
int firsttime = 1;
float iconrotate = 0.0;
float r_r = 186.0 / 232.0;
float r_g = 17.0 / 232.0;
float r_b = 29.0 / 232.0;
float g = 121.0 / 276.0;
float b = 155.0 / 276.0;
static float year = 0.0;
static float day = 0.0;
static float sunday = 0.0;
//camera position
float cam_x = 0.0, cam_y = 0.0, cam_z = 20.0;
static GLfloat colors[] = { 0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                                r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                            r_r, r_g, r_b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                    r_r, r_g, r_b,
                                    r_r, r_g, r_b,
                                    r_r, r_g, r_b,
                                    r_r, r_g, r_b,
                                    r_r, r_g, r_b,
                                    r_r, r_g, r_b,
                                    r_r, r_g, r_b,
                                    r_r, r_g, r_b, };

float getv(int a) {
    return ((float)a / (float)WIDTH) - 0.5;
}
float getv_b(int b) {
    return (-((float)b - (float)HEIGHT) / (float)HEIGHT) - 0.5;
}

void setupPointers(void)
{
    static GLfloat vertices[] = { 0.022 - 0.5, 0.8 - 0.5, 0.0,
                        0.02 - 0.5,   0.78 - 0.5, 0.0,
                        0.114 - 0.5,   0.83 - 0.5, 0.0,
                        0.1137 - 0.5, 0.85 - 0.5, 0.0,
                        0.025 - 0.5, 0.8 - 0.5, 0.0,
                        0.1137 - 0.5, 0.85 - 0.5, 0.0,
                        0.096 - 0.5, 0.856 - 0.5, 0.0,
                        0.036 - 0.5, 0.815 - 0.5, 0.0,
                        0.02 - 0.5, 0.78 - 0.5, 0.0,
                        0.02 - 0.5, 0.765 - 0.5, 0.0,
                        0.07 - 0.5, 0.81 - 0.5, 0.0,
                        0.02 - 0.5, 0.8 - 0.5, 0.0,
                        0.02 - 0.5, 0.552 - 0.5, 0.0,
                        0.03 - 0.5, 0.56 - 0.5, 0.0,
                        0.035 - 0.5, 0.78 - 0.5, 0.0,
                        0.035 - 0.5, 0.78 - 0.5, 0.0,
                        0.032 - 0.5, 0.7 - 0.5, 0.0,
                        0.045 - 0.5, 0.725 - 0.5, 0.0,
                        0.045 - 0.5, 0.75 - 0.5, 0.0,
                        0.045 - 0.5, 0.75 - 0.5, 0.0,
                        0.045 - 0.5, 0.725 - 0.5, 0.0,
                        0.083 - 0.5, 0.77 - 0.5, 0.0,
                        0.083 - 0.5, 0.79 - 0.5, 0.0,
                        0.081 - 0.5, 0.82 - 0.5, 0.0,
                        0.083 - 0.5, 0.77 - 0.5, 0.0,
                        0.101 - 0.5, 0.77 - 0.5, 0.0,
                        0.092 - 0.5, 0.825 - 0.5, 0.0,
                        0.067 - 0.5, 0.81 - 0.5, 0.0,
                        0.069 - 0.5, 0.77 - 0.5, 0.0,
                        0.102 - 0.5, 0.605 - 0.5, 0.0,
                        0.10 - 0.5, 0.625 - 0.5, 0.0,
                        0.104 - 0.5, 0.648 - 0.5, 0.0,
                        0.095 - 0.5, 0.675 - 0.5, 0.0,
                        0.079 - 0.5, 0.775 - 0.5, 0.0,
                        0.078 - 0.5, 0.818 - 0.5, 0.0,
                        0.049 - 0.5, 0.737 - 0.5, 0.0,
                        0.032 - 0.5, 0.675 - 0.5, 0.0,
                        0.033 - 0.5, 0.658 - 0.5, 0.0,
                        0.041 - 0.5, 0.672 - 0.5, 0.0,
                        0.034 - 0.5, 0.645 - 0.5, 0.0,
                        0.035 - 0.5, 0.615 - 0.5, 0.0,
                        0.081 - 0.5, 0.668 - 0.5, 0.0,
                        0.083 - 0.5, 0.695 - 0.5, 0.0,
                        0.0668 - 0.5, 0.687 - 0.5, 0.0,
                        0.075 - 0.5, 0.725 - 0.5, 0.0,
                        0.072 - 0.5, 0.75 - 0.5, 0.0,
                        0.05 - 0.5, 0.702 - 0.5, 0.0,
                        0.065 - 0.5, 0.742 - 0.5, 0.0,
                        0.0915 - 0.5, 0.75 - 0.5, 0.0,
                        0.087 - 0.5, 0.74 - 0.5, 0.0,
                        0.0837 - 0.5, 0.68 - 0.5, 0.0,
                        0.079 - 0.5, 0.648 - 0.5, 0.0,
                        0.058 - 0.5, 0.6 - 0.5, 0.0,
                        0.0809 - 0.5, 0.6 - 0.5, 0.0,
                        0.0837 - 0.5, 0.625 - 0.5, 0.0,
                        0.0915 - 0.5, 0.65 - 0.5, 0.0,
                        0.1 - 0.5, 0.724 - 0.5, 0.0,
                        0.1 - 0.5, 0.6 - 0.5, 0.0,
                        0.058 - 0.5, 0.6 - 0.5, 0.0,
                        0.03 - 0.5, 0.59 - 0.5, 0.0,
                        0.03 - 0.5, 0.567 - 0.5, 0.0,
                        0.081 - 0.5, 0.575 - 0.5, 0.0,
                        0.1 - 0.5, 0.57 - 0.5, 0.0,
                        0.115 - 0.5, 0.585 - 0.5, 0.0,
                        0.107 - 0.5, 0.83 - 0.5, 0.0,
                        0.11 - 0.5, 0.562 - 0.5, 0.0,
                        0.1 - 0.5, 0.568 - 0.5, 0.0,
                        0.107 - 0.5, 0.52 - 0.5, 0.0,
                        0.112 - 0.5, 0.52 - 0.5, 0.0,
                        0.117 - 0.5, 0.55 - 0.5, 0.0,
                        0.114 - 0.5, 0.83 - 0.5, 0.0,
                        0.186 - 0.5, 0.83 - 0.5, 0.0,
                        0.183 - 0.5, 0.8 - 0.5, 0.0,
                        0.194 - 0.5, 0.77 - 0.5, 0.0,
                        0.208 - 0.5, 0.775 - 0.5, 0.0,
                        0.208 - 0.5, 0.8 - 0.5, 0.0,
                        0.186 - 0.5, 0.83 - 0.5, 0.0,
                        0.183 - 0.5, 0.8 - 0.5, 0.0,
                        0.194 - 0.5, 0.77 - 0.5, 0.0,
                        0.208 - 0.5, 0.775 - 0.5, 0.0,
                        0.208 - 0.5, 0.8 - 0.5, 0.0,
                        0.16 - 0.5, 0.74 - 0.5, 0.0,
                        0.158 - 0.5, 0.71 - 0.5, 0.0,
                        0.166 - 0.5, 0.7 - 0.5, 0.0,
                        0.195 - 0.5, 0.738 - 0.5, 0.0,
                        0.21 - 0.5, 0.745 - 0.5, 0.0,
                        0.225 - 0.5, 0.75 - 0.5, 0.0,
                        0.225 - 0.5, 0.774 - 0.5, 0.0,
                        0.216 - 0.5, 0.78 - 0.5, 0.0,
                        0.208 - 0.5, 0.775 - 0.5, 0.0,
                        0.194 - 0.5, 0.77 - 0.5, 0.0,
                        0.172 - 0.5, 0.745 - 0.5, 0.0,
                        0.172 - 0.5, 0.75 - 0.5, 0.0,
                        0.195 - 0.5, 0.738 - 0.5, 0.0,
                        0.173 - 0.5, 0.68 - 0.5, 0.0,
                        0.177 - 0.5, 0.65 - 0.5, 0.0,
                        0.195 - 0.5, 0.7 - 0.5, 0.0,
                        0.21 - 0.5, 0.745 - 0.5, 0.0,
                        0.195 - 0.5, 0.7 - 0.5, 0.0,
                        0.177 - 0.5, 0.65 - 0.5, 0.0,
                        0.215 - 0.5, 0.705 - 0.5, 0.0,
                        0.2255 - 0.5, 0.7 - 0.5, 0.0,
                        0.225 - 0.5, 0.72 - 0.5, 0.0,
                        0.219 - 0.5, 0.727 - 0.5, 0.0,
                        0.2255 - 0.5, 0.7 - 0.5, 0.0,
                        0.215 - 0.5, 0.65 - 0.5, 0.0,
                        0.205 - 0.5, 0.605 - 0.5, 0.0,
                        0.195 - 0.5, 0.6 - 0.5, 0.0,
                        0.207 - 0.5, 0.653 - 0.5, 0.0,
                        0.215 - 0.5, 0.705 - 0.5, 0.0,
                        0.195 - 0.5, 0.6 - 0.5, 0.0,
                        0.156 - 0.5, 0.595 - 0.5, 0.0,
                        0.16 - 0.5, 0.575 - 0.5, 0.0,
                        0.172 - 0.5, 0.565 - 0.5, 0.0,
                        0.219 - 0.5, 0.588 - 0.5, 0.0,
                        0.2415 - 0.5, 0.585 - 0.5, 0.0,
                        0.241 - 0.5, 0.605 - 0.5, 0.0,
                        0.233 - 0.5, 0.61 - 0.5, 0.0,
                        0.205 - 0.5, 0.605 - 0.5, 0.0,
                        0.267 - 0.5, 0.79 - 0.5, 0.0,
                        0.26 - 0.5, 0.75 - 0.5, 0.0,
                        0.275 - 0.5, 0.67 - 0.5, 0.0,
                        0.284 - 0.5, 0.67 - 0.5, 0.0,
                        0.277 - 0.5, 0.75 - 0.5, 0.0,
                        0.275 - 0.5, 0.77 - 0.5, 0.0,
                        0.273 - 0.5, 0.78 - 0.5, 0.0,
                        0.275 - 0.5, 0.77 - 0.5, 0.0,
                        0.287 - 0.5, 0.75 - 0.5, 0.0,
                        0.32 - 0.5, 0.79 - 0.5, 0.0,
                        0.329 - 0.5, 0.79 - 0.5, 0.0,
                        0.339 - 0.5, 0.79 - 0.5, 0.0,
                        0.353 - 0.5, 0.785 - 0.5, 0.0,
                        0.353 - 0.5, 0.8 - 0.5, 0.0,
                        0.349 - 0.5, 0.815 - 0.5, 0.0,
                        0.327 - 0.5, 0.81 - 0.5, 0.0,
                        0.317 - 0.5, 0.808 - 0.5, 0.0,
                        0.284 - 0.5, 0.79 - 0.5, 0.0,
                        0.273 - 0.5, 0.78 - 0.5, 0.0,
                        0.353 - 0.5, 0.785 - 0.5, 0.0,
                        0.327 - 0.5, 0.723 - 0.5, 0.0,
                        0.295 - 0.5, 0.675 - 0.5, 0.0,
                        0.3 - 0.5, 0.7 - 0.5, 0.0,
                        0.317 - 0.5, 0.73 - 0.5, 0.0,
                        0.327 - 0.5, 0.75 - 0.5, 0.0,
                        0.339 - 0.5, 0.79 - 0.5, 0.0,
                        0.317 - 0.5, 0.808 - 0.5, 0.0,
                        0.317 - 0.5, 0.845 - 0.5, 0.0,
                        0.322 - 0.5, 0.85 - 0.5, 0.0,
                        0.327 - 0.5, 0.845 - 0.5, 0.0,
                        0.327 - 0.5, 0.81 - 0.5, 0.0,
                        0.327 - 0.5, 0.75 - 0.5, 0.0,
                        0.327 - 0.5, 0.723 - 0.5, 0.0,
                        0.327 - 0.5, 0.44 - 0.5, 0.0,
                        0.317 - 0.5, 0.425 - 0.5, 0.0,
                        0.317 - 0.5, 0.73 - 0.5, 0.0,
                        0.32 - 0.5, 0.79 - 0.5, 0.0,
                        0.327 - 0.5, 0.723 - 0.5, 0.0,
                        0.339 - 0.5, 0.72 - 0.5, 0.0,
                        0.336 - 0.5, 0.695 - 0.5, 0.0,
                        0.295 - 0.5, 0.675 - 0.5, 0.0,
                        0.3 - 0.5, 0.7 - 0.5, 0.0,
                        0.394 - 0.5, 0.808 - 0.5, 0.0,
                        0.4 - 0.5, 0.8 - 0.5, 0.0,
                        0.4 - 0.5, 0.675 - 0.5, 0.0,
                        0.406 - 0.5, 0.678 - 0.5, 0.0,
                        0.406 - 0.5, 0.8 - 0.5, 0.0,
                        0.4 - 0.5, 0.823 - 0.5, 0.0,
                        0.406 - 0.5, 0.825 - 0.5, 0.0,
                        0.411 - 0.5, 0.8 - 0.5, 0.0,
                        0.411 - 0.5, 0.675 - 0.5, 0.0,
                        0.417 - 0.5, 0.685 - 0.5, 0.0,
                        0.417 - 0.5, 0.8 - 0.5, 0.0,
                        0.417 - 0.5, 0.82 - 0.5, 0.0,
                        0.422 - 0.5, 0.825 - 0.5, 0.0,
                        0.422 - 0.5, 0.69 - 0.5, 0.0,
                        0.428 - 0.5, 0.7 - 0.5, 0.0,
                        0.428 - 0.5, 0.82 - 0.5, 0.0,
                        0.438 - 0.5, 0.825 - 0.5, 0.0,
                        0.45 - 0.5, 0.83 - 0.5, 0.0,
                        0.45 - 0.5, 0.845 - 0.5, 0.0,
                        0.444 - 0.5, 0.85 - 0.5, 0.0,
                        0.45 - 0.5, 0.83 - 0.5, 0.0,
                        0.449 - 0.5, 0.805 - 0.5, 0.0,
                        0.448 - 0.5, 0.795 - 0.5, 0.0,
                        0.446 - 0.5, 0.77 - 0.5, 0.0,
                        0.445 - 0.5, 0.705 - 0.5, 0.0,
                        0.428 - 0.5, 0.7 - 0.5, 0.0,
                        0.428 - 0.5, 0.8 - 0.5, 0.0,
                        0.438 - 0.5, 0.8 - 0.5, 0.0,
                        0.438 - 0.5, 0.825 - 0.5, 0.0,
                        0.45 - 0.5, 0.83 - 0.5, 0.0,
                        0.449 - 0.5, 0.805 - 0.5, 0.0,
                        0.46 - 0.5, 0.803 - 0.5, 0.0,
                        0.457 - 0.5, 0.708 - 0.5, 0.0,
                        0.462 - 0.5, 0.71 - 0.5, 0.0,
                        0.467 - 0.5, 0.75 - 0.5, 0.0,
                        0.463 - 0.5, 0.76 - 0.5, 0.0,
                        0.469 - 0.5, 0.82 - 0.5, 0.0,
                        0.471 - 0.5, 0.85 - 0.5, 0.0,
                        0.36 - 0.5, 0.65 - 0.5, 0.0,
                        0.358 - 0.5, 0.62 - 0.5, 0.0,
                        0.365 - 0.5, 0.6 - 0.5, 0.0,
                        0.402 - 0.5, 0.6503 - 0.5, 0.0,
                        0.443 - 0.5, 0.68 - 0.5, 0.0,
                        0.492 - 0.5, 0.695 - 0.5, 0.0,
                        0.494 - 0.5, 0.715 - 0.5, 0.0,
                        0.487 - 0.5, 0.72 - 0.5, 0.0,
                        0.48 - 0.5, 0.715 - 0.5, 0.0,
                        0.462 - 0.5, 0.71 - 0.5, 0.0,
                        0.457 - 0.5, 0.708 - 0.5, 0.0,
                        0.445 - 0.5, 0.705 - 0.5, 0.0,
                        0.428 - 0.5, 0.7 - 0.5, 0.0,
                        0.422 - 0.5, 0.69 - 0.5, 0.0,
                        0.417 - 0.5, 0.685 - 0.5, 0.0,
                        0.411 - 0.5, 0.675 - 0.5, 0.0,
                        0.406 - 0.5, 0.678 - 0.5, 0.0,
                        0.4 - 0.5, 0.675 - 0.5, 0.0,
                        0.383 - 0.5, 0.61 - 0.5, 0.0,
                        0.391 - 0.5, 0.6 - 0.5, 0.0,
                        0.443 - 0.5, 0.64 - 0.5, 0.0,
                        0.393 - 0.5, 0.56 - 0.5, 0.0,
                        0.461 - 0.5, 0.65 - 0.5, 0.0,
                        0.483 - 0.5, 0.5 - 0.5, 0.0,
                        0.486 - 0.5, 0.57 - 0.5, 0.0,
                        0.487 - 0.5, 0.6 - 0.5, 0.0,
                        0.461 - 0.5, 0.65 - 0.5, 0.0,
                        0.483 - 0.5, 0.5 - 0.5, 0.0,
                        0.486 - 0.5, 0.57 - 0.5, 0.0,
                        0.487 - 0.5, 0.6 - 0.5, 0.0,
                        0.519 - 0.5, 0.71 - 0.5, 0.0,
                        0.522 - 0.5, 0.69 - 0.5, 0.0,
                        0.525 - 0.5, 0.677 - 0.5, 0.0,
                        0.534 - 0.5, 0.68 - 0.5, 0.0,
                        0.544 - 0.5, 0.7 - 0.5, 0.0,
                        0.557 - 0.5, 0.725 - 0.5, 0.0,
                        0.57 - 0.5, 0.73 - 0.5, 0.0,
                        0.588 - 0.5, 0.74 - 0.5, 0.0,
                        0.592 - 0.5, 0.765 - 0.5, 0.0,
                        0.574 - 0.5, 0.765 - 0.5, 0.0,
                        0.562 - 0.5, 0.755 - 0.5, 0.0,
                        0.562 - 0.5, 0.755 - 0.5, 0.0,
                        0.57 - 0.5, 0.83 - 0.5, 0.0,
                        0.574 - 0.5, 0.845 - 0.5, 0.0,
                        0.574 - 0.5, 0.765 - 0.5, 0.0,
                        0.57 - 0.5, 0.73 - 0.5, 0.0,
                        0.562 - 0.5, 0.67 - 0.5, 0.0,
                        0.555 - 0.5, 0.625 - 0.5, 0.0,
                        0.533 - 0.5, 0.605 - 0.5, 0.0,
                        0.549 - 0.5, 0.655 - 0.5, 0.0,
                        0.557 - 0.5, 0.725 - 0.5, 0.0,
                        0.574 - 0.5, 0.675 - 0.5, 0.0,
                        0.593 - 0.5, 0.63 - 0.5, 0.0,
                        0.608 - 0.5, 0.625 - 0.5, 0.0,
                        0.602 - 0.5, 0.65 - 0.5, 0.0,
                        0.608 - 0.5, 0.625 - 0.5, 0.0,
                        0.593 - 0.5, 0.63 - 0.5, 0.0,
                        0.574 - 0.5, 0.6 - 0.5, 0.0,
                        0.592 - 0.5, 0.6 - 0.5, 0.0,
                        0.602 - 0.5, 0.595 - 0.5, 0.0,
                        0.641 - 0.5, 0.84 - 0.5, 0.0,
                        0.646 - 0.5, 0.825 - 0.5, 0.0,
                        0.654 - 0.5, 0.855 - 0.5, 0.0,
                        0.659 - 0.5, 0.842 - 0.5, 0.0,
                        0.653 - 0.5, 0.82 - 0.5, 0.0,
                        0.659 - 0.5, 0.818 - 0.5, 0.0,
                        0.658 - 0.5, 0.79 - 0.5, 0.0,
                        0.653 - 0.5, 0.76 - 0.5, 0.0,
                        0.653 - 0.5, 0.7 - 0.5, 0.0,
                        0.641 - 0.5, 0.7 - 0.5, 0.0,
                        0.638 - 0.5, 0.8 - 0.5, 0.0,
                        0.653 - 0.5, 0.76 - 0.5, 0.0,
                        0.652 - 0.5, 0.83 - 0.5, 0.0,
                        0.675 - 0.5, 0.8 - 0.5, 0.0,
                        0.67 - 0.5, 0.825 - 0.5, 0.0,
                        0.683 - 0.5, 0.84 - 0.5, 0.0,
                        0.675 - 0.5, 0.855 - 0.5, 0.0,
                        0.6675 - 0.5, 0.82 - 0.5, 0.0,
                        0.667 - 0.5, 0.794 - 0.5, 0.0,
                        0.667 - 0.5, 0.794 - 0.5, 0.0,
                        0.661 - 0.5, 0.8 - 0.5, 0.0,
                        0.661 - 0.5, 0.819 - 0.5, 0.0,
                        0.6675 - 0.5, 0.82 - 0.5, 0.0,
                        0.679 - 0.5, 0.825 - 0.5, 0.0,
                        0.684 - 0.5, 0.825 - 0.5, 0.0,
                        0.683 - 0.5, 0.8 - 0.5, 0.0,
                        0.675 - 0.5, 0.8 - 0.5, 0.0,
                        0.662 - 0.5, 0.755 - 0.5, 0.0,
                        0.667 - 0.5, 0.725 - 0.5, 0.0,
                        0.678 - 0.5, 0.73 - 0.5, 0.0,
                        0.677 - 0.5, 0.75 - 0.5, 0.0,
                        0.668 - 0.5, 0.76 - 0.5, 0.0,
                        0.668 - 0.5, 0.76 - 0.5, 0.0,
                        0.677 - 0.5, 0.75 - 0.5, 0.0,
                        0.679 - 0.5, 0.78 - 0.5, 0.0,
                        0.675 - 0.5, 0.8 - 0.5, 0.0,
                        0.684 - 0.5, 0.83 - 0.5, 0.0,
                        0.686 - 0.5, 0.82 - 0.5, 0.0,
                        0.694 - 0.5, 0.81 - 0.5, 0.0,
                        0.704 - 0.5, 0.83 - 0.5, 0.0,
                        0.702 - 0.5, 0.85 - 0.5, 0.0,
                        0.704 - 0.5, 0.83 - 0.5, 0.0,
                        0.696 - 0.5, 0.808 - 0.5, 0.0,
                        0.683 - 0.5, 0.8 - 0.5, 0.0,
                        0.684 - 0.5, 0.775 - 0.5, 0.0,
                        0.683 - 0.5, 0.75 - 0.5, 0.0,
                        0.688 - 0.5, 0.74 - 0.5, 0.0,
                        0.698 - 0.5, 0.745 - 0.5, 0.0,
                        0.699 - 0.5, 0.8 - 0.5, 0.0,
                        0.6335 - 0.5, 0.695 - 0.5, 0.0,
                        0.618 - 0.5, 0.625 - 0.5, 0.0,
                        0.627 - 0.5, 0.6 - 0.5, 0.0,
                        0.641 - 0.5, 0.67 - 0.5, 0.0,
                        0.6335 - 0.5, 0.695 - 0.5, 0.0,
                        0.641 - 0.5, 0.67 - 0.5, 0.0,
                        0.711 - 0.5, 0.725 - 0.5, 0.0,
                        0.725 - 0.5, 0.725 - 0.5, 0.0,
                        0.714 - 0.5, 0.748 - 0.5, 0.0,
                        0.698 - 0.5, 0.745 - 0.5, 0.0,
                        0.688 - 0.5, 0.74 - 0.5, 0.0,
                        0.678 - 0.5, 0.73 - 0.5, 0.0,
                        0.667 - 0.5, 0.725 - 0.5, 0.0,
                        0.653 - 0.5, 0.7 - 0.5, 0.0,
                        0.641 - 0.5, 0.698 - 0.5, 0.0,
                        0.725 - 0.5, 0.725 - 0.5, 0.0,
                        0.711 - 0.5, 0.725 - 0.5, 0.0,
                        0.698 - 0.5, 0.695 - 0.5, 0.0,
                        0.722 - 0.5, 0.7 - 0.5, 0.0,
                        0.725 - 0.5, 0.713 - 0.5, 0.0,
                        0.667 - 0.5, 0.675 - 0.5, 0.0,
                        0.675 - 0.5, 0.66 - 0.5, 0.0,
                        0.685 - 0.5, 0.66 - 0.5, 0.0,
                        0.687 - 0.5, 0.68 - 0.5, 0.0,
                        0.684 - 0.5, 0.7 - 0.5, 0.0,
                        0.685 - 0.5, 0.66 - 0.5, 0.0,
                        0.675 - 0.5, 0.66 - 0.5, 0.0,
                        0.68 - 0.5, 0.645 - 0.5, 0.0,
                        0.682 - 0.5, 0.625 - 0.5, 0.0,
                        0.683 - 0.5, 0.58 - 0.5, 0.0,
                        0.678 - 0.5, 0.54 - 0.5, 0.0,
                        0.6875 - 0.5, 0.525 - 0.5, 0.0,
                        0.6875 - 0.5, 0.625 - 0.5, 0.0,
                        0.6875 - 0.5, 0.65 - 0.5, 0.0,
                        0.6875 - 0.5, 0.525 - 0.5, 0.0,
                        0.678 - 0.5, 0.54 - 0.5, 0.0,
                        0.652 - 0.5, 0.475 - 0.5, 0.0,
                        0.65 - 0.5, 0.44 - 0.5, 0.0,
                        0.667 - 0.5, 0.45 - 0.5, 0.0,
                        0.679 - 0.5, 0.5 - 0.5, 0.0,
                        0.6875 - 0.5, 0.65 - 0.5, 0.0,
                        0.68 - 0.5, 0.645 - 0.5, 0.0,
                        0.65 - 0.5, 0.615 - 0.5, 0.0,
                        0.64 - 0.5, 0.62 - 0.5, 0.0,
                        0.645 - 0.5, 0.6 - 0.5, 0.0,
                        0.682 - 0.5, 0.625 - 0.5, 0.0,
                        0.6875 - 0.5, 0.625 - 0.5, 0.0,
                        0.706 - 0.5, 0.6245 - 0.5, 0.0,
                        0.708 - 0.5, 0.64 - 0.5, 0.0,
                        0.7 - 0.5, 0.65 - 0.5, 0.0,
                        0.65 - 0.5, 0.44 - 0.5, 0.0,
                        0.652 - 0.5, 0.475 - 0.5, 0.0,
                        0.633 - 0.5, 0.458 - 0.5, 0.0,
                        0.617 - 0.5, 0.465 - 0.5, 0.0,
                        0.63 - 0.5, 0.445 - 0.5, 0.0,
                        getv(756), getv_b(28), 0.0,
                        getv(758), getv_b(36), 0.0,
                        getv(771), getv_b(42), 0.0,
                        getv(771), getv_b(33), 0.0,
                        getv(785), getv_b(46), 0.0,
                        getv(787), getv_b(36), 0.0,
                        getv(799), getv_b(55), 0.0,
                        getv(802), getv_b(37), 0.0,
                        getv(810), getv_b(63), 0.0,
                        getv(814), getv_b(38), 0.0,
                        getv(826), getv_b(62), 0.0,
                        getv(845), getv_b(36), 0.0,
                        getv(835), getv_b(66), 0.0,
                        getv(862), getv_b(34), 0.0,
                        getv(842), getv_b(71), 0.0,
                        getv(885), getv_b(28), 0.0,
                        getv(846), getv_b(77), 0.0,
                        getv(878), getv_b(46), 0.0,
                        getv(850), getv_b(84), 0.0,
                        getv(874), getv_b(66), 0.0,
                        getv(851), getv_b(93), 0.0,
                        getv(873), getv_b(80), 0.0,
                        getv(846), getv_b(108), 0.0,
                        getv(872), getv_b(95), 0.0,
                        getv(851), getv_b(121), 0.0,
                        getv(875), getv_b(111), 0.0,
                        getv(856), getv_b(135), 0.0,
                        getv(879), getv_b(129), 0.0,
                        getv(860), getv_b(150), 0.0,
                        getv(884), getv_b(143), 0.0,
                        getv(878), getv_b(157), 0.0,
                        getv(888), getv_b(152), 0.0,
                        getv(886), getv_b(161), 0.0,
                        getv(894), getv_b(164), 0.0,
                        getv(760), getv_b(44), 0.0,
                        getv(764), getv_b(60), 0.0,
                        getv(777), getv_b(51), 0.0,
                        getv(769), getv_b(47), 0.0,
                        getv(765), getv_b(71), 0.0,
                        getv(788), getv_b(57), 0.0,
                        getv(766), getv_b(82), 0.0,
                        getv(803), getv_b(67), 0.0,
                        getv(765), getv_b(90), 0.0,
                        getv(792), getv_b(80), 0.0,
                        getv(764), getv_b(102), 0.0,
                        getv(790), getv_b(94), 0.0,
                        getv(762), getv_b(115), 0.0,
                        getv(793), getv_b(105), 0.0,
                        getv(757), getv_b(134), 0.0,
                        getv(797), getv_b(113), 0.0,
                        getv(746), getv_b(161), 0.0,
                        getv(804), getv_b(119), 0.0,
                        getv(784), getv_b(148), 0.0,
                        getv(814), getv_b(122), 0.0,
                        getv(811), getv_b(144), 0.0,
                        getv(826), getv_b(122), 0.0,
                        getv(826), getv_b(144), 0.0,
                        getv(833), getv_b(119), 0.0,
                        getv(843), getv_b(145), 0.0,
                        getv(841), getv_b(114), 0.0,
                        getv(840), getv_b(145), 0.0,
                        getv(848), getv_b(129), 0.0,
                        getv(848), getv_b(147), 0.0,
                        getv(853), getv_b(139), 0.0,
                        getv(856), getv_b(149), 0.0,
                        getv(854), getv_b(143), 0.0,
                        getv(832), getv_b(78), 0.0,
                        getv(810), getv_b(63), 0.0,
                        getv(826), getv_b(62), 0.0,
                        getv(835), getv_b(66), 0.0,
                        getv(842), getv_b(71), 0.0,
                        getv(846), getv_b(77), 0.0,
                        getv(850), getv_b(84), 0.0,
                        getv(851), getv_b(93), 0.0,
                        getv(846), getv_b(108), 0.0,
                        getv(832), getv_b(78), 0.0,
                        getv(846), getv_b(108), 0.0,
                        getv(838), getv_b(96), 0.0,
                        getv(829), getv_b(84), 0.0,
                        getv(821), getv_b(74), 0.0,
                        getv(810), getv_b(63), 0.0,
                        getv(803), getv_b(67), 0.0,
                        getv(792), getv_b(80), 0.0,
                        getv(790), getv_b(94), 0.0,
                        getv(793), getv_b(105), 0.0,
                        getv(797), getv_b(113), 0.0,
                        getv(804), getv_b(119), 0.0,
                        getv(814), getv_b(122), 0.0,
                        getv(826), getv_b(122), 0.0,
                        getv(833), getv_b(119), 0.0,
                        getv(841), getv_b(114), 0.0,
                        getv(832), getv_b(99), 0.0,
                        getv(825), getv_b(89), 0.0,
                        getv(815), getv_b(78), 0.0,
                        getv(809), getv_b(72), 0.0,
                        getv(31), getv_b(276), 0.0,
                        getv(35), getv_b(276), 0.0,
                        getv(31), getv_b(238), 0.0,
                        getv(35), getv_b(238), 0.0,
                        getv(35), getv_b(238), 0.0,
                        getv(35), getv_b(246), 0.0,
                        getv(57), getv_b(268), 0.0,
                        getv(57), getv_b(276), 0.0,
                        getv(57), getv_b(276), 0.0,
                        getv(61), getv_b(276), 0.0,
                        getv(57), getv_b(238), 0.0,
                        getv(61), getv_b(238), 0.0,
                        getv(72), getv_b(255), 0.0,//a
                        getv(76), getv_b(257), 0.0,
                        getv(75), getv_b(250), 0.0,
                        getv(79), getv_b(253), 0.0,
                        getv(80), getv_b(248), 0.0,
                        getv(83), getv_b(252), 0.0,
                        getv(85), getv_b(247), 0.0,
                        getv(88), getv_b(253), 0.0,
                        getv(91), getv_b(249), 0.0,
                        getv(90), getv_b(254), 0.0,
                        getv(94), getv_b(252), 0.0,
                        getv(91), getv_b(258), 0.0,
                        getv(95), getv_b(257), 0.0,
                        getv(92), getv_b(276), 0.0,
                        getv(97), getv_b(276), 0.0,
                        getv(91), getv_b(258), 0.0,
                        getv(91), getv_b(262), 0.0,
                        getv(87), getv_b(259), 0.0,
                        getv(85), getv_b(264), 0.0,
                        getv(81), getv_b(260), 0.0,
                        getv(80), getv_b(264), 0.0,
                        getv(77), getv_b(262), 0.0,
                        getv(78), getv_b(266), 0.0,
                        getv(73), getv_b(264), 0.0,
                        getv(76), getv_b(268), 0.0,
                        getv(71), getv_b(269), 0.0,
                        getv(77), getv_b(271), 0.0,
                        getv(72), getv_b(273), 0.0,
                        getv(79), getv_b(273), 0.0,
                        getv(77), getv_b(276), 0.0,
                        getv(82), getv_b(273), 0.0,
                        getv(82), getv_b(277), 0.0,
                        getv(86), getv_b(272), 0.0,
                        getv(88), getv_b(275), 0.0,
                        getv(89), getv_b(271), 0.0,
                        getv(92), getv_b(271), 0.0,
                        getv(92), getv_b(267), 0.0,//
                        getv(105), getv_b(248), 0.0,//t
                        getv(105), getv_b(253), 0.0,
                        getv(117), getv_b(248), 0.0,
                        getv(117), getv_b(253), 0.0,
                        getv(108), getv_b(241), 0.0,
                        getv(112), getv_b(238), 0.0,
                        getv(108), getv_b(273), 0.0,
                        getv(112), getv_b(271), 0.0,
                        getv(111), getv_b(276), 0.0,
                        getv(117), getv_b(272), 0.0,
                        getv(117), getv_b(276), 0.0,//
                        getv(126), getv_b(242), 0.0,//i
                        getv(126), getv_b(238), 0.0,
                        getv(130), getv_b(242), 0.0,
                        getv(130), getv_b(238), 0.0,
                        getv(126), getv_b(276), 0.0,
                        getv(126), getv_b(248), 0.0,
                        getv(130), getv_b(276), 0.0,
                        getv(130), getv_b(248), 0.0,// 
                        getv(140), getv_b(261), 0.0,
                        getv(144), getv_b(259), 0.0,
                        getv(141), getv_b(254), 0.0,
                        getv(145), getv_b(256), 0.0,
                        getv(145), getv_b(250), 0.0,
                        getv(149), getv_b(253), 0.0,
                        getv(151), getv_b(247), 0.0,
                        getv(153), getv_b(252), 0.0,
                        getv(157), getv_b(248), 0.0,
                        getv(157), getv_b(253), 0.0,
                        getv(162), getv_b(250), 0.0,
                        getv(160), getv_b(256), 0.0,
                        getv(164), getv_b(255), 0.0,
                        getv(160), getv_b(260), 0.0,
                        getv(165), getv_b(260), 0.0,
                        getv(160), getv_b(265), 0.0,
                        getv(165), getv_b(267), 0.0,
                        getv(160), getv_b(268), 0.0,
                        getv(162), getv_b(273), 0.0,
                        getv(157), getv_b(272), 0.0,
                        getv(157), getv_b(276), 0.0,
                        getv(153), getv_b(273), 0.0,
                        getv(151), getv_b(277), 0.0,
                        getv(149), getv_b(272), 0.0,
                        getv(146), getv_b(275), 0.0,
                        getv(146), getv_b(270), 0.0,
                        getv(141), getv_b(270), 0.0,
                        getv(145), getv_b(266), 0.0,
                        getv(139), getv_b(266), 0.0,
                        getv(144), getv_b(263), 0.0,
                        getv(141), getv_b(254), 0.0,
                        getv(175), getv_b(248), 0.0,//n
                        getv(179), getv_b(248), 0.0,
                        getv(175), getv_b(276), 0.0,
                        getv(179), getv_b(276), 0.0,
                        getv(179), getv_b(256), 0.0,
                        getv(179), getv_b(251), 0.0,
                        getv(185), getv_b(253), 0.0,
                        getv(184), getv_b(248), 0.0,
                        getv(188), getv_b(253), 0.0,
                        getv(189), getv_b(247), 0.0,
                        getv(191), getv_b(253), 0.0,
                        getv(195), getv_b(249), 0.0,
                        getv(193), getv_b(256), 0.0,
                        getv(198), getv_b(256), 0.0,
                        getv(193), getv_b(276), 0.0,
                        getv(198), getv_b(276), 0.0, //
                        getv(72 + 136), getv_b(255), 0.0,//a+136
                        getv(76 + 136), getv_b(257), 0.0,
                        getv(75 + 136), getv_b(250), 0.0,
                        getv(79 + 136), getv_b(253), 0.0,
                        getv(80 + 136), getv_b(248), 0.0,
                        getv(83 + 136), getv_b(252), 0.0,
                        getv(85 + 136), getv_b(247), 0.0,
                        getv(88 + 136), getv_b(253), 0.0,
                        getv(91 + 136), getv_b(249), 0.0,
                        getv(90 + 136), getv_b(254), 0.0,
                        getv(94 + 136), getv_b(252), 0.0,
                        getv(91 + 136), getv_b(258), 0.0,
                        getv(95 + 136), getv_b(257), 0.0,
                        getv(92 + 136), getv_b(276), 0.0,
                        getv(97 + 136), getv_b(276), 0.0,
                        getv(91 + 136), getv_b(258), 0.0,
                        getv(91 + 136), getv_b(262), 0.0,
                        getv(87 + 136), getv_b(259), 0.0,
                        getv(85 + 136), getv_b(264), 0.0,
                        getv(81 + 136), getv_b(260), 0.0,
                        getv(80 + 136), getv_b(264), 0.0,
                        getv(77 + 136), getv_b(262), 0.0,
                        getv(78 + 136), getv_b(266), 0.0,
                        getv(73 + 136), getv_b(264), 0.0,
                        getv(76 + 136), getv_b(268), 0.0,
                        getv(71 + 136), getv_b(269), 0.0,
                        getv(77 + 136), getv_b(271), 0.0,
                        getv(72 + 136), getv_b(273), 0.0,
                        getv(79 + 136), getv_b(273), 0.0,
                        getv(77 + 136), getv_b(276), 0.0,
                        getv(82 + 136), getv_b(273), 0.0,
                        getv(82 + 136), getv_b(277), 0.0,
                        getv(86 + 136), getv_b(272), 0.0,
                        getv(88 + 136), getv_b(275), 0.0,
                        getv(89 + 136), getv_b(271), 0.0,
                        getv(92 + 136), getv_b(271), 0.0,
                        getv(92 + 136), getv_b(267), 0.0,// 
                        getv(242), getv_b(238), 0.0,
                        getv(247), getv_b(238), 0.0,
                        getv(242), getv_b(276), 0.0,
                        getv(247), getv_b(276), 0.0,
                        getv(298), getv_b(250), 0.0,
                        getv(304), getv_b(250), 0.0,
                        getv(298), getv_b(248), 0.0,
                        getv(302), getv_b(244), 0.0,
                        getv(297), getv_b(245), 0.0,
                        getv(298), getv_b(239), 0.0,
                        getv(294), getv_b(242), 0.0,
                        getv(294), getv_b(237), 0.0,
                        getv(292), getv_b(242), 0.0,
                        getv(291), getv_b(236), 0.0,
                        getv(288), getv_b(241), 0.0,
                        getv(285), getv_b(237), 0.0,
                        getv(285), getv_b(242), 0.0,
                        getv(281), getv_b(238), 0.0,
                        getv(282), getv_b(243), 0.0,
                        getv(275), getv_b(241), 0.0,
                        getv(278), getv_b(246), 0.0,
                        getv(271), getv_b(246), 0.0,
                        getv(276), getv_b(250), 0.0,
                        getv(269), getv_b(251), 0.0,
                        getv(275), getv_b(254), 0.0,
                        getv(269), getv_b(257), 0.0,
                        getv(275), getv_b(260), 0.0,
                        getv(270), getv_b(263), 0.0,
                        getv(276), getv_b(266), 0.0,
                        getv(272), getv_b(270), 0.0,
                        getv(279), getv_b(269), 0.0,
                        getv(278), getv_b(274), 0.0,
                        getv(283), getv_b(271), 0.0,
                        getv(283), getv_b(276), 0.0,
                        getv(288), getv_b(272), 0.0,
                        getv(290), getv_b(277), 0.0,
                        getv(292), getv_b(271), 0.0,
                        getv(296), getv_b(275), 0.0,
                        getv(296), getv_b(269), 0.0,
                        getv(302), getv_b(271), 0.0,
                        getv(298), getv_b(266), 0.0,
                        getv(304), getv_b(266), 0.0,
                        getv(299), getv_b(263), 0.0,
                        getv(304), getv_b(263), 0.0,
                        getv(175 + 138), getv_b(248), 0.0,//n+138
                        getv(179 + 138), getv_b(248), 0.0,
                        getv(175 + 138), getv_b(276), 0.0,
                        getv(179 + 138), getv_b(276), 0.0,
                        getv(179 + 138), getv_b(256), 0.0,
                        getv(179 + 138), getv_b(251), 0.0,
                        getv(185 + 138), getv_b(253), 0.0,
                        getv(184 + 138), getv_b(248), 0.0,
                        getv(188 + 138), getv_b(253), 0.0,
                        getv(189 + 138), getv_b(247), 0.0,
                        getv(191 + 138), getv_b(253), 0.0,
                        getv(195 + 138), getv_b(249), 0.0,
                        getv(193 + 138), getv_b(256), 0.0,
                        getv(198 + 138), getv_b(256), 0.0,
                        getv(193 + 138), getv_b(276), 0.0,
                        getv(198 + 138), getv_b(276), 0.0,//
                        getv(313), getv_b(238), 0.0,
                        getv(318), getv_b(238), 0.0,
                        getv(313), getv_b(276), 0.0,
                        getv(318), getv_b(276), 0.0,
                        getv(353), getv_b(247), 0.0,//u
                        getv(348), getv_b(247), 0.0,
                        getv(353), getv_b(270), 0.0,
                        getv(348), getv_b(270), 0.0,
                        getv(348), getv_b(270), 0.0,
                        getv(353), getv_b(270), 0.0,
                        getv(351), getv_b(275), 0.0,
                        getv(356), getv_b(272), 0.0,
                        getv(357), getv_b(276), 0.0,
                        getv(360), getv_b(272), 0.0,
                        getv(362), getv_b(275), 0.0,
                        getv(363), getv_b(271), 0.0,
                        getv(366), getv_b(272), 0.0,
                        getv(366), getv_b(269), 0.0,
                        getv(366), getv_b(247), 0.0,
                        getv(371), getv_b(247), 0.0,
                        getv(366), getv_b(276), 0.0,
                        getv(371), getv_b(276), 0.0,//
                        getv(175 + 207), getv_b(248), 0.0,//n382-175=+207
                        getv(179 + 207), getv_b(248), 0.0,
                        getv(175 + 207), getv_b(276), 0.0,
                        getv(179 + 207), getv_b(276), 0.0,
                        getv(179 + 207), getv_b(256), 0.0,
                        getv(179 + 207), getv_b(251), 0.0,
                        getv(185 + 207), getv_b(253), 0.0,
                        getv(184 + 207), getv_b(248), 0.0,
                        getv(188 + 207), getv_b(253), 0.0,
                        getv(189 + 207), getv_b(247), 0.0,
                        getv(191 + 207), getv_b(253), 0.0,
                        getv(195 + 207), getv_b(249), 0.0,
                        getv(193 + 207), getv_b(256), 0.0,
                        getv(198 + 207), getv_b(256), 0.0,
                        getv(193 + 207), getv_b(276), 0.0,
                        getv(198 + 207), getv_b(276), 0.0,//
                        getv(435), getv_b(257), 0.0,//g
                        getv(435), getv_b(252), 0.0,
                        getv(432), getv_b(254), 0.0,
                        getv(431), getv_b(249), 0.0,
                        getv(429), getv_b(252), 0.0,
                        getv(425), getv_b(247), 0.0,
                        getv(424), getv_b(252), 0.0,
                        getv(420), getv_b(249), 0.0,
                        getv(421), getv_b(254), 0.0,
                        getv(416), getv_b(254), 0.0,
                        getv(420), getv_b(258), 0.0,
                        getv(415), getv_b(262), 0.0,
                        getv(419), getv_b(266), 0.0,
                        getv(415), getv_b(269), 0.0,
                        getv(421), getv_b(270), 0.0,
                        getv(420), getv_b(274), 0.0,
                        getv(425), getv_b(272), 0.0,
                        getv(425), getv_b(276), 0.0,
                        getv(428), getv_b(272), 0.0,
                        getv(431), getv_b(275), 0.0,
                        getv(431), getv_b(270), 0.0,
                        getv(434), getv_b(272), 0.0,
                        getv(434), getv_b(267), 0.0,
                        getv(434), getv_b(248), 0.0,
                        getv(439), getv_b(248), 0.0,
                        getv(434), getv_b(279), 0.0,
                        getv(439), getv_b(279), 0.0,
                        getv(432), getv_b(281), 0.0,
                        getv(435), getv_b(285), 0.0,
                        getv(429), getv_b(284), 0.0,
                        getv(430), getv_b(288), 0.0,
                        getv(426), getv_b(285), 0.0,
                        getv(423), getv_b(288), 0.0,
                        getv(423), getv_b(283), 0.0,
                        getv(416), getv_b(284), 0.0,
                        getv(420), getv_b(279), 0.0,
                        getv(415), getv_b(279), 0.0,//
                        getv(463), getv_b(238), 0.0,
                        getv(468), getv_b(238), 0.0,
                        getv(463), getv_b(276), 0.0,
                        getv(468), getv_b(276), 0.0,
                        getv(489), getv_b(238), 0.0,
                        getv(494), getv_b(238), 0.0,
                        getv(489), getv_b(276), 0.0,
                        getv(494), getv_b(276), 0.0,
                        getv(468), getv_b(253), 0.0,
                        getv(489), getv_b(253), 0.0,
                        getv(468), getv_b(258), 0.0,
                        getv(489), getv_b(258), 0.0,
                        getv(526), getv_b(255), 0.0,//s
                        getv(521), getv_b(255), 0.0,
                        getv(525), getv_b(251), 0.0,
                        getv(520), getv_b(253), 0.0,
                        getv(521), getv_b(248), 0.0,
                        getv(518), getv_b(251), 0.0,
                        getv(516), getv_b(247), 0.0,
                        getv(513), getv_b(251), 0.0,
                        getv(510), getv_b(248), 0.0,
                        getv(510), getv_b(253), 0.0,
                        getv(506), getv_b(253), 0.0,
                        getv(509), getv_b(256), 0.0,
                        getv(505), getv_b(258), 0.0,
                        getv(511), getv_b(258), 0.0,
                        getv(509), getv_b(262), 0.0,
                        getv(514), getv_b(260), 0.0,
                        getv(514), getv_b(263), 0.0,
                        getv(519), getv_b(260), 0.0,
                        getv(519), getv_b(264), 0.0,
                        getv(523), getv_b(262), 0.0,
                        getv(522), getv_b(266), 0.0,
                        getv(528), getv_b(266), 0.0,
                        getv(523), getv_b(268), 0.0,
                        getv(527), getv_b(271), 0.0,
                        getv(522), getv_b(271), 0.0,
                        getv(523), getv_b(275), 0.0,
                        getv(519), getv_b(273), 0.0,
                        getv(517), getv_b(276), 0.0,
                        getv(513), getv_b(272), 0.0,
                        getv(509), getv_b(275), 0.0,
                        getv(510), getv_b(271), 0.0,
                        getv(505), getv_b(272), 0.0,
                        getv(508), getv_b(267), 0.0,
                        getv(505), getv_b(267), 0.0,//
                        getv(126 + 411), getv_b(242), 0.0,//i
                        getv(126 + 411), getv_b(238), 0.0,
                        getv(130 + 411), getv_b(242), 0.0,
                        getv(130 + 411), getv_b(238), 0.0,
                        getv(126 + 411), getv_b(276), 0.0,
                        getv(126 + 411), getv_b(248), 0.0,
                        getv(130 + 411), getv_b(276), 0.0,
                        getv(130 + 411), getv_b(248), 0.0,//
                        getv(175 + 377), getv_b(248), 0.0,//n+377
                        getv(179 + 377), getv_b(248), 0.0,
                        getv(175 + 377), getv_b(276), 0.0,
                        getv(179 + 377), getv_b(276), 0.0,
                        getv(179 + 377), getv_b(256), 0.0,
                        getv(179 + 377), getv_b(251), 0.0,
                        getv(185 + 377), getv_b(253), 0.0,
                        getv(184 + 377), getv_b(248), 0.0,
                        getv(188 + 377), getv_b(253), 0.0,
                        getv(189 + 377), getv_b(247), 0.0,
                        getv(191 + 377), getv_b(253), 0.0,
                        getv(195 + 377), getv_b(249), 0.0,
                        getv(193 + 377), getv_b(256), 0.0,
                        getv(198 + 377), getv_b(256), 0.0,
                        getv(193 + 377), getv_b(276), 0.0,
                        getv(198 + 377), getv_b(276), 0.0,//
                        getv(435 + 170), getv_b(257), 0.0,//g
                        getv(435 + 170), getv_b(252), 0.0,
                        getv(432 + 170), getv_b(254), 0.0,
                        getv(431 + 170), getv_b(249), 0.0,
                        getv(429 + 170), getv_b(252), 0.0,
                        getv(425 + 170), getv_b(247), 0.0,
                        getv(424 + 170), getv_b(252), 0.0,
                        getv(420 + 170), getv_b(249), 0.0,
                        getv(421 + 170), getv_b(254), 0.0,
                        getv(416 + 170), getv_b(254), 0.0,
                        getv(420 + 170), getv_b(258), 0.0,
                        getv(415 + 170), getv_b(262), 0.0,
                        getv(419 + 170), getv_b(266), 0.0,
                        getv(415 + 170), getv_b(269), 0.0,
                        getv(421 + 170), getv_b(270), 0.0,
                        getv(420 + 170), getv_b(274), 0.0,
                        getv(425 + 170), getv_b(272), 0.0,
                        getv(425 + 170), getv_b(276), 0.0,
                        getv(428 + 170), getv_b(272), 0.0,
                        getv(431 + 170), getv_b(275), 0.0,
                        getv(431 + 170), getv_b(270), 0.0,
                        getv(434 + 170), getv_b(272), 0.0,
                        getv(434 + 170), getv_b(267), 0.0,
                        getv(434 + 170), getv_b(248), 0.0,
                        getv(439 + 170), getv_b(248), 0.0,
                        getv(434 + 170), getv_b(279), 0.0,
                        getv(439 + 170), getv_b(279), 0.0,
                        getv(432 + 170), getv_b(281), 0.0,
                        getv(435 + 170), getv_b(285), 0.0,
                        getv(429 + 170), getv_b(284), 0.0,
                        getv(430 + 170), getv_b(288), 0.0,
                        getv(426 + 170), getv_b(285), 0.0,
                        getv(423 + 170), getv_b(288), 0.0,
                        getv(423 + 170), getv_b(283), 0.0,
                        getv(416 + 170), getv_b(284), 0.0,
                        getv(420 + 170), getv_b(279), 0.0,
                        getv(415 + 170), getv_b(279), 0.0,//
                        getv(633), getv_b(238), 0.0,//U
                        getv(638), getv_b(238), 0.0,
                        getv(633), getv_b(266), 0.0,
                        getv(638), getv_b(266), 0.0,
                        getv(637), getv_b(273), 0.0,
                        getv(641), getv_b(270), 0.0,
                        getv(643), getv_b(276), 0.0,
                        getv(647), getv_b(272), 0.0,
                        getv(651), getv_b(276), 0.0,
                        getv(654), getv_b(271), 0.0,
                        getv(659), getv_b(273), 0.0,
                        getv(659), getv_b(266), 0.0,
                        getv(664), getv_b(266), 0.0,
                        getv(659), getv_b(238), 0.0,
                        getv(664), getv_b(238), 0.0, //
                        getv(175 + 501), getv_b(248), 0.0,//n+501
                        getv(179 + 501), getv_b(248), 0.0,
                        getv(175 + 501), getv_b(276), 0.0,
                        getv(179 + 501), getv_b(276), 0.0,
                        getv(179 + 501), getv_b(256), 0.0,
                        getv(179 + 501), getv_b(251), 0.0,
                        getv(185 + 501), getv_b(253), 0.0,
                        getv(184 + 501), getv_b(248), 0.0,
                        getv(188 + 501), getv_b(253), 0.0,
                        getv(189 + 501), getv_b(247), 0.0,
                        getv(191 + 501), getv_b(253), 0.0,
                        getv(195 + 501), getv_b(249), 0.0,
                        getv(193 + 501), getv_b(256), 0.0,
                        getv(198 + 501), getv_b(256), 0.0,
                        getv(193 + 501), getv_b(276), 0.0,
                        getv(198 + 501), getv_b(276), 0.0,//
                        getv(126 + 584), getv_b(242), 0.0,//i+584
                        getv(126 + 584), getv_b(238), 0.0,
                        getv(130 + 584), getv_b(242), 0.0,
                        getv(130 + 584), getv_b(238), 0.0,
                        getv(126 + 584), getv_b(276), 0.0,
                        getv(126 + 584), getv_b(248), 0.0,
                        getv(130 + 584), getv_b(276), 0.0,
                        getv(130 + 584), getv_b(248), 0.0,//
                        getv(721), getv_b(248), 0.0,//v
                        getv(726), getv_b(248), 0.0,
                        getv(733), getv_b(276), 0.0,
                        getv(735), getv_b(270), 0.0,
                        getv(738), getv_b(276), 0.0,
                        getv(743), getv_b(248), 0.0,
                        getv(748), getv_b(248), 0.0,//
                        getv(760), getv_b(259), 0.0,//e
                        getv(760), getv_b(263), 0.0,
                        getv(777), getv_b(259), 0.0,
                        getv(781), getv_b(263), 0.0,
                        getv(776), getv_b(256), 0.0,
                        getv(779), getv_b(254), 0.0,
                        getv(774), getv_b(254), 0.0,
                        getv(774), getv_b(249), 0.0,
                        getv(769), getv_b(252), 0.0,
                        getv(768), getv_b(247), 0.0,
                        getv(765), getv_b(252), 0.0,
                        getv(762), getv_b(249), 0.0,
                        getv(761), getv_b(254), 0.0,
                        getv(757), getv_b(253), 0.0,
                        getv(760), getv_b(259), 0.0,
                        getv(754), getv_b(259), 0.0,
                        getv(760), getv_b(263), 0.0,
                        getv(754), getv_b(266), 0.0,
                        getv(761), getv_b(268), 0.0,
                        getv(759), getv_b(273), 0.0,
                        getv(763), getv_b(272), 0.0,
                        getv(764), getv_b(276), 0.0,
                        getv(768), getv_b(273), 0.0,
                        getv(772), getv_b(276), 0.0,
                        getv(774), getv_b(271), 0.0,
                        getv(780), getv_b(271), 0.0,
                        getv(776), getv_b(267), 0.0,
                        getv(781), getv_b(267), 0.0,//
                        getv(790), getv_b(248), 0.0,//r
                        getv(795), getv_b(248), 0.0,
                        getv(790), getv_b(276), 0.0,
                        getv(795), getv_b(276), 0.0,
                        getv(795), getv_b(257), 0.0,
                        getv(795), getv_b(251), 0.0,
                        getv(799), getv_b(252), 0.0,
                        getv(800), getv_b(247), 0.0,
                        getv(805), getv_b(254), 0.0,
                        getv(805), getv_b(249), 0.0,//
                        getv(526 + 306), getv_b(255), 0.0,//s
                        getv(521 + 306), getv_b(255), 0.0,
                        getv(525 + 306), getv_b(251), 0.0,
                        getv(520 + 306), getv_b(253), 0.0,
                        getv(521 + 306), getv_b(248), 0.0,
                        getv(518 + 306), getv_b(251), 0.0,
                        getv(516 + 306), getv_b(247), 0.0,
                        getv(513 + 306), getv_b(251), 0.0,
                        getv(510 + 306), getv_b(248), 0.0,
                        getv(510 + 306), getv_b(253), 0.0,
                        getv(506 + 306), getv_b(253), 0.0,
                        getv(509 + 306), getv_b(256), 0.0,
                        getv(505 + 306), getv_b(258), 0.0,
                        getv(511 + 306), getv_b(258), 0.0,
                        getv(509 + 306), getv_b(262), 0.0,
                        getv(514 + 306), getv_b(260), 0.0,
                        getv(514 + 306), getv_b(263), 0.0,
                        getv(519 + 306), getv_b(260), 0.0,
                        getv(519 + 306), getv_b(264), 0.0,
                        getv(523 + 306), getv_b(262), 0.0,
                        getv(522 + 306), getv_b(266), 0.0,
                        getv(528 + 306), getv_b(266), 0.0,
                        getv(523 + 306), getv_b(268), 0.0,
                        getv(527 + 306), getv_b(271), 0.0,
                        getv(522 + 306), getv_b(271), 0.0,
                        getv(523 + 306), getv_b(275), 0.0,
                        getv(519 + 306), getv_b(273), 0.0,
                        getv(517 + 306), getv_b(276), 0.0,
                        getv(513 + 306), getv_b(272), 0.0,
                        getv(509 + 306), getv_b(275), 0.0,
                        getv(510 + 306), getv_b(271), 0.0,
                        getv(505 + 306), getv_b(272), 0.0,
                        getv(508 + 306), getv_b(267), 0.0,
                        getv(505 + 306), getv_b(267), 0.0,//
                        getv(126 + 716), getv_b(242), 0.0,//i
                        getv(126 + 716), getv_b(238), 0.0,
                        getv(130 + 716), getv_b(242), 0.0,
                        getv(130 + 716), getv_b(238), 0.0,
                        getv(126 + 716), getv_b(276), 0.0,
                        getv(126 + 716), getv_b(248), 0.0,
                        getv(130 + 716), getv_b(276), 0.0,
                        getv(130 + 716), getv_b(248), 0.0,//
                        getv(105 + 753), getv_b(248), 0.0,//t
                        getv(105 + 753), getv_b(253), 0.0,
                        getv(117 + 753), getv_b(248), 0.0,
                        getv(117 + 753), getv_b(253), 0.0,
                        getv(108 + 753), getv_b(241), 0.0,
                        getv(112 + 753), getv_b(238), 0.0,
                        getv(108 + 753), getv_b(273), 0.0,
                        getv(112 + 753), getv_b(271), 0.0,
                        getv(111 + 753), getv_b(276), 0.0,
                        getv(117 + 753), getv_b(272), 0.0,
                        getv(117 + 753), getv_b(276), 0.0,//
                        getv(721 + 152), getv_b(248), 0.0,//v
                        getv(726 + 152), getv_b(248), 0.0,
                        getv(733 + 152), getv_b(276), 0.0,
                        getv(735 + 152), getv_b(270), 0.0,
                        getv(738 + 152), getv_b(276), 0.0,
                        getv(743 + 152), getv_b(248), 0.0,
                        getv(748 + 152), getv_b(248), 0.0,//
                        getv(889), getv_b(275), 0.0,
                        getv(884), getv_b(275), 0.0,
                        getv(888), getv_b(281), 0.0,
                        getv(882), getv_b(281), 0.0,
                        getv(883), getv_b(287), 0.0,
                        getv(876), getv_b(283), 0.0,
                        getv(876), getv_b(288), 0.0,
                        getv(769), getv_b(47), 0.0,
                        getv(786), getv_b(56), 0.0,
                        getv(765), getv_b(72), 0.0,
                        getv(764), getv_b(60), 0.0,
                        getv(760), getv_b(36), 0.0,
                        getv(784), getv_b(45), 0.0,
                        getv(787), getv_b(36), 0.0,
                        getv(771), getv_b(33), 0.0 };


    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
}
void drawPlanet()
{

    glPushMatrix();
    glTranslatef(0.3, 0.15, -0.625);
    glPushMatrix();
    glRotatef((GLfloat)sunday, 0.0, 1.0, 0.0);
    glRotated(90, 1.0, 0.0, 0.0);
    glutWireSphere(0.08, 20, 16);   // sun 
    glPopMatrix();
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
    glPushMatrix();
    glRotated(90, 1.0, 0.0, 0.0);
    glutWireSphere(0.02, 10, 8);    // planet 
    glPopMatrix();
    glPopMatrix();
}
void state_1() {
    //glClearColor(1.0, 1.0, 1.0, 0.0);
    //glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(0.38, 0.0, 0.0);
    //glRotatef(iconrotate, 0.0, 1.0, 0.0);
    glRotatef(iconrotate, 0.0, 1.0, 0.0);
    glTranslatef(-0.38, 0.0, 0.0);
    glDrawArrays(GL_QUAD_STRIP, 363, 34);
    glDrawArrays(GL_QUAD_STRIP, 397, 32);
    glDrawArrays(GL_TRIANGLE_FAN, 429, 9);
    glDrawArrays(GL_TRIANGLE_FAN, 438, 6);
    glDrawArrays(GL_POLYGON, 444, 14);
    glDrawArrays(GL_POLYGON, 1003, 4);
    glDrawArrays(GL_POLYGON, 1007, 4);
    glPopMatrix();
    glDrawArrays(GL_POLYGON, 0, 4);
    glDrawArrays(GL_POLYGON, 4, 4);
    glDrawArrays(GL_TRIANGLES, 8, 3);
    glDrawArrays(GL_POLYGON, 11, 4);
    glDrawArrays(GL_POLYGON, 15, 4);
    glDrawArrays(GL_POLYGON, 19, 4);
    glDrawArrays(GL_POLYGON, 23, 4);
    glDrawArrays(GL_POLYGON, 27, 8);
    glDrawArrays(GL_POLYGON, 35, 13);
    glDrawArrays(GL_POLYGON, 48, 9);
    glDrawArrays(GL_POLYGON, 57, 7);
    glDrawArrays(GL_POLYGON, 64, 7);
    glDrawArrays(GL_POLYGON, 71, 5);
    glDrawArrays(GL_POLYGON, 76, 5);
    glDrawArrays(GL_POLYGON, 81, 4);
    glDrawArrays(GL_POLYGON, 93, 5);
    glDrawArrays(GL_POLYGON, 98, 6);
    glDrawArrays(GL_POLYGON, 104, 6);
    glDrawArrays(GL_POLYGON, 110, 9);
    glDrawArrays(GL_POLYGON, 119, 7);
    glDrawArrays(GL_POLYGON, 126, 12);
    glDrawArrays(GL_POLYGON, 138, 7);
    glDrawArrays(GL_POLYGON, 145, 11);
    glDrawArrays(GL_POLYGON, 156, 5);
    glDrawArrays(GL_POLYGON, 161, 6);
    glDrawArrays(GL_POLYGON, 167, 6);
    glDrawArrays(GL_POLYGON, 173, 8);
    glDrawArrays(GL_POLYGON, 181, 9);
    glDrawArrays(GL_POLYGON, 190, 9);
    glDrawArrays(GL_POLYGON, 199, 18);
    glDrawArrays(GL_POLYGON, 217, 4);
    glDrawArrays(GL_POLYGON, 221, 4);
    glDrawArrays(GL_POLYGON, 225, 4);
    glDrawArrays(GL_POLYGON, 229, 11);
    glDrawArrays(GL_POLYGON, 240, 10);
    glDrawArrays(GL_POLYGON, 250, 4);
    glDrawArrays(GL_POLYGON, 254, 5);
    glDrawArrays(GL_POLYGON, 259, 11);
    glDrawArrays(GL_POLYGON, 270, 8);
    glDrawArrays(GL_POLYGON, 278, 8);
    glDrawArrays(GL_POLYGON, 286, 5);
    glDrawArrays(GL_POLYGON, 291, 4);
    glDrawArrays(GL_POLYGON, 295, 5);
    glDrawArrays(GL_POLYGON, 300, 8);
    glDrawArrays(GL_POLYGON, 308, 4);
    glDrawArrays(GL_POLYGON, 312, 11);
    glDrawArrays(GL_POLYGON, 323, 5);
    glDrawArrays(GL_POLYGON, 328, 5);
    glDrawArrays(GL_POLYGON, 333, 9);
    glDrawArrays(GL_POLYGON, 342, 6);
    glDrawArrays(GL_POLYGON, 348, 10);
    glDrawArrays(GL_POLYGON, 358, 5);

    glDrawArrays(GL_TRIANGLE_STRIP, 458, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 462, 8);
    glDrawArrays(GL_TRIANGLE_STRIP, 470, 15);
    glDrawArrays(GL_TRIANGLE_STRIP, 485, 22);
    glDrawArrays(GL_TRIANGLE_STRIP, 507, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 511, 7);
    glDrawArrays(GL_TRIANGLE_STRIP, 518, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 522, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 526, 31);
    glDrawArrays(GL_TRIANGLE_STRIP, 557, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 561, 12);
    glDrawArrays(GL_TRIANGLE_STRIP, 573, 15);
    glDrawArrays(GL_TRIANGLE_STRIP, 588, 22);
    glDrawArrays(GL_TRIANGLE_STRIP, 610, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 614, 40);
    glDrawArrays(GL_TRIANGLE_STRIP, 654, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 658, 12);
    glDrawArrays(GL_TRIANGLE_STRIP, 670, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 674, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 678, 10);
    glDrawArrays(GL_TRIANGLE_STRIP, 688, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 692, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 696, 12);
    glDrawArrays(GL_TRIANGLE_STRIP, 708, 23);
    glDrawArrays(GL_TRIANGLE_STRIP, 731, 14);
    glDrawArrays(GL_TRIANGLE_STRIP, 745, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 749, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 753, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 757, 34);
    glDrawArrays(GL_TRIANGLE_STRIP, 791, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 795, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 799, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 803, 12);
    glDrawArrays(GL_TRIANGLE_STRIP, 815, 23);
    glDrawArrays(GL_TRIANGLE_STRIP, 838, 14);
    glDrawArrays(GL_TRIANGLE_STRIP, 852, 15);
    glDrawArrays(GL_TRIANGLE_STRIP, 867, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 871, 12);
    glDrawArrays(GL_TRIANGLE_STRIP, 883, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 887, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 891, 7);
    glDrawArrays(GL_TRIANGLE_STRIP, 898, 28);
    glDrawArrays(GL_TRIANGLE_STRIP, 926, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 930, 6);
    glDrawArrays(GL_TRIANGLE_STRIP, 936, 34);
    glDrawArrays(GL_TRIANGLE_STRIP, 970, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 974, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 978, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 982, 7);
    glDrawArrays(GL_TRIANGLE_STRIP, 989, 7);
    glDrawArrays(GL_TRIANGLE_STRIP, 996, 7);

    //glDisableClientState(GL_VERTEX_ARRAY);
    //glDisableClientState(GL_COLOR_ARRAY);
}
void robot()
{
    glPushMatrix();
    glTranslatef(0.6, -0.4, -0.625);
    glRotatef(-30, 1.0, 0.0, 0.0);
    glScalef(0.2, 0.2, 0.75);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    //elbow
    glPushMatrix();
    glTranslatef(0.55, -0.3 - 0.2, -1.2);
    glRotatef(5, 1.0, 0.0, 0.0);
    glScalef(0.2, 0.2, 0.6);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    //hand
    glPushMatrix();
    glTranslatef(0.55, -0.35, -1.5);
    glRotatef(-30, 1.0, 0.0, 0.0);
    glScalef(0.2, 0.3, 0.1);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    //finger 0
    glPushMatrix();
    glTranslatef(0.6 + 0.25, -0.3, -1.35 - 0.55);
    glPushMatrix();
    glRotatef(40, 1.0, 0.0, 0.0);
    glScalef(0.5 / 5, 0.3 / 5, 0.3 / 5);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.09, 0.06, 0.0);
    glRotatef(40, 1.0, 0.0, 0.0);
    glRotatef(-20, 0.0, 0.0, 1.0);
    glScalef(0.3 / 5, 0.6 / 5, 0.3 / 5);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
    //finger 1
    glPushMatrix();
    glTranslatef(0.6 + 0.15, -0.2, -1.35 - 0.55);
    glPushMatrix();
    glRotatef(50, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.02, 0.13, -0.08);
    glRotatef(10, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
    //finger 2
    glPushMatrix();
    glTranslatef(0.6 + 0.08, -0.2, -1.35 - 0.55);
    glPushMatrix();
    glRotatef(80, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.02, 0.03, 0.0);
    glRotatef(120, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    //finger 3
    glPushMatrix();
    glTranslatef(0.6 + 0.01, -0.2, -1.35 - 0.55);
    glPushMatrix();
    glRotatef(80, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.02, 0.03, 0.0);
    glRotatef(120, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
    //finger 4
    glPushMatrix();
    glTranslatef(0.6 - 0.06, -0.2, -1.35 - 0.55);
    glPushMatrix();
    glRotatef(50, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.02, 0.13, -0.08);
    glRotatef(10, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
}
void display(void)
{
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_ALWAYS);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(cam_x, cam_y, cam_z, cam_x, cam_y, cam_z - 1.0, 0.0, 1.0, 0.0);
    setupMethod = POINTER;
    setupPointers();
    glPushMatrix();
        glScalef(20.0, 20.0, 1.0);
        state_1();
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
    glPopMatrix();
    glLoadIdentity();
    // start drawing
    glPushMatrix();
    //glTranslatef(camPosx, camPosy, camPosz);
        drawPlanet();
        robot();
    glPopMatrix();
    //printf("x:%f\ty:%f\t\z:%f\n",camPosx,camPosy,camPosz);
    //system("cls");

    glutSwapBuffers();
    glFlush();
    glDisable(GL_DEPTH_TEST);
}
void init(void)
{
    glewInit();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    setupPointers();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, 1.0, 0.01, 200.0);
    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //gluLookAt(camPosx, camPosy, camPosz, camPosx, camPosy, camPosz - 1.0, 0.0, 1.0, 0.0);
}
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(100.0, 1.0, 0.5, 220.0);
    gluPerspective(80.0, 1.0, 0.01, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glViewport(150, 150, WIDTH, HEIGHT);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();

    //glMatrixMode(GL_MODELVIEW);

    gluLookAt(cam_x, cam_y, cam_z, cam_x, cam_y, cam_z - 1.0, 0.0, 1.0, 0.0);
}

void mouse(int button, int state, int x, int y)
{
    switch (button) {
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
    }

}
void idle() {
    iconrotate += 0.5;

    if (iconrotate == 360.0) {
        iconrotate = 0.0;
    }
    r_r = ((float)(rand() % 256)) / 255;
    r_g = ((float)(rand() % 256)) / 255;
    r_b = ((float)(rand() % 256)) / 255;
    for (int i = (1426 - 1063) * 3; i <= (1492 - 1063) * 3; i += 3)
    {
        colors[i] = r_r;
        colors[i + 1] = r_g;
        colors[i + 2] = r_b;
    }
    for (int i = (1492 - 1063) * 3; i <= (1520 - 1063) * 3; i += 3)
    {
        colors[i] = r_r + 0.5;
        colors[i + 1] = r_g;
        colors[i + 2] = r_b;
    }
    for (int i = (2066 - 1063) * 3; i <= (2073 - 1063) * 3; i += 3)
    {
        colors[i] = r_r;
        colors[i + 1] = r_g;
        colors[i + 2] = r_b;
    }
    day = day + 0.1;
    year = year + 0.02;
    sunday = sunday + 0.005;
    if (day == 360.0) {
        day = 0.0;
    }
    if (year == 360.0) {
        year = 0.0;
    }
    if (sunday == 360.0) {
        sunday = 0.0;
    }
    //setupPointers();
    //gluLookAt(camPosx, camPosy, camPosz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //glLoadIdentity();
    //gluLookAt(camPosx, camPosy, camPosz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutPostRedisplay();
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
#else
int main(int argc, char** argv)
{
    fprintf(stderr, "This program demonstrates a feature which is not in OpenGL Version 1.0.\n");
    fprintf(stderr, "If your implementation of OpenGL Version 1.0 has the right extensions,\n");
    fprintf(stderr, "you may be able to modify this program to make it run.\n");
    return 0;
}
#endif

