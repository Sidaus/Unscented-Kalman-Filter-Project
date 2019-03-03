#include "tools.h"
#include <iostream>

using Eigen::VectorXd;
using std::vector;
using std::cout;
using std::endl;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
   * TODO: Calculate the RMSE here.
   */
  // we calculate the RMSE just like the last time no changes there
  //Lets create the RSME vector
  VectorXd RSME = VectorXd(4);
  RSME << 0,0,0,0;
  if ((estimations.size()!=ground_truth.size())||(estimations.size()==0))
  {
    cout << "Estimation and ground truth vector sizes DON'T match or estimation vector size is ZERO" << endl;
    return RSME; //terminates the function
  }
  
  //Now to implement the RSME 
  for (unsigned int i=0; i < estimations.size(); ++i) 
  {
    VectorXd residual = estimations[i] - ground_truth[i];
  	residual = residual.array()*residual.array();
  	RSME += residual;
  }

  // calculate the mean
  RSME = RSME/estimations.size();

  // calculate the squared root
  RSME = RSME.array().sqrt();

  // return the result
  return RSME;
}

// I simply copied the whole thing from the last project