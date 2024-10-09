#ifndef COMPONENTMANAGER_HPP
#define COMPONENTMANAGER_HPP

#include <unordered_map>
#include <memory>
#include <cassert>
#include "component.hpp"
#include "componentarray.hpp"

class ComponentManager {
  // Map from type string pointer to a component type
  std::unordered_map<const char *, ComponentType> mComponentTypes{};

  // Map from type string pointer to a component array
  std::unordered_map<const char *, std::shared_ptr<IComponentArray>>
      mComponentArrays{};

  // The component type to be assigned to the next registered component -
  // starting at 0
  ComponentType mNextComponentType{};

  // Convenience function to get the statically casted pointer to the
  // ComponentArray of type T.
  template <typename T> std::shared_ptr<ComponentArray<T>> GetComponentArray();

public:
  template <typename T> void RegisterComponent();
  template <typename T> ComponentType GetComponentType();
  template <typename T> void AddComponent(Entity entity, T component);
  template <typename T> void RemoveComponent(Entity entity);
  template <typename T> T &GetComponent(Entity entity);
  void EntityDestroyed(Entity entity);
};

#endif // COMPONENTMANAGER_HPP
