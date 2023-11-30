//
// Created by aku on 11/30/23.
//

#pragma once

namespace rbplib
{
	/**
	 * Abstract class for drive joystick curves. Allows for more precise operator
	 * control. Used by many world class teams such as Freedom Gladiators 4082B.
	 *
	 * Uses a gain (scale) to allow user control of how much the input is
	 * curved. Implementation of curve function is up to children classes.
	 */
	class DriveCurve
	{
	public:
		/**
		 * @return The current gain of drive curve.
		 */
		virtual double getGain() const = 0;
		/**
		 * @param igain New gain.
		 */
		virtual void setGain(const double igain) = 0;

		/**
		 * Applies the curve function to the input. As stated in description of class,
		 * implementation of the mathematical function is up to children classes.
		 *
		 * @param ivalue Joystick value to curve.
		 * @return Curved ivalue that can be passed into chassis control loop.
		 */
		virtual double curve(const double ivalue) = 0;
	protected:
		double gain = 0.0;
	};
} // namespace rbplib