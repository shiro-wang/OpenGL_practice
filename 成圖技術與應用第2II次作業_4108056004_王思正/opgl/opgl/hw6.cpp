/***************************
4108056004 王思正 第6-VI次作業12/22
***************************/
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

#define T(x) (model->triangles[(x)])
using namespace std;

#pragma warning(disable:4996)
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
float cam_x = 0.0, cam_y = -0.5, cam_z = 3.0;
//gravity
int double_jump_mode = 0;
int jump = 0;
int first_j = 0;
float v_start = 0.015;
float v = 0.0;
float x = 0.0;
float gravity = 0.0005;
float t = 0.0;
float t_g = 0.1;
float jj = 0.0;
//fire
int fire = 0;
int first_fire = 0;
float fire_start_x;
float fire_start_y;
float fire_start_z;
float fire_dis_x;
float fire_dis_y;
float fire_dis_z;
float fire_x = 0.0;
float fire_y = 0.0;
float fire_z = 0.0;
float distancef = 0.0;
float fire_total_t;
float fire_v = 0.05;
float t_f = 0.1;
float fire_t = 0.0;
//fire_hand_animation
GLfloat rotate_fire_angle = 0.0;
int rotate_fire = 0;
//material
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
GLfloat mat_diffuse[] = { 0.8, 0.8, 0.2, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat no_shininess[] = { 0.0 };
GLfloat low_shininess[] = { 1.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };
GLfloat mat_f0[] = { 255. / 255., 102. / 255., 0. ,1.0 };
GLfloat mat_diffuse_f0[] = { 255. / 255., 102. / 255., 0. , 1.0 };
GLfloat mat_f1[] = { 178. / 255., 255. / 255., 0., 1.0 };
GLfloat mat_diffuse_f1[] = { 178. / 255., 255. / 255., 0., 1.0 };
GLfloat mat_f2[] = { 70. / 255., 117. / 255., 0., 1.0 };
GLfloat mat_diffuse_f2[] = { 70. / 255., 117. / 255., 0., 1.0 };
GLfloat mat_f3[] = { 0., 102. / 255., 204. / 255., 1.0 };
GLfloat mat_diffuse_f3[] = { 0., 102. / 255., 204. / 255., 1.0 };
GLfloat mat_f4[] = { 174. / 255., 86. / 255., 164. / 255., 1.0 };
GLfloat mat_diffuse_f4[] = { 174. / 255., 86. / 255., 164. / 255., 1.0 };
GLfloat mat_earth[] = { 41. / 255., 41. / 255., 255. / 255. ,1.0 };
GLfloat mat_diffuse_earth[] = { 41. / 255., 41. / 255., 255. / 255. ,1.0 };

//swing arm
GLfloat rotate_arm_angle = 0.0;
int rotate_arm = 0;
//hit
int hit[60];
//anti-aliasing
int bgtoggle = 0;
//fog
int fogmode = 0;
//snipe
int snipemode = 0;
float snipe_z = 0.0;
float snipe_distance = -1.4;
//polyoffset
int offsetmode = 0;
GLfloat polyfactor = 9.0;
GLfloat polyunits = 5.0;
////obj

float myhealth = 20.0;
float nyhealth_rm = 20.0;
float mydamage = 3.0;
int alive = 1;
//enemy1
GLuint list_1;
float enemy1_x = -2.0;
float enemy1_z = 0.0;
float enemy1_h = 12.0;
float enemy1_rh = 12.0;
float enemy1_speed = 0.001;
float enemy1_damage = 3.0;
float enemy1_hitbox = 0.8;
int enemy1_alive = 1;
GLfloat enemy1_dir[2];

//enemy2
GLuint list_2;
float enemy2_x = 5.0;
float enemy2_z = -5.0;
float enemy2_h = 20.0;
float enemy2_rh = 20.0;
float enemy2_speed = 0.001;
float enemy2_damage = 2.0;
float enemy2_hitbox = 0.4;
int enemy2_alive = 1;
GLfloat enemy2_dir[2];
//enemy3
GLuint list_3;
float enemy3_x = 0.0;
float enemy3_z = -4.0;
float enemy3_h = 8.0;
float enemy3_rh = 8.0;
float enemy3_speed = 0.001;
float enemy3_damage = 4.0;
float enemy3_hitbox = 0.5;
int enemy3_alive = 1;
GLfloat enemy3_dir[2];
/*
      glm.c
      Nate Robins, 1997
      ndr@pobox.com, http://www.pobox.com/~ndr/

      Wavefront OBJ model file format reader/writer/manipulator.

      Includes routines for generating smooth normals with
      preservation of edges, welding redundant vertices & texture
      coordinate generation (spheremap and planar projections) + more.

 */





 /* _GLMnode: general purpose node
  */
typedef struct _GLMnode {
    GLuint           index;
    GLboolean        averaged;
    struct _GLMnode* next;
} GLMnode;


/* glmMax: returns the maximum of two floats */
static GLfloat
glmMax(GLfloat a, GLfloat b)
{
    if (b > a)
        return b;
    return a;
}

/* glmAbs: returns the absolute value of a float */
static GLfloat
glmAbs(GLfloat f)
{
    if (f < 0)
        return -f;
    return f;
}

/* glmDot: compute the dot product of two vectors
 *
 * u - array of 3 GLfloats (GLfloat u[3])
 * v - array of 3 GLfloats (GLfloat v[3])
 */
static GLfloat
glmDot(GLfloat* u, GLfloat* v)
{
    assert(u); assert(v);

    return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

/* glmCross: compute the cross product of two vectors
 *
 * u - array of 3 GLfloats (GLfloat u[3])
 * v - array of 3 GLfloats (GLfloat v[3])
 * n - array of 3 GLfloats (GLfloat n[3]) to return the cross product in
 */
static GLvoid
glmCross(GLfloat* u, GLfloat* v, GLfloat* n)
{
    assert(u); assert(v); assert(n);

    n[0] = u[1] * v[2] - u[2] * v[1];
    n[1] = u[2] * v[0] - u[0] * v[2];
    n[2] = u[0] * v[1] - u[1] * v[0];
}

/* glmNormalize: normalize a vector
 *
 * v - array of 3 GLfloats (GLfloat v[3]) to be normalized
 */
static GLvoid
glmNormalize(GLfloat* v)
{
    GLfloat l;

    assert(v);

    l = (GLfloat)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    v[0] /= l;
    v[1] /= l;
    v[2] /= l;
}

/* glmEqual: compares two vectors and returns GL_TRUE if they are
 * equal (within a certain threshold) or GL_FALSE if not. An epsilon
 * that works fairly well is 0.000001.
 *
 * u - array of 3 GLfloats (GLfloat u[3])
 * v - array of 3 GLfloats (GLfloat v[3])
 */
static GLboolean
glmEqual(GLfloat* u, GLfloat* v, GLfloat epsilon)
{
    if (glmAbs(u[0] - v[0]) < epsilon &&
        glmAbs(u[1] - v[1]) < epsilon &&
        glmAbs(u[2] - v[2]) < epsilon)
    {
        return GL_TRUE;
    }
    return GL_FALSE;
}

/* glmWeldVectors: eliminate (weld) vectors that are within an
 * epsilon of each other.
 *
 * vectors    - array of GLfloat[3]'s to be welded
 * numvectors - number of GLfloat[3]'s in vectors
 * epsilon    - maximum difference between vectors
 *
 */
GLfloat*
glmWeldVectors(GLfloat* vectors, GLuint* numvectors, GLfloat epsilon)
{
    GLfloat* copies;
    GLuint   copied;
    GLuint   i, j;

    copies = (GLfloat*)malloc(sizeof(GLfloat) * 3 * (*numvectors + 1));
    memcpy(copies, vectors, (sizeof(GLfloat) * 3 * (*numvectors + 1)));

    copied = 1;
    for (i = 1; i <= *numvectors; i++) {
        for (j = 1; j <= copied; j++) {
            if (glmEqual(&vectors[3 * i], &copies[3 * j], epsilon)) {
                goto duplicate;
            }
        }

        /* must not be any duplicates -- add to the copies array */
        copies[3 * copied + 0] = vectors[3 * i + 0];
        copies[3 * copied + 1] = vectors[3 * i + 1];
        copies[3 * copied + 2] = vectors[3 * i + 2];
        j = copied;				/* pass this along for below */
        copied++;

    duplicate:
        /* set the first component of this vector to point at the correct
           index into the new copies array */
        vectors[3 * i + 0] = (GLfloat)j;
    }

    *numvectors = copied - 1;
    return copies;
}

/* glmFindGroup: Find a group in the model
 */
GLMgroup*
glmFindGroup(GLMmodel* model, char* name)
{
    GLMgroup* group;

    assert(model);

    group = model->groups;
    while (group) {
        if (!strcmp(name, group->name))
            break;
        group = group->next;
    }

    return group;
}

/* glmAddGroup: Add a group to the model
 */
GLMgroup*
glmAddGroup(GLMmodel* model, char* name)
{
    GLMgroup* group;

    group = glmFindGroup(model, name);
    if (!group) {
        group = (GLMgroup*)malloc(sizeof(GLMgroup));
        group->name = strdup(name);
        group->material = 0;
        group->numtriangles = 0;
        group->triangles = NULL;
        group->next = model->groups;
        model->groups = group;
        model->numgroups++;
    }

    return group;
}

/* glmFindGroup: Find a material in the model
 */
GLuint
glmFindMaterial(GLMmodel* model, char* name)
{
    GLuint i;

    /* XXX doing a linear search on a string key'd list is pretty lame,
       but it works and is fast enough for now. */
    for (i = 0; i < model->nummaterials; i++) {
        if (!strcmp(model->materials[i].name, name))
            goto found;
    }

    /* didn't find the name, so print a warning and return the default
       material (0). */
    printf("glmFindMaterial():  can't find material \"%s\".\n", name);
    i = 0;

found:
    return i;
}


/* glmDirName: return the directory given a path
 *
 * path - filesystem path
 *
 * NOTE: the return value should be free'd.
 */
static char*
glmDirName(char* path)
{
    char* dir;
    char* s;

    dir = strdup(path);

    s = strrchr(dir, '/');
    if (s)
        s[1] = '\0';
    else
        dir[0] = '\0';

    return dir;
}


/* glmReadMTL: read a wavefront material library file
 *
 * model - properly initialized GLMmodel structure
 * name  - name of the material library
 */
static GLvoid
glmReadMTL(GLMmodel* model, char* name)
{
    FILE* file;
    char* dir;
    char* filename;
    char  buf[128];
    GLuint nummaterials, i;

    dir = glmDirName(model->pathname);
    filename = (char*)malloc(sizeof(char) * (strlen(dir) + strlen(name) + 1));
    strcpy(filename, dir);
    strcat(filename, name);
    free(dir);

    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "glmReadMTL() failed: can't open material file \"%s\".\n",
            filename);
        exit(1);
    }
    free(filename);

    /* count the number of materials in the file */
    nummaterials = 1;
    while (fscanf(file, "%s", buf) != EOF) {
        switch (buf[0]) {
        case '#':				/* comment */
          /* eat up rest of line */
            fgets(buf, sizeof(buf), file);
            break;
        case 'n':				/* newmtl */
            fgets(buf, sizeof(buf), file);
            nummaterials++;
            sscanf(buf, "%s %s", buf, buf);
            break;
        default:
            /* eat up rest of line */
            fgets(buf, sizeof(buf), file);
            break;
        }
    }

    rewind(file);

    model->materials = (GLMmaterial*)malloc(sizeof(GLMmaterial) * nummaterials);
    model->nummaterials = nummaterials;

    /* set the default material */
    for (i = 0; i < nummaterials; i++) {
        model->materials[i].name = NULL;
        model->materials[i].shininess = 65.0;
        model->materials[i].diffuse[0] = 0.8;
        model->materials[i].diffuse[1] = 0.8;
        model->materials[i].diffuse[2] = 0.8;
        model->materials[i].diffuse[3] = 1.0;
        model->materials[i].ambient[0] = 0.2;
        model->materials[i].ambient[1] = 0.2;
        model->materials[i].ambient[2] = 0.2;
        model->materials[i].ambient[3] = 1.0;
        model->materials[i].specular[0] = 0.0;
        model->materials[i].specular[1] = 0.0;
        model->materials[i].specular[2] = 0.0;
        model->materials[i].specular[3] = 1.0;
    }
    model->materials[0].name = strdup("default");

    /* now, read in the data */
    nummaterials = 0;
    while (fscanf(file, "%s", buf) != EOF) {
        switch (buf[0]) {
        case '#':				/* comment */
          /* eat up rest of line */
            fgets(buf, sizeof(buf), file);
            break;
        case 'n':				/* newmtl */
            fgets(buf, sizeof(buf), file);
            sscanf(buf, "%s %s", buf, buf);
            nummaterials++;
            model->materials[nummaterials].name = strdup(buf);
            break;
        case 'N':
            fscanf(file, "%f", &model->materials[nummaterials].shininess);
            /* wavefront shininess is from [0, 1000], so scale for OpenGL */
            model->materials[nummaterials].shininess /= 1000.0;
            model->materials[nummaterials].shininess *= 128.0;
            break;
        case 'K':
            switch (buf[1]) {
            case 'd':
                fscanf(file, "%f %f %f",
                    &model->materials[nummaterials].diffuse[0],
                    &model->materials[nummaterials].diffuse[1],
                    &model->materials[nummaterials].diffuse[2]);
                break;
            case 's':
                fscanf(file, "%f %f %f",
                    &model->materials[nummaterials].specular[0],
                    &model->materials[nummaterials].specular[1],
                    &model->materials[nummaterials].specular[2]);
                break;
            case 'a':
                fscanf(file, "%f %f %f",
                    &model->materials[nummaterials].ambient[0],
                    &model->materials[nummaterials].ambient[1],
                    &model->materials[nummaterials].ambient[2]);
                break;
            default:
                /* eat up rest of line */
                fgets(buf, sizeof(buf), file);
                break;
            }
            break;
        default:
            /* eat up rest of line */
            fgets(buf, sizeof(buf), file);
            break;
        }
    }
}

