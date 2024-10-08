#include "QmParticle.h"
#include "QmUpdater.h"

using namespace Quantum;

QmParticle::QmParticle() : QmBody(TYPE_PARTICLE), position(0, 0, 0), velocity(0, 0, 0), acceleration(0, 0, 0) {
}

QmParticle::QmParticle(glm::vec3 pos, glm::vec3 vel, glm::vec3 acc, float mass, int charge)
        : QmBody(TYPE_PARTICLE), position(pos), velocity(vel), acceleration(acc),
          charge(charge), invMass(1 - mass), damping(0.995f) {
}

QmParticle::QmParticle(glm::vec3 position, glm::vec3 velocity, glm::vec3 acceleration, float mass, int charge,
    float damping): QmParticle(position, velocity, acceleration, mass, charge)
{
    this->damping = damping;
}

QmParticle::~QmParticle() {
    delete updater;
}

void QmParticle::integrate(float t) {
    acceleration = forceAccumulator * invMass;
    position += t * velocity;
    velocity += t * acceleration;
    velocity *= damping;
    if (updater != nullptr) {
        updater->update(position);
    }

}

glm::vec3 QmParticle::getAcc() {
    return acceleration;
}

glm::vec3 QmParticle::getVel() {
    return velocity;
}

glm::vec3 QmParticle::getPos() const {
    return position;
}

void QmParticle::setUpdater(QmUpdater *updater) {
    this->updater = updater;
}

QmUpdater* QmParticle::getUpdater() const
{
    return updater;
}

void QmParticle::setDamping(float damping)
{
this->damping = damping;
}

float QmParticle::getDamping() const
{
    return damping;
}

void QmParticle::addForce(const glm::vec3 &force) {
    forceAccumulator += force;
}

void QmParticle::reset() {
    acceleration = glm::vec3{0.0};
    forceAccumulator = glm::vec3{0.0};
}

int QmParticle::getCharge() const {
    return charge;
}

float QmParticle::getInvMass() const {
    return invMass;
}

float QmParticle::getMass() const
{
    return 1 - invMass;
}


