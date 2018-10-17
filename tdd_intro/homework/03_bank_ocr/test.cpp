/*### Bank OCR
Your manager has recently purchased a machine that assists in reading letters and faxes sent in by branch offices.
The machine scans the paper documents, and produces a file with a number of entries. You will write a program to parse this file.
#### Specification
#### User Story 1
The following format is created by the machine:
```
    _  _     _  _  _  _  _
  | _| _||_||_ |_   ||_||_|
  ||_  _|  | _||_|  ||_| _|
```
Each entry is 3 lines long, and each line has 27 characters. 3 lines of each entry contain an account number written using pipes and underscores.
Each account number should have 9 digits, all of which should be in the range 0-9. A normal file contains around 500 entries.
Write a program that can take this file and parse it into actual account numbers.
Example input and output
```
 _  _  _  _  _  _  _  _  _
| || || || || || || || || |
|_||_||_||_||_||_||_||_||_|
=> 000000000
  |  |  |  |  |  |  |  |  |
  |  |  |  |  |  |  |  |  |
=> 111111111
 _  _  _  _  _  _  _  _  _
 _| _| _| _| _| _| _| _| _|
|_ |_ |_ |_ |_ |_ |_ |_ |_
=> 222222222
 _  _  _  _  _  _  _  _  _
 _| _| _| _| _| _| _| _| _|
 _| _| _| _| _| _| _| _| _|
=> 333333333
|_||_||_||_||_||_||_||_||_|
  |  |  |  |  |  |  |  |  |
=> 444444444
 _  _  _  _  _  _  _  _  _
|_ |_ |_ |_ |_ |_ |_ |_ |_
 _| _| _| _| _| _| _| _| _|
=> 555555555
 _  _  _  _  _  _  _  _  _
|_ |_ |_ |_ |_ |_ |_ |_ |_
|_||_||_||_||_||_||_||_||_|
=> 666666666
 _  _  _  _  _  _  _  _  _
  |  |  |  |  |  |  |  |  |
  |  |  |  |  |  |  |  |  |
=> 777777777
 _  _  _  _  _  _  _  _  _
|_||_||_||_||_||_||_||_||_|
|_||_||_||_||_||_||_||_||_|
=> 888888888
 _  _  _  _  _  _  _  _  _
|_||_||_||_||_||_||_||_||_|
 _| _| _| _| _| _| _| _| _|
=> 999999999
    _  _     _  _  _  _  _
  | _| _||_||_ |_   ||_||_|
  ||_  _|  | _||_|  ||_| _|
=> 123456789
```
*/
#include <gtest/gtest.h>
#include <string>

const unsigned short g_digitLen = 3;
const unsigned short g_linesInDigit = 3;
struct Digit
{
    bool operator ==(const Digit& digit)
    {
        for (unsigned int i = 0; i < g_linesInDigit; i++)
        {
            if (lines[i] != digit.lines[i])
            {
                return false;
            }
        }
        return true;
    }

    std::string lines[g_linesInDigit];
};

const unsigned short g_digitsOnDisplay = 9;
struct Display
{
    Digit digits[g_linesInDigit];
};

const Digit s_digit0 = { " _ ",
                         "| |",
                         "|_|"
                       };
const Digit s_digit1 = { "   ",
                         "  |",
                         "  |"
                       };
const Digit s_digit2 = { " _ ",
                         " _|",
                         "|_ "
                       };
const Digit s_digit3 = { " _ ",
                         " _|",
                         " _|"
                       };
const Digit s_digit4 = { "   ",
                         "|_|",
                         "  |"
                       };
const Digit s_digit5 = { " _ ",
                         "|_ ",
                         " _|"
                       };
const Digit s_digit6 = { " _ ",
                         "|_ ",
                         "|_|"
                       };
const Digit s_digit7 = { " _ ",
                         "  |",
                         "  |"
                       };
const Digit s_digit8 = { " _ ",
                         "|_|",
                         "|_|"
                       };
const Digit s_digit9 = { " _ ",
                         "|_|",
                         " _|"
                       };

const Display s_displayAll0 = { " _  _  _  _  _  _  _  _  _ ",
                                "| || || || || || || || || |",
                                "|_||_||_||_||_||_||_||_||_|"
};

const Display s_displayAll1 = { "                           ",
                                "  |  |  |  |  |  |  |  |  |",
                                "  |  |  |  |  |  |  |  |  |"
};

const Display s_displayAll2 = {  " _  _  _  _  _  _  _  _  _ ",
                                 " _| _| _| _| _| _| _| _| _|",
                                 "|_ |_ |_ |_ |_ |_ |_ |_ |_ "
};

