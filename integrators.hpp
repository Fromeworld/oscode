# include "system.hpp"

class RKFsolver
{
    private:

    public:
    // default constructor
    RKFsolver(); 
    // constructor overloads
    RKFsolver(de_system);

    // class data
    de_system sys;    

    // class functions
    void step();

};

///////////////////////////////////////////////////////////////////////////

RKFsolver::RKFsolver(){
    // Default constructor of RKFsolver (does nothing)
};

RKFsolver::RKFsolver(de_system system){
    // Constructor for an RKFsolver from a system of differential equations
    std::cout << "Constructed an RKFsolver object" << std::endl;
    sys = system;
};

void RKFsolver::step(){
    // Stepper function using the RKF method   
};

///////////////////////////////////////////////////////////////////////////

class WKBsolver
{
    private:

    public:
    // default constructor
    WKBsolver();    
    // constructor overloads
    WKBsolver(de_system);

    // class data
    de_system sys;
    
    // class methods
    void step(); 

};

WKBsolver::WKBsolver(){
    // Default constructor for a WKBsolver (does nothing)
};

WKBsolver::WKBsolver(de_system system){
    // Constructor for a WKBsolver from a system of differential equations
    std::cout << "Constructed a WKBsolver object" << std::endl;
    sys = system;
};

void WKBsolver::step(){
    // Stepper function using the RKF method   
};

