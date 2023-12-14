#include "pch.h"
#include "CppUnitTest.h"
#include "..\kalkulator\funkcje.cpp"
#include "..\kalkulator\kalkulator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_logarytm)
		{
			double expected = log(3);
			Assert::AreEqual(expected, logarytm(3));
		}
		TEST_METHOD(Test_eksponenta)
		{
			double expected = log(3);
			Assert::AreEqual(expected, logarytm(3));
		}
		TEST_METHOD(Test_odchylenie)
		{
			double sumator=0;
			double tab[20];
			for (int i = 0; i < 20; i++) {
				tab[i] = 20 - (i / 2);
			}
			double expected = odchylenie(tab,sumator);
			Assert::AreEqual(expected, odchylenie(tab,sumator));
		}
		TEST_METHOD(Test_dzielenia)
		{
			double expected = 4.0/7.0;
			Assert::AreEqual(expected, dzielenie(4,7));
		}
	};
}
