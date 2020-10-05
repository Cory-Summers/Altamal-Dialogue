#pragma once
namespace Altamal::Dialogue {
  class ICondition
  {
  public:
    enum class Type { Hidden, Grey, Shown };
    virtual bool ConditionMet() = 0;
    virtual Type GetType()  const = 0;
  };
}
