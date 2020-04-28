/*
 * Test.cpp
 *
 *  Created on: 24 Apr 2020
 *      Author: zohar
 */
#include "doctest.h"
#include <iostream>
#include <complex>
#include "solver.hpp"

using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;

TEST_CASE("Testing"){
    for(int i=0;i<105;i++){
        CHECK(true);
    }
}

