#pragma once
namespace rogue_engine {

class FpsLimiter {
public:
  FpsLimiter();

  void init(float maxFPS);

  void setMaxFPS(float maxFPS);

  void begin();

  // end will return current FpsLimiter
  float end();

private:
  void calculateFPS();

  float _fps;
  float _maxFPS;
  float _frameTime;
  unsigned int _startTicks;
};

} // namespace rogue_engine
