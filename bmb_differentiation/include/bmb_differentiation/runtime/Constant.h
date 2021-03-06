#pragma once

#include <bmb_differentiation/runtime/Expression.h>
#include <memory>
#include <string>
#include <unordered_map>

class Constant;

using ConstPtr = std::shared_ptr<Constant>;

class Constant : public Expression {
 public:
  Constant() = delete;

  static ConstPtr make(const double& value);

  [[nodiscard]] double evaluate(
      const std::unordered_map<std::string, double>& variables) const override;

  [[nodiscard]] ExprPtr diff(const std::string& identifier) const override;

  [[nodiscard]] ExprPtr subs(
      const std::unordered_map<std::string, ExprPtr>& subs) const override;

  [[nodiscard]] ExprPtr simplify() const override;

  [[nodiscard]] std::string toStr() const override;

  [[nodiscard]] double getValue() const;

 protected:
  explicit Constant(const double& value) : value(value) {}

 private:
  double value;
};
