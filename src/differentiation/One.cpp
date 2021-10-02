#include "One.h"
#include "Zero.h"

double One::evaluate(const std::map<std::string, double> &/** variables **/) const {
    return 1;
}

std::shared_ptr<Expression> One::diff(const std::string & /** identifier **/) const {
    return std::make_shared<Zero>();
}

std::shared_ptr<Expression> One::subs(const std::map<std::string, std::shared_ptr<Expression>> & /** subs **/) const {
    return std::make_shared<One>();
}

std::string One::toStr() const {
    return "1";
}

bool One::isOne() const {
    return true;
}
