/**
 * @file main.cpp
 * @author Halit Cetin (halitcetin@live.com)
 * @brief This file is the enterance point of the application.
 * @version 0.1
 * @date 2022-11-30
 *
 * @copyright Copyright (c) 2022
 */

#include <Arduino.h>
#include <vector>
#include <list>

#define TEST_SIZE 1000

std::vector<int> testVector;
std::list<int> testList;
int *testArray;

int testValue = 0;

unsigned long timeMicroSecFirst = 0;
unsigned long timeMicroSecLast = 0;

unsigned long timeIntervalVectorFill = 0;
unsigned long timeIntervalArrayFill = 0;
unsigned long timeIntervalListFill = 0;

unsigned long timeIntervalVectorAccess = 0;
unsigned long timeIntervalArrayAccess = 0;
unsigned long timeIntervalListAccess = 0;

unsigned long timeIntervalVectorInsert = 0;
unsigned long timeIntervalArrayInsert = 0;
unsigned long timeIntervalListInsert = 0;

void setup()
{
    Serial.begin(9600);

    timeMicroSecFirst = micros();
    for (int i = 0; i < TEST_SIZE; i++)
    {
        testVector.push_back(i);
    }
    timeMicroSecLast = micros();
    timeIntervalVectorFill = timeMicroSecLast - timeMicroSecFirst;

    timeMicroSecFirst = micros();
    testArray = (int *)malloc(sizeof(int) * TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        testArray[i] = i;
    }
    timeMicroSecLast = micros();
    timeIntervalArrayFill = timeMicroSecLast - timeMicroSecFirst;

    timeMicroSecFirst = micros();
    for (int i = 0; i < TEST_SIZE; i++)
    {
        testList.push_back(i);
    }
    timeMicroSecLast = micros();
    timeIntervalListFill = timeMicroSecLast - timeMicroSecFirst;

    timeMicroSecFirst = micros();
    for (int i = 0; i < TEST_SIZE; i++)
    {
        testValue = testVector[i];
    }
    timeMicroSecLast = micros();
    timeIntervalVectorAccess = timeMicroSecLast - timeMicroSecFirst;

    timeMicroSecFirst = micros();
    for (int i = 0; i < TEST_SIZE; i++)
    {
        testValue = testArray[i];
    }
    timeMicroSecLast = micros();
    timeIntervalArrayAccess = timeMicroSecLast - timeMicroSecFirst;

    timeMicroSecFirst = micros();
    for (std::list<int>::iterator it = testList.begin(); it != testList.end(); it++)
    {
        testValue = *it;
    }
    timeMicroSecLast = micros();
    timeIntervalListAccess = timeMicroSecLast - timeMicroSecFirst;

    timeMicroSecFirst = micros();
    for (int i = 0; i < TEST_SIZE; i++)
    {
        std::vector<int>::iterator itVec = testVector.begin() + TEST_SIZE / 2;
        testVector.insert(itVec, i);
    }
    timeMicroSecLast = micros();
    timeIntervalVectorInsert = timeMicroSecLast - timeMicroSecFirst;

    timeMicroSecFirst = micros();
    for (int i = 0; i < TEST_SIZE; i++)
    {
        std::list<int>::iterator itList = testList.begin();
        std::advance(itList, TEST_SIZE / 2);
        testList.insert(itList, i);
    }
    timeMicroSecLast = micros();
    timeIntervalListInsert = timeMicroSecLast - timeMicroSecFirst;

    Serial.println("Vector filling time (uS) : " + String(timeIntervalVectorFill));
    Serial.println("Array filling time (uS) : " + String(timeIntervalArrayFill));
    Serial.println("List filling time (uS) : " + String(timeIntervalListFill));
    Serial.println("Vector access time (uS) : " + String(timeIntervalVectorAccess));
    Serial.println("Array access time (uS) : " + String(timeIntervalArrayAccess));
    Serial.println("List access time (uS) : " + String(timeIntervalListAccess));
    Serial.println("Vector insert time (uS) : " + String(timeIntervalVectorInsert));
    Serial.println("List insert time (uS) : " + String(timeIntervalListInsert));
}

void loop()
{
    delay(5000);
}
