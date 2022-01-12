#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
char *lines[]={ "3.25	-0.1	3.55	-0.1  0  start",
		"3.4	-0.1	3.4	0.5   0  l01",
		"3.4	0.5	3.7	0.8",
		"3.5	0.6	5.4	0.6 0 l03",
		"3.7	0.8	4.1	1.2",
		"4.0	1.1	5.6	1.1 0 l04",
		"5.6	0.80	5.6	2.2 0 l09",
		"4.1	1.2	4.1	1.6 0 l05" ,
		"4.1	1.6	4.2	1.7 0 l06" ,
		"4.2	1.7	5.8	1.7 0 l07",
		"5.6	2.2	5.7	2.3",
		"5.7	2.3	5.7	4.6",
                "5.7    4.6     5.5     4.8 ",
		"5.5	2.8	5.9	2.8 0 cross",
		"0.5	2.2	5.4	2.2  0 l08",
		"1.7	2.0	1.7	2.4 0 cross",
		"5.5	4.8	3.0	4.8",
		"3.5	4.6	3.5	5.0 0 cross",
                "3.0    4.8     2.3     4.1 255 ",
		"2.3    4.1     2.3     3.5 255 ",
		"2.3    3.5     3.0     2.8 255 ",
		"3.0    2.8     3.0     2.25 255 ",

               ""};

char *walls[]={"4.0   4.575   4.0     3.25 0 gatewall",
                 ""};

void box(FILE *f,double x,double y,double dx,double dy);

void garage(FILE * f,double x,double y,double dx,double dy);

void gate(FILE *f,double x, double y, double th);

void box1(FILE * f,double x,double y);

int main(int argc, char ** argv){
FILE *linefile, *wallfile;
int i;
time_t t;
srand((unsigned) time(&t));
linefile=fopen("385linev02","w");
if (linefile){
   i=0;
   while(lines[i]!=""){
      fprintf(linefile,"%s\n",lines[i]);
      i++;
   }
  
}
wallfile=fopen("385wallv02","w");
if (wallfile){
   double x,y;
   x=4.2+rand()/(double)RAND_MAX;
   printf("%lf \n",x);
   i=0;
   while(walls[i]!=""){
      fprintf(wallfile,"%s\n",walls[i]);
      i++;
   }
   box(wallfile,x,0.45,0.3,0.3);
   box1(wallfile,5.6-0.725,1.45);
   box(wallfile,5.6-0.25,1.5,0.5,0.4);
   garage(wallfile,0.5,1.9,0.8,0.6);
   y=3.45+rand()/(double)RAND_MAX/2.0;
   gate(wallfile,5.3,y,90);
   gate(wallfile,4.0,4.575,90);
   gate(wallfile,4.0,2.8,90);
   gate(wallfile,2.475,4.625,-45);
   gate(wallfile,2.475,2.975,45);
}   
return 0;
}
void box(FILE * f,double x,double y,double dx,double dy){
  fprintf(f,"%f %f %f %f %d\n",x,y,x, y+dy,0);
  fprintf(f,"%f %f %f %f %d\n",x,y+dy,x+dx, y+dy,0);
  fprintf(f,"%f %f %f %f %d\n",x,y,x+dx, y,0);
  fprintf(f,"%f %f %f %f %d\n",x+dx,y,x+dx, y+dy,0);
}

void garage(FILE * f,double x,double y,double dx,double dy){
  fprintf(f,"%f %f %f %f %d\n",x,y,x, y+dy,0);
  fprintf(f,"%f %f %f %f %d\n",x,y+dy,x+dx, y+dy,0);
  fprintf(f,"%f %f %f %f %d\n",x,y,x+dx, y,0);
  fprintf(f,"%f %f %f %f %d\n",x+dx,y-0.2,x+dx, y+dy,0);
}

void gate(FILE *f, double x, double y, double th){
 double v1,v2,x1,y1;
 v1=(th+135)/180*M_PI;
 v2=(th-135)/180*M_PI;
    fprintf(f,"%f %f %f %f %d\n",x,y,x+cos(v1)*0.05, y+sin(v1)*0.05,0);
    fprintf(f,"%f %f %f %f %d\n",x,y,x+cos(v2)*0.05, y+sin(v2)*0.05,0);
 v1=v1-M_PI;
 v2=v2-M_PI;
x=x+cos(th/180*M_PI)*0.45;
y=y+ sin(th/180*M_PI)*0.45;
fprintf(f,"%f %f %f %f %d\n",x,y,x+cos(v1)*0.05, y+sin(v1)*0.05,0);
    fprintf(f,"%f %f %f %f %d\n",x,y,x+cos(v2)*0.05, y+sin(v2)*0.05,0);
}

void box1(FILE * f,double x,double y){
  fprintf(f,"%f %f %f %f %d\n",x,y,x+0.5, y,0);
  fprintf(f,"%f %f %f %f %d\n",x+0.95,y,x+1.45, y,0);
  fprintf(f,"%f %f %f %f %d\n",x,y+0.5,x+0.5, y+0.5,0);
  fprintf(f,"%f %f %f %f %d\n",x+0.95,y+0.5,x+1.45, y+0.5,0);
  
}



 
