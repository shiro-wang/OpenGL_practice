/***************************
4108056004 王思正 第三次作業10/27
***************************/
#include <GL\glew.h>
#include <GL\glut.h>

#include <GL\freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef GL_VERSION_1_1
#define POINTER 1
#define INTERLEAVED 2

#define DRAWARRAY 1
#define DRAWELEMENTS 2
#define MULTIDRAWARRAYS 3
#define MULTIDRAWELEMENTS 4

#define WIDTH 935
#define HEIGHT 311

#define MAX 120
#define ARRAYMAXSIZE 40
#define ROTATEX 1
#define ROTATEY 2
#define ROTATEZ 3
int setupMethod = POINTER;
int derefMethod = DRAWARRAY;
int rotateMethod = 0;

int array_1[ARRAYMAXSIZE] = { 0 };
int array_2[ARRAYMAXSIZE] = { 0 };
int array_3[ARRAYMAXSIZE] = { 0 };
int array_4[ARRAYMAXSIZE] = { 0 };
int array_5[ARRAYMAXSIZE] = { 0 };
int array_6[ARRAYMAXSIZE] = { 0 };
int array_7[ARRAYMAXSIZE] = { 0 };
int array_8[ARRAYMAXSIZE] = { 0 };
int array_9[ARRAYMAXSIZE] = { 0 };
int array_10[ARRAYMAXSIZE] = { 0 };
int array_11[ARRAYMAXSIZE] = { 0 };
int array_12[ARRAYMAXSIZE] = { 0 };
int array_13[ARRAYMAXSIZE] = { 0 };
int array_14[ARRAYMAXSIZE] = { 0 };
int array_15[ARRAYMAXSIZE] = { 0 };
int array_16[ARRAYMAXSIZE] = { 0 };
int array_17[ARRAYMAXSIZE] = { 0 };
int array_18[ARRAYMAXSIZE] = { 0 };
int array_19[ARRAYMAXSIZE] = { 0 };
int array_20[ARRAYMAXSIZE] = { 0 };
int array_21[ARRAYMAXSIZE] = { 0 };
int array_22[ARRAYMAXSIZE] = { 0 };
int array_23[ARRAYMAXSIZE] = { 0 };
int array_24[ARRAYMAXSIZE] = { 0 };
int array_25[ARRAYMAXSIZE] = { 0 };
int array_26[ARRAYMAXSIZE] = { 0 };
int array_27[ARRAYMAXSIZE] = { 0 };
int array_28[ARRAYMAXSIZE] = { 0 };
int array_29[ARRAYMAXSIZE] = { 0 };
int array_30[ARRAYMAXSIZE] = { 0 };
int array_31[ARRAYMAXSIZE] = { 0 };
int array_32[ARRAYMAXSIZE] = { 0 };
int array_33[ARRAYMAXSIZE] = { 0 };
int array_34[ARRAYMAXSIZE] = { 0 };
int array_35[ARRAYMAXSIZE] = { 0 };
int array_36[ARRAYMAXSIZE] = { 0 };
int array_37[ARRAYMAXSIZE] = { 0 };
int array_38[ARRAYMAXSIZE] = { 0 };
int array_39[ARRAYMAXSIZE] = { 0 };
int array_40[ARRAYMAXSIZE] = { 0 };
int array_41[ARRAYMAXSIZE] = { 0 };
int array_42[ARRAYMAXSIZE] = { 0 };
int array_43[ARRAYMAXSIZE] = { 0 };
int array_44[ARRAYMAXSIZE] = { 0 };
int array_45[ARRAYMAXSIZE] = { 0 };
int array_46[ARRAYMAXSIZE] = { 0 };
int array_47[ARRAYMAXSIZE] = { 0 };
int array_48[ARRAYMAXSIZE] = { 0 };
int array_49[ARRAYMAXSIZE] = { 0 };
int array_50[ARRAYMAXSIZE] = { 0 };
int array_51[ARRAYMAXSIZE] = { 0 };
int array_52[ARRAYMAXSIZE] = { 0 };
int array_53[ARRAYMAXSIZE] = { 0 };
int array_54[ARRAYMAXSIZE] = { 0 };
int array_55[ARRAYMAXSIZE] = { 0 };
int array_56[ARRAYMAXSIZE] = { 0 };
int array_57[ARRAYMAXSIZE] = { 0 };
int array_58[ARRAYMAXSIZE] = { 0 };
int array_59[ARRAYMAXSIZE] = { 0 };
int array_60[ARRAYMAXSIZE] = { 0 };
int array_61[ARRAYMAXSIZE] = { 0 };
int array_62[ARRAYMAXSIZE] = { 0 };
int array_63[ARRAYMAXSIZE] = { 0 };
int array_64[ARRAYMAXSIZE] = { 0 };
int array_65[ARRAYMAXSIZE] = { 0 };
int array_66[ARRAYMAXSIZE] = { 0 };
int array_67[ARRAYMAXSIZE] = { 0 };
int array_68[ARRAYMAXSIZE] = { 0 };
int array_69[ARRAYMAXSIZE] = { 0 };
int array_70[ARRAYMAXSIZE] = { 0 };
int array_71[ARRAYMAXSIZE] = { 0 };
int array_72[ARRAYMAXSIZE] = { 0 };
int array_73[ARRAYMAXSIZE] = { 0 };
int array_74[ARRAYMAXSIZE] = { 0 };
int array_75[ARRAYMAXSIZE] = { 0 };
int array_76[ARRAYMAXSIZE] = { 0 };
int array_77[ARRAYMAXSIZE] = { 0 };
int array_78[ARRAYMAXSIZE] = { 0 };
int array_79[ARRAYMAXSIZE] = { 0 };
int array_80[ARRAYMAXSIZE] = { 0 };
int array_81[ARRAYMAXSIZE] = { 0 };
int array_82[ARRAYMAXSIZE] = { 0 };
int array_83[ARRAYMAXSIZE] = { 0 };
int array_84[ARRAYMAXSIZE] = { 0 };
int array_85[ARRAYMAXSIZE] = { 0 };
int array_86[ARRAYMAXSIZE] = { 0 };
int array_87[ARRAYMAXSIZE] = { 0 };
int array_88[ARRAYMAXSIZE] = { 0 };
int array_89[ARRAYMAXSIZE] = { 0 };
int array_90[ARRAYMAXSIZE] = { 0 };
int array_91[ARRAYMAXSIZE] = { 0 };
int array_92[ARRAYMAXSIZE] = { 0 };
int array_93[ARRAYMAXSIZE] = { 0 };
int array_94[ARRAYMAXSIZE] = { 0 };
int array_95[ARRAYMAXSIZE] = { 0 };
int array_96[ARRAYMAXSIZE] = { 0 };
int array_97[ARRAYMAXSIZE] = { 0 };
int array_98[ARRAYMAXSIZE] = { 0 };
int array_99[ARRAYMAXSIZE] = { 0 };
int array_100[ARRAYMAXSIZE] = { 0 };
int array_101[ARRAYMAXSIZE] = { 0 };
int array_102[ARRAYMAXSIZE] = { 0 };
int array_103[ARRAYMAXSIZE] = { 0 };
int array_104[ARRAYMAXSIZE] = { 0 };
int array_105[ARRAYMAXSIZE] = { 0 };
int array_106[ARRAYMAXSIZE] = { 0 };
int array_107[ARRAYMAXSIZE] = { 0 };
int array_108[ARRAYMAXSIZE] = { 0 };
int array_109[ARRAYMAXSIZE] = { 0 };
int array_110[ARRAYMAXSIZE] = { 0 };

float getv(int a) {
    return ((float)a / (float)WIDTH )- 0.5;
}
float getv_b(int b) {
    return (-((float)b - (float)HEIGHT) / (float)HEIGHT) - 0.5;
}

