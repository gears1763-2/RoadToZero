/*
 *  RoadToZero
 *
 *  [ESC] Interactive
 *
 *  Header file for various testing utilities.
 *
 */


///
/// \file testing_utils.h
///
/// \brief Header file for various testing utilities.
///
/// This is a library of utility functions used throughout the various test suites.
///


#ifndef TESTING_UTILS_H
#define TESTING_UTILS_H


#include "constants.h"
#include "includes.h"


#ifdef _WIN32
    void activateVirtualTerminal(void);
#endif  /* _WIN32 */


void printGreen(std::string);
void printGold(std::string);
void printRed(std::string);

void testFloatEquals(double, double, std::string, int);
void testGreaterThan(double, double, std::string, int);
void testGreaterThanOrEqualTo(double, double, std::string, int);
void testLessThan(double, double, std::string, int);
void testLessThanOrEqualTo(double, double, std::string, int);
void testTruth(bool, std::string, int);

void expectedErrorNotDetected(std::string, int);


#endif  /* TESTING_UTILS_H */
