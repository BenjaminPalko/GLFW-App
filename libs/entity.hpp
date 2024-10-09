#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <cstdint>
#include <queue>
#include <array>
#include "component.hpp"

using Entity = std::uint32_t;

const Entity MAX_ENTITIES = 5000;

class EntityManager {
  // Queue of unused entity IDs
  std::queue<Entity> mAvailableEntities{};

  // Array of signatures where the index corresponds to the entity ID
  std::array<Signature, MAX_ENTITIES> mSignatures{};

  // Total living entities - used to keep limits on how many exist
  uint32_t mLivingEntityCount{};

public:
  EntityManager();
  Entity CreateEntity();
  void DestroyEntity(Entity entity);
  void SetSignature(Entity entity, Signature signature);
  Signature GetSignature(Entity entity);
};

#endif // ENTITY_HPP
