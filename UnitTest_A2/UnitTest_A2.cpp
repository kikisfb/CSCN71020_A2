#include "pch.h"
#include "CppUnitTest.h"
extern "C" 
{

	int getPerimeter(int*, int*);
	int getArea(int*,int*);
	void setLength(int, int*);
	void setWidth(int, int*);
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestA2
{
	TEST_CLASS(UnitTestA2)
	{
	public:
		
		TEST_METHOD(returningPerimeter)
		{
			//this is testing getPerimeter function using width of 2 and length of 4 which the permimeter is 12
			int w = 2;
			int l = 4;
			int result = getPerimeter(&l, &w);
			Assert::AreEqual(12,result);
		}
		TEST_METHOD(returningArea) 
		{
			//this is testing getArea function using width of 2 and length of 4 which the area is 8
			int w = 2;
			int l = 4;
			int result = getArea(&l, &w);
			Assert::AreEqual(8,result );
		}
		TEST_METHOD(setLength_1)
		{
			//this is testing setLength function setting the length of 2 to 4.5 which should show length as 4 now
			int l = 2;
			setLength(4.5, &l);
			Assert::AreEqual(4, l);
		}
		TEST_METHOD(setLength_2)
		{
			//this is testing setLength function setting the length of 2 to 0 which should show length as 2 becuase it can't 0;
			int l = 2;
			setLength(0, &l);
			Assert::AreEqual(2, l);
		}
		TEST_METHOD(setLength_3)
		{
			//this is testing setLength function setting the length of 40 to 99 which show length of 99 now
			int l = 40;
			setLength(99, &l);
			Assert::AreEqual(99, l);
		}
		TEST_METHOD(setWidth_1)
		{
			//this is testing setWidth function setting the width from 5 to 0 which should show width as 5 now
			int w = 5;
			setWidth(0, &w);
			Assert::AreEqual(5, w);
		}
		TEST_METHOD(setWidth_2)
		{
			//this is testing setWidth function setting the width from 10 to 100 which should show width as 10 now because 100 should not be in the range
			int w = 10;
			setWidth(100, &w);
			Assert::AreEqual(10, w);

		}
		TEST_METHOD(setWidth_3)
		{
			//this is testing setWidth function setting the width of 1 to 2.8 which should round it down to the width of 2 now
			int w = 1;
			setWidth(2.8, &w);
			Assert::AreEqual(2, w);
		}
	};
}
