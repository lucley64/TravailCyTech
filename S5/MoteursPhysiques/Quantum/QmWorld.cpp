#include <iostream>

#include "QmWorld.h"
#include "QmParticle.h"

using namespace Quantum;

QmWorld::QmWorld() {
    std::cout << "Starting Quantum Physics engine." << std::endl;
    time = 0.f;
}

QmWorld::~QmWorld() = default;

void QmWorld::simulate(float t) {
    resetBodies();
    updateForces();
    integrate(t);
}


void QmWorld::integrate(float t) {
    time += t;
    for (QmBody *b: bodies) {

        b->integrate(t);
    }
}

void QmWorld::addBody(QmBody *b) {
    bodies.push_back(b);
}

std::vector<QmBody *> QmWorld::getBodies() const {
    return bodies;
}

void QmWorld::clear() {

    for (QmBody *b: bodies) {
        delete b;
    }
    forceRegistries.clear();
    bodies.clear();
}

void QmWorld::addForceRegistry(const QmForceRegistry &forceRegistry) {
    forceRegistries.push_back(forceRegistry);
}

void QmWorld::resetBodies() {
    for (auto& b: bodies){
        b->reset();
    }
}

void QmWorld::updateForces() {
    for (auto &r: forceRegistries){
        r.getForceGenerator()->update(r.getParticle());
    }
}
