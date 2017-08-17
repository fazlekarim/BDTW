/*
 * BDTW.cpp
 *
 *  Created on: Jan 21, 2015
 *      Author: Diego Furtado Silva (diego.fsilva@gmail.com)
 */

#include "BDTW.h"
#include <algorithm>
#include <vector>

BDTW::BDTW() {
	// TODO Auto-generated constructor stub

}

BDTW::~BDTW() {
	// TODO Auto-generated destructor stub
}

/**
 * The simple ED between two given observations/points
**/
double** BDTW::bdtw_runs(TimeSeries x) {
//	std::vector<double> x1 = x.getSeriesValues();
//	int j = 0;
//  double k[20];
//  double t = x1[0];
//  k[0]= {(x1[0])};
//  double v[x1.size()];
//  v[0]= 1;
	
//	std::vector<double> x1 = x.getSeriesValues();
//	double a[sizeof(x1)];
//	std::copy(x1.begin(), x1.end(), a);
//	int j = 0;
//
//	double k[sizeof(a)];
//  k[0]= a[0];
//  double v[sizeof(a)];
//  v[0]= 1;
//	
	int j = 0;
	double k[(x.getLength())];
	k[0]= x.getValueAt(0);

    double v[(x.getLength())];
    v[0]= 1;
 
  

  
  for (double i=1; i<x.getLength();i++){
	  if (i == 1 && x.getValueAt(i)==x.getValueAt(i-1)){
		  j = j+1;
		  k[j]=x.getValueAt(i);
		  v[j] = 1;
	  }
	  if (i == x.getLength() && x.getValueAt(i)==x.getValueAt(i-1)){
		  j = j+1;
		  k[j]=x.getValueAt(i);
		  v[j] = 1;
	  }
	  
	  if (x.getValueAt(i)==x.getValueAt(i-1)&& i!= 2 && i !=x.getLength()){
		  v[j]=v[j]+1;
	  }
	  
	  if (x.getValueAt(i) != x.getValueAt(i-1)){
		  j = j+1;
		  k[j]=x.getValueAt(i);
		  v[j] = 1;
	  }

//  for (double i=1; i<(x1.size());i++){
//	  if (i == 1 && x1[i]==x1[i-1]){
//		  j = j+1;
//		  k[j]=x1[i];
//		  v[j] = 1;
//	  }
//	  if (i == (x1.size()) && x1[i]==x1[i-1]){
//		  j = j+1;
//		  k[j]=x1[i];
//		  v[j] = 1;
//	  }
//	  
//	  if (x1[i]==x1[i-1]&& i!= 2 && i !=(x1.size())){
//		  v[j]=v[j]+1;
//	  }
//	  
//	  if (x1[i] != x1[i-1]){
//		  j = j+1;
//		  k[j]=x1[i];
//		  v[j] = 1;
//	  }	  	  
//	  
//  }
  
  }
  static double *E[2];
  E[0] = k;
  E[1] = v;
  
  
//  double random = E[0][5];
//  
//  printf ("%d\t",E[0][5]);
//  
//  printf("here");


  
  //return (E);
  return (E);
}