//multi
int firsttime = 1;
void setupPointers(void)
{
    static GLfloat vertices[] = { 0.022 - 0.5, 0.8 - 0.5,
                        0.02 - 0.5,   0.78 - 0.5,
                        0.114 - 0.5,   0.83 - 0.5,
                        0.1137 - 0.5, 0.85 - 0.5,
                        0.025 - 0.5, 0.8 - 0.5,
                        0.1137 - 0.5, 0.85 - 0.5,
                        0.096 - 0.5, 0.856 - 0.5,
                        0.036 - 0.5, 0.815 - 0.5,
                        0.02 - 0.5, 0.78 - 0.5,
                        0.02 - 0.5, 0.765 - 0.5,
                        0.07 - 0.5, 0.81 - 0.5,
                        0.02 - 0.5, 0.8 - 0.5,
                        0.02 - 0.5, 0.552 - 0.5,
                        0.03 - 0.5, 0.56 - 0.5,
                        0.035 - 0.5, 0.78 - 0.5,
                        0.035 - 0.5, 0.78 - 0.5,
                        0.032 - 0.5, 0.7 - 0.5,
                        0.045 - 0.5, 0.725 - 0.5,
                        0.045 - 0.5, 0.75 - 0.5,
                        0.045 - 0.5, 0.75 - 0.5,
                        0.045 - 0.5, 0.725 - 0.5,
                        0.083 - 0.5, 0.77 - 0.5,
                        0.083 - 0.5, 0.79 - 0.5,
                        0.081 - 0.5, 0.82 - 0.5,
                        0.083 - 0.5, 0.77 - 0.5,
                        0.101 - 0.5, 0.77 - 0.5,
                        0.092 - 0.5, 0.825 - 0.5,
                        0.067 - 0.5, 0.81 - 0.5,
                        0.069 - 0.5, 0.77 - 0.5,
                        0.102 - 0.5, 0.605 - 0.5,
                        0.10 - 0.5, 0.625 - 0.5,
                        0.104 - 0.5, 0.648 - 0.5,
                        0.095 - 0.5, 0.675 - 0.5,
                        0.079 - 0.5, 0.775 - 0.5,
                        0.078 - 0.5, 0.818 - 0.5,
                        0.049 - 0.5, 0.737 - 0.5,
                        0.032 - 0.5, 0.675 - 0.5,
                        0.033 - 0.5, 0.658 - 0.5,
                        0.041 - 0.5, 0.672 - 0.5,
                        0.034 - 0.5, 0.645 - 0.5,
                        0.035 - 0.5, 0.615 - 0.5,
                        0.081 - 0.5, 0.668 - 0.5,
                        0.083 - 0.5, 0.695 - 0.5,
                        0.0668 - 0.5, 0.687 - 0.5,
                        0.075 - 0.5, 0.725 - 0.5,
                        0.072 - 0.5, 0.75 - 0.5,
                        0.05 - 0.5, 0.702 - 0.5,
                        0.065 - 0.5, 0.742 - 0.5,
                        0.0915 - 0.5, 0.75 - 0.5,
                        0.087 - 0.5, 0.74 - 0.5,
                        0.0837 - 0.5, 0.68 - 0.5,
                        0.079 - 0.5, 0.648 - 0.5,
                        0.058 - 0.5, 0.6 - 0.5,
                        0.0809 - 0.5, 0.6 - 0.5,
                        0.0837 - 0.5, 0.625 - 0.5,
                        0.0915 - 0.5, 0.65 - 0.5,
                        0.1 - 0.5, 0.724 - 0.5,
                        0.1 - 0.5, 0.6 - 0.5,
                        0.058 - 0.5, 0.6 - 0.5,
                        0.03 - 0.5, 0.59 - 0.5,
                        0.03 - 0.5, 0.567 - 0.5,
                        0.081 - 0.5, 0.575 - 0.5,
                        0.1 - 0.5, 0.57 - 0.5,
                        0.115 - 0.5, 0.585 - 0.5,
                        0.107 - 0.5, 0.83 - 0.5,
                        0.11 - 0.5, 0.562 - 0.5,
                        0.1 - 0.5, 0.568 - 0.5,
                        0.107 - 0.5, 0.52 - 0.5,
                        0.112 - 0.5, 0.52 - 0.5,
                        0.117 - 0.5, 0.55 - 0.5,
                        0.114 - 0.5, 0.83 - 0.5,
                        0.186 - 0.5, 0.83 - 0.5,
                        0.183 - 0.5, 0.8 - 0.5,
                        0.194 - 0.5, 0.77 - 0.5,
                        0.208 - 0.5, 0.775 - 0.5,
                        0.208 - 0.5, 0.8 - 0.5,
                        0.186 - 0.5, 0.83 - 0.5,
                        0.183 - 0.5, 0.8 - 0.5,
                        0.194 - 0.5, 0.77 - 0.5,
                        0.208 - 0.5, 0.775 - 0.5,
                        0.208 - 0.5, 0.8 - 0.5,
                        0.16 - 0.5, 0.74 - 0.5,
                        0.158 - 0.5, 0.71 - 0.5,
                        0.166 - 0.5, 0.7 - 0.5,
                        0.195 - 0.5, 0.738 - 0.5,
                        0.21 - 0.5, 0.745 - 0.5,
                        0.225 - 0.5, 0.75 - 0.5,
                        0.225 - 0.5, 0.774 - 0.5,
                        0.216 - 0.5, 0.78 - 0.5,
                        0.208 - 0.5, 0.775 - 0.5,
                        0.194 - 0.5, 0.77 - 0.5,
                        0.172 - 0.5, 0.745 - 0.5,
                        0.172 - 0.5, 0.75 - 0.5,
                        0.195 - 0.5, 0.738 - 0.5,
                        0.173 - 0.5, 0.68 - 0.5,
                        0.177 - 0.5, 0.65 - 0.5,
                        0.195 - 0.5, 0.7 - 0.5,
                        0.21 - 0.5, 0.745 - 0.5,
                        0.195 - 0.5, 0.7 - 0.5,
                        0.177 - 0.5, 0.65 - 0.5,
                        0.215 - 0.5, 0.705 - 0.5,
                        0.2255 - 0.5, 0.7 - 0.5,
                        0.225 - 0.5, 0.72 - 0.5,
                        0.219 - 0.5, 0.727 - 0.5,
                        0.2255 - 0.5, 0.7 - 0.5,
                        0.215 - 0.5, 0.65 - 0.5,
                        0.205 - 0.5, 0.605 - 0.5,
                        0.195 - 0.5, 0.6 - 0.5,
                        0.207 - 0.5, 0.653 - 0.5,
                        0.215 - 0.5, 0.705 - 0.5,
                        0.195 - 0.5, 0.6 - 0.5,
                        0.156 - 0.5, 0.595 - 0.5,
                        0.16 - 0.5, 0.575 - 0.5,
                        0.172 - 0.5, 0.565 - 0.5,
                        0.219 - 0.5, 0.588 - 0.5,
                        0.2415 - 0.5, 0.585 - 0.5,
                        0.241 - 0.5, 0.605 - 0.5,
                        0.233 - 0.5, 0.61 - 0.5,
                        0.205 - 0.5, 0.605 - 0.5,
                        0.267 - 0.5, 0.79 - 0.5,
                        0.26 - 0.5, 0.75 - 0.5,
                        0.275 - 0.5, 0.67 - 0.5,
                        0.284 - 0.5, 0.67 - 0.5,
                        0.277 - 0.5, 0.75 - 0.5,
                        0.275 - 0.5, 0.77 - 0.5,
                        0.273 - 0.5, 0.78 - 0.5,
                        0.275 - 0.5, 0.77 - 0.5,
                        0.287 - 0.5, 0.75 - 0.5,
                        0.32 - 0.5, 0.79 - 0.5,
                        0.329 - 0.5, 0.79 - 0.5,
                        0.339 - 0.5, 0.79 - 0.5,
                        0.353 - 0.5, 0.785 - 0.5,
                        0.353 - 0.5, 0.8 - 0.5,
                        0.349 - 0.5, 0.815 - 0.5,
                        0.327 - 0.5, 0.81 - 0.5,
                        0.317 - 0.5, 0.808 - 0.5,
                        0.284 - 0.5, 0.79 - 0.5,
                        0.273 - 0.5, 0.78- 0.5,
                        0.353 - 0.5, 0.785 - 0.5,
                        0.327 - 0.5, 0.723 - 0.5,
                        0.295 - 0.5, 0.675 - 0.5,
                        0.3 - 0.5, 0.7 - 0.5,
                        0.317 - 0.5, 0.73 - 0.5,
                        0.327 - 0.5, 0.75 - 0.5,
                        0.339 - 0.5, 0.79 - 0.5,
                        0.317 - 0.5, 0.808 - 0.5,
                        0.317 - 0.5, 0.845 - 0.5,
                        0.322 - 0.5, 0.85 - 0.5,
                        0.327 - 0.5, 0.845 - 0.5,
                        0.327 - 0.5, 0.81 - 0.5,
                        0.327 - 0.5, 0.75 - 0.5,
                        0.327 - 0.5, 0.723 - 0.5,
                        0.327 - 0.5, 0.44 - 0.5,
                        0.317 - 0.5, 0.425 - 0.5,
                        0.317 - 0.5, 0.73 - 0.5,
                        0.32 - 0.5, 0.79 - 0.5,
                        0.327 - 0.5, 0.723 - 0.5,
                        0.339 - 0.5, 0.72 - 0.5,
                        0.336 - 0.5, 0.695 - 0.5,
                        0.295 - 0.5, 0.675 - 0.5,
                        0.3 - 0.5, 0.7 - 0.5,
                        0.394 - 0.5, 0.808 - 0.5,
                        0.4 - 0.5, 0.8 - 0.5,
                        0.4 - 0.5, 0.675 - 0.5,
                        0.406 - 0.5, 0.678 - 0.5,
                        0.406 - 0.5, 0.8 - 0.5,
                        0.4 - 0.5, 0.823 - 0.5,
                        0.406 - 0.5, 0.825 - 0.5,
                        0.411 - 0.5, 0.8 - 0.5,
                        0.411 - 0.5, 0.675 - 0.5,
                        0.417 - 0.5, 0.685 - 0.5,
                        0.417 - 0.5, 0.8 - 0.5,
                        0.417 - 0.5, 0.82 - 0.5,
                        0.422 - 0.5, 0.825 - 0.5,
                        0.422 - 0.5, 0.69 - 0.5,
                        0.428 - 0.5, 0.7 - 0.5,
                        0.428 - 0.5, 0.82 - 0.5,
                        0.438 - 0.5, 0.825 - 0.5,
                        0.45 - 0.5, 0.83 - 0.5,
                        0.45 - 0.5, 0.845 - 0.5,
                        0.444 - 0.5, 0.85 - 0.5,
                        0.45 - 0.5, 0.83 - 0.5,
                        0.449 - 0.5, 0.805 - 0.5,
                        0.448 - 0.5, 0.795 - 0.5,
                        0.446 - 0.5, 0.77 - 0.5,
                        0.445 - 0.5, 0.705 - 0.5,
                        0.428 - 0.5, 0.7 - 0.5,
                        0.428 - 0.5, 0.8 - 0.5,
                        0.438 - 0.5, 0.8 - 0.5,
                        0.438 - 0.5, 0.825 - 0.5,
                        0.45 - 0.5, 0.83 - 0.5,
                        0.449 - 0.5, 0.805 - 0.5,
                        0.46 - 0.5, 0.803 - 0.5,
                        0.457 - 0.5, 0.708 - 0.5,
                        0.462 - 0.5, 0.71 - 0.5,
                        0.467 - 0.5, 0.75 - 0.5,
                        0.463 - 0.5, 0.76 - 0.5,
                        0.469 - 0.5, 0.82 - 0.5,
                        0.471 - 0.5, 0.85 - 0.5,
                        0.36 - 0.5, 0.65 - 0.5,
                        0.358 - 0.5, 0.62 - 0.5,
                        0.365 - 0.5, 0.6- 0.5,
                        0.402 - 0.5, 0.6503 - 0.5,
                        0.443 - 0.5, 0.68 - 0.5,
                        0.492 - 0.5, 0.695 - 0.5,
                        0.494 - 0.5, 0.715 - 0.5,
                        0.487 - 0.5, 0.72 - 0.5,
                        0.48 - 0.5, 0.715 - 0.5,
                        0.462 - 0.5, 0.71 - 0.5,
                        0.457 - 0.5, 0.708 - 0.5,
                        0.445 - 0.5, 0.705 - 0.5,
                        0.428 - 0.5, 0.7 - 0.5,
                        0.422 - 0.5, 0.69 - 0.5,
                        0.417 - 0.5, 0.685 - 0.5,
                        0.411 - 0.5, 0.675 - 0.5,
                        0.406 - 0.5, 0.678 - 0.5,
                        0.4 - 0.5, 0.675 - 0.5,
                        0.383 - 0.5, 0.61 - 0.5,
                        0.391 - 0.5, 0.6 - 0.5,
                        0.443 - 0.5, 0.64 - 0.5,
                        0.393 - 0.5, 0.56 - 0.5,
                        0.461 - 0.5, 0.65 - 0.5,
                        0.483 - 0.5, 0.5 - 0.5,
                        0.486 - 0.5, 0.57 - 0.5,
                        0.487 - 0.5, 0.6 - 0.5,
                        0.461 - 0.5, 0.65 - 0.5,
                        0.483 - 0.5, 0.5 - 0.5,
                        0.486 - 0.5, 0.57 - 0.5,
                        0.487 - 0.5, 0.6 - 0.5,
                        0.519 - 0.5, 0.71 - 0.5,
                        0.522 - 0.5, 0.69 - 0.5,
                        0.525 - 0.5, 0.677 - 0.5,
                        0.534 - 0.5, 0.68 - 0.5,
                        0.544 - 0.5, 0.7 - 0.5,
                        0.557 - 0.5, 0.725 - 0.5,
                        0.57 - 0.5, 0.73 - 0.5,
                        0.588 - 0.5, 0.74 - 0.5,
                        0.592 - 0.5, 0.765 - 0.5,
                        0.574 - 0.5, 0.765 - 0.5,
                        0.562 - 0.5, 0.755 - 0.5,
                        0.562 - 0.5, 0.755 - 0.5,
                        0.57 - 0.5, 0.83 - 0.5,
                        0.574 - 0.5, 0.845 - 0.5,
                        0.574 - 0.5, 0.765 - 0.5,
                        0.57 - 0.5, 0.73 - 0.5,
                        0.562 - 0.5, 0.67 - 0.5,
                        0.555 - 0.5, 0.625 - 0.5,
                        0.533 - 0.5, 0.605 - 0.5,
                        0.549 - 0.5, 0.655 - 0.5,
                        0.557 - 0.5, 0.725 - 0.5,
                        0.574 - 0.5, 0.675 - 0.5,
                        0.593 - 0.5, 0.63 - 0.5,
                        0.608 - 0.5, 0.625 - 0.5,
                        0.602 - 0.5, 0.65 - 0.5,
                        0.608 - 0.5, 0.625 - 0.5,
                        0.593 - 0.5, 0.63 - 0.5,
                        0.574 - 0.5, 0.6 - 0.5,
                        0.592 - 0.5, 0.6 - 0.5,
                        0.602 - 0.5, 0.595 - 0.5,
                        0.641 - 0.5, 0.84 - 0.5,
                        0.646 - 0.5, 0.825 - 0.5,
                        0.654 - 0.5, 0.855 - 0.5,
                        0.659 - 0.5, 0.842 - 0.5,
                        0.653 - 0.5, 0.82 - 0.5,
                        0.659 - 0.5, 0.818 - 0.5,
                        0.658 - 0.5, 0.79 - 0.5,
                        0.653 - 0.5, 0.76 - 0.5,
                        0.653 - 0.5, 0.7 - 0.5,
                        0.641 - 0.5, 0.7 - 0.5,
                        0.638 - 0.5, 0.8 - 0.5,
                        0.653 - 0.5, 0.76 - 0.5,
                        0.652 - 0.5, 0.83 - 0.5,
                        0.675 - 0.5, 0.8 - 0.5,
                        0.67 - 0.5, 0.825 - 0.5,
                        0.683 - 0.5, 0.84 - 0.5,
                        0.675 - 0.5, 0.855 - 0.5,
                        0.6675 - 0.5, 0.82 - 0.5,
                        0.667 - 0.5, 0.794 - 0.5,
                        0.667 - 0.5, 0.794 - 0.5,
                        0.661 - 0.5, 0.8 - 0.5,
                        0.661 - 0.5, 0.819 - 0.5,
                        0.6675 - 0.5, 0.82 - 0.5,
                        0.679 - 0.5, 0.825 - 0.5,
                        0.684 - 0.5, 0.825 - 0.5,
                        0.683 - 0.5, 0.8 - 0.5,
                        0.675 - 0.5, 0.8 - 0.5,
                        0.662 - 0.5, 0.755 - 0.5,
                        0.667 - 0.5, 0.725 - 0.5,
                        0.678 - 0.5, 0.73 - 0.5,
                        0.677 - 0.5, 0.75 - 0.5,
                        0.668 - 0.5, 0.76 - 0.5,
                        0.668 - 0.5, 0.76 - 0.5,
                        0.677 - 0.5, 0.75 - 0.5,
                        0.679 - 0.5, 0.78 - 0.5,
                        0.675 - 0.5, 0.8 - 0.5,
                        0.684 - 0.5, 0.83 - 0.5,
                        0.686 - 0.5, 0.82 - 0.5,
                        0.694 - 0.5, 0.81 - 0.5,
                        0.704 - 0.5, 0.83 - 0.5,
                        0.702 - 0.5, 0.85 - 0.5,
                        0.704 - 0.5, 0.83 - 0.5,
                        0.696 - 0.5, 0.808 - 0.5,
                        0.683 - 0.5, 0.8 - 0.5,
                        0.684 - 0.5, 0.775 - 0.5,
                        0.683 - 0.5, 0.75 - 0.5,
                        0.688 - 0.5, 0.74 - 0.5,
                        0.698 - 0.5, 0.745 - 0.5,
                        0.699 - 0.5, 0.8 - 0.5,
                        0.6335 - 0.5, 0.695 - 0.5,
                        0.618 - 0.5, 0.625 - 0.5,
                        0.627 - 0.5, 0.6 - 0.5,
                        0.641 - 0.5, 0.67 - 0.5,
                        0.6335 - 0.5, 0.695 - 0.5,
                        0.641 - 0.5, 0.67 - 0.5,
                        0.711 - 0.5, 0.725 - 0.5,
                        0.725 - 0.5, 0.725 - 0.5,
                        0.714 - 0.5, 0.748 - 0.5,
                        0.698 - 0.5, 0.745 - 0.5,
                        0.688 - 0.5, 0.74 - 0.5,
                        0.678 - 0.5, 0.73 - 0.5,
                        0.667 - 0.5, 0.725 - 0.5,
                        0.653 - 0.5, 0.7 - 0.5,
                        0.641 - 0.5, 0.698 - 0.5,
                        0.725 - 0.5, 0.725 - 0.5,
                        0.711 - 0.5, 0.725 - 0.5,
                        0.698 - 0.5, 0.695 - 0.5,
                        0.722 - 0.5, 0.7 - 0.5,
                        0.725 - 0.5, 0.713 - 0.5,
                        0.667 - 0.5, 0.675 - 0.5,
                        0.675 - 0.5, 0.66 - 0.5,
                        0.685 - 0.5, 0.66 - 0.5,
                        0.687 - 0.5, 0.68 - 0.5,
                        0.684 - 0.5, 0.7 - 0.5,
                        0.685 - 0.5, 0.66 - 0.5,
                        0.675 - 0.5, 0.66 - 0.5,
                        0.68 - 0.5, 0.645 - 0.5,
                        0.682 - 0.5, 0.625 - 0.5,
                        0.683 - 0.5, 0.58 - 0.5,
                        0.678 - 0.5, 0.54 - 0.5,
                        0.6875 - 0.5, 0.525 - 0.5,
                        0.6875 - 0.5, 0.625 - 0.5,
                        0.6875 - 0.5, 0.65 - 0.5,
                        0.6875 - 0.5, 0.525 - 0.5,
                        0.678 - 0.5, 0.54 - 0.5,
                        0.652 - 0.5, 0.475 - 0.5,
                        0.65 - 0.5, 0.44 - 0.5,
                        0.667 - 0.5, 0.45 - 0.5,
                        0.679 - 0.5, 0.5 - 0.5,
                        0.6875 - 0.5, 0.65 - 0.5,
                        0.68 - 0.5, 0.645 - 0.5,
                        0.65 - 0.5, 0.615 - 0.5,
                        0.64 - 0.5, 0.62 - 0.5,
                        0.645 - 0.5, 0.6 - 0.5,
                        0.682 - 0.5, 0.625 - 0.5,
                        0.6875 - 0.5, 0.625 - 0.5,
                        0.706 - 0.5, 0.6245 - 0.5,
                        0.708 - 0.5, 0.64 - 0.5,
                        0.7 - 0.5, 0.65 - 0.5,
                        0.65 - 0.5, 0.44 - 0.5,
                        0.652 - 0.5, 0.475 - 0.5,
                        0.633 - 0.5, 0.458 - 0.5,
                        0.617 - 0.5, 0.465 - 0.5,
                        0.63 - 0.5, 0.445 - 0.5,
                        getv(756), getv_b(28),
                        getv(758), getv_b(36),
                        getv(771), getv_b(42),
                        getv(771), getv_b(33),
                        getv(785), getv_b(46),
                        getv(787), getv_b(36),
                        getv(799), getv_b(55),
                        getv(802), getv_b(37),
                        getv(810), getv_b(63),
                        getv(814), getv_b(38),
                        getv(826), getv_b(62),
                        getv(845), getv_b(36),
                        getv(835), getv_b(66),
                        getv(862), getv_b(34),
                        getv(842), getv_b(71),
                        getv(885), getv_b(28),
                        getv(846), getv_b(77),
                        getv(878), getv_b(46),
                        getv(850), getv_b(84),
                        getv(874), getv_b(66),
                        getv(851), getv_b(93),
                        getv(873), getv_b(80),
                        getv(846), getv_b(108),
                        getv(872), getv_b(95),
                        getv(851), getv_b(121),
                        getv(875), getv_b(111),
                        getv(856), getv_b(135),
                        getv(879), getv_b(129),
                        getv(860), getv_b(150),
                        getv(884), getv_b(143),
                        getv(878), getv_b(157),
                        getv(888), getv_b(152),
                        getv(886), getv_b(161),
                        getv(894), getv_b(164),
                        getv(760), getv_b(44),
                        getv(764), getv_b(60),
                        getv(777), getv_b(51),
                        getv(769), getv_b(47),
                        getv(765), getv_b(71),
                        getv(788), getv_b(57),
                        getv(766), getv_b(82),
                        getv(803), getv_b(67),
                        getv(765), getv_b(90),
                        getv(792), getv_b(80),
                        getv(764), getv_b(102),
                        getv(790), getv_b(94),
                        getv(762), getv_b(115),
                        getv(793), getv_b(105),
                        getv(757), getv_b(134),
                        getv(797), getv_b(113),
                        getv(746), getv_b(161),
                        getv(804), getv_b(119),
                        getv(784), getv_b(148),
                        getv(814), getv_b(122),
                        getv(811), getv_b(144),
                        getv(826), getv_b(122),
                        getv(826), getv_b(144),
                        getv(833), getv_b(119),
                        getv(843), getv_b(145),
                        getv(841), getv_b(114),
                        getv(840), getv_b(145),
                        getv(848), getv_b(129),
                        getv(848), getv_b(147),
                        getv(853), getv_b(139),
                        getv(856), getv_b(149),
                        getv(854), getv_b(143),
                        getv(832), getv_b(78),
                        getv(810), getv_b(63),
                        getv(826), getv_b(62),
                        getv(835), getv_b(66),
                        getv(842), getv_b(71),
                        getv(846), getv_b(77),
                        getv(850), getv_b(84),
                        getv(851), getv_b(93),
                        getv(846), getv_b(108),
                        getv(832), getv_b(78),
                        getv(846), getv_b(108),
                        getv(838), getv_b(96),
                        getv(829), getv_b(84),
                        getv(821), getv_b(74),
                        getv(810), getv_b(63),
                        getv(803), getv_b(67),
                        getv(792), getv_b(80),
                        getv(790), getv_b(94),
                        getv(793), getv_b(105),
                        getv(797), getv_b(113),
                        getv(804), getv_b(119),
                        getv(814), getv_b(122),
                        getv(826), getv_b(122),
                        getv(833), getv_b(119),
                        getv(841), getv_b(114),
                        getv(832), getv_b(99),
                        getv(825), getv_b(89),
                        getv(815), getv_b(78),
                        getv(809), getv_b(72),
                        getv(31), getv_b(276),
                        getv(35), getv_b(276),
                        getv(31), getv_b(238),
                        getv(35), getv_b(238),
                        getv(35), getv_b(238),
                        getv(35), getv_b(246),
                        getv(57), getv_b(268),
                        getv(57), getv_b(276),
                        getv(57), getv_b(276),
                        getv(61), getv_b(276),
                        getv(57), getv_b(238),
                        getv(61), getv_b(238),
                        getv(72), getv_b(255),//a
                        getv(76), getv_b(257),
                        getv(75), getv_b(250),
                        getv(79), getv_b(253),
                        getv(80), getv_b(248),
                        getv(83), getv_b(252),
                        getv(85), getv_b(247),
                        getv(88), getv_b(253),
                        getv(91), getv_b(249),
                        getv(90), getv_b(254),
                        getv(94), getv_b(252),
                        getv(91), getv_b(258),
                        getv(95), getv_b(257),
                        getv(92), getv_b(276),
                        getv(97), getv_b(276),
                        getv(91), getv_b(258),
                        getv(91), getv_b(262),
                        getv(87), getv_b(259),
                        getv(85), getv_b(264),
                        getv(81), getv_b(260),
                        getv(80), getv_b(264),
                        getv(77), getv_b(262),
                        getv(78), getv_b(266),
                        getv(73), getv_b(264),
                        getv(76), getv_b(268),
                        getv(71), getv_b(269),
                        getv(77), getv_b(271),
                        getv(72), getv_b(273),
                        getv(79), getv_b(273),
                        getv(77), getv_b(276),
                        getv(82), getv_b(273),
                        getv(82), getv_b(277),
                        getv(86), getv_b(272),
                        getv(88), getv_b(275),
                        getv(89), getv_b(271),
                        getv(92), getv_b(271),
                        getv(92), getv_b(267),//
                        getv(105), getv_b(248),//t
                        getv(105), getv_b(253),
                        getv(117), getv_b(248),
                        getv(117), getv_b(253),
                        getv(108), getv_b(241),
                        getv(112), getv_b(238),
                        getv(108), getv_b(273),
                        getv(112), getv_b(271),
                        getv(111), getv_b(276),
                        getv(117), getv_b(272),
                        getv(117), getv_b(276),//
                        getv(126), getv_b(242),//i
                        getv(126), getv_b(238),
                        getv(130), getv_b(242),
                        getv(130), getv_b(238),
                        getv(126), getv_b(276),
                        getv(126), getv_b(248),
                        getv(130), getv_b(276),
                        getv(130), getv_b(248),//
                        getv(140), getv_b(261),
                        getv(144), getv_b(259),
                        getv(141), getv_b(254),
                        getv(145), getv_b(256),
                        getv(145), getv_b(250),
                        getv(149), getv_b(253),
                        getv(151), getv_b(247),
                        getv(153), getv_b(252),
                        getv(157), getv_b(248),
                        getv(157), getv_b(253),
                        getv(162), getv_b(250),
                        getv(160), getv_b(256),
                        getv(164), getv_b(255),
                        getv(160), getv_b(260),
                        getv(165), getv_b(260),
                        getv(160), getv_b(265),
                        getv(165), getv_b(267),
                        getv(160), getv_b(268),
                        getv(162), getv_b(273),
                        getv(157), getv_b(272),
                        getv(157), getv_b(276),
                        getv(153), getv_b(273),
                        getv(151), getv_b(277),
                        getv(149), getv_b(272),
                        getv(146), getv_b(275),
                        getv(146), getv_b(270),
                        getv(141), getv_b(270),
                        getv(145), getv_b(266),
                        getv(139), getv_b(266),
                        getv(144), getv_b(263),
                        getv(141), getv_b(254),
                        getv(175), getv_b(248),//n
                        getv(179), getv_b(248),
                        getv(175), getv_b(276),
                        getv(179), getv_b(276),
                        getv(179), getv_b(256),
                        getv(179), getv_b(251),
                        getv(185), getv_b(253),
                        getv(184), getv_b(248),
                        getv(188), getv_b(253),
                        getv(189), getv_b(247),
                        getv(191), getv_b(253),
                        getv(195), getv_b(249),
                        getv(193), getv_b(256),
                        getv(198), getv_b(256),
                        getv(193), getv_b(276),
                        getv(198), getv_b(276), //
                        getv(72 + 136), getv_b(255),//a+136
                        getv(76 + 136), getv_b(257),
                        getv(75 + 136), getv_b(250),
                        getv(79 + 136), getv_b(253),
                        getv(80 + 136), getv_b(248),
                        getv(83 + 136), getv_b(252),
                        getv(85 + 136), getv_b(247),
                        getv(88 + 136), getv_b(253),
                        getv(91 + 136), getv_b(249),
                        getv(90 + 136), getv_b(254),
                        getv(94 + 136), getv_b(252),
                        getv(91 + 136), getv_b(258),
                        getv(95 + 136), getv_b(257),
                        getv(92 + 136), getv_b(276),
                        getv(97 + 136), getv_b(276),
                        getv(91 + 136), getv_b(258),
                        getv(91 + 136), getv_b(262),
                        getv(87 + 136), getv_b(259),
                        getv(85 + 136), getv_b(264),
                        getv(81 + 136), getv_b(260),
                        getv(80 + 136), getv_b(264),
                        getv(77 + 136), getv_b(262),
                        getv(78 + 136), getv_b(266),
                        getv(73 + 136), getv_b(264),
                        getv(76 + 136), getv_b(268),
                        getv(71 + 136), getv_b(269),
                        getv(77 + 136), getv_b(271),
                        getv(72 + 136), getv_b(273),
                        getv(79 + 136), getv_b(273),
                        getv(77 + 136), getv_b(276),
                        getv(82 + 136), getv_b(273),
                        getv(82 + 136), getv_b(277),
                        getv(86 + 136), getv_b(272),
                        getv(88 + 136), getv_b(275),
                        getv(89 + 136), getv_b(271),
                        getv(92 + 136), getv_b(271),
                        getv(92 + 136), getv_b(267),//
                        getv(242), getv_b(238),
                        getv(247), getv_b(238),
                        getv(242), getv_b(276),
                        getv(247), getv_b(276),
                        getv(298), getv_b(250),
                        getv(304), getv_b(250),
                        getv(298), getv_b(248),
                        getv(302), getv_b(244),
                        getv(297), getv_b(245),
                        getv(298), getv_b(239),
                        getv(294), getv_b(242),
                        getv(294), getv_b(237),
                        getv(292), getv_b(242),
                        getv(291), getv_b(236),
                        getv(288), getv_b(241),
                        getv(285), getv_b(237),
                        getv(285), getv_b(242),
                        getv(281), getv_b(238),
                        getv(282), getv_b(243),
                        getv(275), getv_b(241),
                        getv(278), getv_b(246),
                        getv(271), getv_b(246),
                        getv(276), getv_b(250),
                        getv(269), getv_b(251),
                        getv(275), getv_b(254),
                        getv(269), getv_b(257),
                        getv(275), getv_b(260),
                        getv(270), getv_b(263),
                        getv(276), getv_b(266),
                        getv(272), getv_b(270),
                        getv(279), getv_b(269),
                        getv(278), getv_b(274),
                        getv(283), getv_b(271),
                        getv(283), getv_b(276),
                        getv(288), getv_b(272),
                        getv(290), getv_b(277),
                        getv(292), getv_b(271),
                        getv(296), getv_b(275),
                        getv(296), getv_b(269),
                        getv(302), getv_b(271),
                        getv(298), getv_b(266),
                        getv(304), getv_b(266),
                        getv(299), getv_b(263),
                        getv(304), getv_b(263),
                        getv(175 + 138), getv_b(248),//n+138
                        getv(179 + 138), getv_b(248),
                        getv(175 + 138), getv_b(276),
                        getv(179 + 138), getv_b(276),
                        getv(179 + 138), getv_b(256),
                        getv(179 + 138), getv_b(251),
                        getv(185 + 138), getv_b(253),
                        getv(184 + 138), getv_b(248),
                        getv(188 + 138), getv_b(253),
                        getv(189 + 138), getv_b(247),
                        getv(191 + 138), getv_b(253),
                        getv(195 + 138), getv_b(249),
                        getv(193 + 138), getv_b(256),
                        getv(198 + 138), getv_b(256),
                        getv(193 + 138), getv_b(276),
                        getv(198 + 138), getv_b(276), //
                        getv(313), getv_b(238),
                        getv(318), getv_b(238),
                        getv(313), getv_b(276),
                        getv(318), getv_b(276),
                        getv(353), getv_b(247),//u
                        getv(348), getv_b(247),
                        getv(353), getv_b(270),
                        getv(348), getv_b(270),
                        getv(348), getv_b(270),
                        getv(353), getv_b(270),
                        getv(351), getv_b(275),
                        getv(356), getv_b(272),
                        getv(357), getv_b(276),
                        getv(360), getv_b(272),
                        getv(362), getv_b(275),
                        getv(363), getv_b(271),
                        getv(366), getv_b(272),
                        getv(366), getv_b(269),
                        getv(366), getv_b(247),
                        getv(371), getv_b(247),
                        getv(366), getv_b(276),
                        getv(371), getv_b(276),//
                        getv(175 + 207), getv_b(248),//n382-175=+207
                        getv(179 + 207), getv_b(248),
                        getv(175 + 207), getv_b(276),
                        getv(179 + 207), getv_b(276),
                        getv(179 + 207), getv_b(256),
                        getv(179 + 207), getv_b(251),
                        getv(185 + 207), getv_b(253),
                        getv(184 + 207), getv_b(248),
                        getv(188 + 207), getv_b(253),
                        getv(189 + 207), getv_b(247),
                        getv(191 + 207), getv_b(253),
                        getv(195 + 207), getv_b(249),
                        getv(193 + 207), getv_b(256),
                        getv(198 + 207), getv_b(256),
                        getv(193 + 207), getv_b(276),
                        getv(198 + 207), getv_b(276), //
                        getv(435), getv_b(257),//g
                        getv(435), getv_b(252),
                        getv(432), getv_b(254),
                        getv(431), getv_b(249),
                        getv(429), getv_b(252),
                        getv(425), getv_b(247),
                        getv(424), getv_b(252),
                        getv(420), getv_b(249),
                        getv(421), getv_b(254),
                        getv(416), getv_b(254),
                        getv(420), getv_b(258),
                        getv(415), getv_b(262),
                        getv(419), getv_b(266),
                        getv(415), getv_b(269),
                        getv(421), getv_b(270),
                        getv(420), getv_b(274),
                        getv(425), getv_b(272),
                        getv(425), getv_b(276),
                        getv(428), getv_b(272),
                        getv(431), getv_b(275),
                        getv(431), getv_b(270),
                        getv(434), getv_b(272),
                        getv(434), getv_b(267),
                        getv(434), getv_b(248),
                        getv(439), getv_b(248),
                        getv(434), getv_b(279),
                        getv(439), getv_b(279),
                        getv(432), getv_b(281),
                        getv(435), getv_b(285),
                        getv(429), getv_b(284),
                        getv(430), getv_b(288),
                        getv(426), getv_b(285),
                        getv(423), getv_b(288),
                        getv(423), getv_b(283),
                        getv(416), getv_b(284),
                        getv(420), getv_b(279),
                        getv(415), getv_b(279),//
                        getv(463), getv_b(238),
                        getv(468), getv_b(238),
                        getv(463), getv_b(276),
                        getv(468), getv_b(276),
                        getv(489), getv_b(238),
                        getv(494), getv_b(238),
                        getv(489), getv_b(276),
                        getv(494), getv_b(276),
                        getv(468), getv_b(253),
                        getv(489), getv_b(253),
                        getv(468), getv_b(258),
                        getv(489), getv_b(258),
                        getv(526), getv_b(255),//s
                        getv(521), getv_b(255),
                        getv(525), getv_b(251),
                        getv(520), getv_b(253),
                        getv(521), getv_b(248),
                        getv(518), getv_b(251),
                        getv(516), getv_b(247),
                        getv(513), getv_b(251),
                        getv(510), getv_b(248),
                        getv(510), getv_b(253),
                        getv(506), getv_b(253),
                        getv(509), getv_b(256),
                        getv(505), getv_b(258),
                        getv(511), getv_b(258),
                        getv(509), getv_b(262),
                        getv(514), getv_b(260),
                        getv(514), getv_b(263),
                        getv(519), getv_b(260),
                        getv(519), getv_b(264),
                        getv(523), getv_b(262),
                        getv(522), getv_b(266),
                        getv(528), getv_b(266),
                        getv(523), getv_b(268),
                        getv(527), getv_b(271),
                        getv(522), getv_b(271),
                        getv(523), getv_b(275),
                        getv(519), getv_b(273),
                        getv(517), getv_b(276),
                        getv(513), getv_b(272),
                        getv(509), getv_b(275),
                        getv(510), getv_b(271),
                        getv(505), getv_b(272),
                        getv(508), getv_b(267),
                        getv(505), getv_b(267),//
                        getv(126 + 411), getv_b(242),//i
                        getv(126 + 411), getv_b(238),
                        getv(130 + 411), getv_b(242),
                        getv(130 + 411), getv_b(238),
                        getv(126 + 411), getv_b(276),
                        getv(126 + 411), getv_b(248),
                        getv(130 + 411), getv_b(276),
                        getv(130 + 411), getv_b(248),//
                        getv(175 + 377), getv_b(248),//n+377
                        getv(179 + 377), getv_b(248),
                        getv(175 + 377), getv_b(276),
                        getv(179 + 377), getv_b(276),
                        getv(179 + 377), getv_b(256),
                        getv(179 + 377), getv_b(251),
                        getv(185 + 377), getv_b(253),
                        getv(184 + 377), getv_b(248),
                        getv(188 + 377), getv_b(253),
                        getv(189 + 377), getv_b(247),
                        getv(191 + 377), getv_b(253),
                        getv(195 + 377), getv_b(249),
                        getv(193 + 377), getv_b(256),
                        getv(198 + 377), getv_b(256),
                        getv(193 + 377), getv_b(276),
                        getv(198 + 377), getv_b(276), //
                        getv(435 + 170), getv_b(257),//g
                        getv(435 + 170), getv_b(252),
                        getv(432 + 170), getv_b(254),
                        getv(431 + 170), getv_b(249),
                        getv(429 + 170), getv_b(252),
                        getv(425 + 170), getv_b(247),
                        getv(424 + 170), getv_b(252),
                        getv(420 + 170), getv_b(249),
                        getv(421 + 170), getv_b(254),
                        getv(416 + 170), getv_b(254),
                        getv(420 + 170), getv_b(258),
                        getv(415 + 170), getv_b(262),
                        getv(419 + 170), getv_b(266),
                        getv(415 + 170), getv_b(269),
                        getv(421 + 170), getv_b(270),
                        getv(420 + 170), getv_b(274),
                        getv(425 + 170), getv_b(272),
                        getv(425 + 170), getv_b(276),
                        getv(428 + 170), getv_b(272),
                        getv(431 + 170), getv_b(275),
                        getv(431 + 170), getv_b(270),
                        getv(434 + 170), getv_b(272),
                        getv(434 + 170), getv_b(267),
                        getv(434 + 170), getv_b(248),
                        getv(439 + 170), getv_b(248),
                        getv(434 + 170), getv_b(279),
                        getv(439 + 170), getv_b(279),
                        getv(432 + 170), getv_b(281),
                        getv(435 + 170), getv_b(285),
                        getv(429 + 170), getv_b(284),
                        getv(430 + 170), getv_b(288),
                        getv(426 + 170), getv_b(285),
                        getv(423 + 170), getv_b(288),
                        getv(423 + 170), getv_b(283),
                        getv(416 + 170), getv_b(284),
                        getv(420 + 170), getv_b(279),
                        getv(415 + 170), getv_b(279),//
                        getv(633), getv_b(238),//U
                        getv(638), getv_b(238),
                        getv(633), getv_b(266),
                        getv(638), getv_b(266),
                        getv(637), getv_b(273),
                        getv(641), getv_b(270),
                        getv(643), getv_b(276),
                        getv(647), getv_b(272),
                        getv(651), getv_b(276),
                        getv(654), getv_b(271),
                        getv(659), getv_b(273),
                        getv(659), getv_b(266),
                        getv(664), getv_b(266),
                        getv(659), getv_b(238),
                        getv(664), getv_b(238),//
                        getv(175 + 501), getv_b(248),//n+501
                        getv(179 + 501), getv_b(248),
                        getv(175 + 501), getv_b(276),
                        getv(179 + 501), getv_b(276),
                        getv(179 + 501), getv_b(256),
                        getv(179 + 501), getv_b(251),
                        getv(185 + 501), getv_b(253),
                        getv(184 + 501), getv_b(248),
                        getv(188 + 501), getv_b(253),
                        getv(189 + 501), getv_b(247),
                        getv(191 + 501), getv_b(253),
                        getv(195 + 501), getv_b(249),
                        getv(193 + 501), getv_b(256),
                        getv(198 + 501), getv_b(256),
                        getv(193 + 501), getv_b(276),
                        getv(198 + 501), getv_b(276), //
                        getv(126 + 584), getv_b(242),//i+584
                        getv(126 + 584), getv_b(238),
                        getv(130 + 584), getv_b(242),
                        getv(130 + 584), getv_b(238),
                        getv(126 + 584), getv_b(276),
                        getv(126 + 584), getv_b(248),
                        getv(130 + 584), getv_b(276),
                        getv(130 + 584), getv_b(248),//
                        getv(721), getv_b(248),//v
                        getv(726), getv_b(248),
                        getv(733), getv_b(276),
                        getv(735), getv_b(270),
                        getv(738), getv_b(276),
                        getv(743), getv_b(248),
                        getv(748), getv_b(248),//
                        getv(760), getv_b(259),//e
                        getv(760), getv_b(263),
                        getv(777), getv_b(259),
                        getv(781), getv_b(263),
                        getv(776), getv_b(256),
                        getv(779), getv_b(254),
                        getv(774), getv_b(254),
                        getv(774), getv_b(249),
                        getv(769), getv_b(252),
                        getv(768), getv_b(247),
                        getv(765), getv_b(252),
                        getv(762), getv_b(249),
                        getv(761), getv_b(254),
                        getv(757), getv_b(253),
                        getv(760), getv_b(259),
                        getv(754), getv_b(259),
                        getv(760), getv_b(263),
                        getv(754), getv_b(266),
                        getv(761), getv_b(268),
                        getv(759), getv_b(273),
                        getv(763), getv_b(272),
                        getv(764), getv_b(276),
                        getv(768), getv_b(273),
                        getv(772), getv_b(276),
                        getv(774), getv_b(271),
                        getv(780), getv_b(271),
                        getv(776), getv_b(267),
                        getv(781), getv_b(267),//
                        getv(790), getv_b(248),//r
                        getv(795), getv_b(248),
                        getv(790), getv_b(276),
                        getv(795), getv_b(276),
                        getv(795), getv_b(257),
                        getv(795), getv_b(251),
                        getv(799), getv_b(252),
                        getv(800), getv_b(247),
                        getv(805), getv_b(254),
                        getv(805), getv_b(249),//
                        getv(526 + 306), getv_b(255),//s
                        getv(521 + 306), getv_b(255),
                        getv(525 + 306), getv_b(251),
                        getv(520 + 306), getv_b(253),
                        getv(521 + 306), getv_b(248),
                        getv(518 + 306), getv_b(251),
                        getv(516 + 306), getv_b(247),
                        getv(513 + 306), getv_b(251),
                        getv(510 + 306), getv_b(248),
                        getv(510 + 306), getv_b(253),
                        getv(506 + 306), getv_b(253),
                        getv(509 + 306), getv_b(256),
                        getv(505 + 306), getv_b(258),
                        getv(511 + 306), getv_b(258),
                        getv(509 + 306), getv_b(262),
                        getv(514 + 306), getv_b(260),
                        getv(514 + 306), getv_b(263),
                        getv(519 + 306), getv_b(260),
                        getv(519 + 306), getv_b(264),
                        getv(523 + 306), getv_b(262),
                        getv(522 + 306), getv_b(266),
                        getv(528 + 306), getv_b(266),
                        getv(523 + 306), getv_b(268),
                        getv(527 + 306), getv_b(271),
                        getv(522 + 306), getv_b(271),
                        getv(523 + 306), getv_b(275),
                        getv(519 + 306), getv_b(273),
                        getv(517 + 306), getv_b(276),
                        getv(513 + 306), getv_b(272),
                        getv(509 + 306), getv_b(275),
                        getv(510 + 306), getv_b(271),
                        getv(505 + 306), getv_b(272),
                        getv(508 + 306), getv_b(267),
                        getv(505 + 306), getv_b(267),//
                        getv(126 + 716), getv_b(242),//i
                        getv(126 + 716), getv_b(238),
                        getv(130 + 716), getv_b(242),
                        getv(130 + 716), getv_b(238),
                        getv(126 + 716), getv_b(276),
                        getv(126 + 716), getv_b(248),
                        getv(130 + 716), getv_b(276),
                        getv(130 + 716), getv_b(248),//
                        getv(105 + 753), getv_b(248),//t
                        getv(105 + 753), getv_b(253),
                        getv(117 + 753), getv_b(248),
                        getv(117 + 753), getv_b(253),
                        getv(108 + 753), getv_b(241),
                        getv(112 + 753), getv_b(238),
                        getv(108 + 753), getv_b(273),
                        getv(112 + 753), getv_b(271),
                        getv(111 + 753), getv_b(276),
                        getv(117 + 753), getv_b(272),
                        getv(117 + 753), getv_b(276),//
                        getv(721 + 152), getv_b(248),//v
                        getv(726 + 152), getv_b(248),
                        getv(733 + 152), getv_b(276),
                        getv(735 + 152), getv_b(270),
                        getv(738 + 152), getv_b(276),
                        getv(743 + 152), getv_b(248),
                        getv(748 + 152), getv_b(248),//
                        getv(889), getv_b(275),
                        getv(884), getv_b(275),
                        getv(888), getv_b(281),
                        getv(882), getv_b(281),
                        getv(883), getv_b(287),
                        getv(876), getv_b(283),
                        getv(876), getv_b(288),
                        getv(769), getv_b(47),
                        getv(786), getv_b(56),
                        getv(765), getv_b(72),
                        getv(764), getv_b(60),
                        getv(760), getv_b(36),
                        getv(784), getv_b(45),
                        getv(787), getv_b(36),
                        getv(771), getv_b(33) };
    float g = 121.0 / 276.0;
    float b = 155.0 / 276.0;
    float r_r = 186.0 / 232.0;
    float r_g = 17.0 / 232.0;
    float r_b = 29.0 / 232.0;
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
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
                            0, g, b,
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
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b,
                                0, g, b };
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
}

