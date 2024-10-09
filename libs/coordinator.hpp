#ifndef COORDINATOR_HPP
#define COORDINATOR_HPP

#include <memory>
#include "componentmanager.hpp"
#include "entity.hpp"
#include "system.hpp"

class Coordinator {
  std::unique_ptr<ComponentManager> mComponentManager;
  std::unique_ptr<EntityManager> mEntityManager;
  std::unique_ptr<SystemManager> mSystemManager;

public:
  void Init();
  // Entity methods
  Entity CreateEntity();
  void DestroyEntity(Entity entity);
  // Component methods
  template <typename T> void RegisterComponent();
  template <typename T> void AddComponent(Entity entity, T component);
  template <typename T> void RemoveComponent(Entity entity);
  template <typename T> T &GetComponent(Entity entity);
  template <typename T> ComponentType GetComponentType();
  // System methods
  template <typename T> std::shared_ptr<T> RegisterSystem();
  template <typename T> void SetSystemSignature(Signature signature);
};

#endif // COORDINATOR_HPP
