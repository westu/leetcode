// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    int next_value;
    bool has_next;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    if (Iterator::hasNext()) {
	        next_value = Iterator::next();
	        has_next = true;
	    } else {
	        has_next = false;
	    }
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return next_value;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int return_value = next_value;
	    if (Iterator::hasNext()) {
	        next_value = Iterator::next();
	        has_next = true;
	    } else {
	        has_next = false;
	    }
	    return return_value;
	}

	bool hasNext() const {
	    return has_next;
	}
};