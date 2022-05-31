#pragma once
#include "GameObjects/Interface/tickable.h"
#include "Utilities/wave.h"
#include <utility>
#include <vector>


class WaveManager : public Tickable {
 public:
  explicit WaveManager(std::vector<Wave>&& waves) : waves_(std::move(waves)) {}
  void Tick(Time delta) override;
 private:
  std::vector<Wave> waves_;
};
