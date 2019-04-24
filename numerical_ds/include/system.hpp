#pragma once
#include "interpolator.hpp"

class de_system
    {
    private:
        // interpolation checker
        

    public:
        // constructors
        template<typename X, typename Y, typename Z> de_system(X ts, Y ws, Z gs, bool isglogw=false, bool islogg=false);
        de_system(std::complex<double> (*w)(double), std::complex<double> (*g)(double));
        de_system(const Eigen::VectorXd &ts, const Eigen::VectorXcd &ws, const Eigen::VectorXcd &gs, bool islogw=false, bool islogg=false);
        std::function<std::complex<double>(double)> w;
        std::function<std::complex<double>(double)> g;
        std::complex<double> _w(double);
        std::complex<double> _g(double);
        std::complex<double> _logw(double);
        std::complex<double> _logg(double);
        bool interp;
        LinearInterpolator<double, std::complex<double>> _winterp, _ginterp;
};
    
de_system::de_system(std::complex<double> (*W)(double), std::complex<double> (*G)(double)){
        // default constructor for a system of differential equations
    
        interp = false;
        //w = W;
        //g = G;
    };

de_system::de_system(const Eigen::VectorXd &ts, const Eigen::VectorXcd &ws, const Eigen::VectorXcd &gs, bool islogw, bool islogg){
    
    interp = true;
    LinearInterpolator<double, std::complex<double>> winterp;
    LinearInterpolator<double, std::complex<double>> ginterp;
    int n = ts.size();
    for(int i=0; i<n; i++){
        winterp.insert(ts(i),ws(i));
        ginterp.insert(ts(i),gs(i));
    };
    _winterp = winterp;
    _ginterp = ginterp;
    if(islogw)
        w = std::bind(&de_system::_logw, this, std::placeholders::_1);
    else
        w = std::bind(&de_system::_w, this, std::placeholders::_1);
    if(islogg)
        g = std::bind(&de_system::_logg, this, std::placeholders::_1);
    else
        g = std::bind(&de_system::_g, this, std::placeholders::_1);
};

template<typename X, typename Y, typename Z> de_system::de_system(X ts, Y ws, Z gs, bool islogw, bool islogg){
    
    interp = true;
    LinearInterpolator<double, std::complex<double>> winterp;
    LinearInterpolator<double, std::complex<double>> ginterp;
    auto iter_t = ts.begin();
    auto iter_w = ws.begin();
    auto iter_g = gs.begin();
    while(iter_t!=ts.end() || iter_w!=ws.end() || iter_g!=gs.end()){
        winterp.insert((*iter_t),(*iter_w));
        ginterp.insert((*iter_t),(*iter_g));
        ++iter_t;
        ++iter_w;
        ++iter_g;
    };
    _winterp = winterp;
    _ginterp = ginterp;
    if(islogw)
        w = std::bind(&de_system::_logw, this, std::placeholders::_1);
    else
        w = std::bind(&de_system::_w, this, std::placeholders::_1);
    if(islogg)
        g = std::bind(&de_system::_logg, this, std::placeholders::_1);
    else
        g = std::bind(&de_system::_g, this, std::placeholders::_1);
};

std::complex<double> de_system::_w(double t){
    return _winterp(t);
};

std::complex<double> de_system::_g(double t){
    return _ginterp(t);
};

std::complex<double> de_system::_logw(double t){
    return std::exp(_winterp(t));
};

std::complex<double> de_system::_logg(double t){
    return std::exp(_ginterp(t));
};

