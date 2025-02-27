//
//#include "Point.h"
//#include "Pose.h"
//#include <iostream>
//#include <cassert>
//#include <cmath>
//#ifndef M_PI
//#define M_PI 3.14159265358979323846
//#endif
//
////Umay Ece Mantar 152120221127 19.12.2024
//using namespace std;
//
//// default constructor test function - verifies initialization to (0,0)
//void testDefaultConstructor() {
//    cout << "\nTesting Default Constructor..." << endl;
//    // create a point with default constructor
//    Point p;
//    // verify both coordinates are initialized to 0
//    assert(p.getX() == 0);
//    assert(p.getY() == 0);
//    cout << "default constructor test passed!" << endl;
//}
//
//// parameterized constructor test - checks if coordinates are properly set
//void testParameterizedConstructor() {
//    cout << "\nTesting Parameterized Constructor..." << endl;
//    // test values for initialization
//    double x = 3.0;
//    double y = 4.0;
//    // create point with specific coordinates
//    Point p(x, y);
//    // verify the coordinates match what we set
//    assert(p.getX() == x);
//    assert(p.getY() == y);
//    cout << "parameterized constructor test passed!" << endl;
//}
//
//// getter and setter test function - verifies coordinate access and modification
//void testGettersAndSetters() {
//    cout << "\nTesting Getters and Setters..." << endl;
//    Point p;
//
//    // test setting and getting positive x coordinate
//    p.setX(5.5);
//    assert(p.getX() == 5.5);
//
//    // test setting and getting negative y coordinate
//    p.setY(-2.5);
//    assert(p.getY() == -2.5);
//
//    // test setting and getting zero values
//    p.setX(0.0);
//    p.setY(0.0);
//    assert(p.getX() == 0.0);
//    assert(p.getY() == 0.0);
//
//    cout << "getters and setters test passed!" << endl;
//}
//
//// pose comparison test - verifies equality operator between point and pose
//void testPoseComparison() {
//    cout << "\nTesting Pose Comparison..." << endl;
//    Point p;
//    // set initial point coordinates
//    p.setX(1.0);
//    p.setY(2.0);
//
//    // create test poses for comparison
//    Pose pose1(1.0, 2.0, 0.0);  // matching coordinates with point
//    Pose pose2(1.0, 3.0, 0.0);  // different y coordinate
//
//    // test equality with matching coordinates
//    assert(p == pose1);  // should match
//    // test inequality with different coordinates
//    assert(!(p == pose2));  // should not match
//
//    // test comparison with zero coordinates
//    p.setX(0.0);
//    p.setY(0.0);
//    Pose pose3(0.0, 0.0, 0.0);
//    assert(p == pose3);  // should match at origin
//
//    cout << "pose comparison test passed!" << endl;
//}
//
//// get/set point test - verifies bulk coordinate operations
//void testGetSetPoint() {
//    cout << "\nTesting getPoint and setPoint..." << endl;
//    Point p;
//    // test values for coordinate pairs
//    double x = 3.0;
//    double y = 4.0;
//
//    // test setting both coordinates at once
//    p.setPoint(x, y);
//
//    // variables to store retrieved coordinates
//    double getX, getY;
//    p.getPoint(getX, getY);
//
//    // verify coordinates were properly set and retrieved
//    assert(getX == x);
//    assert(getY == y);
//
//    // test with zero coordinates
//    double zero = 0.0;
//    p.setPoint(zero, zero);
//    p.getPoint(getX, getY);
//    assert(getX == 0.0);
//    assert(getY == 0.0);
//
//    cout << "getPoint and setPoint test passed!" << endl;
//}
//
//// distance calculation test - verifies euclidean distance computation
//void testFindDistanceTo() {
//    cout << "\nTesting findDistanceTo..." << endl;
//    Point p1;
//    // set first point at origin
//    p1.setX(0.0);
//    p1.setY(0.0);
//
//    Point p2;
//    // set second point for 3-4-5 triangle test
//    p2.setX(3.0);
//    p2.setY(4.0);
//
//    // test pythagorean triple case (3-4-5 triangle)
//    double distance = p1.findDistanceTo(p2);
//    assert(abs(distance - 5.0) < 0.0001);  // should be exactly 5
//
//    // test distance to self (should be 0)
//    distance = p1.findDistanceTo(p1);
//    assert(abs(distance) < 0.0001);
//
//    // test with negative coordinates (should give same distance)
//    p2.setX(-3.0);
//    p2.setY(-4.0);
//    distance = p1.findDistanceTo(p2);
//    assert(abs(distance - 5.0) < 0.0001);
//
//    cout << "findDistanceTo test passed!" << endl;
//}
//
//// angle calculation test - verifies angle computation between points
//void testFindAngleTo() {
//    cout << "\nTesting findAngleTo..." << endl;
//    Point p1;
//    // set reference point at origin
//    p1.setX(0.0);
//    p1.setY(0.0);
//
//    Point p2;
//    // test 45 degree angle (first quadrant)
//    p2.setX(1.0);
//    p2.setY(1.0);
//    double angle = p1.findAngleTo(p2);
//    assert(abs(angle - M_PI / 4) < 0.0001);
//
//    // test 135 degree angle (second quadrant)
//    p2.setX(-1.0);
//    p2.setY(1.0);
//    angle = p1.findAngleTo(p2);
//    assert(abs(angle - 3 * M_PI / 4) < 0.0001);
//
//    // test -135 degree angle (third quadrant)
//    p2.setX(-1.0);
//    p2.setY(-1.0);
//    angle = p1.findAngleTo(p2);
//    assert(abs(angle + 3 * M_PI / 4) < 0.0001);
//
//    // test -45 degree angle (fourth quadrant)
//    p2.setX(1.0);
//    p2.setY(-1.0);
//    angle = p1.findAngleTo(p2);
//    assert(abs(angle + M_PI / 4) < 0.0001);
//
//    cout << "findAngleTo test passed!" << endl;
//}
//
//int main() {
//    cout << "starting Point Class Tests..." << endl;
//
//    try {
//        // execute all test functions in sequence
//        testDefaultConstructor();
//        testParameterizedConstructor();
//        testGettersAndSetters();
//        testPoseComparison();
//        testGetSetPoint();
//        testFindDistanceTo();
//        testFindAngleTo();
//
//        cout << "\nall tests completed successfully!" << endl;
//    }
//    catch (const exception& e) {
//        // catch and report any test failures
//        cerr << "test failed with exception: " << e.what() << endl;
//        return 1;
//    }
//
//    return 0;
//}
//
