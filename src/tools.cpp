#include "tools.h"
#include <iostream>

using std::vector;
using Eigen::VectorXd;
using std::vector;
using namespace std;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
   * TODO: Calculate the RMSE here.
   */

    VectorXd rmse(4);
    rmse << 0, 0, 0, 0;

    // check the validity of the following inputs
    // * the estimate vector size should not be zero
    // * the estimate vector size should equal groud truth vector size
    if (estimations.size() != ground_truth.size() || estimations.size() == 0) {
        cout << "Invalid estimation or ground_truth data" << "/n";
        return rmse;
    }

    // accumulate squared residuals
    for (unsigned int i = 0; i < estimations.size(); i++) {
        VectorXd residual = estimations[i] - ground_truth[i];

        // coefficient-wise multiplication
        residual = residual.array() * residual.array();
        rmse += residual;
    }

    // calculate the mean
    rmse = rmse / estimations.size();

    // calculate the squared root
    rmse = rmse.array().sqrt();

    // return the result
    return rmse;

}