void state_1() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    printf("FKU\n");
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
    glDrawArrays(GL_QUAD_STRIP, 363, 34);
    glDrawArrays(GL_QUAD_STRIP, 397, 32);
    glDrawArrays(GL_TRIANGLE_FAN, 429, 9);
    glDrawArrays(GL_TRIANGLE_FAN, 438, 6);
    glDrawArrays(GL_POLYGON, 444, 14);
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
    glDrawArrays(GL_TRIANGLE_STRIP, 1003, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 1007, 4);
    //glDisableClientState(GL_VERTEX_ARRAY);
    //glDisableClientState(GL_COLOR_ARRAY);
}
void state_2_poly(int start, int times, int test[]) {
    //static GLubyte tmp[] = {};
    if (firsttime == 1) {
        for (int i = 0; i < times; i++) {
            test[i] = start++;
            //printf("%d\n", test[i]);
        }
    }
    //printf("total%d\n////////////////\n", times);
    glDrawElements(GL_POLYGON, times, GL_UNSIGNED_INT, test);
}
void state_2_tri(int start, int times, int test[]) {
    if (firsttime == 1) {
        for (int i = 0; i < times; i++) {
            test[i] = start++;
            //printf("%d\n", test[i]);
        }
    }
    glDrawElements(GL_TRIANGLES, times, GL_UNSIGNED_INT, test);
}
void state_2_quads(int start, int times, int test[]) {
    if (firsttime == 1) {
        for (int i = 0; i < times; i++) {
            test[i] = start++;
            //printf("%d\n", test[i]);
        }
    }
    glDrawElements(GL_QUAD_STRIP, times, GL_UNSIGNED_INT, test);
}
void state_2_trif(int start, int times, int test[]) {
    if (firsttime == 1) {
        for (int i = 0; i < times; i++) {
            test[i] = start++;
            //printf("%d\n", test[i]);
        }
    }
    glDrawElements(GL_TRIANGLE_FAN, times, GL_UNSIGNED_INT, test);
}
void state_2_tris(int start, int times, int test[]) {
    if (firsttime == 1) {
        for (int i = 0; i < times; i++) {
            test[i] = start++;
            //printf("%d\n", test[i]);
        }
    }
    glDrawElements(GL_TRIANGLE_STRIP, times, GL_UNSIGNED_INT, test);
}
void state_2() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    state_2_poly(0, 4, array_1);
    state_2_poly(4, 4, array_2);
    state_2_tri(8, 3, array_3);
    state_2_poly(11, 4, array_4);
    state_2_poly(15, 4, array_5);
    state_2_poly(19, 4, array_6);
    state_2_poly(23, 4, array_7);
    state_2_poly(27, 8, array_8);
    state_2_poly(35, 13, array_9);
    state_2_poly(48, 9, array_10);
    state_2_poly(57, 7, array_11);
    state_2_poly(64, 7, array_12);
    state_2_poly(71, 5, array_13);
    state_2_poly(76, 5, array_14);
    state_2_poly(81, 4, array_15);
    state_2_poly(93, 5, array_16);
    state_2_poly(98, 6, array_17);
    state_2_poly(104, 6, array_18);
    state_2_poly(110, 9, array_19);
    state_2_poly(119, 7, array_20);
    state_2_poly(126, 12, array_21);
    state_2_poly(138, 7, array_22);
    state_2_poly(145, 11, array_23);
    state_2_poly(156, 5, array_24);
    state_2_poly(161, 6, array_25);
    state_2_poly(167, 6, array_26);
    state_2_poly(173, 8, array_27);
    state_2_poly(181, 9, array_28);
    state_2_poly(190, 9, array_29);
    state_2_poly(199, 18, array_30);
    state_2_poly(217, 4, array_31);
    state_2_poly(221, 4, array_32);
    state_2_poly(225, 4, array_33);
    state_2_poly(229, 11, array_34);
    state_2_poly(240, 10, array_35);
    state_2_poly(250, 4, array_36);
    state_2_poly(254, 5, array_37);
    state_2_poly(259, 11, array_38);
    state_2_poly(270, 8, array_39);
    state_2_poly(278, 8, array_40);
    state_2_poly(286, 5, array_41);
    state_2_poly(291, 4, array_42);
    state_2_poly(295, 5, array_43);
    state_2_poly(300, 8, array_44);
    state_2_poly(308, 4, array_45);
    state_2_poly(312, 11, array_46);
    state_2_poly(323, 5, array_47);
    state_2_poly(328, 5, array_48);
    state_2_poly(333, 9, array_49);
    state_2_poly(342, 6, array_50);
    state_2_poly(348, 10, array_51);
    state_2_poly(358, 5, array_52);
    state_2_quads(363, 34, array_53);
    state_2_quads(397, 32, array_54);
    state_2_trif(429, 9, array_55);
    state_2_trif(438, 6, array_56);
    state_2_poly(444, 14, array_57);
    state_2_tris(458, 4, array_58);
    state_2_tris(462, 8, array_59);
    state_2_tris(470, 15, array_60);
    state_2_tris(485, 22, array_61);
    state_2_tris(507, 4, array_62);
    state_2_tris(511, 7, array_63);
    state_2_tris(518, 4, array_64);
    state_2_tris(522, 4, array_65);
    state_2_tris(526, 31, array_66);
    state_2_tris(557, 4, array_67);
    state_2_tris(561, 12, array_68);
    state_2_tris(573, 15, array_69);
    state_2_tris(588, 22, array_70);
    state_2_tris(610, 4, array_71);
    state_2_tris(614, 40, array_72);
    state_2_tris(654, 4, array_73);
    state_2_tris(658, 12, array_74);
    state_2_tris(670, 4, array_75);
    state_2_tris(674, 4, array_76);
    state_2_tris(678, 10, array_77);
    state_2_tris(688, 4, array_78);
    state_2_tris(692, 4, array_79);
    state_2_tris(696, 12, array_80);
    state_2_tris(708, 23, array_81);
    state_2_tris(731, 14, array_82);
    state_2_tris(745, 4, array_83);
    state_2_tris(749, 4, array_84);
    state_2_tris(753, 4, array_85);
    state_2_tris(757, 34, array_86);
    state_2_tris(791, 4, array_87);
    state_2_tris(795, 4, array_88);
    state_2_tris(799, 4, array_89);
    state_2_tris(803, 12, array_90);
    state_2_tris(815, 23, array_91);
    state_2_tris(838, 14, array_92);
    state_2_tris(852, 15, array_93);
    state_2_tris(867, 4, array_94);
    state_2_tris(871, 12, array_95);
    state_2_tris(883, 4, array_96);
    state_2_tris(887, 4, array_97);
    state_2_tris(891, 7, array_98);
    state_2_tris(898, 28, array_99);
    state_2_tris(926, 4, array_100);
    state_2_tris(930, 6, array_101);
    state_2_tris(936, 34, array_102);
    state_2_tris(970, 4, array_103);
    state_2_tris(974, 4, array_104);
    state_2_tris(978, 4, array_105);
    state_2_tris(982, 7, array_106);
    state_2_tris(989, 7, array_107);
    state_2_tris(996, 7, array_108);
    state_2_tris(1003, 4, array_109);
    state_2_tris(1007, 4, array_110);
    firsttime = 0;
    //printf("%d %d %d %d\n", array_108[0], array_108[1], array_108[2], array_108[3]);
    //glDisableClientState(GL_VERTEX_ARRAY);
    //glDisableClientState(GL_COLOR_ARRAY);
}


