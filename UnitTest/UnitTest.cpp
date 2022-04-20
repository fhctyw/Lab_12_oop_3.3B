#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_oop_3.3B\Pair.cpp"
#include "..\Lab_12_oop_3.3B\Rational.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			Rational r{14, 7};
			Assert::IsTrue(Rational{ 1, 1 } ==  r / r);
		}
	};
}