/**
 * Squared ED between two time series
**/
double BDTW::dtw_ub(double** x2, double** y2) {
	
	int lx2 = sizeof(x2[0]);
	int ly2 = sizeof(y2[0]);
	
	if (x2==y2){
		printf("hereweare");
		
	}
	
	double E[lx2][ly2];
	
//	double val = std::max (x2[1][0],y2[1][0]);
	
	E[0][0] = (std::max (x2[1][0],y2[1][0]))*(x2[0][0]-y2[0][0])*(x2[0][0]-y2[0][0]);
	
	for (int i = 1; i<lx2; i++){
		E[i][0] = E[i-1][0] + x2[1][i]*(x2[0][i] - y2[0][0])*(x2[0][i] - y2[0][0]);		
	}
	
	for (int i = 1; i<ly2; i++){
	    E[0][i] = E[0][i-1] + y2[1][i]*(x2[0][0] - y2[0][i])*(x2[0][0] - y2[0][i]);
	}
	
	for (int j = 1; j<ly2; j++){
		for (int i = 1; i<lx2; i++){
			if (x2[1][i]==1 && y2[1][j]==1){
				E[i][j] = std::min(std::min(E[(i-1)][j],E[(i-1)][(j-1)]), E[i][(j-1)]) + (x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
			}
			if (x2[1][i] !=1 && y2[1][j]==1){
				double t = E[i-1][j]+x2[1][i]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double d = E[i-1][j-1] + x2[1][i]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double l = E[i][j-1]+(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				
//				double mydbs []={t,d,l}
				E[i][j]=std::min(std::min(t,d),l);
			}
			
			if (x2[1][i]==1 && y2[1][j]!=1){
				double t = E[i-1][j]+(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double d = E[i-1][j-1]+y2[1][j]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double l = E[i][j-1]+y2[1][j]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				E[i][j] = std::min(std::min(t,d),l);
			}
			
			if (x2[1][i]!=1 && y2[1][j] != 1){
				double t = E[i-1][j] +x2[1][i]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double d = E[i-1][j-1]+std::max(x2[1][i],y2[1][j])*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double l = E[i][j-1] + y2[1][j]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				E[i][j] = std::min (std::min(t,d),l);
			}
		}
	}
	
	printf("xz");
	return (E[lx2-1][ly2-1]);
	
	


}


double BDTW::dtw_ub_all(TimeSeries x, TimeSeries y, double warping) {
	int j = 0;
	double k[(x.getLength())];
	
//	double *k;
//	k = new double[(x.getLength())];
	k[0]= x.getValueAt(0);

    double v[(x.getLength())];
//	double *v;
//	v = new double[(x.getLength())];
    v[0]= 1;

	//std::vector<double> k;
	//k.push_back(x.getValueAt(0));
	
	//std::vector<double> v;
	//v.push_back(x.getValueAt(0));
 
  

  
  for (double i=1; i<x.getLength();i++){
	  if (i == 1 && x.getValueAt(i)==x.getValueAt(i-1)){
		  j = j+1;
		  
		  k[j]=x.getValueAt(i);
		  v[j] = 1;
		  //k.insert(j,x.getValueAt(i));
		  //v.insert(j,1);
	  }
	  if (i == x.getLength() && x.getValueAt(i)==x.getValueAt(i-1)){
		  j = j+1;
		  k[j]=x.getValueAt(i);
		  v[j] = 1;
		  //k.insert(j,x.getValueAt(i));
		  //v.insert(j,1);
	  }
	  
	  if (x.getValueAt(i)==x.getValueAt(i-1)&& i!= 2 && i !=x.getLength()){
		  v[j]=v[j]+1;
		  //v.insert(j,)
	  }
	  
	  if (x.getValueAt(i) != x.getValueAt(i-1)){
		  j = j+1;
		  k[j]=x.getValueAt(i);
		  v[j] = 1;
		  //k.insert(j,x.getValueAt(i));
		  //v.insert(j,1);
	  }

//  for (double i=1; i<(x1.size());i++){
//	  if (i == 1 && x1[i]==x1[i-1]){
//		  j = j+1;
//		  k[j]=x1[i];
//		  v[j] = 1;
//	  }
//	  if (i == (x1.size()) && x1[i]==x1[i-1]){
//		  j = j+1;
//		  k[j]=x1[i];
//		  v[j] = 1;
//	  }
//	  
//	  if (x1[i]==x1[i-1]&& i!= 2 && i !=(x1.size())){
//		  v[j]=v[j]+1;
//	  }
//	  
//	  if (x1[i] != x1[i-1]){
//		  j = j+1;
//		  k[j]=x1[i];
//		  v[j] = 1;
//	  }	  	  
//	  
//  }
  
  }
  
  double newk[j+2];
  double newv[j+2];
  for (int i=0; i<=j+1; i++){
	  newk[i]=k[i];
	  newv[i]=v[i];
	  if (i==(j+1)){
		  newk[i]=newk[i-1];
		  newv[i]=1;
		  newv[i-1]=newv[i-1]-1;
	  }
  }
  
  static double *E2[2];
  E2[0] = newk;
  E2[1] = newv;
  //double k123[(x.getLength())];
  //k123[0]=5;
  //E2[0] = k123;
 // E2[1] = k123;
  
//  double random = E[0][5];
//  
//  printf ("%d\t",E[0][5]);
//  
//  printf("here");


  
  //return (E);
  int j1 = 0;
  double k1[(y.getLength())];
  k1[0]= y.getValueAt(0);
  
  double v1[(y.getLength())];
  v1[0]= 1;
 
  

//	double *k1;
//	k1 = new double[(y.getLength())];
//	k1[0]= x.getValueAt(0);

    //double v[(x.getLength())];
//	double *v1;
//	v1 = new double[(y.getLength())];
//	v1[0]= 1;


  
  for (double i=1; i<y.getLength();i++){
	  if (i == 1 && y.getValueAt(i)==y.getValueAt(i-1)){
		  j1 = j1+1;
		  k1[j1]=y.getValueAt(i);
		  v1[j1] = 1;
	  }
	  if (i == y.getLength() && y.getValueAt(i)==y.getValueAt(i-1)){
		  j1 = j1+1;
		  k1[j1]=y.getValueAt(i);
		  v1[j1] = 1;
	  }
	  
	  if (y.getValueAt(i)==y.getValueAt(i-1)&& i!= 2 && i !=y.getLength()){
		  v1[j1]=v1[j1]+1;
	  }
	  
	  if (y.getValueAt(i) != y.getValueAt(i-1)){
		  j1 = j1+1;
		  k1[j1]=y.getValueAt(i);
		  v1[j1] = 1;
	  }

//  for (double i=1; i<(x1.size());i++){
//	  if (i == 1 && x1[i]==x1[i-1]){
//		  j = j+1;
//		  k[j]=x1[i];
//		  v[j] = 1;
//	  }
//	  if (i == (x1.size()) && x1[i]==x1[i-1]){
//		  j = j+1;
//		  k[j]=x1[i];
//		  v[j] = 1;
//	  }
//	  
//	  if (x1[i]==x1[i-1]&& i!= 2 && i !=(x1.size())){
//		  v[j]=v[j]+1;
//	  }
//	  
//	  if (x1[i] != x1[i-1]){
//		  j = j+1;
//		  k[j]=x1[i];
//		  v[j] = 1;
//	  }	  	  
//	  
//  }
  
  }
  
  double newk1[j1+2];
  double newv1[j1+2];
  for (int i=0; i<=j1+1; i++){
	  newk1[i]=k1[i];
	  newv1[i]=v1[i];
	  if (i==(j1+1)){
		  newk1[i]=newk1[i-1];
		  newv1[i]=1;
		  newv1[i-1]=newv1[i-1]-1;
	  }
  }
  static double *E1[2];
  E1[0] = newk1;
  E1[1] = newv1;
  
  
//  double random = E[0][5];
//  
//  printf ("%d\t",E[0][5]);
//  
//  printf("here");


  
  //return (E);
  
  double** x2 = E2;
  double** y2 = E1;
  
	int lx2 = (sizeof (newk)/sizeof(*newk));
//int lx2 = 1;
///	int lx2 = sizeof(x2[0]);
	int ly2 = (sizeof (newk1)/sizeof(*newk1));
	
	int g1 = ceil(warping*lx2)+1;
	int g2 = ceil(warping*ly2)+1;
	
	if (x2==y2){
		printf("hereweare");
		
	}
	
	double E[lx2][ly2];
	
	for (int i=0; i<lx2; i++){
		for (int j=0; j<ly2; j++){
			E[i][j]=99999999;
		}
	}
	
//	double val = std::max (x2[1][0],y2[1][0]);
	
	E[0][0] = (std::max (x2[1][0],y2[1][0]))*(x2[0][0]-y2[0][0])*(x2[0][0]-y2[0][0]);
	
	/*for (int i = 1; i<lx2; i++){
		E[i][0] = E[i-1][0] + x2[1][i]*(x2[0][i] - y2[0][0])*(x2[0][i] - y2[0][0]);		
	}
	
	for (int i = 1; i<ly2; i++){
	    E[0][i] = E[0][i-1] + y2[1][i]*(x2[0][0] - y2[0][i])*(x2[0][0] - y2[0][i]);
	}*/
	
	for (int i = 1; i<g1; i++){
		E[i][0] = E[i-1][0] + x2[1][i]*(x2[0][i] - y2[0][0])*(x2[0][i] - y2[0][0]);		
	}
	
	for (int i = 1; i<g2; i++){
	    E[0][i] = E[0][i-1] + y2[1][i]*(x2[0][0] - y2[0][i])*(x2[0][0] - y2[0][i]);
	}
	
	g1=g1+1;
	int z=1;
	
	for (int j = 1; j<ly2; j++){
		for (int i = z; i<g1; i++){
			if (x2[1][i]==1 && y2[1][j]==1){
				E[i][j] = std::min(std::min(E[(i-1)][j],E[(i-1)][(j-1)]), E[i][(j-1)]) + (x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				//printf("E is %f \n", E[i][j]);
			}
			if (x2[1][i] !=1 && y2[1][j]==1){
				double t = E[i-1][j]+x2[1][i]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double d = E[i-1][j-1] + x2[1][i]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double l = E[i][j-1]+(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				
//				double mydbs []={t,d,l}
				E[i][j]=std::min(std::min(t,d),l);
			}
			
			if (x2[1][i]==1 && y2[1][j]!=1){
				double t = E[i-1][j]+(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double d = E[i-1][j-1]+y2[1][j]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double l = E[i][j-1]+y2[1][j]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				E[i][j] = std::min(std::min(t,d),l);
			}
			
			if (x2[1][i]!=1 && y2[1][j] != 1){
				double t = E[i-1][j] +x2[1][i]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double d = E[i-1][j-1]+std::max(x2[1][i],y2[1][j])*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				double l = E[i][j-1] + y2[1][j]*(x2[0][i]-y2[0][j])*(x2[0][i]-y2[0][j]);
				E[i][j] = std::min (std::min(t,d),l);
			}
		}
		
		if (g1<lx2){
			g1=g1+1;
		}
		if ((j+1)==(ly2-1)){
			g1=lx2;
		}
		if (j>=g2 && z<(lx2-1)){
			z=z+1;
		}
	}
	printf("");
	int final1 = 5;
	
	return (E[lx2-1][ly2-1]);





	}


/**
 * Regular ED between two time series
**/