int count_p = 0;
static GLint first_polygon[MAX];
static GLint count_polygon[MAX];

int count_t = 0;
static GLint first_tri[MAX];
static GLint count_tri[MAX];

int count_qs = 0;
static GLint first_quads[MAX];
static GLint count_quads[MAX];

int count_tf = 0;
static GLint first_trif[MAX];
static GLint count_trif[MAX];

int count_ts = 0;
static GLint first_tris[MAX];
static GLint count_tris[MAX];

static GLvoid* array_polygon[MAX];
static GLvoid* array_t[MAX];
static GLvoid* array_qs[MAX];
static GLvoid* array_tf[MAX];
static GLvoid* array_ts[MAX];

void state_3_poly(int start, int times, int test[]) {
    first_polygon[count_p] = start;
    count_polygon[count_p] = times;
    array_polygon[count_p] = test;
    count_p++;
}
void state_3_tri(int start, int times, int test[]) {
    first_tri[count_t] = start;
    count_tri[count_t] = times;
    array_t[count_t] = test;
    count_t++;
}
void state_3_quads(int start, int times, int test[]) {
    first_quads[count_qs] = start;
    count_quads[count_qs] = times;
    array_qs[count_qs] = test;
    count_qs++;
}
void state_3_trif(int start, int times, int test[]) {
    first_trif[count_tf] = start;
    count_trif[count_tf] = times;
    array_tf[count_tf] = test;
    count_tf++;
}
void state_3_tris(int start, int times, int test[]) {
    first_tris[count_ts] = start;
    count_tris[count_ts] = times;
    array_ts[count_ts] = test;
    count_ts++;

}
int firsttime_set_for_34 = 1;
void set_for_34(){
    if (firsttime_set_for_34 == 1) {
        state_3_poly(0, 4, array_1);
        state_3_poly(4, 4, array_2);
        state_3_tri(8, 3, array_3);
        state_3_poly(11, 4, array_4);
        state_3_poly(15, 4, array_5);
        state_3_poly(19, 4, array_6);
        state_3_poly(23, 4, array_7);
        state_3_poly(27, 8, array_8);
        state_3_poly(35, 13, array_9);
        state_3_poly(48, 9, array_10);
        state_3_poly(57, 7, array_11);
        state_3_poly(64, 7, array_12);
        state_3_poly(71, 5, array_13);
        state_3_poly(76, 5, array_14);
        state_3_poly(81, 4, array_15);
        state_3_poly(93, 5, array_16);
        state_3_poly(98, 6, array_17);
        state_3_poly(104, 6, array_18);
        state_3_poly(110, 9, array_19);
        state_3_poly(119, 7, array_20);
        state_3_poly(126, 12, array_21);
        state_3_poly(138, 7, array_22);
        state_3_poly(145, 11, array_23);
        state_3_poly(156, 5, array_24);
        state_3_poly(161, 6, array_25);
        state_3_poly(167, 6, array_26);
        state_3_poly(173, 8, array_27);
        state_3_poly(181, 9, array_28);
        state_3_poly(190, 9, array_29);
        state_3_poly(199, 18, array_30);
        state_3_poly(217, 4, array_31);
        state_3_poly(221, 4, array_32);
        state_3_poly(225, 4, array_33);
        state_3_poly(229, 11, array_34);
        state_3_poly(240, 10, array_35);
        state_3_poly(250, 4, array_36);
        state_3_poly(254, 5, array_37);
        state_3_poly(259, 11, array_38);
        state_3_poly(270, 8, array_39);
        state_3_poly(278, 8, array_40);
        state_3_poly(286, 5, array_41);
        state_3_poly(291, 4, array_42);
        state_3_poly(295, 5, array_43);
        state_3_poly(300, 8, array_44);
        state_3_poly(308, 4, array_45);
        state_3_poly(312, 11, array_46);
        state_3_poly(323, 5, array_47);
        state_3_poly(328, 5, array_48);
        state_3_poly(333, 9, array_49);
        state_3_poly(342, 6, array_50);
        state_3_poly(348, 10, array_51);
        state_3_poly(358, 5, array_52);
        state_3_quads(363, 34, array_53);
        state_3_quads(397, 32, array_54);
        state_3_trif(429, 9, array_55);
        state_3_trif(438, 6, array_56);
        state_3_poly(444, 14, array_57);
        state_3_tris(458, 4, array_58);
        state_3_tris(462, 8, array_59);
        state_3_tris(470, 15, array_60);
        state_3_tris(485, 22, array_61);
        state_3_tris(507, 4, array_62);
        state_3_tris(511, 7, array_63);
        state_3_tris(518, 4, array_64);
        state_3_tris(522, 4, array_65);
        state_3_tris(526, 31, array_66);
        state_3_tris(557, 4, array_67);
        state_3_tris(561, 12, array_68);
        state_3_tris(573, 15, array_69);
        state_3_tris(588, 22, array_70);
        state_3_tris(610, 4, array_71);
        state_3_tris(614, 40, array_72);
        state_3_tris(654, 4, array_73);
        state_3_tris(658, 12, array_74);
        state_3_tris(670, 4, array_75);
        state_3_tris(674, 4, array_76);
        state_3_tris(678, 10, array_77);
        state_3_tris(688, 4, array_78);
        state_3_tris(692, 4, array_79);
        state_3_tris(696, 12, array_80);
        state_3_tris(708, 23, array_81);
        state_3_tris(731, 14, array_82);
        state_3_tris(745, 4, array_83);
        state_3_tris(749, 4, array_84);
        state_3_tris(753, 4, array_85);
        state_3_tris(757, 34, array_86);
        state_3_tris(791, 4, array_87);
        state_3_tris(795, 4, array_88);
        state_3_tris(799, 4, array_89);
        state_3_tris(803, 12, array_90);
        state_3_tris(815, 23, array_91);
        state_3_tris(838, 14, array_92);
        state_3_tris(852, 15, array_93);
        state_3_tris(867, 4, array_94);
        state_3_tris(871, 12, array_95);
        state_3_tris(883, 4, array_96);
        state_3_tris(887, 4, array_97);
        state_3_tris(891, 7, array_98);
        state_3_tris(898, 28, array_99);
        state_3_tris(926, 4, array_100);
        state_3_tris(930, 6, array_101);
        state_3_tris(936, 34, array_102);
        state_3_tris(970, 4, array_103);
        state_3_tris(974, 4, array_104);
        state_3_tris(978, 4, array_105);
        state_3_tris(982, 7, array_106);
        state_3_tris(989, 7, array_107);
        state_3_tris(996, 7, array_108);
        state_3_tris(1003, 4, array_109);
        state_3_tris(1007, 4, array_110);
        firsttime_set_for_34 = 0;
    }
}

