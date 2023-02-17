/*The four sorting algorithims I chose, I chose indiscriminately. I tested each, and these 4 show a pretty big difference in performance amongst themselves
so I ended with these. */

#include "Sorting.h"
#include "Timer.h"
using std::cout;
using std::endl;
void testingInsertAlg();
void testingSelectionAlg();
void testingShellAlg();
void testingHeapAlg();

int main()
{
	testingInsertAlg();
	testingSelectionAlg();
	testingShellAlg();
	testingHeapAlg();

	return 0;
}
void testingInsertAlg()
{
	Timer t;
	Sorting testingInsert(20000);
	t.startTimer();
	Sleep(1000);

	cout << "Testing insert sort...\n";
	testingInsert.insertionSort(testingInsert.SizeofList());
	t.stopTimer();
	cout << "Insert sort complete. It took...\n";
	cout << "In Milliseconds " << t.getMilli() << endl;
	cout << "In Seconds " << t.getSeconds() << endl;
	cout << std::fixed << "In Microseconds " << t.getMicro() << endl;
	cout << "It made " << testingInsert.ReturnIt() << " iterations.\n\n";
}
void testingSelectionAlg()
{
	Timer t2;
	Sorting testingSelection(20000);
	t2.startTimer();
	Sleep(1000);
	cout << "Testing selection sort...\n";
	testingSelection.selectionSort(testingSelection.SizeofList());
	t2.stopTimer();
	cout << "Selection sort complete. It took...\n";
	cout << "In Milliseconds " << t2.getMilli() << endl;
	cout << "In Seconds " << t2.getSeconds() << endl;
	cout << std::fixed << "In Microseconds " << t2.getMicro() << endl;
	cout << "It made " << testingSelection.ReturnIt() << " iterations.\n\n";
}
void testingShellAlg()
{
	Timer t3;
	Sorting testingShell(20000);
	t3.startTimer();
	Sleep(1000);

	cout << "Testing shell sort...\n";
	testingShell.shellSort(testingShell.SizeofList());
	t3.stopTimer();
	cout << "Shell sort complete. It took...\n";
	cout << "In Milliseconds " << t3.getMilli() << endl;
	cout << "In Seconds " << t3.getSeconds() << endl;
	cout << std::fixed << "In Microseconds " << t3.getMicro() << endl;
	cout << "It made " << testingShell.ReturnIt() << " iterations.\n\n";
}
void testingHeapAlg()
{
	Timer t4;
	Sorting testingHeap(10000);
	t4.startTimer();
	Sleep(1000);

	cout << "Testing heap sort...\n";
	testingHeap.heapSort(testingHeap.SizeofList());
	t4.stopTimer();
	cout << "Heap sort complete. It took...\n";
	cout << "In Milliseconds " << t4.getMilli() << endl;
	cout << "In Seconds " << t4.getSeconds() << endl;
	cout << std::fixed << "In Microseconds " << t4.getMicro() << endl;
	cout << "It made " << testingHeap.ReturnIt() << " iterations.\n\n";
}