/* glmWriteMTL: write a wavefront material library file
 *
 * model      - properly initialized GLMmodel structure
 * modelpath  - pathname of the model being written
 * mtllibname - name of the material library to be written
 */
static GLvoid
glmWriteMTL(GLMmodel* model, char* modelpath, char* mtllibname)
{
    FILE* file;
    char* dir;
    char* filename;
    GLMmaterial* material;
    GLuint i;

    dir = glmDirName(modelpath);
    filename = (char*)malloc(sizeof(char) * (strlen(dir) + strlen(mtllibname)));
    strcpy(filename, dir);
    strcat(filename, mtllibname);
    free(dir);

    /* open the file */
    file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "glmWriteMTL() failed: can't open file \"%s\".\n",
            filename);
        exit(1);
    }
    free(filename);

    /* spit out a header */
    fprintf(file, "#  \n");
    fprintf(file, "#  Wavefront MTL generated by GLM library\n");
    fprintf(file, "#  \n");
    fprintf(file, "#  GLM library\n");
    fprintf(file, "#  Nate Robins\n");
    fprintf(file, "#  ndr@pobox.com\n");
    fprintf(file, "#  http://www.pobox.com/~ndr\n");
    fprintf(file, "#  \n\n");

    for (i = 0; i < model->nummaterials; i++) {
        material = &model->materials[i];
        fprintf(file, "newmtl %s\n", material->name);
        fprintf(file, "Ka %f %f %f\n",
            material->ambient[0], material->ambient[1], material->ambient[2]);
        fprintf(file, "Kd %f %f %f\n",
            material->diffuse[0], material->diffuse[1], material->diffuse[2]);
        fprintf(file, "Ks %f %f %f\n",
            material->specular[0], material->specular[1], material->specular[2]);
        fprintf(file, "Ns %f\n", material->shininess / 128.0 * 1000.0);
        fprintf(file, "\n");
    }
}


/* glmFirstPass: first pass at a Wavefront OBJ file that gets all the
 * statistics of the model (such as #vertices, #normals, etc)
 *
 * model - properly initialized GLMmodel structure
 * file  - (fopen'd) file descriptor
 */
static GLvoid
glmFirstPass(GLMmodel* model, FILE* file)
{
    GLuint    numvertices;		/* number of vertices in model */
    GLuint    numnormals;			/* number of normals in model */
    GLuint    numtexcoords;		/* number of texcoords in model */
    GLuint    numtriangles;		/* number of triangles in model */
    GLMgroup* group;			/* current group */
    unsigned  v, n, t;
    char      buf[128];

    /* make a default group */
    char fff[10] = {0};
    strcpy(fff, "default");
    group = glmAddGroup(model, fff);

    numvertices = numnormals = numtexcoords = numtriangles = 0;
    while (fscanf(file, "%s", buf) != EOF) {
        switch (buf[0]) {
        case '#':				/* comment */
          /* eat up rest of line */
            fgets(buf, sizeof(buf), file);
            break;
        case 'v':				/* v, vn, vt */
            switch (buf[1]) {
            case '\0':			/* vertex */
          /* eat up rest of line */
                fgets(buf, sizeof(buf), file);
                numvertices++;
                break;
            case 'n':				/* normal */
          /* eat up rest of line */
                fgets(buf, sizeof(buf), file);
                numnormals++;
                break;
            case 't':				/* texcoord */
          /* eat up rest of line */
                fgets(buf, sizeof(buf), file);
                numtexcoords++;
                break;
            default:
                printf("glmFirstPass(): Unknown token \"%s\".\n", buf);
                exit(1);
                break;
            }
            break;
        case 'm':
            fgets(buf, sizeof(buf), file);
            sscanf(buf, "%s %s", buf, buf);
            model->mtllibname = strdup(buf);
            glmReadMTL(model, buf);
            break;
        case 'u':
            /* eat up rest of line */
            fgets(buf, sizeof(buf), file);
            break;
        case 'g':				/* group */
          /* eat up rest of line */
            fgets(buf, sizeof(buf), file);
#if SINGLE_STRING_GROUP_NAMES
            sscanf(buf, "%s", buf);
#else
            buf[strlen(buf) - 1] = '\0';	/* nuke '\n' */
#endif
            group = glmAddGroup(model, buf);
            break;
        case 'f':				/* face */
            v = n = t = 0;
            fscanf(file, "%s", buf);
            /* can be one of %d, %d//%d, %d/%d, %d/%d/%d %d//%d */
            if (strstr(buf, "//")) {
                /* v//n */
                sscanf(buf, "%d//%d", &v, &n);
                fscanf(file, "%d//%d", &v, &n);
                fscanf(file, "%d//%d", &v, &n);
                numtriangles++;
                group->numtriangles++;
                while (fscanf(file, "%d//%d", &v, &n) > 0) {
                    numtriangles++;
                    group->numtriangles++;
                }
            }
            else if (sscanf(buf, "%d/%d/%d", &v, &t, &n) == 3) {
                /* v/t/n */
                fscanf(file, "%d/%d/%d", &v, &t, &n);
                fscanf(file, "%d/%d/%d", &v, &t, &n);
                numtriangles++;
                group->numtriangles++;
                while (fscanf(file, "%d/%d/%d", &v, &t, &n) > 0) {
                    numtriangles++;
                    group->numtriangles++;
                }
            }
            else if (sscanf(buf, "%d/%d", &v, &t) == 2) {
                /* v/t */
                fscanf(file, "%d/%d", &v, &t);
                fscanf(file, "%d/%d", &v, &t);
                numtriangles++;
                group->numtriangles++;
                while (fscanf(file, "%d/%d", &v, &t) > 0) {
                    numtriangles++;
                    group->numtriangles++;
                }
            }
            else {
                /* v */
                fscanf(file, "%d", &v);
                fscanf(file, "%d", &v);
                numtriangles++;
                group->numtriangles++;
                while (fscanf(file, "%d", &v) > 0) {
                    numtriangles++;
                    group->numtriangles++;
                }
            }
            break;

        default:
            /* eat up rest of line */
            fgets(buf, sizeof(buf), file);
            break;
        }
    }

    /* set the stats in the model structure */
    model->numvertices = numvertices;
    model->numnormals = numnormals;
    model->numtexcoords = numtexcoords;
    model->numtriangles = numtriangles;

    /* allocate memory for the triangles in each group */
    group = model->groups;
    while (group) {
        group->triangles = (GLuint*)malloc(sizeof(GLuint) * group->numtriangles);
        group->numtriangles = 0;
        group = group->next;
    }
}

/* glmSecondPass: second pass at a Wavefront OBJ file that gets all
 * the data.
 *
 * model - properly initialized GLMmodel structure
 * file  - (fopen'd) file descriptor
 */
static GLvoid
glmSecondPass(GLMmodel* model, FILE* file)
{
    GLuint    numvertices;		/* number of vertices in model */
    GLuint    numnormals;			/* number of normals in model */
    GLuint    numtexcoords;		/* number of texcoords in model */
    GLuint    numtriangles;		/* number of triangles in model */
    GLfloat* vertices;			/* array of vertices  */
    GLfloat* normals;			/* array of normals */
    GLfloat* texcoords;			/* array of texture coordinates */
    GLMgroup* group;			/* current group pointer */
    GLuint    material;			/* current material */
    GLuint    v, n, t;
    char      buf[128];

    /* set the pointer shortcuts */
    vertices = model->vertices;
    normals = model->normals;
    texcoords = model->texcoords;
    group = model->groups;

    /* on the second pass through the file, read all the data into the
       allocated arrays */
    numvertices = numnormals = numtexcoords = 1;
    numtriangles = 0;
    material = 0;
    while (fscanf(file, "%s", buf) != EOF) {
        switch (buf[0]) {
        case '#':				/* comment */
          /* eat up rest of line */
            fgets(buf, sizeof(buf), file);
            break;
        case 'v':				/* v, vn, vt */
            switch (buf[1]) {
            case '\0':			/* vertex */
                fscanf(file, "%f %f %f",
                    &vertices[3 * numvertices + 0],
                    &vertices[3 * numvertices + 1],
                    &vertices[3 * numvertices + 2]);
                numvertices++;
                break;
            case 'n':				/* normal */
                fscanf(file, "%f %f %f",
                    &normals[3 * numnormals + 0],
                    &normals[3 * numnormals + 1],
                    &normals[3 * numnormals + 2]);
                numnormals++;
                break;
            case 't':				/* texcoord */
                fscanf(file, "%f %f",
                    &texcoords[2 * numtexcoords + 0],
                    &texcoords[2 * numtexcoords + 1]);
                numtexcoords++;
                break;
            }
            break;
        case 'u':
            fgets(buf, sizeof(buf), file);
            sscanf(buf, "%s %s", buf, buf);
            group->material = material = glmFindMaterial(model, buf);
            break;
        case 'g':				/* group */
          /* eat up rest of line */
            fgets(buf, sizeof(buf), file);
#if SINGLE_STRING_GROUP_NAMES
            sscanf(buf, "%s", buf);
#else
            buf[strlen(buf) - 1] = '\0';	/* nuke '\n' */
#endif
            group = glmFindGroup(model, buf);
            group->material = material;
            break;
        case 'f':				/* face */
            v = n = t = 0;
            fscanf(file, "%s", buf);
            /* can be one of %d, %d//%d, %d/%d, %d/%d/%d %d//%d */
            if (strstr(buf, "//")) {
                /* v//n */
                sscanf(buf, "%d//%d", &v, &n);
                T(numtriangles).vindices[0] = v;
                T(numtriangles).nindices[0] = n;
                fscanf(file, "%d//%d", &v, &n);
                T(numtriangles).vindices[1] = v;
                T(numtriangles).nindices[1] = n;
                fscanf(file, "%d//%d", &v, &n);
                T(numtriangles).vindices[2] = v;
                T(numtriangles).nindices[2] = n;
                group->triangles[group->numtriangles++] = numtriangles;
                numtriangles++;
                while (fscanf(file, "%d//%d", &v, &n) > 0) {
                    T(numtriangles).vindices[0] = T(numtriangles - 1).vindices[0];
                    T(numtriangles).nindices[0] = T(numtriangles - 1).nindices[0];
                    T(numtriangles).vindices[1] = T(numtriangles - 1).vindices[2];
                    T(numtriangles).nindices[1] = T(numtriangles - 1).nindices[2];
                    T(numtriangles).vindices[2] = v;
                    T(numtriangles).nindices[2] = n;
                    group->triangles[group->numtriangles++] = numtriangles;
                    numtriangles++;
                }
            }
            else if (sscanf(buf, "%d/%d/%d", &v, &t, &n) == 3) {
                /* v/t/n */
                T(numtriangles).vindices[0] = v;
                T(numtriangles).tindices[0] = t;
                T(numtriangles).nindices[0] = n;
                fscanf(file, "%d/%d/%d", &v, &t, &n);
                T(numtriangles).vindices[1] = v;
                T(numtriangles).tindices[1] = t;
                T(numtriangles).nindices[1] = n;
                fscanf(file, "%d/%d/%d", &v, &t, &n);
                T(numtriangles).vindices[2] = v;
                T(numtriangles).tindices[2] = t;
                T(numtriangles).nindices[2] = n;
                group->triangles[group->numtriangles++] = numtriangles;
                numtriangles++;
                while (fscanf(file, "%d/%d/%d", &v, &t, &n) > 0) {
                    T(numtriangles).vindices[0] = T(numtriangles - 1).vindices[0];
                    T(numtriangles).tindices[0] = T(numtriangles - 1).tindices[0];
                    T(numtriangles).nindices[0] = T(numtriangles - 1).nindices[0];
                    T(numtriangles).vindices[1] = T(numtriangles - 1).vindices[2];
                    T(numtriangles).tindices[1] = T(numtriangles - 1).tindices[2];
                    T(numtriangles).nindices[1] = T(numtriangles - 1).nindices[2];
                    T(numtriangles).vindices[2] = v;
                    T(numtriangles).tindices[2] = t;
                    T(numtriangles).nindices[2] = n;
                    group->triangles[group->numtriangles++] = numtriangles;
                    numtriangles++;
                }
            }
            else if (sscanf(buf, "%d/%d", &v, &t) == 2) {
                /* v/t */
                T(numtriangles).vindices[0] = v;
                T(numtriangles).tindices[0] = t;
                fscanf(file, "%d/%d", &v, &t);
                T(numtriangles).vindices[1] = v;
                T(numtriangles).tindices[1] = t;
                fscanf(file, "%d/%d", &v, &t);
                T(numtriangles).vindices[2] = v;
                T(numtriangles).tindices[2] = t;
                group->triangles[group->numtriangles++] = numtriangles;
                numtriangles++;
                while (fscanf(file, "%d/%d", &v, &t) > 0) {
                    T(numtriangles).vindices[0] = T(numtriangles - 1).vindices[0];
                    T(numtriangles).tindices[0] = T(numtriangles - 1).tindices[0];
                    T(numtriangles).vindices[1] = T(numtriangles - 1).vindices[2];
                    T(numtriangles).tindices[1] = T(numtriangles - 1).tindices[2];
                    T(numtriangles).vindices[2] = v;
                    T(numtriangles).tindices[2] = t;
                    group->triangles[group->numtriangles++] = numtriangles;
                    numtriangles++;
                }
            }
            else {
                /* v */
                sscanf(buf, "%d", &v);
                T(numtriangles).vindices[0] = v;
                fscanf(file, "%d", &v);
                T(numtriangles).vindices[1] = v;
                fscanf(file, "%d", &v);
                T(numtriangles).vindices[2] = v;
                group->triangles[group->numtriangles++] = numtriangles;
                numtriangles++;
                while (fscanf(file, "%d", &v) > 0) {
                    T(numtriangles).vindices[0] = T(numtriangles - 1).vindices[0];
                    T(numtriangles).vindices[1] = T(numtriangles - 1).vindices[2];
                    T(numtriangles).vindices[2] = v;
                    group->triangles[group->numtriangles++] = numtriangles;
                    numtriangles++;
                }
            }
            break;

        default:
            /* eat up rest of line */
            fgets(buf, sizeof(buf), file);
            break;
        }
    }

#if 0
    /* announce the memory requirements */
    printf(" Memory: %d bytes\n",
        numvertices * 3 * sizeof(GLfloat) +
        numnormals * 3 * sizeof(GLfloat) * (numnormals ? 1 : 0) +
        numtexcoords * 3 * sizeof(GLfloat) * (numtexcoords ? 1 : 0) +
        numtriangles * sizeof(GLMtriangle));
#endif
}