void state_3() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    set_for_34();
    glMultiDrawArrays(GL_POLYGON, first_polygon, count_polygon, count_p);
    glMultiDrawArrays(GL_TRIANGLES, first_tri, count_tri, count_t);
    glMultiDrawArrays(GL_QUAD_STRIP, first_quads, count_quads, count_qs);
    glMultiDrawArrays(GL_TRIANGLE_FAN, first_trif, count_trif, count_tf);
    glMultiDrawArrays(GL_TRIANGLE_STRIP, first_tris, count_tris, count_ts);
}

void state_4() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    set_for_34();
    glMultiDrawElements(GL_POLYGON, count_polygon, GL_UNSIGNED_INT, array_polygon, count_p);
    glMultiDrawElements(GL_TRIANGLES, count_tri, GL_UNSIGNED_INT, array_t, count_t);
    glMultiDrawElements(GL_QUAD_STRIP, count_quads, GL_UNSIGNED_INT, array_qs, count_qs);
    glMultiDrawElements(GL_TRIANGLE_FAN, count_trif, GL_UNSIGNED_INT, array_tf, count_tf);
    glMultiDrawElements(GL_TRIANGLE_STRIP, count_tris, GL_UNSIGNED_INT, array_ts, count_ts);
}

int f = 1;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    setupMethod = POINTER;
    setupPointers();
    if (derefMethod == DRAWARRAY) {
        printf("Now start state_1\n");
        state_1();
    }else if(derefMethod == DRAWELEMENTS) {
        printf("Now start state_2\n");
        state_2();
    }
    else if (derefMethod == MULTIDRAWARRAYS) {
        printf("Now start state_3\n");
        state_3();
    }
    else if (derefMethod == MULTIDRAWELEMENTS) {
        printf("Now start state_4\n");
        state_4();
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glFlush();
}
void init(void)
{
    glewInit();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    setupPointers();
}
void reshape(int w, int h)
{
    glViewport(150, 150, WIDTH, HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 2.0);
    
}

