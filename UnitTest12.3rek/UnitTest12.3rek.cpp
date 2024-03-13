#include "pch.h"
#include "CppUnitTest.h"
#include "../AP12.3rek/AP12.3rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest123rek
{
	TEST_CLASS(UnitTest123rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* L1 = nullptr;
			Elem* L2 = nullptr;

			// Додайте елементи до списків
			LAddRecursive(L1, L1, 1);
			LAddRecursive(L1, L1, 2);
			LAddRecursive(L1, L1, 3);

			LAddRecursive(L2, L2, 2);
			LAddRecursive(L2, L2, 3);

			// Act
			bool result = LisSubset(L1, L2);

			// Assert
			Assert::IsTrue(result);
		}
	};
}
