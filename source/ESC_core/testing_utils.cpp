/*
 *  [ESC] Interactive
 *
 *  Implementation file for various testing utilities.
 *
 */


/*
 *   **** 3-Clause BSD License ****
 *   ref: https://opensource.org/license/bsd-3-clause/
 *
 *
 *   Copyright 2023 - [ESC] Interactive (Anthony Truelove MASc, P.Eng.)
 *
 *   Redistribution and use in source and binary forms, with or without modification, are
 *   permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list of
 *   conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this list
 *   of conditions and the following disclaimer in the documentation and/or other materials
 *   provided with the distribution.
 *
 *   3. Neither the name of the copyright holder nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without specific prior
 *   written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY
 *   EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 *   THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 *   OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 *   TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


///
/// \file testing_utils.cpp
///
/// \brief Implementation file for various testing utilities.
///
/// This is a library of utility functions used throughout the various test suites.
///


#include "../../header/ESC_core/testing_utils.h"


// ---------------------------------------------------------------------------------- //

///
/// \fn void printGreen(std::string input_str)
///
/// \brief A function that sends green text to std::cout.
///
/// \param input_str The text of the string to be sent to std::cout.
///

void printGreen(std::string input_str)
{
    std::cout << "\x1B[32m" << input_str << "\033[0m";
    return;
}   /* printGreen() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void printGold(std::string input_str)
///
/// \brief A function that sends gold text to std::cout.
///
/// \param input_str The text of the string to be sent to std::cout.
///

void printGold(std::string input_str)
{
    std::cout << "\x1B[33m" << input_str << "\033[0m";
    return;
}   /* printGold() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void printRed(std::string input_str)
///
/// \brief A function that sends red text to std::cout.
///
/// \param input_str The text of the string to be sent to std::cout.
///

void printRed(std::string input_str)
{
    std::cout << "\x1B[31m" << input_str << "\033[0m";
    return;
}   /* printRed() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void testFloatEquals(double x, double y, std::string file, int line)
///
/// \brief Tests for the equality of two floating point numbers \a x and \a y (to
///     within FLOAT_TOLERANCE).
///
/// \param x The first of two numbers to test.
///
/// \param y The second of two numbers to test.
///
/// \param file The file in which the test is applied (you should be able to just pass
///     in "__FILE__").
///
/// \param line The line of the file in which the test is applied (you should be able
///     to just pass in "__LINE__").
///

void testFloatEquals(
    double x,
    double y,
    std::string file,
    int line
)
{
    if (fabs(x - y) <= FLOAT_TOLERANCE) {
        return;
    }

    std::string error_str = "ERROR: testFloatEquals():\t in ";
    error_str += file;
    error_str += "\tline ";
    error_str += std::to_string(line);
    error_str += ":\t\n";
    error_str += std::to_string(x);
    error_str += " and ";
    error_str += std::to_string(y);
    error_str += " are not equal to within +/- ";
    error_str += std::to_string(FLOAT_TOLERANCE);
    error_str += "\n";

    #ifdef _WIN32
        std::cout << error_str << std::endl;
    #endif

    throw std::runtime_error(error_str);
    return;
}   /* testFloatEquals() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void testGreaterThan(double x, double y, std::string file, int line)
///
/// \brief Tests if x > y.
///
/// \param x The first of two numbers to test.
///
/// \param y The second of two numbers to test.
///
/// \param file The file in which the test is applied (you should be able to just pass
///     in "__FILE__").
///
/// \param line The line of the file in which the test is applied (you should be able
///     to just pass in "__LINE__").
///

void testGreaterThan(
    double x,
    double y,
    std::string file,
    int line
)
{
    if (x > y) {
        return;
    }

    std::string error_str = "ERROR: testGreaterThan():\t in ";
    error_str += file;
    error_str += "\tline ";
    error_str += std::to_string(line);
    error_str += ":\t\n";
    error_str += std::to_string(x);
    error_str += " is not greater than ";
    error_str += std::to_string(y);
    error_str += "\n";

    #ifdef _WIN32
        std::cout << error_str << std::endl;
    #endif

    throw std::runtime_error(error_str);
    return;
}   /* testGreaterThan() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void testGreaterThanOrEqualTo(double x, double y, std::string file, int line)
///
/// \brief Tests if x >= y.
///
/// \param x The first of two numbers to test.
///
/// \param y The second of two numbers to test.
///
/// \param file The file in which the test is applied (you should be able to just pass
///     in "__FILE__").
///
/// \param line The line of the file in which the test is applied (you should be able
///     to just pass in "__LINE__").
///

void testGreaterThanOrEqualTo(
    double x,
    double y,
    std::string file,
    int line
)
{
    if (x >= y) {
        return;
    }

    std::string error_str = "ERROR: testGreaterThanOrEqualTo():\t in ";
    error_str += file;
    error_str += "\tline ";
    error_str += std::to_string(line);
    error_str += ":\t\n";
    error_str += std::to_string(x);
    error_str += " is not greater than or equal to ";
    error_str += std::to_string(y);
    error_str += "\n";

    #ifdef _WIN32
        std::cout << error_str << std::endl;
    #endif

    throw std::runtime_error(error_str);
    return;
}   /* testGreaterThanOrEqualTo() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void testLessThan(double x, double y, std::string file, int line)
///
/// \brief Tests if x < y.
///
/// \param x The first of two numbers to test.
///
/// \param y The second of two numbers to test.
///
/// \param file The file in which the test is applied (you should be able to just pass
///     in "__FILE__").
///
/// \param line The line of the file in which the test is applied (you should be able
///     to just pass in "__LINE__").
///

void testLessThan(
    double x,
    double y,
    std::string file,
    int line
)
{
    if (x < y) {
        return;
    }

    std::string error_str = "ERROR: testLessThan():\t in ";
    error_str += file;
    error_str += "\tline ";
    error_str += std::to_string(line);
    error_str += ":\t\n";
    error_str += std::to_string(x);
    error_str += " is not less than ";
    error_str += std::to_string(y);
    error_str += "\n";

    #ifdef _WIN32
        std::cout << error_str << std::endl;
    #endif

    throw std::runtime_error(error_str);
    return;
}   /* testLessThan() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void testLessThanOrEqualTo(double x, double y, std::string file, int line)
///
/// \brief Tests if x <= y.
///
/// \param x The first of two numbers to test.
///
/// \param y The second of two numbers to test.
///
/// \param file The file in which the test is applied (you should be able to just pass
///     in "__FILE__").
///
/// \param line The line of the file in which the test is applied (you should be able
///     to just pass in "__LINE__").
///

void testLessThanOrEqualTo(
    double x,
    double y,
    std::string file,
    int line
)
{
    if (x <= y) {
        return;
    }

    std::string error_str = "ERROR: testLessThanOrEqualTo():\t in ";
    error_str += file;
    error_str += "\tline ";
    error_str += std::to_string(line);
    error_str += ":\t\n";
    error_str += std::to_string(x);
    error_str += " is not less than or equal to ";
    error_str += std::to_string(y);
    error_str += "\n";

    #ifdef _WIN32
        std::cout << error_str << std::endl;
    #endif

    throw std::runtime_error(error_str);
    return;
}   /* testLessThanOrEqualTo() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void testTruth(bool statement, std::string file, int line)
///
/// \brief Tests if the given statement is true.
///
/// \param statement The statement whose truth is to be tested ("1 == 0", for example).
///
/// \param file The file in which the test is applied (you should be able to just pass
///     in "__FILE__").
///
/// \param line The line of the file in which the test is applied (you should be able
///     to just pass in "__LINE__").
///

void testTruth(
    bool statement,
    std::string file,
    int line
)
{
    if (statement) {
        return;
    }

    std::string error_str = "ERROR: testTruth():\t in ";
    error_str += file;
    error_str += "\tline ";
    error_str += std::to_string(line);
    error_str += ":\t\n";
    error_str += "Given statement is not true";

    #ifdef _WIN32
        std::cout << error_str << std::endl;
    #endif

    throw std::runtime_error(error_str);
    return;
}   /* testTruth() */

// ---------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------- //

///
/// \fn void expectedErrorNotDetected(std::string file, int line)
///
/// \brief A utility function to print out a meaningful error message whenever an
///     expected error fails to be thrown/caught/detected.
///
/// \param file The file in which the test is applied (you should be able to just pass
///     in "__FILE__").
///
/// \param line The line of the file in which the test is applied (you should be able
///     to just pass in "__LINE__").
///

void expectedErrorNotDetected(std::string file, int line)
{
    std::string error_str = "\n ERROR  failed to throw expected error prior to line ";
    error_str += std::to_string(line);
    error_str += " of ";
    error_str += file;
    
    #ifdef _WIN32
        std::cout << error_str << std::endl;
    #endif
    
    throw std::runtime_error(error_str);
    return;
}   /* expectedErrorNotDetected() */

// ---------------------------------------------------------------------------------- //