void mouse(int button, int state, int x, int y)
{
    switch (button) {
    case GLUT_LEFT_BUTTON:
        rotateMethod = ROTATEZ;
        //angle_z = rotateplus(angle_z);
        break;
    case GLUT_MIDDLE_BUTTON:
        rotateMethod = ROTATEY;
        //angle_y = rotateplus(angle_y);
        break;
    case GLUT_RIGHT_BUTTON:
        rotateMethod = ROTATEX;
        //angle_x = rotateplus(angle_x);
        break;
    default:
        break;
    }
    if (rotateMethod == ROTATEX) {
        glRotatef(10.0, 1.0, 0.0, 0.0);
    }
    else if (rotateMethod == ROTATEY) {
        glRotatef(10.0, 0.0, 1.0, 0.0);
    }
    else if (rotateMethod == ROTATEZ) {
        glRotatef(10.0, 0.0, 0.0, 1.0);
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    case '1':
        derefMethod == DRAWARRAY;
        glutPostRedisplay();
        break;
    case '2':
        derefMethod = DRAWELEMENTS;
        glutPostRedisplay();
        break;
    case '3':
        derefMethod = MULTIDRAWARRAYS;
        glutPostRedisplay();
        break;
    case '4':
        derefMethod = MULTIDRAWELEMENTS;
        glutPostRedisplay();
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1280, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
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
