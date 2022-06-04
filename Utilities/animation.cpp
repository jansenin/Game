#include "animation.h"

#include <utility>

Animation::Animation(std::vector<QPixmap*> frames, Time time_between_frames)
  : frames_(std::move(frames)),
  time_between_frames_(time_between_frames),
  time_to_next_frame_(time_between_frames),
  frame_index_(0),
  was_ended_during_previous_update(false) {
  assert(!frames_.empty());
}

Animation::Animation(QPixmap* pixmap)
  // doesn't matter what time between frames is, it just must be non-zero
  : Animation(std::vector<QPixmap*>{pixmap}, 1_ms) {}

void Animation::Tick(Time delta) {
  time_to_next_frame_ -= delta;
  if (time_to_next_frame_ < 0_ms) {
    int frames_passed =
        abs(time_to_next_frame_.ms() / time_between_frames_.ms());
    ++frames_passed;
    time_to_next_frame_ += time_between_frames_ * frames_passed;
    bool animation_ended = false;
    if (frame_index_ + frames_passed >= frames_.size()) {
      animation_ended = true;
    }
    SetIndex(frame_index_ + frames_passed);
    was_ended_during_previous_update = animation_ended;
  }
}

const QPixmap* Animation::Frame() const {
  return frames_.at(frame_index_);
}

QPixmap* Animation::Frame() {
  return frames_.at(frame_index_);
}

void Animation::SetIndex(int index) {
  was_ended_during_previous_update = false;
  if (index >= frames_.size()) {
    was_ended_during_previous_update = true;
  }
  frame_index_ = ((index % frames_.size()) + frames_.size()) % frames_.size();
}

void Animation::SetTimeBetweenFrames(Time time) {
  time_between_frames_ = time;
}

Time Animation::TimeBetweenFrames() const {
  return time_between_frames_;
}

Time Animation::TimeToNextFrame() const {
  return time_to_next_frame_;
}

int Animation::FrameIndex() const {
  return frame_index_;
}

void Animation::NextFrame() {
  SetIndex(frame_index_ + 1);
}

void Animation::Reset() {
  time_to_next_frame_ = time_between_frames_;
  SetIndex(0);
  was_ended_during_previous_update = false;
}

bool Animation::WasEndedDuringPreviousUpdate() const {
  return was_ended_during_previous_update;
}

int Animation::FrameCount() const {
  return frames_.size();
}