/* public functions */


/* glmUnitize: "unitize" a model by translating it to the origin and
 * scaling it to fit in a unit cube around the origin.  Returns the
 * scalefactor used.
 *
 * model - properly initialized GLMmodel structure
 */
GLfloat
glmUnitize(GLMmodel* model)
{
    GLuint  i;
    GLfloat maxx, minx, maxy, miny, maxz, minz;
    GLfloat cx, cy, cz, w, h, d;
    GLfloat scale;

    assert(model);
    assert(model->vertices);

    /* get the max/mins */
    maxx = minx = model->vertices[3 + 0];
    maxy = miny = model->vertices[3 + 1];
    maxz = minz = model->vertices[3 + 2];
    for (i = 1; i <= model->numvertices; i++) {
        if (maxx < model->vertices[3 * i + 0])
            maxx = model->vertices[3 * i + 0];
        if (minx > model->vertices[3 * i + 0])
            minx = model->vertices[3 * i + 0];

        if (maxy < model->vertices[3 * i + 1])
            maxy = model->vertices[3 * i + 1];
        if (miny > model->vertices[3 * i + 1])
            miny = model->vertices[3 * i + 1];

        if (maxz < model->vertices[3 * i + 2])
            maxz = model->vertices[3 * i + 2];
        if (minz > model->vertices[3 * i + 2])
            minz = model->vertices[3 * i + 2];
    }

    /* calculate model width, height, and depth */
    w = glmAbs(maxx) + glmAbs(minx);
    h = glmAbs(maxy) + glmAbs(miny);
    d = glmAbs(maxz) + glmAbs(minz);

    /* calculate center of the model */
    cx = (maxx + minx) / 2.0;
    cy = (maxy + miny) / 2.0;
    cz = (maxz + minz) / 2.0;

    /* calculate unitizing scale factor */
    scale = 2.0 / glmMax(glmMax(w, h), d);

    /* translate around center then scale */
    for (i = 1; i <= model->numvertices; i++) {
        model->vertices[3 * i + 0] -= cx;
        model->vertices[3 * i + 1] -= cy;
        model->vertices[3 * i + 2] -= cz;
        model->vertices[3 * i + 0] *= scale;
        model->vertices[3 * i + 1] *= scale;
        model->vertices[3 * i + 2] *= scale;
    }

    return scale;
}

/* glmDimensions: Calculates the dimensions (width, height, depth) of
 * a model.
 *
 * model      - initialized GLMmodel structure
 * dimensions - array of 3 GLfloats (GLfloat dimensions[3])
 */
GLvoid
glmDimensions(GLMmodel* model, GLfloat* dimensions)
{
    GLuint i;
    GLfloat maxx, minx, maxy, miny, maxz, minz;

    assert(model);
    assert(model->vertices);
    assert(dimensions);

    /* get the max/mins */
    maxx = minx = model->vertices[3 + 0];
    maxy = miny = model->vertices[3 + 1];
    maxz = minz = model->vertices[3 + 2];
    for (i = 1; i <= model->numvertices; i++) {
        if (maxx < model->vertices[3 * i + 0])
            maxx = model->vertices[3 * i + 0];
        if (minx > model->vertices[3 * i + 0])
            minx = model->vertices[3 * i + 0];

        if (maxy < model->vertices[3 * i + 1])
            maxy = model->vertices[3 * i + 1];
        if (miny > model->vertices[3 * i + 1])
            miny = model->vertices[3 * i + 1];

        if (maxz < model->vertices[3 * i + 2])
            maxz = model->vertices[3 * i + 2];
        if (minz > model->vertices[3 * i + 2])
            minz = model->vertices[3 * i + 2];
    }

    /* calculate model width, height, and depth */
    dimensions[0] = glmAbs(maxx) + glmAbs(minx);
    dimensions[1] = glmAbs(maxy) + glmAbs(miny);
    dimensions[2] = glmAbs(maxz) + glmAbs(minz);
}

/* glmScale: Scales a model by a given amount.
 *
 * model - properly initialized GLMmodel structure
 * scale - scalefactor (0.5 = half as large, 2.0 = twice as large)
 */
GLvoid
glmScale(GLMmodel* model, GLfloat scale)
{
    GLuint i;

    for (i = 1; i <= model->numvertices; i++) {
        model->vertices[3 * i + 0] *= scale;
        model->vertices[3 * i + 1] *= scale;
        model->vertices[3 * i + 2] *= scale;
    }
}

/* glmReverseWinding: Reverse the polygon winding for all polygons in
 * this model.  Default winding is counter-clockwise.  Also changes
 * the direction of the normals.
 *
 * model - properly initialized GLMmodel structure
 */
GLvoid
glmReverseWinding(GLMmodel* model)
{
    GLuint i, swap;

    assert(model);

    for (i = 0; i < model->numtriangles; i++) {
        swap = T(i).vindices[0];
        T(i).vindices[0] = T(i).vindices[2];
        T(i).vindices[2] = swap;

        if (model->numnormals) {
            swap = T(i).nindices[0];
            T(i).nindices[0] = T(i).nindices[2];
            T(i).nindices[2] = swap;
        }

        if (model->numtexcoords) {
            swap = T(i).tindices[0];
            T(i).tindices[0] = T(i).tindices[2];
            T(i).tindices[2] = swap;
        }
    }

    /* reverse facet normals */
    for (i = 1; i <= model->numfacetnorms; i++) {
        model->facetnorms[3 * i + 0] = -model->facetnorms[3 * i + 0];
        model->facetnorms[3 * i + 1] = -model->facetnorms[3 * i + 1];
        model->facetnorms[3 * i + 2] = -model->facetnorms[3 * i + 2];
    }

    /* reverse vertex normals */
    for (i = 1; i <= model->numnormals; i++) {
        model->normals[3 * i + 0] = -model->normals[3 * i + 0];
        model->normals[3 * i + 1] = -model->normals[3 * i + 1];
        model->normals[3 * i + 2] = -model->normals[3 * i + 2];
    }
}

/* glmFacetNormals: Generates facet normals for a model (by taking the
 * cross product of the two vectors derived from the sides of each
 * triangle).  Assumes a counter-clockwise winding.
 *
 * model - initialized GLMmodel structure
 */
GLvoid
glmFacetNormals(GLMmodel* model)
{
    GLuint  i;
    GLfloat u[3];
    GLfloat v[3];

    assert(model);
    assert(model->vertices);

    /* clobber any old facetnormals */
    if (model->facetnorms)
        free(model->facetnorms);

    /* allocate memory for the new facet normals */
    model->numfacetnorms = model->numtriangles;
    model->facetnorms = (GLfloat*)malloc(sizeof(GLfloat) *
        3 * (model->numfacetnorms + 1));

    for (i = 0; i < model->numtriangles; i++) {
        model->triangles[i].findex = i + 1;

        u[0] = model->vertices[3 * T(i).vindices[1] + 0] -
            model->vertices[3 * T(i).vindices[0] + 0];
        u[1] = model->vertices[3 * T(i).vindices[1] + 1] -
            model->vertices[3 * T(i).vindices[0] + 1];
        u[2] = model->vertices[3 * T(i).vindices[1] + 2] -
            model->vertices[3 * T(i).vindices[0] + 2];

        v[0] = model->vertices[3 * T(i).vindices[2] + 0] -
            model->vertices[3 * T(i).vindices[0] + 0];
        v[1] = model->vertices[3 * T(i).vindices[2] + 1] -
            model->vertices[3 * T(i).vindices[0] + 1];
        v[2] = model->vertices[3 * T(i).vindices[2] + 2] -
            model->vertices[3 * T(i).vindices[0] + 2];

        glmCross(u, v, &model->facetnorms[3 * (i + 1)]);
        glmNormalize(&model->facetnorms[3 * (i + 1)]);
    }
}

/* glmVertexNormals: Generates smooth vertex normals for a model.
 * First builds a list of all the triangles each vertex is in.  Then
 * loops through each vertex in the the list averaging all the facet
 * normals of the triangles each vertex is in.  Finally, sets the
 * normal index in the triangle for the vertex to the generated smooth
 * normal.  If the dot product of a facet normal and the facet normal
 * associated with the first triangle in the list of triangles the
 * current vertex is in is greater than the cosine of the angle
 * parameter to the function, that facet normal is not added into the
 * average normal calculation and the corresponding vertex is given
 * the facet normal.  This tends to preserve hard edges.  The angle to
 * use depends on the model, but 90 degrees is usually a good start.
 *
 * model - initialized GLMmodel structure
 * angle - maximum angle (in degrees) to smooth across
 */
GLvoid
glmVertexNormals(GLMmodel* model, GLfloat angle)
{
    GLMnode* node;
    GLMnode* tail;
    GLMnode** members;
    GLfloat* normals;
    GLuint    numnormals;
    GLfloat   average[3];
    GLfloat   dot, cos_angle;
    GLuint    i, avg;

    assert(model);
    assert(model->facetnorms);

    /* calculate the cosine of the angle (in degrees) */
    cos_angle = cos(angle * M_PI / 180.0);

    /* nuke any previous normals */
    if (model->normals)
        free(model->normals);

    /* allocate space for new normals */
    model->numnormals = model->numtriangles * 3; /* 3 normals per triangle */
    model->normals = (GLfloat*)malloc(sizeof(GLfloat) * 3 * (model->numnormals + 1));

    /* allocate a structure that will hold a linked list of triangle
       indices for each vertex */
    members = (GLMnode**)malloc(sizeof(GLMnode*) * (model->numvertices + 1));
    for (i = 1; i <= model->numvertices; i++)
        members[i] = NULL;

    /* for every triangle, create a node for each vertex in it */
    for (i = 0; i < model->numtriangles; i++) {
        node = (GLMnode*)malloc(sizeof(GLMnode));
        node->index = i;
        node->next = members[T(i).vindices[0]];
        members[T(i).vindices[0]] = node;

        node = (GLMnode*)malloc(sizeof(GLMnode));
        node->index = i;
        node->next = members[T(i).vindices[1]];
        members[T(i).vindices[1]] = node;

        node = (GLMnode*)malloc(sizeof(GLMnode));
        node->index = i;
        node->next = members[T(i).vindices[2]];
        members[T(i).vindices[2]] = node;
    }

    /* calculate the average normal for each vertex */
    numnormals = 1;
    for (i = 1; i <= model->numvertices; i++) {
        /* calculate an average normal for this vertex by averaging the
           facet normal of every triangle this vertex is in */
        node = members[i];
        if (!node)
            fprintf(stderr, "glmVertexNormals(): vertex w/o a triangle\n");
        average[0] = 0.0; average[1] = 0.0; average[2] = 0.0;
        avg = 0;
        while (node) {
            /* only average if the dot product of the angle between the two
               facet normals is greater than the cosine of the threshold
               angle -- or, said another way, the angle between the two
               facet normals is less than (or equal to) the threshold angle */
            dot = glmDot(&model->facetnorms[3 * T(node->index).findex],
                &model->facetnorms[3 * T(members[i]->index).findex]);
            if (dot > cos_angle) {
                node->averaged = GL_TRUE;
                average[0] += model->facetnorms[3 * T(node->index).findex + 0];
                average[1] += model->facetnorms[3 * T(node->index).findex + 1];
                average[2] += model->facetnorms[3 * T(node->index).findex + 2];
                avg = 1;			/* we averaged at least one normal! */
            }
            else {
                node->averaged = GL_FALSE;
            }
            node = node->next;
        }

        if (avg) {
            /* normalize the averaged normal */
            glmNormalize(average);

            /* add the normal to the vertex normals list */
            model->normals[3 * numnormals + 0] = average[0];
            model->normals[3 * numnormals + 1] = average[1];
            model->normals[3 * numnormals + 2] = average[2];
            avg = numnormals;
            numnormals++;
        }

        /* set the normal of this vertex in each triangle it is in */
        node = members[i];
        while (node) {
            if (node->averaged) {
                /* if this node was averaged, use the average normal */
                if (T(node->index).vindices[0] == i)
                    T(node->index).nindices[0] = avg;
                else if (T(node->index).vindices[1] == i)
                    T(node->index).nindices[1] = avg;
                else if (T(node->index).vindices[2] == i)
                    T(node->index).nindices[2] = avg;
            }
            else {
                /* if this node wasn't averaged, use the facet normal */
                model->normals[3 * numnormals + 0] =
                    model->facetnorms[3 * T(node->index).findex + 0];
                model->normals[3 * numnormals + 1] =
                    model->facetnorms[3 * T(node->index).findex + 1];
                model->normals[3 * numnormals + 2] =
                    model->facetnorms[3 * T(node->index).findex + 2];
                if (T(node->index).vindices[0] == i)
                    T(node->index).nindices[0] = numnormals;
                else if (T(node->index).vindices[1] == i)
                    T(node->index).nindices[1] = numnormals;
                else if (T(node->index).vindices[2] == i)
                    T(node->index).nindices[2] = numnormals;
                numnormals++;
            }
            node = node->next;
        }
    }

    model->numnormals = numnormals - 1;

    /* free the member information */
    for (i = 1; i <= model->numvertices; i++) {
        node = members[i];
        while (node) {
            tail = node;
            node = node->next;
            free(tail);
        }
    }
    free(members);

    /* pack the normals array (we previously allocated the maximum
       number of normals that could possibly be created (numtriangles *
       3), so get rid of some of them (usually alot unless none of the
       facet normals were averaged)) */
    normals = model->normals;
    model->normals = (GLfloat*)malloc(sizeof(GLfloat) * 3 * (model->numnormals + 1));
    for (i = 1; i <= model->numnormals; i++) {
        model->normals[3 * i + 0] = normals[3 * i + 0];
        model->normals[3 * i + 1] = normals[3 * i + 1];
        model->normals[3 * i + 2] = normals[3 * i + 2];
    }
    free(normals);
}


