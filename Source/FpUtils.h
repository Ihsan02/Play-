#pragma once

#include <cstddef>

class CMipsJitter;

namespace FpUtils
{
	void SetDenormalHandlingMode();
	void EnableFpExceptions();

	void IsZero(CMipsJitter*, size_t);
	void ComputeDivisionByZero(CMipsJitter*, size_t, size_t);
}
