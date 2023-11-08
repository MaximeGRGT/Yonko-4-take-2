#include <Enemies.h>

void Enemy::dropWood(Ressources& ressources)
{
	ressources.setBois(ressources.getBois() + eWood);
}