#ifndef DIALOGUE_TREE_HPP
#define DIALOGUE_TREE_HPP
#include "pch.h"
#include <string>
#include "serialize-interface.hpp"
namespace Altamal::Dialogue{
  /// <summary>
  /// 
  /// </summary>
  /// <typeparam name="char_type"></typeparam>
  template<typename char_type>
  class BasicTree : public Serializable<char_type>
  { 
    namespace nl = nlohmann;
    using string_type = std::basic_string<char_type>;
    using node_type   = BasicNode<char_type>;
    using node_ptr    = std::shared_ptr<node_type>;
    using serializer_type = BasicTreeSerializer<char_type>;
  public:
    BasicTree();
    virtual void Serialize(json_type&);
  private:
    node_ptr entry;
    node_ptr end;
  };
  template<typename char_type>
  inline void BasicTree<char_type>::Serialize(json_type& data)
  {
    Serializable<char_type>::Context context;

  }
}
#endif //DIALOGUE_TREE_HPP