/* glmLinearTexture: Generates texture coordinates according to a
 * linear projection of the texture map.  It generates these by
 * linearly mapping the vertices onto a square.
 *
 * model - pointer to initialized GLMmodel structure
 */
GLvoid
glmLinearTexture(GLMmodel* model)
{
    GLMgroup* group;
    GLfloat dimensions[3];
    GLfloat x, y, scalefactor;
    GLuint i;

    assert(model);

    if (model->texcoords)
        free(model->texcoords);
    model->numtexcoords = model->numvertices;
    model->texcoords = (GLfloat*)malloc(sizeof(GLfloat) * 2 * (model->numtexcoords + 1));

    glmDimensions(model, dimensions);
    scalefactor = 2.0 /
        glmAbs(glmMax(glmMax(dimensions[0], dimensions[1]), dimensions[2]));

    /* do the calculations */
    for (i = 1; i <= model->numvertices; i++) {
        x = model->vertices[3 * i + 0] * scalefactor;
        y = model->vertices[3 * i + 2] * scalefactor;
        model->texcoords[2 * i + 0] = (x + 1.0) / 2.0;
        model->texcoords[2 * i + 1] = (y + 1.0) / 2.0;
    }

    /* go through and put texture coordinate indices in all the triangles */
    group = model->groups;
    while (group) {
        for (i = 0; i < group->numtriangles; i++) {
            T(group->triangles[i]).tindices[0] = T(group->triangles[i]).vindices[0];
            T(group->triangles[i]).tindices[1] = T(group->triangles[i]).vindices[1];
            T(group->triangles[i]).tindices[2] = T(group->triangles[i]).vindices[2];
        }
        group = group->next;
    }

#if 0
    printf("glmLinearTexture(): generated %d linear texture coordinates\n",
        model->numtexcoords);
#endif
}

/* glmSpheremapTexture: Generates texture coordinates according to a
 * spherical projection of the texture map.  Sometimes referred to as
 * spheremap, or reflection map texture coordinates.  It generates
 * these by using the normal to calculate where that vertex would map
 * onto a sphere.  Since it is impossible to map something flat
 * perfectly onto something spherical, there is distortion at the
 * poles.  This particular implementation causes the poles along the X
 * axis to be distorted.
 *
 * model - pointer to initialized GLMmodel structure
 */
GLvoid
glmSpheremapTexture(GLMmodel* model)
{
    GLMgroup* group;
    GLfloat theta, phi, rho, x, y, z, r;
    GLuint i;

    assert(model);
    assert(model->normals);

    if (model->texcoords)
        free(model->texcoords);
    model->numtexcoords = model->numnormals;
    model->texcoords = (GLfloat*)malloc(sizeof(GLfloat) * 2 * (model->numtexcoords + 1));

    for (i = 1; i <= model->numnormals; i++) {
        z = model->normals[3 * i + 0];	/* re-arrange for pole distortion */
        y = model->normals[3 * i + 1];
        x = model->normals[3 * i + 2];
        r = sqrt((x * x) + (y * y));
        rho = sqrt((r * r) + (z * z));

        if (r == 0.0) {
            theta = 0.0;
            phi = 0.0;
        }
        else {
            if (z == 0.0)
                phi = 3.14159265 / 2.0;
            else
                phi = acos(z / rho);

            if (y == 0.0)
                theta = 3.141592365 / 2.0;
            else
                theta = asin(y / r) + (3.14159265 / 2.0);
        }

        model->texcoords[2 * i + 0] = theta / 3.14159265;
        model->texcoords[2 * i + 1] = phi / 3.14159265;
    }

    /* go through and put texcoord indices in all the triangles */
    group = model->groups;
    while (group) {
        for (i = 0; i < group->numtriangles; i++) {
            T(group->triangles[i]).tindices[0] = T(group->triangles[i]).nindices[0];
            T(group->triangles[i]).tindices[1] = T(group->triangles[i]).nindices[1];
            T(group->triangles[i]).tindices[2] = T(group->triangles[i]).nindices[2];
        }
        group = group->next;
    }
}

/* glmDelete: Deletes a GLMmodel structure.
 *
 * model - initialized GLMmodel structure
 */
GLvoid
glmDelete(GLMmodel* model)
{
    GLMgroup* group;
    GLuint i;

    assert(model);

    if (model->pathname)   free(model->pathname);
    if (model->mtllibname) free(model->mtllibname);
    if (model->vertices)   free(model->vertices);
    if (model->normals)    free(model->normals);
    if (model->texcoords)  free(model->texcoords);
    if (model->facetnorms) free(model->facetnorms);
    if (model->triangles)  free(model->triangles);
    if (model->materials) {
        for (i = 0; i < model->nummaterials; i++)
            free(model->materials[i].name);
    }
    free(model->materials);
    while (model->groups) {
        group = model->groups;
        model->groups = model->groups->next;
        free(group->name);
        free(group->triangles);
        free(group);
    }

    free(model);
}

/* glmReadOBJ: Reads a model description from a Wavefront .OBJ file.
 * Returns a pointer to the created object which should be free'd with
 * glmDelete().
 *
 * filename - name of the file containing the Wavefront .OBJ format data.
 */
GLMmodel*
glmReadOBJ(char* filename)
{
    GLMmodel* model;
    FILE* file;

    /* open the file */
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "glmReadOBJ() failed: can't open data file \"%s\".\n",
            filename);
        exit(1);
    }

    /* allocate a new model */
    model = (GLMmodel*)malloc(sizeof(GLMmodel));
    model->pathname = strdup(filename);
    model->mtllibname = NULL;
    model->numvertices = 0;
    model->vertices = NULL;
    model->numnormals = 0;
    model->normals = NULL;
    model->numtexcoords = 0;
    model->texcoords = NULL;
    model->numfacetnorms = 0;
    model->facetnorms = NULL;
    model->numtriangles = 0;
    model->triangles = NULL;
    model->nummaterials = 0;
    model->materials = NULL;
    model->numgroups = 0;
    model->groups = NULL;
    model->position[0] = 0.0;
    model->position[1] = 0.0;
    model->position[2] = 0.0;

    /* make a first pass through the file to get a count of the number
       of vertices, normals, texcoords & triangles */
    glmFirstPass(model, file);

    /* allocate memory */
    model->vertices = (GLfloat*)malloc(sizeof(GLfloat) *
        3 * (model->numvertices + 1));
    model->triangles = (GLMtriangle*)malloc(sizeof(GLMtriangle) *
        model->numtriangles);
    if (model->numnormals) {
        model->normals = (GLfloat*)malloc(sizeof(GLfloat) *
            3 * (model->numnormals + 1));
    }
    if (model->numtexcoords) {
        model->texcoords = (GLfloat*)malloc(sizeof(GLfloat) *
            2 * (model->numtexcoords + 1));
    }

    /* rewind to beginning of file and read in the data this pass */
    rewind(file);

    glmSecondPass(model, file);

    /* close the file */
    fclose(file);

    return model;
}

/* glmWriteOBJ: Writes a model description in Wavefront .OBJ format to
 * a file.
 *
 * model    - initialized GLMmodel structure
 * filename - name of the file to write the Wavefront .OBJ format data to
 * mode     - a bitwise or of values describing what is written to the file
 *            GLM_NONE     -  render with only vertices
 *            GLM_FLAT     -  render with facet normals
 *            GLM_SMOOTH   -  render with vertex normals
 *            GLM_TEXTURE  -  render with texture coords
 *            GLM_COLOR    -  render with colors (color material)
 *            GLM_MATERIAL -  render with materials
 *            GLM_COLOR and GLM_MATERIAL should not both be specified.
 *            GLM_FLAT and GLM_SMOOTH should not both be specified.
 */
GLvoid
glmWriteOBJ(GLMmodel* model, char* filename, GLuint mode)
{
    GLuint    i;
    FILE* file;
    GLMgroup* group;

    assert(model);

    /* do a bit of warning */
    if (mode & GLM_FLAT && !model->facetnorms) {
        printf("glmWriteOBJ() warning: flat normal output requested "
            "with no facet normals defined.\n");
        mode &= ~GLM_FLAT;
    }
    if (mode & GLM_SMOOTH && !model->normals) {
        printf("glmWriteOBJ() warning: smooth normal output requested "
            "with no normals defined.\n");
        mode &= ~GLM_SMOOTH;
    }
    if (mode & GLM_TEXTURE && !model->texcoords) {
        printf("glmWriteOBJ() warning: texture coordinate output requested "
            "with no texture coordinates defined.\n");
        mode &= ~GLM_TEXTURE;
    }
    if (mode & GLM_FLAT && mode & GLM_SMOOTH) {
        printf("glmWriteOBJ() warning: flat normal output requested "
            "and smooth normal output requested (using smooth).\n");
        mode &= ~GLM_FLAT;
    }
    if (mode & GLM_COLOR && !model->materials) {
        printf("glmWriteOBJ() warning: color output requested "
            "with no colors (materials) defined.\n");
        mode &= ~GLM_COLOR;
    }
    if (mode & GLM_MATERIAL && !model->materials) {
        printf("glmWriteOBJ() warning: material output requested "
            "with no materials defined.\n");
        mode &= ~GLM_MATERIAL;
    }
    if (mode & GLM_COLOR && mode & GLM_MATERIAL) {
        printf("glmWriteOBJ() warning: color and material output requested "
            "outputting only materials.\n");
        mode &= ~GLM_COLOR;
    }


    /* open the file */
    file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "glmWriteOBJ() failed: can't open file \"%s\" to write.\n",
            filename);
        exit(1);
    }

    /* spit out a header */
    fprintf(file, "#  \n");
    fprintf(file, "#  Wavefront OBJ generated by GLM library\n");
    fprintf(file, "#  \n");
    fprintf(file, "#  GLM library\n");
    fprintf(file, "#  Nate Robins\n");
    fprintf(file, "#  ndr@pobox.com\n");
    fprintf(file, "#  http://www.pobox.com/~ndr\n");
    fprintf(file, "#  \n");

    if (mode & GLM_MATERIAL && model->mtllibname) {
        fprintf(file, "\nmtllib %s\n\n", model->mtllibname);
        glmWriteMTL(model, filename, model->mtllibname);
    }

    /* spit out the vertices */
    fprintf(file, "\n");
    fprintf(file, "# %d vertices\n", model->numvertices);
    for (i = 1; i <= model->numvertices; i++) {
        fprintf(file, "v %f %f %f\n",
            model->vertices[3 * i + 0],
            model->vertices[3 * i + 1],
            model->vertices[3 * i + 2]);
    }

    /* spit out the smooth/flat normals */
    if (mode & GLM_SMOOTH) {
        fprintf(file, "\n");
        fprintf(file, "# %d normals\n", model->numnormals);
        for (i = 1; i <= model->numnormals; i++) {
            fprintf(file, "vn %f %f %f\n",
                model->normals[3 * i + 0],
                model->normals[3 * i + 1],
                model->normals[3 * i + 2]);
        }
    }
    else if (mode & GLM_FLAT) {
        fprintf(file, "\n");
        fprintf(file, "# %d normals\n", model->numfacetnorms);
        for (i = 1; i <= model->numnormals; i++) {
            fprintf(file, "vn %f %f %f\n",
                model->facetnorms[3 * i + 0],
                model->facetnorms[3 * i + 1],
                model->facetnorms[3 * i + 2]);
        }
    }

    /* spit out the texture coordinates */
    if (mode & GLM_TEXTURE) {
        fprintf(file, "\n");
        fprintf(file, "# %d texcoords\n", model->texcoords);
        for (i = 1; i <= model->numtexcoords; i++) {
            fprintf(file, "vt %f %f\n",
                model->texcoords[2 * i + 0],
                model->texcoords[2 * i + 1]);
        }
    }

    fprintf(file, "\n");
    fprintf(file, "# %d groups\n", model->numgroups);
    fprintf(file, "# %d faces (triangles)\n", model->numtriangles);
    fprintf(file, "\n");

    group = model->groups;
    while (group) {
        fprintf(file, "g %s\n", group->name);
        if (mode & GLM_MATERIAL)
            fprintf(file, "usemtl %s\n", model->materials[group->material].name);
        for (i = 0; i < group->numtriangles; i++) {
            if (mode & GLM_SMOOTH && mode & GLM_TEXTURE) {
                fprintf(file, "f %d/%d/%d %d/%d/%d %d/%d/%d\n",
                    T(group->triangles[i]).vindices[0],
                    T(group->triangles[i]).nindices[0],
                    T(group->triangles[i]).tindices[0],
                    T(group->triangles[i]).vindices[1],
                    T(group->triangles[i]).nindices[1],
                    T(group->triangles[i]).tindices[1],
                    T(group->triangles[i]).vindices[2],
                    T(group->triangles[i]).nindices[2],
                    T(group->triangles[i]).tindices[2]);
            }
            else if (mode & GLM_FLAT && mode & GLM_TEXTURE) {
                fprintf(file, "f %d/%d %d/%d %d/%d\n",
                    T(group->triangles[i]).vindices[0],
                    T(group->triangles[i]).findex,
                    T(group->triangles[i]).vindices[1],
                    T(group->triangles[i]).findex,
                    T(group->triangles[i]).vindices[2],
                    T(group->triangles[i]).findex);
            }
            else if (mode & GLM_TEXTURE) {
                fprintf(file, "f %d/%d %d/%d %d/%d\n",
                    T(group->triangles[i]).vindices[0],
                    T(group->triangles[i]).tindices[0],
                    T(group->triangles[i]).vindices[1],
                    T(group->triangles[i]).tindices[1],
                    T(group->triangles[i]).vindices[2],
                    T(group->triangles[i]).tindices[2]);
            }
            else if (mode & GLM_SMOOTH) {
                fprintf(file, "f %d//%d %d//%d %d//%d\n",
                    T(group->triangles[i]).vindices[0],
                    T(group->triangles[i]).nindices[0],
                    T(group->triangles[i]).vindices[1],
                    T(group->triangles[i]).nindices[1],
                    T(group->triangles[i]).vindices[2],
                    T(group->triangles[i]).nindices[2]);
            }
            else if (mode & GLM_FLAT) {
                fprintf(file, "f %d//%d %d//%d %d//%d\n",
                    T(group->triangles[i]).vindices[0],
                    T(group->triangles[i]).findex,
                    T(group->triangles[i]).vindices[1],
                    T(group->triangles[i]).findex,
                    T(group->triangles[i]).vindices[2],
                    T(group->triangles[i]).findex);
            }
            else {
                fprintf(file, "f %d %d %d\n",
                    T(group->triangles[i]).vindices[0],
                    T(group->triangles[i]).vindices[1],
                    T(group->triangles[i]).vindices[2]);
            }
        }
        fprintf(file, "\n");
        group = group->next;
    }

    fclose(file);
}

