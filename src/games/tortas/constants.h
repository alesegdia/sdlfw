#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

// Player
constexpr float PLAYER_X_SPEED = 5.f;
constexpr float PLAYER_Y_SPEED = 5.f;
constexpr int PLAYER_SHOOT_RATE = 500;
constexpr float PLAYER_JUMP_IMPULSE=-5.f;
constexpr float PLAYER_JUMP_GRAVITY=.5f;
const int PLAYER_PUNCH_DURATION = 20;

// Bullet
constexpr int BULLET_SPEED = 10;
constexpr int BULLET_DESTROY_X_LIMIT = 800;

// Spawner
constexpr int SPAWNER_RESPAWN_TIME = 500;
constexpr int SPAWNER_BOT_TOLERANCE = 150;
constexpr int SPAWNER_TOP_TOLERANCE = 100;
constexpr int SPAWNER_WAIT_TIME = 1000;
constexpr int SPAWNER_N_SPAWNS = 5;

// Enemy
constexpr float ENEMY_SINE_AMPLITUDE = 50;
constexpr float ENEMY_SINE_PERIOD = 10;
constexpr float ENEMY_X_SPEED = 4.f;
constexpr float ENEMY_X_DESTROY_LIMIT = 100;

#endif // CONSTANTS_H_INCLUDED
