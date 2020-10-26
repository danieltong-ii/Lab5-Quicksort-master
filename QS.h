#include "QSInterface.h"

using namespace std;

class QS: public QSInterface
{
    public:
        QS() {
        }
    	~QS() {
            clear();
        }
        void sortAll();
    	int medianOfThree(int left, int right);
    	int partition(int left, int right, int pivotIndex);
    	string getArray() const;
    	int getSize() const;
        void swapIndexValues(int index_one, int index_two);
    	bool addToArray(int value);
    	bool createArray(int capacity);
    	void clear();
    private:
        int* iArray = NULL;
        int position_in_array_ = 0;
        int array_size_ = 0;

};
