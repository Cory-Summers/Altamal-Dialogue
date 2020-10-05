#pragma once
#include "pch.h"
#include <vector>
#include "dialogue-node-choice.hpp"
namespace Altamal::Dialogue {
  template<typename char_type>
  class BasicTree;
  template<typename char_type>
  class BasicNode : public Symbolic<char_type>
                  , public Serializable<char_type>
  {
    using string_type = std::basic_string<char_type>;
    using string_cref = string_type const&;
    using vector_type = std::vector<NodeChoice<char_type>>;
    using vector_cref = vector_type const&;
    using tree_type   = BasicTree<char_type>;
  public:
    BasicNode(string_type const& dialogue, vector_type const& choices, tree_type * m_parent);
    string_cref GetDialogue() const { return m_dialogue; }
    vector_cref GetChoices()  const { return m_choices;  }
    tree_type*  GetParent()   const { return m_parent; }
    void        SetParent(tree_type* parent) { m_parent = parent; }
  protected:
    tree_type * m_parent;
    string_type m_dialogue;
    vector_type m_choices;
    bool        is_end_node;
  };
  template<typename char_type>
  inline BasicNode<char_type>::BasicNode(
    string_type const& dialogue, 
    vector_type const& choices,
    tree_type * parent
  )
    : m_parent(parent)
    , m_dialogue(dialogue)
    , m_choices(choices)
  {
  }
}

