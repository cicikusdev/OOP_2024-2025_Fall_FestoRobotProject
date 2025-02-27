//#include "MAP.h"
//#include "Point.h"
//#include <iostream>
//#include <cassert>
//
//using namespace std;
//
//// Umay Ece Mantar 152120221127 19.12.2024
//// This file is for the Test cases of the MAP class
//
//// Constructor test function
//void testConstructor() {
//    cout << "\nConstructor Test" << endl;
//    MAP map(5, 4, 1.0);
//
//    // Test constructor values
//    assert(map.getNumberX() == 5);
//    assert(map.getNumberY() == 4);
//    assert(map.addGridSize() == 1.0);
//
//    // Test grid initialization
//    for (int y = 0; y < map.getNumberY(); y++) {
//        for (int x = 0; x < map.getNumberX(); x++) {
//            assert(map.getGrid(x, y) == 0);
//        }
//    }
//    cout << "Constructor test passed" << endl;
//}
//
//// Destructor test function
//void testDestructor() {
//    cout << "\nDestructor Test" << endl;
//    {
//        MAP map(3, 3, 1.0); // Constructor called
//    } // Destructor automatically called here
//    cout << "Destructor test passed" << endl;
//}
//
//void testInsertPoint() {
//    cout << "\ninsertPoint() Test" << endl;
//    MAP map(5, 4, 1.0);
//
//    // Test valid point insertion
//    Point p1(1.5, 2.5);
//    map.insertPoint(p1);
//    assert(map.getGrid(1, 2) == 1);
//
//    // Test boundary points
//    Point p2(0.0, 0.0);
//    map.insertPoint(p2);
//    assert(map.getGrid(0, 0) == 1);
//
//    // Test out of bounds points
//    Point p3(-1.0, -1.0);
//    Point p4(10.0, 10.0);
//    map.insertPoint(p3); // Should not crash
//    map.insertPoint(p4); // Should not crash
//
//    cout << "insertPoint() test passed" << endl;
//}
//
//void testGetGrid() {
//    cout << "\ngetGrid() Test" << endl;
//    MAP map(4, 4, 1.0);
//
//    // Test valid indices
//    map.setGrid(2, 2, 1);
//    assert(map.getGrid(2, 2) == 1);
//    assert(map.getGrid(0, 0) == 0);
//
//    // Test invalid indices
//    assert(map.getGrid(-1, 0) == -1);
//    assert(map.getGrid(0, -1) == -1);
//    assert(map.getGrid(4, 0) == -1);
//    assert(map.getGrid(0, 4) == -1);
//
//    cout << "getGrid() test passed" << endl;
//}
//
//void testSetGrid() {
//    cout << "\nsetGrid() Test" << endl;
//    MAP map(4, 4, 1.0);
//
//    // Test valid indices
//    map.setGrid(2, 2, 1);
//    assert(map.getGrid(2, 2) == 1);
//
//    map.setGrid(0, 0, 1);
//    assert(map.getGrid(0, 0) == 1);
//
//    // Test invalid indices (should not crash)
//    map.setGrid(-1, 0, 1);
//    map.setGrid(0, -1, 1);
//    map.setGrid(4, 0, 1);
//    map.setGrid(0, 4, 1);
//
//    cout << "setGrid() test passed" << endl;
//}
//
//void testClearMap() {
//    cout << "\nclearMap() Test" << endl;
//    MAP map(3, 3, 1.0);
//
//    // Set some grid values
//    map.setGrid(0, 0, 1);
//    map.setGrid(1, 1, 1);
//    map.setGrid(2, 2, 1);
//
//    // Clear the map
//    map.clearMap();
//
//    // Verify all cells are cleared
//    for (int y = 0; y < map.getNumberY(); y++) {
//        for (int x = 0; x < map.getNumberX(); x++) {
//            assert(map.getGrid(x, y) == 0);
//        }
//    }
//    cout << "clearMap() test passed" << endl;
//}
//
//void testPrintInfo() {
//    cout << "\nprintInfo() Test" << endl;
//    MAP map(5, 4, 1.5);
//    map.printInfo(); // Verify visually
//    cout << "printInfo() test passed" << endl;
//}
//
//void testShowMap() {
//    cout << "\nshowMap() Test" << endl;
//    MAP map(3, 3, 1.0);
//    map.setGrid(1, 1, 1);
//    map.showMap(); // Verify visually
//    cout << "showMap() test passed" << endl;
//}
//
//void testGetters() {
//    cout << "\nTesting get functions..." << endl;
//    MAP map(5, 4, 1.5);
//
//    assert(map.getNumberX() == 5);
//    assert(map.getNumberY() == 4);
//    assert(map.addGridSize() == 1.5);
//
//    cout << "Get functions test passed" << endl;
//}
//
//void testSetGridSize() {
//    cout << "\nsetGridSize() Test" << endl;
//    MAP map(5, 4, 1.0);
//
//    map.setGridSize(2.5);
//    assert(map.addGridSize() == 2.5);
//
//    map.setGridSize(0.5);
//    assert(map.addGridSize() == 0.5);
//
//    cout << "setGridSize() test passed" << endl;
//}
//
//void testStreamOperator() {
//    cout << "\noperator<< Test" << endl;
//    MAP map(3, 3, 1.0);
//    map.setGrid(1, 1, 1);
//
//    cout << map; // Verify visually
//    cout << "Stream operator test passed" << endl;
//}
//
//int main() {
//    cout << "Starting MAP Class Tests" << endl;
//
//    try {
//        testConstructor();
//        testDestructor();
//        testInsertPoint();
//        testGetGrid();
//        testSetGrid();
//        testClearMap();
//        testPrintInfo();
//        testShowMap();
//        testGetters();
//        testSetGridSize();
//        testStreamOperator();
//
//        cout << "\nAll tests completed successfully" << endl;
//    }
//    catch (const exception& e) {
//        cerr << "Test failed with exception: " << e.what() << endl;
//        return 1;
//    }
//
//    return 0;
//}
