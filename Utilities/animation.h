#pragma once

#include <vector>

#include <QPixmap>

#include "Utilities/time.h"
#include "GameObjects/BasicObjects/Interface/tickable.h"

class Animation : public Tickable {
 public:
  Animation(std::vector<QPixmap*>  frames, Time time_between_frames);
  explicit Animation(QPixmap* pixmap);

  void Tick(Time delta) override;
  QPixmap* Frame();
  [[nodiscard]] const QPixmap* Frame() const;
  void SetIndex(int index);
  void SetTimeBetweenFrames(Time time);
  void NextFrame();
  void Reset();

  [[nodiscard]] bool WasEndedDuringPreviousUpdate() const;
  [[nodiscard]] int FrameCount() const;
  [[nodiscard]] Time TimeBetweenFrames() const;
  [[nodiscard]] Time TimeToNextFrame() const;
  [[nodiscard]] int FrameIndex() const;

 protected:
  std::vector<QPixmap*> frames_;
  Time time_between_frames_;
  Time time_to_next_frame_;
  int frame_index_;
  bool was_ended_during_previous_update;
};
