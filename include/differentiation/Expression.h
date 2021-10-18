#pragma once

#include <map>
#include <memory>
#include <string>

class Expression;

typedef std::shared_ptr<Expression> ExprPtr;

class Expression {
    // Note that we can't declare variables of type Expression since it is abstract
    // Thus we also can't have them as elements in Vector
    // The workaround is to use ExprPtr in its place, and defined global arithmetic operators to work with it
public:
    [[nodiscard]] virtual double evaluate(const std::map<std::string, double> &variables) const = 0;

    [[nodiscard]] virtual ExprPtr diff(const std::string &id) const = 0;

    [[nodiscard]] virtual ExprPtr subs(const std::map<std::string, ExprPtr> &subs) const = 0;

    [[nodiscard]] virtual ExprPtr simplify() const = 0;

    [[nodiscard]] virtual std::string toStr() const = 0;

    [[nodiscard]] virtual int nodeCount() const;
};

// We need to #include all direct sub-classes because they overload operators for ExprPtr
// The direct sub-classes are in turn responsible for #include-ing their subclasses
#include "UnaryOperator.h"
#include "BinaryOperator.h"
