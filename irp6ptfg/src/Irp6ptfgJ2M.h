#ifndef Irp6ptfgJ2M_H_
#define Irp6ptfgJ2M_H_

#include <rtt/TaskContext.hpp>
#include <rtt/Port.hpp>
#include <Eigen/Dense>

class Irp6ptfgJ2M : public RTT::TaskContext {
 public:
  Irp6ptfgJ2M(const std::string& name);
  virtual ~Irp6ptfgJ2M();

  bool configureHook();
  void updateHook();
 private:
  bool i2mp(const double* joints, double* motors);
  bool checkMotorPosition(const double * motor_position);
  RTT::InputPort<Eigen::VectorXd> port_joint_position_;
  RTT::OutputPort<Eigen::VectorXd> port_motor_position_;

  Eigen::VectorXd motor_position_, joint_position_;



  //! Variable related to the computations of the gripper spread.
  double inv_a_7;

  //! Variable related to the computations of the gripper spread.
  double inv_b_7;

  //! Variable related to the computations of the gripper spread.
  double inv_c_7;

  //! Variable related to the computations of the gripper spread.
  double inv_d_7;
};

#endif /* Irp6ptfgJ2M_H_ */
