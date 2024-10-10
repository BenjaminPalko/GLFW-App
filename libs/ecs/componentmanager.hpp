#ifndef COMPONENTMANAGER_HPP
#define COMPONENTMANAGER_HPP

#include <array>
#include <unordered_map>
#include <memory>
#include "entity.hpp"
#include "component.hpp"

class IComponentArray {
public:
  virtual ~IComponentArray() = default;
  virtual void EntityDestroyed(Entity entity) = 0;
};

template <typename T> class ComponentArray : public IComponentArray {
  // The packed array of components (of generic type T),
  // set to a specified maximum amount, matching the maximum number
  // of entities allowed to exist simultaneously, so that each entity
  // has a unique spot.
  std::array<T, MAX_ENTITIES> mComponentArray;

  // Map from an entity ID to an array index.
  std::unordered_map<Entity, size_t> mEntityToIndexMap;

  // Map from an array index to an entity ID.
  std::unordered_map<size_t, Entity> mIndexToEntityMap;

  // Total size of valid entries in the array.
  size_t mSize;

public:
  void InsertData(Entity entity, T component);
  void RemoveData(Entity entity);
  T &GetData(Entity entity);
  void EntityDestroyed(Entity entity) override;
};

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
