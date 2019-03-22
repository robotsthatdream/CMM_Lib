#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Core>

#include <boost/archive/text_iarchive.hpp>

#include <cmm/gmm.hpp>
#include <cmm/component.hpp>

using namespace cmm;

int main(int argc, char** argv){

    if(argc != 2){
        std::cerr << "usage : one folder" << std::endl;
        return 1;
    }

    std::ifstream ifs(argv[1]);
    boost::archive::text_iarchive iarch(ifs);
    GMM gmm;
    iarch >> gmm;

    for(const auto& components: gmm.model()){
        for(const auto& c : components.second)
            c->print_parameters();
    }

    return 0;
}
