#ifndef SECP_MULTIEXPONENT_H
#define SECP_MULTIEXPONENT_H

#include <vector>
#include "GroupElement.h"
#include "Scalar.h"

namespace secp_primitives {

class MultiExponent final {
public:
    MultiExponent(const MultiExponent& other);
    MultiExponent(const std::vector<GroupElement>& generators, const std::vector<Scalar>& powers);
    ~MultiExponent();

    GroupElement get_multiple();

private:
    void  *sc_; // secp256k1_scalar[]
    void  *pt_; // secp256k1_gej[]
    int n_points;
};

}// namespace secp_primitives

#endif //SECP_MULTIEXPONENT_H
