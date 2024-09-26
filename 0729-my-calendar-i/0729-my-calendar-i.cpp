class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    map<int, int> bookings;  // Map to store the start and end times
    
    bool book(int start, int end) {
        // Check for conflicts with existing bookings
        auto nextBooking = bookings.lower_bound(start);  // First booking that starts at or after 'start'
        
        // Check if the new event overlaps with the next event
        if (nextBooking != bookings.end() && nextBooking->first < end) {
            return false;  // Overlap with the next booking
        }
        
        // Check if the new event overlaps with the previous event
        if (nextBooking != bookings.begin() && (--nextBooking)->second > start) {
            return false;  // Overlap with the previous booking
        }
        
        // If no overlap, add the booking
        bookings[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start, end);
 */
