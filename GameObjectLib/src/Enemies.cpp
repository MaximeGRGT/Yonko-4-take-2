#include <Enemies.h>
#include <Maths/Vector2.h>

void Enemy::dropWood(Ressources& ressources)
{
	ressources.setBois(ressources.getBois() + eWood);
}

void Enemy::attackBase(Base& target) 
{
	target.setHealth(target.getHealth() - eDamage);
}

void Enemy::move()
{
	SetPosition(GetPosition() + Maths::Vector2<float>::Left);
}