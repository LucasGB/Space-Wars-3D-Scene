/*
 * ---------------- www.spacesimulator.net --------------
 *   ---- Space simulators and 3d engine tutorials ----
 *
 * Author: Damiano Vitulli
 *
 * This program is released under the BSD licence
 * By using this program you agree to licence terms on spacesimulator.net copyright page
 *
 *
 * Camera management
 *  
 */

#include "camera.h"
#include "mat_matr.h"

camera_type camera;



/**********************************************************
 *
 * SUBROUTINE CamTranslate(float p_x,float p_y,float p_z)
 *
 * Camera translation relative to the point of view
 *
 * Input parameters: p_x = x coordinate
 *					 p_y = y coordinate
 *                   p_z = z coordinate
 * 
 *********************************************************/

void CamTranslate (float p_x,float p_y,float p_z)
{
	//The position fields in the camera matrix are filled with the new values
    camera.matrix[3][0]+=p_x;
    camera.matrix[3][1]+=p_y;
    camera.matrix[3][2]+=p_z;
}



/**********************************************************
 *
 * SUBROUTINE CamTranslateW(float p_x,float p_y,float p_z)
 *
 * Camera translation relative to the world
 *
 * Input parameters: p_x = x coordinate
 *					 p_y = y coordinate
 *                   p_z = z coordinate
 * 
 *********************************************************/

void CamTranslateW (float p_x,float p_y,float p_z)
{
    matrix_4x4_type l_matrix, l_res;
    MatrIdentity_4x4(l_matrix); 
	l_matrix[3][0]=p_x;
	l_matrix[3][1]=p_y;
	l_matrix[3][2]=p_z;
	//The camera matrix is multiplied by a translation matrix
	MatrMul_4x4_4x4(l_matrix,camera.matrix,l_res);
	MatrCopy_4x4(camera.matrix,l_res);
}



/**********************************************************
 *
 * SUBROUTINE CamRotate(int p_angle_x,int p_angle_y,int p_angle_z)
 *
 * Camera rotation relative to the point of view
 * Angles are expressed in 1/10 degree
 *
 * Input parameters: p_angle_x = x rotation angle
 *					 p_angle_y = y rotation angle
 *                   p_angle_z = z rotation angle
 * 
 *********************************************************/

void CamRotate(int p_angle_x,int p_angle_y,int p_angle_z)
{
    matrix_4x4_type l_matrix, l_res;
	
    //Range control
	if (p_angle_x<0) p_angle_x=3600+p_angle_x;
    if (p_angle_y<0) p_angle_y=3600+p_angle_y;  
    if (p_angle_z<0) p_angle_z=3600+p_angle_z;
    if (p_angle_x<0 || p_angle_x>3600) p_angle_x=0;
    if (p_angle_y<0 || p_angle_y>3600) p_angle_y=0;  
    if (p_angle_z<0 || p_angle_z>3600) p_angle_z=0;

    if (p_angle_x)
    {
		//The camera matrix is multiplied by the X rotation matrix
        MatrIdentity_4x4(l_matrix);
        l_matrix[1][1]=(matr_cos_table[p_angle_x]);
        l_matrix[1][2]=(matr_sin_table[p_angle_x]);
        l_matrix[2][1]=(-matr_sin_table[p_angle_x]);
        l_matrix[2][2]=(matr_cos_table[p_angle_x]);
	    MatrMul_4x4_4x4(camera.matrix,l_matrix,l_res);
		MatrCopy_4x4(camera.matrix,l_res);
    }
    if (p_angle_y)
    {

		// ...by the Y rotation matrix
        MatrIdentity_4x4(l_matrix);
        l_matrix[0][0]=(matr_cos_table[p_angle_y]);
        l_matrix[0][2]=(-matr_sin_table[p_angle_y]);
        l_matrix[2][0]=(matr_sin_table[p_angle_y]);
        l_matrix[2][2]=(matr_cos_table[p_angle_y]);
		MatrMul_4x4_4x4(camera.matrix,l_matrix,l_res);
		MatrCopy_4x4(camera.matrix,l_res);
    }
    if (p_angle_z)
    {
		// ...by the Z rotation matrix
        MatrIdentity_4x4(l_matrix);
        l_matrix[0][0]=(matr_cos_table[p_angle_z]);
        l_matrix[0][1]=(matr_sin_table[p_angle_z]);
        l_matrix[1][0]=(-matr_sin_table[p_angle_z]);
        l_matrix[1][1]=(matr_cos_table[p_angle_z]);
		MatrMul_4x4_4x4(camera.matrix,l_matrix,l_res);
		MatrCopy_4x4(camera.matrix,l_res);
    }
}
