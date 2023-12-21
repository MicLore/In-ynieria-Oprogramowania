#include "pch.h"
#include "CppUnitTest.h"
#include "..\IO - ustawienia\IO - ustawienia.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace draże
{
	TEST_CLASS(draże)
	{
	public:
		
        TEST_METHOD(UstawieniaObjectCreation)
        {
            // Arrange
            Ustawienia ust;

            // Act - No specific action needed, as the instance is already created

            // Assert
            Assert::IsNotNull(&ust); // Check if the instance of Ustawienia is not null
        }
        TEST_METHOD(ReadSettingsFromFile)
        {
            // Arrange
            Ustawienia ust;
            std::string testFilename = "test_ustawienia.txt"; // Test file name


            // Act
            ust.wczytajUstawienia(); // Read settings from the test file

            // Assert
            // Verify if the values read by the function match the expected values
            Assert::AreEqual(0, ust.zestawOpcji[0]);
            Assert::AreEqual(3, ust.zestawOpcji[1]);
            Assert::AreEqual(3, ust.zestawOpcji[2]);
            Assert::AreEqual(0, ust.zestawOpcji[3]);
            Assert::AreEqual(3, ust.zestawOpcji[4]);
            Assert::AreEqual(0, ust.zestawOpcji[5]);
            Assert::AreEqual(3, ust.zestawOpcji[6]);
            Assert::AreEqual(3, ust.zestawOpcji[7]);

            // Optional: Clean up by removing the test file
            //std::remove(testFilename.c_str());
        }
        TEST_METHOD(SaveSettingsToFile)
        {
            // Arrange
            Ustawienia ust;
            std::string testFilename = "test_ustawienia_save.txt"; // Test file name

            // Set some initial values in zestawOpcji
            ust.zestawOpcji[0] = 0;
            ust.zestawOpcji[1] = 3;
            ust.zestawOpcji[2] = 3;
            ust.zestawOpcji[3] = 0;
            ust.zestawOpcji[4] = 3;
            ust.zestawOpcji[5] = 0;
            ust.zestawOpcji[6] = 3;
            ust.zestawOpcji[7] = 3;

            // Act
            ust.zapiszUstawienia(); // Save settings to the test file

            // Assert
            // Verify if the values were saved correctly to the file
            std::ifstream testFile(testFilename);
            std::stringstream buffer;
            buffer << testFile.rdbuf(); // Read the file content into a stringstream
            testFile.close();

            std::string fileContent = buffer.str();

            // Check if each value is correctly written to the file
            Assert::AreEqual("0\n3\n3\n0\n3\n0\n3\n3\n", fileContent.c_str());

            // Optional: Clean up by removing the test file
            std::remove(testFilename.c_str());
        }
        TEST_METHOD(ChangeSettingValue)
        {
            // Arrange
            Ustawienia ust;

            // Set initial values for testing
            ust.zestawOpcji[0] = 0; // Initial value: 0

            // Act
            ust.zmienUstawienie(0); // Change the setting value

            // Assert
            Assert::AreEqual(2, ust.zestawOpcji[0]); // Check if the value is changed correctly

            // Additional test cases for other initial values and input parameters
            ust.zestawOpcji[1] = 1; // Initial value: 1
            ust.zmienUstawienie(1); // Change the setting value
            Assert::AreEqual(3, ust.zestawOpcji[1]); // Check if the value is changed correctly

            ust.zestawOpcji[2] = 2; // Initial value: 2
            ust.zmienUstawienie(2); // Change the setting value
            Assert::AreEqual(0, ust.zestawOpcji[2]); // Check if the value is changed correctly

            ust.zestawOpcji[3] = 3; // Initial value: 3
            ust.zmienUstawienie(3); // Change the setting value
            Assert::AreEqual(1, ust.zestawOpcji[3]); // Check if the value is changed correctly
        }
	};
}
