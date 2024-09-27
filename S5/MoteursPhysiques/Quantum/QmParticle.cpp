#include "QmParticle.h"
#include "QmUpdater.h"

using namespace Quantum;

QmParticle::QmParticle() : QmBody(TYPE_PARTICLE), position(0, 0, 0), velocity(0, 0, 0), acceleration(0, 0, 0) {
}

QmParticle::QmParticle(glm::vec3 pos, glm::vec3 vel, glm::vec3 acc, float mass, int charge)
        : QmBody(TYPE_PARTICLE), position(pos), velocity(vel), acceleration(acc),
          charge(charge), invMass(1 - mass), damping(0.9999f) {
}

QmParticle::~QmParticle() {
    delete updater;
}

void QmParticle::integrate(float t) {
    acceleration = forceAccumulator * invMass;
    position += t * velocity;
    velocity += t * acceleration;
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


