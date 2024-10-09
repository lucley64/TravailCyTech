#ifndef QMPARTICLE_H
#define QMPARTICLE_H

#include <array>
#include <Application/GxParticle.h>
#include <Application/GxParticle.h>
#include <Application/GxParticle.h>
#include <Application/GxParticle.h>
#include <Application/GxParticle.h>
#include <Application/GxParticle.h>
#include <Application/GxParticle.h>
#include <Application/GxParticle.h>
#include <glm/glm.hpp>
#include "QmBody.h"


namespace Quantum {
	class QmUpdater;

	class QmParticle : public QmBody {
	public:
		QmParticle();
		QmParticle(glm::vec3 position, glm::vec3 velocity, glm::vec3 acceleration, float mass, int charge);
		QmParticle(glm::vec3 position, glm::vec3 velocity, glm::vec3 acceleration, float mass, int charge, float damping);
		~QmParticle() override;
		void integrate(float t) override;
		void integrate(float, unsigned int i) final;
		void computeAccelerations(unsigned i) override;
		void integrateRK4(float t) override;
		void addForce(const glm::vec3 &force, unsigned int i) override;

        void reset() override;

		std::array<glm::vec3, 4> getAcc() const;
		std::array<glm::vec3, 4> getVel() const;
		[[nodiscard]] std::array<glm::vec3, 4> getPos() const;

        [[nodiscard]] int getCharge() const;

        [[nodiscard]] float getInvMass() const;
        [[nodiscard]] float getMass() const;

        void setUpdater(QmUpdater* updater);
		[[nodiscard]] QmUpdater* getUpdater() const;

		void setDamping(float damping);
		[[nodiscard]] float getDamping() const;

	private:
		QmUpdater* updater = nullptr;
		std::array<glm::vec3, 4> position;
		std::array<glm::vec3, 4> velocity;
		std::array<glm::vec3, 4> acceleration;
        std::array<glm::vec3, 4> forceAccumulator{};
        int charge = 1;
        float invMass{};

		float damping{};

	};
}

#endif