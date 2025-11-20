// 적군 AI도 GA or 규칙 기반으로 학습 가능
#include "EnemyAI.h"

void EnemyAI::update(TileMap* map, float px, float py) {
    // 단순한 GA 기반 또는 추적 알고리즘
    double dx = px - x;
    double dy = py - y;

    double len = hypot(dx, dy);
    x += (dx / len) * speed;
    y += (dy / len) * speed;

    if (map->isWall(x, y))
        speed = 0; // 충돌 처리
}
