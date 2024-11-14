/*Programers: Zimzy Buchheit, Sean Crist, Alexander Brawn,
    Wyatt Churchman, Anthony Cook
*/

#include <iostream>
#include <string>
#include "Database.h"
#include "Container.h"
#include "DynamicArray.h"
using namespace std;

int main () {
    cout << "Testing DBase1, expecting error" << endl;
    try {
        DynamicArray<string> names;
        names.pushBack("Field 1");
        names.pushBack("Field 2");
        names.pushBack("Field 3");
        DynamicArray<int> types;
        types.pushBack(Database().type_int);
        types.pushBack(Database().type_bool);
        Database KDBase = Database(names, types); // size mismatch
    }
    catch (const char* err_msg) {
        cout << "DBase1" << endl;
        cout << err_msg << endl << endl;
    }

    cout << "Testing Knitting Database" << endl;
    try { // not expecting an error
        DynamicArray<string> names;
        names.pushBack("Pattern Name");
        names.pushBack("Yardage");
        names.pushBack("Price");
        names.pushBack("Craft");
        names.pushBack("Made it?");
        DynamicArray<int> types;
        types.pushBack(Database().type_string);
        types.pushBack(Database().type_int);
        types.pushBack(Database().type_double);
        types.pushBack(Database().type_char);
        types.pushBack(Database().type_bool);
        Database KDBase = Database(names, types);

        cout << "Testing brokenRecord, expecting error" << endl;
        try { // expecting error at index 0
            DynamicArray<Container> brokenRecord;
            Container c1_n(1776);
            Container c1_y(1776);
            Container c1_p(13.99);
            Container c1_c('K');
            Container c1_m(false);
            brokenRecord.pushBack(c1_n);
            brokenRecord.pushBack(c1_y);
            brokenRecord.pushBack(c1_p);
            brokenRecord.pushBack(c1_c);
            brokenRecord.pushBack(c1_m);
            KDBase.addRecord(brokenRecord);
        }
        catch (int index) {
            cout << "Type mismatch at index " << index << endl << endl;
        }

        try { // not expecting error

            cout << "Adding 1st Record:" << endl;
            DynamicArray<Container> record1;
            Container c1_1("Boneyard Shawl");
            Container c1_2(600);
            Container c1_3(0.00);
            Container c1_4('K');
            Container c1_5(false);
            record1.pushBack(c1_1);
            record1.pushBack(c1_2);
            record1.pushBack(c1_3);
            record1.pushBack(c1_4);
            record1.pushBack(c1_5);
            KDBase.addRecord(record1);

            KDBase.printDatabase();

            cout << endl << "Adding More Records:" << endl;
            DynamicArray<Container> record2;
            Container c2_1("It's Pants!");
            Container c2_2(1200);
            Container c2_3(6.00);
            Container c2_4('C');
            Container c2_5(false);
            record2.pushBack(c2_1);
            record2.pushBack(c2_2);
            record2.pushBack(c2_3);
            record2.pushBack(c2_4);
            record2.pushBack(c2_5);
            KDBase.addRecord(record2);

            DynamicArray<Container> record3;
            Container c3_1("Abigail Fairy Dress");
            Container c3_2(1094);
            Container c3_3(6.20);
            Container c3_4('C');
            Container c3_5(true);
            record3.pushBack(c3_1);
            record3.pushBack(c3_2);
            record3.pushBack(c3_3);
            record3.pushBack(c3_4);
            record3.pushBack(c3_5);
            KDBase.addRecord(record3);

            DynamicArray<Container> record4;
            Container c4_1("Find Your Fade");
            Container c4_2(1500);
            Container c4_3(8.00);
            Container c4_4('K');
            Container c4_5(true);
            record4.pushBack(c4_1);
            record4.pushBack(c4_2);
            record4.pushBack(c4_3);
            record4.pushBack(c4_4);
            record4.pushBack(c4_5);
            KDBase.addRecord(record4);

            DynamicArray<Container> record5;
            Container c5_1("Strange Signs");
            Container c5_2(90);
            Container c5_3(0.00);
            Container c5_4('C');
            Container c5_5(false);
            record5.pushBack(c5_1);
            record5.pushBack(c5_2);
            record5.pushBack(c5_3);
            record5.pushBack(c5_4);
            record5.pushBack(c5_5);
            KDBase.addRecord(record5);

            DynamicArray<Container> record6;
            Container c6_1("Summer Hat");
            Container c6_2(300);
            Container c6_3(0.00);
            Container c6_4('K');
            Container c6_5(true);
            record6.pushBack(c6_1);
            record6.pushBack(c6_2);
            record6.pushBack(c6_3);
            record6.pushBack(c6_4);
            record6.pushBack(c6_5);
            KDBase.addRecord(record6);

            DynamicArray<Container> record7;
            Container c7_1("Bandos Wrap");
            Container c7_2(1203);
            Container c7_3(4.48);
            Container c7_4('C');
            Container c7_5(false);
            record7.pushBack(c7_1);
            record7.pushBack(c7_2);
            record7.pushBack(c7_3);
            record7.pushBack(c7_4);
            record7.pushBack(c7_5);
            KDBase.addRecord(record7);

            DynamicArray<Container> record8;
            Container c8_1("Diagonal Fade T-Shirt");
            Container c8_2(1000);
            Container c8_3(6.29);
            Container c8_4('C');
            Container c8_5(true);
            record8.pushBack(c8_1);
            record8.pushBack(c8_2);
            record8.pushBack(c8_3);
            record8.pushBack(c8_4);
            record8.pushBack(c8_5);
            KDBase.addRecord(record8);

            DynamicArray<Container> record9;
            Container c9_1("Homecoming Skirt");
            Container c9_2(1086);
            Container c9_3(0.00);
            Container c9_4('K');
            Container c9_5(false);
            record9.pushBack(c9_1);
            record9.pushBack(c9_2);
            record9.pushBack(c9_3);
            record9.pushBack(c9_4);
            record9.pushBack(c9_5);
            KDBase.addRecord(record9);

            DynamicArray<Container> record10;
            Container c10_1("Honeycomb Cowl");
            Container c10_2(250);
            Container c10_3(3.00);
            Container c10_4('C');
            Container c10_5(true);
            record10.pushBack(c10_1);
            record10.pushBack(c10_2);
            record10.pushBack(c10_3);
            record10.pushBack(c10_4);
            record10.pushBack(c10_5);
            KDBase.addRecord(record10);

            KDBase.printDatabase();

            cout << endl << "Removing Record 7" << endl;
            KDBase.removeRecord(6);
            KDBase.printDatabase();

            cout << endl << "Adding it back at the end" << endl;
            KDBase.addRecord(record7);
            KDBase.printDatabase();
           
            // tests sort method
            cout << endl << "Knitting Database before sorting" << endl;
            KDBase.printDatabase();

            cout << endl << "Sorting on Pattern Name" << endl;
            KDBase.sortByField(KDBase, "Pattern Name");
            KDBase.printDatabase();

            cout << endl << "Sorting on Yardage" << endl;
            KDBase.sortByField(KDBase, "Yardage");
            KDBase.printDatabase();

            cout << endl << "Sorting on Price" << endl;
            KDBase.sortByField(KDBase, "Price");
            KDBase.printDatabase();

            cout << endl << "Sorting on Craft" << endl;
            KDBase.sortByField(KDBase, "Craft");
            KDBase.printDatabase();

            cout << endl << "Sorting on Made it?" << endl;
            KDBase.sortByField(KDBase, "Made it?");
            KDBase.printDatabase();

            cout << endl << "Searching for patterns I have made" << endl;
            Container temp(true);
            DynamicArray<DynamicArray<Container> > results = KDBase.searchByField("Made it?", temp);
            Database RDBase = Database(names, types);
            for (int i = 0; i < results.getSize(); i++) {
                RDBase.addRecord(results.searchByIndex(i));
            }
            RDBase.printDatabase();
            
        }
        catch (int index) {
            cout << "Type mismatch at index " << index << endl;
        }
    }
    catch (const char* err_msg) {
        cout << "Knitting Database" << endl;
        cout << err_msg << endl;
    }

    return 0;
}