const Display s_displayAll3 = { " _  _  _  _  _  _  _  _  _ ",
                                " _| _| _| _| _| _| _| _| _|",
                                " _| _| _| _| _| _| _| _| _|"
};

const Display s_displayAll4 = { "                           ",
                                "|_||_||_||_||_||_||_||_||_|",
                                "  |  |  |  |  |  |  |  |  |"
};

const Display s_displayAll5 = { " _  _  _  _  _  _  _  _  _ ",
                                "|_ |_ |_ |_ |_ |_ |_ |_ |_ ",
                                " _| _| _| _| _| _| _| _| _|"
};

const Display s_displayAll6 = { " _  _  _  _  _  _  _  _  _ ",
                                "|_ |_ |_ |_ |_ |_ |_ |_ |_ ",
                                "|_||_||_||_||_||_||_||_||_|"
};

const Display s_displayAll7 = { " _  _  _  _  _  _  _  _  _ ",
                                "  |  |  |  |  |  |  |  |  |",
                                "  |  |  |  |  |  |  |  |  |"
};

const Display s_displayAll8 = { " _  _  _  _  _  _  _  _  _ ",
                                "|_||_||_||_||_||_||_||_||_|",
                                "|_||_||_||_||_||_||_||_||_|"
};

const Display s_displayAll9 = { " _  _  _  _  _  _  _  _  _ ",
                                "|_||_||_||_||_||_||_||_||_|",
                                " _| _| _| _| _| _| _| _| _|"
};

const Display s_display123456789 = { "    _  _     _  _  _  _  _ ",
                                     "  | _| _||_||_ |_   ||_||_|",
                                     "  ||_  _|  | _||_|  ||_| _|"
};

// Test list:
// Digit
// Another digit
// Invalid symbols in input
// Display
// Another display
// Acceptance

unsigned long long ConvertDigit(Digit digit)
{
    static const Digit allDigits[] = {  s_digit0, s_digit1, s_digit2,
                                        s_digit3, s_digit4, s_digit5,
                                        s_digit6, s_digit7, s_digit8,
                                        s_digit9
                                     };

    for (size_t i = 0; i < 10; i++)
    {
        if (digit == allDigits[i])
        {
            return i;
        }
    }
    throw std::runtime_error("Invalid input");
}

unsigned long long ConvertDisplay(Display display)
{
    unsigned long long result = 0;
    for (size_t digitNumber = 0, powIndex = g_digitsOnDisplay - 1; digitNumber < g_digitsOnDisplay; digitNumber++, powIndex--)
    {
        Digit digit;
        for (size_t lineNumber = 0; lineNumber < g_linesInDigit; lineNumber++)
        {
            digit.lines[lineNumber].assign(display.digits[0].lines[lineNumber].cbegin() + digitNumber * g_digitLen,
                                           display.digits[0].lines[lineNumber].cbegin() + digitNumber * g_digitLen + g_digitLen);
        }
        result += ConvertDigit(digit) * std::pow(10, powIndex);
    }
    return result;
}

TEST(BankOcr, Convert1)
{
    EXPECT_EQ(ConvertDigit(s_digit0), 0);
}

TEST(BankOcr, Convert3)
{
    EXPECT_EQ(ConvertDigit(s_digit3), 3);
}

TEST(BankOcr, Convert5)
{
    EXPECT_EQ(ConvertDigit(s_digit5), 5);
}

TEST(BankOcr, ConvertInvalid)
{
    const Digit s_digitInvalid = {  " 1 ",
                                    "|3 ",
                                    " 4|"
                                 };
    EXPECT_THROW(ConvertDigit(s_digitInvalid), std::runtime_error);
}

TEST(BankOcr, ConvertDisplay0)
{
    EXPECT_EQ(ConvertDisplay(s_displayAll0), 000000000);
}

TEST(BankOcr, ConvertDisplay2)
{
    EXPECT_EQ(ConvertDisplay(s_displayAll2), 222222222);
}

TEST(BankOcr, ConvertDisplayAll)
{
    EXPECT_EQ(ConvertDisplay(s_display123456789), 123456789);
}

TEST(BankOcr, Acceptence)
{
    EXPECT_EQ(ConvertDisplay(s_displayAll3), 333333333);
    EXPECT_EQ(ConvertDisplay(s_displayAll8), 888888888);
    EXPECT_EQ(ConvertDisplay(s_displayAll4), 444444444);
}

