#pragma once
#include "GameObjects/BasicObjects/Interface/tickable.h"
#include "Utilities/wave.h"
#include <vector>


class WaveManager : public Tickable {
 public:
  explicit WaveManager(std::vector<Wave>&& waves) : waves_(std::move(waves)) {};
  void Tick(Time delta) override;
 private:
  std::vector<Wave> waves_;
};
