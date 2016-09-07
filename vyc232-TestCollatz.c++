// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read_1) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_2){
    istringstream r("5 55\n");
    int i;
    int j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(5, i);
    ASSERT_EQ(55, j);}

TEST(CollatzFixture, read_3){
    istringstream r("1 1\n");
    int i;
    int j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(1, i);
    ASSERT_EQ(1, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(5, 55);
    ASSERT_EQ(113, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(780, 952);
    ASSERT_EQ(179, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(19, 212);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(961, 987);
    ASSERT_EQ(143, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}

// --------------------
// compute_cycle_length
// --------------------

TEST(CollatzFixture, compute_cycle_length_1){
    const int a = compute_cycle_length(800, 800, 1);
    ASSERT_EQ(29, a);}

TEST(CollatzFixture, compute_cycle_length_2){
    const int a = compute_cycle_length(98765, 98765, 1);
    ASSERT_EQ(54, a);}

TEST(CollatzFixture, compute_cycle_length_3){
    const int a = compute_cycle_length(12345, 12345, 1);
    ASSERT_EQ(51, a);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 10, 1, 20);
    ASSERT_EQ("10 1 20\n", w.str());}    

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 69, 96, 116);
    ASSERT_EQ("69 96 116\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("10 1\n200 100\n210 201\n1000 900\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("10 1 20\n200 100 125\n210 201 89\n1000 900 174\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("1 10\n1 100\n1 200\n1 300\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n1 100 119\n1 200 125\n1 300 128\n", w.str());}
