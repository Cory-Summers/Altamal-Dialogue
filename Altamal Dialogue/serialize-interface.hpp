#pragma once
#include "pch.h"
#include <map>

#include "symbolic.hpp"
// https://wizardsduelgame.files.wordpress.com/2014/12/2015-09-06_source_graph.png
namespace Altamal::Dialogue {
  template<typename char_type>
  class Serializable
  {
    using string_type = std::basic_string<char_type>;
  public:
    virtual void Serialize(json_type&, Context = Context()) = 0;
    void operator<<(json_type& data) { this->Serialize(data); }
  protected:
    struct Context {
      struct SymbolTableData
      {
        enum class Type { None, Node, Choice } type;
        std::shared_ptr<Symbolic<char_type>> sym_obj;
      };
      std::map<string_type, SymbolTableData> symbol_table;
    };
  };
}