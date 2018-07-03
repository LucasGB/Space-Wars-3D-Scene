#include "functions.h"

enum {SKY_LEFT=0,SKY_BACK,SKY_RIGHT,SKY_FRONT,SKY_TOP,SKY_BOTTOM};
unsigned int skybox[6]; 

void initskybox()
{
        skybox[SKY_LEFT]=loadTexture("left.bmp");
        skybox[SKY_BACK]=loadTexture("back.bmp");
        skybox[SKY_RIGHT]=loadTexture("right.bmp");
        skybox[SKY_FRONT]=loadTexture("front.bmp");
        skybox[SKY_TOP]=loadTexture("top.bmp");
        skybox[SKY_BOTTOM]=loadTexture("bottom.bmp");
}
//delete all of the textures from the skybox array (to avoid memory leaks)
void killskybox(){
        glDeleteTextures(6,&skybox[0]);
}
 
void drawSkybox(float size)
{
        bool b1=glIsEnabled(GL_TEXTURE_2D);     //new, we left the textures turned on, if it was turned on
        glDisable(GL_LIGHTING); //turn off lighting, when making the skybox
        glDisable(GL_DEPTH_TEST);       //turn off depth texting
        glEnable(GL_TEXTURE_2D);        //and turn on texturing
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_BACK]);  //use the texture we want
        glBegin(GL_QUADS);      //and draw a face
                //back face
                glTexCoord2f(0,0);      //use the correct texture coordinate
                glVertex3f(size/2,size/2,size/2);       //and a vertex
                glTexCoord2f(1,0);      //and repeat it...
                glVertex3f(-size/2,size/2,size/2);
                glTexCoord2f(1,1);
                glVertex3f(-size/2,-size/2,size/2);
                glTexCoord2f(0,1);
                glVertex3f(size/2,-size/2,size/2);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_LEFT]);
        glBegin(GL_QUADS);     
                //left face
                glTexCoord2f(0,0);
                glVertex3f(-size/2,size/2,size/2);
                glTexCoord2f(1,0);
                glVertex3f(-size/2,size/2,-size/2);
                glTexCoord2f(1,1);
                glVertex3f(-size/2,-size/2,-size/2);
                glTexCoord2f(0,1);
                glVertex3f(-size/2,-size/2,size/2);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_FRONT]);
        glBegin(GL_QUADS);     
                //front face
                glTexCoord2f(1,0);
                glVertex3f(size/2,size/2,-size/2);
                glTexCoord2f(0,0);
                glVertex3f(-size/2,size/2,-size/2);
                glTexCoord2f(0,1);
                glVertex3f(-size/2,-size/2,-size/2);
                glTexCoord2f(1,1);
                glVertex3f(size/2,-size/2,-size/2);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_RIGHT]);
        glBegin(GL_QUADS);     
                //right face
                glTexCoord2f(0,0);
                glVertex3f(size/2,size/2,-size/2);
                glTexCoord2f(1,0);
                glVertex3f(size/2,size/2,size/2);
                glTexCoord2f(1,1);
                glVertex3f(size/2,-size/2,size/2);
                glTexCoord2f(0,1);
                glVertex3f(size/2,-size/2,-size/2);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_TOP]);          
        glBegin(GL_QUADS);                      //top face
                glTexCoord2f(1,0);
                glVertex3f(size/2,size/2,size/2);
                glTexCoord2f(0,0);
                glVertex3f(-size/2,size/2,size/2);
                glTexCoord2f(0,1);
                glVertex3f(-size/2,size/2,-size/2);
                glTexCoord2f(1,1);
                glVertex3f(size/2,size/2,-size/2);
        glEnd();
        glBindTexture(GL_TEXTURE_2D,skybox[SKY_BOTTOM]);               
        glBegin(GL_QUADS);     
                //bottom face
                glTexCoord2f(1,1);
                glVertex3f(size/2,-size/2,size/2);
                glTexCoord2f(0,1);
                glVertex3f(-size/2,-size/2,size/2);
                glTexCoord2f(0,0);
                glVertex3f(-size/2,-size/2,-size/2);
                glTexCoord2f(1,0);
                glVertex3f(size/2,-size/2,-size/2);
        glEnd();
        glEnable(GL_LIGHTING);  //turn everything back, which we turned on, and turn everything off, which we have turned on.
        glEnable(GL_DEPTH_TEST);
        if(!b1)
                glDisable(GL_TEXTURE_2D);
}

void drawCube(float size)
{
        float difamb[]={1.0,0.5,0.3,1.0};
        glBegin(GL_QUADS);
                //front face
                glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,difamb);
                glNormal3f(0.0,0.0,1.0);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(size/2,-size/2,size/2);
 
                //left face
                glNormal3f(-1.0,0.0,0.0);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(-size/2,-size/2,size/2);
 
                //back face
                glNormal3f(0.0,0.0,-1.0);
                glVertex3f(size/2,size/2,-size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(size/2,-size/2,-size/2);
 
                //right face
                glNormal3f(1.0,0.0,0.0);
                glVertex3f(size/2,size/2,-size/2);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(size/2,-size/2,size/2);
                glVertex3f(size/2,-size/2,-size/2);
 
                //top face
                glNormal3f(0.0,1.0,0.0);
                glVertex3f(size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,size/2);
                glVertex3f(-size/2,size/2,-size/2);
                glVertex3f(size/2,size/2,-size/2);
 
                //bottom face
                glNormal3f(0.0,-1.0,0.0);
                glVertex3f(size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,size/2);
                glVertex3f(-size/2,-size/2,-size/2);
                glVertex3f(size/2,-size/2,-size/2);
        glEnd();
}

unsigned int loadTexture(const char* filename)  //load the filename named texture
{
        unsigned int num;       //the id for the texture
        glGenTextures(1,&num);  //we generate a unique one
        SDL_Surface* img=SDL_LoadBMP(filename); //load the bmp image
        glBindTexture(GL_TEXTURE_2D,num);       //and use the texture, we have just generated
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //same if the image bigger
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);      //we repeat the pixels in the edge of the texture, it will hide that 1px wide line at the edge of the cube, which you have seen in the video
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);      //we do it for vertically and horizontally (previous line)
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->w,img->h,0,GL_RGB,GL_UNSIGNED_SHORT_5_6_5,img->pixels);        //we make the actual texture
        SDL_FreeSurface(img);   //we delete the image, we don't need it anymore
        return num;     //and we return the id
}