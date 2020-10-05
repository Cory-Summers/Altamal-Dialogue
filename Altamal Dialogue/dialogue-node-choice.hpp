#pragma once
#include "pch.h"
#include <functional>

#include "condition-interface.hpp"
#include "serialize-interface.hpp"
#include "symbolic.hpp"
namespace Altamal::Dialogue {
  template<typename char_type>
  class BasicNode;
  template<typename char_type>
  class NodeChoice : public Symbolic<char_type>
                   , public Serializable<char_type>
  {
    using string_type    = std::basic_string<char_type>;
    using string_cref    = string_type const&;
    using node_type      = BasicNode<char_type>;
    using node_ptr       = std::shared_ptr<node_type>;
    using flag_type      = std::uint64_t;
    using flag_cref      = flag_type const&;
    using callback_func  = std::function<void(flag_type const&));
    using condition_ptr  = std::shared_ptr<ICondition>;
    using condition_cref = condition_ptr const&;
  public:
    NodeChoice(
      string_type const&, 
      node_ptr const&, 
      flag_type const&, 
      callback_func const& = callback_func()
    );
    string_cref    GetString()    const { return m_dialogue;  }
    node_ptr       GetNextNode()  const { return m_next_node; }
    flag_cref      GetFlags()     const { return m_flags; }
    callback_func  GetCallback()  const { return m_callback; }
    void           CallCallback() const { m_callback(m_flags); }
    void           SetCondition(condition_ptr const& condition) { m_condition = condition; }
    condition_cref GetCondition() const { return m_condition; }
    bool           HasCondition() const { return (m_condition == true); }
  private:
    string_type   m_dialogue;
    node_ptr      m_next_node;
    flag_type     m_flags;
    callback_func m_callback;
    condition_ptr m_condition;
  };
  template<typename char_type>
  inline NodeChoice<char_type>::NodeChoice(
    string_type   const& dialogue, 
    node_ptr      const& next_node, 
    flag_type     const& flags, 
    callback_func const& callback
  )
    : m_dialogue(dialogue)
    , m_next_node(next_node)
    , m_flags(flags)
    , m_callback(callback)
  {
  }
}
