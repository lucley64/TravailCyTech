#include "QmParticle.h"

#include "QmUpdater.h"

using namespace Quantum;

QmParticle::QmParticle() : QmBody(TYPE_PARTICLE), position({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}),
                           velocity({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}),
                           acceleration({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}})
{
}

QmParticle::QmParticle(const glm::vec3 position, const glm::vec3 velocity, const glm::vec3 acceleration,
                       const float mass, const int charge)
    : QmBody(TYPE_PARTICLE), position({position, position, position, position}),
      velocity({velocity, velocity, velocity, velocity}),
      acceleration({acceleration, acceleration, acceleration, acceleration}),
      charge(charge), invMass(1 - mass), damping(0.995f)
{
}

QmParticle::QmParticle(const glm::vec3 position, const glm::vec3 velocity, const glm::vec3 acceleration,
                       const float mass, const int charge,
                       const float damping): QmParticle(position, velocity, acceleration, mass, charge)
{
    this->damping = damping;
}

QmParticle::~QmParticle()
{
    delete updater;
}

void QmParticle::integrate(const float t)
{
    acceleration[0] = forceAccumulator[0] * invMass;
    position[0] += t * velocity[0];
    velocity[0] += t * acceleration[0];
    velocity[0] *= damping;
    if (updater != nullptr)
    {
        updater->update(position[0]);
    }
}

void QmParticle::integrate(const float t, const unsigned int i)
{
    position[i] = position[0] + t * velocity[i - 1];
    velocity[i] = velocity[0] + t * acceleration[i - 1];
    velocity[i] *= damping;
    // if (updater != nullptr)
    // {
    //     updater->update(position[i]);
    // }
}

void QmParticle::integrateRK4(const float t)
{
    velocity[0] += t *
        ((acceleration[0] + 2.0f * acceleration[1] + 2.0f * acceleration[2] + acceleration[3]) / 6.0f);
    position[0] += t *
        ((velocity[0] + 2.0f * velocity[1] + 2.0f * velocity[2] + velocity[3]) / 6.0f);
    // velocity[0] *= damping;
    if (updater != nullptr)
    {
        updater->update(position[0]);
    }
}

void QmParticle::computeAccelerations(unsigned i)
{
    acceleration[i] = forceAccumulator[i] * invMass;
}

std::array<glm::vec3, 4> QmParticle::getAcc() const
{
    return acceleration;
}

std::array<glm::vec3, 4> QmParticle::getVel() const
{
    return velocity;
}

std::array<glm::vec3, 4> QmParticle::getPos() const
{
    return position;
}

void QmParticle::setUpdater(QmUpdater* updater)
{
    this->updater = updater;
}

QmUpdater* QmParticle::getUpdater() const
{
    return updater;
}

void QmParticle::setDamping(const float damping)
{
    this->damping = damping;
}

float QmParticle::getDamping() const
{
    return damping;
}

void QmParticle::addForce(const glm::vec3& force, unsigned int i)
{
    forceAccumulator[i] += force;
}

void QmParticle::reset()
{
    acceleration[0] = glm::vec3{0.0};
    acceleration[1] = glm::vec3{0.0};
    acceleration[2] = glm::vec3{0.0};
    acceleration[3] = glm::vec3{0.0};
    forceAccumulator[0] = glm::vec3{0.0};
    forceAccumulator[1] = glm::vec3{0.0};
    forceAccumulator[2] = glm::vec3{0.0};
    forceAccumulator[3] = glm::vec3{0.0};
}

int QmParticle::getCharge() const
{
    return charge;
}

float QmParticle::getInvMass() const
{
    return invMass;
}

float QmParticle::getMass() const
{
    return 1 - invMass;
}