/* glmDraw: Renders the model to the current OpenGL context using the
 * mode specified.
 *
 * model    - initialized GLMmodel structure
 * mode     - a bitwise OR of values describing what is to be rendered.
 *            GLM_NONE     -  render with only vertices
 *            GLM_FLAT     -  render with facet normals
 *            GLM_SMOOTH   -  render with vertex normals
 *            GLM_TEXTURE  -  render with texture coords
 *            GLM_COLOR    -  render with colors (color material)
 *            GLM_MATERIAL -  render with materials
 *            GLM_COLOR and GLM_MATERIAL should not both be specified.
 *            GLM_FLAT and GLM_SMOOTH should not both be specified.
 */
GLvoid
glmDraw(GLMmodel* model, GLuint mode)
{
    static GLuint i;
    static GLMgroup* group;
    static GLMtriangle* triangle;
    static GLMmaterial* material;

    assert(model);
    assert(model->vertices);

    /* do a bit of warning */
    if (mode & GLM_FLAT && !model->facetnorms) {
        printf("glmDraw() warning: flat render mode requested "
            "with no facet normals defined.\n");
        mode &= ~GLM_FLAT;
    }
    if (mode & GLM_SMOOTH && !model->normals) {
        printf("glmDraw() warning: smooth render mode requested "
            "with no normals defined.\n");
        mode &= ~GLM_SMOOTH;
    }
    if (mode & GLM_TEXTURE && !model->texcoords) {
        printf("glmDraw() warning: texture render mode requested "
            "with no texture coordinates defined.\n");
        mode &= ~GLM_TEXTURE;
    }
    if (mode & GLM_FLAT && mode & GLM_SMOOTH) {
        printf("glmDraw() warning: flat render mode requested "
            "and smooth render mode requested (using smooth).\n");
        mode &= ~GLM_FLAT;
    }
    if (mode & GLM_COLOR && !model->materials) {
        printf("glmDraw() warning: color render mode requested "
            "with no materials defined.\n");
        mode &= ~GLM_COLOR;
    }
    if (mode & GLM_MATERIAL && !model->materials) {
        printf("glmDraw() warning: material render mode requested "
            "with no materials defined.\n");
        mode &= ~GLM_MATERIAL;
    }
    if (mode & GLM_COLOR && mode & GLM_MATERIAL) {
        printf("glmDraw() warning: color and material render mode requested "
            "using only material mode.\n");
        mode &= ~GLM_COLOR;
    }
    if (mode & GLM_COLOR)
        glEnable(GL_COLOR_MATERIAL);
    else if (mode & GLM_MATERIAL)
        glDisable(GL_COLOR_MATERIAL);

    /* perhaps this loop should be unrolled into material, color, flat,
       smooth, etc. loops?  since most cpu's have good branch prediction
       schemes (and these branches will always go one way), probably
       wouldn't gain too much?  */

    group = model->groups;
    while (group) {
        if (mode & GLM_MATERIAL) {
            material = &model->materials[group->material];
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material->ambient);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material->diffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material->specular);
            glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material->shininess);
        }

        if (mode & GLM_COLOR) {
            glColor3fv(material->diffuse);
        }

        glBegin(GL_TRIANGLES);
        for (i = 0; i < group->numtriangles; i++) {
            triangle = &T(group->triangles[i]);

            if (mode & GLM_FLAT)
                glNormal3fv(&model->facetnorms[3 * triangle->findex]);

            if (mode & GLM_SMOOTH)
                glNormal3fv(&model->normals[3 * triangle->nindices[0]]);
            if (mode & GLM_TEXTURE)
                glTexCoord2fv(&model->texcoords[2 * triangle->tindices[0]]);
            glVertex3fv(&model->vertices[3 * triangle->vindices[0]]);

            if (mode & GLM_SMOOTH)
                glNormal3fv(&model->normals[3 * triangle->nindices[1]]);
            if (mode & GLM_TEXTURE)
                glTexCoord2fv(&model->texcoords[2 * triangle->tindices[1]]);
            glVertex3fv(&model->vertices[3 * triangle->vindices[1]]);

            if (mode & GLM_SMOOTH)
                glNormal3fv(&model->normals[3 * triangle->nindices[2]]);
            if (mode & GLM_TEXTURE)
                glTexCoord2fv(&model->texcoords[2 * triangle->tindices[2]]);
            glVertex3fv(&model->vertices[3 * triangle->vindices[2]]);

        }
        glEnd();

        group = group->next;
    }
}

/* glmList: Generates and returns a display list for the model using
 * the mode specified.
 *
 * model    - initialized GLMmodel structure
 * mode     - a bitwise OR of values describing what is to be rendered.
 *            GLM_NONE     -  render with only vertices
 *            GLM_FLAT     -  render with facet normals
 *            GLM_SMOOTH   -  render with vertex normals
 *            GLM_TEXTURE  -  render with texture coords
 *            GLM_COLOR    -  render with colors (color material)
 *            GLM_MATERIAL -  render with materials
 *            GLM_COLOR and GLM_MATERIAL should not both be specified.
 * GLM_FLAT and GLM_SMOOTH should not both be specified.  */
GLuint
glmList(GLMmodel* model, GLuint mode)
{
    GLuint list;

    list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    glmDraw(model, mode);
    glEndList();

    return list;
}

/* glmWeld: eliminate (weld) vectors that are within an epsilon of
 * each other.
 *
 * model      - initialized GLMmodel structure
 * epsilon    - maximum difference between vertices
 *              ( 0.00001 is a good start for a unitized model)
 *
 */
GLvoid
glmWeld(GLMmodel* model, GLfloat epsilon)
{
    GLfloat* vectors;
    GLfloat* copies;
    GLuint   numvectors;
    GLuint   i;

    /* vertices */
    numvectors = model->numvertices;
    vectors = model->vertices;
    copies = glmWeldVectors(vectors, &numvectors, epsilon);

#if 0
    printf("glmWeld(): %d redundant vertices.\n",
        model->numvertices - numvectors - 1);
#endif

    for (i = 0; i < model->numtriangles; i++) {
        T(i).vindices[0] = (GLuint)vectors[3 * T(i).vindices[0] + 0];
        T(i).vindices[1] = (GLuint)vectors[3 * T(i).vindices[1] + 0];
        T(i).vindices[2] = (GLuint)vectors[3 * T(i).vindices[2] + 0];
    }

    /* free space for old vertices */
    free(vectors);

    /* allocate space for the new vertices */
    model->numvertices = numvectors;
    model->vertices = (GLfloat*)malloc(sizeof(GLfloat) *
        3 * (model->numvertices + 1));

    /* copy the optimized vertices into the actual vertex list */
    for (i = 1; i <= model->numvertices; i++) {
        model->vertices[3 * i + 0] = copies[3 * i + 0];
        model->vertices[3 * i + 1] = copies[3 * i + 1];
        model->vertices[3 * i + 2] = copies[3 * i + 2];
    }

    free(copies);
}


#if 0
/* normals */
if (model->numnormals) {
    numvectors = model->numnormals;
    vectors = model->normals;
    copies = glmOptimizeVectors(vectors, &numvectors);

    printf("glmOptimize(): %d redundant normals.\n",
        model->numnormals - numvectors);

    for (i = 0; i < model->numtriangles; i++) {
        T(i).nindices[0] = (GLuint)vectors[3 * T(i).nindices[0] + 0];
        T(i).nindices[1] = (GLuint)vectors[3 * T(i).nindices[1] + 0];
        T(i).nindices[2] = (GLuint)vectors[3 * T(i).nindices[2] + 0];
    }

    /* free space for old normals */
    free(vectors);

    /* allocate space for the new normals */
    model->numnormals = numvectors;
    model->normals = (GLfloat*)malloc(sizeof(GLfloat) *
        3 * (model->numnormals + 1));

    /* copy the optimized vertices into the actual vertex list */
    for (i = 1; i <= model->numnormals; i++) {
        model->normals[3 * i + 0] = copies[3 * i + 0];
        model->normals[3 * i + 1] = copies[3 * i + 1];
        model->normals[3 * i + 2] = copies[3 * i + 2];
    }

    free(copies);
}

/* texcoords */
if (model->numtexcoords) {
    numvectors = model->numtexcoords;
    vectors = model->texcoords;
    copies = glmOptimizeVectors(vectors, &numvectors);

    printf("glmOptimize(): %d redundant texcoords.\n",
        model->numtexcoords - numvectors);

    for (i = 0; i < model->numtriangles; i++) {
        for (j = 0; j < 3; j++) {
            T(i).tindices[j] = (GLuint)vectors[3 * T(i).tindices[j] + 0];
        }
    }

    /* free space for old texcoords */
    free(vectors);

    /* allocate space for the new texcoords */
    model->numtexcoords = numvectors;
    model->texcoords = (GLfloat*)malloc(sizeof(GLfloat) *
        2 * (model->numtexcoords + 1));

    /* copy the optimized vertices into the actual vertex list */
    for (i = 1; i <= model->numtexcoords; i++) {
        model->texcoords[2 * i + 0] = copies[2 * i + 0];
        model->texcoords[2 * i + 1] = copies[2 * i + 1];
    }

    free(copies);
}
#endif

