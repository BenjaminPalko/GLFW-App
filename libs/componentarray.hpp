#ifndef COMPONENTARRAY_HPP
#define COMPONENTARRAY_HPP

#include <unordered_map>
#include <array>
#include "entity.hpp"

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

#endif // COMPONENTARRAY_HPP
