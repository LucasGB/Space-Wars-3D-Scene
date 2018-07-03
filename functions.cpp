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