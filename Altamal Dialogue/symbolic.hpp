#pragma once
#include "pch.h"
namespace Altamal::Dialogue {
  template<typename char_type>
  struct Symbolic
  {
    using string_type = std::basic_string<char_type>;
  private:
    using string_cref = string_type const&;
    string_type m_name;
  public:
    string_cref GetName() const    { return m_name; }
    void SetName(string_cref name) { m_name = name; }
  };
}