#if 0
/* look for unused vertices */
/* look for unused normals */
/* look for unused texcoords */
for (i = 1; i <= model->numvertices; i++) {
    for (j = 0; j < model->numtriangles; i++) {
        if (T(j).vindices[0] == i ||
            T(j).vindices[1] == i ||
            T(j).vindices[1] == i)
            break;
    }
}
#endif

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
        glTranslatef(0.3, 0.15 + x, -0.625);
        if (first_fire == 1) {
            fire_start_x = 0.3 + cam_x;
            fire_start_y = 0.15 + x + cam_y;
            fire_start_z = -0.625 + cam_z;
        }

        //printf("x: %f y: %f z: %f\n", fire_start_x, fire_start_y, fire_start_z);

        glPushMatrix();
            glRotatef((GLfloat)sunday, 0.0, 1.0, 0.0);
            glRotated(90, 1.0, 0.0, 0.0);
            glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
            glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
            glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
            if (offsetmode == 1) {
                glEnable(GL_POLYGON_OFFSET_FILL);
                glPolygonOffset(polyfactor, polyunits);
            }
            glutSolidSphere(0.08, 20, 16);   // sun 
            if (offsetmode == 0) {
                glDisable(GL_POLYGON_OFFSET_FILL);
            }
        glPopMatrix();
        glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
        glTranslatef(0.2, 0.0, 0.0);
        glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
        glPushMatrix();
            glRotated(90, 1.0, 0.0, 0.0);
            glMaterialfv(GL_FRONT, GL_AMBIENT, mat_earth);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_earth);
            glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
            glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
            glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
            if (offsetmode == 1) {
                glEnable(GL_POLYGON_OFFSET_FILL);
                glPolygonOffset(polyfactor, polyunits);
            }
            glutSolidSphere(0.02, 10, 8);    // planet 
            if (offsetmode == 0) {
                glDisable(GL_POLYGON_OFFSET_FILL);
            }
        glPopMatrix();
    glPopMatrix();
}
void set_hit() {
    for (int i = 0; i < 60; i++) {
        hit[i] = 0;
    }
    enemy1_x = -2.0;
    enemy1_z = 0.0;
    enemy1_rh = enemy1_h;
    enemy1_alive = 1;
    enemy2_x = 5.0;
    enemy2_z = -5.0;
    enemy2_rh = enemy2_h;
    enemy2_alive = 1;
    enemy3_x = 0.0;
    enemy3_z = -4.0;
    enemy3_rh = enemy3_h;
    enemy3_alive = 1;
    alive = 1;
    nyhealth_rm = myhealth;
}
void attack_hit(float x, float y) {
    float h_x = x, h_y = y;
    if (h_x <= getv(105) && h_x >= getv(23) && h_y >= getv_b(71) && h_y <= getv_b(42)) {
        hit[0] = 1;
    }
    if (h_x <= getv(33) && h_x >= getv(22) && h_y >= getv_b(141) && h_y <= getv_b(66)) {
        hit[1] = 1;
    }
    if (h_x <= getv(101) && h_x >= getv(32) && h_y >= getv_b(126) && h_y <= getv_b(58)) {
        hit[2] = 1;
    }
    if (h_x <= getv(95) && h_x >= getv(29) && h_y >= getv_b(141) && h_y <= getv_b(123)) {
        hit[3] = 1;
    }
    if (h_x <= getv(113) && h_x >= getv(97) && h_y >= getv_b(154) && h_y <= getv_b(45)) {
        hit[4] = 1;
    }
    if (h_x <= getv(217) && h_x >= getv(147) && h_y >= getv_b(93) && h_y <= getv_b(51)) {
        hit[5] = 1;
    }
    if (h_x <= getv(217) && h_x >= getv(161) && h_y >= getv_b(126) && h_y <= getv_b(81)) {
        hit[6] = 1;
    }
    if (h_x <= getv(236) && h_x >= getv(146) && h_y >= getv_b(141) && h_y <= getv_b(126)) {
        hit[7] = 1;
    }
    if (h_x <= getv(269) && h_x >= getv(246) && h_y >= getv_b(108) && h_y <= getv_b(67)) {
        hit[8] = 1;
    }
    if (h_x <= getv(337) && h_x >= getv(252) && h_y >= getv_b(77) && h_y <= getv_b(58)) {
        hit[9] = 1;
    }
    if (h_x <= getv(337) && h_x >= getv(302) && h_y >= getv_b(90) && h_y <= getv_b(67)) {
        hit[10] = 1;
    }
    if (h_x <= getv(307) && h_x >= getv(296) && h_y >= getv_b(184) && h_y <= getv_b(45)) {
        hit[11] = 1;
    }
    if (h_x <= getv(322) && h_x >= getv(277) && h_y >= getv_b(105) && h_y <= getv_b(88)) {
        hit[12] = 1;
    }
    if (h_x <= getv(394) && h_x >= getv(375) && h_y >= getv_b(105) && h_y <= getv_b(55)) {
        hit[13] = 1;
    }
    if (h_x <= getv(424) && h_x >= getv(399) && h_y >= getv_b(97) && h_y <= getv_b(45)) {
        hit[14] = 1;
    }
    if (h_x <= getv(444) && h_x >= getv(420) && h_y >= getv_b(93) && h_y <= getv_b(47)) {
        hit[15] = 1;
    }
    if (h_x <= getv(463) && h_x >= getv(339) && h_y >= getv_b(128) && h_y <= getv_b(91)) {
        hit[16] = 1;
    }
    if (h_x <= getv(395) && h_x >= getv(360) && h_y >= getv_b(142) && h_y <= getv_b(124)) {
        hit[17] = 1;
    }
    if (h_x <= getv(460) && h_x >= getv(434) && h_y >= getv_b(146) && h_y <= getv_b(114)) {
        hit[18] = 1;
    }
    if (h_x <= getv(559) && h_x >= getv(488) && h_y >= getv_b(106) && h_y <= getv_b(73)) {
        hit[19] = 1;
    }
    if (h_x <= getv(545) && h_x >= getv(500) && h_y >= getv_b(128) && h_y <= getv_b(50)) {
        hit[20] = 1;
    }
    if (h_x <= getv(573) && h_x >= getv(541) && h_y >= getv_b(128) && h_y <= getv_b(102)) {
        hit[21] = 1;
    }
    if (h_x <= getv(666) && h_x >= getv(600) && h_y >= getv_b(82) && h_y <= getv_b(40)) {
        hit[22] = 1;
    }
    if (h_x <= getv(597) && h_x >= getv(583) && h_y >= getv_b(125) && h_y <= getv_b(101)) {
        hit[23] = 1;
    }
    if (h_x <= getv(685) && h_x >= getv(599) && h_y >= getv_b(96) && h_y <= getv_b(85)) {
        hit[24] = 1;
    }
    if (h_x <= getv(649) && h_x >= getv(627) && h_y >= getv_b(112) && h_y <= getv_b(98)) {
        hit[25] = 1;
    }
    if (h_x <= getv(649) && h_x >= getv(600) && h_y >= getv_b(176) && h_y <= getv_b(126)) {
        hit[26] = 1;
    }
    if (h_x <= getv(669) && h_x >= getv(615) && h_y >= getv_b(124) && h_y <= getv_b(113)) {
        hit[27] = 1;
    }
    if (h_x <= getv(886) && h_x >= getv(752) && h_y >= getv_b(157) && h_y <= getv_b(30)) {
        hit[28] = 1;
    }
    if (h_x <= getv(61) && h_x >= getv(30) && h_y >= getv_b(277) && h_y <= getv_b(236)) {
        hit[29] = 1;
    }
    if (h_x <= getv(97) && h_x >= getv(71) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[30] = 1;
    }
    if (h_x <= getv(117) && h_x >= getv(104) && h_y >= getv_b(277) && h_y <= getv_b(240)) {
        hit[31] = 1;
    }
    if (h_x <= getv(131) && h_x >= getv(123) && h_y >= getv_b(277) && h_y <= getv_b(240)) {
        hit[32] = 1;
    }
    if (h_x <= getv(167) && h_x >= getv(136) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[33] = 1;
    }
    if (h_x <= getv(199) && h_x >= getv(174) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[34] = 1;
    }
    if (h_x <= getv(232) && h_x >= getv(207) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[35] = 1;
    }
    if (h_x <= getv(249) && h_x >= getv(242) && h_y >= getv_b(277) && h_y <= getv_b(239)) {
        hit[36] = 1;
    }
    if (h_x <= getv(305) && h_x >= getv(268) && h_y >= getv_b(277) && h_y <= getv_b(239)) {
        hit[37] = 1;
    }
    if (h_x <= getv(337) && h_x >= getv(313) && h_y >= getv_b(277) && h_y <= getv_b(239)) {
        hit[38] = 1;
    }
    if (h_x <= getv(372) && h_x >= getv(347) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[39] = 1;
    }
    if (h_x <= getv(405) && h_x >= getv(381) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[40] = 1;
    }
    if (h_x <= getv(440) && h_x >= getv(413) && h_y >= getv_b(288) && h_y <= getv_b(247)) {
        hit[41] = 1;
    }
    if (h_x <= getv(495) && h_x >= getv(464) && h_y >= getv_b(277) && h_y <= getv_b(239)) {
        hit[42] = 1;
    }
    if (h_x <= getv(528) && h_x >= getv(504) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[43] = 1;
    }
    if (h_x <= getv(542) && h_x >= getv(535) && h_y >= getv_b(277) && h_y <= getv_b(239)) {
        hit[44] = 1;
    }
    if (h_x <= getv(576) && h_x >= getv(552) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[45] = 1;
    }
    if (h_x <= getv(609) && h_x >= getv(583) && h_y >= getv_b(288) && h_y <= getv_b(247)) {
        hit[46] = 1;
    }
    if (h_x <= getv(665) && h_x >= getv(633) && h_y >= getv_b(277) && h_y <= getv_b(239)) {
        hit[47] = 1;
    }
    if (h_x <= getv(700) && h_x >= getv(676) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[48] = 1;
    }
    if (h_x <= getv(715) && h_x >= getv(708) && h_y >= getv_b(277) && h_y <= getv_b(239)) {
        hit[49] = 1;
    }
    if (h_x <= getv(748) && h_x >= getv(721) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[50] = 1;
    }
    if (h_x <= getv(783) && h_x >= getv(754) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[51] = 1;
    }
    if (h_x <= getv(805) && h_x >= getv(790) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[52] = 1;
    }
    if (h_x <= getv(834) && h_x >= getv(810) && h_y >= getv_b(277) && h_y <= getv_b(247)) {
        hit[53] = 1;
    }
    if (h_x <= getv(849) && h_x >= getv(841) && h_y >= getv_b(277) && h_y <= getv_b(239)) {
        hit[54] = 1;
    }
    if (h_x <= getv(869) && h_x >= getv(854) && h_y >= getv_b(277) && h_y <= getv_b(239)) {
        hit[55] = 1;
    }
    if (h_x <= getv(900) && h_x >= getv(873) && h_y >= getv_b(288) && h_y <= getv_b(247)) {
        hit[56] = 1;
    }
}
void fire_reset() {
    fire_x = 0.0;
    fire_y = 0.0;
    fire_z = 0.0;
    fire = 0;
    fire_t = 0.0;
}
void state_1() {
    //glClearColor(1.0, 1.0, 1.0, 0.0);
    //glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    if (hit[28] == 0) {
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
    }
    glPopMatrix();
    if (hit[0] == 0) {
        glDrawArrays(GL_POLYGON, 0, 4);
        glDrawArrays(GL_POLYGON, 4, 4);
        glDrawArrays(GL_TRIANGLES, 8, 3);
    }
    if (hit[1] == 0) {
        glDrawArrays(GL_POLYGON, 11, 4);
        glDrawArrays(GL_POLYGON, 15, 4);
    }
    if (hit[2] == 0) {
        glDrawArrays(GL_POLYGON, 19, 4);
        glDrawArrays(GL_POLYGON, 23, 4);
        glDrawArrays(GL_POLYGON, 27, 8);
        glDrawArrays(GL_POLYGON, 35, 13);
        glDrawArrays(GL_POLYGON, 48, 9);
    }
    if (hit[3] == 0) {
        glDrawArrays(GL_POLYGON, 57, 7);
    }
    if (hit[4] == 0) {
        glDrawArrays(GL_POLYGON, 64, 7);
    }
    if (hit[5] == 0) {
        glDrawArrays(GL_POLYGON, 71, 5);
        glDrawArrays(GL_POLYGON, 76, 5);
        glDrawArrays(GL_POLYGON, 81, 4);
        glDrawArrays(GL_POLYGON, 85, 9);
    }
    if (hit[6] == 0) {
        glDrawArrays(GL_POLYGON, 93, 5);
        glDrawArrays(GL_POLYGON, 98, 6);
        glDrawArrays(GL_POLYGON, 104, 6);
    }
    if (hit[7] == 0) {
        glDrawArrays(GL_POLYGON, 110, 9);
    }
    if (hit[8] == 0) {
        glDrawArrays(GL_POLYGON, 119, 7);
    }
    if (hit[9] == 0) {
        glDrawArrays(GL_POLYGON, 126, 12);
    }
    if (hit[10] == 0) {
        glDrawArrays(GL_POLYGON, 138, 7);
    }
    if (hit[11] == 0) {
        glDrawArrays(GL_POLYGON, 145, 11);
    }
    if (hit[12] == 0) {
        glDrawArrays(GL_POLYGON, 156, 5);
    }
    if (hit[13] == 0) {
        glDrawArrays(GL_POLYGON, 161, 6);
        glDrawArrays(GL_POLYGON, 167, 6);
    }
    if (hit[14] == 0) {
        glDrawArrays(GL_POLYGON, 173, 8);
        glDrawArrays(GL_POLYGON, 181, 9);
    }
    if (hit[15] == 0) {
        glDrawArrays(GL_POLYGON, 190, 9);
    }
    if (hit[16] == 0) {
        glDrawArrays(GL_POLYGON, 199, 18);
    }
    if (hit[17] == 0) {
        glDrawArrays(GL_POLYGON, 217, 4);
    }
    if (hit[18] == 0) {
        glDrawArrays(GL_POLYGON, 221, 4);
    }
    if (hit[19] == 0) {
        glDrawArrays(GL_POLYGON, 225, 4);
        glDrawArrays(GL_POLYGON, 229, 11);
    }
    if (hit[20] == 0) {
        glDrawArrays(GL_POLYGON, 240, 10);
    }
    if (hit[21] == 0) {
        glDrawArrays(GL_POLYGON, 250, 4);
        glDrawArrays(GL_POLYGON, 254, 5);
    }
    //大
    if (hit[22] == 0) {
        glDrawArrays(GL_POLYGON, 259, 11);
        glDrawArrays(GL_POLYGON, 270, 8);
        glDrawArrays(GL_POLYGON, 278, 8);
        glDrawArrays(GL_POLYGON, 286, 5);
        glDrawArrays(GL_POLYGON, 291, 4);
        glDrawArrays(GL_POLYGON, 295, 5);
        glDrawArrays(GL_POLYGON, 300, 8);
    }
    if (hit[23] == 0) {
        glDrawArrays(GL_POLYGON, 308, 4);
    }
    if (hit[24] == 0) {
        glDrawArrays(GL_POLYGON, 312, 11);
        glDrawArrays(GL_POLYGON, 323, 5);
    }
    if (hit[25] == 0) {
        glDrawArrays(GL_POLYGON, 328, 5);
    }
    if (hit[26] == 0) {
        glDrawArrays(GL_POLYGON, 333, 9);
        glDrawArrays(GL_POLYGON, 342, 6);
        glDrawArrays(GL_POLYGON, 358, 5);
    }
    if (hit[27] == 0) {
        glDrawArrays(GL_POLYGON, 348, 10);
    }
    if (hit[29] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 458, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 462, 8);
    }
    if (hit[30] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 470, 15);
        glDrawArrays(GL_TRIANGLE_STRIP, 485, 22);
    }
    if (hit[31] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 507, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 511, 7);
    }
    if (hit[32] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 518, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 522, 4);
    }
    if (hit[33] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 526, 31);
    }
    if (hit[34] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 557, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 561, 12);
    }
    if (hit[35] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 573, 15);
        glDrawArrays(GL_TRIANGLE_STRIP, 588, 22);
    }
    if (hit[36] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 610, 4);
    }
    if (hit[37] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 614, 40);
    }
    if (hit[38] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 654, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 658, 12);
        glDrawArrays(GL_TRIANGLE_STRIP, 670, 4);
    }
    if (hit[39] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 674, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 678, 10);
        glDrawArrays(GL_TRIANGLE_STRIP, 688, 4);
    }
    if (hit[40] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 692, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 696, 12);
    }
    if (hit[41] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 708, 23);
        glDrawArrays(GL_TRIANGLE_STRIP, 731, 14);
    }
    if (hit[42] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 745, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 749, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 753, 4);
    }
    if (hit[43] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 757, 34);
    }
    if (hit[44] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 791, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 795, 4);
    }
    if (hit[45] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 799, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 803, 12);
    }
    if (hit[46] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 815, 23);
        glDrawArrays(GL_TRIANGLE_STRIP, 838, 14);
    }
    if (hit[47] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 852, 15);
    }
    if (hit[48] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 867, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 871, 12);
    }
    if (hit[49] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 883, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 887, 4);
    }
    if (hit[50] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 891, 7);
    }
    if (hit[51] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 898, 28);
    }
    if (hit[52] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 926, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 930, 6);
    }
    if (hit[53] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 936, 34);
    }
    if (hit[54] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 970, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 974, 4);
    }
    if (hit[55] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 978, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 982, 7);
    }
    if (hit[56] == 0) {
        glDrawArrays(GL_TRIANGLE_STRIP, 989, 7);
        glDrawArrays(GL_TRIANGLE_STRIP, 996, 7);
    }


    //glDisableClientState(GL_VERTEX_ARRAY);
    //glDisableClientState(GL_COLOR_ARRAY);
}
void robot()
{
    glPushMatrix();
    glTranslatef(0.6, -0.4 + x, -0.625);
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(-30, 1.0, 0.0, 0.0);
    glScalef(0.2, 0.2, 0.75);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    //elbow
    glPushMatrix();
    glTranslatef(0.55, -0.3 - 0.2 + x, -1.2);
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(5, 1.0, 0.0, 0.0);
    glScalef(0.2, 0.2, 0.6);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    //hand
    glPushMatrix();
    glTranslatef(0.55, -0.35 + x, -1.5);
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(-30, 1.0, 0.0, 0.0);
    glScalef(0.2, 0.3, 0.1);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    //finger 0
    glPushMatrix();
    glTranslatef(0.6 + 0.25, -0.3 + x, -1.35 - 0.55);
    glPushMatrix();
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(40, 1.0, 0.0, 0.0);
    glScalef(0.5 / 5, 0.3 / 5, 0.3 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f0);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.09, 0.06, 0.0);
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(40, 1.0, 0.0, 0.0);
    glRotatef(-20, 0.0, 0.0, 1.0);
    glScalef(0.3 / 5, 0.6 / 5, 0.3 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f0);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
    //finger 1
    glPushMatrix();
    glTranslatef(0.6 + 0.15, -0.2 + x, -1.35 - 0.55);
    glPushMatrix();
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(50, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f1);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.02, 0.13, -0.08);
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(10, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f1);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
    //finger 2
    glPushMatrix();
    glTranslatef(0.6 + 0.08, -0.2 + x, -1.35 - 0.55);
    glPushMatrix();
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(80, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.02, 0.03, 0.0);
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(120, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();

    //finger 3
    glPushMatrix();
    glTranslatef(0.6 + 0.01, -0.2 + x, -1.35 - 0.55);
    glPushMatrix();
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(80, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f3);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f3);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.02, 0.03, 0.0);
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(120, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f3);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f3);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
    //finger 4
    glPushMatrix();
    glTranslatef(0.6 - 0.06, -0.2 + x, -1.35 - 0.55);
    glPushMatrix();
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(50, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f4);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.02, 0.13, -0.08);
    glRotatef(rotate_fire_angle, 1.0, 0.0, 0.0);
    glRotatef(10, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f4);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
}
void robot_2() {
    glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(-0.6, -0.4 + x, -0.625);
    //glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(-30, 1.0, 0.0, 0.0);
    glScalef(0.2, 0.2, 0.75);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    //elbow
    glPushMatrix();
    glTranslatef(-0.55, -0.3 - 0.2 + x, -1.2);
    //glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(5, 1.0, 0.0, 0.0);
    glScalef(0.2, 0.2, 0.6);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    //hand
    glPushMatrix();
    glTranslatef(-0.55, -0.35 + x, -1.5);
    //glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(-30, 1.0, 0.0, 0.0);
    glScalef(0.2, 0.3, 0.1);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    //finger 0
    glPushMatrix();
    glTranslatef(-(0.6 + 0.25), -0.3 + x * 1.2, -1.35 - 0.55);
    glPushMatrix();
    //glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(40, 1.0, 0.0, 0.0);
    glScalef(0.5 / 5, 0.3 / 5, 0.3 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f0);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.09, 0.06 + x * 1.4, 0.0);
    //glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(40, 1.0, 0.0, 0.0);
    glRotatef(-20, 0.0, 0.0, 1.0);
    glScalef(0.3 / 5, 0.6 / 5, 0.3 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f0);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
    //finger 1
    glPushMatrix();
    glTranslatef(-(0.6 + 0.15), -0.2 + x * 1.2, -1.35 - 0.55);
    glPushMatrix();
    // glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(50, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f1);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.02, 0.13 + x * 1.4, -0.08);
    // glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(10, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f1);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
    //finger 2
    glPushMatrix();
    glTranslatef(-(0.6 + 0.08), -0.2 + x * 1.2, -1.35 - 0.55);
    glPushMatrix();
    //glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(80, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.02, 0.03 + x * 1.4, 0.0);
    // glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(120, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();

    //finger 3
    glPushMatrix();
    glTranslatef(-(0.6 + 0.01), -0.2 + x * 1.2, -1.35 - 0.55);
    glPushMatrix();
    //glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(80, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f3);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f3);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.02, 0.03 + x * 1.4, 0.0);
    //glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(120, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f3);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f3);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
    //finger 4
    glPushMatrix();
    glTranslatef(-(0.6 - 0.06), -0.2 + x * 1.2, -1.35 - 0.55);
    glPushMatrix();
    //glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(50, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.2 / 5, 0.75 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f4);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.02, 0.13 + 1.4 * x, -0.08);
    //glRotatef(rotate_arm_angle, 1.0, 0.0, 0.0);
    glRotatef(10, 1.0, 0.0, 0.0);
    glScalef(0.2 / 5, 0.75 / 5, 0.2 / 5);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_f4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_f4);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();
}
void floor() {
    glTranslatef(0., -1.5, 0.);
    glColor3f(2. / 256., 222. / 256., 131. / 256.);
    glBegin(GL_QUADS);
    glVertex3f(10., 0., 10.);
    glVertex3f(10., 0., -10.);
    glVertex3f(-10., 0., -10.);
    glVertex3f(-10., 0., 10.);
    glEnd();
}
void wall() {
    glColor3f(0., 1., 0.);
    glBegin(GL_QUADS);
    glVertex3f(1., -1., 0.);
    glVertex3f(1., 1., 0.);
    glVertex3f(-1., 1., 0.);
    glVertex3f(-1., -1., 0.);
    glEnd();
}
void aimline() {
    glColor3f(1, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex3f(0.0 + cam_x, 0.001 + cam_y + x, cam_z - 0.1);
    glVertex3f(0.0 + cam_x, -0.001 + cam_y + x, cam_z - 0.1);
    glVertex3f(0.0005 + cam_x, 0. + cam_y + x, cam_z - 0.1);
    glVertex3f(-0.0005 + cam_x, 0. + cam_y + x, cam_z - 0.1);
    /*glVertex3f(fire_start_x, fire_start_y, fire_start_y);
    glVertex3f(cam_x, cam_y, 0.0);*/
    glEnd();
}
void snipe() {
    glColor3f(1, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINES);
        glVertex3f(0.0 + cam_x, 1. + cam_y + x, cam_z + snipe_z - 0.5);
        glVertex3f(0.0 + cam_x, -1. + cam_y + x, cam_z + snipe_z - 0.5);
        glVertex3f(0.5 + cam_x, 0. + cam_y + x, cam_z + snipe_z - 0.5);
        glVertex3f(-0.5 + cam_x, 0. + cam_y + x, cam_z + snipe_z - 0.5);
    glEnd();
    glColor4f(0.5, 0., 0.5, 0.25);
    glBegin(GL_QUADS);
        glVertex3f(-5. + cam_x, -10. + cam_y + x, cam_z + snipe_z - 0.5);
        glVertex3f(5. + cam_x, -10. + cam_y + x, cam_z + snipe_z - 0.5);
        glVertex3f(5. + cam_x, 10. + cam_y + x, cam_z + snipe_z - 0.5);
        glVertex3f(-5. + cam_x, 10. + cam_y + x, cam_z + snipe_z - 0.5);
    glEnd();
}
void die_blend() {
    glColor4f(1, 0, 0, 0.5);
    glBegin(GL_QUADS);
        glVertex3f(-5. + cam_x, -10. + cam_y + x, cam_z  - 0.1);
        glVertex3f(5. + cam_x, -10. + cam_y + x, cam_z - 0.1);
        glVertex3f(5. + cam_x, 10. + cam_y + x, cam_z  - 0.1);
        glVertex3f(-5. + cam_x, 10. + cam_y + x, cam_z  - 0.1);
    glEnd();
}
void obj_1() {
    GLMmodel* pmodel = NULL;
    if (!pmodel) {
        char filename[] = "soccerball.obj";
        pmodel = glmReadOBJ(filename);
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH|GLM_MATERIAL);
}
void obj_2() {
    GLMmodel* pmodel = NULL;
    if (!pmodel) {
        char filename[] = "rose+vase.obj";
        pmodel = glmReadOBJ(filename);
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}
void obj_3() {
    GLMmodel* pmodel = NULL;
    if (!pmodel) {
        char filename[] = "flowers.obj";
        pmodel = glmReadOBJ(filename);
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}
void health(float h, float rh) {
    float remain_rate = rh / h * 2.0 - 1.0;
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-1.0, 1.4, 0.0);
        glVertex3f(remain_rate, 1.4, 0.0);
        glVertex3f(remain_rate, 1.6, 0.0);
        glVertex3f(-1.0, 1.6, 0.0);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-1.0, 1.4, 0.0);
        glVertex3f(1.0, 1.4, 0.0);
        glVertex3f(1.0, 1.6, 0.0);
        glVertex3f(-1.0, 1.6, 0.0);
    glEnd();
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}
void myhealth_render() {
    float remain_rate = nyhealth_rm / myhealth * 1.0 - 0.5;
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    
    glTranslatef(0.006, 0.007, 0.0);
    glScalef(0.004, 0.004, 0.1);
    //glTranslatef(cam_x, cam_y, cam_z);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5, -0.1, -0.1);
        glVertex3f(remain_rate, -0.1, - 0.1);
        glVertex3f(remain_rate, 0.1, - 0.1);
        glVertex3f(-0.5, 0.1, - 0.1);
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
void gethit(float damage) {
    nyhealth_rm -= damage;
    if (nyhealth_rm <= 0) {
        nyhealth_rm = 0;
        alive = 0;
    }
}
void enemy1_backward() {
    float dis = sqrt(pow((enemy1_dir[0]), 2) + pow((enemy1_dir[1]), 2));
    float path = enemy1_speed / dis;
    enemy1_x -= enemy1_dir[0] * path * 500;
    enemy1_z -= enemy1_dir[1] * path * 500;
}
void enemy2_backward() {
    float dis = sqrt(pow((enemy2_dir[0]), 2) + pow((enemy2_dir[1]), 2));
    float path = enemy1_speed / dis;
    enemy2_x -= enemy2_dir[0] * path * 500;
    enemy2_z -= enemy2_dir[1] * path * 500;
}
void enemy3_backward() {
    float dis = sqrt(pow((enemy3_dir[0]), 2) + pow((enemy3_dir[1]), 2));
    float path = enemy1_speed / dis;
    enemy3_x -= enemy3_dir[0] * path * 500;
    enemy3_z -= enemy3_dir[1] * path * 500;
}
void hitenemy(float ball_x, float ball_z) {
    //printf("bx: %f, bz: %f, rangex: %f %f, rangez: %f %f\n", ball_x, ball_z, enemy1_x + enemy1_hitbox / 2, enemy1_x - enemy1_hitbox / 2, enemy1_z + enemy1_hitbox / 2, enemy1_z - enemy1_hitbox / 2);
    if (enemy1_x + enemy1_hitbox/2 >= ball_x && ball_x >= enemy1_x - enemy1_hitbox/2 && enemy1_z + enemy1_hitbox/2 >= ball_z && ball_z >= enemy1_z - enemy1_hitbox/2) {
        fire = 0;
        fire_reset();
        enemy1_backward();
        enemy1_rh -= mydamage;
        if (enemy1_rh <= 0) {
            enemy1_rh = 0;
            enemy1_alive = 0;
        }
    }
    if (enemy2_x + enemy2_hitbox / 2 >= ball_x && ball_x >= enemy2_x - enemy2_hitbox / 2 && enemy2_z + enemy2_hitbox / 2 >= ball_z && ball_z >= enemy2_z - enemy2_hitbox / 2) {
        fire = 0;
        fire_reset();
        enemy2_backward();
        enemy2_rh -= mydamage;
        if (enemy2_rh <= 0) {
            enemy2_rh = 0;
            enemy2_alive = 0;
        }
    }
    if (enemy3_x + enemy3_hitbox / 2 >= ball_x && ball_x >= enemy3_x - enemy3_hitbox / 2 && enemy3_z + enemy3_hitbox / 2 >= ball_z && ball_z >= enemy3_z - enemy3_hitbox / 2) {
        fire = 0;
        fire_reset();
        enemy3_backward();
        enemy3_rh -= mydamage;
        if (enemy3_rh <= 0) {
            enemy3_rh = 0;
            enemy3_alive = 0;
        }
    }
}
void enemy1_mv() {
    float dis = sqrt(pow((enemy1_dir[0]), 2) + pow((enemy1_dir[1]), 2));
    float path = enemy1_speed / dis;
    if (dis > 1.0) {
        //printf("dis:%f path:%f\n", dis, path);
        enemy1_x += enemy1_dir[0] * path;
        enemy1_z += enemy1_dir[1] * path;
    }
    else {
        gethit(enemy1_damage);
        enemy1_backward();
    }
}
void enemy2_mv() {
    float dis = sqrt(pow((enemy2_dir[0]), 2) + pow((enemy2_dir[1]), 2));
    float path = enemy2_speed / dis;
    if (dis > 0.6) {
        //printf("dis:%f path:%f\n", dis, path);
        enemy2_x += enemy2_dir[0] * path;
        enemy2_z += enemy2_dir[1] * path;
    }
    else {
        gethit(enemy2_damage);
        enemy2_backward();
    }
}
void enemy3_mv() {
    float dis = sqrt(pow((enemy3_dir[0]), 2) + pow((enemy3_dir[1]), 2));
    float path = enemy3_speed / dis;
    if (dis > 0.6) {
        //printf("dis:%f path:%f\n", dis, path);
        enemy3_x += enemy3_dir[0] * path;
        enemy3_z += enemy3_dir[1] * path;
    }
    else {
        gethit(enemy3_damage);
        enemy3_backward();
    }
}
void enemy1_total() {
    glPushMatrix();
        glTranslatef(enemy1_x, -0.5, enemy1_z);
        glScalef(0.5, 0.5, 0.5);
        health(enemy1_h, enemy1_rh);
        glCallList(list_1);
    glPopMatrix();
    glPushMatrix();
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
        glTranslatef(enemy1_x, -0.5, enemy1_z);
        glColor3f(1.0, 0.0, 0.0);
        glutWireCube(enemy1_hitbox);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
    glPopMatrix();
}
void enemy2_total() {
    glPushMatrix();
        glTranslatef(enemy2_x, -0.5, enemy2_z);
        glScalef(0.5, 0.5, 0.5);
        health(enemy2_h, enemy2_rh);
        glCallList(list_2);
    glPopMatrix();
    glPushMatrix();
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
        glTranslatef(enemy2_x, -0.5, enemy2_z);
        glScalef(1.0, 1.7, 1.0);
        glColor3f(1.0, 0.0, 0.0);
        glutWireCube(enemy2_hitbox);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
    glPopMatrix();
}
void enemy3_total() {
    glPushMatrix();
        glTranslatef(enemy3_x, -0.5, enemy3_z);
        glScalef(0.5, 0.5, 0.5);
        health(enemy3_h, enemy3_rh);
        glCallList(list_3);
    glPopMatrix();
    glPushMatrix();
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
        glTranslatef(enemy3_x, -0.5, enemy3_z);
        glScalef(1.0, 1.7, 1.0);
        glColor3f(1.0, 0.0, 0.0);
        glutWireCube(enemy3_hitbox);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
    glPopMatrix();
}
void display(void)
{
    if (fogmode == 1) {
        glEnable(GL_FOG);
    }
    if (snipemode == 1) {
        glEnable(GL_BLEND);
    }
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(cam_x, cam_y + x, cam_z + snipe_z, cam_x, cam_y + x, cam_z - 5.0, 0.0, 1.0, 0.0);
    setupMethod = POINTER;
    setupPointers();
    glColor3f(1., 1., 1.);
    glPushMatrix();
    //glScalef(20.0, 20.0, 1.0);
    //glTranslatef(0., 1., 0.);
        state_1();
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
    glPopMatrix();
    //floor
    glPushMatrix();
        floor();
    glPopMatrix();
   // glPushMatrix();
    
   // glPopMatrix();
    //glLoadIdentity();
    // start drawing
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColor3f(1., 1., 1.);
    if (bgtoggle == 1) {
        glEnable(GL_BLEND);
        glEnable(GL_POLYGON_SMOOTH);
        glEnable(GL_LINE_SMOOTH);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
        //glEnable(GLUT_MULTISAMPLE);
    }
    glPushMatrix();
        if (fire == 1) {
            glTranslatef(fire_x - 0.3, fire_y - fire_start_y + cam_y, fire_z + 0.625);
            hitenemy(fire_x - 0.3, fire_z + 0.625);
        }
        else {
            glTranslatef(cam_x, cam_y, cam_z);
        }
        drawPlanet();
    glPopMatrix();
    //glEnable()
    glPushMatrix();
        glTranslatef(cam_x, cam_y, cam_z);
        robot();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(cam_x, cam_y, cam_z);
        robot_2();
    glPopMatrix();
    //printf("x:%f\ty:%f\t\z:%f\n",camPosx,camPosy,camPosz);
    //system("cls");
    
    // myhealth
    glPushMatrix();
        glTranslatef(cam_x, cam_y + x, cam_z);
        myhealth_render();
    glPopMatrix();

    //enemy1
    if (enemy1_alive == 1) {
        enemy1_total();
    }
    //enemy2
    if (enemy2_alive == 1) {
        enemy2_total();
    }
    //enemy3
    if (enemy3_alive == 1) {
        enemy3_total();
    }
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
    
    
    if (snipemode == 0) {
        aimline();
    }
    else {
        snipe();
    }
    if (bgtoggle == 0) {
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_BLEND);
        glDisable(GL_POLYGON_SMOOTH);
        //glDisable(GLUT_MULTISAMPLE);
    }
    if (fogmode == 1) {
        glDisable(GL_FOG);
    }
    if (snipemode == 1) {
        glDisable(GL_BLEND);
    }
    if (alive == 0) {
        glEnable(GL_BLEND);
        die_blend();
    }
    glutSwapBuffers();
    glFlush();
    glDisable(GL_DEPTH_TEST);
}
void init(void)
{
    GLfloat ambient[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat position[] = { 10.0, 10.0, 0.0, 0.0 };
    glewInit();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    setupPointers();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, 1.0, 0.01, 200.0);
    glMatrixMode(GL_MODELVIEW);
    //light
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    //鋸齒
    GLfloat values[2];
    glGetFloatv(GL_LINE_WIDTH_GRANULARITY, values);
    printf("GL_LINE_WIDTH_GRANULARITY value is %3.1f\n", values[0]);

    glGetFloatv(GL_LINE_WIDTH_RANGE, values);
    printf("GL_LINE_WIDTH_RANGE values are %3.1f %3.1f\n", values[0], values[1]);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    //fog
    GLfloat fogColor[4] = { 0.0, 0.25, 0.25, 1.0 };
    glFogi(GL_FOG_MODE, GL_EXP2);
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogf(GL_FOG_DENSITY, 0.7);
    glHint(GL_FOG_HINT, GL_DONT_CARE);
    //glFogi(GL_FOG_COORDINATE_SOURCE_EXT, GL_FOG_COORDINATE_EXT);
    glFogf(GL_FOG_START, 0.1);
    glFogf(GL_FOG_END, 5.0);
    //glLoadIdentity();
    //gluLookAt(camPosx, camPosy, camPosz, camPosx, camPosy, camPosz - 1.0, 0.0, 1.0, 0.0);

    //enemy1
    list_1 = glGenLists(1);
    glNewList(list_1, GL_COMPILE);
        obj_1();
    glEndList();
    //enemy2
    list_2 = glGenLists(1);
    glNewList(list_2, GL_COMPILE);
        obj_2();
    glEndList();
    //enemy3
    list_3 = glGenLists(1);
    glNewList(list_3, GL_COMPILE);
        obj_3();
    glEndList();
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
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            if (alive == 1) {
                if (fire == 0) {
                    fire = 1;
                    if (first_fire == 0) {
                        rotate_fire = 1;
                        first_fire = 1;
                    }
                }
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
        cam_z -= 0.01;
        glutPostRedisplay();
        break;
    case 's':
    case 'S':
        cam_z += 0.01;
        glutPostRedisplay();
        break;
    case 'a':
    case 'A':
        cam_x -= 0.01;
        glutPostRedisplay();
        break;
    case 'd':
    case 'D':
        cam_x += 0.01;
        glutPostRedisplay();
        break;
    case 32:
        if (double_jump_mode == 0) {
            if (jump == 0) {
                jump = 1;
                if (first_j == 0) {
                    first_j = 1;
                }
            }
        }
        else {
            jump = 1;
            first_j = 1;
        }

        break;
    case 'r':
    case 'R':
        set_hit();
        break;
    case 'x':
    case 'X':
        if (rotate_arm == 0) {
            rotate_arm = 1;
            rotate_arm_angle = 0.0;
        }
    case 'm':
    case 'M':
        if (double_jump_mode == 0) {
            double_jump_mode = 1;
            printf("open double jump mode.\n");
        }
        else {
            double_jump_mode = 0;
            printf("close double jump mode.\n");
        }
        break;
    case 'c':
    case 'C':
        bgtoggle = !bgtoggle;
        //printf("now bg = %d\n", bgtoggle);
        glutPostRedisplay();
        break;
    case 'f':
    case 'F':
        fogmode = !fogmode;
        //printf("now bg = %d\n", bgtoggle);
        glutPostRedisplay();
        break;
    case 'b':
    case 'B':
        if (alive == 1) {
            snipemode = !snipemode;
            if (snipemode == 0) {
                snipe_z = 0.0;
            }
            else {
                snipe_z = snipe_distance;
            }
            printf("move:%f\n", snipe_z);
            glutPostRedisplay();
        }
        break;
    case 'p':
    case 'P':
        offsetmode = !offsetmode;
        //printf("now bg = %d\n", bgtoggle);
        glutPostRedisplay();
        break;
    default:
        break;
    }

}

void idle() {
    if (alive == 1) {
        iconrotate += 0.5;

        if (iconrotate == 360.0) {
            iconrotate = 0.0;
        }
        /*r_r = ((float)(rand() % 256)) / 255;
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
        }*/
        day = day + 0.1;
        year = year + 0.2;
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
        //rotate_arm
        if (rotate_arm == 1) {
            if (rotate_arm_angle != 360.) {
                rotate_arm_angle += 0.5;
            }
            else {
                rotate_arm_angle = 0.0;
                rotate_arm = 0;
            }
        }
        //fire hand animation
        if (rotate_fire == 1) {
            if (rotate_fire_angle != 360.) {
                rotate_fire_angle += 1.0;
            }
            else {
                rotate_fire_angle = 0.0;
                rotate_fire = 0;
            }
        }
        //jump
        if (jump == 1) {
            if (first_j == 1) {
                first_j = 0;
                t = 0.0;
                jj = x;
            }
            x = v_start * t - gravity * t * t / 2 + jj;
            t += t_g;
            if (x < 0) {
                x = 0.0;
                jump = 0;
                t = 0.0;
                jj = 0.0;
            }
        }
        //fire
        if (fire == 1) {
            if (first_fire == 1) {
                first_fire = 0;
                fire_dis_x = cam_x - fire_start_x;
                fire_dis_y = cam_y + x - fire_start_y;
                fire_dis_z = 0. - fire_start_z;
                //printf("disx: %f disy: %f disz: %f y:%f fy:%f \n", fire_dis_x, fire_dis_y, fire_dis_z, cam_y +x, fire_start_y);
                distancef = sqrt(pow((fire_dis_x), 2) + pow((fire_dis_y), 2) + pow(fire_dis_z, 2));
                fire_t = 0.0;
                fire_total_t = distancef / fire_v;   //距離目標需要多久
                //printf("dis: %f totaltime: %f\n", distance, fire_total_t);
            }
            fire_t += t_f;  //time going
            //printf("x: %f y: %f z: %f\n", fire_start_x, fire_start_y, fire_start_z);
            fire_x = fire_start_x + fire_dis_x / fire_total_t * fire_t;  //start + dis * (how much time has gone / total need time)
            fire_y = fire_start_y + fire_dis_y / fire_total_t * fire_t;
            fire_z = fire_start_z + fire_dis_z / fire_total_t * fire_t;
            //printf("t: %f fx: %f fy: %f fz: %f\n", fire_t, fire_x, fire_y, fire_z);
            if (fire_t > fire_total_t) {
                attack_hit(fire_x, fire_y);
                fire_reset();
            }
        }
        //enemy1
        if (enemy1_alive == 1) {
            enemy1_dir[0] = cam_x - enemy1_x;
            enemy1_dir[1] = cam_z - enemy1_z;
            //printf("%f %f\n", enemy1_dir[0], enemy1_dir[1]);
            enemy1_mv();
        }
        //enemy2
        if (enemy2_alive == 1) {
            enemy2_dir[0] = cam_x - enemy2_x;
            enemy2_dir[1] = cam_z - enemy2_z;
            //printf("%f %f\n", enemy1_dir[0], enemy1_dir[1]);
            enemy2_mv();
        }
        //enemy3
        if (enemy3_alive == 1) {
            enemy3_dir[0] = cam_x - enemy3_x;
            enemy3_dir[1] = cam_z - enemy3_z;
            //printf("%f %f\n", enemy1_dir[0], enemy1_dir[1]);
            enemy3_mv();
        }
    }
    
   
    //setupPointers();
    //gluLookAt(camPosx, camPosy, camPosz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    //glLoadIdentity();
    //gluLookAt(camPosx, camPosy, camPosz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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
#else
int main(int argc, char** argv)
{
    fprintf(stderr, "This program demonstrates a feature which is not in OpenGL Version 1.0.\n");
    fprintf(stderr, "If your implementation of OpenGL Version 1.0 has the right extensions,\n");
    fprintf(stderr, "you may be able to modify this program to make it run.\n");
    return 0;
}
#endif
