#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10.1/lab101A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101A
{
	TEST_CLASS(UnitTest101A)
	{
	public:

		TEST_METHOD(TestProcentFizyka4abo5)
		{
			Student s[4];
			s[0].fizyka = 5;
			s[1].fizyka = 4;
			s[2].fizyka = 3;
			s[3].fizyka = 2;

			double t = ProcentFizyka4abo5(s, 4);

			Assert::AreEqual(50.0, t, 0.001);
		}

		TEST_METHOD(TestSerednijBal)
		{
			Student s;
			s.fizyka = 5;
			s.matematyka = 4;
			s.informatyka = 3;

			double t = SerednijBal(s);

			Assert::AreEqual(4.0, t, 0.001);
		}
	};
}