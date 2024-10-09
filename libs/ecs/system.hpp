#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <set>
#include <memory>
#include <unordered_map>
#include "component.hpp"
#include "entity.hpp"

class System {
public:
  std::set<Entity> mEntities;
};

class SystemManager {
  // Map from system type string pointer to a signature
  std::unordered_map<const char *, Signature> mSignatures{};

  // Map from system type string pointer to a system pointer
  std::unordered_map<const char *, std::shared_ptr<System>> mSystems{};

public:
  template <typename T> std::shared_ptr<T> RegisterSystem();
  template <typename T> void SetSignature(Signature signature);
  void EntityDestroyed(Entity entity);
  void EntitySignatureChanged(Entity entity, Signature entitySignature);
};

#endif // !SYSTEM_HPP
