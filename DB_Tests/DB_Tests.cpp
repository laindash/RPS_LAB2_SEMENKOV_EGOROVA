#include "CppUnitTest.h"
#include "..\Rps_lab3_Semenkov_Egorova\main_algorithms.h"
#include "..\Rps_lab3_Semenkov_Egorova\database.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DBTests {
	TEST_CLASS(DBTests) {
	public:
		// ������������ ���������� 100 ��������� �������� � ���� ������
		TEST_METHOD(t1_addArrays100) {
			std::vector<std::vector<int>> arrays{};
			int number_of_arrays(100);
			int array_loading_counter{};
			generateRandomArrays(arrays, static_cast<size_t>(number_of_arrays));
			array_loading_counter = initializeDB(arrays);

			Assert::AreEqual(number_of_arrays, array_loading_counter);
		}

		// ������������ ���������� 1000 ��������� �������� � ���� ������
		TEST_METHOD(t4_addArrays1000) {
			std::vector<std::vector<int>> arrays{};
			int number_of_arrays(1000);
			int array_loading_counter{};

			generateRandomArrays(arrays, static_cast<size_t>(number_of_arrays));
			array_loading_counter = initializeDB(arrays);

			Assert::AreEqual(number_of_arrays, array_loading_counter);
		}

		// ������������ ���������� 10000 ��������� �������� � ���� ������
		TEST_METHOD(t7_addArrays10000) {
			std::vector<std::vector<int>> arrays{};
			int number_of_arrays(10000);
			int array_loading_counter{};

			generateRandomArrays(arrays, static_cast<size_t>(number_of_arrays));
			array_loading_counter = initializeDB(arrays);

			Assert::AreEqual(number_of_arrays, array_loading_counter);
		}

		// ������������ �������� 100 �������� �� ���� ������ � �� ����������
		TEST_METHOD(t2_uploadArrays100) {
			std::vector<std::vector<int>> arrays{};
			std::vector<std::string> change_dates{};
			int number_of_arrays(100);
			int array_loading_counter{};

			loadDataFromDB(arrays, change_dates);
			array_loading_counter = static_cast<int>(arrays.size());
			startSorting(arrays);

			Assert::AreEqual(number_of_arrays, array_loading_counter);
		}

		// ������������ �������� 1000 �������� �� ���� ������ � �� ����������
		TEST_METHOD(t5_uploadArrays1000) {
			std::vector<std::vector<int>> arrays{};
			std::vector<std::string> change_dates{};
			int number_of_arrays(1000);
			int array_loading_counter{};

			loadDataFromDB(arrays, change_dates);
			array_loading_counter = static_cast<int>(arrays.size());
			startSorting(arrays);

			Assert::AreEqual(number_of_arrays, array_loading_counter);
		}

		// ������������ �������� 10000 �������� �� ���� ������ � �� ����������
		TEST_METHOD(t8_uploadArrays10000) {
			std::vector<std::vector<int>> arrays{};
			std::vector<std::string> change_dates{};
			int number_of_arrays(10000);
			int array_loading_counter{};

			loadDataFromDB(arrays, change_dates);
			array_loading_counter = static_cast<int>(arrays.size());
			startSorting(arrays);

			Assert::AreEqual(number_of_arrays, array_loading_counter);
		}

		// ������������ ������� ���� ������ ����� ���������� 100 ��������
		TEST_METHOD(t3_databaseCleaning100) {
			bool success = clearTable();

			Assert::IsTrue(success, L"test failed or the database has already been cleared");
		}

		// ������������ ������� ���� ������ ����� ���������� 1000 ��������
		TEST_METHOD(t6_databaseCleaning1000) {
			bool success = clearTable();

			Assert::IsTrue(success, L"test failed or the database has already been cleared");
		}

		// ������������ ������� ���� ������ ����� ���������� 10000 ��������
		TEST_METHOD(t9_databaseCleaning10000) {
			bool success = clearTable();

			Assert::IsTrue(success, L"test failed or the database has already been cleared");
		}
	};
}
