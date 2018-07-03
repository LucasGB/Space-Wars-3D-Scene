//This example program is created by thecplusplusuy for demonstration purposes. It's a simple skybox:
//http://www.youtube.com/user/thecplusplusguy
//Free source, modify if you want, LGPL licence (I guess), I would be happy, if you would not delete the link
//so other people can see the tutorial
//this file is functions.h, it's contain the function prototypes
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <cmath>
#ifndef FUNCTION_H
#define FUNCTION_H

void drawCube(float size);
void drawSkybox(float size);	//draw the skybox
void initskybox();	//load the textures
void killskybox();	//delete the textures
void lockCamera();
void moveCamera(float,float);
void moveCamerraUp(float,float);
void Control(float,float,bool);
void UpdateCamera();
unsigned int loadTexture(const char*);
#endif