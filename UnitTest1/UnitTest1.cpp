#include "pch.h"
#include "CppUnitTest.h"
#include "..\\normlab9.1.2\Student.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(StudentTests)
	{
	public:

		TEST_METHOD(TestQuantOfStudentsMarkThan45)
		{
			const int N = 3;
			Student students[N];


			students[0] = { "�������1", 1, KOMPNAUKI, 4, 5, {3} };
			students[1] = { "�������2", 2, INFORMATIC, 3, 4, {4} };
			students[2] = { "�������3", 3, KOMPNAUKI, 5, 5, {5} };

			int result = QuantOfStudentsMarkThan45(students, N, 3); // ����������, �� K = 3

			Assert::AreEqual(1, result);



		}
	};
}